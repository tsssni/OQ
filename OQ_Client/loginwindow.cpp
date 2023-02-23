#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "oqnetwork.h"
#include <QString>
#include <QStringView>
#include <QDateTime>
#include <QVector>
#include "chatbox.h"
#include "registerwindow.h"
LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    ui->picture->setMask(QRegion(ui->picture->rect(),QRegion::RegionType::Ellipse));
    connect(ui->signIn,SIGNAL(clicked()),this,SLOT(signInClicked()));
    connect(ui->register_2,SIGNAL(clicked()),this,SLOT(registerClicked()));
}
LoginWindow::~LoginWindow()
{
    delete ui;
}
void LoginWindow::signInClicked(){
    QStringView id=ui->uid->text(),psw=ui->upsw->text();
    if(id.empty()){
        ui->inf->setText("请输入OQ号码");
        ui->inf->setStyleSheet("color: rgb(255,0,0)");
        return;
    }
    else if(psw.empty()){
        ui->inf->setText("请输入密码");
        ui->inf->setStyleSheet("color: rgb(255,0,0)");
        return;
    }
    OQ_LOGIN_STATE FB=OQ_LOGIN_STATE_PASSWORD_INVALID;
    //FB = OQNetwork::getNetwork()->login(id,psw);

    switch (FB) {
    case OQ_LOGIN_STATE_SUCCESS:{
            login();
            this->close();
            ChatBox *c = new ChatBox;
            //c
            c->show();
        }
        break;
        case OQ_LOGIN_STATE_PASSWORD_INVALID:{
            ui->inf->setText("登录失败：密码错误");
            ui->inf->setStyleSheet("color: rgb(255,0,0)");
        }
        break;
        case OQ_LOGIN_STATE_NETWORK_ERROR:{
            ui->inf->setText("登录失败：网络错误");
            ui->inf->setStyleSheet("color: rgb(255,0,0)");
        }
        break;
        case OQ_LOGIN_STATE_UNKNOWN_ERROR:{
            ui->inf->setText("登录失败：未知错误");
            ui->inf->setStyleSheet("color: rgb(255,0,0)");
        }
        break;
    }
}
void LoginWindow::registerClicked(){
    RegisterWindow *r=new RegisterWindow;
    r->show();
}
