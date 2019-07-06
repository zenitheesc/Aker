/********************************************************************************
** Form generated from reading UI file 'addfunc.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDFUNC_H
#define UI_ADDFUNC_H

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
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_4;
    QLineEdit *vModuleOfFunction;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLineEdit *vFuncRetType;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *vFuncParameters;
    QPushButton *pbOk;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_18;
    QLabel *paramLabelType0;
    QLineEdit *vParamType0;
    QLabel *paramLabelName0;
    QLineEdit *vParamName0;
    QHBoxLayout *horizontalLayout_6;
    QLabel *paramLabelType1;
    QLineEdit *vParamType1;
    QLabel *paramLabelName1;
    QLineEdit *vParamName1;
    QHBoxLayout *horizontalLayout_8;
    QLabel *paramLabelType2;
    QLineEdit *vParamType2;
    QLabel *paramLabelName2;
    QLineEdit *vParamName2;
    QHBoxLayout *horizontalLayout_15;
    QLabel *paramLabelType3;
    QLineEdit *vParamType3;
    QLabel *paramLabelName3;
    QLineEdit *vParamName3;
    QHBoxLayout *horizontalLayout_11;
    QLabel *paramLabelType4;
    QLineEdit *vParamType4;
    QLabel *paramLabelName4;
    QLineEdit *vParamName4;
    QHBoxLayout *horizontalLayout_14;
    QLabel *paramLabelType5;
    QLineEdit *vParamType5;
    QLabel *paramLabelName5;
    QLineEdit *vParamName5;
    QHBoxLayout *horizontalLayout_12;
    QLabel *paramLabelType6;
    QLineEdit *vParamType6;
    QLabel *paramLabelName6;
    QLineEdit *vParamName6;
    QHBoxLayout *horizontalLayout_17;
    QLabel *paramLabelType7;
    QLineEdit *vParamType7;
    QLabel *paramLabelName7;
    QLineEdit *vParamName7;
    QHBoxLayout *horizontalLayout_16;
    QLabel *paramLabelType8;
    QLineEdit *vParamType8;
    QLabel *paramLabelName8;
    QLineEdit *vParamName8;
    QHBoxLayout *horizontalLayout_9;
    QLabel *paramLabelType9;
    QLineEdit *vParamType9;
    QLabel *paramLabelName9;
    QLineEdit *vParamName9;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *addFunc)
    {
        if (addFunc->objectName().isEmpty())
            addFunc->setObjectName(QStringLiteral("addFunc"));
        addFunc->resize(829, 482);
        addFunc->setStyleSheet(QStringLiteral("background-color: rgb(46, 52, 54);"));
        centralwidget = new QWidget(addFunc);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 0, 381, 391));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout->addWidget(label);

        vFuncID = new QLineEdit(layoutWidget);
        vFuncID->setObjectName(QStringLiteral("vFuncID"));
        vFuncID->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout->addWidget(vFuncID);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout_2->addWidget(label_2);

        vFuncName = new QLineEdit(layoutWidget);
        vFuncName->setObjectName(QStringLiteral("vFuncName"));
        vFuncName->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout_2->addWidget(vFuncName);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout_7->addWidget(label_4);

        vModuleOfFunction = new QLineEdit(layoutWidget);
        vModuleOfFunction->setObjectName(QStringLiteral("vModuleOfFunction"));
        vModuleOfFunction->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout_7->addWidget(vModuleOfFunction);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout_4->addWidget(label_5);

        vFuncRetType = new QLineEdit(layoutWidget);
        vFuncRetType->setObjectName(QStringLiteral("vFuncRetType"));
        vFuncRetType->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout_4->addWidget(vFuncRetType);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout_3->addWidget(label_3);

        vFuncParameters = new QLineEdit(layoutWidget);
        vFuncParameters->setObjectName(QStringLiteral("vFuncParameters"));
        vFuncParameters->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout_3->addWidget(vFuncParameters);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);

        pbOk = new QPushButton(centralwidget);
        pbOk->setObjectName(QStringLiteral("pbOk"));
        pbOk->setGeometry(QRect(10, 400, 379, 31));
        pbOk->setStyleSheet(QLatin1String("background-color: rgb(85, 87, 83);\n"
"color: rgb(238, 238, 236);\n"
"font: 14pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));
        layoutWidget_2 = new QWidget(centralwidget);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(400, 0, 421, 431));
        verticalLayout_3 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        paramLabelType0 = new QLabel(layoutWidget_2);
        paramLabelType0->setObjectName(QStringLiteral("paramLabelType0"));
        paramLabelType0->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout_18->addWidget(paramLabelType0);

        vParamType0 = new QLineEdit(layoutWidget_2);
        vParamType0->setObjectName(QStringLiteral("vParamType0"));
        vParamType0->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout_18->addWidget(vParamType0);

        paramLabelName0 = new QLabel(layoutWidget_2);
        paramLabelName0->setObjectName(QStringLiteral("paramLabelName0"));
        paramLabelName0->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout_18->addWidget(paramLabelName0);

        vParamName0 = new QLineEdit(layoutWidget_2);
        vParamName0->setObjectName(QStringLiteral("vParamName0"));
        vParamName0->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout_18->addWidget(vParamName0);


        verticalLayout_3->addLayout(horizontalLayout_18);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        paramLabelType1 = new QLabel(layoutWidget_2);
        paramLabelType1->setObjectName(QStringLiteral("paramLabelType1"));
        paramLabelType1->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout_6->addWidget(paramLabelType1);

        vParamType1 = new QLineEdit(layoutWidget_2);
        vParamType1->setObjectName(QStringLiteral("vParamType1"));
        vParamType1->setEnabled(true);
        vParamType1->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout_6->addWidget(vParamType1);

        paramLabelName1 = new QLabel(layoutWidget_2);
        paramLabelName1->setObjectName(QStringLiteral("paramLabelName1"));
        paramLabelName1->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout_6->addWidget(paramLabelName1);

        vParamName1 = new QLineEdit(layoutWidget_2);
        vParamName1->setObjectName(QStringLiteral("vParamName1"));
        vParamName1->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout_6->addWidget(vParamName1);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        paramLabelType2 = new QLabel(layoutWidget_2);
        paramLabelType2->setObjectName(QStringLiteral("paramLabelType2"));
        paramLabelType2->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout_8->addWidget(paramLabelType2);

        vParamType2 = new QLineEdit(layoutWidget_2);
        vParamType2->setObjectName(QStringLiteral("vParamType2"));
        vParamType2->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout_8->addWidget(vParamType2);

        paramLabelName2 = new QLabel(layoutWidget_2);
        paramLabelName2->setObjectName(QStringLiteral("paramLabelName2"));
        paramLabelName2->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout_8->addWidget(paramLabelName2);

        vParamName2 = new QLineEdit(layoutWidget_2);
        vParamName2->setObjectName(QStringLiteral("vParamName2"));
        vParamName2->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout_8->addWidget(vParamName2);


        verticalLayout_3->addLayout(horizontalLayout_8);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        paramLabelType3 = new QLabel(layoutWidget_2);
        paramLabelType3->setObjectName(QStringLiteral("paramLabelType3"));
        paramLabelType3->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout_15->addWidget(paramLabelType3);

        vParamType3 = new QLineEdit(layoutWidget_2);
        vParamType3->setObjectName(QStringLiteral("vParamType3"));
        vParamType3->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout_15->addWidget(vParamType3);

        paramLabelName3 = new QLabel(layoutWidget_2);
        paramLabelName3->setObjectName(QStringLiteral("paramLabelName3"));
        paramLabelName3->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout_15->addWidget(paramLabelName3);

        vParamName3 = new QLineEdit(layoutWidget_2);
        vParamName3->setObjectName(QStringLiteral("vParamName3"));
        vParamName3->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout_15->addWidget(vParamName3);


        verticalLayout_3->addLayout(horizontalLayout_15);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        paramLabelType4 = new QLabel(layoutWidget_2);
        paramLabelType4->setObjectName(QStringLiteral("paramLabelType4"));
        paramLabelType4->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout_11->addWidget(paramLabelType4);

        vParamType4 = new QLineEdit(layoutWidget_2);
        vParamType4->setObjectName(QStringLiteral("vParamType4"));
        vParamType4->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout_11->addWidget(vParamType4);

        paramLabelName4 = new QLabel(layoutWidget_2);
        paramLabelName4->setObjectName(QStringLiteral("paramLabelName4"));
        paramLabelName4->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout_11->addWidget(paramLabelName4);

        vParamName4 = new QLineEdit(layoutWidget_2);
        vParamName4->setObjectName(QStringLiteral("vParamName4"));
        vParamName4->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout_11->addWidget(vParamName4);


        verticalLayout_3->addLayout(horizontalLayout_11);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        paramLabelType5 = new QLabel(layoutWidget_2);
        paramLabelType5->setObjectName(QStringLiteral("paramLabelType5"));
        paramLabelType5->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout_14->addWidget(paramLabelType5);

        vParamType5 = new QLineEdit(layoutWidget_2);
        vParamType5->setObjectName(QStringLiteral("vParamType5"));
        vParamType5->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout_14->addWidget(vParamType5);

        paramLabelName5 = new QLabel(layoutWidget_2);
        paramLabelName5->setObjectName(QStringLiteral("paramLabelName5"));
        paramLabelName5->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout_14->addWidget(paramLabelName5);

        vParamName5 = new QLineEdit(layoutWidget_2);
        vParamName5->setObjectName(QStringLiteral("vParamName5"));
        vParamName5->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout_14->addWidget(vParamName5);


        verticalLayout_3->addLayout(horizontalLayout_14);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        paramLabelType6 = new QLabel(layoutWidget_2);
        paramLabelType6->setObjectName(QStringLiteral("paramLabelType6"));
        paramLabelType6->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout_12->addWidget(paramLabelType6);

        vParamType6 = new QLineEdit(layoutWidget_2);
        vParamType6->setObjectName(QStringLiteral("vParamType6"));
        vParamType6->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout_12->addWidget(vParamType6);

        paramLabelName6 = new QLabel(layoutWidget_2);
        paramLabelName6->setObjectName(QStringLiteral("paramLabelName6"));
        paramLabelName6->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout_12->addWidget(paramLabelName6);

        vParamName6 = new QLineEdit(layoutWidget_2);
        vParamName6->setObjectName(QStringLiteral("vParamName6"));
        vParamName6->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout_12->addWidget(vParamName6);


        verticalLayout_3->addLayout(horizontalLayout_12);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        paramLabelType7 = new QLabel(layoutWidget_2);
        paramLabelType7->setObjectName(QStringLiteral("paramLabelType7"));
        paramLabelType7->setEnabled(true);
        paramLabelType7->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout_17->addWidget(paramLabelType7);

        vParamType7 = new QLineEdit(layoutWidget_2);
        vParamType7->setObjectName(QStringLiteral("vParamType7"));
        vParamType7->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout_17->addWidget(vParamType7);

        paramLabelName7 = new QLabel(layoutWidget_2);
        paramLabelName7->setObjectName(QStringLiteral("paramLabelName7"));
        paramLabelName7->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout_17->addWidget(paramLabelName7);

        vParamName7 = new QLineEdit(layoutWidget_2);
        vParamName7->setObjectName(QStringLiteral("vParamName7"));
        vParamName7->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout_17->addWidget(vParamName7);


        verticalLayout_3->addLayout(horizontalLayout_17);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        paramLabelType8 = new QLabel(layoutWidget_2);
        paramLabelType8->setObjectName(QStringLiteral("paramLabelType8"));
        paramLabelType8->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout_16->addWidget(paramLabelType8);

        vParamType8 = new QLineEdit(layoutWidget_2);
        vParamType8->setObjectName(QStringLiteral("vParamType8"));
        vParamType8->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout_16->addWidget(vParamType8);

        paramLabelName8 = new QLabel(layoutWidget_2);
        paramLabelName8->setObjectName(QStringLiteral("paramLabelName8"));
        paramLabelName8->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout_16->addWidget(paramLabelName8);

        vParamName8 = new QLineEdit(layoutWidget_2);
        vParamName8->setObjectName(QStringLiteral("vParamName8"));
        vParamName8->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout_16->addWidget(vParamName8);


        verticalLayout_3->addLayout(horizontalLayout_16);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        paramLabelType9 = new QLabel(layoutWidget_2);
        paramLabelType9->setObjectName(QStringLiteral("paramLabelType9"));
        paramLabelType9->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout_9->addWidget(paramLabelType9);

        vParamType9 = new QLineEdit(layoutWidget_2);
        vParamType9->setObjectName(QStringLiteral("vParamType9"));
        vParamType9->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout_9->addWidget(vParamType9);

        paramLabelName9 = new QLabel(layoutWidget_2);
        paramLabelName9->setObjectName(QStringLiteral("paramLabelName9"));
        paramLabelName9->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout_9->addWidget(paramLabelName9);

        vParamName9 = new QLineEdit(layoutWidget_2);
        vParamName9->setObjectName(QStringLiteral("vParamName9"));
        vParamName9->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout_9->addWidget(vParamName9);


        verticalLayout_3->addLayout(horizontalLayout_9);

        addFunc->setCentralWidget(centralwidget);
        menubar = new QMenuBar(addFunc);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 829, 22));
        addFunc->setMenuBar(menubar);
        statusbar = new QStatusBar(addFunc);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        addFunc->setStatusBar(statusbar);

        retranslateUi(addFunc);

        QMetaObject::connectSlotsByName(addFunc);
    } // setupUi

    void retranslateUi(QMainWindow *addFunc)
    {
        addFunc->setWindowTitle(QApplication::translate("addFunc", "Add New Function", Q_NULLPTR));
        label->setText(QApplication::translate("addFunc", "Function ID:", Q_NULLPTR));
        label_2->setText(QApplication::translate("addFunc", "Function Name:", Q_NULLPTR));
        label_4->setText(QApplication::translate("addFunc", "Module of Function", Q_NULLPTR));
        label_5->setText(QApplication::translate("addFunc", "Return Type", Q_NULLPTR));
        label_3->setText(QApplication::translate("addFunc", "Number of Parameters:", Q_NULLPTR));
        pbOk->setText(QApplication::translate("addFunc", "Ok", Q_NULLPTR));
        paramLabelType0->setText(QApplication::translate("addFunc", "Type 0", Q_NULLPTR));
        paramLabelName0->setText(QApplication::translate("addFunc", "Name 0", Q_NULLPTR));
        paramLabelType1->setText(QApplication::translate("addFunc", "Type 1", Q_NULLPTR));
        paramLabelName1->setText(QApplication::translate("addFunc", "Name 1", Q_NULLPTR));
        paramLabelType2->setText(QApplication::translate("addFunc", "Type 2", Q_NULLPTR));
        paramLabelName2->setText(QApplication::translate("addFunc", "Name 2", Q_NULLPTR));
        paramLabelType3->setText(QApplication::translate("addFunc", "Type 3", Q_NULLPTR));
        paramLabelName3->setText(QApplication::translate("addFunc", "Name 3", Q_NULLPTR));
        paramLabelType4->setText(QApplication::translate("addFunc", "Type 4", Q_NULLPTR));
        paramLabelName4->setText(QApplication::translate("addFunc", "Name 4", Q_NULLPTR));
        paramLabelType5->setText(QApplication::translate("addFunc", "Type 5", Q_NULLPTR));
        paramLabelName5->setText(QApplication::translate("addFunc", "Name 5", Q_NULLPTR));
        paramLabelType6->setText(QApplication::translate("addFunc", "Type 6", Q_NULLPTR));
        paramLabelName6->setText(QApplication::translate("addFunc", "Name 6", Q_NULLPTR));
        paramLabelType7->setText(QApplication::translate("addFunc", "Type 7", Q_NULLPTR));
        paramLabelName7->setText(QApplication::translate("addFunc", "Name 7", Q_NULLPTR));
        paramLabelType8->setText(QApplication::translate("addFunc", "Type 8", Q_NULLPTR));
        paramLabelName8->setText(QApplication::translate("addFunc", "Name 8", Q_NULLPTR));
        paramLabelType9->setText(QApplication::translate("addFunc", "Type 9", Q_NULLPTR));
        paramLabelName9->setText(QApplication::translate("addFunc", "Name 9", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class addFunc: public Ui_addFunc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDFUNC_H
