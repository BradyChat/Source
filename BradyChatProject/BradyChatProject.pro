# -------------------------------------------------
# Project created by QtCreator 2013-02-23T11:54:25
# -------------------------------------------------
TARGET = BradyChatProject
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    nuovoutente.cpp \
    chat.cpp
HEADERS += mainwindow.h \
    nuovoutente.h \
    chat.h \
    Include/str.h \
    Include/SQLiteManager.hpp \
    Include/sqlite3.h \
    Include/SocketTCP.hpp \
    Include/Server.hpp \
    Include/Lista.hpp \
    Include/Client.hpp \
    Include/ChatAgent.hpp \
    Include/Address.hpp
FORMS += mainwindow.ui \
    nuovoutente.ui \
    chat.ui
QT += network \
    sql
