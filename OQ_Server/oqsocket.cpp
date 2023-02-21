#include "oqsocket.h"
#include <QDataStream>
#include <QByteArray>
#include <QThread>

OQSocket::OQSocket(QObject* parent)
    :QTcpSocket(parent)
{
    connect(this, &OQSocket::readyRead, this, &OQSocket::receiveMessage);
}

void OQSocket::sendMessage(const QMap<QString, QString>& msg)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_12);

    out<<(quint16)0;
    for(const QString& key : msg.keys())
    {
        QString tempMsg=key+":"+msg[key];
        out<<tempMsg;
    }

    write(block);
}

void OQSocket::receiveMessage()
{
    QDataStream in(this);
    in.setVersion(QDataStream::Qt_5_12);

    // test whether the data size is accessible
    if(mBufSize==0)
    {
        if(bytesAvailable()<(qint64)sizeof(quint16))
        {
            return;
        }

        in>>mBufSize;
    }

    // test whether all the data has been received
    quint16 initBytes=bytesAvailable();
    if(initBytes<mBufSize)
    {
        return;
    }

    // read json message
    QMap<QString, QString> msg;
    quint16 msgSize=0;

    while(msgSize<mBufSize)
    {
        QString tempMsg;
        in>>tempMsg;

        int splitorIdx=tempMsg.indexOf(":");
        QString key=tempMsg.mid(0, splitorIdx);
        QString value=tempMsg.mid(splitorIdx+1,tempMsg.length()-splitorIdx-1);
        msg[key]=value;

        msgSize=initBytes-bytesAvailable();
    }

    emit(handleMessage(msg, this));

    mBufSize=0;

    if(bytesAvailable()>0)
    {
        receiveMessage();
    }
}
