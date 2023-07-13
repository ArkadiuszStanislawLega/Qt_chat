#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>

class Server : public QTcpServer
{
    Q_OBJECT
public:
    Server(QObject *parent = nullptr);
};

#endif // SERVER_H
