#include "chatframe.h"
#include "oqnetwork.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ChatFrame c;

    OQNetworkThread* t_net=new OQNetworkThread();
    t_net->start();

    return a.exec();
}
