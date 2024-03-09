#include "statusbar.h"

StatusBar::StatusBar(QWidget *parent)
    : QStatusBar{parent}
{
    this->setLayout(m_layout);
    this->addWidget(m_msg_label);
    this->addWidget(m_file_name, 1);
    this->addWidget(m_file_size);
    setMsg("HELLO WORLD");
}

void StatusBar::setMsg(QString msg, int time)
{
    m_msg_label->setText(msg);
    QTimer::singleShot(time, [&](){
        m_msg_label->setText("");
    });
}

void StatusBar::setFileName(QString filename)
{
    m_file_name->setText(filename);
}

void StatusBar::setFileSize(QString size)
{
    m_file_size->setText(size);
}
