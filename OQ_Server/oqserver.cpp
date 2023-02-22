#include "oqserver.h"
#include "oqsocket.h"
#include "oqnetwork.h"
#include "oqmysqltest.h"
#include <QTimer>

OQServer::OQServer(QObject* parent)
    :QTcpServer(parent)
{
    listen(QHostAddress::Any, 8088);

    QTimer *timer=new QTimer(this);
    connect(timer, &QTimer::timeout, this, &OQServer::clearOfflineSockets);
    timer->start(1000);
}


void OQServer::incomingConnection(qintptr socketDesc)
{
    OQSocketThread* socketThread=new OQSocketThread(socketDesc, this);
    mSockets.push_back(socketThread);
    socketThread->start();
}

void OQServer::clearOfflineSockets()
{
    for(auto itr = mSockets.begin(); !mSockets.empty() && itr!=mSockets.end();++itr)
    {
        if(!(*itr) || (*itr)->getSocket()->state()==QAbstractSocket::SocketState::UnconnectedState)
        {
            mSockets.erase(itr);
        }
    }
}



