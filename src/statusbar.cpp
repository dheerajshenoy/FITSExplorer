#include "statusbar.h"

StatusBar::StatusBar(QWidget *parent)
    : QStatusBar(parent)
{
    this->setLayout(m_layout);
    this->addWidget(m_msg_label);
    this->addWidget(m_coord_label);
    this->addWidget(m_file_name, 1);
    this->addWidget(m_file_dir);
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

QString HumanReadableSize(qint64 size)
{
    static const char* suffixes[] = {"B", "KB", "MB", "GB", "TB", "PB", "EB", "ZB", "YB"};
    static const int numSuffixes = sizeof(suffixes) / sizeof(suffixes[0]);
    int index = 0;
    double fileSize = size;

    while (fileSize >= 1024 && index < numSuffixes - 1) {
        fileSize /= 1024;
        index++;
    }

    return QString("%1 %2").arg(fileSize, 0, 'f', 2).arg(suffixes[index]);
}

void StatusBar::setFile(QString filename)
{
    QFileInfo fileInfo(filename);
    m_file_name->setText(fileInfo.fileName());
    m_file_size->setText(HumanReadableSize(fileInfo.size()));
    m_file_dir->setText(fileInfo.absoluteFilePath());
}

void StatusBar::setCoordinate(QPointF point)
{
    m_coord_label->setText(QString("(%1, %2)").arg(point.x()).arg(point.y()));

}
