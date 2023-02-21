<<<<<<< HEAD
#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
=======
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
>>>>>>> 38903b3b3b0b0c5323008f885dfc3df61c636a15
{
    ui->setupUi(this);
    ui->picture->setMask(QRegion(ui->picture->rect(),QRegion::RegionType::Ellipse));
    connect(ui->signIn,SIGNAL(clicked()),this,SLOT(signInClicked()));
}

<<<<<<< HEAD
LoginWindow::~LoginWindow()
=======
MainWindow::~MainWindow()
>>>>>>> 38903b3b3b0b0c5323008f885dfc3df61c636a15
{
    delete ui;
}

<<<<<<< HEAD
void LoginWindow::signInClicked(){
=======
void MainWindow::signInClicked(){
>>>>>>> 38903b3b3b0b0c5323008f885dfc3df61c636a15
    ;
}
