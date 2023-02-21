#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->picture->setMask(QRegion(ui->picture->rect(),QRegion::RegionType::Ellipse));
    connect(ui->signIn,SIGNAL(clicked()),this,SLOT(signInClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::signInClicked(){
    ;
}
