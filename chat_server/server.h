#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QThreadPool>
#include <QDebug>

class Server : public QTcpServer
{
    Q_OBJECT
public:
    Server(QObject *parent = nullptr);

public slots:
    void start(qint16 port);
    void quit();

private:
    QThreadPool _pool;

    // QTcpServer interface
protected:
    virtual void incomingConnection(qintptr handle) Q_DECL_OVERRIDE;
};

#endif // SERVER_H
