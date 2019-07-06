/********************************************************************************
** Form generated from reading UI file 'generate.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENERATE_H
#define UI_GENERATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_generate
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QListWidget *listMain;
    QPushButton *listMainPb;
    QLabel *label_2;
    QListWidget *listComm;
    QPushButton *listCommPb;
    QLabel *label_3;
    QListWidget *listSensor;
    QPushButton *listSensorPb;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QListWidget *listMainFunctions;
    QPushButton *mainFunctionPb;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_6;
    QListWidget *listCommFunctions;
    QPushButton *commFunctionPb;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_10;
    QListWidget *listSensorFunctions;
    QPushButton *sensorFunctionPb;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QLineEdit *vNumberOfStates;
    QPushButton *numberOfStatesPb;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_7;
    QComboBox *curStateBox;
    QLabel *label_11;
    QListWidget *listCurStateFunction;
    QPushButton *clearCurrFunctionStatePb;
    QPushButton *confirmFunctionsForStatePb;
    QPushButton *generatePb;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_8;
    QLineEdit *vNumberOfModules;
    QPushButton *numberOfModulesPb;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *generate)
    {
        if (generate->objectName().isEmpty())
            generate->setObjectName(QStringLiteral("generate"));
        generate->resize(800, 600);
        generate->setStyleSheet(QStringLiteral("background-color: rgb(46, 52, 54);"));
        centralwidget = new QWidget(generate);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 230, 241, 401));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        verticalLayout->addWidget(label);

        listMain = new QListWidget(verticalLayoutWidget);
        listMain->setObjectName(QStringLiteral("listMain"));
        listMain->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        verticalLayout->addWidget(listMain);

        listMainPb = new QPushButton(verticalLayoutWidget);
        listMainPb->setObjectName(QStringLiteral("listMainPb"));
        listMainPb->setStyleSheet(QLatin1String("background-color: rgb(85, 87, 83);\n"
"color: rgb(238, 238, 236);\n"
"font: 14pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        verticalLayout->addWidget(listMainPb);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        verticalLayout->addWidget(label_2);

        listComm = new QListWidget(verticalLayoutWidget);
        listComm->setObjectName(QStringLiteral("listComm"));
        listComm->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        verticalLayout->addWidget(listComm);

        listCommPb = new QPushButton(verticalLayoutWidget);
        listCommPb->setObjectName(QStringLiteral("listCommPb"));
        listCommPb->setStyleSheet(QLatin1String("background-color: rgb(85, 87, 83);\n"
"color: rgb(238, 238, 236);\n"
"font: 14pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        verticalLayout->addWidget(listCommPb);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        verticalLayout->addWidget(label_3);

        listSensor = new QListWidget(verticalLayoutWidget);
        listSensor->setObjectName(QStringLiteral("listSensor"));
        listSensor->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        verticalLayout->addWidget(listSensor);

        listSensorPb = new QPushButton(verticalLayoutWidget);
        listSensorPb->setObjectName(QStringLiteral("listSensorPb"));
        listSensorPb->setStyleSheet(QLatin1String("background-color: rgb(85, 87, 83);\n"
"color: rgb(238, 238, 236);\n"
"font: 14pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        verticalLayout->addWidget(listSensorPb);

        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(270, 20, 270, 521));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_5 = new QLabel(verticalLayoutWidget_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout->addWidget(label_5);


        verticalLayout_2->addLayout(horizontalLayout);

        listMainFunctions = new QListWidget(verticalLayoutWidget_2);
        listMainFunctions->setObjectName(QStringLiteral("listMainFunctions"));
        listMainFunctions->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        verticalLayout_2->addWidget(listMainFunctions);

        mainFunctionPb = new QPushButton(verticalLayoutWidget_2);
        mainFunctionPb->setObjectName(QStringLiteral("mainFunctionPb"));
        mainFunctionPb->setStyleSheet(QLatin1String("background-color: rgb(85, 87, 83);\n"
"color: rgb(238, 238, 236);\n"
"font: 14pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        verticalLayout_2->addWidget(mainFunctionPb);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_6 = new QLabel(verticalLayoutWidget_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout_2->addWidget(label_6);


        verticalLayout_2->addLayout(horizontalLayout_2);

        listCommFunctions = new QListWidget(verticalLayoutWidget_2);
        listCommFunctions->setObjectName(QStringLiteral("listCommFunctions"));
        listCommFunctions->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        verticalLayout_2->addWidget(listCommFunctions);

        commFunctionPb = new QPushButton(verticalLayoutWidget_2);
        commFunctionPb->setObjectName(QStringLiteral("commFunctionPb"));
        commFunctionPb->setStyleSheet(QLatin1String("background-color: rgb(85, 87, 83);\n"
"color: rgb(238, 238, 236);\n"
"font: 14pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        verticalLayout_2->addWidget(commFunctionPb);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_10 = new QLabel(verticalLayoutWidget_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout_5->addWidget(label_10);


        verticalLayout_2->addLayout(horizontalLayout_5);

        listSensorFunctions = new QListWidget(verticalLayoutWidget_2);
        listSensorFunctions->setObjectName(QStringLiteral("listSensorFunctions"));
        listSensorFunctions->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        verticalLayout_2->addWidget(listSensorFunctions);

        sensorFunctionPb = new QPushButton(verticalLayoutWidget_2);
        sensorFunctionPb->setObjectName(QStringLiteral("sensorFunctionPb"));
        sensorFunctionPb->setStyleSheet(QLatin1String("background-color: rgb(85, 87, 83);\n"
"color: rgb(238, 238, 236);\n"
"font: 14pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        verticalLayout_2->addWidget(sensorFunctionPb);

        verticalLayoutWidget_3 = new QWidget(centralwidget);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(20, 20, 241, 85));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(verticalLayoutWidget_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        verticalLayout_3->addWidget(label_4);

        vNumberOfStates = new QLineEdit(verticalLayoutWidget_3);
        vNumberOfStates->setObjectName(QStringLiteral("vNumberOfStates"));
        vNumberOfStates->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        verticalLayout_3->addWidget(vNumberOfStates);

        numberOfStatesPb = new QPushButton(verticalLayoutWidget_3);
        numberOfStatesPb->setObjectName(QStringLiteral("numberOfStatesPb"));
        numberOfStatesPb->setStyleSheet(QLatin1String("background-color: rgb(85, 87, 83);\n"
"color: rgb(238, 238, 236);\n"
"font: 14pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        verticalLayout_3->addWidget(numberOfStatesPb);

        verticalLayoutWidget_4 = new QWidget(centralwidget);
        verticalLayoutWidget_4->setObjectName(QStringLiteral("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(550, 20, 260, 471));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(verticalLayoutWidget_4);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        verticalLayout_4->addWidget(label_7);

        curStateBox = new QComboBox(verticalLayoutWidget_4);
        curStateBox->setObjectName(QStringLiteral("curStateBox"));
        curStateBox->setStyleSheet(QLatin1String("background-color: rgb(85, 87, 83);\n"
"color: rgb(238, 238, 236);\n"
"font: 14pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        verticalLayout_4->addWidget(curStateBox);

        label_11 = new QLabel(verticalLayoutWidget_4);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        verticalLayout_4->addWidget(label_11);

        listCurStateFunction = new QListWidget(verticalLayoutWidget_4);
        listCurStateFunction->setObjectName(QStringLiteral("listCurStateFunction"));
        listCurStateFunction->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        verticalLayout_4->addWidget(listCurStateFunction);

        clearCurrFunctionStatePb = new QPushButton(verticalLayoutWidget_4);
        clearCurrFunctionStatePb->setObjectName(QStringLiteral("clearCurrFunctionStatePb"));
        clearCurrFunctionStatePb->setStyleSheet(QLatin1String("background-color: rgb(85, 87, 83);\n"
"color: rgb(238, 238, 236);\n"
"font: 14pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        verticalLayout_4->addWidget(clearCurrFunctionStatePb);

        confirmFunctionsForStatePb = new QPushButton(verticalLayoutWidget_4);
        confirmFunctionsForStatePb->setObjectName(QStringLiteral("confirmFunctionsForStatePb"));
        confirmFunctionsForStatePb->setStyleSheet(QLatin1String("background-color: rgb(85, 87, 83);\n"
"color: rgb(238, 238, 236);\n"
"font: 14pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        verticalLayout_4->addWidget(confirmFunctionsForStatePb);

        generatePb = new QPushButton(centralwidget);
        generatePb->setObjectName(QStringLiteral("generatePb"));
        generatePb->setGeometry(QRect(550, 510, 239, 31));
        generatePb->setStyleSheet(QLatin1String("background-color: rgb(85, 87, 83);\n"
"color: rgb(238, 238, 236);\n"
"font: 14pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));
        verticalLayoutWidget_5 = new QWidget(centralwidget);
        verticalLayoutWidget_5->setObjectName(QStringLiteral("verticalLayoutWidget_5"));
        verticalLayoutWidget_5->setGeometry(QRect(20, 120, 241, 85));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_5);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(verticalLayoutWidget_5);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        verticalLayout_5->addWidget(label_8);

        vNumberOfModules = new QLineEdit(verticalLayoutWidget_5);
        vNumberOfModules->setObjectName(QStringLiteral("vNumberOfModules"));
        vNumberOfModules->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        verticalLayout_5->addWidget(vNumberOfModules);

        numberOfModulesPb = new QPushButton(verticalLayoutWidget_5);
        numberOfModulesPb->setObjectName(QStringLiteral("numberOfModulesPb"));
        numberOfModulesPb->setStyleSheet(QLatin1String("background-color: rgb(85, 87, 83);\n"
"color: rgb(238, 238, 236);\n"
"font: 14pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        verticalLayout_5->addWidget(numberOfModulesPb);

        generate->setCentralWidget(centralwidget);
        menubar = new QMenuBar(generate);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        generate->setMenuBar(menubar);
        statusbar = new QStatusBar(generate);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        generate->setStatusBar(statusbar);

        retranslateUi(generate);

        QMetaObject::connectSlotsByName(generate);
    } // setupUi

    void retranslateUi(QMainWindow *generate)
    {
        generate->setWindowTitle(QApplication::translate("generate", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("generate", "Main Module", Q_NULLPTR));
        listMainPb->setText(QApplication::translate("generate", "Ok", Q_NULLPTR));
        label_2->setText(QApplication::translate("generate", "Comm Module", Q_NULLPTR));
        listCommPb->setText(QApplication::translate("generate", "Ok", Q_NULLPTR));
        label_3->setText(QApplication::translate("generate", "Sensor Module", Q_NULLPTR));
        listSensorPb->setText(QApplication::translate("generate", "Ok", Q_NULLPTR));
        label_5->setText(QApplication::translate("generate", "Main Module Functions", Q_NULLPTR));
        mainFunctionPb->setText(QApplication::translate("generate", "add", Q_NULLPTR));
        label_6->setText(QApplication::translate("generate", "Comm Module Functions", Q_NULLPTR));
        commFunctionPb->setText(QApplication::translate("generate", "add", Q_NULLPTR));
        label_10->setText(QApplication::translate("generate", "Sensor Module Functions", Q_NULLPTR));
        sensorFunctionPb->setText(QApplication::translate("generate", "add", Q_NULLPTR));
        label_4->setText(QApplication::translate("generate", "Number of States", Q_NULLPTR));
        numberOfStatesPb->setText(QApplication::translate("generate", "confirm", Q_NULLPTR));
        label_7->setText(QApplication::translate("generate", "Current State", Q_NULLPTR));
        label_11->setText(QApplication::translate("generate", "Functions of this state", Q_NULLPTR));
        clearCurrFunctionStatePb->setText(QApplication::translate("generate", "clear", Q_NULLPTR));
        confirmFunctionsForStatePb->setText(QApplication::translate("generate", "confirm", Q_NULLPTR));
        generatePb->setText(QApplication::translate("generate", "Fucking Generate!", Q_NULLPTR));
        label_8->setText(QApplication::translate("generate", "Number of Modules", Q_NULLPTR));
        numberOfModulesPb->setText(QApplication::translate("generate", "confirm", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class generate: public Ui_generate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERATE_H
