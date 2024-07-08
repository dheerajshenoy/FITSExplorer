/********************************************************************************
** Form generated from reading UI file 'pixanalyser.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PIXANALYSER_H
#define UI_PIXANALYSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PixAnalyser
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *preview_label;
    QLabel *pixvalue_label;

    void setupUi(QWidget *PixAnalyser)
    {
        if (PixAnalyser->objectName().isEmpty())
            PixAnalyser->setObjectName("PixAnalyser");
        PixAnalyser->resize(400, 300);
        PixAnalyser->setStyleSheet(QString::fromUtf8("background-color: black;"));
        verticalLayout = new QVBoxLayout(PixAnalyser);
        verticalLayout->setObjectName("verticalLayout");
        preview_label = new QLabel(PixAnalyser);
        preview_label->setObjectName("preview_label");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(preview_label->sizePolicy().hasHeightForWidth());
        preview_label->setSizePolicy(sizePolicy);
        preview_label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(preview_label);

        pixvalue_label = new QLabel(PixAnalyser);
        pixvalue_label->setObjectName("pixvalue_label");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pixvalue_label->sizePolicy().hasHeightForWidth());
        pixvalue_label->setSizePolicy(sizePolicy1);
        pixvalue_label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(pixvalue_label);


        retranslateUi(PixAnalyser);

        QMetaObject::connectSlotsByName(PixAnalyser);
    } // setupUi

    void retranslateUi(QWidget *PixAnalyser)
    {
        PixAnalyser->setWindowTitle(QCoreApplication::translate("PixAnalyser", "Form", nullptr));
        preview_label->setText(QCoreApplication::translate("PixAnalyser", "IMG PREVIEW", nullptr));
        pixvalue_label->setText(QCoreApplication::translate("PixAnalyser", "PIX VALUE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PixAnalyser: public Ui_PixAnalyser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PIXANALYSER_H
