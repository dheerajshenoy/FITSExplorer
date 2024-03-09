#include "lightcurve.h"
#include "ui_lightcurve.h"

LightCurve::LightCurve(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LightCurve)
{
    ui->setupUi(this);

    this->setLayout(m_layout);
}

void LightCurve::setData(float* data, int row, int col)
{
    using namespace QtCharts;
    QLineSeries *series = new QLineSeries();

    for(int j=0; j < col; j++)
    {
        double m = 0;
        for(int i=0; i < row; i++)
        {
            m += data[j * col + i];
        }
        m = m / row;
        printf("%d %f", j, m);
        series->append(j, m);
    }


    // Create a QChart and add the series to it
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Light Curve");

    // Create a QChartView to display the chart
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);


    m_layout->addWidget(chartView);
}

LightCurve::~LightCurve()
{
    delete ui;
}
