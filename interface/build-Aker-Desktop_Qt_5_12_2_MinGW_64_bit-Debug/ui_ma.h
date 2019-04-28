/********************************************************************************
** Form generated from reading UI file 'ma.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MA_H
#define UI_MA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MA
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MA)
    {
        if (MA->objectName().isEmpty())
            MA->setObjectName(QString::fromUtf8("MA"));
        MA->resize(800, 600);
        centralwidget = new QWidget(MA);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MA->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MA);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MA->setMenuBar(menubar);
        statusbar = new QStatusBar(MA);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MA->setStatusBar(statusbar);

        retranslateUi(MA);

        QMetaObject::connectSlotsByName(MA);
    } // setupUi

    void retranslateUi(QMainWindow *MA)
    {
        MA->setWindowTitle(QApplication::translate("MA", "Aker System - Mission Analyzer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MA: public Ui_MA {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MA_H
