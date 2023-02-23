#include "changeprofile.h"
#include "ui_changeprofile.h"
#include<QFileDialog>
#include<string>
#include"user.h"
#include"oqnetwork.h"
#include"chatbox.h"

changeprofile::changeprofile(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::changeprofile)
{
    ui->setupUi(this);
    this->setWindowTitle("编辑资料");
    QString id,name,age,address,gender;
    id = ChatBox::getuserId();
    OQNetwork::getNetwork()->getSettings(id,name,gender,age,address);
    ui->textEdit->setText(name);
    ui->textEdit_5->setText(age);
    ui->textEdit_4->setText(address);
    ui->textEdit_2->setText(gender);
}

changeprofile::~changeprofile()
{
    delete ui;
}

void changeprofile::on_pushButton_clicked()
{
    QString id,name,age,address,gender;
    id = ChatBox::getuserId();
    name = ui->textEdit->toPlainText();
    age=ui->textEdit_5->toPlainText();
    address=ui->textEdit_4->toPlainText();
    gender=ui->textEdit_2->toPlainText();
    OQNetwork::getNetwork()->setSettings(id,name,gender,age,address);
    this->close();
    user *u = new user;
    u->show();
}

