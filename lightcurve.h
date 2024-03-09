#ifndef LIGHTCURVE_H
#define LIGHTCURVE_H

#include <QWidget>
#include <QChart>
#include <QLineSeries>
#include <QChartView>
#include <QVBoxLayout>

namespace Ui {
class LightCurve;
}

class LightCurve : public QWidget
{
    Q_OBJECT

public:
    explicit LightCurve(QWidget *parent = nullptr);
    ~LightCurve();

    void setData(float* image_data, int row, int col);

private:
    Ui::LightCurve *ui;
    QVBoxLayout *m_layout = new QVBoxLayout();
};

#endif // LIGHTCURVE_H
