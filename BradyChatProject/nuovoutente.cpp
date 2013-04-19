#include <QtSql/QtSql>
#include "nuovoutente.h"
#include "ui_nuovoutente.h"
#include "mainwindow.h"
#include <QTcpSocket>
#include <QHostAddress>
#include <QAbstractSocket>
#include <QWidget>
#include <QBuffer>

QTcpSocket* socknuovo;
QBuffer* buffernuovo;

nuovoUtente::nuovoUtente(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::nuovoUtente)
{
    ui->setupUi(this);
    socknuovo = new QTcpSocket(this);
       buffernuovo = new QBuffer(this);
       buffernuovo->open(QIODevice::ReadWrite);

       char ip[15];
       FILE* fp;

       if (socknuovo->state() == QAbstractSocket::UnconnectedState)
       {//Mi collego al server.

                   fp = fopen("config.cfg","r");
                   fscanf(fp,"%s",ip);
                   socknuovo->connectToHost(ip,9003);
       }
       else
       {
               socknuovo->disconnectFromHost();
       }
}

nuovoUtente::~nuovoUtente()
{
    delete ui;
    delete socknuovo;
    delete buffernuovo;
}

void nuovoUtente::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void nuovoUtente::on_btnRitorna_clicked()
{
    MainWindow* mainw = new MainWindow();
    mainw->show();
    this->close();
}

void nuovoUtente::on_btnIscriviti_clicked() //Chiedo al server di iscrivere un nuovo utente.
{
    socknuovo->write("!/" + this->ui->txtUserNameNew->text().toLatin1()+"/"+ this->ui->txtPasswordNew->text().toLatin1()+"\n");
    MainWindow* mainw = new MainWindow();
    mainw->show();
    socknuovo->disconnectFromHost();
    this->close();
}
