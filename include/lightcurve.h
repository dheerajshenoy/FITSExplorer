#ifndef LIGHTCURVE_H
#define LIGHTCURVE_H

#include <QWidget>
#include <QVBoxLayout>
#include "imagewidget.h"
#include "qcustomplot.h"

namespace Ui {
class LightCurve;
}

class LightCurve : public QWidget
{
    Q_OBJECT

public:
    explicit LightCurve(ImageWidget *parent = nullptr);
    ~LightCurve();

    void setData(const float* image_data, const int row, const int col);
    void addLine(float, float);
    void setImageWidget(ImageWidget *img_widget);
    void INIT_Graph();

    QCustomPlot *getPlot();
    void Show();

    void addLineToList(QCPItemStraightLine *);
    void clearLines();
    inline int numLines()
    {
        return m_line_list.count();
    }

    QCPItemStraightLine *getLineAt(int index);
private:
    Ui::LightCurve *ui;
    QVBoxLayout *m_layout = new QVBoxLayout();
    ImageWidget *m_img_widget;
    QVector<QCPItemStraightLine*> m_line_list;

private slots:
    void on_save_btn_clicked();
};

#endif // LIGHTCURVE_H
