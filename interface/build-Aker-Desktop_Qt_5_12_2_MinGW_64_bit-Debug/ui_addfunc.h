/********************************************************************************
** Form generated from reading UI file 'addfunc.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDFUNC_H
#define UI_ADDFUNC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addFunc
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *vFuncID;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *vFuncName;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *vFuncParameters;
    QPushButton *pbOk;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *addFunc)
    {
        if (addFunc->objectName().isEmpty())
            addFunc->setObjectName(QString::fromUtf8("addFunc"));
        addFunc->resize(400, 240);
        addFunc->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 54);"));
        centralwidget = new QWidget(addFunc);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 0, 381, 191));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout->addWidget(label);

        vFuncID = new QLineEdit(layoutWidget);
        vFuncID->setObjectName(QString::fromUtf8("vFuncID"));
        vFuncID->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout->addWidget(vFuncID);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout_2->addWidget(label_2);

        vFuncName = new QLineEdit(layoutWidget);
        vFuncName->setObjectName(QString::fromUtf8("vFuncName"));
        vFuncName->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout_2->addWidget(vFuncName);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout_3->addWidget(label_3);

        vFuncParameters = new QLineEdit(layoutWidget);
        vFuncParameters->setObjectName(QString::fromUtf8("vFuncParameters"));
        vFuncParameters->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout_3->addWidget(vFuncParameters);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);

        pbOk = new QPushButton(layoutWidget);
        pbOk->setObjectName(QString::fromUtf8("pbOk"));
        pbOk->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 87, 83);\n"
"color: rgb(238, 238, 236);\n"
"font: 14pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        verticalLayout_2->addWidget(pbOk);

        addFunc->setCentralWidget(centralwidget);
        menubar = new QMenuBar(addFunc);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 400, 26));
        addFunc->setMenuBar(menubar);
        statusbar = new QStatusBar(addFunc);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        addFunc->setStatusBar(statusbar);

        retranslateUi(addFunc);

        QMetaObject::connectSlotsByName(addFunc);
    } // setupUi

    void retranslateUi(QMainWindow *addFunc)
    {
        addFunc->setWindowTitle(QApplication::translate("addFunc", "Add New Function", nullptr));
        label->setText(QApplication::translate("addFunc", "Function ID:", nullptr));
        label_2->setText(QApplication::translate("addFunc", "Function Name:", nullptr));
        label_3->setText(QApplication::translate("addFunc", "Number of Parameters:", nullptr));
        pbOk->setText(QApplication::translate("addFunc", "Ok", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addFunc: public Ui_addFunc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDFUNC_H
