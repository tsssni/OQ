#include "oqserver.h"
#include "oqsocket.h"
#include <QPointer>

void OQServer::incomingConnection(qintptr socketDesc)
{
    OQSocket* socket=new OQSocket(this);
    socket->setSocketDescriptor(socketDesc);
    mSockets.push_back(socket);

    connect(socket, &OQSocket::handleMessage, this, &OQServer::handleMessage);
    connect(socket, &OQSocket::finishMessage, this, &OQServer::clearFinishedSockets);
}

OQServer *OQServer::getServer()
{
    if(!sServer)
    {
        sServer=new OQServer();
    }

    return sServer;
}

void OQServer::handleMessage(QMap<QString, QString> msg)
{
    if(msg["register"] == "true")
    {
        registerUser(msg["id"], msg["userName"],msg["password"]);
    }
    else if(msg["login"]=="true")
    {
        login(msg["id"], msg["password"]);
    }
    else if(msg["sendMessage"]=="true")
    {
        sendMessage(msg["senderId"],msg["receiverId"],msg["message"]);
    }
    else if(msg["receiveMessage"]=="true")
    {
        receiveMessage(msg["senderId"],msg["receiverId"]);
    }
}

void OQServer::clearFinishedSockets()
{
    while(!mSockets.empty() && mSockets.front()->finished())
    {
        mSockets.pop_front();
    }
}

OQServer::OQServer(QObject* parent)
    :QTcpServer(parent)
{
    listen(QHostAddress::Any, 8088);
}

void OQServer::registerUser(QStringView id, QStringView userName, QStringView password)
{

}

void OQServer::login(QStringView id, QStringView password)
{

}

void OQServer::sendMessage(QStringView senderId, QStringView receiverId, QStringView message)
{

}

void OQServer::receiveMessage(QString senderId, QStringView receiverId)
{

}

