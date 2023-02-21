#ifndef OQSERVER_H
#define OQSERVER_H
#include <QTcpServer>
#include <QPointer>
#include <QVector>
#include <QList>

class OQSocket;

class OQServer : public QTcpServer
{
    Q_OBJECT
public:
    OQServer(QObject* parent = nullptr);
    virtual void incomingConnection(qintptr socketDesc)override;
private:

    QList<OQSocket*> mSockets;
};

#endif // OQSERVER_H
