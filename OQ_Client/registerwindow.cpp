#include <QMessageBox>
#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "oqnetwork.h"
RegisterWindow::RegisterWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
    connect(ui->registerbutton,SIGNAL(clicked()),this,SLOT(registerButtonClicked()));
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}
void RegisterWindow::registerButtonClicked(){
    QStringView name=ui->uname->text(),psw=ui->upsw->text(),psw2=ui->upsw2->text(),vcode=ui->vcode->text();
    QString id;
    if(name.empty()){
        ui->inf->setText("昵称不可以为空");
        ui->inf->setStyleSheet("color: rgb(255,0,0)");
        return;
    }
    else if(psw.empty()){
        ui->inf->setText("请输入密码");
        ui->inf->setStyleSheet("color: rgb(255,0,0)");
        return;
    }
    else if(psw2.empty()){
        ui->inf->setText("请确认密码");
        ui->inf->setStyleSheet("color: rgb(255,0,0)");
        return;
    }
    else if(psw!=psw2){
        ui->inf->setText("密码不一致,请重新输入");
        ui->inf->setStyleSheet("color: rgb(255,0,0)");
        return;
    }
    else if(vcode.empty()){
        ui->inf->setText("请输入验证码");
        ui->inf->setStyleSheet("color: rgb(255,0,0)");
        return;
    }
//    else {
//    }

    OQ_REGISTER_STATE FB=OQ_REGISTER_STATE_SUCCESS;//;
   // FB = OQNetwork::getNetwork()->registerUser(name,psw,id);
    switch (FB) {
    case OQ_REGISTER_STATE_SUCCESS:{
            this->close();
            QMessageBox::about(this,"注册成功","您的oq号码为");
        }
        break;
        case OQ_REGISTER_STATE_NETWORK_ERROR:{
            ui->inf->setText("注册失败：网络错误");
            ui->inf->setStyleSheet("color: rgb(255,0,0)");
        }
        break;
        case OQ_REGISTER_STATE_UNKNOWN_ERROR:{
            ui->inf->setText("注册失败：未知错误");
            ui->inf->setStyleSheet("color: rgb(255,0,0)");
        }
        break;
    }
}
