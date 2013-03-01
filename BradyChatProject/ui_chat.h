/********************************************************************************
** Form generated from reading UI file 'chat.ui'
**
** Created: Fri Mar 1 15:43:39 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAT_H
#define UI_CHAT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Chat
{
public:
    QWidget *centralwidget;
    QPlainTextEdit *txtChatRoom;
    QLineEdit *txtMessage;
    QPushButton *btnInvia;
    QPushButton *btnRitorna;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Chat)
    {
        if (Chat->objectName().isEmpty())
            Chat->setObjectName(QString::fromUtf8("Chat"));
        Chat->resize(800, 600);
        centralwidget = new QWidget(Chat);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        txtChatRoom = new QPlainTextEdit(centralwidget);
        txtChatRoom->setObjectName(QString::fromUtf8("txtChatRoom"));
        txtChatRoom->setGeometry(QRect(3, 3, 791, 481));
        txtMessage = new QLineEdit(centralwidget);
        txtMessage->setObjectName(QString::fromUtf8("txtMessage"));
        txtMessage->setGeometry(QRect(0, 490, 791, 27));
        btnInvia = new QPushButton(centralwidget);
        btnInvia->setObjectName(QString::fromUtf8("btnInvia"));
        btnInvia->setGeometry(QRect(690, 520, 93, 27));
        btnRitorna = new QPushButton(centralwidget);
        btnRitorna->setObjectName(QString::fromUtf8("btnRitorna"));
        btnRitorna->setGeometry(QRect(0, 520, 111, 27));
        Chat->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Chat);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        Chat->setMenuBar(menubar);
        statusbar = new QStatusBar(Chat);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Chat->setStatusBar(statusbar);

        retranslateUi(Chat);

        QMetaObject::connectSlotsByName(Chat);
    } // setupUi

    void retranslateUi(QMainWindow *Chat)
    {
        Chat->setWindowTitle(QApplication::translate("Chat", "Chat", 0, QApplication::UnicodeUTF8));
        btnInvia->setText(QApplication::translate("Chat", "Invia", 0, QApplication::UnicodeUTF8));
        btnRitorna->setText(QApplication::translate("Chat", "Cambia Account", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Chat: public Ui_Chat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAT_H
