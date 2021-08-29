#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class Server : public QObject
{
    Q_OBJECT
private:
    QTcpServer* _server;

    QTcpSocket* _clientConnection;

    int _data;

private slots:
    void respondNewConnection();

    void ReadyRead();

public:
    Server();

    ~Server();
};

#endif // SERVER_H
