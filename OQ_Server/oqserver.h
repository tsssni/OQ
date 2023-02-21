#ifndef OQSERVER_H
#define OQSERVER_H
#include <QTcpServer>
#include <QPointer>
#include <QVector>
#include <QQueue>

class OQSocket;

class OQServer : public QTcpServer
{
    Q_OBJECT
public:
    static OQServer* getServer();
    virtual void incomingConnection(qintptr socketDesc)override;
public slots:
    void handleMessage(QMap<QString, QString> msg);
    void clearFinishedSockets();
private:
    OQServer(QObject* parent=nullptr);

    void registerUser(QStringView id, QStringView userName, QStringView password);
    void login(QStringView id, QStringView password);
    void sendMessage(QStringView senderId, QStringView receiverId, QStringView message);
    void receiveMessage(QString senderId, QStringView receiverId);

    static OQServer* sServer;
    QQueue<OQSocket*> mSockets;
};

#endif // OQSERVER_H
