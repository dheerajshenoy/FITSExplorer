#include "image_statistics_overview.h"
#include "ui_image_statistics_overview.h"

ImageStatisticsOverview::ImageStatisticsOverview(QWidget *parent, float* img_data)
    : QWidget(parent)
    , image_data(img_data)
    , ui(new Ui::ImageStatisticsOverview)
{
    if (img_data == nullptr)
    {
        QMessageBox::information(this, "Information", "Please select an Image first from the HDU List");
        return;
    }
    ui->setupUi(this);
    m_n = getSize(image_data);
    ui->gaussian_dist_plot->addGraph();
    ui->gaussian_dist_plot->graph(0)->setPen(QPen(Qt::red, 2));

    ui->gaussian_dist_plot->plotLayout()->insertRow(0);
    ui->gaussian_dist_plot->plotLayout()->addElement(0, 0, new QCPTextElement(ui->gaussian_dist_plot,
                                                                            "Gaussian Curve"));

    ui->gaussian_dist_plot->plotLayout()->setRowStretchFactor(0, 0.1); // Adjust as needed

    ui->gaussian_dist_plot->setInteractions(QCP::iSelectPlottables | QCP::iRangeDrag | QCP::iMultiSelect);
    Gaussian();
    this->show();
    //QVector<float> minmax = GetMinMax();

    QTableWidgetItem *mean_item = new QTableWidgetItem(QString::number(Mean()));
    ui->table_widget->setItem(0, 1, mean_item);

    QTableWidgetItem *median_item = new QTableWidgetItem(QString::number(Median()));
    ui->table_widget->setItem(1, 1, median_item);

    QTableWidgetItem *sd_item = new QTableWidgetItem(QString::number(StandardDeviation()));
    ui->table_widget->setItem(2, 1, sd_item);

    auto minmax = GetMinMax();

    QTableWidgetItem *min_pix_item = new QTableWidgetItem(QString::number(minmax[0]));
    ui->table_widget->setItem(3, 1, min_pix_item);

    QTableWidgetItem *max_pix_item = new QTableWidgetItem(QString::number(minmax[1]));
    ui->table_widget->setItem(4, 1, max_pix_item);
}

ImageStatisticsOverview::~ImageStatisticsOverview()
{
    delete ui;
}

double ImageStatisticsOverview::Mean()
{
    double m = 0;
    for(size_t i=0; i < m_n; i++)
    {
        m += image_data[i];
    }
    return m / m_n;
}

float* ImageStatisticsOverview::sort(float * d)
{
    float *temp = d;
    size_t n = getSize(d);
    std::sort(temp, temp + n);
    return temp;
}

size_t ImageStatisticsOverview::getSize(float * data)
{
    return sizeof(data)/sizeof(float);
}

QVector<double> ImageStatisticsOverview::arange(const float from, const float to, const float s)
{
    if (to < from)
    {
        return {};
    }
    int n = (to - from)/s;
    QVector<double> d(n);
    double x = from;

    for(size_t i=0; i < m_n; i++)
    {
        d[i] = x;
        x += s;
    }

    return d;
}

double ImageStatisticsOverview::Median()
{
    auto m = sort(image_data);

    if(m_n%2 == 0)
    {
        return m[m_n/2];
    }
    else {
        return m[(m_n + 1)/2];
    }
}

double ImageStatisticsOverview::StandardDeviation()
{
    double SD = 0;
    double mean = Mean();
    for(size_t i=0; i < m_n; i++)
    {
        SD += pow(image_data[i] - mean, 2);
    }

    SD /= m_n;

    return sqrtf(SD);
}

QVector<float> ImageStatisticsOverview::GetMinMax()
{
    auto sorted_arr = sort(image_data);
    QVector<float> minmax = { sorted_arr[0], sorted_arr[m_n - 1] };
    return minmax;
}

void ImageStatisticsOverview::Gaussian()
{

    // Generate Gaussian curve data points
    QVector<double> xData, yData;
    double mean = Mean();
    double stddev = StandardDeviation();
    int numPoints = 1000; // Number of points to generate

    double maxYValue = 0.0;

    for (int i = 0; i < numPoints; ++i) {
        double x = -5.0 + i * 10.0 / (numPoints - 1); // Adjust the range as needed
        double y = exp(-0.5 * pow((x - mean) / stddev, 2)) / (stddev * sqrt(2 * M_PI));
        xData.append(x);
        yData.append(y);

        if (y > maxYValue)
            maxYValue = y;
    }

    ui->gaussian_dist_plot->graph(0)->setData(xData, yData);
    ui->gaussian_dist_plot->replot();

    ui->gaussian_dist_plot->xAxis->setRange(-10, 10);
    ui->gaussian_dist_plot->yAxis->setRange(-0.25, maxYValue);

    ui->gaussian_dist_plot->show();
}

