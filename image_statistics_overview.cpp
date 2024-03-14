#include "image_statistics_overview.h"
#include "ui_image_statistics_overview.h"

ImageStatisticsOverview::ImageStatisticsOverview(QWidget *parent, float* img_data)
    : QWidget(parent)
    , image_data(img_data)
    , ui(new Ui::ImageStatisticsOverview)
{
    ui->setupUi(this);
    m_n = getSize(image_data);
    ui->label_mean->setText(QString::number(Mean()));
    ui->label_median->setText(QString::number(Median()));
    ui->label_std->setText(QString::number(StandardDeviation()));
    Gaussian();
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

double* ImageStatisticsOverview::GetMinMax()
{
    double minmax[2] = {0, 0};
    auto sorted_arr = sort(image_data);
    minmax[0] = sorted_arr[0];
    minmax[m_n - 1] = sorted_arr[m_n - 1];
    return minmax;
}

void ImageStatisticsOverview::Gaussian()
{
    /*
    auto dist = boost::math::normal_distribution<double>(Mean(), StandardDeviation());

    double* minmax = GetMinMax();

    QVector<double> x = arange(minmax[0], minmax[1], 1);

    QVector<double> y(x.size());

    for(size_t i=0; i < x.size(); i++)
    {
        y[i] = boost::math::pdf(dist, x[i]);
    }

    ui->gaussian_dist_plot->addGraph();
    ui->gaussian_dist_plot->graph(0)->setData(x, y);
*/
}

