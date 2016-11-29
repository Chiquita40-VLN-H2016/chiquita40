QT += core
QT -= gui

CONFIG += c++11

TARGET = ComputerScientists
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    csservices.cpp \
    csdata.cpp \
    scientist.cpp

HEADERS += \
    csservices.h \
    csdata.h \
    scientist.h
