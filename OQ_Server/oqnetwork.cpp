#include "oqnetwork.h"
#include "oqserver.h"
#include "oqsocket.h"
#include "mysqltest.h"

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
    
    if(msg["register"] == "true")
    {
        registerUser(msg["id"], msg["userName"],msg["password"], retMsg);
    }
    else if(msg["login"]=="true")
    {
        login(msg["id"], msg["password"], retMsg);
    }
    else if(msg["sendMessage"]=="true")
    {
        sendMessage(msg["senderId"],msg["receiverId"],msg["message"], retMsg);
    }
    else if(msg["receiveMessage"]=="true")
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
    
    msg["state"]=state;

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
    
    msg["state"]=state;
}

void OQNetwork::sendMessage(QStringView senderId, QStringView receiverId, QStringView message, QMap<QString, QString>& msg)
{

}

void OQNetwork::receiveMessage(QString senderId, QStringView receiverId, QMap<QString, QString>& msg)
{
    
}

OQNetwork::OQNetwork()
	:mServer(new OQServer(this)), mMySqlTest(std::make_unique<mysqltest>())
{   
}


