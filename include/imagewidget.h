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
#include <QStackedWidget>
#include "mygraphicsview.h"

namespace Ui {
class ImageWidget;
}

class ImageWidget : public QStackedWidget
{
    Q_OBJECT

public:
    explicit ImageWidget(QWidget *parent = nullptr);
    ~ImageWidget();

    QSlider* GetSlider();
    QImage GetImage();
    void setImage(QImage);
    void scaleImage(float);
    void adjustScrollBar(QScrollBar *scrollBar, double factor);
    inline void SetData(float *data)
    {
        image_data = data;
    }

    MyGraphicsView *GetGraphicsView();
    void setPixmap(QPixmap pix);
private:
    Ui::ImageWidget *ui;

    QImage scaledImage;
    QImage originalImage;

    float *image_data;

    double scaleFactor = 1;


private slots:
    void on_reset_brightness_btn_clicked();
};

#endif // IMAGEWIDGET_H
