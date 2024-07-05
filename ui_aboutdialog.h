/********************************************************************************
** Form generated from reading UI file 'aboutdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTDIALOG_H
#define UI_ABOUTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AboutDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QLabel *app_label;
    QVBoxLayout *verticalLayout;
    QLabel *app_desc_label;
    QLabel *app_creator_label_2;
    QLabel *app_creator_label;
    QHBoxLayout *horizontalLayout;
    QPushButton *gitBtn;
    QPushButton *linkedinBtn;

    void setupUi(QWidget *AboutDialog)
    {
        if (AboutDialog->objectName().isEmpty())
            AboutDialog->setObjectName("AboutDialog");
        AboutDialog->resize(550, 300);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AboutDialog->sizePolicy().hasHeightForWidth());
        AboutDialog->setSizePolicy(sizePolicy);
        AboutDialog->setMinimumSize(QSize(550, 300));
        AboutDialog->setMaximumSize(QSize(550, 300));
        verticalLayout_2 = new QVBoxLayout(AboutDialog);
        verticalLayout_2->setObjectName("verticalLayout_2");
        app_label = new QLabel(AboutDialog);
        app_label->setObjectName("app_label");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(app_label->sizePolicy().hasHeightForWidth());
        app_label->setSizePolicy(sizePolicy1);
        app_label->setStyleSheet(QString::fromUtf8("font: 20pt \"Rajdhani Semibold\";"));

        verticalLayout_2->addWidget(app_label);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        app_desc_label = new QLabel(AboutDialog);
        app_desc_label->setObjectName("app_desc_label");
        sizePolicy1.setHeightForWidth(app_desc_label->sizePolicy().hasHeightForWidth());
        app_desc_label->setSizePolicy(sizePolicy1);
        app_desc_label->setStyleSheet(QString::fromUtf8("font: 9pt \"Rajdhani\";"));

        verticalLayout->addWidget(app_desc_label);

        app_creator_label_2 = new QLabel(AboutDialog);
        app_creator_label_2->setObjectName("app_creator_label_2");
        sizePolicy1.setHeightForWidth(app_creator_label_2->sizePolicy().hasHeightForWidth());
        app_creator_label_2->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(app_creator_label_2);


        verticalLayout_2->addLayout(verticalLayout);

        app_creator_label = new QLabel(AboutDialog);
        app_creator_label->setObjectName("app_creator_label");
        sizePolicy1.setHeightForWidth(app_creator_label->sizePolicy().hasHeightForWidth());
        app_creator_label->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(app_creator_label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        gitBtn = new QPushButton(AboutDialog);
        gitBtn->setObjectName("gitBtn");
        gitBtn->setStyleSheet(QString::fromUtf8("padding: 10px;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../Downloads/icons8-github.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        gitBtn->setIcon(icon);
        gitBtn->setIconSize(QSize(32, 32));
#if QT_CONFIG(shortcut)
        gitBtn->setShortcut(QString::fromUtf8(""));
#endif // QT_CONFIG(shortcut)

        horizontalLayout->addWidget(gitBtn);

        linkedinBtn = new QPushButton(AboutDialog);
        linkedinBtn->setObjectName("linkedinBtn");
        linkedinBtn->setStyleSheet(QString::fromUtf8("padding: 10px;"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../../Downloads/icons8-linkedin.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        linkedinBtn->setIcon(icon1);
        linkedinBtn->setIconSize(QSize(32, 32));
        linkedinBtn->setCheckable(false);

        horizontalLayout->addWidget(linkedinBtn);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(AboutDialog);

        QMetaObject::connectSlotsByName(AboutDialog);
    } // setupUi

    void retranslateUi(QWidget *AboutDialog)
    {
        AboutDialog->setWindowTitle(QCoreApplication::translate("AboutDialog", "About", nullptr));
        app_label->setText(QCoreApplication::translate("AboutDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:26pt; font-weight:700; font-style:italic;\">FITSExplorer</span></p></body></html>", nullptr));
        app_desc_label->setText(QCoreApplication::translate("AboutDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt;\">Modern Day FITS Viewer</span></p></body></html>", nullptr));
        app_creator_label_2->setText(QCoreApplication::translate("AboutDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; font-weight:700; font-style:italic;\">Written in C++</span></p></body></html>", nullptr));
        app_creator_label->setText(QCoreApplication::translate("AboutDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">Created By : </span><span style=\" font-size:10pt; font-weight:700;\">Dheeraj Vittal Shenoy</span></p></body></html>", nullptr));
        gitBtn->setText(QCoreApplication::translate("AboutDialog", "GitHub", nullptr));
        linkedinBtn->setText(QCoreApplication::translate("AboutDialog", "LinkedIn", nullptr));
#if QT_CONFIG(shortcut)
        linkedinBtn->setShortcut(QCoreApplication::translate("AboutDialog", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
    } // retranslateUi

};

namespace Ui {
    class AboutDialog: public Ui_AboutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTDIALOG_H
