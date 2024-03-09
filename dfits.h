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
#include <QTableWidgetItem>

#include "imagewidget.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class DFits;
}
QT_END_NAMESPACE

class DFits : public QMainWindow
{
    Q_OBJECT

public:
    DFits(QWidget *parent = nullptr);
    ~DFits();
    int HandleFile(QString filename);
    int HandleImage();
    int HandleAsciiTable();
    void ShowOverview(int HDU_index);

private slots:
    void OpenFile();
    int ChangeBrightness();
    void HDU_Table_Double_Clicked(int, int);
    void CloseTab(int);

    void on_actionopen_toolbar_triggered();
    void on_actionoverview_triggered();

private:
    Ui::DFits *ui;

    ImageWidget *img_widget = new ImageWidget();

    fitsfile *fptr;
    int status = 0;

    float *image_data;
    int width, height;

};
#endif // DFITS_H
