#include "loginwindow.h"
#include "ui_loginwindow.h"

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
    ;
}
