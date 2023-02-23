#include "chatframe.h"
#include "oqnetwork.h"
#include <QApplication>
#include<windows.h>
int main(int argc, char *argv[])
{
    srand((quint64)new char);

    QApplication a(argc, argv);
    ChatFrame c;
    OQNetworkThread* t_net=new OQNetworkThread();
    t_net->start();
    return a.exec();
}
