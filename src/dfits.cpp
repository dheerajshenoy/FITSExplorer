#include "dfits.h"
#include "ui_dfits.h"

DFits::DFits(QStringList argv, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DFits)
{
    ui->setupUi(this);

    // Change brightness when slider is moved and released
    connect(img_widget->GetSlider(), SIGNAL(sliderReleased()),
            SLOT(ChangeBrightness()));

    MyGraphicsView *gv = img_widget->GetGraphicsView();

    // Get signal when moves is moved inside the pixmap
    connect(gv,
            SIGNAL(mouseMoved(QPointF)),
            SLOT(ShowCoordinates(QPointF)));

    connect(gv,
            SIGNAL(markerAdded(QPointF)),
            SLOT(MarkerAdded(QPointF)));

    connect(gv,
            &MyGraphicsView::markersRemoved,
            this,
            [&](){ this->RemoveAllMarkers(); });


    // Get signal when cursor moves outside the pixmap within the GraphicsView
    connect(gv,
            &MyGraphicsView::mouseOutsidePixmap,
            this,
            [&]() {
                ui->statusbar->clearCoordinate();
            });

    connect(ui->actionOpen, SIGNAL(triggered()), SLOT(OpenFile()));

    connect(ui->HDU_List, SIGNAL(cellDoubleClicked(int,int)), SLOT(HDU_Table_Double_Clicked(int, int)));

    connect(ui->tab_widget, SIGNAL(tabCloseRequested(int)), SLOT(CloseTab(int)));

    ui->splitter->setStretchFactor(1, 1);

    ui->mini_light_curve_plot->addGraph();
    ui->mini_light_curve_plot->setInteractions(QCP::iRangeDrag |
                                               QCP::iRangeZoom |
                                               QCP::iSelectPlottables |
                                               QCP::iSelectAxes);
    ui->mini_light_curve_plot->graph(0)->setAntialiased(true);
    ui->mini_light_curve_plot->xAxis->setLabel("Image Width");
    ui->mini_light_curve_plot->yAxis->setLabel("Mean Intensity");
    ui->mini_light_curve_plot->plotLayout()->insertRow(0);
    ui->mini_light_curve_plot->plotLayout()->addElement(0,
                                                        0,
                                                        new QCPTextElement(ui->mini_light_curve_plot,
                                                                           "Light Curve"));
    if(argv.size() > 1)
    {
        OpenFile(argv[1]);
    }
}

void DFits::CloseTab(int index)
{
    ui->tab_widget->removeTab(index);
    //ui->mini_light_curve_plot->removeGraph(index);
}

int DFits::HDU_Table_Double_Clicked(int row, int col)
{
    //QTableWidgetItem *typeItem = ui->HDU_List->item(row, col);
    int type;

    if(row > m_nhdu)
        return 0;

    if(fits_movabs_hdu(fptr, row + 1, &type, &status))
    {
        fits_report_error(stderr, status);
        QMessageBox::critical(this, "Error", "Unable to move to the HDU");
        return status;
    }

    if(type == IMAGE_HDU)
    {
        return HandleImage();
    }
    else if(type == ASCII_TBL)
    {
        return HandleAsciiTable();
    }
    else if(type == BINARY_TBL)
    {
        return HandleBinaryTable();
    }

    return 0;
}

int DFits::HandleAsciiTable()
{
    QMessageBox::information(this, "Info", "TODO: Implement ASCII Table Processing");
    return 0;
}

int DFits::HandleBinaryTable()
{
    QMessageBox::information(this, "Info", "TODO: Implement Binary Table Processing");
    return 0;
}

void DFits::OpenFile(QString filename)
{
    if (filename.isNull())
    {
        QFileDialog openFileDialog;
        filename = openFileDialog.getOpenFileName(this, "Open File", "", "FITS (*.fits *.fit);;All Files (*)");

        if (openFileDialog.result() == QDialog::Accepted) {
            ui->statusbar->setMsg("File Open Cancelled");
            return;
        }
    }

    img_widget->GetSlider()->setEnabled(true);
    HandleFile(filename);
    ui->statusbar->setMsg(QString("File {%1} Opened").arg(filename));
    ui->statusbar->setFile(filename);

    ui->mini_light_curve_plot->graph(0)->data()->clear();

    ui->actionoverview->setEnabled(true);
    ui->actionoverview_raw->setEnabled(true);
    ui->menuImage->setEnabled(true);
    ui->menuStatistics->setEnabled(true);
    ui->action_export_toolbar->setEnabled(true);
    ui->actionSave_toolbar->setEnabled(true);
    ui->actionxport->setEnabled(true);
}

