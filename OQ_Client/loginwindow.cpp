#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "oqnetwork.h"
#include <QString>
#include <QStringView>
#include <QDateTime>
#include <QVector>
#include"chatbox.h"
LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    ui->picture->setMask(QRegion(ui->picture->rect(),QRegion::RegionType::Ellipse));
    connect(ui->signIn,SIGNAL(clicked()),this,SLOT(signInClicked()));
}
LoginWindow::~LoginWindow()
{
    delete ui;
}
void LoginWindow::signInClicked(){
    QStringView id=ui->uid->text(),psw=ui->upsw->text();
    OQ_LOGIN_STATE FB=OQ_LOGIN_STATE_SUCCESS;
    FB = OQNetwork::getNetwork()->login(id,psw);

    switch (FB) {
        case OQ_LOGIN_STATE_SUCCESS:
        login();
        this->close();
        ChatBox *c = new ChatBox;
        c->show();
        break;
    //    case :
      //  break;
    }
}
