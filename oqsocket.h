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

    void setState(int state);
    void setData(QMap<QString, QString>&& data);
    int getState();
    const QMap<QString, QString>& getData();

signals:
    void handleMessage(QMap<QString, QString> msg, OQSocket*);
private slots:
    void receiveMessage();
private:
    quint16 mBufSize = 0;
    int mState;
    QMap<QString, QString> mData;
};

#endif // OQSOCKET_H
