#-------------------------------------------------
#
# Project created by QtCreator 2011-10-05T13:56:30
#
#-------------------------------------------------

QT       += core gui

TARGET = ADCS_View
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    widget/core/connectDialog.cpp \
    adcs.cpp

HEADERS  += mainwindow.h \
    widget/core/connectDialog.h \
    adcs.h

FORMS    += mainwindow.ui \
    forms/ConnectDlg.ui






