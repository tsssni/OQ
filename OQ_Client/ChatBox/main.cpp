#include "chatbox.h"

#include <QApplication>
#include<windows.h>

int main(int argc, char *argv[])
{
    qreal  cx = GetSystemMetrics(SM_CXSCREEN);
        qreal scale = cx / 1920;				// 960 = 1920 / 2
        qputenv("QT_SCALE_FACTOR", QString::number(scale).toLatin1());
    QApplication a(argc, argv);
    ChatBox w;
    w.show();
    return a.exec();
}
