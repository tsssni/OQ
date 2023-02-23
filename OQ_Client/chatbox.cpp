#include "chatbox.h"
#include "ui_chatbox.h"
#include"settings.h"
#include"user.h"
#include"addfriend.h"
#include <QGuiApplication>
#include <QWidget>
#include <QScreen>
#include <windows.h>
#include<QtNetwork>
#include"oqnetwork.h"
#include<QTimer>
#include<iostream>

QString ChatBox::userId="";

ChatBox::ChatBox(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ChatBox)
{
    ui->setupUi(this);
    connect(ui->send,SIGNAL(clicked()),this,SLOT(sendMessage()));
    QTimer *timer = new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(readMessage()));
    timer->start(1000);
    InitUI();

}

ChatBox::~ChatBox()
{
    delete ui;
}


void ChatBox::InitUI()
{
    this->setWindowTitle("QQ");//设置窗口名
}



void ChatBox::on_add_clicked()
{
    AddFriend *a;
    a = new AddFriend(ui->FriendList);
    a->show();
}


void ChatBox::on_user_clicked()
{
    user *u;
    u = new user;
    u->show();
}


void ChatBox::on_settings_clicked()
{
    Settings *s;
    s = new Settings;
    s->show();
}

void ChatBox::readMessage(){//收消息
    QVector<QString> message;
    QVector<QDateTime> time;
    QVector<bool> direction;
    OQ_RECEIVE_MESSAGE_STATE RMS = OQ_RECEIVE_MESSAGE_STATE_SUCCESS;
    QString receiverId=getReceiverID();
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
            ui->textBrowser->append(timetemp.toString());
            if(dirtemp)ui->textBrowser->append(" 我： ");
            else ui->textBrowser->append(" 来自 "+receiverId+":"+"\n");
            ui->textBrowser->append(mestemp);
        }
    }
    }
}

void ChatBox::sendMessage(){
    QString text;
    QString senderId , receiverId;
    //senderid
    receiverId=getReceiverID();
    text=ui->textEdit->toPlainText();//读取输入框中的内容
    ui->textEdit->clear();
    OQ_SEND_MESSAGE_STATE FB=OQ_SEND_MESSAGE_STATE_SUCCESS;
    FB = OQNetwork::getNetwork()->sendMessage(senderId,receiverId,text);
    if(FB==OQ_SEND_MESSAGE_STATE_SUCCESS)std::cout<<"发送成功"<<std::endl;
    else std::cout<<"发送失败"<<std::endl;

}

void ChatBox::setuserId(QString Id){
    userId=Id;
}

QString ChatBox::getuserId(){
    return userId;
}

void ChatBox::setReceiverID(QString id){
    nowReceiverID=id;
}

QString ChatBox::getReceiverID(){
    return nowReceiverID;
}

void ChatBox::on_FriendList_itemClicked(QListWidgetItem *item)
{
    qDebug()<<item->text();//调试
    /*QString text;
    text=ui->textBrowser->toPlainText();
    ui->textEdit->clear();
    text+="\n"+item->text();*/
    QString text="";
    QString senderID="998";//调试
    QString receiverID=item->text();
    QDateTime historyTime=QDateTime::currentDateTime().addSecs(-600);
    QVector<QString>message;
    QVector<QDateTime>time;
    QVector<bool>direction;

    OQ_RECEIVE_MESSAGE_STATE FB=OQ_RECEIVE_MESSAGE_STATE_SUCCESS;
    FB=OQNetwork::getNetwork()->receiveMessage(senderID,receiverID,historyTime,message,time,direction);
    for(int i=0;i<message.size()&& FB == OQ_RECEIVE_MESSAGE_STATE_SUCCESS;i++){

    }
    ui->textBrowser->setText(text);
}
