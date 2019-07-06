/********************************************************************************
** Form generated from reading UI file 'mde.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MDE_H
#define UI_MDE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MDE
{
public:
    QAction *actionGeneral_Infos;
    QAction *actionAdd_library;
    QAction *actionSearch_modules;
    QAction *actionSearch_functions;
    QAction *actionAker_Documentation;
    QAction *actionTutorials;
    QAction *actionContact;
    QWidget *centralwidget;
    QLabel *vMdeLogo;
    QPushButton *pbAddFunction;
    QPushButton *pbAddModule;
    QPushButton *pbGenerate;
    QPushButton *pbExit;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuLibraries;
    QMenu *menuHelp;

    void setupUi(QMainWindow *MDE)
    {
        if (MDE->objectName().isEmpty())
            MDE->setObjectName(QStringLiteral("MDE"));
        MDE->resize(557, 351);
        MDE->setStyleSheet(QStringLiteral("background-color: rgb(46, 52, 54);"));
        actionGeneral_Infos = new QAction(MDE);
        actionGeneral_Infos->setObjectName(QStringLiteral("actionGeneral_Infos"));
        actionAdd_library = new QAction(MDE);
        actionAdd_library->setObjectName(QStringLiteral("actionAdd_library"));
        actionSearch_modules = new QAction(MDE);
        actionSearch_modules->setObjectName(QStringLiteral("actionSearch_modules"));
        actionSearch_functions = new QAction(MDE);
        actionSearch_functions->setObjectName(QStringLiteral("actionSearch_functions"));
        actionAker_Documentation = new QAction(MDE);
        actionAker_Documentation->setObjectName(QStringLiteral("actionAker_Documentation"));
        actionTutorials = new QAction(MDE);
        actionTutorials->setObjectName(QStringLiteral("actionTutorials"));
        actionContact = new QAction(MDE);
        actionContact->setObjectName(QStringLiteral("actionContact"));
        centralwidget = new QWidget(MDE);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        vMdeLogo = new QLabel(centralwidget);
        vMdeLogo->setObjectName(QStringLiteral("vMdeLogo"));
        vMdeLogo->setGeometry(QRect(110, 120, 341, 181));
        vMdeLogo->setPixmap(QPixmap(QString::fromUtf8("../MDELOGO.png")));
        pbAddFunction = new QPushButton(centralwidget);
        pbAddFunction->setObjectName(QStringLiteral("pbAddFunction"));
        pbAddFunction->setGeometry(QRect(30, 7, 241, 41));
        pbAddFunction->setStyleSheet(QLatin1String("background-color: rgb(85, 87, 83);\n"
"color: rgb(238, 238, 236);\n"
"font: 14pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));
        pbAddModule = new QPushButton(centralwidget);
        pbAddModule->setObjectName(QStringLiteral("pbAddModule"));
        pbAddModule->setGeometry(QRect(290, 10, 241, 41));
        pbAddModule->setStyleSheet(QLatin1String("background-color: rgb(85, 87, 83);\n"
"color: rgb(238, 238, 236);\n"
"font: 14pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));
        pbGenerate = new QPushButton(centralwidget);
        pbGenerate->setObjectName(QStringLiteral("pbGenerate"));
        pbGenerate->setGeometry(QRect(30, 60, 241, 41));
        pbGenerate->setStyleSheet(QLatin1String("background-color: rgb(85, 87, 83);\n"
"color: rgb(238, 238, 236);\n"
"font: 14pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));
        pbExit = new QPushButton(centralwidget);
        pbExit->setObjectName(QStringLiteral("pbExit"));
        pbExit->setGeometry(QRect(290, 60, 241, 41));
        pbExit->setStyleSheet(QLatin1String("background-color: rgb(85, 87, 83);\n"
"color: rgb(238, 238, 236);\n"
"font: 14pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));
        MDE->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MDE);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 557, 26));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuLibraries = new QMenu(menubar);
        menuLibraries->setObjectName(QStringLiteral("menuLibraries"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MDE->setMenuBar(menubar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuLibraries->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionGeneral_Infos);
        menuLibraries->addAction(actionAdd_library);
        menuLibraries->addAction(actionSearch_modules);
        menuLibraries->addAction(actionSearch_functions);
        menuHelp->addAction(actionAker_Documentation);
        menuHelp->addAction(actionTutorials);
        menuHelp->addAction(actionContact);

        retranslateUi(MDE);

        QMetaObject::connectSlotsByName(MDE);
    } // setupUi

    void retranslateUi(QMainWindow *MDE)
    {
        MDE->setWindowTitle(QApplication::translate("MDE", "Aker System - Mission Design Environment", Q_NULLPTR));
        actionGeneral_Infos->setText(QApplication::translate("MDE", "General Infos", Q_NULLPTR));
        actionAdd_library->setText(QApplication::translate("MDE", "Add library", Q_NULLPTR));
        actionSearch_modules->setText(QApplication::translate("MDE", "Search modules", Q_NULLPTR));
        actionSearch_functions->setText(QApplication::translate("MDE", "Search functions", Q_NULLPTR));
        actionAker_Documentation->setText(QApplication::translate("MDE", "Aker Documentation", Q_NULLPTR));
        actionTutorials->setText(QApplication::translate("MDE", "Tutorials", Q_NULLPTR));
        actionContact->setText(QApplication::translate("MDE", "Contact", Q_NULLPTR));
        vMdeLogo->setText(QString());
        pbAddFunction->setText(QApplication::translate("MDE", "Add Function", Q_NULLPTR));
        pbAddModule->setText(QApplication::translate("MDE", "Add Module", Q_NULLPTR));
        pbGenerate->setText(QApplication::translate("MDE", "Generate Code", Q_NULLPTR));
        pbExit->setText(QApplication::translate("MDE", "Exit", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MDE", "File", Q_NULLPTR));
        menuLibraries->setTitle(QApplication::translate("MDE", "Libraries", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("MDE", "Help", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MDE: public Ui_MDE {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MDE_H
