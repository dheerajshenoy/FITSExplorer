#include "FITSExplorer.h"
#include "ui_FITSExplorer.h"

FITSExplorer::FITSExplorer(QStringList argv, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FITSExplorer)
{
    ui->setupUi(this);
    INIT_Connections();
    INIT_Shortcuts();
    ui->splitter->setStretchFactor(1, 1);

    ui->HDU_List->setHorizontalHeaderLabels({"HDU", "HDU Type"});

    /*auto overview_image_widget = new OverviewGraphicsView(gv->scene(), gv);*/
    /*ui->verticalLayout_2->addWidget(overview_image_widget);*/

    // lc = new LightCurve(img_widget);

    QActionGroup *colormapActionGroup = new QActionGroup(this);

    colormapActionGroup->addAction(ui->actionNoColormap);
    colormapActionGroup->addAction(ui->actionAutumn);
    colormapActionGroup->addAction(ui->actionWinter);
    colormapActionGroup->addAction(ui->actionBone);
    colormapActionGroup->addAction(ui->actionHot);
    colormapActionGroup->addAction(ui->actionHSV);
    colormapActionGroup->addAction(ui->actionJet);
    colormapActionGroup->addAction(ui->actionPink);
    colormapActionGroup->addAction(ui->actionCool);
    colormapActionGroup->addAction(ui->actionOcean);
    colormapActionGroup->addAction(ui->actionParula);
    colormapActionGroup->addAction(ui->actionGrayscale);
    colormapActionGroup->addAction(ui->actionRainbow);
    colormapActionGroup->addAction(ui->actionTurbo);
    colormapActionGroup->addAction(ui->actionSpring);
    colormapActionGroup->addAction(ui->actionSummer);
    colormapActionGroup->addAction(ui->action94);
    colormapActionGroup->addAction(ui->action131);
    colormapActionGroup->addAction(ui->action171);
    colormapActionGroup->addAction(ui->action193);
    colormapActionGroup->addAction(ui->action211);
    colormapActionGroup->addAction(ui->action304);
    colormapActionGroup->addAction(ui->action4500);
    colormapActionGroup->addAction(ui->action1600);
    colormapActionGroup->addAction(ui->action1700);

    INIT_Configuration();
    //colormapActionGroup->addAction(ui->actionColormap);

    if(argv.size() > 1)
    {
        OpenFile(argv[1]);
    }

    // OpenFile("/home/neo/Gits/Solar-Project/Data/09-04-2013/DATA_UNCALIBRATED/94/aia.lev1_euv_12s.2013-04-09T124003Z.94.image_lev1.fits");
}

void FITSExplorer::INIT_Configuration()
{
    const QDir XDG_CONFIG_DIR = QDir(QStandardPaths::
                                     writableLocation(QStandardPaths::ConfigLocation));

    QDir configDir = XDG_CONFIG_DIR.filePath(APPNAME);

    // Check if  file exists
    if (configDir.exists())
    {
        m_recentFile.setFileName(configDir.path() + "/recentf");

        QAction *recent_action = ui->actionOpen_Recent;
        QMenu *menu = new QMenu();
        recent_action->setMenu(menu);
        if (m_recentFile.exists()) {
            if (m_recentFile.open(QIODevice::ReadWrite)) {
                QTextStream in(&m_recentFile);
                while (!in.atEnd()) {
                    QAction *action = new QAction(in.readLine());
                    menu->addAction(action);
                    connect(action, &QAction::triggered, this, &FITSExplorer::OpenRecent);
                }
            } else {
                MSG("Couldn't open recent files!");
            }
        } else {

        }

        /*
        QFile configFile(configDir.path() + "config.toml");

        if(configFile.exists())
        {
            // READ THE CONFIG FILE
        }
        else
        {
        }
*/
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
*/
    }
    //ReadConfigFile("/home/neo/.config/FITSExplorer/config.toml");
}

void FITSExplorer::ReadConfigFile(QString cfgfile)
{
    // If no config file is specified use the default at ~/.config/DFITS/config.toml
    if (cfgfile.isEmpty() || cfgfile.isNull())
    {
    }

    //TOMLCFG = toml::parse(cfgfile.toStdString());

}

