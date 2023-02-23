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
#include <QListWidget>

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
    static void setuserId(QString Id);
    static QString getuserId();
    QString getReceiverID();
    void setReceiverID(QString id);
    void read();

public slots:

    void on_add_clicked();

    void on_user_clicked();

    void on_settings_clicked();


    void readMessage();//读取新消息

    void sendMessage();//发送数据

private slots:
    void on_FriendList_itemClicked(QListWidgetItem *item);

private:
    Ui::ChatBox *ui;
    QTcpSocket *tcpSocket;
    QString message;
    quint16 blockSize;
    QString ChatShow;//聊天记录保存
    static QString userId;
    QString nowReceiverID;
};
#endif // CHATBOX_H
