#ifndef STATUSBAR_H
#define STATUSBAR_H

#include <QWidget>
#include <QStatusBar>
#include <QLabel>
#include <QHBoxLayout>
#include <QTimer>

class StatusBar : public QStatusBar
{
public:
    explicit StatusBar(QWidget *parent = nullptr);
    void setFileName(QString);
    void setFileSize(QString);
    void setMsg(QString msg, int time_in_ms = 1000);

signals:

private:
    QHBoxLayout *m_layout = new QHBoxLayout();
    QLabel *m_file_name = new QLabel("");
    QLabel *m_file_size = new QLabel("");
    QLabel *m_msg_label = new QLabel("");

};

#endif // STATUSBAR_H
