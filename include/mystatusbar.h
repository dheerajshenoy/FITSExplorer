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
    void setMsg(QString msg, int time_in_ms = 1000);
    void setFile(QString filename);
    void setCoordinate(QPointF coordinate);
    void clearCoordinate();

private:
    Ui::MyStatusBar *ui;
};

#endif // STATUSBAR_H
