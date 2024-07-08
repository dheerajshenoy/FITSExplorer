#include "pixanalyser.h"
#include "ui_pixanalyser.h"

PixAnalyser::PixAnalyser(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PixAnalyser)
{
    ui->setupUi(this);

    this->hide();
    this->setFixedSize(QSize(50, 50));
    this->setBackgroundRole(QPalette::Accent);
    this->setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
    this->raise();
}

void PixAnalyser::setPixValue(float val)
{
    ui->pixvalue_label->setText(QString::number(val));
}

float PixAnalyser::getPixValue()
{
    return ui->pixvalue_label->text().toFloat();
}

void PixAnalyser::setImg(QImage img)
{
    ui->preview_label->setPixmap(QPixmap::fromImage(img));
}

PixAnalyser::~PixAnalyser()
{
    delete ui;
}
