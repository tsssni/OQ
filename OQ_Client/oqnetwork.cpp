#include "oqnetwork.h"
#include "oqsocket.h"
#include <QMap>
#include <QString>

OQNetwork* OQNetwork::sNetwork=nullptr;

OQNetwork *OQNetwork::getNetwork()
{
    if(!sNetwork)
    {
        sNetwork=new OQNetwork();
    }

    return sNetwork;
}

OQ_REGISTER_STATE OQNetwork::registerUser(QStringView id, QStringView userName, QStringView password)
{
    QMap<QString, QString> msg;

    msg["register"]="1";
    msg["id"]=id.toString();
    msg["userName"]=userName.toString();
    msg["password"]=password.toString();

    tryToConnect(mRegisterSocket);
    auto state=communicate(mRegisterSocket, msg, OQ_REGISTER_STATE_NETWORK_ERROR);

    mRegisterSocket->disconnectFromHost();
    return state;
}

OQ_LOGIN_STATE OQNetwork::login(QStringView id, QStringView password)
{
    QMap<QString, QString> msg;

    msg["register"]="1";
    msg["id"]=id.toString();
    msg["password"]=password.toString();

    tryToConnect(mSocket);
    auto state = communicate(mSocket, msg, OQ_LOGIN_STATE_NETWORK_ERROR);

    return state;
}

OQ_SEND_MESSAGE_STATE OQNetwork::sendMessage(QStringView senderId, QStringView receiverId, QStringView message)
{
    QMap<QString, QString> msg;

    msg["sendMessage"]="1";
    msg["senderId"]=senderId.toString();
    msg["receiverId"]=receiverId.toString();
    msg["message"]=message.toString();

    tryToConnect(mSocket);
    auto state=communicate(mSocket, msg, OQ_SEND_MESSAGE_STATE_NETWORK_ERROR);

    return state;
}

OQ_RECEIVE_MESSAGE_STATE OQNetwork::receiveMessage(QStringView senderId, QStringView receiverId, QDateTime queryTime, QVector<QDateTime> &time, QVector<QString> &message)
{
    QMap<QString, QString> msg;

    msg["sendMessage"]="1";
    msg["senderId"]=senderId.toString();
    msg["receiverId"]=receiverId.toString();
    msg["queryTime"]=queryTime.toString("yyyy-MM-dd hh:mm:ss");

    tryToConnect(mSocket);
    auto state=communicate(mSocket, msg, OQ_RECEIVE_MESSAGE_STATE_NETWORK_ERROR);

    auto messages=mSocket->getData();
    int i=0;

    while(msg["message" + QString::number(i)].count())
    {
        time.append(QDateTime::fromString(msg["time"+QString::number(i)], "yyyy-MM-dd hh:mm:ss"));
        message.append(msg["message"+QString::number(i)]);
    }

    return state;
}

void OQNetwork::handleMessage(QMap<QString, QString> msg, OQSocket *socket)
{
    if(msg["register"]=="1"||
       msg["login"]=="1"||
       msg["sendMessage"]=="1"||
       msg["receiveMessage"]=="1")
    {
        socket->setState(msg["state"].toInt());
    }

    if(msg["receiveMessage"]=="1")
    {
        socket->setData(std::move(msg["message"]));
    }
}

OQNetwork::OQNetwork()
{

}

void OQNetwork::tryToConnect(OQSocket* socket)
{
    if(socket->state()!=QAbstractSocket::ConnectedState)
    {
        socket=new OQSocket();
        connect(socket, &OQSocket::handleMessage, this, &OQNetwork::handleMessage, Qt::DirectConnection);
        socket->connectToHost("127.0.0.1", 8088);
    }

}
