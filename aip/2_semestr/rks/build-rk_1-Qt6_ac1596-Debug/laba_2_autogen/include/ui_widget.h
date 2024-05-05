/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *sizeLine;
    QPushButton *sizeButton;
    QLineEdit *nameLine;
    QHBoxLayout *horizontalLayout;
    QLineEdit *elemLine;
    QPushButton *addElemButton;
    QHBoxLayout *horizontalLayout_4;
    QTextEdit *bigTextEdit;
    QVBoxLayout *verticalLayout_2;
    QPushButton *showAllButton;
    QPushButton *sortButton;
    QPushButton *pushButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(750, 613);
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        sizeLine = new QLineEdit(widget);
        sizeLine->setObjectName(QString::fromUtf8("sizeLine"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(sizeLine->sizePolicy().hasHeightForWidth());
        sizeLine->setSizePolicy(sizePolicy);
        sizeLine->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_2->addWidget(sizeLine);

        sizeButton = new QPushButton(widget);
        sizeButton->setObjectName(QString::fromUtf8("sizeButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(sizeButton->sizePolicy().hasHeightForWidth());
        sizeButton->setSizePolicy(sizePolicy1);
        sizeButton->setMaximumSize(QSize(200, 16777215));
        sizeButton->setAutoDefault(true);

        horizontalLayout_2->addWidget(sizeButton);

        nameLine = new QLineEdit(widget);
        nameLine->setObjectName(QString::fromUtf8("nameLine"));

        horizontalLayout_2->addWidget(nameLine);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        elemLine = new QLineEdit(widget);
        elemLine->setObjectName(QString::fromUtf8("elemLine"));

        horizontalLayout->addWidget(elemLine);

        addElemButton = new QPushButton(widget);
        addElemButton->setObjectName(QString::fromUtf8("addElemButton"));
        addElemButton->setAutoDefault(true);

        horizontalLayout->addWidget(addElemButton);


        horizontalLayout_3->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        bigTextEdit = new QTextEdit(widget);
        bigTextEdit->setObjectName(QString::fromUtf8("bigTextEdit"));

        horizontalLayout_4->addWidget(bigTextEdit);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        showAllButton = new QPushButton(widget);
        showAllButton->setObjectName(QString::fromUtf8("showAllButton"));
        showAllButton->setMinimumSize(QSize(100, 100));
        showAllButton->setAutoDefault(true);

        verticalLayout_2->addWidget(showAllButton);

        sortButton = new QPushButton(widget);
        sortButton->setObjectName(QString::fromUtf8("sortButton"));
        sortButton->setMinimumSize(QSize(100, 100));
        sortButton->setAutoDefault(true);

        verticalLayout_2->addWidget(sortButton);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(100, 100));
        pushButton->setAutoDefault(true);

        verticalLayout_2->addWidget(pushButton);


        horizontalLayout_4->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_4);


        verticalLayout->addWidget(widget);


        retranslateUi(Widget);
        QObject::connect(pushButton, &QPushButton::clicked, Widget, qOverload<>(&QWidget::close));

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        sizeButton->setText(QCoreApplication::translate("Widget", "\320\222\320\262\320\265\321\201\321\202\320\270 \320\272\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\272\320\275\320\270\320\263", nullptr));
        addElemButton->setText(QCoreApplication::translate("Widget", "\320\222\320\262\320\265\321\201\321\202\320\270 \320\272\320\275\320\270\320\263\321\203", nullptr));
        showAllButton->setText(QCoreApplication::translate("Widget", "\320\222\321\213\320\262\320\265\321\201\321\202\320\270 \320\262\321\201\321\221", nullptr));
        sortButton->setText(QCoreApplication::translate("Widget", "\320\241\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\272\320\260", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "\320\222\321\213\321\205\320\276\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
