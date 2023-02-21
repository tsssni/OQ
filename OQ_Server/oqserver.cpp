#include "oqserver.h"
#include "oqsocket.h"
#include "oqnetwork.h"
#include "mysqltest.h"
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
    OQSocket* socket=new OQSocket(this);
    socket->setSocketDescriptor(socketDesc);
    mSockets.push_back(socket);

    connect(socket, &OQSocket::handleMessage, OQNetwork::getNetwork(), &OQNetwork::handleMessage);
}

void OQServer::clearOfflineSockets()
{
    for(auto itr = mSockets.begin(); itr!=mSockets.end();++itr)
    {
        if((*itr)->state()==QAbstractSocket::SocketState::UnconnectedState)
        {
            mSockets.erase(itr);
        }
    }
}



