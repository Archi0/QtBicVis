#-------------------------------------------------
#
# Project created by QtCreator 2016-04-15T11:59:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtBiVis
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qbiclusterwindow.cpp \
    qcustomplot.cpp \
    common.cpp \
    qhistogram.cpp \
    qplotwindow.cpp \
    qsigmawindow.cpp \
    qbicstats.cpp \
    qbicwin.cpp \
    qparallelplot.cpp \
    optionsdialog.cpp

HEADERS  += mainwindow.h \
    qbiclusterwindow.h \
    common.h \
    qcustomplot.h \
    qhistogram.h \
    qplotwindow.h \
    qsigmawindow.h \
    qbicstats.h \
    qbicwin.h \
    qparallelplot.h \
    optionsdialog.h
QT += printsupport

INCLUDEPATH += "E:\Programowanie\boost_1_60_0"
