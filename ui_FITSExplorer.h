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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <mystatusbar.h>

QT_BEGIN_NAMESPACE

class Ui_FITSExplorer
{
public:
    QAction *actionOpen;
    QAction *actionExit;
    QAction *actionPreferences;
    QAction *actionAbout;
    QAction *actionSelect;
    QAction *actionOpen_Recent;
    QAction *actionoverview;
    QAction *actionopen_toolbar;
    QAction *actionLight_Curve;
    QAction *actionxport;
    QAction *actionSave_toolbar;
    QAction *action_export_toolbar;
    QAction *actionFit_to_Width;
    QAction *actionFit_to_Height;
    QAction *actionZoom0;
    QAction *actionZoom25;
    QAction *actionZoom50;
    QAction *actionZoom75;
    QAction *actionZoom100;
    QAction *actionClose_File;
    QAction *actionList_Markers;
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
    QAction *actionMarker_Mode;
    QAction *actionImageStatisticsOverview;
    QAction *actionHideAll_Markers;
    QAction *actionSave_As;
    QAction *actionExport;
    QAction *actionNoColormap;
    QAction *action94;
    QAction *action131;
    QAction *action171;
    QAction *action193;
    QAction *action211;
    QAction *action304;
    QAction *action1600;
    QAction *action4500;
    QAction *action1700;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QSplitter *splitter;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *HDU_List;
    QPushButton *reset_brightness_btn;
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
    QMenu *menuSDO_AIA;