bool FITSExplorer::isColormapSelected()
{
    if(m_cur_colormap == Colormap::None)
        return false;
    return true;
}


void FITSExplorer::HandleColorMapSelect(Colormap colormap)
{
    File *file = getCurrentFile();
    file->setColormap(colormap);
}

void FITSExplorer::INIT_Connections()
{
    // Get signal when moves is moved inside the pixmap
    // connect(gv,
            // SIGNAL(mouseMoved(QPointF)),
            // SLOT(ShowCoordinates(QPointF)));

    // connect(gv,
            // SIGNAL(markerAdded(QPointF)),
            // SLOT(MarkerAdded(QPointF)));

    // connect(gv,
            // &MyGraphicsView::markersRemoved,
            // this,
            // [&](){ this->RemoveAllMarkers(); });

    // Get signal when cursor moves outside the pixmap within the GraphicsView
    // connect(gv,
            // &MyGraphicsView::mouseOutsidePixmap,
            // this,
            // [&]() {
                // ui->statusbar->clearCoordinate();
            // });

    connect(ui->actionOpen, SIGNAL(triggered()), SLOT(OpenFile()));
    connect(ui->HDU_List, SIGNAL(cellDoubleClicked(int,int)), SLOT(HDU_Table_Double_Clicked(int, int)));
    connect(ui->tab_widget, SIGNAL(tabCloseRequested(int)), SLOT(CloseTab(int)));
    connect(ui->tab_widget, SIGNAL(tabBarClicked(int)), SLOT(update_HDU_Table(int)));

    // connect(gv, SIGNAL(markerColorChanged(int, QColor)), SLOT(changeMarkerLineColor(int, QColor)));

    connect(ui->roi_table, &ROITableWidget::deleteROI, this, [&](QUuid uid) {
        getCurrentFile()->getImgWidget()->GetGraphicsView()->DeleteROIRect__for_table(uid);
    });

    connect(ui->roi_table, &ROITableWidget::hideROI, this, [&](QUuid uid) {
        getCurrentFile()->getImgWidget()->GetGraphicsView()->HideROIRect__for_table(uid);
    });

    connect(ui->roi_table, &ROITableWidget::zoomROI, this, [&](QUuid uid) {
        getCurrentFile()->getImgWidget()->GetGraphicsView()->ZoomIntoROI(uid);
    });

    connect(ui->roi_table, &ROITableWidget::selectROI, this, [&](QUuid uid) {
        getCurrentFile()->getImgWidget()->GetGraphicsView()->SelectROI(uid);
    });

    connect(ui->roi_table, &ROITableWidget::unselectROI, this, [&](QUuid uid) {
        getCurrentFile()->getImgWidget()->GetGraphicsView()->UnselectROI(uid);
    });
}

void FITSExplorer::update_HDU_Table(int index)
{

    m_file_index = index;

    File *file = getCurrentFile();

    ui->HDU_List->clear();
    ui->HDU_List->setRowCount(file->getNHDU());

    QList<int> types = file->getHDUTypes();
    int type;
    QString type_string;

    for(int i=0; i < types.size(); i++)
    {
        type = types[i];
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
        QTableWidgetItem *item2 = new QTableWidgetItem();

        item2->setText(type_string);

        if (i == 0) {
            item1->setText("Primary");
        }
        else {
            item1->setText("Ext " + QString::number(i));
        }

        ui->HDU_List->setItem(i, 0, item1);
        ui->HDU_List->setItem(i, 1, item2);
    }
}

void FITSExplorer::CloseTab(int index)
{
    File *file = m_files_list[index];
    m_files_list.removeAt(index);

    ui->HDU_List->clear();
    ui->HDU_List->setRowCount(0);
    ui->HDU_List->setColumnCount(0);
    ui->tab_widget->removeTab(index);

    disconnect(file->getImgWidget()->GetGraphicsView(),
            SIGNAL(mouseMoved(QPointF)), this,
            SLOT(ShowCoordinates(QPointF)));
    delete file;
}

