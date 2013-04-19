#include <qtimer.h>
#include <QTcpSocket>
#include <QHostAddress>
#include <QAbstractSocket>
#include <QWidget>
#include <QBuffer>
#include <string.h>
#include "chat.h"
#include "ui_chat.h"
#include "mainwindow.h"
#include <stdio.h>


QString _nome;
QString _chatroom;
//Client* _client;
QTcpSocket* sock;
QBuffer* buffer;

Chat::Chat(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Chat)
{
    ui->setupUi(this);
    sock = new QTcpSocket(this);
    buffer = new QBuffer(this);
    buffer->open(QIODevice::ReadWrite);

    char ip[15];
    FILE* fp;

    if (sock->state() == QAbstractSocket::UnconnectedState)//Mi collego al server.
    {

                fp = fopen("config.cfg","r");
                fscanf(fp,"%s",ip);
                sock->connectToHost(ip,9003);
    }
    else
    {
            sock->disconnectFromHost();
    }
    connect(sock, SIGNAL(readyRead()),this, SLOT(on_btnAggiorna_clicked()));
    connect(this->ui->txtMessage,SIGNAL(returnPressed()), SLOT(on_btnInvia_clicked()));
}

Chat::~Chat()
{
    delete ui;
    delete sock;
    delete buffer;
}

void Chat::changeEvent(QEvent *e)
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

void Chat::nomeUtente(QString nome)
{
    _nome = nome;
}

void Chat::chatRoom(QString chatroom)
{
    _chatroom = chatroom;
}

void Chat::on_btnRitorna_clicked()
{
    sock->disconnectFromHost();
    MainWindow* mainw = new MainWindow();
    mainw->show();
    this->close();
}

void Chat::on_btnInvia_clicked() //@chatroom@ viene inviato in modo che ogni ricevente capisca se il messaggio è rivolto a lui.
{
  sock->write("@" + _chatroom.toLatin1() + "@" + _nome.toLatin1()+": "+ this->ui->txtMessage->text().toLatin1() + "\n");
  this->ui->txtMessage->clear();
}

void Chat::leggi()
{
    qint64 bytes = buffer->write(sock->readAll()); //Per leggere i messaggi dal server.
    buffer->seek(buffer->pos() - bytes);
    while (buffer->canReadLine())
            {
                    QString line = buffer->readLine();
                    QString chatroomName = "@" + _chatroom;
                    QString messaggioPerMe = line.mid(line.indexOf('@',0),line.indexOf('@',1));
                    if(chatroomName.compare(messaggioPerMe)==0)
                    {
                        line.remove(chatroomName + "@");
                        this->ui->txtChatRoom->appendPlainText(line);
                    }
            }
}

void Chat::on_btnAggiorna_clicked()
{
    leggi();
}
