#include "imagewidget.h"
#include "ui_imagewidget.h"
#include <QMessageBox>
#include <QString>
#include <QSlider>
#include "colormap.h"

ImageWidget::ImageWidget(QWidget *parent)
    : QStackedWidget(parent)
    , ui(new Ui::ImageWidget)
{
    ui->setupUi(this);

    connect(ui->slider, &QSlider::sliderReleased,
            [&]() { emit changeBrightness(); });
}

QSlider* ImageWidget::GetSlider() { return ui->slider; }

QImage ImageWidget::GetImage() {
    return ui->graphics_view->GetPixmap().toImage();
}

void ImageWidget::setPixmap(QPixmap pix)
{
    ui->graphics_view->setPixmap(pix);
}

MyGraphicsView* ImageWidget::GetGraphicsView()
{
    return ui->graphics_view;
}

ImageWidget::~ImageWidget()
{
    delete ui;
}

void ImageWidget::on_reset_brightness_btn_clicked()
{
    QPixmap p = ui->graphics_view->GetPixmap();
    QImage image(p.width(), p.height(), QImage::Format_Grayscale8);
    for (int x = 0; x < p.width(); ++x) {
        double m = 0;
        for (int y = 0; y < p.height(); ++y) {
            float value = image_data[y * p.width() + x];
            image.setPixel(x, y, qRgb(value, value, value)); // Assuming grayscale image
            m += value;
        }
        m = m / p.height();
    }
    ui->graphics_view->setPixmap(QPixmap::fromImage(image));
}
