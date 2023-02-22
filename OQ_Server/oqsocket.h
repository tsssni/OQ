#ifndef OQSOCKET_H
#define OQSOCKET_H
#include <QTcpSocket>
#include <QMap>
#include <QString>
#include <QThread>

class OQSocket;

class OQSocketThread : public QThread
{
public:
    OQSocketThread(qintptr socketDesc, QObject* parent = nullptr);
    OQSocket *getSocket();
    void run() override;
private:
    OQSocket* mSocket;
};

class OQSocket : public QTcpSocket
{
    Q_OBJECT
public:
    OQSocket(QObject* parent = nullptr);
    void sendMessage(const QMap<QString, QString>& msg);
signals:
    void handleMessage(QMap<QString, QString> msg, OQSocket*);
private slots:
    void receiveMessage();
private:
    quint16 mBufSize = 0;
};

#endif // OQSOCKET_H
