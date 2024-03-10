#include "imagewidget.h"
#include "ui_imagewidget.h"
#include <QMessageBox>
#include <QString>

ImageWidget::ImageWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ImageWidget)
{
    ui->setupUi(this);
    ui->image_label->setScaledContents(true);
}

QSlider* ImageWidget::GetSlider() { return ui->slider; }
QImage ImageWidget::GetImage() { return ui->image_label->pixmap(Qt::ReturnByValue).toImage(); }

void ImageWidget::setImage(QImage img)
{
    ui->image_label->setPixmap(QPixmap::fromImage(img).scaled(img.width(),
                                                              img.height(),
                                                              Qt::KeepAspectRatio));
}

void ImageWidget::wheelEvent(QWheelEvent *event)
{
    if(event->modifiers() == Qt::ControlModifier)
    {

    }
}

void ImageWidget::scaleImage(float factor)
{
    scaleFactor *= factor;
    ui->image_label->resize(scaleFactor * ui->image_label->pixmap(Qt::ReturnByValue).size());

    adjustScrollBar(ui->scrollArea->horizontalScrollBar(), factor);
    adjustScrollBar(ui->scrollArea->verticalScrollBar(), factor);

}

void ImageWidget::adjustScrollBar(QScrollBar *scrollBar, double factor)
{
    scrollBar->setValue(int(factor * scrollBar->value()
                            + ((factor - 1) * scrollBar->pageStep()/2)));
}

void ImageWidget::ZoomIn()
{
    scaleImage(1.25);
}

void ImageWidget::ZoomOut()
{
    scaleImage(0.8);
}

ImageWidget::~ImageWidget()
{
    delete ui;
}

void ImageWidget::on_zoomInBtn_clicked()
{
    ZoomIn();
}


void ImageWidget::on_zoomOutBtn_clicked()
{
    ZoomOut();
}
