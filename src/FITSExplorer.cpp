#include "FITSExplorer.h"
#include "ui_FITSExplorer.h"

FITSExplorer::FITSExplorer(QStringList argv, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DFits)
{
    ui->setupUi(this);
    INIT_Connections();
    INIT_Configuration();
    INIT_MiniLightCurve();
    ui->splitter->setStretchFactor(1, 1);

    if(argv.size() > 1)
    {
        OpenFile(argv[1]);
    }
}

void FITSExplorer::INIT_MiniLightCurve()
{
    //ui->mini_light_curve_plot->setVisible(toml::find<bool>(TOMLCFG,
    //                                                       "GUI.Mini_Light_Curve.shown"));
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
    ui->mini_light_curve_plot->setHidden(true);
}

void FITSExplorer::INIT_Configuration()
{
    /*
    const QDir XDG_CONFIG_DIR = QDir(QStandardPaths::
                                     writableLocation(QStandardPaths::ConfigLocation));

    QDir configDir = XDG_CONFIG_DIR.filePath(APPNAME);

    MSG(configDir.path());

    // Check if  file exists
    if (configDir.exists())
    {
        /*
        QFile configFile(configDir.path() + "config.toml");

        if(configFile.exists())
        {
            // READ THE CONFIG FILE
        }
        else
        {
        }
    }
    else {
        /*
        auto msgbox = QMessageBox();
        msgbox.setText("Config directory doesn't exist, create it at " + configDir.path());
        msgbox.setWindowTitle("Create Config Directory?");
        msgbox.addButton("Ok", QMessageBox::AcceptRole);
        msgbox.addButton("Cancel", QMessageBox::RejectRole);
        msgbox.exec();

        // If yes, create the config directory
        if (msgbox.result() == QMessageBox::Ok)
        {
            QDir(XDG_CONFIG_DIR).mkdir(APPNAME);
        }
    }
*/
    ReadConfigFile("/home/neo/.config/FITSExplorer/config.toml");
}

void FITSExplorer::ReadConfigFile(QString cfgfile)
{
    // If no config file is specified use the default at ~/.config/DFITS/config.toml
    if (cfgfile.isEmpty() || cfgfile.isNull())
    {
    }

    //TOMLCFG = toml::parse(cfgfile.toStdString());

}

void FITSExplorer::INIT_Connections()
{
    // Change brightness when slider is moved and released
    connect(img_widget->GetSlider(), SIGNAL(sliderReleased()),
            SLOT(ChangeBrightness()));

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

}

void FITSExplorer::CloseTab(int index)
{
    ui->tab_widget->removeTab(index);
    //ui->mini_light_curve_plot->removeGraph(index);
}

int FITSExplorer::HDU_Table_Double_Clicked(int row, int col)
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

int FITSExplorer::HandleAsciiTable()
{
    QMessageBox::information(this, "Info", "TODO: Implement ASCII Table Processing");
    return 0;
}

