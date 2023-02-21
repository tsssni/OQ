#ifndef OQSOCKET_H
#define OQSOCKET_H
#include <QTcpSocket>
#include <QMap>
#include <QString>
#include <QThread>

class OQSocket : public QTcpSocket
{
    Q_OBJECT
public:
    OQSocket(QObject* parent = nullptr);
    void sendMessage(const QMap<QString, QString>& msg);
signals:
    void handleMessage(QMap<QString, QString> msg);
private slots:
    void receiveMessage();
private:
    quint16 mBufSize;
};

#endif // OQSOCKET_H
