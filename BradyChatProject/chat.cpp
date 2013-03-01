#include "chat.h"
#include "ui_chat.h"
#include "mainwindow.h"
#include <qtcpsocket.h>

QString _nome;
QString _chatroom;
QTcpSocket* _socket;

Chat::Chat(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Chat)
{
    ui->setupUi(this);
    _socket = new QTcpSocket(this);
    connect(_socket, SIGNAL(leggi()), this, SLOT(leggi()));
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
  msg = this->ui->txtMessage->text();
  this->ui->txtChatRoom->appendPlainText(_nome + ": " + msg);
  _socket->write(QString(_nome + ": " + msg + "\n").trimmed().toUtf8());
  this->ui->txtMessage->clear();
  this->ui->txtMessage->setFocus();
  //InviaMessaggio(chatroom, _nome + ": " + msg);
}

void Chat::leggi()
{
    while(_socket->canReadLine())
    {
        QString msg = QString::fromUtf8(_socket->readLine()).trimmed();
        this->ui->txtChatRoom->appendPlainText(msg);
    }
}