    void setupUi(QMainWindow *FITSExplorer)
    {
        if (FITSExplorer->objectName().isEmpty())
            FITSExplorer->setObjectName("FITSExplorer");
        FITSExplorer->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FITSExplorer->sizePolicy().hasHeightForWidth());
        FITSExplorer->setSizePolicy(sizePolicy);
        FITSExplorer->setMinimumSize(QSize(200, 0));
        actionOpen = new QAction(FITSExplorer);
        actionOpen->setObjectName("actionOpen");
        actionExit = new QAction(FITSExplorer);
        actionExit->setObjectName("actionExit");
        actionPreferences = new QAction(FITSExplorer);
        actionPreferences->setObjectName("actionPreferences");
        actionAbout = new QAction(FITSExplorer);
        actionAbout->setObjectName("actionAbout");
        actionSelect = new QAction(FITSExplorer);
        actionSelect->setObjectName("actionSelect");
        actionSelect->setCheckable(true);
        actionOpen_Recent = new QAction(FITSExplorer);
        actionOpen_Recent->setObjectName("actionOpen_Recent");
        actionoverview = new QAction(FITSExplorer);
        actionoverview->setObjectName("actionoverview");
        actionoverview->setEnabled(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../Downloads/file-color-icon.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionoverview->setIcon(icon);
        actionoverview->setMenuRole(QAction::MenuRole::NoRole);
        actionopen_toolbar = new QAction(FITSExplorer);
        actionopen_toolbar->setObjectName("actionopen_toolbar");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../../Downloads/file-manager-icon.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionopen_toolbar->setIcon(icon1);
        actionopen_toolbar->setMenuRole(QAction::MenuRole::NoRole);
        actionLight_Curve = new QAction(FITSExplorer);
        actionLight_Curve->setObjectName("actionLight_Curve");
        actionLight_Curve->setEnabled(true);
        actionxport = new QAction(FITSExplorer);
        actionxport->setObjectName("actionxport");
        actionxport->setEnabled(false);
        actionSave_toolbar = new QAction(FITSExplorer);
        actionSave_toolbar->setObjectName("actionSave_toolbar");
        actionSave_toolbar->setEnabled(false);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../../Downloads/diskette-save-svgrepo-com.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionSave_toolbar->setIcon(icon2);
        actionSave_toolbar->setMenuRole(QAction::MenuRole::NoRole);
        action_export_toolbar = new QAction(FITSExplorer);
        action_export_toolbar->setObjectName("action_export_toolbar");
        action_export_toolbar->setEnabled(false);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("../../Downloads/export-svgrepo-com.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        action_export_toolbar->setIcon(icon3);
        action_export_toolbar->setMenuRole(QAction::MenuRole::NoRole);
        actionFit_to_Width = new QAction(FITSExplorer);
        actionFit_to_Width->setObjectName("actionFit_to_Width");
        actionFit_to_Height = new QAction(FITSExplorer);
        actionFit_to_Height->setObjectName("actionFit_to_Height");
        actionZoom0 = new QAction(FITSExplorer);
        actionZoom0->setObjectName("actionZoom0");
        actionZoom25 = new QAction(FITSExplorer);
        actionZoom25->setObjectName("actionZoom25");
        actionZoom50 = new QAction(FITSExplorer);
        actionZoom50->setObjectName("actionZoom50");
        actionZoom75 = new QAction(FITSExplorer);
        actionZoom75->setObjectName("actionZoom75");
        actionZoom100 = new QAction(FITSExplorer);
        actionZoom100->setObjectName("actionZoom100");
        actionClose_File = new QAction(FITSExplorer);
        actionClose_File->setObjectName("actionClose_File");
        actionList_Markers = new QAction(FITSExplorer);
        actionList_Markers->setObjectName("actionList_Markers");
        actionBone = new QAction(FITSExplorer);
        actionBone->setObjectName("actionBone");
        actionBone->setCheckable(true);
        actionCool = new QAction(FITSExplorer);
        actionCool->setObjectName("actionCool");
        actionCool->setCheckable(true);
        actionHot = new QAction(FITSExplorer);
        actionHot->setObjectName("actionHot");
        actionHot->setCheckable(true);
        actionHSV = new QAction(FITSExplorer);
        actionHSV->setObjectName("actionHSV");
        actionHSV->setCheckable(true);
        actionJet = new QAction(FITSExplorer);
        actionJet->setObjectName("actionJet");
        actionJet->setCheckable(true);
        actionOcean = new QAction(FITSExplorer);
        actionOcean->setObjectName("actionOcean");
        actionOcean->setCheckable(true);
        actionParula = new QAction(FITSExplorer);
        actionParula->setObjectName("actionParula");
        actionParula->setCheckable(true);
        actionPink = new QAction(FITSExplorer);
        actionPink->setObjectName("actionPink");
        actionPink->setCheckable(true);
        actionRainbow = new QAction(FITSExplorer);
        actionRainbow->setObjectName("actionRainbow");
        actionRainbow->setCheckable(true);
        actionSpring = new QAction(FITSExplorer);
        actionSpring->setObjectName("actionSpring");
        actionSpring->setCheckable(true);
        actionSummer = new QAction(FITSExplorer);
        actionSummer->setObjectName("actionSummer");
        actionSummer->setCheckable(true);
        actionTurbo = new QAction(FITSExplorer);
        actionTurbo->setObjectName("actionTurbo");
        actionTurbo->setCheckable(true);
        actionWinter = new QAction(FITSExplorer);
        actionWinter->setObjectName("actionWinter");
        actionWinter->setCheckable(true);
        actionAutumn = new QAction(FITSExplorer);
        actionAutumn->setObjectName("actionAutumn");
        actionAutumn->setCheckable(true);
        actionGrayscale = new QAction(FITSExplorer);
        actionGrayscale->setObjectName("actionGrayscale");
        actionGrayscale->setCheckable(true);
        actionMarker_Mode = new QAction(FITSExplorer);
        actionMarker_Mode->setObjectName("actionMarker_Mode");
        actionMarker_Mode->setCheckable(true);
        actionImageStatisticsOverview = new QAction(FITSExplorer);
        actionImageStatisticsOverview->setObjectName("actionImageStatisticsOverview");
        actionHideAll_Markers = new QAction(FITSExplorer);
        actionHideAll_Markers->setObjectName("actionHideAll_Markers");
        actionHideAll_Markers->setCheckable(true);
        actionSave_As = new QAction(FITSExplorer);
        actionSave_As->setObjectName("actionSave_As");
        actionExport = new QAction(FITSExplorer);
        actionExport->setObjectName("actionExport");
        actionNoColormap = new QAction(FITSExplorer);
        actionNoColormap->setObjectName("actionNoColormap");
        actionNoColormap->setCheckable(true);
        action94 = new QAction(FITSExplorer);
        action94->setObjectName("action94");
        action131 = new QAction(FITSExplorer);
        action131->setObjectName("action131");
        action171 = new QAction(FITSExplorer);
        action171->setObjectName("action171");
        action193 = new QAction(FITSExplorer);
        action193->setObjectName("action193");
        action211 = new QAction(FITSExplorer);
        action211->setObjectName("action211");
        action304 = new QAction(FITSExplorer);
        action304->setObjectName("action304");
        action1600 = new QAction(FITSExplorer);
        action1600->setObjectName("action1600");
        action4500 = new QAction(FITSExplorer);
        action4500->setObjectName("action4500");
        action1700 = new QAction(FITSExplorer);
        action1700->setObjectName("action1700");
        centralwidget = new QWidget(FITSExplorer);
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

        reset_brightness_btn = new QPushButton(verticalLayoutWidget);
        reset_brightness_btn->setObjectName("reset_brightness_btn");

        verticalLayout_2->addWidget(reset_brightness_btn);

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

        FITSExplorer->setCentralWidget(centralwidget);
        menubar = new QMenuBar(FITSExplorer);
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
        menuImage->setEnabled(true);
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
        menuSDO_AIA = new QMenu(menuColormap);
        menuSDO_AIA->setObjectName("menuSDO_AIA");
        FITSExplorer->setMenuBar(menubar);

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
        menuImage->addAction(actionSelect);
        menuStatistics->addAction(actionImageStatisticsOverview);
        menuStatistics->addAction(actionLight_Curve);
        menuMarker->addAction(actionMarker_Mode);
        menuMarker->addAction(actionList_Markers);
        menuMarker->addAction(actionHideAll_Markers);
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
        menuColormap->addSeparator();
        menuColormap->addAction(menuSDO_AIA->menuAction());
        menuSDO_AIA->addAction(action94);
        menuSDO_AIA->addAction(action131);
        menuSDO_AIA->addAction(action171);
        menuSDO_AIA->addAction(action193);
        menuSDO_AIA->addAction(action211);
        menuSDO_AIA->addAction(action304);
        menuSDO_AIA->addAction(action1600);
        menuSDO_AIA->addAction(action1700);
        menuSDO_AIA->addAction(action4500);

        retranslateUi(FITSExplorer);
        QObject::connect(actionExit, &QAction::triggered, FITSExplorer, qOverload<>(&QMainWindow::close));

        tab_widget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(FITSExplorer);
    } // setupUi

    void retranslateUi(QMainWindow *FITSExplorer)
    {
        FITSExplorer->setWindowTitle(QCoreApplication::translate("FITSExplorer", "FITSExplorer", nullptr));
        actionOpen->setText(QCoreApplication::translate("FITSExplorer", "Open", nullptr));
#if QT_CONFIG(shortcut)
        actionOpen->setShortcut(QCoreApplication::translate("FITSExplorer", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionExit->setText(QCoreApplication::translate("FITSExplorer", "Exit", nullptr));
        actionPreferences->setText(QCoreApplication::translate("FITSExplorer", "Preferences", nullptr));
        actionAbout->setText(QCoreApplication::translate("FITSExplorer", "About", nullptr));
        actionSelect->setText(QCoreApplication::translate("FITSExplorer", "Select", nullptr));
        actionOpen_Recent->setText(QCoreApplication::translate("FITSExplorer", "Open Recent", nullptr));
        actionoverview->setText(QCoreApplication::translate("FITSExplorer", "overview", nullptr));
#if QT_CONFIG(tooltip)
        actionoverview->setToolTip(QCoreApplication::translate("FITSExplorer", "Overview", nullptr));
#endif // QT_CONFIG(tooltip)
        actionopen_toolbar->setText(QCoreApplication::translate("FITSExplorer", "open_toolbar", nullptr));
#if QT_CONFIG(tooltip)
        actionopen_toolbar->setToolTip(QCoreApplication::translate("FITSExplorer", "Open File", nullptr));
#endif // QT_CONFIG(tooltip)
        actionLight_Curve->setText(QCoreApplication::translate("FITSExplorer", "Light Curve", nullptr));
        actionxport->setText(QCoreApplication::translate("FITSExplorer", "Save", nullptr));
        actionSave_toolbar->setText(QCoreApplication::translate("FITSExplorer", "Save", nullptr));
        action_export_toolbar->setText(QCoreApplication::translate("FITSExplorer", "export", nullptr));
        actionFit_to_Width->setText(QCoreApplication::translate("FITSExplorer", "Fit to Width", nullptr));
        actionFit_to_Height->setText(QCoreApplication::translate("FITSExplorer", "Fit to Height", nullptr));
        actionZoom0->setText(QCoreApplication::translate("FITSExplorer", "0%", nullptr));
        actionZoom25->setText(QCoreApplication::translate("FITSExplorer", "25%", nullptr));
        actionZoom50->setText(QCoreApplication::translate("FITSExplorer", "50%", nullptr));
        actionZoom75->setText(QCoreApplication::translate("FITSExplorer", "75%", nullptr));
        actionZoom100->setText(QCoreApplication::translate("FITSExplorer", "100%", nullptr));
        actionClose_File->setText(QCoreApplication::translate("FITSExplorer", "Close Session", nullptr));
        actionList_Markers->setText(QCoreApplication::translate("FITSExplorer", "List Markers", nullptr));
        actionBone->setText(QCoreApplication::translate("FITSExplorer", "Bone", nullptr));
        actionCool->setText(QCoreApplication::translate("FITSExplorer", "Cool", nullptr));
        actionHot->setText(QCoreApplication::translate("FITSExplorer", "Hot", nullptr));
        actionHSV->setText(QCoreApplication::translate("FITSExplorer", "HSV", nullptr));
        actionJet->setText(QCoreApplication::translate("FITSExplorer", "Jet", nullptr));
        actionOcean->setText(QCoreApplication::translate("FITSExplorer", "Ocean", nullptr));
        actionParula->setText(QCoreApplication::translate("FITSExplorer", "Parula", nullptr));
        actionPink->setText(QCoreApplication::translate("FITSExplorer", "Pink", nullptr));
        actionRainbow->setText(QCoreApplication::translate("FITSExplorer", "Rainbow", nullptr));
        actionSpring->setText(QCoreApplication::translate("FITSExplorer", "Spring", nullptr));
        actionSummer->setText(QCoreApplication::translate("FITSExplorer", "Summer", nullptr));
        actionTurbo->setText(QCoreApplication::translate("FITSExplorer", "Turbo", nullptr));
        actionWinter->setText(QCoreApplication::translate("FITSExplorer", "Winter", nullptr));
        actionAutumn->setText(QCoreApplication::translate("FITSExplorer", "Autumn", nullptr));
        actionGrayscale->setText(QCoreApplication::translate("FITSExplorer", "Grayscale", nullptr));
        actionMarker_Mode->setText(QCoreApplication::translate("FITSExplorer", "Marker Mode", nullptr));
        actionImageStatisticsOverview->setText(QCoreApplication::translate("FITSExplorer", "Overview", nullptr));
        actionHideAll_Markers->setText(QCoreApplication::translate("FITSExplorer", "Hide All Markers", nullptr));
        actionSave_As->setText(QCoreApplication::translate("FITSExplorer", "Save As", nullptr));
        actionExport->setText(QCoreApplication::translate("FITSExplorer", "Export", nullptr));
        actionNoColormap->setText(QCoreApplication::translate("FITSExplorer", "No Colormap", nullptr));
        action94->setText(QCoreApplication::translate("FITSExplorer", "94", nullptr));
        action131->setText(QCoreApplication::translate("FITSExplorer", "131", nullptr));
        action171->setText(QCoreApplication::translate("FITSExplorer", "171", nullptr));
        action193->setText(QCoreApplication::translate("FITSExplorer", "193", nullptr));
        action211->setText(QCoreApplication::translate("FITSExplorer", "211", nullptr));
        action304->setText(QCoreApplication::translate("FITSExplorer", "304", nullptr));
        action1600->setText(QCoreApplication::translate("FITSExplorer", "1600", nullptr));
        action4500->setText(QCoreApplication::translate("FITSExplorer", "4500", nullptr));
        action1700->setText(QCoreApplication::translate("FITSExplorer", "1700", nullptr));
        reset_brightness_btn->setText(QCoreApplication::translate("FITSExplorer", "Reset Image", nullptr));
        menuFile->setTitle(QCoreApplication::translate("FITSExplorer", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("FITSExplorer", "Edit", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("FITSExplorer", "Help", nullptr));
        menuTools->setTitle(QCoreApplication::translate("FITSExplorer", "Tools", nullptr));
        menuImage->setTitle(QCoreApplication::translate("FITSExplorer", "Image", nullptr));
        menuStatistics->setTitle(QCoreApplication::translate("FITSExplorer", "Statistics", nullptr));
        menuMarker->setTitle(QCoreApplication::translate("FITSExplorer", "Marker", nullptr));
        menuZoom->setTitle(QCoreApplication::translate("FITSExplorer", "Zoom", nullptr));
        menuColormap->setTitle(QCoreApplication::translate("FITSExplorer", "Colormap", nullptr));
        menuSDO_AIA->setTitle(QCoreApplication::translate("FITSExplorer", "SDO AIA", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FITSExplorer: public Ui_FITSExplorer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FITSEXPLORER_H
