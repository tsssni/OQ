#include "chatbox.h"
#include "ui_chatbox.h"
#include"settings.h"
#include"user.h"
#include"addfriend.h"
#include <QGraphicsDropShadowEffect>
#include <QGuiApplication>
#include <QWidget>
#include <QScreen>
#include <windows.h>
#include<QtNetwork>


ChatBox::ChatBox(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ChatBox)
{
    ui->setupUi(this);
    tcpSocket = new QTcpSocket(this);
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(readMessage()));
    connect(ui->send,SIGNAL(clicked()),this,SLOT(sendMessage()));
    tcpSocket->connectToHost("127.0.0.1",1234);//待改
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

void ChatBox::readMessage(){
    QDataStream in(tcpSocket);
    //in>>blockSize;//保存已接受到的大小
    //if(tcpSocket->bytesAvailable()<blockSize)return;//如果没接收完继续接收
    in>>message;//接收完成就保存在message中
    QDateTime time = QDateTime::currentDateTime();//获取当前时间
    QString timestr = time.toString("yyyy-MM-dd hh:mm:ss");
    ChatShow = ChatShow  + timestr + message;
    ui->textBrowser->setText(ChatShow);
}

void ChatBox::sendMessage(){
    QString text;
    text=ui->textEdit->toPlainText();//读取输入框中的内容
    ui->textEdit->clear();
    QByteArray block;//缓冲区
    QDataStream out(&block, QIODevice::WriteOnly);//数据默认写到block内
    out<<text;
    tcpSocket->write(block);//发送
    QDateTime time = QDateTime::currentDateTime();//获取当前时间
    QString timestr = time.toString("yyyy-MM-dd hh:mm:ss");
    ChatShow = ChatShow  + timestr + " 我： " + text + "\n";
    ui->textBrowser->setText(ChatShow);
}
