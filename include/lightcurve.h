#ifndef LIGHTCURVE_H
#define LIGHTCURVE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include "imagewidget.h"
#include <QMessageBox>
#include "qcustomplot.h"

namespace Ui {
class LightCurve;
}

class LightCurve : public QWidget
{
    Q_OBJECT

    friend ImageWidget;

public:
    explicit LightCurve(ImageWidget *img_widget);
    ~LightCurve();

    void setData(float*, int, int);
    void INIT_Graph();

public slots:

private slots:

    void on_save_btn_clicked();

private:
    ImageWidget *m_img_widget;
    Ui::LightCurve *ui;
};

#endif // LIGHTCURVE_H
