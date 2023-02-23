#include <QMessageBox>
#include <QPainter>
#include <QMouseEvent>
#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "oqnetwork.h"

void RegisterWindow::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QPen pen;
    QFont font("楷体",25,QFont::Bold,true);
    painter.setFont(font);
    for(int i=0;i<4;++i){
        pen=QPen(QColor(qrand()%220,qrand()%220,qrand()%220));
        painter.setPen(pen);
        painter.drawText(170+i*20,175,100,300,Qt::AlignCenter,realvcode.mid(i,1));
    }
    for(int i=0;i<50;++i){
        pen=QPen(QColor(qrand()%256,qrand()%256,qrand()%256));
        painter.setPen(pen);
        painter.drawPoint(210+qrand()%90,310+qrand()%40);
    }
    for(int i=0;i<20;++i){
        pen=QPen(QColor(qrand()%256,qrand()%256,qrand()%256));
        painter.setPen(pen);
        painter.drawLine(210+qrand()%90,310+qrand()%40,210+qrand()%90,310+qrand()%40);
    }
}

void RegisterWindow::getvcode(){
    realvcode.clear();
    for(int i=0;i<4;++i){
        int tmp=qrand()%3;
        if(tmp==0){
            realvcode+=('0'+qrand()%10);
        }
        else if(tmp==1){
            realvcode+=('a'+qrand()%26);
        }
        else{
            realvcode+=('A'+qrand()%26);
        }
    }
    update();
}
void RegisterWindow::mousePressEvent(QMouseEvent *event){
    int x=event->x(),y=event->y();
    if(x>=210&&x<=300&&y>=310&&y<=350){
        this->getvcode();
    }
}
RegisterWindow::RegisterWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
    getvcode();
    connect(ui->registerbutton,SIGNAL(clicked()),this,SLOT(registerButtonClicked()));
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}
void RegisterWindow::registerButtonClicked(){
    QStringView name=ui->uname->text(),psw=ui->upsw->text(),psw2=ui->upsw2->text();
    QString vcode=ui->vcode->text(),id;
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
    else if(vcode.isEmpty()){
        ui->inf->setText("请输入验证码");
        ui->inf->setStyleSheet("color: rgb(255,0,0)");
        return;
    }
    else if(realvcode!=vcode){
        ui->inf->setText("验证码错误");
        ui->inf->setStyleSheet("color: rgb(255,0,0)");
        getvcode();
        return;
    }

    OQ_REGISTER_STATE FB = OQNetwork::getNetwork()->registerUser(name,psw,id);

    switch (FB) {
    case OQ_REGISTER_STATE_SUCCESS:{
            this->close();
            QMessageBox::about(this,"注册成功","您的oq号码为:"+id);
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
