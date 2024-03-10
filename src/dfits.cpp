#include "dfits.h"
#include "ui_dfits.h"

DFits::DFits(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DFits)
{
    ui->setupUi(this);
    connect(img_widget->GetSlider(), SIGNAL(sliderReleased()), SLOT(ChangeBrightness()));
    connect(ui->actionOpen, SIGNAL(triggered()), SLOT(OpenFile()));
    connect(ui->HDU_List, SIGNAL(cellDoubleClicked(int,int)), SLOT(HDU_Table_Double_Clicked(int, int)));
    connect(ui->tab_widget, SIGNAL(tabCloseRequested(int)), SLOT(CloseTab(int)));

    ui->splitter->setStretchFactor(1, 1);
}

void DFits::CloseTab(int index)
{
    ui->tab_widget->removeTab(index);
}

void DFits::HDU_Table_Double_Clicked(int row, int col)
{
    //QTableWidgetItem *typeItem = ui->HDU_List->item(row, col);
    int type;
    if(fits_movabs_hdu(fptr, row + 1, &type, &status))
    {
        QMessageBox::critical(this, "Error", "Unable to open the HDU");
        return;
    }

    if(type == IMAGE_HDU)
    {
        HandleImage();
    }
    else if(type == ASCII_TBL)
    {
        HandleAsciiTable();
    }
}

int DFits::HandleAsciiTable()
{

    return 0;
}

void DFits::OpenFile()
{
    /*
    QFileDialog openFileDialog;
    QString filename = openFileDialog.getOpenFileName(this, "Open File", "DD");

    if (openFileDialog.result() == QDialog::Accepted) {
        ui->statusbar->setMsg("File Open Cancelled");
        return;
    }
*/

    img_widget->GetSlider()->setEnabled(true);
    QString filename = "/home/neo/Gits/dfits/test.fits";
    HandleFile(filename);
    ui->statusbar->setMsg(QString("File {%1} Opened").arg(filename));
    ui->statusbar->setFile(filename);

    ui->actionoverview->setEnabled(true);
    ui->actionoverview_raw->setEnabled(true);
    ui->menuImage->setEnabled(true);
    ui->menuStatistics->setEnabled(true);
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

    int nhdu;

    if(fits_get_num_hdus(fptr, &nhdu, &status))
    {
        fits_report_error(stderr, status);
        QMessageBox::critical(this, "Error", "Cannot get the number of HDUs!");
        return status;
    }

    ui->HDU_List->setRowCount(nhdu);

    for(int i=1; i <= nhdu; i++)
    {
        if(fits_movabs_hdu(fptr, i, nullptr, &status))
        {
            fits_report_error(stderr, status);
            return status;
        }

        /*char hdu_name[FLEN_VALUE];

        if (fits_read_keyword(fptr, "EXTNAME", hdu_name, NULL, &status)) {
            if (status == KEY_NO_EXIST) {
                //fits_report_error(stderr, status); // Report any errors
            }
        }*/

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

    // image = CM::jet(image);
    img_widget->setImage(image);
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
        fits_report_error(stderr, status);
        return status;
    }

    width = naxes[0];
    height = naxes[1];

    long fpixel = 1; // Starting pixel

    image_data = new float[width * height];
    img_widget->SetData(image_data);
    //float *image_data = (float *)malloc(naxes[0] * naxes[1] * sizeof(float));


    if(fits_read_img(fptr, TFLOAT, fpixel, width * height,
                      NULL, image_data, NULL, &status))
    {
        fits_report_error(stderr, status);
        return status;
    }

    QImage image(width, height, QImage::Format_Grayscale8);

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            float value = image_data[y * width + x];
            image.setPixel(x, y, qRgb(value, value, value)); // Assuming grayscale image
        }
    }

    //image = CM::jet(image);

    img_widget->setImage(image);
    //img_widget->GetImageLabel()->setPixmap(QPixmap::fromImage(image).scaled(width, height, Qt::KeepAspectRatio));
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

