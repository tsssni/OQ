#include "chatframe.h"
#include "ui_chatframe.h"

ChatFrame::ChatFrame(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChatFrame)
{
    ui->setupUi(this);
    mlog=new LoginWindow;
    mlog->show();
    connect(mlog,SIGNAL(login()),this,SLOT(show()));
}

ChatFrame::~ChatFrame()
{
    delete ui;
}
