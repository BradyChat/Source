#include "chat.h"
#include "ui_chat.h"
#include "mainwindow.h"
#include "Include/Client.hpp"


QString _nome;
QString _chatroom;
Client* _client;

Chat::Chat(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Chat)
{
    ui->setupUi(this);
    _client = new Client("127.0.0.1",9001,"0.0.0.0",9000);
    QObject* sender;
    connect(sender, SIGNAL(leggi()), this, SLOT(leggi()));
}

Chat::~Chat()
{
    delete ui;
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
    MainWindow* mainw = new MainWindow();
    mainw->show();
    this->close();
}

void Chat::on_btnInvia_clicked()
{
  QString msg;
  QByteArray ba;
  char* msgDaInviare;
  msg = this->ui->txtMessage->text();
  this->ui->txtChatRoom->appendPlainText(_nome + ": " + msg);
  ba = msg.toLatin1();
  msgDaInviare = ba.data();
  _client->Invia(msgDaInviare);
  this->ui->txtMessage->clear();
  this->ui->txtMessage->setFocus();
}

void Chat::leggi()
{
    while(_client->canReadLine())
    {
        QString msg = QString::fromUtf8(_client->Ricevi());
        this->ui->txtChatRoom->appendPlainText(msg);
    }
}
