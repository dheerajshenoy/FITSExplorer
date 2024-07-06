/********************************************************************************
** Form generated from reading UI file 'FITSExplorer.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FITSEXPLORER_H
#define UI_FITSEXPLORER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <mystatusbar.h>

QT_BEGIN_NAMESPACE

class Ui_DFits
{
public:
    QAction *actionOpen;
    QAction *actionExit;
    QAction *actionPreferences;
    QAction *actionAbout;
    QAction *actionColormap;
    QAction *actionOpen_Recent;
    QAction *actionoverview;
    QAction *actionopen_toolbar;
    QAction *actionoverview_raw;
    QAction *actionLight_Curve;
    QAction *actionxport;
    QAction *actionSave_toolbar;
    QAction *action_export_toolbar;
    QAction *actionDeleteAllMarkers;
    QAction *actionFit_to_Width;
    QAction *actionFit_to_Height;
    QAction *actionZoom0;
    QAction *actionZoom25;
    QAction *actionZoom50;
    QAction *actionZoom75;
    QAction *actionZoom100;
    QAction *actionClose_File;
    QAction *actionMarkerMode;
    QAction *actionList_Markers;
    QAction *actionDelete_Markers;
    QAction *actionBone;
    QAction *actionCool;
    QAction *actionHot;
    QAction *actionHSV;
    QAction *actionJet;
    QAction *actionOcean;
    QAction *actionParula;
    QAction *actionPink;
    QAction *actionRainbow;
    QAction *actionSpring;
    QAction *actionSummer;
    QAction *actionTurbo;
    QAction *actionWinter;
    QAction *actionAutumn;
    QAction *actionGrayscale;
    QAction *actionCustom;
    QAction *actionMarker_Mode;
    QAction *actionImageStatisticsOverview;
    QAction *actionHideAll_Markers;
    QAction *actionSave_As;
    QAction *actionExport;
    QAction *actionNoColormap;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QSplitter *splitter;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *HDU_List;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout;
    QTabWidget *tab_widget;
    MyStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuHelp;
    QMenu *menuTools;
    QMenu *menuImage;
    QMenu *menuStatistics;
    QMenu *menuMarker;
    QMenu *menuZoom;
    QMenu *menuColormap;
    QToolBar *toolbar;

    void setupUi(QMainWindow *DFits)
    {
        if (DFits->objectName().isEmpty())
            DFits->setObjectName("DFits");
        DFits->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DFits->sizePolicy().hasHeightForWidth());
        DFits->setSizePolicy(sizePolicy);
        DFits->setMinimumSize(QSize(200, 0));
        actionOpen = new QAction(DFits);
        actionOpen->setObjectName("actionOpen");
        actionExit = new QAction(DFits);
        actionExit->setObjectName("actionExit");
        actionPreferences = new QAction(DFits);
        actionPreferences->setObjectName("actionPreferences");
        actionAbout = new QAction(DFits);
        actionAbout->setObjectName("actionAbout");
        actionColormap = new QAction(DFits);
        actionColormap->setObjectName("actionColormap");
        actionOpen_Recent = new QAction(DFits);
        actionOpen_Recent->setObjectName("actionOpen_Recent");
        actionoverview = new QAction(DFits);
        actionoverview->setObjectName("actionoverview");
        actionoverview->setEnabled(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../Downloads/file-color-icon.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionoverview->setIcon(icon);
        actionoverview->setMenuRole(QAction::MenuRole::NoRole);
        actionopen_toolbar = new QAction(DFits);
        actionopen_toolbar->setObjectName("actionopen_toolbar");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../../Downloads/file-manager-icon.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionopen_toolbar->setIcon(icon1);
        actionopen_toolbar->setMenuRole(QAction::MenuRole::NoRole);
        actionoverview_raw = new QAction(DFits);
        actionoverview_raw->setObjectName("actionoverview_raw");
        actionoverview_raw->setEnabled(false);
        QIcon icon2(QIcon::fromTheme(QString::fromUtf8("applications-development")));
        actionoverview_raw->setIcon(icon2);
        actionoverview_raw->setMenuRole(QAction::MenuRole::NoRole);
        actionLight_Curve = new QAction(DFits);
        actionLight_Curve->setObjectName("actionLight_Curve");
        actionLight_Curve->setEnabled(true);
        actionxport = new QAction(DFits);
        actionxport->setObjectName("actionxport");
        actionxport->setEnabled(false);
        actionSave_toolbar = new QAction(DFits);
        actionSave_toolbar->setObjectName("actionSave_toolbar");
        actionSave_toolbar->setEnabled(false);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("../../Downloads/diskette-save-svgrepo-com.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionSave_toolbar->setIcon(icon3);
        actionSave_toolbar->setMenuRole(QAction::MenuRole::NoRole);
        action_export_toolbar = new QAction(DFits);
        action_export_toolbar->setObjectName("action_export_toolbar");
        action_export_toolbar->setEnabled(false);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("../../Downloads/export-svgrepo-com.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        action_export_toolbar->setIcon(icon4);
        action_export_toolbar->setMenuRole(QAction::MenuRole::NoRole);
        actionDeleteAllMarkers = new QAction(DFits);
        actionDeleteAllMarkers->setObjectName("actionDeleteAllMarkers");
        QIcon icon5(QIcon::fromTheme(QString::fromUtf8("edit-delete")));
        actionDeleteAllMarkers->setIcon(icon5);
        actionDeleteAllMarkers->setMenuRole(QAction::MenuRole::NoRole);
        actionFit_to_Width = new QAction(DFits);
        actionFit_to_Width->setObjectName("actionFit_to_Width");
        actionFit_to_Height = new QAction(DFits);
        actionFit_to_Height->setObjectName("actionFit_to_Height");
        actionZoom0 = new QAction(DFits);
        actionZoom0->setObjectName("actionZoom0");
        actionZoom25 = new QAction(DFits);
        actionZoom25->setObjectName("actionZoom25");
        actionZoom50 = new QAction(DFits);
        actionZoom50->setObjectName("actionZoom50");
        actionZoom75 = new QAction(DFits);
        actionZoom75->setObjectName("actionZoom75");
        actionZoom100 = new QAction(DFits);
        actionZoom100->setObjectName("actionZoom100");
        actionClose_File = new QAction(DFits);
        actionClose_File->setObjectName("actionClose_File");
        actionMarkerMode = new QAction(DFits);
        actionMarkerMode->setObjectName("actionMarkerMode");
        actionMarkerMode->setCheckable(true);
        actionMarkerMode->setChecked(false);
        actionMarkerMode->setEnabled(false);
        QIcon icon6(QIcon::fromTheme(QString::fromUtf8("applications-graphics")));
        actionMarkerMode->setIcon(icon6);
        actionMarkerMode->setMenuRole(QAction::MenuRole::NoRole);
        actionList_Markers = new QAction(DFits);
        actionList_Markers->setObjectName("actionList_Markers");
        actionDelete_Markers = new QAction(DFits);
        actionDelete_Markers->setObjectName("actionDelete_Markers");
        actionDelete_Markers->setIcon(icon5);
        actionBone = new QAction(DFits);
        actionBone->setObjectName("actionBone");
        actionBone->setCheckable(true);
        actionCool = new QAction(DFits);
        actionCool->setObjectName("actionCool");
        actionCool->setCheckable(true);
        actionHot = new QAction(DFits);
        actionHot->setObjectName("actionHot");
        actionHot->setCheckable(true);
        actionHSV = new QAction(DFits);
        actionHSV->setObjectName("actionHSV");
        actionHSV->setCheckable(true);
        actionJet = new QAction(DFits);
        actionJet->setObjectName("actionJet");
        actionJet->setCheckable(true);
        actionOcean = new QAction(DFits);
        actionOcean->setObjectName("actionOcean");
        actionOcean->setCheckable(true);
        actionParula = new QAction(DFits);
        actionParula->setObjectName("actionParula");
        actionParula->setCheckable(true);
        actionPink = new QAction(DFits);
        actionPink->setObjectName("actionPink");
        actionPink->setCheckable(true);
        actionRainbow = new QAction(DFits);
        actionRainbow->setObjectName("actionRainbow");
        actionRainbow->setCheckable(true);
        actionSpring = new QAction(DFits);
        actionSpring->setObjectName("actionSpring");
        actionSpring->setCheckable(true);
        actionSummer = new QAction(DFits);
        actionSummer->setObjectName("actionSummer");
        actionSummer->setCheckable(true);
        actionTurbo = new QAction(DFits);
        actionTurbo->setObjectName("actionTurbo");
        actionTurbo->setCheckable(true);
        actionWinter = new QAction(DFits);
        actionWinter->setObjectName("actionWinter");
        actionWinter->setCheckable(true);
        actionAutumn = new QAction(DFits);
        actionAutumn->setObjectName("actionAutumn");
        actionAutumn->setCheckable(true);
        actionGrayscale = new QAction(DFits);
        actionGrayscale->setObjectName("actionGrayscale");
        actionGrayscale->setCheckable(true);
        actionCustom = new QAction(DFits);
        actionCustom->setObjectName("actionCustom");
        actionCustom->setCheckable(false);
        actionMarker_Mode = new QAction(DFits);
        actionMarker_Mode->setObjectName("actionMarker_Mode");
        actionMarker_Mode->setCheckable(true);
        actionImageStatisticsOverview = new QAction(DFits);
        actionImageStatisticsOverview->setObjectName("actionImageStatisticsOverview");
        actionHideAll_Markers = new QAction(DFits);
        actionHideAll_Markers->setObjectName("actionHideAll_Markers");
        actionHideAll_Markers->setCheckable(true);
        actionSave_As = new QAction(DFits);
        actionSave_As->setObjectName("actionSave_As");
        actionExport = new QAction(DFits);
        actionExport->setObjectName("actionExport");
        actionNoColormap = new QAction(DFits);
        actionNoColormap->setObjectName("actionNoColormap");
        actionNoColormap->setCheckable(true);
        centralwidget = new QWidget(DFits);
        centralwidget->setObjectName("centralwidget");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy1);
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Orientation::Horizontal);
        verticalLayoutWidget = new QWidget(splitter);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        HDU_List = new QTableWidget(verticalLayoutWidget);
        if (HDU_List->columnCount() < 2)
            HDU_List->setColumnCount(2);
        HDU_List->setObjectName("HDU_List");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(HDU_List->sizePolicy().hasHeightForWidth());
        HDU_List->setSizePolicy(sizePolicy2);
        HDU_List->setMinimumSize(QSize(220, 0));
        HDU_List->setBaseSize(QSize(0, 0));
        HDU_List->setTabletTracking(false);
        HDU_List->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        HDU_List->setAlternatingRowColors(true);
        HDU_List->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
        HDU_List->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        HDU_List->setGridStyle(Qt::PenStyle::DashLine);
        HDU_List->setSortingEnabled(false);
        HDU_List->setColumnCount(2);
        HDU_List->horizontalHeader()->setStretchLastSection(true);
        HDU_List->verticalHeader()->setStretchLastSection(false);

        verticalLayout_2->addWidget(HDU_List);

        splitter->addWidget(verticalLayoutWidget);
        verticalLayoutWidget_2 = new QWidget(splitter);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayout = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tab_widget = new QTabWidget(verticalLayoutWidget_2);
        tab_widget->setObjectName("tab_widget");
        tab_widget->setEnabled(true);
        tab_widget->setTabShape(QTabWidget::TabShape::Triangular);
        tab_widget->setTabsClosable(true);
        tab_widget->setMovable(true);
        tab_widget->setTabBarAutoHide(false);

        verticalLayout->addWidget(tab_widget);

        splitter->addWidget(verticalLayoutWidget_2);

        verticalLayout_3->addWidget(splitter);

        statusbar = new MyStatusBar(centralwidget);
        statusbar->setObjectName("statusbar");

        verticalLayout_3->addWidget(statusbar);

        DFits->setCentralWidget(centralwidget);
        menubar = new QMenuBar(DFits);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 27));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName("menuEdit");
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName("menuHelp");
        menuTools = new QMenu(menubar);
        menuTools->setObjectName("menuTools");
        menuImage = new QMenu(menuTools);
        menuImage->setObjectName("menuImage");
        menuImage->setEnabled(false);
        menuStatistics = new QMenu(menuTools);
        menuStatistics->setObjectName("menuStatistics");
        menuStatistics->setEnabled(false);
        menuMarker = new QMenu(menuTools);
        menuMarker->setObjectName("menuMarker");
        menuMarker->setEnabled(false);
        menuZoom = new QMenu(menubar);
        menuZoom->setObjectName("menuZoom");
        menuColormap = new QMenu(menubar);
        menuColormap->setObjectName("menuColormap");
        DFits->setMenuBar(menubar);
        toolbar = new QToolBar(DFits);
        toolbar->setObjectName("toolbar");
        toolbar->setAllowedAreas(Qt::ToolBarArea::TopToolBarArea);
        DFits->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuTools->menuAction());
        menubar->addAction(menuColormap->menuAction());
        menubar->addAction(menuZoom->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionOpen_Recent);
        menuFile->addAction(actionClose_File);
        menuFile->addAction(actionxport);
        menuFile->addAction(actionSave_As);
        menuFile->addAction(actionExport);
        menuFile->addAction(actionExit);
        menuEdit->addAction(actionPreferences);
        menuHelp->addSeparator();
        menuHelp->addAction(actionAbout);
        menuTools->addAction(menuImage->menuAction());
        menuTools->addAction(menuStatistics->menuAction());
        menuTools->addAction(menuMarker->menuAction());
        menuImage->addAction(actionColormap);
        menuStatistics->addAction(actionImageStatisticsOverview);
        menuStatistics->addAction(actionLight_Curve);
        menuMarker->addAction(actionMarker_Mode);
        menuMarker->addAction(actionList_Markers);
        menuMarker->addAction(actionHideAll_Markers);
        menuMarker->addAction(actionDelete_Markers);
        menuZoom->addAction(actionFit_to_Width);
        menuZoom->addAction(actionFit_to_Height);
        menuZoom->addAction(actionZoom0);
        menuZoom->addAction(actionZoom25);
        menuZoom->addAction(actionZoom50);
        menuZoom->addAction(actionZoom75);
        menuZoom->addAction(actionZoom100);
        menuColormap->addAction(actionNoColormap);
        menuColormap->addAction(actionGrayscale);
        menuColormap->addAction(actionBone);
        menuColormap->addAction(actionCool);
        menuColormap->addAction(actionHot);
        menuColormap->addAction(actionHSV);
        menuColormap->addAction(actionJet);
        menuColormap->addAction(actionOcean);
        menuColormap->addAction(actionParula);
        menuColormap->addAction(actionPink);
        menuColormap->addAction(actionRainbow);
        menuColormap->addAction(actionSpring);
        menuColormap->addAction(actionSummer);
        menuColormap->addAction(actionTurbo);
        menuColormap->addAction(actionWinter);
        menuColormap->addAction(actionAutumn);
        menuColormap->addSeparator();
        menuColormap->addAction(actionCustom);
        toolbar->addAction(actionopen_toolbar);
        toolbar->addSeparator();
        toolbar->addAction(actionoverview);
        toolbar->addAction(actionoverview_raw);
        toolbar->addAction(actionSave_toolbar);
        toolbar->addAction(action_export_toolbar);
        toolbar->addAction(actionDeleteAllMarkers);
        toolbar->addAction(actionMarkerMode);

        retranslateUi(DFits);
        QObject::connect(actionExit, &QAction::triggered, DFits, qOverload<>(&QMainWindow::close));

        tab_widget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(DFits);
    } // setupUi

    void retranslateUi(QMainWindow *DFits)
    {
        DFits->setWindowTitle(QCoreApplication::translate("DFits", "DFits", nullptr));
        actionOpen->setText(QCoreApplication::translate("DFits", "Open", nullptr));
#if QT_CONFIG(shortcut)
        actionOpen->setShortcut(QCoreApplication::translate("DFits", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionExit->setText(QCoreApplication::translate("DFits", "Exit", nullptr));
        actionPreferences->setText(QCoreApplication::translate("DFits", "Preferences", nullptr));
        actionAbout->setText(QCoreApplication::translate("DFits", "About", nullptr));
        actionColormap->setText(QCoreApplication::translate("DFits", "Colormap", nullptr));
        actionOpen_Recent->setText(QCoreApplication::translate("DFits", "Open Recent", nullptr));
        actionoverview->setText(QCoreApplication::translate("DFits", "overview", nullptr));
#if QT_CONFIG(tooltip)
        actionoverview->setToolTip(QCoreApplication::translate("DFits", "Overview", nullptr));
#endif // QT_CONFIG(tooltip)
        actionopen_toolbar->setText(QCoreApplication::translate("DFits", "open_toolbar", nullptr));
#if QT_CONFIG(tooltip)
        actionopen_toolbar->setToolTip(QCoreApplication::translate("DFits", "Open File", nullptr));
#endif // QT_CONFIG(tooltip)
        actionoverview_raw->setText(QCoreApplication::translate("DFits", "Raw Overview", nullptr));
        actionLight_Curve->setText(QCoreApplication::translate("DFits", "Light Curve", nullptr));
        actionxport->setText(QCoreApplication::translate("DFits", "Save", nullptr));
        actionSave_toolbar->setText(QCoreApplication::translate("DFits", "Save", nullptr));
        action_export_toolbar->setText(QCoreApplication::translate("DFits", "export", nullptr));
        actionDeleteAllMarkers->setText(QCoreApplication::translate("DFits", "DeleteAllMarkers", nullptr));
        actionFit_to_Width->setText(QCoreApplication::translate("DFits", "Fit to Width", nullptr));
        actionFit_to_Height->setText(QCoreApplication::translate("DFits", "Fit to Height", nullptr));
        actionZoom0->setText(QCoreApplication::translate("DFits", "0%", nullptr));
        actionZoom25->setText(QCoreApplication::translate("DFits", "25%", nullptr));
        actionZoom50->setText(QCoreApplication::translate("DFits", "50%", nullptr));
        actionZoom75->setText(QCoreApplication::translate("DFits", "75%", nullptr));
        actionZoom100->setText(QCoreApplication::translate("DFits", "100%", nullptr));
        actionClose_File->setText(QCoreApplication::translate("DFits", "Close Session", nullptr));
        actionMarkerMode->setText(QCoreApplication::translate("DFits", "MarkerMode", nullptr));
#if QT_CONFIG(shortcut)
        actionMarkerMode->setShortcut(QCoreApplication::translate("DFits", "M", nullptr));
#endif // QT_CONFIG(shortcut)
        actionList_Markers->setText(QCoreApplication::translate("DFits", "List Markers", nullptr));
        actionDelete_Markers->setText(QCoreApplication::translate("DFits", "Delete All Markers", nullptr));
        actionBone->setText(QCoreApplication::translate("DFits", "Bone", nullptr));
        actionCool->setText(QCoreApplication::translate("DFits", "Cool", nullptr));
        actionHot->setText(QCoreApplication::translate("DFits", "Hot", nullptr));
        actionHSV->setText(QCoreApplication::translate("DFits", "HSV", nullptr));
        actionJet->setText(QCoreApplication::translate("DFits", "Jet", nullptr));
        actionOcean->setText(QCoreApplication::translate("DFits", "Ocean", nullptr));
        actionParula->setText(QCoreApplication::translate("DFits", "Parula", nullptr));
        actionPink->setText(QCoreApplication::translate("DFits", "Pink", nullptr));
        actionRainbow->setText(QCoreApplication::translate("DFits", "Rainbow", nullptr));
        actionSpring->setText(QCoreApplication::translate("DFits", "Spring", nullptr));
        actionSummer->setText(QCoreApplication::translate("DFits", "Summer", nullptr));
        actionTurbo->setText(QCoreApplication::translate("DFits", "Turbo", nullptr));
        actionWinter->setText(QCoreApplication::translate("DFits", "Winter", nullptr));
        actionAutumn->setText(QCoreApplication::translate("DFits", "Autumn", nullptr));
        actionGrayscale->setText(QCoreApplication::translate("DFits", "Grayscale", nullptr));
        actionCustom->setText(QCoreApplication::translate("DFits", "Custom", nullptr));
        actionMarker_Mode->setText(QCoreApplication::translate("DFits", "Marker Mode", nullptr));
        actionImageStatisticsOverview->setText(QCoreApplication::translate("DFits", "Overview", nullptr));
        actionHideAll_Markers->setText(QCoreApplication::translate("DFits", "Hide All Markers", nullptr));
        actionSave_As->setText(QCoreApplication::translate("DFits", "Save As", nullptr));
        actionExport->setText(QCoreApplication::translate("DFits", "Export", nullptr));
        actionNoColormap->setText(QCoreApplication::translate("DFits", "No Colormap", nullptr));
        menuFile->setTitle(QCoreApplication::translate("DFits", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("DFits", "Edit", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("DFits", "Help", nullptr));
        menuTools->setTitle(QCoreApplication::translate("DFits", "Tools", nullptr));
        menuImage->setTitle(QCoreApplication::translate("DFits", "Image", nullptr));
        menuStatistics->setTitle(QCoreApplication::translate("DFits", "Statistics", nullptr));
        menuMarker->setTitle(QCoreApplication::translate("DFits", "Marker", nullptr));
        menuZoom->setTitle(QCoreApplication::translate("DFits", "Zoom", nullptr));
        menuColormap->setTitle(QCoreApplication::translate("DFits", "Colormap", nullptr));
        toolbar->setWindowTitle(QCoreApplication::translate("DFits", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DFits: public Ui_DFits {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FITSEXPLORER_H
