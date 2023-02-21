#ifndef CHATFRAME_H
#define CHATFRAME_H
#include"loginwindow.h"
#include <QWidget>

namespace Ui {
class ChatFrame;
}

class ChatFrame : public QWidget
{
    Q_OBJECT

public:
    explicit ChatFrame(QWidget *parent = nullptr);
    ~ChatFrame();

private:
    Ui::ChatFrame *ui;
    LoginWindow *mlog;
};

#endif // CHATFRAME_H
