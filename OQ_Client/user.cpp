#include "user.h"
#include "ui_user.h"
#include<QFileDialog>
#include<iostream>
#include"changeprofile.h"
#include"oqnetwork.h"
#include"chatbox.h"
user::user(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::user)
{
    ui->setupUi(this);
    this->setWindowTitle("用户设置");
    QString id,name,gender,age,address;
    id=ChatBox::getuserId();
    OQNetwork::getNetwork()->getSettings(id,name,gender,age,address);
    ui->textBrowser->setText(name);
    ui->textBrowser_2->setText(id);
    ui->textBrowser_3->setText(age);
    ui->textBrowser_4->setText(address);
    ui->textBrowser_5->setText(gender);
}

user::~user()
{
    delete ui;
}

void user::on_pushButton_2_clicked()
{
    changeprofile *c = new changeprofile;
    c->show();
    this->close();
}


void user::on_pushButton_clicked()
{
    QString filename=QFileDialog::getOpenFileName(this,tr("Open Image"),QDir::homePath(),tr("(*.jpg)\n(*.bmp)\n(*.png)"));//用系统的文件管理器并保存目录
    ui->pushButton->setStyleSheet("background-color: rgb(255, 255, 255);border:none;image: url("+filename+");");//将图片写到样式表中来更改显示
}
