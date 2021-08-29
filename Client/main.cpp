#include <QCoreApplication>
#include "data.h"
#include <QFile>
#include <QThread>
#include "clientmanager.h"
#include <QObject>
#include <QDir>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    std::string enteringData;
    Data* data = new Data();
    QThread* thread = new QThread();
    ClientManager* clientMngr = new ClientManager();
    clientMngr->moveToThread(thread);
    QFile bufferFile(QDir::currentPath() + "/buffer.txt");
    QObject::connect(data, SIGNAL(isWritted()), clientMngr, SLOT(run()), Qt::QueuedConnection);
    QObject::connect(clientMngr, SIGNAL(end()), thread, SLOT(terminate()), Qt::QueuedConnection);
    while(true)
    {
        std::cout << "Please, enter data or ESC for exit" << std::endl;
        std::getline(std::cin, enteringData);
        if (enteringData == "ESC" || enteringData == "esc") break;
        data->SetData(enteringData);
        data->Sort();
        if(bufferFile.open(QIODevice::Append))
        {
            QTextStream out(&bufferFile);
            out << data->GetData().c_str();
            bufferFile.close();
            thread->start();
            data->EmitSignalAboutWritten();
        }
    }
    delete data;
    delete thread;
    delete clientMngr;
}
