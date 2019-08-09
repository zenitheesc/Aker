#-------------------------------------------------
#
# Project created by QtCreator 2019-01-23T23:57:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Aker
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        firstmenu.cpp \
    mde.cpp \
    mm.cpp \
    ma.cpp \
    missioninfo.cpp \
    addfunc.cpp \
    codegenerator.cpp \
    addmodule.cpp \
    generate.cpp

HEADERS += \
        firstmenu.h \
    mde.h \
    mm.h \
    ma.h \
    missioninfo.h \
    addfunc.h \
    codegenerator.h \
    addmodule.h \
    generate.h

FORMS += \
        firstmenu.ui \
    mde.ui \
    mm.ui \
    ma.ui \
    missioninfo.ui \
    addfunc.ui \
    addmodule.ui \
    generate.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES +=
