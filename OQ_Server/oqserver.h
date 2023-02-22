#ifndef OQSERVER_H
#define OQSERVER_H
#include <QTcpServer>
#include <QPointer>
#include <QVector>
#include <memory>

class OQSocketThread;
class OQMySqlTest;

class OQServer : public QTcpServer
{
    Q_OBJECT
public:
    OQServer(QObject* parent = nullptr);
    virtual void incomingConnection(qintptr socketDesc)override;
public slots:
    void clearOfflineSockets();
private:
    QVector<OQSocketThread*> mSockets;
};

#endif // OQSERVER_H
