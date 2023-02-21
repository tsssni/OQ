#ifndef OQCONNECTION_H
#define OQCONNECTION_H
#include <oqserver.h>
#include <QStringView>

class OQServer;

class OQNetwork : public QObject
{
    Q_OBJECT
public:
    static OQNetwork* getNetwork();
public slots:
    void handleMessage(QMap<QString, QString> msg);
private:
    bool registerUser(QStringView info);

    OQNetwork();

    static OQNetwork* sNetwork;
    OQServer* mServer;
};

#endif // OQCONNECTION_H
