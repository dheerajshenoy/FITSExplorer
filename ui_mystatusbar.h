/********************************************************************************
** Form generated from reading UI file 'mystatusbar.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYSTATUSBAR_H
#define UI_MYSTATUSBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyStatusBar
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label_mode;
    QLabel *label_msg;
    QLabel *label_coord;
    QProgressBar *progressBar;
    QSpacerItem *horizontalSpacer;
    QLabel *label_filedir;
    QLabel *label_filename;
    QLabel *label_filesize;

    void setupUi(QWidget *MyStatusBar)
    {
        if (MyStatusBar->objectName().isEmpty())
            MyStatusBar->setObjectName("MyStatusBar");
        MyStatusBar->resize(810, 48);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MyStatusBar->sizePolicy().hasHeightForWidth());
        MyStatusBar->setSizePolicy(sizePolicy);
        MyStatusBar->setBaseSize(QSize(0, 35));
        horizontalLayout = new QHBoxLayout(MyStatusBar);
        horizontalLayout->setObjectName("horizontalLayout");
        label_mode = new QLabel(MyStatusBar);
        label_mode->setObjectName("label_mode");

        horizontalLayout->addWidget(label_mode);

        label_msg = new QLabel(MyStatusBar);
        label_msg->setObjectName("label_msg");

        horizontalLayout->addWidget(label_msg);

        label_coord = new QLabel(MyStatusBar);
        label_coord->setObjectName("label_coord");

        horizontalLayout->addWidget(label_coord);

        progressBar = new QProgressBar(MyStatusBar);
        progressBar->setObjectName("progressBar");
        progressBar->setMaximumSize(QSize(100, 16777215));
        progressBar->setValue(24);
        progressBar->setTextVisible(false);

        horizontalLayout->addWidget(progressBar);

        horizontalSpacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_filedir = new QLabel(MyStatusBar);
        label_filedir->setObjectName("label_filedir");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_filedir->sizePolicy().hasHeightForWidth());
        label_filedir->setSizePolicy(sizePolicy1);
        label_filedir->setMaximumSize(QSize(16777215, 200));
        label_filedir->setBaseSize(QSize(0, 200));

        horizontalLayout->addWidget(label_filedir);

        label_filename = new QLabel(MyStatusBar);
        label_filename->setObjectName("label_filename");
        label_filename->setTextFormat(Qt::TextFormat::RichText);

        horizontalLayout->addWidget(label_filename);

        label_filesize = new QLabel(MyStatusBar);
        label_filesize->setObjectName("label_filesize");

        horizontalLayout->addWidget(label_filesize);


        retranslateUi(MyStatusBar);

        QMetaObject::connectSlotsByName(MyStatusBar);
    } // setupUi

    void retranslateUi(QWidget *MyStatusBar)
    {
        MyStatusBar->setWindowTitle(QCoreApplication::translate("MyStatusBar", "Form", nullptr));
        label_mode->setText(QCoreApplication::translate("MyStatusBar", "MODE", nullptr));
        label_msg->setText(QCoreApplication::translate("MyStatusBar", "MSG", nullptr));
        label_coord->setText(QCoreApplication::translate("MyStatusBar", "COORD", nullptr));
        label_filedir->setText(QCoreApplication::translate("MyStatusBar", "FILE DIR", nullptr));
        label_filename->setText(QCoreApplication::translate("MyStatusBar", "FILE NAME", nullptr));
        label_filesize->setText(QCoreApplication::translate("MyStatusBar", "FILE SIZE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyStatusBar: public Ui_MyStatusBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYSTATUSBAR_H
