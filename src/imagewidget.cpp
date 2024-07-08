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

void ImageWidget::setImage(QImage img)
{
    ui->graphics_view->setPixmap(QPixmap::fromImage(img));
}

MyGraphicsView* ImageWidget::GetGraphicsView()
{
    return ui->graphics_view;
}

ImageWidget::~ImageWidget()
{
    delete ui;
}
