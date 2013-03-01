/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri Mar 1 15:43:39 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *txtUsername;
    QLineEdit *txtPassword;
    QPushButton *btnAccedi;
    QPushButton *btnIscriviti;
    QLabel *label_4;
    QPushButton *btnEsci;
    QLineEdit *txtChatRoom;
    QLabel *label_5;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(489, 400);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(160, 40, 71, 21));
        label->setTextFormat(Qt::RichText);
        label->setScaledContents(true);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(71, 90, 71, 20));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(80, 120, 62, 17));
        txtUsername = new QLineEdit(centralWidget);
        txtUsername->setObjectName(QString::fromUtf8("txtUsername"));
        txtUsername->setGeometry(QRect(150, 80, 113, 27));
        txtPassword = new QLineEdit(centralWidget);
        txtPassword->setObjectName(QString::fromUtf8("txtPassword"));
        txtPassword->setGeometry(QRect(150, 110, 113, 27));
        btnAccedi = new QPushButton(centralWidget);
        btnAccedi->setObjectName(QString::fromUtf8("btnAccedi"));
        btnAccedi->setGeometry(QRect(150, 170, 111, 27));
        btnIscriviti = new QPushButton(centralWidget);
        btnIscriviti->setObjectName(QString::fromUtf8("btnIscriviti"));
        btnIscriviti->setGeometry(QRect(190, 200, 93, 27));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 210, 201, 20));
        btnEsci = new QPushButton(centralWidget);
        btnEsci->setObjectName(QString::fromUtf8("btnEsci"));
        btnEsci->setGeometry(QRect(390, 300, 93, 27));
        txtChatRoom = new QLineEdit(centralWidget);
        txtChatRoom->setObjectName(QString::fromUtf8("txtChatRoom"));
        txtChatRoom->setGeometry(QRect(150, 140, 113, 27));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(80, 150, 62, 17));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 489, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(btnEsci, SIGNAL(clicked()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "BradyChat", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Login", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Username", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Password", 0, QApplication::UnicodeUTF8));
        btnAccedi->setText(QApplication::translate("MainWindow", "Accedi", 0, QApplication::UnicodeUTF8));
        btnIscriviti->setText(QApplication::translate("MainWindow", "Iscriviti ora", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Non sei ancora iscritto?", 0, QApplication::UnicodeUTF8));
        btnEsci->setText(QApplication::translate("MainWindow", "Esci", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "ChatRoom", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
