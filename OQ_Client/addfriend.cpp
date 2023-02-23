#include "addfriend.h"
#include "ui_addfriend.h"
#include <QMessageBox>
AddFriend::AddFriend(QListWidget *f,QWidget *parent) :
    friendList(f),
    QWidget(parent),
    ui(new Ui::AddFriend)
{
    ui->setupUi(this);
    this->setWindowTitle("添加好友");
}

AddFriend::~AddFriend()
{
    delete ui;
}

void AddFriend::on_pushButton_clicked()
{
    if(ui->lineEdit->text()=="123"){
        friendList->addItem("123");
    }else {
        QMessageBox::warning(this,"错误","输入的id不存在",QMessageBox::Ok);
    }
}
