/********************************************************************************
** Form generated from reading UI file 'image_statistics_overview.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGE_STATISTICS_OVERVIEW_H
#define UI_IMAGE_STATISTICS_OVERVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_ImageStatisticsOverview
{
public:
    QHBoxLayout *horizontalLayout;
    QTableWidget *table_widget;
    QCustomPlot *gaussian_dist_plot;

    void setupUi(QWidget *ImageStatisticsOverview)
    {
        if (ImageStatisticsOverview->objectName().isEmpty())
            ImageStatisticsOverview->setObjectName("ImageStatisticsOverview");
        ImageStatisticsOverview->resize(749, 403);
        horizontalLayout = new QHBoxLayout(ImageStatisticsOverview);
        horizontalLayout->setObjectName("horizontalLayout");
        table_widget = new QTableWidget(ImageStatisticsOverview);
        if (table_widget->columnCount() < 2)
            table_widget->setColumnCount(2);
        if (table_widget->rowCount() < 5)
            table_widget->setRowCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table_widget->setItem(0, 0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table_widget->setItem(1, 0, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table_widget->setItem(2, 0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        table_widget->setItem(3, 0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        table_widget->setItem(4, 0, __qtablewidgetitem4);
        table_widget->setObjectName("table_widget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(table_widget->sizePolicy().hasHeightForWidth());
        table_widget->setSizePolicy(sizePolicy);
        table_widget->setAutoFillBackground(false);
        table_widget->setRowCount(5);
        table_widget->setColumnCount(2);
        table_widget->horizontalHeader()->setStretchLastSection(true);

        horizontalLayout->addWidget(table_widget);

        gaussian_dist_plot = new QCustomPlot(ImageStatisticsOverview);
        gaussian_dist_plot->setObjectName("gaussian_dist_plot");

        horizontalLayout->addWidget(gaussian_dist_plot);


        retranslateUi(ImageStatisticsOverview);

        QMetaObject::connectSlotsByName(ImageStatisticsOverview);
    } // setupUi

    void retranslateUi(QWidget *ImageStatisticsOverview)
    {
        ImageStatisticsOverview->setWindowTitle(QCoreApplication::translate("ImageStatisticsOverview", "Form", nullptr));

        const bool __sortingEnabled = table_widget->isSortingEnabled();
        table_widget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem = table_widget->item(0, 0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("ImageStatisticsOverview", "Mean", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = table_widget->item(1, 0);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("ImageStatisticsOverview", "Median", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = table_widget->item(2, 0);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("ImageStatisticsOverview", "Standard Deviation", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = table_widget->item(3, 0);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("ImageStatisticsOverview", "Min Pixel", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = table_widget->item(4, 0);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("ImageStatisticsOverview", "Max Pixel", nullptr));
        table_widget->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class ImageStatisticsOverview: public Ui_ImageStatisticsOverview {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGE_STATISTICS_OVERVIEW_H
