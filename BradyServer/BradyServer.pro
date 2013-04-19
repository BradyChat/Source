# -------------------------------------------------
# Project created by QtCreator 2013-04-12T18:32:20
# -------------------------------------------------
QT -= gui
TARGET = BradyServer
CONFIG += console
CONFIG -= app_bundle
TEMPLATE = app
SOURCES += main.cpp \
    Server.cpp
HEADERS += Server.h
QT += network \
	sql
