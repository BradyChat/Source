#include "mainwindow.h"
#include "nuovoutente.h"
#include "chat.h"
#include "ui_mainwindow.h"
#include <QtSql/QtSql>

QSqlDatabase db;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db =  QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./users.sqldb");
    if (!db.open()) {
                this->ui->lineEdit->setText("Errore apertura Database");
            }
}

MainWindow::~MainWindow()
{
    delete ui;
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

void MainWindow::on_btnAccedi_clicked()
{
    Chat* w;
    QSqlQuery s;
    s.prepare("SELECT Username FROM Utenti WHERE Username = '" + this->ui->lineEdit->text() + "' AND Password = '" + this->ui->lineEdit_2->text()+"'");
    s.exec();
    s.next();
    QString username = s.value(0).toString();
    this->ui->lineEdit_2->setText(username);
    if(username != "")
    {
        w = new Chat();
        w->nomeUtente(username);
        w->chatRoom(this->ui->txtChatRoom->text());
        w->show();
        this->close();
    }
    else
        this->ui->lineEdit->setText("Non esisti");
}

void MainWindow::on_btnIscriviti_clicked()
{
    nuovoUtente* w;
    w = new nuovoUtente();
    w->show();
    this->close();
}
