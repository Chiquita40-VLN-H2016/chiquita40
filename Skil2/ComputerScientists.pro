QT += core
QT -= gui

CONFIG += c++11

TARGET = ComputerScientists
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    ScientistService.cpp \
    Scientist.cpp \
    DataAccess.cpp \
    ConsoleUI.cpp

HEADERS += \
    ScientistService.h \
    Scientist.h \
    DataAccess.h \
    ConsoleUI.h
