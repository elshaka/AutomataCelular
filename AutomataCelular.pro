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
    onedimensionalca.cpp \
    twodimensionalca.cpp

HEADERS  += mainwindow.h \
    cell.h \
    cellularautomaton.h \
    onedimensionalca.h \
    twodimensionalca.h

FORMS    += mainwindow.ui
