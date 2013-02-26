#ifndef CHAT_H
#define CHAT_H

#include <QMainWindow>

namespace Ui {
    class Chat;
}

class Chat : public QMainWindow {
    Q_OBJECT
public:
    Chat(QWidget *parent = 0);
    ~Chat();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::Chat *ui;

private slots:
    void on_btnRitorna_clicked();
};

#endif // CHAT_H
