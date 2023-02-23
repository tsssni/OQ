#ifndef ADDFRIEND_H
#define ADDFRIEND_H

#include <QWidget>
#include <QListWidget>
namespace Ui {
class AddFriend;
}

class AddFriend : public QWidget
{
    Q_OBJECT

public:
    explicit AddFriend(QListWidget *friendList,QWidget *parent = nullptr);
    ~AddFriend();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AddFriend *ui;
    QListWidget *friendList;
};

#endif // ADDFRIEND_H
