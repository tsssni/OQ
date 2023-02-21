#include "oqserver.h"
#include "oqsocket.h"
#include "oqnetwork.h"
#include <QPointer>

OQServer::OQServer(QObject* parent)
    :QTcpServer(parent)
{
    listen(QHostAddress::Any, 8088);
}

void OQServer::incomingConnection(qintptr socketDesc)
{
       OQSocket* socket=new OQSocket(this);
       socket->setSocketDescriptor(socketDesc);
       mSockets.append(socket);

       OQNetwork* network=dynamic_cast<OQNetwork*>(parent());
       if(network)
       {
           connect(socket, &OQSocket::handleMessage, network, &OQNetwork::handleMessage);
       }
}

