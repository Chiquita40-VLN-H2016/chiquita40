QT += core
QT -= gui
QT += core sql

CONFIG += c++11

TARGET = ComputerScientists
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    Scientist.cpp \
    DataAccess.cpp \
    ConsoleUI.cpp \
    Computer.cpp \
    SCService.cpp

HEADERS += \
    Scientist.h \
    DataAccess.h \
    ConsoleUI.h \
    Computer.h \
    SCService.h
