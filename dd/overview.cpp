#include "overview.h"

#include "ui_overview.h"
#include <QMessageBox>

Overview::Overview(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Overview)
{
    ui->setupUi(this);
}

void Overview::SetRecords(QMap<QString, QString> records)
{
    //m_records = records;
    int i;
    ui->records_table->setHorizontalHeaderLabels({"Key", "Value"});
    ui->records_table->setRowCount(records.size());
    QMap<QString, QString>::const_iterator it;
    for(i = 0, it = records.constBegin(); it != records.constEnd(); ++i, ++it)
    {
        QTableWidgetItem *keyItem = new QTableWidgetItem();
        QTableWidgetItem *valueItem = new QTableWidgetItem();

        /*
        // Ignore if it's not a keyword
        if(!records[i].contains("="))
            return;

        QStringList KV = records[i].split("=");
        keyItem->setText(KV[0]);

        if (records[i].contains("/"))
        {
            QStringList val_with_desc = records[i].split("/");
            valueItem->setText(val_with_desc[0].split('=')[1]);
            descItem->setText(val_with_desc[1]);
        }
*/

        keyItem->setText(it.key());
        valueItem->setText(it.value());

        ui->records_table->setItem(i, 0, keyItem);
        ui->records_table->setItem(i, 1, valueItem);
    }
}

QVector<QString> Overview::getRecords()
{
    return m_records;
}

Overview::~Overview()
{
    delete ui;
}

void Overview::on_rawBtn_clicked()
{
}