int DFits::HandleFile(QString filename)
{
    status = 0;
    qDebug() << "OUTPUT " << filename;
    if(fits_open_file(&fptr, filename.toStdString().c_str(), READONLY, &status))
    {
        fits_report_error(stderr, status);
        QMessageBox::critical(this, "Error", "Cannot Open File!");
        return status;
    }

    if(fits_get_num_hdus(fptr, &m_nhdu, &status))
    {
        fits_report_error(stderr, status);
        QMessageBox::critical(this, "Error", "Cannot get the number of HDUs!");
        return status;
    }

    if (m_nhdu < 1)
        return 0;

    ui->HDU_List->setRowCount(m_nhdu);

    for(int i=1; i <= m_nhdu; i++)
    {
        if(fits_movabs_hdu(fptr, i, nullptr, &status))
        {
            fits_report_error(stderr, status);
            return status;
        }

        int type;

        if(fits_get_hdu_type(fptr, &type, &status))
        {
            fits_report_error(stderr, status);
            return status;
        }

        QString type_string;

        switch(type)
        {
        case IMAGE_HDU:
            type_string = "IMAGE";
            break;

        case ASCII_TBL:
            type_string = "ASCII TBL";
            break;

        case BINARY_TBL:
            type_string = "BINARY TBL";
            break;
        }

        QTableWidgetItem *item1 = new QTableWidgetItem();
        item1->setText("Unknown");
        /*if (hdu_name == "")
            item1->setText("Unknown");
        else
            item1->setText(hdu_name);
*/

        QTableWidgetItem *item2 = new QTableWidgetItem();
        item2->setText(type_string);

        ui->HDU_List->setItem(i-1, 0, item1);
        ui->HDU_List->setItem(i-1, 1, item2);
    }

    return 0;
}

int DFits::ChangeBrightness()
{
    QImage image = img_widget->GetImage();
    //QImage image = pixmap.toImage();
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            float value = image_data[y * width + x];
            value = qBound(0, static_cast<int>(value * img_widget->GetSlider()->value()/100), 255);
            image.setPixel(x, y, qRgb(value, value, value));
        }
    }

    //image = CM::jet(image);
    img_widget->setPixmap(QPixmap::fromImage(image));
    return 0;
}

int DFits::HandleImage()
{
    int naxis;
    if(fits_get_img_dim(fptr, &naxis, &status))
    {
        fits_report_error(stderr, status);
        return status;
    }

    long naxes[naxis];

    if(fits_get_img_size(fptr, naxis, naxes, &status))
    {
        QMessageBox::critical(this, "Error", "Cannot get the image dimension");
        fits_report_error(stderr, status);
        return status;
    }

    int bitpix;

    if(fits_get_img_type(fptr, &bitpix, &status))
    {
        QMessageBox::critical(this, "Error", "Cannot get the image datatype");
        fits_report_error(stderr, status);
        return status;
    }

    width = naxes[0];
    height = naxes[1];

    long fpixel = 1; // Starting pixel

    if(width == 0 || height == 0)
    {
        QMessageBox::critical(this, "Error", "Undefined height and width for Image");
        return -1;
    }

    if(width < 0 || height < 0)
    {
        QMessageBox::critical(this, "Error", "Undefined height and width for Image");
        return -1;
    }

    try {
        image_data = new float[width * height];
    }
    catch(std::bad_array_new_length *e)
    {
        qCritical() << "Caught std::bad_array_new_length: " << e->what();
        QMessageBox::critical(this, "Error", e->what());
        return 1;
    }

    img_widget->SetData(image_data);

    if(fits_read_img(fptr, TFLOAT, fpixel, width * height,
                      NULL, image_data, NULL, &status))
    {
        fits_report_error(stderr, status);
        return status;
    }

    QImage image(width, height, QImage::Format_Grayscale8);



    for (int x = 0; x < width; ++x) {
        double m = 0;
        for (int y = 0; y < height; ++y) {
            float value = image_data[y * width + x];
            image.setPixel(x, y, qRgb(value, value, value)); // Assuming grayscale image
            m += value;
        }
        m = m / height;
        ui->mini_light_curve_plot->graph(0)->addData(x, m);
    }

    ui->mini_light_curve_plot->rescaleAxes(true);
    ui->mini_light_curve_plot->replot();

    img_widget->setPixmap(QPixmap::fromImage(image));
    ui->tab_widget->addTab(img_widget, "DD");
    return 0;
}

DFits::~DFits()
{
    delete ui;
}

void DFits::on_actionopen_toolbar_triggered()
{
    OpenFile();
}

