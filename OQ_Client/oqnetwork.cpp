#include "oqnetwork.h"
/*OQNetwork *OQNetwork::getNetwork()
{
    if(!sNetwork)
    {
        sNetwork=new OQNetwork();
    }

    return sNetwork;
}
*/
OQ_REGISTER_STATE OQNetwork::registerUser(QStringView id, QStringView userName, QStringView password)
{
    return OQ_REGISTER_STATE_SUCCESS;
}

OQ_LOGIN_STATE OQNetwork::login(QStringView id, QStringView password)
{
    return OQ_LOGIN_STATE_SUCCESS;
}

OQ_SEND_MESSAGE_STATE OQNetwork::sendMessage(QStringView senderId, QStringView receiverId, QStringView message)
{
    return OQ_SEND_MESSAGE_STATE_SUCCESS;
}

OQ_SEND_MESSAGE_STATE OQNetwork::sendMessage(QStringView senderId, QStringView receiverId, const QVector<QString> &message)
{
    return OQ_SEND_MESSAGE_STATE_SUCCESS;
}

OQ_RECEIVE_MESSAGE_STATE OQNetwork::receiveMessage(QStringView senderId, QStringView receiverId, QVector<QString> &message)
{
    return OQ_RECEIVE_MESSAGE_STATE_SUCCESS;
}
