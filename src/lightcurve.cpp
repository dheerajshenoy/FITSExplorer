#include "lightcurve.h"
#include "ui_lightcurve.h"
#include <QFileDialog>
#include "imagewidget.h"


LightCurve::LightCurve(ImageWidget *img_widget)
    : m_img_widget(img_widget)
    , ui(new Ui::LightCurve)
{
    ui->setupUi(this);
    INIT_Graph();

}

void LightCurve::setImageWidget(ImageWidget *img_widget)
{
    m_img_widget = img_widget;
}

void LightCurve::INIT_Graph()
{
    ui->plot_widget->addGraph();
    ui->plot_widget->graph(0)->setLineStyle(QCPGraph::LineStyle::lsLine);
    ui->plot_widget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
}

void LightCurve::setData(float *data, int width, int height)
{
    ui->plot_widget->graph(0)->data()->clear();
    for(int i=0; i < width; i++)
    {
        double m = 0;
        for(int j=0; j < height; j++)
        {
            m += data[j * width + i];
        }
        m = m / height; // average per column
        ui->plot_widget->graph(0)->addData(i, m);
    }
    ui->plot_widget->graph(0)->rescaleAxes(true);
    ui->plot_widget->update();
}

LightCurve::~LightCurve()
{
    delete ui;
}

void LightCurve::on_save_btn_clicked()
{
    QFileDialog fd;
    QString filename = fd.getSaveFileName(this,
                           "Save File As",
                           "",
                           "Image Files(*.jpg *.bmp *.png);;PDF (*.pdf)");
    if(filename.endsWith(".png"))
    {
        ui->plot_widget->savePng(filename, 0, 1, -1,
                                 300 * QCP::ResolutionUnit::ruDotsPerInch);
    }

    if(filename.endsWith(".jpeg") || filename.endsWith(".jpg"))
    {
        ui->plot_widget->saveJpg(filename, 0, 1, -1,
                                 300 * QCP::ResolutionUnit::ruDotsPerInch);
    }

    if(filename.endsWith(".bmp"))
    {
        ui->plot_widget->saveBmp(filename, 0, 1, -1,
                                 300 * QCP::ResolutionUnit::ruDotsPerInch);
    }

    if(filename.endsWith(".pdf"))
    {
        ui->plot_widget->savePdf(filename);
    }
}
