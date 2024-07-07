/********************************************************************************
** Form generated from reading UI file 'roitablewidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROITABLEWIDGET_H
#define UI_ROITABLEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ROITableWidget
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *table;

    void setupUi(QWidget *ROITableWidget)
    {
        if (ROITableWidget->objectName().isEmpty())
            ROITableWidget->setObjectName("ROITableWidget");
        ROITableWidget->resize(400, 300);
        verticalLayout = new QVBoxLayout(ROITableWidget);
        verticalLayout->setObjectName("verticalLayout");
        table = new QTableWidget(ROITableWidget);
        if (table->columnCount() < 2)
            table->setColumnCount(2);
        table->setObjectName("table");
        table->setContextMenuPolicy(Qt::ContextMenuPolicy::CustomContextMenu);
        table->setColumnCount(2);
        table->horizontalHeader()->setStretchLastSection(true);

        verticalLayout->addWidget(table);


        retranslateUi(ROITableWidget);

        QMetaObject::connectSlotsByName(ROITableWidget);
    } // setupUi

    void retranslateUi(QWidget *ROITableWidget)
    {
        ROITableWidget->setWindowTitle(QCoreApplication::translate("ROITableWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ROITableWidget: public Ui_ROITableWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROITABLEWIDGET_H
