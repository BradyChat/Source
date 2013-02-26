#include "chat.h"
#include "ui_chat.h"
#include "mainwindow.h"

Chat::Chat(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Chat)
{
    ui->setupUi(this);
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

void Chat::on_btnRitorna_clicked()
{
    MainWindow* mainw = new MainWindow();
    mainw->show();
    this->close();
}
