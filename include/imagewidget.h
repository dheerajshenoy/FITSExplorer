#ifndef IMAGEWIDGET_H
#define IMAGEWIDGET_H

#include <QWidget>
#include <QSlider>
#include <QLabel>
#include <QWheelEvent>
#include <QImage>
#include <QPixmap>
#include <QScrollArea>
#include <QScrollBar>
#include "mygraphicsview.h"

namespace Ui {
class ImageWidget;
}

class ImageWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ImageWidget(QWidget *parent = nullptr);
    ~ImageWidget();

    QSlider* GetSlider();
    QImage GetImage();
    void setPixmap(QPixmap);

    inline void SetData(float* data) { image_data = data; }
    inline void* GetData() { return image_data; }

    MyGraphicsView* GetGraphicsView();

private slots:
    void on_reset_brightness_btn_clicked();

private:
    Ui::ImageWidget *ui;

    double scaleFactor = 1;

    float *image_data = nullptr;

};

#endif // IMAGEWIDGET_H
