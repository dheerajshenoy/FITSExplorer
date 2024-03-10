#include "imagewidget.h"
#include "ui_imagewidget.h"
#include <QMessageBox>
#include <QString>
#include "colormap.h"

ImageWidget::ImageWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ImageWidget)
{
    ui->setupUi(this);
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
