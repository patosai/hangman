#-------------------------------------------------
#
# Project created by QtCreator 2014-10-11T02:53:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Hangman
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dataManagement.cpp

HEADERS  += mainwindow.h \
    dataManagement.h

FORMS    += mainwindow.ui
