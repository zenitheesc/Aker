/********************************************************************************
** Form generated from reading UI file 'mm.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MM_H
#define UI_MM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MM
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MM)
    {
        if (MM->objectName().isEmpty())
            MM->setObjectName(QString::fromUtf8("MM"));
        MM->resize(800, 600);
        centralwidget = new QWidget(MM);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MM->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MM);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MM->setMenuBar(menubar);
        statusbar = new QStatusBar(MM);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MM->setStatusBar(statusbar);

        retranslateUi(MM);

        QMetaObject::connectSlotsByName(MM);
    } // setupUi

    void retranslateUi(QMainWindow *MM)
    {
        MM->setWindowTitle(QApplication::translate("MM", "Aker System - Mission Monitor", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MM: public Ui_MM {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MM_H
