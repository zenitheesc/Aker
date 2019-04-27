/********************************************************************************
** Form generated from reading UI file 'eachparam.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EACHPARAM_H
#define UI_EACHPARAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_eachParam
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *vParamType;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *vParamName;
    QPushButton *pbOk;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *eachParam)
    {
        if (eachParam->objectName().isEmpty())
            eachParam->setObjectName(QStringLiteral("eachParam"));
        eachParam->resize(400, 240);
        eachParam->setStyleSheet(QStringLiteral("background-color: rgb(46, 52, 54);"));
        centralwidget = new QWidget(eachParam);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 0, 381, 181));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout_2->addWidget(label);

        vParamType = new QLineEdit(widget);
        vParamType->setObjectName(QStringLiteral("vParamType"));
        vParamType->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout_2->addWidget(vParamType);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout->addWidget(label_2);

        vParamName = new QLineEdit(widget);
        vParamName->setObjectName(QStringLiteral("vParamName"));
        vParamName->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout->addWidget(vParamName);


        verticalLayout->addLayout(horizontalLayout);

        pbOk = new QPushButton(widget);
        pbOk->setObjectName(QStringLiteral("pbOk"));
        pbOk->setStyleSheet(QLatin1String("background-color: rgb(85, 87, 83);\n"
"color: rgb(238, 238, 236);\n"
"font: 14pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        verticalLayout->addWidget(pbOk);

        eachParam->setCentralWidget(centralwidget);
        menubar = new QMenuBar(eachParam);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 400, 26));
        eachParam->setMenuBar(menubar);
        statusbar = new QStatusBar(eachParam);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        eachParam->setStatusBar(statusbar);

        retranslateUi(eachParam);

        QMetaObject::connectSlotsByName(eachParam);
    } // setupUi

    void retranslateUi(QMainWindow *eachParam)
    {
        eachParam->setWindowTitle(QApplication::translate("eachParam", "Parameter", Q_NULLPTR));
        label->setText(QApplication::translate("eachParam", "Parameter Type", Q_NULLPTR));
        label_2->setText(QApplication::translate("eachParam", "Parameter Name:", Q_NULLPTR));
        pbOk->setText(QApplication::translate("eachParam", "Ok", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class eachParam: public Ui_eachParam {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EACHPARAM_H
