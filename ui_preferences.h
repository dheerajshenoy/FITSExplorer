/********************************************************************************
** Form generated from reading UI file 'preferences.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREFERENCES_H
#define UI_PREFERENCES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Preferences
{
public:
    QVBoxLayout *verticalLayout;
    QSplitter *splitter;
    QListWidget *listWidget;
    QWidget *rightWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *ok_btn;
    QPushButton *cancel_btn;
    QPushButton *apply_btn;

    void setupUi(QWidget *Preferences)
    {
        if (Preferences->objectName().isEmpty())
            Preferences->setObjectName("Preferences");
        Preferences->resize(677, 476);
        verticalLayout = new QVBoxLayout(Preferences);
        verticalLayout->setObjectName("verticalLayout");
        splitter = new QSplitter(Preferences);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Horizontal);
        listWidget = new QListWidget(splitter);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName("listWidget");
        splitter->addWidget(listWidget);
        rightWidget = new QWidget(splitter);
        rightWidget->setObjectName("rightWidget");
        splitter->addWidget(rightWidget);

        verticalLayout->addWidget(splitter);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        ok_btn = new QPushButton(Preferences);
        ok_btn->setObjectName("ok_btn");

        horizontalLayout->addWidget(ok_btn);

        cancel_btn = new QPushButton(Preferences);
        cancel_btn->setObjectName("cancel_btn");

        horizontalLayout->addWidget(cancel_btn);

        apply_btn = new QPushButton(Preferences);
        apply_btn->setObjectName("apply_btn");

        horizontalLayout->addWidget(apply_btn);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Preferences);

        QMetaObject::connectSlotsByName(Preferences);
    } // setupUi

    void retranslateUi(QWidget *Preferences)
    {
        Preferences->setWindowTitle(QCoreApplication::translate("Preferences", "Form", nullptr));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("Preferences", "General", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("Preferences", "Appearance", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("Preferences", "New Item", nullptr));
        listWidget->setSortingEnabled(__sortingEnabled);

        ok_btn->setText(QCoreApplication::translate("Preferences", "Ok", nullptr));
        cancel_btn->setText(QCoreApplication::translate("Preferences", "Cancel", nullptr));
        apply_btn->setText(QCoreApplication::translate("Preferences", "Apply", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Preferences: public Ui_Preferences {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREFERENCES_H
