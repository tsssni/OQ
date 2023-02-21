#include "oqnetwork.h"
#include "oqserver.h"

OQNetwork *OQNetwork::getNetwork()
{
    if(!sNetwork)
    {
        sNetwork=new OQNetwork();
    }

    return sNetwork;
}

void OQNetwork::handleMessage(QMap<QString, QString> msg)
{

}

OQNetwork::OQNetwork()
{
    mServer=new OQServer(this);
}
