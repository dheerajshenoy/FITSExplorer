/********************************************************************************
** Form generated from reading UI file 'lightcurve.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIGHTCURVE_H
#define UI_LIGHTCURVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_LightCurve
{
public:
    QVBoxLayout *verticalLayout;
    QCustomPlot *plot_widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *save_btn;
    QComboBox *comboBox_2;
    QComboBox *comboBox;

    void setupUi(QWidget *LightCurve)
    {
        if (LightCurve->objectName().isEmpty())
            LightCurve->setObjectName("LightCurve");
        LightCurve->resize(655, 469);
        verticalLayout = new QVBoxLayout(LightCurve);
        verticalLayout->setObjectName("verticalLayout");
        plot_widget = new QCustomPlot(LightCurve);
        plot_widget->setObjectName("plot_widget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(plot_widget->sizePolicy().hasHeightForWidth());
        plot_widget->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(plot_widget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        save_btn = new QPushButton(LightCurve);
        save_btn->setObjectName("save_btn");

        horizontalLayout->addWidget(save_btn);

        comboBox_2 = new QComboBox(LightCurve);
        comboBox_2->setObjectName("comboBox_2");

        horizontalLayout->addWidget(comboBox_2);

        comboBox = new QComboBox(LightCurve);
        comboBox->setObjectName("comboBox");

        horizontalLayout->addWidget(comboBox);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(LightCurve);

        QMetaObject::connectSlotsByName(LightCurve);
    } // setupUi

    void retranslateUi(QWidget *LightCurve)
    {
        LightCurve->setWindowTitle(QCoreApplication::translate("LightCurve", "Light Curve", nullptr));
        save_btn->setText(QCoreApplication::translate("LightCurve", "Save Figure", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LightCurve: public Ui_LightCurve {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIGHTCURVE_H