int FITSExplorer::HDU_Table_Double_Clicked(int row, int col)
{
    int type;
    status = 0;

    File *file = getCurrentFile();

    if(row > file->getNHDU())
        return 0;

    status = file->moveAbsRow(row + 1, type);

    if (status)
    {
        QMessageBox::critical(this, "Error", "Unable to move to the HDU");
        return status;
    }

    switch(type)
    {
    case IMAGE_HDU:
        return HandleImage();
        break;

    case ASCII_TBL:
        return HandleAsciiTable();
        break;

    case BINARY_TBL:
        break;
    }
        //return HandleBinaryTable();


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
        //ui->mini_light_curve_plot->graph(0)->addData(x, m);
    }

    //ui->mini_light_curve_plot->rescaleAxes(true);
    //ui->mini_light_curve_plot->replot();

    // img_widget->setPixmap(QPixmap::fromImage(image));


    // ui->tab_widget->addTab(img_widget, "DD");

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

            ui->statusbar->hideProgressBar(true);
            //ui->mini_light_curve_plot->graph(0)->data()->clear();
            // img_widget->GetSlider()->setEnabled(true);
            ui->actionoverview->setEnabled(true);
            ui->menuImage->setEnabled(true);
            ui->menuStatistics->setEnabled(true);
            ui->action_export_toolbar->setEnabled(true);
            ui->actionSave_toolbar->setEnabled(true);
            ui->actionxport->setEnabled(true);
            auto filenames = openFileDialog.selectedFiles();
            AddRecentFile(filenames[0]);
            ui->statusbar->setMsg(QString("File {%1} Opened").arg(filenames[0]));
            ui->statusbar->setFile(filename);
            HandleFile(filenames[0]);
            return;
        }
    }
    else {
        //ui->mini_light_curve_plot->graph(0)->data()->clear();
        // img_widget->GetSlider()->setEnabled(true);
        ui->actionoverview->setEnabled(true);
        ui->statusbar->hideProgressBar(true);
        ui->menuImage->setEnabled(true);
        ui->menuStatistics->setEnabled(true);
        ui->action_export_toolbar->setEnabled(true);
        ui->actionSave_toolbar->setEnabled(true);
        ui->actionxport->setEnabled(true);
        ui->statusbar->setMsg(QString("File {%1} Opened").arg(filename));
        AddRecentFile(filename);
        ui->statusbar->setFile(filename);
        HandleFile(filename);
        return;
    }
    // If user cancels opening the file
    ui->statusbar->setMsg("File Open Cancelled");
}

void FITSExplorer::OpenRecent() {
    if (sender() != nullptr) {
        QString filename = qobject_cast<QAction *>(sender())->text();

        //ui->mini_light_curve_plot->graph(0)->data()->clear();
        // img_widget->GetSlider()->setEnabled(true);
        ui->actionoverview->setEnabled(true);
        ui->statusbar->hideProgressBar(true);
        ui->menuImage->setEnabled(true);
        ui->menuStatistics->setEnabled(true);
        ui->action_export_toolbar->setEnabled(true);
        ui->actionSave_toolbar->setEnabled(true);
        ui->actionxport->setEnabled(true);
        ui->statusbar->setMsg(QString("File {%1} Opened").arg(filename));
        MSG(filename);
        ui->statusbar->setFile(filename);
        HandleFile(filename);
    }
}

int FITSExplorer::nfiles()
{
    return m_files_list.size();
}

