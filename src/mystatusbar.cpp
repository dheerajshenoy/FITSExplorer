#include "mystatusbar.h"
#include "ui_mystatusbar.h"

MyStatusBar::MyStatusBar(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyStatusBar)
{
    ui->setupUi(this);

    ui->progressbar->setVisible(false);
}

MyStatusBar::~MyStatusBar()
{
    delete ui;
}

void MyStatusBar::setMsg(QString msg, int time)
{
    ui->label_msg->setText(msg);
    QTimer::singleShot(time, [&](){
        ui->label_msg->setText("");
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

void MyStatusBar::setFile(QString filename)
{
    QFileInfo fileInfo(filename);
    ui->label_filename->setText(fileInfo.fileName());
    ui->label_filesize->setText(HumanReadableSize(fileInfo.size()));
    ui->label_filedir->setText(fileInfo.absoluteFilePath());
}

void MyStatusBar::setCoordinate(QPointF point)
{
    ui->label_coord->setText(QString("(%1, %2)").arg(point.x()).arg(point.y()));

}

void MyStatusBar::clearCoordinate()
{
    ui->label_coord->clear();
}
