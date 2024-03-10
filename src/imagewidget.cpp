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

void ImageWidget::wheelEvent(QWheelEvent *event)
{
    if(event->modifiers() == Qt::ControlModifier)
    {

    }
}

void ImageWidget::scaleImage(float factor)
{
    scaleFactor *= factor;

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
