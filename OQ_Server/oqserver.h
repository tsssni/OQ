#ifndef OQSERVER_H
#define OQSERVER_H
#include <QTcpServer>
#include <QPointer>
#include <QVector>
#include <QQueue>
#include <memory>

class OQSocket;
class mysqltest;

class OQServer : public QTcpServer
{
    Q_OBJECT
public:
    OQServer(QObject* parent = nullptr);
    virtual void incomingConnection(qintptr socketDesc)override;
public slots:
    void clearOfflineSockets();
private:
    QQueue<OQSocket*> mSockets;
};

#endif // OQSERVER_H
