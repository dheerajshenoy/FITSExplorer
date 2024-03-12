#ifndef DFITS_H
#define DFITS_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDialog>
#include <fitsio2.h>
#include <QMessageBox>
#include <QDebug>
#include <QTableWidget>
#include <QTableWidgetItem>
#include "overview.h"
#include "imagewidget.h"
#include <QTextCursor>
#include <QPlainTextEdit>
#include <QWidget>
#include <QVBoxLayout>
#include <QSettings>
#include <QStandardPaths>
#include "aboutdialog.h"
#include "lightcurve.h"
#include "toml.hpp"
#include "preferences.h"

const QString APPNAME = "DFits";
const QString CONFIG_NAME = "config.toml";

QT_BEGIN_NAMESPACE
namespace Ui {
class DFits;
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
    int ShowOverview(int HDU_index);
    void RemoveAllMarkers();
    void INIT_Connections();
    void INIT_MiniLightCurve();
    void INIT_Configuration();
    inline void MSG(QString msg)
    {
        QMessageBox::information(this, "Information", msg);
    }
    void ReadConfigFile(QString filename = "");

private slots:
    void OpenFile(QString filename = nullptr);
    int ChangeBrightness();
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

private:
    Ui::DFits *ui;

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

    QVector<QCPItemStraightLine*> m_lines_list;
    QVector<QRgb> m_inferno;

    toml::value TOMLCFG;

    Preferences *prefs = new Preferences();

};
#endif // DFITS_H
