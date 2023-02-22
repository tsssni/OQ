#ifndef CHANGEPROFILE_H
#define CHANGEPROFILE_H

#include <QWidget>

namespace Ui {
class changeprofile;
}

class changeprofile : public QWidget
{
    Q_OBJECT

public:
    explicit changeprofile(QWidget *parent = nullptr);
    ~changeprofile();

private slots:
    void on_pushButton_clicked();

private:
    Ui::changeprofile *ui;
    QString path ="D:/Qt Code/QQ_ChatBox/profile/profile.txt";
    QByteArray temp;
};

#endif // CHANGEPROFILE_H
