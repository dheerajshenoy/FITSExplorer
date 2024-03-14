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
QImage ImageWidget::GetImage() { return ui->image_label->pixmap(Qt::ReturnByValue).copy().toImage(); }

void ImageWidget::setImage(QImage img)
{
    //originalImage = img;


    ui->image_label->setPixmap(QPixmap::fromImage(img).scaled(img.width(),
                                                              img.height(),
                                                              Qt::KeepAspectRatio));
    //QMessageBox::information(this, "DD",
    //                         QString("{%1} {%2} {%3}").arg(ui->image_label->size().height())
    //                             .arg(ui->image_label->size().width()).arg("DD"));
    //ui->image_label->resize(scaleFactor * img.size());
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

//zoomInAct->setEnabled(scaleFactor < 3.0);
 //  zoomOutAct->setEnabled(scaleFactor > 0.333);
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

