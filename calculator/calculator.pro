TEMPLATE = app
TARGET = main
QT = core gui
INCLUDEPATH += C:\\Users\\Hp\\Desktop\\muparser-2.3.4\\include
LIBS += -LC:\\Users\\Hp\\Desktop\\muparser-2.3.4\\lib -lmuparser

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += calculator.cpp \
           main.cpp

HEADERS += calculator.h
