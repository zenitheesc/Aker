/********************************************************************************
** Form generated from reading UI file 'missioninfo.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MISSIONINFO_H
#define UI_MISSIONINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MissionInfo
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QDateEdit *dateEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QLabel *label_5;
    QLineEdit *lineEdit_5;
    QLabel *label_6;
    QLineEdit *lineEdit_6;
    QLabel *label_7;
    QLineEdit *lineEdit_7;
    QLabel *label_8;
    QLineEdit *lineEdit_8;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_9;
    QPlainTextEdit *plainTextEdit;
    QLabel *label_10;
    QPlainTextEdit *plainTextEdit_2;
    QLabel *label_11;
    QPlainTextEdit *plainTextEdit_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MissionInfo)
    {
        if (MissionInfo->objectName().isEmpty())
            MissionInfo->setObjectName(QStringLiteral("MissionInfo"));
        MissionInfo->resize(800, 600);
        MissionInfo->setStyleSheet(QStringLiteral("background-color: rgb(46, 52, 54);"));
        centralwidget = new QWidget(MissionInfo);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 0, 401, 517));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QLatin1String("font: 15pt \"Courier 10 Pitch\";\n"
"color: rgb(238, 238, 236);"));

        horizontalLayout_3->addWidget(label);

        lineEdit = new QLineEdit(verticalLayoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QPalette palette;
        QBrush brush(QColor(46, 52, 54, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        lineEdit->setPalette(palette);
        lineEdit->setFocusPolicy(Qt::StrongFocus);

        horizontalLayout_3->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QLatin1String("font: 15pt \"Courier 10 Pitch\";\n"
"color: rgb(238, 238, 236);"));

        horizontalLayout_2->addWidget(label_2);

        dateEdit = new QDateEdit(verticalLayoutWidget);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setStyleSheet(QLatin1String("font: 15pt \"Courier 10 Pitch\";\n"
"color: rgb(238, 238, 236);"));

        horizontalLayout_2->addWidget(dateEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QLatin1String("font: 15pt \"Courier 10 Pitch\";\n"
"color: rgb(238, 238, 236);"));

        horizontalLayout_4->addWidget(label_3);

        lineEdit_3 = new QLineEdit(verticalLayoutWidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        horizontalLayout_4->addWidget(lineEdit_3);


        verticalLayout->addLayout(horizontalLayout_4);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setStyleSheet(QLatin1String("font: 15pt \"Courier 10 Pitch\";\n"
"color: rgb(238, 238, 236);"));

        verticalLayout->addWidget(label_4);

        lineEdit_4 = new QLineEdit(verticalLayoutWidget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        verticalLayout->addWidget(lineEdit_4);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setStyleSheet(QLatin1String("font: 15pt \"Courier 10 Pitch\";\n"
"color: rgb(238, 238, 236);"));

        verticalLayout->addWidget(label_5);

        lineEdit_5 = new QLineEdit(verticalLayoutWidget);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));

        verticalLayout->addWidget(lineEdit_5);

        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setStyleSheet(QLatin1String("font: 15pt \"Courier 10 Pitch\";\n"
"color: rgb(238, 238, 236);"));

        verticalLayout->addWidget(label_6);

        lineEdit_6 = new QLineEdit(verticalLayoutWidget);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));

        verticalLayout->addWidget(lineEdit_6);

        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setStyleSheet(QLatin1String("font: 15pt \"Courier 10 Pitch\";\n"
"color: rgb(238, 238, 236);"));

        verticalLayout->addWidget(label_7);

        lineEdit_7 = new QLineEdit(verticalLayoutWidget);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));

        verticalLayout->addWidget(lineEdit_7);

        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setStyleSheet(QLatin1String("font: 15pt \"Courier 10 Pitch\";\n"
"color: rgb(238, 238, 236);"));

        verticalLayout->addWidget(label_8);

        lineEdit_8 = new QLineEdit(verticalLayoutWidget);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));

        verticalLayout->addWidget(lineEdit_8);

        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(420, 0, 361, 481));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(verticalLayoutWidget_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setStyleSheet(QLatin1String("font: 15pt \"Courier 10 Pitch\";\n"
"color: rgb(238, 238, 236);"));

        verticalLayout_2->addWidget(label_9);

        plainTextEdit = new QPlainTextEdit(verticalLayoutWidget_2);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));

        verticalLayout_2->addWidget(plainTextEdit);

        label_10 = new QLabel(verticalLayoutWidget_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setStyleSheet(QLatin1String("font: 15pt \"Courier 10 Pitch\";\n"
"color: rgb(238, 238, 236);"));

        verticalLayout_2->addWidget(label_10);

        plainTextEdit_2 = new QPlainTextEdit(verticalLayoutWidget_2);
        plainTextEdit_2->setObjectName(QStringLiteral("plainTextEdit_2"));

        verticalLayout_2->addWidget(plainTextEdit_2);

        label_11 = new QLabel(verticalLayoutWidget_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setStyleSheet(QLatin1String("font: 15pt \"Courier 10 Pitch\";\n"
"color: rgb(238, 238, 236);"));

        verticalLayout_2->addWidget(label_11);

        plainTextEdit_3 = new QPlainTextEdit(verticalLayoutWidget_2);
        plainTextEdit_3->setObjectName(QStringLiteral("plainTextEdit_3"));

        verticalLayout_2->addWidget(plainTextEdit_3);

        MissionInfo->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MissionInfo);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MissionInfo->setMenuBar(menubar);
        statusbar = new QStatusBar(MissionInfo);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MissionInfo->setStatusBar(statusbar);

        retranslateUi(MissionInfo);

        QMetaObject::connectSlotsByName(MissionInfo);
    } // setupUi

    void retranslateUi(QMainWindow *MissionInfo)
    {
        MissionInfo->setWindowTitle(QApplication::translate("MissionInfo", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("MissionInfo", "Mission", Q_NULLPTR));
        lineEdit->setText(QString());
        label_2->setText(QApplication::translate("MissionInfo", "Date", Q_NULLPTR));
        label_3->setText(QApplication::translate("MissionInfo", "Team", Q_NULLPTR));
        label_4->setText(QApplication::translate("MissionInfo", "Mission Leader", Q_NULLPTR));
        label_5->setText(QApplication::translate("MissionInfo", "Project Manager", Q_NULLPTR));
        label_6->setText(QApplication::translate("MissionInfo", "Embeddeds Manager", Q_NULLPTR));
        label_7->setText(QApplication::translate("MissionInfo", "Structures Manager", Q_NULLPTR));
        label_8->setText(QApplication::translate("MissionInfo", "Flight Manager", Q_NULLPTR));
        label_9->setText(QApplication::translate("MissionInfo", "Mission Description", Q_NULLPTR));
        label_10->setText(QApplication::translate("MissionInfo", "Contact Information", Q_NULLPTR));
        label_11->setText(QApplication::translate("MissionInfo", "Other Informations", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MissionInfo: public Ui_MissionInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MISSIONINFO_H
