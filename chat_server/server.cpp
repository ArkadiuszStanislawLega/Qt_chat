#include "server.h"
#define MAX_USERS_CONNECTED 200

Server::Server(QObject *parent) : QTcpServer(parent)
{
    this->_pool.setMaxThreadCount(MAX_USERS_CONNECTED);
    qInfo() << "Max number of users: " << MAX_USERS_CONNECTED;
}

void Server::start(qint16 port)
{
    if(this->listen(QHostAddress::Any, port)){
        qInfo() << "Server started on port: " << port;
    } else {
        qWarning() << this->errorString();
    }
}

void Server::quit()
{
    this->close();
    qInfo() << "Server stopped.";
}

void Server::incomingConnection(qintptr handle)
{
    qInfo() << "Incoming Connection " << handle << " " << QThread::currentThread();
    //TODO: finish this whan client class created.

}
