#include "overview.h"

#include "ui_overview.h"
#include <QMessageBox>

Overview::Overview(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Overview)
{
    ui->setupUi(this);
}

void Overview::SetRecords(QVector<QString> records)
{
    shownAlready = true;
    m_records = records;
    ui->records_table->setRowCount(records.size());

    for(int i=0; i < records.size(); i++)
    {
        QTableWidgetItem *keyItem = new QTableWidgetItem();
        QTableWidgetItem *valueItem = new QTableWidgetItem();
        QTableWidgetItem *descItem = new QTableWidgetItem();

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

        ui->records_table->setItem(i, 0, keyItem);
        ui->records_table->setItem(i, 1, valueItem);
        ui->records_table->setItem(i, 2, descItem);
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

