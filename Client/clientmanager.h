#ifndef CLIENTMANAGER_H
#define CLIENTMANAGER_H

#include <QObject>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <iostream>
#include <QTcpSocket>

class ClientManager : public QObject
{
    Q_OBJECT

private:
    std::string _dataFromBuffer;

    QTcpSocket* _socket = nullptr;

signals:

    void end();

public:
    int Sum(std::string data);

    void SendData(int result);

    ClientManager();

    ~ClientManager();

public slots:

    void run();

    std::string GetDataFromBuffer();
};

#endif // CLIENTMANAGER_H
