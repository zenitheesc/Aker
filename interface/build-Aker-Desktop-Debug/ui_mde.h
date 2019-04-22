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
#include <QtWidgets/QTextBrowser>
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
    QLabel *zenithLogo;
    QTextBrowser *textBrowser;
    QLabel *label_2;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuLibraries;
    QMenu *menuHelp;

    void setupUi(QMainWindow *MDE)
    {
        if (MDE->objectName().isEmpty())
            MDE->setObjectName(QStringLiteral("MDE"));
        MDE->resize(700, 500);
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
        zenithLogo = new QLabel(centralwidget);
        zenithLogo->setObjectName(QStringLiteral("zenithLogo"));
        zenithLogo->setGeometry(QRect(50, 140, 341, 161));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(410, 140, 251, 161));
        textBrowser->setStyleSheet(QLatin1String("color: rgb(186, 189, 182);\n"
"background-color: rgb(46, 52, 54);\n"
"alternate-background-color: rgb(85, 87, 83);\n"
"border-color: rgb(46, 52, 54);"));
        textBrowser->setFrameShape(QFrame::NoFrame);
        textBrowser->setFrameShadow(QFrame::Plain);
        textBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textBrowser->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textBrowser->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        textBrowser->setTabChangesFocus(false);
        textBrowser->setLineWrapMode(QTextEdit::WidgetWidth);
        textBrowser->setLineWrapColumnOrWidth(0);
        textBrowser->setOpenLinks(false);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(410, 60, 231, 41));
        label_2->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"font: 75 italic 27pt \"Courier 10 Pitch\";"));
        label_2->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(450, 320, 191, 25));
        MDE->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MDE);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 700, 22));
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
        zenithLogo->setText(QString());
        textBrowser->setHtml(QApplication::translate("MDE", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">High Altitud Balloons (HAB's)</span></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">- General Command and Data Handling functions</span></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">- Telecommunications handler</span></p>\n"
"<p align=\"justify\" styl"
                        "e=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">- Power Supply management and monitor</span></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">- Multisensor handler and checker</span></p></body></html>", Q_NULLPTR));
        label_2->setText(QApplication::translate("MDE", "HAB's", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MDE", "Start a HAB project", Q_NULLPTR));
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
