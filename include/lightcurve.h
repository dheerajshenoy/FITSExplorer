#ifndef LIGHTCURVE_H
#define LIGHTCURVE_H

#include <QWidget>
#include <QChart>
#include <QLineSeries>
#include <QChartView>
#include <QVBoxLayout>
#include "imagewidget.h"

namespace Ui {
class LightCurve;
}

class LightCurve : public QWidget
{
    Q_OBJECT

public:
    explicit LightCurve(ImageWidget *parent = nullptr);
    ~LightCurve();

    void setData(float* image_data, int row, int col);

    void setImageWidget(ImageWidget *img_widget);
    void INIT_Graph();

private:
    Ui::LightCurve *ui;
    QVBoxLayout *m_layout = new QVBoxLayout();
    ImageWidget *m_img_widget;

private slots:
    void on_save_btn_clicked();
};

#endif // LIGHTCURVE_H
