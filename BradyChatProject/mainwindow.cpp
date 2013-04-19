#include "mainwindow.h"
#include "nuovoutente.h"
#include "chat.h"
#include "ui_mainwindow.h"
#include <QtSql/QtSql>
#include <QTcpSocket>
#include <QHostAddress>
#include <QAbstractSocket>
#include <QWidget>
#include <QBuffer>

QTcpSocket* sockmain;
QBuffer* buffermain;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sockmain = new QTcpSocket(this);
    buffermain = new QBuffer(this);
    buffermain->open(QIODevice::ReadWrite);
    char ip[15];
    FILE* fp;

        if (sockmain->state() == QAbstractSocket::UnconnectedState)
        {//Mi collego al server.

                    fp = fopen("config.cfg","r");
                    fscanf(fp,"%s",ip);
                    sockmain->connectToHost(ip,9003);
        }
        else
        {
                sockmain->disconnectFromHost();
        }
        connect(sockmain, SIGNAL(readyRead()),this, SLOT(ricevi()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete sockmain;
    delete buffermain;
}

void MainWindow::changeEvent(QEvent *e)
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

void MainWindow::ricevi() //Ricevo una risposta dal server in merito all'esistenza o meno dell'utente.
{
   Chat* w;

   qint64 bytes = buffermain->write(sockmain->readAll()); //Per leggere i messaggi dal server.
       buffermain->seek(buffermain->pos() - bytes);
       while (buffermain->canReadLine())
               {
                       QString line = buffermain->readLine();
                       if(line.startsWith("#"))
                       {
                           if(line.compare("#true\n")==0)
                           {
                               w = new Chat();
                               w->nomeUtente(this->ui->lineEdit->text());
                               w->chatRoom(this->ui->txtChatRoom->text());
                               w->show();
                               this->close();
                               sockmain->disconnectFromHost();
                           }
                           else
                           {
                              this->ui->lineEdit->setText("Non esisti");
                           }
                       }
               }
}

void MainWindow::on_btnAccedi_clicked() //Chiedo al server se l'utente esiste.
{
     sockmain->write("#/" + this->ui->lineEdit->text().toLatin1()+ "/" + this->ui->lineEdit_2->text().toLatin1()+"\n");
}

void MainWindow::on_btnIscriviti_clicked()
{
    nuovoUtente* w;
    w = new nuovoUtente();
    w->show();
    this->close();
}
