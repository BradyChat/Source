#include "nuovoutente.h"
#include "ui_nuovoutente.h"
#include "mainwindow.h"

nuovoUtente::nuovoUtente(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::nuovoUtente)
{
    ui->setupUi(this);
}

nuovoUtente::~nuovoUtente()
{
    delete ui;
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
    MainWindow* mainw;
    mainw = new MainWindow();
    mainw->show();
    this->close();
}

void nuovoUtente::on_btnIscriviti_clicked()
{
    MainWindow* mainw;
    mainw = new MainWindow();
    mainw->show();
    this->close();
}
