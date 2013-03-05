#include "mainwindow.h"
#include "nuovoutente.h"
#include "chat.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
    w = new Chat();
    w->show();
    this->close();
}

void MainWindow::on_btnIscriviti_clicked()
{
    nuovoUtente* w;
    w = new nuovoUtente();
    w->show();
    this->close();
}
