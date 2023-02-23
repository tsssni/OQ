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

void OQNetwork::disconnect()
{
    if(mSocket->state()==QAbstractSocket::SocketState::ConnectedState)
    {
        mSocket->disconnectFromHost();

        while(!mSocket->waitForDisconnected(500))
        {
            mSocket->disconnectFromHost();
        }
    }
}

OQ_REGISTER_STATE OQNetwork::registerUser(QStringView userName, QStringView password, QString& id)
{
    QMap<QString, QString> msg;

    msg["register"]="1";
    msg["userName"]=userName.toString();
    msg["password"]=password.toString();

    tryToConnect(&mRegisterSocket);
    auto state=communicate<OQ_REGISTER_STATE>(mRegisterSocket, msg);

    if(state==OQ_REGISTER_STATE_SUCCESS)
    {
        auto retMessage=mRegisterSocket->getData();
        id=retMessage["id"];
    }

    mRegisterSocket->disconnectFromHost();
    return state;
}

OQ_LOGIN_STATE OQNetwork::login(QStringView id, QStringView password)
{
    QMap<QString, QString> msg;

    msg["login"]="1";
    msg["id"]=id.toString();
    msg["password"]=password.toString();

    tryToConnect(&mSocket);
    auto state = communicate<OQ_LOGIN_STATE>(mSocket, msg);

    return state;
}

OQ_SEND_MESSAGE_STATE OQNetwork::sendMessage(QStringView senderId, QStringView receiverId, QStringView message)
{
    QMap<QString, QString> msg;

    msg["sendMessage"]="1";
    msg["senderId"]=senderId.toString();
    msg["receiverId"]=receiverId.toString();
    msg["message"]=message.toString();

    tryToConnect(&mSocket);
    auto state=communicate<OQ_SEND_MESSAGE_STATE>(mSocket, msg);

    return state;
}

OQ_RECEIVE_MESSAGE_STATE OQNetwork::receiveMessage(QStringView senderId, QStringView receiverId, QDateTime queryTime, QVector<QString>& messages, QVector<QDateTime> &times, QVector<bool> &directions)
{
    QMap<QString, QString> msg;

    msg["receiveMessage"]="1";
    msg["senderId"]=senderId.toString();
    msg["receiverId"]=receiverId.toString();
    msg["queryTime"]=queryTime.toString("yyyy-MM-dd hh:mm:ss");

    tryToConnect(&mSocket);
    auto state=communicate<OQ_RECEIVE_MESSAGE_STATE>(mSocket, msg);

    if(state==OQ_RECEIVE_MESSAGE_STATE_SUCCESS)
    {
        auto retMsg=mSocket->getData();
        int i=0;

        while(retMsg["message" + QString::number(i)].count())
        {
            QString num=QString::number(i);

            messages.append(retMsg["message"+num]);
            times.append(QDateTime::fromString(retMsg["time"+num], "yyyy-MM-dd hh:mm:ss"));
            directions.append(bool(retMsg["direction"+num].toInt()));

            ++i;
        }
    }

    return state;
}

OQ_GET_USERNAME_STATE OQNetwork::getUserName(QStringView id, QString &name)
{
    QMap<QString, QString> msg;

    msg["getUserName"]="1";
    msg["id"]=id.toString();

    tryToConnect(&mSocket);
    auto state=communicate<OQ_GET_USERNAME_STATE>(mSocket, msg);

    if(state==OQ_GET_USERNAME_STATE_SUCCESS)
    {
        name=mSocket->getData()["userName"];
    }

    return state;
}

OQ_SET_SETTINGS_STATE OQNetwork::setSettings(QStringView id, QStringView name, QStringView gender, QStringView age, QStringView address)
{
    QMap<QString, QString> msg;

    msg["setSettings"]="1";
    msg["id"]=id.toString();
    msg["name"]=name.toString();
    msg["gender"]=gender.toString();
    msg["age"]=age.toString();
    msg["address"]=address.toString();

    tryToConnect(&mSocket);
    auto state=communicate<OQ_SET_SETTINGS_STATE>(mSocket, msg);

    return state;
}

OQ_GET_SETTINGS_STATE OQNetwork::getSettings(QStringView id, QString &name, QString &gender, QString &age, QString &address)
{
    QMap<QString, QString> msg;

    msg["getSettings"]="1";
    msg["id"]=id.toString();

    tryToConnect(&mSocket);
    auto state=communicate<OQ_GET_SETTINGS_STATE>(mSocket, msg);

    if(state==OQ_GET_SETTINGS_STATE_SUCCESS)
    {
        auto retMsg=mSocket->getData();
        name=retMsg["name"];
        gender=retMsg["gender"];
        age=retMsg["age"];
        address=retMsg["address"];
    }

    return state;

}

void OQNetwork::handleMessage(QMap<QString, QString> msg, OQSocket *socket)
{
    if(msg.count("register")||
       msg.count("login")||
       msg.count("sendMessage")||
       msg.count("receiveMessage")||
       msg.count("getUserName")||
       msg.count("setSettings")||
       msg.count("getSettings"))
    {
        socket->setState(msg["state"].toInt());
    }

    if(msg.count("receiveMessage")||
       msg.count("getUserName")||
       msg.count("getSettings"))
    {
        socket->setData(std::move(msg));
    }
}

OQNetwork::OQNetwork()
{

}

void OQNetwork::tryToConnect(OQSocket** socketPtr)
{
    OQSocket* &socket=*socketPtr;

    if(!socket)
    {
        socket=new OQSocket(this);
        connect(socket, &OQSocket::handleMessage, this, &OQNetwork::handleMessage, Qt::DirectConnection);
    }

    if(socket->state()!=QAbstractSocket::ConnectedState)
    {
        socket->connectToHost("127.0.0.1", 8088);
    }

}

void OQNetworkThread::run()
{
    OQNetwork::getNetwork();
}
