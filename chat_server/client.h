#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QRunnable>

class Client : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = nullptr, qintptr handle = 0);
    virtual void run() Q_DECL_OVERRIDE;

signals:

private:
    qintptr _handle;


};

#endif // CLIENT_H
