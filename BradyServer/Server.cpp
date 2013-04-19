#include <QBuffer>
#include <QTcpSocket>
#include "Server.h"
#include <QtSql/QtSql>

QSqlDatabase db;

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
                if(line.startsWith('#')) //Richiesta di autenticazione.
                {
                    db =  QSqlDatabase::addDatabase("QSQLITE");
                    db.setDatabaseName("./users.sqldb");
                    if (!db.open()) {
                        socket->write("#false");
                                   }
                    QSqlQuery s;
                    QString nome;
                    QString password;
                    QList<QByteArray> nomepassword;

                    nomepassword = line.split('/');
                    nome = nomepassword[1];
                    password = nomepassword[2];
                    password = password.remove("\n");

                    s.prepare("SELECT Username FROM Utenti WHERE Username = '" + nome + "' AND Password = '" + password +"'");
                    s.exec();
                    s.next();
                    QString username = s.value(0).toString();
                            if(username != "")
                            {
                                socket->write("#true\n");
                            }
                            else
                            {
                                socket->write("#false\n");
                            }
                    db.close();
                }
                else if(line.startsWith('!')) //Richiesta di iscrizione.
                {

                    QString nome;
                    QString password;
                    QList<QByteArray> nomepassword = line.split('/');

                    db =  QSqlDatabase::addDatabase("QSQLITE");
                    db.setDatabaseName("./users.sqldb");
                    db.open();
                     QSqlQuery s;

                    nome = nomepassword[1];
                    password = nomepassword[2];
                    password = password.remove("\n");

                    s.prepare("INSERT INTO Utenti VALUES ('" + nome + "', '" + password + "')");
                    s.exec();
                    db.close();
                }
                else
                foreach (QTcpSocket* connection, connections)
                {
                     connection->write(line); //Invio il testo ricevuto a un'altra connessione.
                }
        }
}
