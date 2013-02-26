#ifndef NUOVOUTENTE_H
#define NUOVOUTENTE_H

#include <QMainWindow>

namespace Ui {
    class nuovoUtente;
}

class nuovoUtente : public QMainWindow {
    Q_OBJECT
public:
    nuovoUtente(QWidget *parent = 0);
    ~nuovoUtente();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::nuovoUtente *ui;

private slots:
    void on_btnIscriviti_clicked();
    void on_btnRitorna_clicked();
};

#endif // NUOVOUTENTE_H
