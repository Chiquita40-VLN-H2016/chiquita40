#-------------------------------------------------
#
# Project created by QtCreator 2016-12-12T19:02:04
#
#-------------------------------------------------

QT       += core gui
QT       += core sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Skil3
TEMPLATE = app

SOURCES += main.cpp\
        MainWindow.cpp\
        Computer.cpp\
        DataAccess.cpp\
        Invented.cpp\
        Scientist.cpp\
        SCService.cpp \
    Utilities.cpp \
        DeleteWindow.cpp \
    EditWindow.cpp \
    ListWindow.cpp

HEADERS  += MainWindow.h\
         Computer.h\
         DataAccess.h\
         Invented.h\
         Scientist.h\
         SCService.h \
    Utilities.h\
         DeleteWindow.h \
    EditWindow.h \
    ListWindow.h


FORMS    += MainWindow.ui \
            DeleteWindow.ui \
    EditWindow.ui \
    ListWindow.ui
