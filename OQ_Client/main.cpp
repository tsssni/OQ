#include "chatframe.h"
#include "oqnetwork.h"
#include <QApplication>
#include<windows.h>
int main(int argc, char *argv[])
{
    srand((unsigned int)new char);
    //qreal  cx = GetSystemMetrics(SM_CXSCREEN);
    //qreal scale = cx / 1920;				// 自动缩放
   // qputenv("QT_SCALE_FACTOR", QString::number(scale).toLatin1());
    QApplication a(argc, argv);
    ChatFrame c;
   // OQNetworkThread* t_net=new OQNetworkThread();
   // t_net->start();
    return a.exec();
}
