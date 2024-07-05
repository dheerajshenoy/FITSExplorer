/********************************************************************************
** Form generated from reading UI file 'listmarkers.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTMARKERS_H
#define UI_LISTMARKERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ListMarkers
{
public:
    QVBoxLayout *verticalLayout;
    QSplitter *splitter;
    QListWidget *markers_list_widget;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QPushButton *color_btn;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *text_field;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QPushButton *text_color_btn;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QComboBox *shape_combo;
    QPushButton *delete_marker_btn;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *ok_btn;

    void setupUi(QWidget *ListMarkers)
    {
        if (ListMarkers->objectName().isEmpty())
            ListMarkers->setObjectName("ListMarkers");
        ListMarkers->setWindowModality(Qt::NonModal);
        ListMarkers->resize(585, 398);
        verticalLayout = new QVBoxLayout(ListMarkers);
        verticalLayout->setObjectName("verticalLayout");
        splitter = new QSplitter(ListMarkers);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Horizontal);
        markers_list_widget = new QListWidget(splitter);
        markers_list_widget->setObjectName("markers_list_widget");
        splitter->addWidget(markers_list_widget);
        widget = new QWidget(splitter);
        widget->setObjectName("widget");
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(widget);
        label->setObjectName("label");

        horizontalLayout_2->addWidget(label);

        color_btn = new QPushButton(widget);
        color_btn->setObjectName("color_btn");
        color_btn->setEnabled(false);

        horizontalLayout_2->addWidget(color_btn);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        horizontalLayout_3->addWidget(label_2);

        text_field = new QLineEdit(widget);
        text_field->setObjectName("text_field");
        text_field->setEnabled(false);

        horizontalLayout_3->addWidget(text_field);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");

        horizontalLayout_5->addWidget(label_4);

        text_color_btn = new QPushButton(widget);
        text_color_btn->setObjectName("text_color_btn");
        text_color_btn->setEnabled(false);

        horizontalLayout_5->addWidget(text_color_btn);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");

        horizontalLayout_4->addWidget(label_3);

        shape_combo = new QComboBox(widget);
        shape_combo->setObjectName("shape_combo");
        shape_combo->setEnabled(false);

        horizontalLayout_4->addWidget(shape_combo);


        verticalLayout_2->addLayout(horizontalLayout_4);


        verticalLayout_3->addLayout(verticalLayout_2);

        delete_marker_btn = new QPushButton(widget);
        delete_marker_btn->setObjectName("delete_marker_btn");
        delete_marker_btn->setEnabled(false);

        verticalLayout_3->addWidget(delete_marker_btn);

        splitter->addWidget(widget);

        verticalLayout->addWidget(splitter);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        ok_btn = new QPushButton(ListMarkers);
        ok_btn->setObjectName("ok_btn");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ok_btn->sizePolicy().hasHeightForWidth());
        ok_btn->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(ok_btn);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ListMarkers);

        QMetaObject::connectSlotsByName(ListMarkers);
    } // setupUi

    void retranslateUi(QWidget *ListMarkers)
    {
        ListMarkers->setWindowTitle(QCoreApplication::translate("ListMarkers", "List Markers", nullptr));
        label->setText(QCoreApplication::translate("ListMarkers", "Marker Color", nullptr));
        color_btn->setText(QString());
        label_2->setText(QCoreApplication::translate("ListMarkers", "Text", nullptr));
        label_4->setText(QCoreApplication::translate("ListMarkers", "Text Color", nullptr));
        text_color_btn->setText(QString());
        label_3->setText(QCoreApplication::translate("ListMarkers", "Shape", nullptr));
        shape_combo->setPlaceholderText(QCoreApplication::translate("ListMarkers", "Not implemented yet", nullptr));
        delete_marker_btn->setText(QCoreApplication::translate("ListMarkers", "Delete", nullptr));
        ok_btn->setText(QCoreApplication::translate("ListMarkers", "Ok", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ListMarkers: public Ui_ListMarkers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTMARKERS_H
