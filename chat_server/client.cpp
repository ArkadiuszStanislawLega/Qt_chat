#include "client.h"

Client::Client(QObject *parent, qintptr handle)
    : QObject{parent}
{
    this->_handle = handle;
}

void Client::run()
{
    QTcpSocket* socket = QTcpSocket(nullptr);
    if(!socket->setSocketDescriptor(this->_handle)){
        qCritical() << socket->erroString();
        delete socket;
        return;
    }

    socket->waitForReadyRead();
    QByteArray request = socket->readAll();

    qInfo() << "Request length: " << request.size();

    QByteArray data("Hello World");
    QByteArray response;

    response.append("HTTP/1.1 200 OK\r\n");
    response.append("Content-Type: text/plain\r\n");
    response.append("Content-Length: " + QString::number(data.length()).toUtf8() + "\r\n");
    response.append("Connection: close\r\n");
    response.append("\r\n");
    response.append(data);

    socket->read(response);
    socket->waitForBytesWritten();
    socket->close();
    socket->deleteLater();
}
