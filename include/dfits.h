#ifndef DFITS_H
#define DFITS_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDialog>
#include "statusbar.h"
#include <fitsio2.h>
#include <QMessageBox>
#include <QDebug>
#include "colormap.h"
#include <QTableWidget>
#include "aboutdialog.h"
#include <QTableWidgetItem>
#include "overview.h"
#include "imagewidget.h"
#include <QTextCursor>
#include <QPlainTextEdit>
#include <QWidget>
#include <QVBoxLayout>
#include "lightcurve.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class DFits;
}
QT_END_NAMESPACE

class DFits : public QMainWindow
{
    Q_OBJECT

public:
    DFits(QStringList args, QWidget *parent = nullptr);
    ~DFits();
    int HandleFile(QString filename);
    int HandleImage();
    int HandleAsciiTable();
    int HandleBinaryTable();
    int ShowOverview(int HDU_index);

private slots:
    void OpenFile(QString filename = nullptr);
    int ChangeBrightness();
    int HDU_Table_Double_Clicked(int, int);
    void CloseTab(int);
    void ShowCoordinates(QPointF);
    void ExportFile();

    void on_actionopen_toolbar_triggered();
    void on_actionoverview_triggered();
    void on_actionAbout_triggered();
    void on_actionoverview_raw_triggered();
    void on_actionLight_Curve_triggered();
    void on_actionxport_triggered();
    void on_actionSave_toolbar_triggered();
    void on_action_export_toolbar_triggered();

private:
    Ui::DFits *ui;

    ImageWidget *img_widget = new ImageWidget();

    fitsfile *fptr;
    int status = 0;

    float *image_data;
    int width, height;

    int m_nhdu;

    Overview *overview;
    LightCurve *lc;

};
#endif // DFITS_H
