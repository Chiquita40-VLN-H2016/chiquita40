QT += core
QT -= gui
QT += core sql

CONFIG += c++11

TARGET = ComputerScientists
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    ScientistService.cpp \
    Scientist.cpp \
    DataAccess.cpp \
    ConsoleUI.cpp \
    Computer.cpp \
    ComputerService.cpp \
    SCService.cpp

HEADERS += \
    ScientistService.h \
    Scientist.h \
    DataAccess.h \
    ConsoleUI.h \
    Computer.h \
    ComputerService.h \
    SCService.h
