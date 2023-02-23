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

ChatBox::ChatBox(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ChatBox)
{
    ui->setupUi(this);
    tcpSocket = new QTcpSocket(this);
    tcpSocket->connectToHost("127.0.0.1",8088);//待改
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(readMessage()));
    connect(ui->send,SIGNAL(clicked()),this,SLOT(sendMessage()));
    QTimer *timer = new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(readMessage()));
    //timer->start(5000);要做多线程
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
    a = new AddFriend;
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

void ChatBox::readMessage(QDateTime timetemp, QString mestemp, bool dirtemp){//收消息
                ui->textBrowser->append(timetemp.toString());
                if(dirtemp)ui->textBrowser->append(" 我： ");
                else ui->textBrowser->append(" 来自 "":");
                ui->textBrowser->append(mestemp);
}

void ChatBox::sendMessage(){
//    QMap<QString,QString> m;
    QString text;
    QString senderId , receiverId;
    text=ui->textEdit->toPlainText();//读取输入框中的内容
    ui->textEdit->clear();
    OQ_SEND_MESSAGE_STATE FB=OQ_SEND_MESSAGE_STATE_SUCCESS;
    FB = OQNetwork::getNetwork()->sendMessage(senderId,receiverId,text);
    if(FB==OQ_SEND_MESSAGE_STATE_SUCCESS);
    else std::cout<<"发送失败"<<std::endl;
    //发送回显，目前用服务器直接读取包括自己的消息记录
    //    QDateTime time = QDateTime::currentDateTime();//获取当前时间
    //    QString timestr = time.toString("yyyy-MM-dd hh:mm:ss");
    //    ChatShow = ChatShow  + timestr + " 我： " + text + "\n";
    //    ui->textBrowser->setText(ChatShow);

}

void ChatBox::setuserId(QString Id){
    userId=Id;
}

QString ChatBox::getuserId(){
    return userId;
}
