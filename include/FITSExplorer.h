#ifndef DFITS_H
#define DFITS_H


#include <qt6/QtGui/QActionGroup>
#include <qt6/QtWidgets/QMainWindow>
#include <qt6/QtWidgets/QFileDialog>
#include <qt6/QtWidgets/QDialog>
#include <fitsio2.h>
#include <qt6/QtWidgets/QMessageBox>
#include <qt6/QtCore/QDebug>
#include <qt6/QtWidgets/QTableWidget>
#include <qt6/QtWidgets/QTableWidgetItem>
#include <qt6/QtGui/QTextCursor>
#include <qt6/QtWidgets/QPlainTextEdit>
#include <qt6/QtWidgets/QWidget>
#include <qt6/QtWidgets/QVBoxLayout>
#include <qt6/QtCore/QSettings>
#include <qt6/QtCore/QStandardPaths>
#include <qt6/QtGui/QShortcut>
#include <qt6/QtGui/QKeySequence>

#include "overview.h"
#include "imagewidget.h"
#include "aboutdialog.h"
#include "lightcurve.h"
#include "toml.hpp"
#include "preferences.h"
#include "qcustomplot.h"
#include "image_statistics_overview.h"
#include "file.h"

const QString APPNAME = "FITSExplorer";
const QString CONFIG_NAME = "config.toml";

QT_BEGIN_NAMESPACE
namespace Ui {
class FITSExplorer;
}
QT_END_NAMESPACE

class FITSExplorer : public QMainWindow
{
    Q_OBJECT

public:
    FITSExplorer(QStringList args, QWidget *parent = nullptr);
    ~FITSExplorer();
    int HandleFile(QString filename);
    int HandleImage();
    int HandleAsciiTable();
    int HandleBinaryTable();
    int ShowOverview();
    void RemoveAllMarkers();
    void INIT_Connections();
    void INIT_Configuration();
    inline void MSG(QString msg)
    {
        QMessageBox::information(this, "Information", msg);
    }
    void ReadConfigFile(QString filename = "");
    bool isColormapSelected();
    QImage ApplyColormap(QImage);
    void INIT_Shortcuts();
    File* getCurrentFile();
    int nfiles();

public slots:
    void HandleColorMapSelect(Colormap);
    void update_HDU_Table(int);

private slots:
    void OpenFile(QString filename = nullptr);
    void OpenRecent();
    int HDU_Table_Double_Clicked(int, int);
    void CloseTab(int);
    void ShowCoordinates(QPointF);
    void ExportFile();
    void MarkerAdded(QPointF);
    void CloseFile();
    void on_actionopen_toolbar_triggered();
    void on_actionoverview_triggered();
    void on_actionAbout_triggered();
    void on_actionoverview_raw_triggered();
    void on_actionLight_Curve_triggered();
    void on_actionxport_triggered();
    void on_actionSave_toolbar_triggered();
    void on_action_export_toolbar_triggered();
    void on_actionDeleteAllMarkers_triggered();
    void on_actionFit_to_Width_triggered();
    void on_actionClose_File_triggered();
    void on_actionPreferences_triggered();
    void on_actionMarkerMode_triggered(bool);
    void on_actionList_Markers_triggered();
    void on_actionGrayscale_triggered();
    void on_actionBone_triggered();
    void on_actionCool_triggered();
    void on_actionHot_triggered();
    void on_actionHSV_triggered();
    void on_actionJet_triggered();
    void on_actionOcean_triggered();
    void on_actionParula_triggered();
    void on_actionPink_triggered();
    void on_actionRainbow_triggered();
    void on_actionSpring_triggered();
    void on_actionSummer_triggered();
    void on_actionTurbo_triggered();
    void on_actionWinter_triggered();
    void on_actionAutumn_triggered();
    void on_actionMarker_Mode_triggered(bool);
    void on_actionImageStatisticsOverview_triggered();
    void changeMarkerLineColor(int, QColor);
    void on_actionHideAll_Markers_triggered(bool);
    void on_actionNoColormap_triggered();
    void on_action94_triggered();
    void on_action171_triggered();
    void on_action131_triggered();
    void on_action193_triggered();
    void on_action211_triggered();
    void on_reset_brightness_btn_clicked();
    void on_actionSelect_triggered();

private:

    QVector<File *> m_files_list = {};

    int m_file_index = -1;


    Ui::FITSExplorer *ui;
    ImageWidget *img_widget = new ImageWidget();
    fitsfile *fptr;
    int status = 0;
    float *image_data;
    int width, height;
    QCPItemStraightLine *m_line;
    int m_nhdu;
    int m_nkeys;
    MyGraphicsView *gv = img_widget->GetGraphicsView();
    Overview *overview = new Overview();
    LightCurve *lc = new LightCurve(img_widget);
    toml::value TOMLCFG;
    Colormap m_cur_colormap = Colormap::None;
    QCustomPlot *lightCurvePlot;
    QFile m_recentFile;
    void AddRecentFile(QString);
    QImage m_orig_img;

    bool m_should_copy_before_applying_colormap = true;

    friend class File;
};
#endif // DFITS_H
