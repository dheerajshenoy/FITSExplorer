#include "aboutdialog.h"
#include "ui_aboutdialog.h"

#include <QDesktopServices>
#include <QUrl>

AboutDialog::AboutDialog(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AboutDialog)
{
    ui->setupUi(this);
    ui->app_label->setScaledContents(true);
}

AboutDialog::~AboutDialog()
{
    delete ui;
}

void AboutDialog::on_gitBtn_clicked()
{
    QDesktopServices::openUrl(QUrl("https://github.com/dheerajshenoy"));
}


void AboutDialog::on_linkedinBtn_clicked()
{
    QDesktopServices::openUrl(QUrl("https://www.linkedin.com/in/dheeraj-vittal-shenoy"));
}

