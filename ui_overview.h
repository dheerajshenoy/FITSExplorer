/********************************************************************************
** Form generated from reading UI file 'overview.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OVERVIEW_H
#define UI_OVERVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Overview
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *records_table;

    void setupUi(QWidget *Overview)
    {
        if (Overview->objectName().isEmpty())
            Overview->setObjectName("Overview");
        Overview->resize(678, 507);
        verticalLayout = new QVBoxLayout(Overview);
        verticalLayout->setObjectName("verticalLayout");
        records_table = new QTableWidget(Overview);
        if (records_table->columnCount() < 2)
            records_table->setColumnCount(2);
        records_table->setObjectName("records_table");
        records_table->setAlternatingRowColors(true);
        records_table->setGridStyle(Qt::DashLine);
        records_table->setSortingEnabled(true);
        records_table->setColumnCount(2);
        records_table->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        records_table->horizontalHeader()->setStretchLastSection(true);

        verticalLayout->addWidget(records_table);


        retranslateUi(Overview);

        QMetaObject::connectSlotsByName(Overview);
    } // setupUi

    void retranslateUi(QWidget *Overview)
    {
        Overview->setWindowTitle(QCoreApplication::translate("Overview", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Overview: public Ui_Overview {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OVERVIEW_H