int DFits::ShowOverview(int index)
{

    overview = new Overview();
    // Overview for all the HDUs present
    if(index == 0)
    {
        if(fits_movabs_hdu(fptr, 1, NULL, &status))
        {
            fits_report_error(stderr, status);
            QMessageBox::critical(this, "Error", "Cannot move to primary HDU");
            return status;
        }

        int nkeys;
        if (fits_get_hdrspace(fptr, &nkeys, NULL, &status)) {
            fits_report_error(stderr, status);
            QMessageBox::critical(this, "Error", "Cannot get keys from the HDU");
            return status;
        }

        QMap<QString, QString> keyvals;
        char keyname[FLEN_CARD];
        char value[FLEN_CARD];
        for (int i = 1; i <= nkeys; i++)
        {
            /*
            char card[FLEN_CARD];
            if (fits_read_record(fptr, i, card, &status))
            {
                fits_report_error(stderr, status);
                QMessageBox::critical(this, "Error", "Cannot get keys from the HDU");
                return status;
            }

            vals.insert(i - 1, QString(card));
*/

            if (fits_read_keyn(fptr, i, keyname, value, NULL, &status)) {
                fits_report_error(stderr, status);
                return status;
            }

            if(QString(keyname) != "")
            {
                keyvals.insert(keyname, value);
            }
        }

        overview->SetRecords(keyvals);
        ui->tab_widget->addTab(overview, "*Overview*");
    }
    else {

    }

    return 0;
}


void DFits::on_actionoverview_triggered()
{
    ShowOverview(0);
}


void DFits::on_actionAbout_triggered()
{
    AboutDialog *ab = new AboutDialog();
    ab->show();
}

void DFits::on_actionoverview_raw_triggered()
{
    if(!overview->hasBeenAlreadyShown())
        ShowOverview(0);
    QWidget *widget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout();
    widget->setLayout(layout);
    QPlainTextEdit *rawEdit = new QPlainTextEdit();
    layout->addWidget(rawEdit);

    QVector<QString> texts = overview->getRecords();
    foreach (QString text, texts) {
        rawEdit->insertPlainText(text);
        rawEdit->insertPlainText("\n");
    }

    rawEdit->moveCursor(QTextCursor::Start);

    ui->tab_widget->addTab(widget, "*Raw Overview*");
}


void DFits::on_actionLight_Curve_triggered()
{
    lc = new LightCurve(img_widget);
    lc->setData(image_data, width, height);
    lc->show();
}

void DFits::ShowCoordinates(QPointF points)
{
    ui->statusbar->setCoordinate(points);
}

void DFits::ExportFile()
{
    QFileDialog fd;
    QString filename = fd.getSaveFileName(this, "Export As",
                                          "",
                                          "Images (*.png *.jpeg);;PDF (*.pdf);;All Files (*)");

    if (fd.result() != QDialog::Rejected)
    {
        QImage img = img_widget->GetImage();
        if(filename.endsWith(".pdf"))
        {
            QString fileName = "/home/neo/output.pdf";
            QPdfWriter pdfWriter(fileName);
            pdfWriter.setPageSize(QPageSize(img.size(), QPageSize::Point));
            QPainter pdfPainter(&pdfWriter);
            pdfPainter.drawImage(QRectF(QPointF(0, 0), img.size()), img);
            pdfPainter.end();
        }
        else
        {
            img.save(filename);
        }
        ui->statusbar->setMsg("File Exported Successfully!", 3000);
    }
    else
    {
        ui->statusbar->setMsg("File Exporting Cancelled");
    }
}

void DFits::MarkerAdded(QPointF pos)
{
    m_line = new QCPItemStraightLine(ui->mini_light_curve_plot);
    m_line->setPen(QColor::fromRgb(255, 0, 0));
    m_line->point1->setCoords(pos.x(), ui->mini_light_curve_plot->yAxis->range().lower);
    m_line->point2->setCoords(pos.x(), ui->mini_light_curve_plot->yAxis->range().upper);
    m_lines_list.append(m_line);
    ui->mini_light_curve_plot->replot();
}

void DFits::RemoveAllMarkers()
{
    printf("HELLO WORLD");
    foreach(QCPItemStraightLine* line, m_lines_list)
    {
        ui->mini_light_curve_plot->removeItem(line);
    }
    ui->mini_light_curve_plot->replot();
}

void DFits::on_actionxport_triggered()
{
    ExportFile();
}


void DFits::on_actionSave_toolbar_triggered()
{

}


void DFits::on_action_export_toolbar_triggered()
{
    ExportFile();
}

void DFits::on_actionDeleteAllMarkers_triggered()
{
    img_widget->GetGraphicsView()->RemoveAllMarkers();
}

