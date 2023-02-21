#include <QCoreApplication>
#include "oqnetwork.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    OQNetwork::getNetwork();
    
    while (true) {
        
    }
    
    return a.exec();
}
