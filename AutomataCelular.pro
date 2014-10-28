#-------------------------------------------------
#
# Project created by QtCreator 2014-10-18T00:13:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AutomataCelular
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cell.cpp \
    cellularautomaton.cpp \
    wolfram.cpp \
    conway.cpp

HEADERS  += mainwindow.h \
    cell.h \
    cellularautomaton.h \
    wolfram.h \
    conway.h

FORMS    += mainwindow.ui
