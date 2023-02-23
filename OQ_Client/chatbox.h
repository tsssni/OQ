#ifndef CHATBOX_H
#define CHATBOX_H

#include <QWidget>
#include<qpushbutton.h>
#include<QTcpSocket>
#include<QTcpServer>
#include <QDialog>
#include <QObject>
#include <QMessageBox>
#include <QDebug>
#include <QDateTime>

QT_BEGIN_NAMESPACE
namespace Ui { class ChatBox; }
QT_END_NAMESPACE

class ChatBox : public QWidget
{
    Q_OBJECT

public:
    ChatBox(QWidget *parent = nullptr);
    ~ChatBox();
    void setButtonBackImage(QPushButton *button,QString image,int W , int H ,int sizeW, int sizeH);
    void InitUI();
    void changeprofile();
private slots:

    void on_add_clicked();

    void on_user_clicked();

    void on_settings_clicked();


    void readMessage();//读取数据

    void sendMessage();//发送数据

private:
    Ui::ChatBox *ui;
    QTcpSocket *tcpSocket;
    QString message;
    quint16 blockSize;
    QString ChatShow;//聊天记录保存
};
#endif // CHATBOX_H
