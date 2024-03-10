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
    void ZoomIn();
    void ZoomOut();
    void scaleImage(float);
    void adjustScrollBar(QScrollBar *scrollBar, double factor);

    inline void SetData(float* data) { image_data = data; }
    inline float* GetData() { return image_data; }

private:
    Ui::ImageWidget *ui;

    QImage scaledImage;
    QImage originalImage;

    double scaleFactor = 1;

    float *image_data;


protected:
    void wheelEvent(QWheelEvent *e) override;
private slots:
    void on_zoomInBtn_clicked();
    void on_zoomOutBtn_clicked();
};

#endif // IMAGEWIDGET_H
