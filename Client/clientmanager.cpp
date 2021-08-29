#include "clientmanager.h"


ClientManager::ClientManager()
{
    _socket = new QTcpSocket(this);
    _socket->connectToHost("localhost", 1440);
}

ClientManager::~ClientManager()
{
    _socket->close();
    delete _socket;
}

void ClientManager::run()
{
    _dataFromBuffer = GetDataFromBuffer();
    int result = Sum(_dataFromBuffer);
    //std::cout << "result equal " << result << std::endl;
    SendData(result);
    emit end();
}

std::string ClientManager::GetDataFromBuffer()
{
    QFile bufferFile(QDir::currentPath() + "/buffer.txt");
    QTextStream in (&bufferFile);
    bufferFile.open(QIODevice::ReadOnly);
    auto data = in.readLine().toStdString();
    bufferFile.remove();
    bufferFile.close();
    return data;
}

int ClientManager::Sum(std::string data)
{
    int sum = 0;
    for (auto i = 0; i < _dataFromBuffer.size(); i++)
    {
        if (_dataFromBuffer[i] >= '0' && _dataFromBuffer[i] <= '9')
        {
            sum += _dataFromBuffer[i] - '0';
        }
    }
    return sum;
}

void ClientManager::SendData(int result)
{
    if (_socket->state() == QAbstractSocket::ConnectedState)
    {
        _socket->write(QString::number(result).toLocal8Bit());
    }
}