// Helper function for opening the file at path `filename`
int FITSExplorer::HandleFile(QString filename)
{
    // ui->tab_widget->addTab(img_widget, QFileInfo(filename).baseName());
    File *file = new File(filename);

    ui->statusbar->setFile(filename);
    MyGraphicsView *gv = file->getImgWidget()->GetGraphicsView();

    connect(gv,
            SIGNAL(mouseMoved(QPointF)),
            this,
            SLOT(ShowCoordinates(QPointF)));

    connect(gv,
            SIGNAL(signalROITable(QUuid)),
            this,
            SLOT(removeUUIDFromTable(QUuid)));

    connect(gv,
            SIGNAL(newROIRect(QUuid,QRectF)),
            this,
            SLOT(newROIRect(QUuid, QRectF)));

    modeChangeUpdateStatusbar(file->getMode());

    if (m_cur_file_ptr)
    {
        disconnect(m_cur_file_ptr, &File::modeChanged, this, &FITSExplorer::modeChangeUpdateStatusbar);
    }
    else
    {
        m_cur_file_ptr = file;
        connect(m_cur_file_ptr, &File::modeChanged, this, &FITSExplorer::modeChangeUpdateStatusbar);
    }

    m_files_list.push_back(file);

    ui->tab_widget->addTab(file->getImgWidget(), QFileInfo(filename).baseName());

    bool status;
    status = file->Open();
    if(!status)
    {
        QMessageBox::critical(this, "Error", "Cannot Open File!");
        return status;
    }

    m_file_index = nfiles() - 1;

    ui->HDU_List->setRowCount(file->getNHDU());

    QList<int> types = file->getHDUTypes();
    int type;
    QString type_string;

    for(int i=0; i < types.size(); i++)
    {
        type = types[i];
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
        QTableWidgetItem *item2 = new QTableWidgetItem();

        item2->setText(type_string);

        if (i == 0) {
            item1->setText("Primary");
        }
        else {
            item1->setText("Ext " + QString::number(i));
        }

        ui->HDU_List->setItem(i, 0, item1);
        ui->HDU_List->setItem(i, 1, item2);
    }


    return 0;
}

File* FITSExplorer::getCurrentFile()
{
    if (!m_files_list.empty() && m_file_index >= 0)
    {
        return m_files_list[m_file_index];
    }

    return nullptr;
}

int FITSExplorer::HandleImage()
{
    // int naxis;

    File *file = getCurrentFile();
    if (!file)
    {
        QMessageBox::critical(this, "Error", "Cannot open the image");
        return -1;
    }

    int naxis = file->getImgDim();

    long naxes[naxis];
    file->getImgSize(naxes);

    if (!naxes)
    {
        QMessageBox::critical(this, "Error", "Cannot get the image dimension");
        return -1;
    }

    if(file->getImgType() == -1)
    {
        QMessageBox::critical(this, "Error", "Cannot get the image type");
        return -1;
    }

    if(!file->checkIfValidDim())
    {
        QMessageBox::critical(this, "Error", "Undefined height and width for Image");
        return -1;
    }

    file->initImgData();

    auto width = naxes[0];
    auto height = naxes[1];

    auto image_data = file->getImgData();

    ui->statusbar->hideProgressBar(false);

    QImage image(width, height, QImage::Format_Grayscale8);

    // Read the image data and put to QImage, pixel by pixel
    for (uint x = 0; x < width; ++x) {
        for (uint y = 0; y < height; ++y) {
            float value = image_data[y * width + x];
            image.setPixel(x, y, qRgb(value, value, value)); // Assuming grayscale image
            //ui->statusbar->setProgress( ((x + 1) * (y + 1))/(width * height)* 100);
        }

        ui->statusbar->setProgress((x + 1)/width  * 100);
    }

    ui->statusbar->hideProgressBar(true);
    // lc->setData(image_data, width, height);
    file->getImgWidget()->setPixmap(QPixmap::fromImage(image));
    // ui->tab_widget->addTab(img_widget, "Image");
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

int FITSExplorer::ShowOverview()
{
    // Overview for all the HDUs present
    File *file = getCurrentFile();
    fprintf(stderr, "%d", file->getCurrentHDU());
    if(file->getCurrentHDU() == 0)
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
        // ui->tab_widget->addTab(overview, "*Overview*");
        getCurrentFile()->getImgWidget()->setCurrentWidget(overview);
    }
    else {

    }

    return 0;
}

void FITSExplorer::on_actionoverview_triggered()
{
    ShowOverview();
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
    // lc->Show();
}

// Show the coordinates in the statusbar of the mouse position in the image
void FITSExplorer::ShowCoordinates(QPointF points)
{
    ui->statusbar->setCoordinate(points);
}

