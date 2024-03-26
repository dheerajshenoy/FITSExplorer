#ifndef MYSTATUSBAR_H
#define MYSTATUSBAR_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QTimer>
#include <QFileInfo>

namespace Ui {
class MyStatusBar;
}

class MyStatusBar : public QWidget
{
    Q_OBJECT
public:
    explicit MyStatusBar(QWidget *parent = nullptr);
    ~MyStatusBar();
    void setMsg(const QString msg, const int time_in_ms = 1000);
    void setFile(const QString filename);
    void setCoordinate(const QPointF coordinate);
    void clearCoordinate();
    void setProgress(const int val);

    void hideProgressBar(bool status);
private:
    Ui::MyStatusBar *ui;
};

#endif // STATUSBAR_H
