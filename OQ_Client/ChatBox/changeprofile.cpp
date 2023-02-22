#include "changeprofile.h"
#include "ui_changeprofile.h"
#include<QFileDialog>
#include<string>
#include"user.h"

changeprofile::changeprofile(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::changeprofile)
{
    ui->setupUi(this);
    this->setWindowTitle("编辑资料");
    QFile file(path);
    file.open(QIODevice::ReadWrite);
    QByteArray array;
    QString s=file.readLine();
    ui->textEdit->setText(s);
    array=file.readLine();
    temp = array;
    s=file.readLine();
    ui->textEdit_5->setText(s);
    s=file.readLine();
    ui->textEdit_4->setText(s);
    s=file.readLine();
    ui->textEdit_2->setText(s);
    s=file.readLine();
    ui->textEdit_3->setText(s);
    file.close();
}

changeprofile::~changeprofile()
{
    delete ui;
}

void changeprofile::on_pushButton_clicked()
{
    QFile file(path);
    file.open(QIODevice::ReadWrite);
    QByteArray array;
    array = ui->textEdit->toPlainText().toUtf8();
    file.write(array);
    file.write(temp);
    array = ui->textEdit_5->toPlainText().toUtf8();
    file.write(array);
    array = ui->textEdit_4->toPlainText().toUtf8();
    file.write(array);
    array = ui->textEdit_2->toPlainText().toUtf8();
    file.write(array);
    array = ui->textEdit_3->toPlainText().toUtf8();
    file.write(array);
    file.close();
    this->close();
    user *u = new user;
    u->show();
}

