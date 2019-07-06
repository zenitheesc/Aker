/********************************************************************************
** Form generated from reading UI file 'firstmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIRSTMENU_H
#define UI_FIRSTMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FirstMenu
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLabel *ZenithLogo;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_6;
    QVBoxLayout *verticalLayout;
    QPushButton *startMDE;
    QPushButton *startMM;
    QPushButton *startMA;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_5;
    QLabel *AkerLabel;

    void setupUi(QMainWindow *FirstMenu)
    {
        if (FirstMenu->objectName().isEmpty())
            FirstMenu->setObjectName(QStringLiteral("FirstMenu"));
        FirstMenu->resize(557, 351);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FirstMenu->sizePolicy().hasHeightForWidth());
        FirstMenu->setSizePolicy(sizePolicy);
        FirstMenu->setStyleSheet(QStringLiteral("background-color: rgb(46, 52, 54);"));
        centralWidget = new QWidget(FirstMenu);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        ZenithLogo = new QLabel(centralWidget);
        ZenithLogo->setObjectName(QStringLiteral("ZenithLogo"));
        ZenithLogo->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(ZenithLogo, 4, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 3, 2, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 4, 2, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        startMDE = new QPushButton(centralWidget);
        startMDE->setObjectName(QStringLiteral("startMDE"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(startMDE->sizePolicy().hasHeightForWidth());
        startMDE->setSizePolicy(sizePolicy1);
        startMDE->setSizeIncrement(QSize(2, 2));
        startMDE->setStyleSheet(QLatin1String("background-color: rgb(85, 87, 83);\n"
"color: rgb(238, 238, 236);\n"
"font: 14pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        verticalLayout->addWidget(startMDE);

        startMM = new QPushButton(centralWidget);
        startMM->setObjectName(QStringLiteral("startMM"));
        sizePolicy1.setHeightForWidth(startMM->sizePolicy().hasHeightForWidth());
        startMM->setSizePolicy(sizePolicy1);
        startMM->setStyleSheet(QLatin1String("background-color: rgb(85, 87, 83);\n"
"color: rgb(238, 238, 236);\n"
"font: 14pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        verticalLayout->addWidget(startMM);

        startMA = new QPushButton(centralWidget);
        startMA->setObjectName(QStringLiteral("startMA"));
        sizePolicy1.setHeightForWidth(startMA->sizePolicy().hasHeightForWidth());
        startMA->setSizePolicy(sizePolicy1);
        startMA->setStyleSheet(QLatin1String("background-color: rgb(85, 87, 83);\n"
"color: rgb(238, 238, 236);\n"
"font: 14pt \"Courier 10 Pitch\";\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-right-color: rgb(0, 0, 0);\n"
"border-bottom-color: rgb(0, 0, 0);"));

        verticalLayout->addWidget(startMA);


        gridLayout->addLayout(verticalLayout, 3, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 4, 0, 1, 1);

        AkerLabel = new QLabel(centralWidget);
        AkerLabel->setObjectName(QStringLiteral("AkerLabel"));
        AkerLabel->setLayoutDirection(Qt::RightToLeft);
        AkerLabel->setStyleSheet(QLatin1String("font: 24pt \"Courier 10 Pitch\";\n"
"color: rgb(238, 238, 236);"));
        AkerLabel->setFrameShape(QFrame::NoFrame);
        AkerLabel->setLineWidth(0);
        AkerLabel->setAlignment(Qt::AlignCenter);
        AkerLabel->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse|Qt::TextBrowserInteraction|Qt::TextEditable|Qt::TextEditorInteraction|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout->addWidget(AkerLabel, 0, 1, 1, 1);

        FirstMenu->setCentralWidget(centralWidget);

        retranslateUi(FirstMenu);

        QMetaObject::connectSlotsByName(FirstMenu);
    } // setupUi

    void retranslateUi(QMainWindow *FirstMenu)
    {
        FirstMenu->setWindowTitle(QApplication::translate("FirstMenu", "Aker System", Q_NULLPTR));
        ZenithLogo->setText(QString());
        startMDE->setText(QApplication::translate("FirstMenu", "Mission Design Environment", Q_NULLPTR));
        startMM->setText(QApplication::translate("FirstMenu", "Mission Monitor", Q_NULLPTR));
        startMA->setText(QApplication::translate("FirstMenu", "Mission Analyzer", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        AkerLabel->setToolTip(QApplication::translate("FirstMenu", "<html><head/><body><p align=\"center\">Aker System</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        AkerLabel->setText(QApplication::translate("FirstMenu", "Aker System", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FirstMenu: public Ui_FirstMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIRSTMENU_H
