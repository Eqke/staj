#include "server.h"

Server::Server()
{
    _server = new QTcpServer();
    _server->listen(QHostAddress::Any, 1440);
    auto a = _server->serverAddress().toString();
    auto b = _server->serverPort();
    auto c = 1;
}

Server::~Server()
{
    delete _server;
}

void Server::respondNewConnection()
{
    _clientConnection = _server->nextPendingConnection();
    connect(_clientConnection, SIGNAL(disconnected),
            _clientConnection, SLOT(deleteLatter));
    connect(_clientConnection, SIGNAL(readyRead()), this, SLOT(ReadyRead()));
}

void Server::ReadyRead()
{
    QByteArray total_data;
    total_data = _clientConnection->readAll();
    QString data(total_data);
    _data = data.toInt();
}

