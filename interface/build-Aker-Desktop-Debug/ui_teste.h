/********************************************************************************
** Form generated from reading UI file 'teste.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTE_H
#define UI_TESTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_teste
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *teste)
    {
        if (teste->objectName().isEmpty())
            teste->setObjectName(QStringLiteral("teste"));
        teste->resize(800, 600);
        menubar = new QMenuBar(teste);
        menubar->setObjectName(QStringLiteral("menubar"));
        teste->setMenuBar(menubar);
        centralwidget = new QWidget(teste);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        teste->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(teste);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        teste->setStatusBar(statusbar);

        retranslateUi(teste);

        QMetaObject::connectSlotsByName(teste);
    } // setupUi

    void retranslateUi(QMainWindow *teste)
    {
        teste->setWindowTitle(QApplication::translate("teste", "MainWindow", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class teste: public Ui_teste {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTE_H
