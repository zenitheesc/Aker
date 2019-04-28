/********************************************************************************
** Form generated from reading UI file 'addmodule.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDMODULE_H
#define UI_ADDMODULE_H

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

class Ui_addModule
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *vModuleID;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *vModuleName;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *vModuleClassifier;
    QPushButton *pbOk;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *addModule)
    {
        if (addModule->objectName().isEmpty())
            addModule->setObjectName(QStringLiteral("addModule"));
        addModule->resize(221, 175);
        addModule->setStyleSheet(QStringLiteral("background-color: rgb(46, 52, 54);"));
        centralwidget = new QWidget(addModule);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 0, 205, 129));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout->addWidget(label_2);

        vModuleID = new QLineEdit(verticalLayoutWidget);
        vModuleID->setObjectName(QStringLiteral("vModuleID"));
        vModuleID->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout->addWidget(vModuleID);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout_2->addWidget(label_3);

        vModuleName = new QLineEdit(verticalLayoutWidget);
        vModuleName->setObjectName(QStringLiteral("vModuleName"));
        vModuleName->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout_2->addWidget(vModuleName);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout_3->addWidget(label_4);

        vModuleClassifier = new QLineEdit(verticalLayoutWidget);
        vModuleClassifier->setObjectName(QStringLiteral("vModuleClassifier"));
        vModuleClassifier->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 10pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        horizontalLayout_3->addWidget(vModuleClassifier);


        verticalLayout->addLayout(horizontalLayout_3);

        pbOk = new QPushButton(verticalLayoutWidget);
        pbOk->setObjectName(QStringLiteral("pbOk"));
        pbOk->setStyleSheet(QLatin1String("background-color: rgb(85, 87, 83);\n"
"color: rgb(238, 238, 236);\n"
"font: 14pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        verticalLayout->addWidget(pbOk);

        addModule->setCentralWidget(centralwidget);
        menubar = new QMenuBar(addModule);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 221, 22));
        addModule->setMenuBar(menubar);
        statusbar = new QStatusBar(addModule);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        addModule->setStatusBar(statusbar);

        retranslateUi(addModule);

        QMetaObject::connectSlotsByName(addModule);
    } // setupUi

    void retranslateUi(QMainWindow *addModule)
    {
        addModule->setWindowTitle(QApplication::translate("addModule", "MainWindow", Q_NULLPTR));
        label_2->setText(QApplication::translate("addModule", "ID", Q_NULLPTR));
        label_3->setText(QApplication::translate("addModule", "Name", Q_NULLPTR));
        label_4->setText(QApplication::translate("addModule", "Classifier", Q_NULLPTR));
        pbOk->setText(QApplication::translate("addModule", "Ok", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class addModule: public Ui_addModule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDMODULE_H
