#ifndef MYTHREAD_H
#define MYTHREAD_H
#include<QThread>
#include"chatbox.h"

class MyThread
        :QThread
{
public:
    MyThread(ChatBox* a);
    void run();
    static ChatBox* chatbox;
public slots:
    void handle();
signals:
    void done();
};

#endif // MYTHREAD_H
