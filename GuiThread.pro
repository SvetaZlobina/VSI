#-------------------------------------------------
#
# Project created by QtCreator 2016-10-21T08:46:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GuiThread
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    mythread.cpp \
    printdialog.cpp \
    fpthread.cpp

HEADERS  += dialog.h \
    mythread.h \
    printdialog.h \
    fpthread.h

FORMS    += dialog.ui \
    printdialog.ui
