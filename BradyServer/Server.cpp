#include <QBuffer>
#include <QTcpSocket>
#include "Server.h"

Server::Server(QObject* parent) : QTcpServer(parent)
{
     connect(this, SIGNAL(newConnection()), this, SLOT(aggiungiNuovaConnessione()));
}

Server::~Server()
{
}

void Server::aggiungiNuovaConnessione()
{
        QTcpSocket* connection;
        QBuffer* buffer;

        connection = nextPendingConnection(); //Aggiungo la nuova connessione con il client.
        connections.append(connection); //Aggiungo questa connessione alla lista delle connessioni.

        buffer = new QBuffer(this);
        buffer->open(QIODevice::ReadWrite);
        buffers.insert(connection, buffer);

        connect(connection, SIGNAL(disconnected()), SLOT(rimuoviConnessione()));
        connect(connection, SIGNAL(readyRead()), SLOT(riceviMessaggio()));
}

void Server::rimuoviConnessione()
{
        QTcpSocket* socket;
        QBuffer* buffer;

        socket = (QTcpSocket*)(sender());
        buffer = buffers.take(socket);

        buffer->close();
        buffer->deleteLater();

        connections.removeAll(socket);
        socket->deleteLater();
}

void Server::riceviMessaggio()
{
        QTcpSocket* socket;
        QBuffer* buffer;
        QByteArray line;

        socket = (QTcpSocket*)(sender());
        buffer = buffers.value(socket);

        qint64 bytes = buffer->write(socket->readAll()); //Per la ricezione del messaggio.
        buffer->seek(buffer->pos() - bytes);

        while (buffer->canReadLine()) //Leggo fino a quando sono presenti linee di testo.
        {
                line = buffer->readLine();
                foreach (QTcpSocket* connection, connections)
                {
                        connection->write(line); //Invio il testo ricevuto a un'altra connessione.
                }
        }
}
