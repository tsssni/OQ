#include "user.h"
#include "ui_user.h"
#include<QFileDialog>
#include<iostream>
#include"changeprofile.h"
user::user(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::user)
{
    ui->setupUi(this);
    this->setWindowTitle("用户设置");
    QString path ="D:/Qt Code/QQ_ChatBox/profile/profile.txt";
    QFile file(path);
    QString s;
    file.open(QIODevice::ReadOnly);
    s=file.readLine();
    ui->textBrowser->setText(s);
    s=file.readLine();
    ui->textBrowser_2->setText(s);
    s=file.readLine();
    ui->textBrowser_3->setText(s);
    s=file.readLine();
    ui->textBrowser_4->setText(s);
    s=file.readLine();
    ui->textBrowser_5->setText(s);
    s=file.readLine();
    ui->textBrowser_6->setText(s);
    file.close();
}

user::~user()
{
    delete ui;
}

void user::on_pushButton_2_clicked()//编辑资料
{
    changeprofile *c = new changeprofile;
    c->show();
    this->close();
}


void user::on_pushButton_clicked()//修改头像
{
    QString filename=QFileDialog::getOpenFileName(this,tr("Open Image"),QDir::homePath(),tr("(*.jpg)\n(*.bmp)\n(*.png)"));//用系统的文件管理器并保存目录
    ui->pushButton->setStyleSheet("background-color: rgb(255, 255, 255);border:none;image: url("+filename+");");//将图片写到样式表中来更改显示
}
