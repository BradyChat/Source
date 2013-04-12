#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QList>
#include <QHash>

class QBuffer;
class QTcpSocket;

class Server : public QTcpServer
{
        Q_OBJECT

public:
        Server(QObject* parent = 0);
        ~Server();

private slots:
        void aggiungiNuovaConnessione();
        void rimuoviConnessione();
        void riceviMessaggio();

private:
        QList<QTcpSocket*> connections;
        QHash<QTcpSocket*, QBuffer*> buffers;
};

#endif // SERVER_H
