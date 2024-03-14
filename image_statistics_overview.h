#ifndef IMAGE_STATISTICS_OVERVIEW_H
#define IMAGE_STATISTICS_OVERVIEW_H

#include <QWidget>
#include <algorithm>
#include <boost/math/distributions/normal.hpp>
#include <QVector>

namespace Ui {
class ImageStatisticsOverview;
}

class ImageStatisticsOverview : public QWidget
{
    Q_OBJECT

public:
    explicit ImageStatisticsOverview(QWidget *parent = nullptr, float* img_data = nullptr);
    ~ImageStatisticsOverview();

    double Mean();
    double Median();
    double StandardDeviation();
    void Gaussian();
    double* GetMinMax();
    float* sort(float*);
    size_t getSize(float*);

    QVector<double> arange(const float, const float, const float);

private:
    Ui::ImageStatisticsOverview *ui;

    float* image_data;

    size_t m_n;
};

#endif // IMAGE_STATISTICS_OVERVIEW_H