int FITSExplorer::HandleBinaryTable()
{

    // Get the number of rows and columns in the binary table
    int ncols;
    long nrows;
    fits_get_num_rows(fptr, &nrows, &status);
    fits_get_num_cols(fptr, &ncols, &status);

    // Allocate memory to store the data
    uchar *data = new uchar[nrows * ncols];

    // Read the binary table data
    if(fits_read_tblbytes(fptr, 1, 1, ncols * nrows * sizeof(uchar), data, &status))
    {
        fits_report_error(stderr, status);
        delete[] data;
        return status;
    }

    QTableWidget *table = new QTableWidget();
    table->setColumnCount(ncols);
    table->setRowCount(nrows);

    printf("%u", data[0]);

    QImage image(ncols, nrows, QImage::Format_Grayscale8);

    for (int x = 0; x < ncols; ++x) {
        double m = 0;
        for (int y = 0; y < nrows; ++y) {
            float value = static_cast<float>(data[y * ncols + x]);
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

    delete[] data;

    return 0;
}

// Handle Opening of files
void FITSExplorer::OpenFile(QString filename)
{
    if (filename.isNull())
    {
        QFileDialog openFileDialog(this, "Open File", "", "FITS (*.fits *.fit);;All Files (*)");
        openFileDialog.setAcceptMode(QFileDialog::AcceptOpen);

        if (openFileDialog.exec())
        {
            // Enable the widgets only on first run of this function

            ui->actionMarkerMode->setEnabled(true);
            ui->mini_light_curve_plot->graph(0)->data()->clear();
            img_widget->GetSlider()->setEnabled(true);
            ui->actionoverview->setEnabled(true);
            ui->actionoverview_raw->setEnabled(true);
            ui->menuImage->setEnabled(true);
            ui->menuStatistics->setEnabled(true);
            ui->action_export_toolbar->setEnabled(true);
            ui->actionSave_toolbar->setEnabled(true);
            ui->actionxport->setEnabled(true);
            filename = openFileDialog.selectedFiles()[0];
            // Till here

            ui->statusbar->setMsg(QString("File {%1} Opened").arg(filename));
            ui->statusbar->setFile(filename);
            HandleFile(openFileDialog.selectedFiles().at(0));
            return;
        }
    }

    // If user cancels opening the file
    ui->statusbar->setMsg("File Open Cancelled");
    return;
}

// Helper function for opening the file at path `filename`
int FITSExplorer::HandleFile(QString filename)
{
    // set status before opening the file according to then norms of cfitsio
    status = 0;
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

int FITSExplorer::ChangeBrightness()
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

    //image.convertTo(QImage::Format_Indexed8);
    //image.setColorTable(m_inferno);

    img_widget->setPixmap(QPixmap::fromImage(image));
    return 0;
}

int FITSExplorer::HandleImage()
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
    ui->mini_light_curve_plot->setHidden(false);

    //image.convertTo(QImage::Format_Indexed8);
    //image.setColorTable(m_inferno);

    img_widget->setPixmap(QPixmap::fromImage(image));
    ui->tab_widget->addTab(img_widget, "DD");
    return 0;
}

FITSExplorer::~FITSExplorer()
{
    CloseFile();
    delete ui;
}

void FITSExplorer::on_actionopen_toolbar_triggered()
{
    OpenFile();
}

int FITSExplorer::ShowOverview(int index)
{
    // Overview for all the HDUs present
    if(index == 0)
    {
        if(fits_movabs_hdu(fptr, 1, NULL, &status))
        {
            fits_report_error(stderr, status);
            QMessageBox::critical(this, "Error", "Cannot move to primary HDU");
            return status;
        }

        if (fits_get_hdrspace(fptr, &m_nkeys, NULL, &status)) {
            fits_report_error(stderr, status);
            QMessageBox::critical(this, "Error", "Cannot get keys from the HDU");
            return status;
        }

        QMap<QString, QString> keyvals;
        char keyname[FLEN_CARD];
        char value[FLEN_CARD];
        for (int i = 1; i <= m_nkeys; i++)
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


void FITSExplorer::on_actionoverview_triggered()
{
    ShowOverview(0);
}


void FITSExplorer::on_actionAbout_triggered()
{
    AboutDialog *ab = new AboutDialog();
    ab->show();
}

void FITSExplorer::on_actionoverview_raw_triggered()
{
    if(fits_movabs_hdu(fptr, 1, NULL, &status))
    {
        fits_report_error(stderr, status);
        QMessageBox::critical(this, "Error", "Cannot move to primary HDU");
        return;
    }

    if (fits_get_hdrspace(fptr, &m_nkeys, NULL, &status)) {
        fits_report_error(stderr, status);
        QMessageBox::critical(this, "Error", "Cannot get keys from the HDU");
        return;
    }

    QWidget *widget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout();
    widget->setLayout(layout);
    QPlainTextEdit *rawEdit = new QPlainTextEdit();
    layout->addWidget(rawEdit);

    char keyname[FLEN_CARD];
    char value[FLEN_CARD];
    for (int i = 1; i <= m_nkeys; i++)
    {
        char card[FLEN_CARD];
        if (fits_read_record(fptr, i, card, &status))
        {
            fits_report_error(stderr, status);
            QMessageBox::critical(this, "Error", "Cannot get keys from the HDU");
            return;
        }
        rawEdit->insertPlainText(card);
        rawEdit->insertPlainText("\n");
    }

    rawEdit->moveCursor(QTextCursor::Start);

    ui->tab_widget->addTab(widget, "*Raw Overview*");
}


void FITSExplorer::on_actionLight_Curve_triggered()
{
    lc = new LightCurve(img_widget);
    lc->setData(image_data, width, height);
    lc->show();
}

void FITSExplorer::ShowCoordinates(QPointF points)
{
    ui->statusbar->setCoordinate(points);
}

void FITSExplorer::ExportFile()
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

void FITSExplorer::MarkerAdded(QPointF pos)
{
    m_line = new QCPItemStraightLine(ui->mini_light_curve_plot);
    m_line->setPen(QColor::fromRgb(255, 0, 0));
    m_line->point1->setCoords(pos.x(), ui->mini_light_curve_plot->yAxis->range().lower);
    m_line->point2->setCoords(pos.x(), ui->mini_light_curve_plot->yAxis->range().upper);
    m_lines_list.append(m_line);
    ui->mini_light_curve_plot->replot();
}

void FITSExplorer::RemoveAllMarkers()
{
    printf("HELLO WORLD");
    foreach(QCPItemStraightLine* line, m_lines_list)
    {
        ui->mini_light_curve_plot->removeItem(line);
    }
    ui->mini_light_curve_plot->replot();
}

void FITSExplorer::CloseFile()
{
    ui->actionMarkerMode->setEnabled(false);
    ui->mini_light_curve_plot->graph(0)->data()->clear();
    img_widget->GetSlider()->setEnabled(false);
    ui->actionoverview->setEnabled(false);
    ui->actionoverview_raw->setEnabled(false);
    ui->menuImage->setEnabled(false);
    ui->menuStatistics->setEnabled(false);
    ui->action_export_toolbar->setEnabled(false);
    ui->actionSave_toolbar->setEnabled(false);
    ui->actionxport->setEnabled(false);
    if(fptr)
    {
        delete fptr;
        delete [] image_data;
        status = 0;
    }
}

void FITSExplorer::on_actionxport_triggered()
{
    ExportFile();
}


void FITSExplorer::on_actionSave_toolbar_triggered()
{

}


void FITSExplorer::on_action_export_toolbar_triggered()
{
    ExportFile();
}

void FITSExplorer::on_actionDeleteAllMarkers_triggered()
{
    gv->RemoveAllMarkers();
}


void FITSExplorer::on_actionFit_to_Width_triggered()
{
    gv->fitToWidth(ui->tab_widget->width());
}


void FITSExplorer::on_actionClose_File_triggered()
{
    CloseFile();
}


void FITSExplorer::on_actionPreferences_triggered()
{
    prefs->show();
}


void FITSExplorer::on_actionMarkerMode_triggered(bool state)
{
    gv->setMarkerMode(state);
}


void FITSExplorer::on_actionList_Markers_triggered()
{
    gv->listMarkers();
}

