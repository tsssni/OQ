#include "mythread.h"
#include<QTimer>
#include"oqnetwork.h"
#include<chatbox.h>
#include<iostream>
MyThread::MyThread(ChatBox *a)
{
    chatbox = a;
}

void MyThread::run(){
    QTimer *timer = new QTimer;
    while(1){
        timer->start(1000);
        connect(timer,SIGNAL(timeout()),this,SLOT(handel()));
    }
}


void MyThread::handle(){
    QVector<QString> message;
    QVector<QDateTime> time;
    QVector<bool> direction;
    OQ_RECEIVE_MESSAGE_STATE RMS = OQ_RECEIVE_MESSAGE_STATE_SUCCESS;
    QString receiverId;//从张振武那来 还没给接口
    QString userId = ChatBox::getuserId();
    RMS = OQNetwork::getNetwork()->receiveMessage(userId,receiverId,QDateTime::currentDateTime().addMSecs(-1),message,time,direction);
    switch(RMS){
    case OQ_RECEIVE_MESSAGE_STATE_NETWORK_ERROR : std::cout<<"networkerror"<<std::endl;break;
    case OQ_RECEIVE_MESSAGE_STATE_NO_NEW_MESSAGE : ;break;
    case OQ_RECEIVE_MESSAGE_STATE_USER_ID_INVALID : std::cout<<"userIdInvalid"<<std::endl;break;
    case OQ_RECEIVE_MESSAGE_STATE_UNKNOWN_ERROR : std::cout<<"Unknownerror"<<std::endl;break;
    default:{
        for(int i = 0;i<message.size();++i){
            QDateTime timetemp = time[i];
            QString mestemp = message[i];
            bool dirtemp = direction[i];
            connect(this,SIGNAL(done()),chatbox,SLOT(chatbox->readMessage(timetemp,mestemp,dirtemp)));
            emit(done());
        }
    }
    }
}
