#include <QCoreApplication>
#include "server.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Server* server = new Server();

    delete server;

}
