#include "preferences.h"
#include "ui_preferences.h"

Preferences::Preferences(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Preferences)
{
    ui->setupUi(this);
}

Preferences::~Preferences()
{
    delete ui;
}

void Preferences::on_cancel_btn_clicked()
{

}


void Preferences::on_listWidget_currentTextChanged(const QString &currentText)
{
    if(currentText == "General")
    {

    }
    else if(currentText == "Appearance")
    {

    }
}

