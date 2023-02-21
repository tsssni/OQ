<<<<<<< HEAD
=======
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

>>>>>>> 38903b3b3b0b0c5323008f885dfc3df61c636a15
#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
QT_BEGIN_NAMESPACE
<<<<<<< HEAD
namespace Ui { class LoginWindow; }
QT_END_NAMESPACE

class LoginWindow : public QMainWindow
=======
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
>>>>>>> 38903b3b3b0b0c5323008f885dfc3df61c636a15
{
    Q_OBJECT

public:
<<<<<<< HEAD
    LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private:
    Ui::LoginWindow *ui;
=======
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
>>>>>>> 38903b3b3b0b0c5323008f885dfc3df61c636a15

private slots:
    void signInClicked();
};
<<<<<<< HEAD
=======
#endif // MAINWINDOW_H
>>>>>>> 38903b3b3b0b0c5323008f885dfc3df61c636a15