// Export the file to a given format
void FITSExplorer::ExportFile()
{
    QFileDialog fd;
    QString filename = fd.getSaveFileName(this, "Export As",
                                          nullptr,
                                          "Images (*.png *.jpeg);;PDF (*.pdf);;All Files (*)");

    if (!filename.isEmpty())
    {
        QImage img = getCurrentFile()->getImgWidget()->GetImage();
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
    // if (lc->numLines() >= 1)
    // {
    // }

    // lightCurvePlot = lc->getPlot();
    // m_line = new QCPItemStraightLine(lightCurvePlot);
    // m_line->setPen(QColor::fromRgb(255, 0, 0));
    // m_line->point1->setCoords(pos.x(), lightCurvePlot->yAxis->range().lower);
    // m_line->point2->setCoords(pos.x(), lightCurvePlot->yAxis->range().upper);
    // lc->addLineToList(m_line);
}

// Remove all the lines corresponding to the markers added to the light curves
void FITSExplorer::RemoveAllMarkers()
{

    // if (lc->numLines() == 0)
        // return;

    // lc->clearLines();

}

// Close the opened file
void FITSExplorer::CloseFile()
{
    //ui->mini_light_curve_plot->graph(0)->data()->clear();
    lightCurvePlot->graph(0)->data()->clear();
    getCurrentFile()->getImgWidget()->GetSlider()->setEnabled(false);
    ui->actionoverview->setEnabled(false);
    ui->menuImage->setEnabled(false);
    ui->menuStatistics->setEnabled(false);
    ui->action_export_toolbar->setEnabled(false);
    ui->actionSave_toolbar->setEnabled(false);
    ui->actionxport->setEnabled(false);
    ui->HDU_List->clear();
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
    getCurrentFile()->getImgWidget()->GetGraphicsView()->RemoveAllMarkers();
}

void FITSExplorer::on_actionFit_to_Width_triggered()
{
    getCurrentFile()->fitToWidth(ui->tab_widget->width());
}

void FITSExplorer::on_actionClose_File_triggered()
{
    CloseFile();
}

void FITSExplorer::on_actionPreferences_triggered()
{
    Preferences *prefs = new Preferences();
    prefs->show();
}

void FITSExplorer::on_actionMarkerMode_triggered(bool state)
{
    ui->actionMarker_Mode->setChecked(state); // Set the marker mode toggle on the menu
    getCurrentFile()->getImgWidget()->GetGraphicsView()->setMarkerMode(state);
}

void FITSExplorer::on_actionList_Markers_triggered()
{
    getCurrentFile()->getImgWidget()->GetGraphicsView()->listMarkers();
}

void FITSExplorer::on_actionGrayscale_triggered()
{
    HandleColorMapSelect(Colormap::Grayscale);
}

void FITSExplorer::on_actionBone_triggered()
{
    HandleColorMapSelect(Colormap::Bone);
}

void FITSExplorer::on_actionCool_triggered()
{
    HandleColorMapSelect(Colormap::Cool);
}


void FITSExplorer::on_actionNoColormap_triggered()
{
    HandleColorMapSelect(Colormap::None);
}

void FITSExplorer::on_actionHot_triggered()
{
    HandleColorMapSelect(Colormap::Hot);
}

void FITSExplorer::on_actionHSV_triggered()
{
    HandleColorMapSelect(Colormap::HSV);
}

void FITSExplorer::on_actionJet_triggered()
{
    // HandleColorMapSelect(Colormap::Jet);
    HandleColorMapSelect(Colormap::Temp);
}

void FITSExplorer::on_actionOcean_triggered()
{
    HandleColorMapSelect(Colormap::Ocean);
}

void FITSExplorer::on_actionParula_triggered()
{
    HandleColorMapSelect(Colormap::Parula);
}

void FITSExplorer::on_actionPink_triggered()
{
    HandleColorMapSelect(Colormap::Pink);
}

void FITSExplorer::on_actionRainbow_triggered()
{
    HandleColorMapSelect(Colormap::Rainbow);
}

void FITSExplorer::on_actionSpring_triggered()
{
    HandleColorMapSelect(Colormap::Spring);
}

void FITSExplorer::on_actionSummer_triggered()
{
    HandleColorMapSelect(Colormap::Summer);
}

void FITSExplorer::on_actionTurbo_triggered()
{
    HandleColorMapSelect(Colormap::Turbo);
}

void FITSExplorer::on_actionWinter_triggered()
{
    HandleColorMapSelect(Colormap::Winter);
}

void FITSExplorer::on_actionAutumn_triggered()
{
    HandleColorMapSelect(Colormap::Autumn);
}

void FITSExplorer::on_action94_triggered()
{
    HandleColorMapSelect(Colormap::SDO_AIA_94);
}


void FITSExplorer::on_action131_triggered()
{
    HandleColorMapSelect(Colormap::SDO_AIA_131);
}

void FITSExplorer::on_action171_triggered()
{
    HandleColorMapSelect(Colormap::SDO_AIA_171);
}

void FITSExplorer::on_action193_triggered()
{
    HandleColorMapSelect(Colormap::SDO_AIA_193);
}


void FITSExplorer::on_action211_triggered()
{
    HandleColorMapSelect(Colormap::SDO_AIA_211);
}




void FITSExplorer::INIT_Shortcuts()
{
}

void FITSExplorer::on_actionMarker_Mode_triggered(bool state)
{
    getCurrentFile()->getImgWidget()->GetGraphicsView()->setMarkerMode(state);
}

void FITSExplorer::on_actionImageStatisticsOverview_triggered()
{
    ImageStatisticsOverview *img_stat_overview = new ImageStatisticsOverview(nullptr, image_data);
}

void FITSExplorer::changeMarkerLineColor(int index, QColor color)
{
    // auto line = lc->getLineAt(index);
    // line->setPen(color);
    // lightCurvePlot->replot();
}


void FITSExplorer::on_actionHideAll_Markers_triggered(bool status)
{
    if (status)
        getCurrentFile()->getImgWidget()->GetGraphicsView()->HideAllMarkers();
    else
        getCurrentFile()->getImgWidget()->GetGraphicsView()->ShowAllMarkers();
}

void FITSExplorer::AddRecentFile(QString filename)
{
    QTextStream in(&m_recentFile);

    in.seek(0);
    QStringList lines;

    while (!in.atEnd()) {
        if (in.readLine() != filename) {
            lines << in.readLine();
        }
    }


    foreach(const QString line, lines) {
        in << line;
    }

    lines.insert(0, filename);
}

void FITSExplorer::on_reset_brightness_btn_clicked()
{
    getCurrentFile()->resetBrightness();
}


void FITSExplorer::on_actionSelect_triggered()
{
    bool state = ui->actionSelect->isChecked();
    if (state)
    {
        setMode(Mode::SELECT_MODE);
    }
    else
        setMode(Mode::NORMAL_MODE);
    getCurrentFile()->setSelectMode(state);
}

void FITSExplorer::on_actionPixel_Analysis_triggered()
{
    bool state = ui->actionPixel_Analysis->isChecked();
    if (state)
    {
        setMode(Mode::PIXEL_ANALYSIS_MODE);
    }
    else
    {
        setMode(Mode::NORMAL_MODE);
    }
        getCurrentFile()->setPixelAnalysisMode(state);
}


Mode FITSExplorer::getMode()
{
    return getCurrentFile()->getMode();
}

void FITSExplorer::setMode(Mode mode)
{
    getCurrentFile()->setMode(mode);
    modeChangeUpdateStatusbar(mode);
}


void FITSExplorer::modeChangeUpdateStatusbar(Mode mode)
{

    QString modestr;
    switch(mode)
    {
    case Mode::NORMAL_MODE:
        modestr = "NORMAL MODE";
        break;

    case Mode::PIXEL_ANALYSIS_MODE:
        modestr = "PIXEL ANALYSIS MODE";
        break;

    case Mode::SELECT_MODE:
        modestr = "SELECT MODE";
        break;
    }

    ui->statusbar->setMode(modestr);
}


void FITSExplorer::newROIRect(QUuid uid, QRectF rect)
{
    ui->roi_table->addItem(uid, rect);
}

void FITSExplorer::removeUUIDFromTable(QUuid uid)
{
    ui->roi_table->removeItem(uid);
}
