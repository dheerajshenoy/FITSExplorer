#include "mystatusbar.h"
#include "ui_mystatusbar.h"

MyStatusBar::MyStatusBar(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyStatusBar)
{
    ui->setupUi(this);

    ui->progressBar->setHidden(true);
    ui->progressBar->setRange(0, 100);

    m_locale = this->locale();
}

MyStatusBar::~MyStatusBar()
{
    delete ui;
}

void MyStatusBar::setMsg(const QString msg, const int time)
{
    ui->label_msg->setText(msg);
    QTimer::singleShot(time, [&](){
        ui->label_msg->setText("");
    });
}

QString HumanReadableSize(const qint64 size)
{
    // static const char* suffixes[] = {"B", "KB", "MB", "GB", "TB", "PB", "EB", "ZB", "YB"};
    // static const int numSuffixes = sizeof(suffixes) / sizeof(suffixes[0]);
    // int index = 0;
    // double fileSize = size;

    // while (fileSize >= 1024 && index < numSuffixes - 1) {
        // fileSize /= 1024;
        // index++;
    // }

    // return QString("%1 %2").arg(fileSize, 0, 'f', 2).arg(suffixes[index]);

}

void MyStatusBar::setFile(const QString filename)
{
    QFileInfo fileInfo(filename);
    ui->label_filename->setText(fileInfo.fileName());
    fprintf(stderr, "%d", fileInfo.size());
    ui->label_filesize->setText(m_locale.formattedDataSize(fileInfo.size()));

    // If file path is more than 20 characters, make it a tooltip text
    if (fileInfo.absoluteFilePath().size() > 10)
    {
        ui->label_filedir->setToolTip(fileInfo.absoluteFilePath());
        ui->label_filedir->setText("Hover for file Path");
    }
    else {
        ui->label_filedir->setText(fileInfo.absoluteFilePath());
    }
}

void MyStatusBar::setCoordinate(const QPointF point)
{
    ui->label_coord->setText(QString("(%1, %2)").arg(point.x()).arg(point.y()));
}

void MyStatusBar::clearCoordinate()
{
    ui->label_coord->clear();
}

void MyStatusBar::setProgress(const int val)
{
    ui->progressBar->setValue(val);
    ui->progressBar->update();
}

void MyStatusBar::hideProgressBar(bool status)
{
    ui->progressBar->setHidden(status);
}


void MyStatusBar::setMode(QString mode)
{
    ui->label_mode->setText(mode);
}
