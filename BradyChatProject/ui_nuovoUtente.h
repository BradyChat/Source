/********************************************************************************
** Form generated from reading UI file 'nuovoutente.ui'
**
** Created: Fri Apr 19 17:32:23 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NUOVOUTENTE_H
#define UI_NUOVOUTENTE_H

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
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_nuovoUtente
{
public:
    QWidget *centralwidget;
    QLineEdit *txtUserNameNew;
    QLabel *label_2;
    QLabel *lblEsistenzaAccount;
    QPushButton *btnRitorna;
    QLabel *label_3;
    QPushButton *btnIscriviti;
    QLineEdit *txtPasswordNew;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *nuovoUtente)
    {
        if (nuovoUtente->objectName().isEmpty())
            nuovoUtente->setObjectName(QString::fromUtf8("nuovoUtente"));
        nuovoUtente->resize(243, 237);
        centralwidget = new QWidget(nuovoUtente);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        txtUserNameNew = new QLineEdit(centralwidget);
        txtUserNameNew->setObjectName(QString::fromUtf8("txtUserNameNew"));
        txtUserNameNew->setGeometry(QRect(99, 40, 113, 27));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 50, 71, 20));
        lblEsistenzaAccount = new QLabel(centralwidget);
        lblEsistenzaAccount->setObjectName(QString::fromUtf8("lblEsistenzaAccount"));
        lblEsistenzaAccount->setGeometry(QRect(100, 130, 62, 17));
        btnRitorna = new QPushButton(centralwidget);
        btnRitorna->setObjectName(QString::fromUtf8("btnRitorna"));
        btnRitorna->setGeometry(QRect(100, 150, 111, 27));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(29, 80, 62, 17));
        btnIscriviti = new QPushButton(centralwidget);
        btnIscriviti->setObjectName(QString::fromUtf8("btnIscriviti"));
        btnIscriviti->setGeometry(QRect(100, 100, 111, 27));
        txtPasswordNew = new QLineEdit(centralwidget);
        txtPasswordNew->setObjectName(QString::fromUtf8("txtPasswordNew"));
        txtPasswordNew->setGeometry(QRect(99, 70, 113, 27));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(109, 0, 71, 21));
        label->setTextFormat(Qt::RichText);
        label->setScaledContents(true);
        nuovoUtente->setCentralWidget(centralwidget);
        menubar = new QMenuBar(nuovoUtente);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 243, 25));
        nuovoUtente->setMenuBar(menubar);
        statusbar = new QStatusBar(nuovoUtente);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        nuovoUtente->setStatusBar(statusbar);

        retranslateUi(nuovoUtente);

        QMetaObject::connectSlotsByName(nuovoUtente);
    } // setupUi

    void retranslateUi(QMainWindow *nuovoUtente)
    {
        nuovoUtente->setWindowTitle(QApplication::translate("nuovoUtente", "Nuovo Utente", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("nuovoUtente", "Username", 0, QApplication::UnicodeUTF8));
        lblEsistenzaAccount->setText(QString());
        btnRitorna->setText(QApplication::translate("nuovoUtente", "Selezione utente", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("nuovoUtente", "Password", 0, QApplication::UnicodeUTF8));
        btnIscriviti->setText(QApplication::translate("nuovoUtente", "Iscriviti", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("nuovoUtente", "Iscrizione", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class nuovoUtente: public Ui_nuovoUtente {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NUOVOUTENTE_H
