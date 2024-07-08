#ifndef PIXANALYSER_H
#define PIXANALYSER_H

#include <QWidget>

namespace Ui {
class PixAnalyser;
}

class PixAnalyser : public QWidget
{
    Q_OBJECT

public:
    explicit PixAnalyser(QWidget *parent = nullptr);
    ~PixAnalyser();

    void setPixValue(float);
    float getPixValue();
    void setImg(QImage img);
    QImage getImg();

private:
    Ui::PixAnalyser *ui;
};

#endif // PIXANALYSER_H
