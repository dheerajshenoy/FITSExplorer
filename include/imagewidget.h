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
#include <QRubberBand>
#include <QMouseEvent>
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
    MyGraphicsView *GetGraphicsView();
    void setPixmap(QPixmap pix);

signals:
    void changeBrightness();


private:
    Ui::ImageWidget *ui;

    QImage scaledImage;
    QImage originalImage;

    double scaleFactor = 1;

};

#endif // IMAGEWIDGET_H
