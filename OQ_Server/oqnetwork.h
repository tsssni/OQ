#ifndef OQNETWORK_H
#define OQNETWORK_H

#include <QObject>
#include <QMap>
#include <QString>
#include <QStringView>

class OQSocket;
class OQServer;
class OQMySqlTest;

enum OQ_REGISTER_STATE
{
    OQ_REGISTER_STATE_SUCCESS = 0,
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

class OQNetwork : public QObject
{
    Q_OBJECT
public:
    static OQNetwork* getNetwork();
public slots:
    void handleMessage(QMap<QString, QString> msg, OQSocket* socket);
public:
    void registerUser(QStringView userName, QStringView password, QMap<QString, QString>& msg);
    void login(QStringView id, QStringView password, QMap<QString, QString>& msg);
    void sendMessage(QStringView senderId, QStringView receiverId, QStringView message, QMap<QString, QString>& msg);
    void receiveMessage(QStringView senderId, QStringView receiverId, QDateTime queryTime, QMap<QString, QString>& msg);
    void getUserName(QStringView id, QMap<QString, QString>& msg);
private:
    OQNetwork();
	static OQNetwork* sNetwork;
    OQServer* mServer;
    OQMySqlTest* mMySqlTest;
};

#endif // OQNETWORK_H
