#ifndef OQNETWORK_H
#define OQNETWORK_H
#include "oqsocket.h"
#include <QObject>
#include <QString>
#include <QStringView>
#include <QMap>
#include <QDateTime>
#include <QThread>

class OQSocket;

enum OQ_REGISTER_STATE
{
    OQ_REGISTER_STATE_SUCCESS = 0,
    OQ_REGISTER_STATE_USER_EXIST,
    OQ_REGISTER_STATE_NETWORK_ERROR = 0xfff0,
    OQ_REGISTER_STATE_UNKNOWN_ERROR = 0xfff1
};

enum OQ_LOGIN_STATE
{
    OQ_LOGIN_STATE_SUCCESS = 0,
    OQ_LOGIN_STATE_USER_ID_INVALID,
    OQ_LOGIN_STATE_PASSWORD_INVALID,
    OQ_LOGIN_STATE_NETWORK_ERROR = 0xfff0,
    OQ_LOGIN_STATE_UNKNOWN_ERROR = 0xfff1
};

enum OQ_SEND_MESSAGE_STATE
{
    OQ_SEND_MESSAGE_STATE_SUCCESS = 0,
    OQ_SEND_MESSAGE_STATE_USER_ID_INVALID,
    OQ_SEND_MESSAGE_STATE_EMPTY_MESSAGE,
    OQ_SEND_MESSAGE_STATE_NETWORK_ERROR = 0xfff0,
    OQ_SEND_MESSAGE_STATE_UNKNOWN_ERROR = 0xfff1
};

enum OQ_RECEIVE_MESSAGE_STATE
{
    OQ_RECEIVE_MESSAGE_STATE_SUCCESS = 0,
    OQ_RECEIVE_MESSAGE_STATE_USER_ID_INVALID,
    OQ_RECEIVE_MESSAGE_STATE_NO_NEW_MESSAGE,
    OQ_RECEIVE_MESSAGE_STATE_NETWORK_ERROR = 0xfff0,
    OQ_RECEIVE_MESSAGE_STATE_UNKNOWN_ERROR = 0xfff1
};

enum OQ_GET_USERNAME_STATE
{
    OQ_GET_USERNAME_STATE_SUCCESS = 0,
    OQ_GET_USERNAME_STATE_USER_ID_INVALID,
    OQ_GET_USERNAME_STATE_NETWORK_ERROR = 0xfff0,
    OQ_GET_USERNAME_STATE_UNKNOWN_ERROR = 0xfff1,
};

class OQNetwork;

class OQNetworkThread : public QThread
{
public:
    void run() override;
};

class OQNetwork : public QObject
{
    Q_OBJECT
public:
    static OQNetwork *getNetwork();
    void disconnect();

    OQ_REGISTER_STATE registerUser(QStringView id, QStringView userName, QStringView password);
    OQ_LOGIN_STATE login(QStringView id, QStringView password);
    OQ_SEND_MESSAGE_STATE sendMessage(QStringView senderId, QStringView receiverId, QStringView message);
    // get message after the time specified
    OQ_RECEIVE_MESSAGE_STATE receiveMessage(QStringView senderId, QStringView receiverId, QDateTime queryTime, QVector<QDateTime> &time, QVector<QString>& message);
    OQ_GET_USERNAME_STATE getUserName(QStringView id, QString& name);


public slots:
    void handleMessage(QMap<QString, QString> msg, OQSocket* socket);
private:
    OQNetwork();
    void tryToConnect(OQSocket** socketPtr);

    template<typename T>
    T communicate(OQSocket* socket, const QMap<QString, QString>& msg)
    {
        T networkError=T(0xfff0);
        T unknownError=T(0xfff1);

        if(!socket->waitForConnected(2000))
        {
            return networkError;
        }

        socket->sendMessage(msg);
        if(!socket->waitForBytesWritten(2000))
        {
            return networkError;
        }

        if(!socket->waitForReadyRead(2000))
        {
            return networkError;
        }
        else if(socket->getState() != -1)
        {
            return T(socket->getState());
        }

        return unknownError;
    }

    static OQNetwork* sNetwork;
    OQSocket* mSocket = nullptr;
    OQSocket* mRegisterSocket = nullptr;
};

#endif // OQNETWORK_H
