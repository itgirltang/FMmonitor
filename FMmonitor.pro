
TEMPLATE = app
TARGET = FMmonitor

QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += debug
DEFINES += QT5 QT_DLL

INCLUDEPATH += include
	
LIBPATH	+= debug

HEADERS += include/FMmonitor.h\
		   include/qFMmonitor.h
		   
SOURCES += source/main.cpp\
		   source/FMmonitor.cpp\
		   source/qFMmonitor.cpp
FORMS	+= ui/FMmonitor.ui