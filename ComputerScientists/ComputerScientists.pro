QT += core
QT -= gui

CONFIG += c++11

TARGET = ComputerScientists
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    csdata.cpp \
    scientist.cpp \
    consoleui.cpp \
    csservice.cpp

HEADERS += \
    csdata.h \
    scientist.h \
    consoleui.h \
    csservice.h
