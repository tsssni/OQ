#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
QT_BEGIN_NAMESPACE
namespace Ui { class LoginWindow; }
QT_END_NAMESPACE

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();
signals:
    void login();
private:
    Ui::LoginWindow *ui;
private slots:
    void signInClicked();
};
