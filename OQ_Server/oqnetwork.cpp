#include "oqnetwork.h"
#include "oqserver.h"
#include "oqsocket.h"
#include "mysqltest.h"

OQNetwork* OQNetwork::sNetwork=nullptr;

OQNetwork *OQNetwork::getNetwork()
{
    if(!sNetwork)
    {
        sNetwork=new OQNetwork();
    }
    
    return sNetwork;
}

void OQNetwork::handleMessage(QMap<QString, QString> msg, OQSocket* socket)
{
    QMap<QString, QString> retMsg;
    
    if(msg["register"] == "1")
    {
        registerUser(msg["id"], msg["userName"],msg["password"], retMsg);
    }
    else if(msg["login"]=="1")
    {
        login(msg["id"], msg["password"], retMsg);
    }
    else if(msg["sendMessage"]=="1")
    {
        sendMessage(msg["senderId"],msg["receiverId"],msg["message"], retMsg);
    }
    else if(msg["receiveMessage"]=="1")
    {
        receiveMessage(msg["senderId"],msg["receiverId"], retMsg);
    }
    
    socket->sendMessage(retMsg);
}

void OQNetwork::registerUser(QStringView id, QStringView userName, QStringView password, QMap<QString, QString>& msg)
{
    QString name;
    OQ_REGISTER_STATE state;

    if(!mMySqlTest->find(id, name, password))
    {
        mMySqlTest->add(id, userName, password);
        state=OQ_REGISTER_STATE_SUCCESS;
    }
    else
    {
        state=OQ_REGISTER_STATE_USER_EXIST;
    }

    msg["register"]="1";
    msg["state"]=QString::number(state);
}

void OQNetwork::login(QStringView id, QStringView password, QMap<QString, QString>& msg)
{
    QString name;
    OQ_LOGIN_STATE state;

    if(mMySqlTest->find(id, name, password))
    {
       state=OQ_LOGIN_STATE_SUCCESS;
    }
    else
    {
        state=OQ_LOGIN_STATE_PASSWORD_INVALID;
    }
    
    msg["login"]="1";
    msg["state"]=QString::number(state);
}

void OQNetwork::sendMessage(QStringView senderId, QStringView receiverId, QStringView message, QMap<QString, QString>& msg)
{
    msg["sendMessage"]="1";
    msg["state"]=QString::number(OQ_SEND_MESSAGE_STATE_SUCCESS);
}

void OQNetwork::receiveMessage(QString senderId, QStringView receiverId, QMap<QString, QString>& msg)
{
    msg["receiveMessage"]="1";
    msg["state"]=QString::number(OQ_RECEIVE_MESSAGE_STATE_SUCCESS);
}

OQNetwork::OQNetwork()
    :mServer(new OQServer(this)), mMySqlTest(new mysqltest(this))
{   
}


