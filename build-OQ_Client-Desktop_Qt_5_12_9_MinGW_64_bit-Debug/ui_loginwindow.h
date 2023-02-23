/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *upsw;
    QLabel *background;
    QPushButton *signIn;
    QPushButton *register_2;
    QLabel *picture;
    QLineEdit *uid;

    void setupUi(QMainWindow *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName(QString::fromUtf8("LoginWindow"));
        LoginWindow->setEnabled(true);
        LoginWindow->resize(530, 410);
        LoginWindow->setMaximumSize(QSize(530, 410));
        LoginWindow->setStyleSheet(QString::fromUtf8("QWidget#centralwidget{\n"
"	background-color: rgb(255,255,255);\n"
"}\n"
"QPushButton#signIn\n"
"{\n"
"	background-color: rgb(7,188,252);\n"
"	border-radius:5px;\n"
"	font:18px;\n"
"	font-weight:500;\n"
"	color:white;\n"
"}\n"
"QPushButton#signIn:hover\n"
"{\n"
"	background-color: rgb(6, 201, 255);\n"
"}\n"
"QPushButton#register_2\n"
"{\n"
"	border:none;\n"
"	color: rgb(166,166,166);\n"
"}\n"
"QPushButton#register_2:hover\n"
"{\n"
"	color: rgb(100,100,100);\n"
"}\n"
"QLineEdit\n"
"{\n"
"	border:none;\n"
"	border-bottom:1px solid rgb(229,229,229);\n"
"	font:18px;\n"
"}"));
        centralwidget = new QWidget(LoginWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setAutoFillBackground(false);
        centralwidget->setStyleSheet(QString::fromUtf8(""));
        upsw = new QLineEdit(centralwidget);
        upsw->setObjectName(QString::fromUtf8("upsw"));
        upsw->setGeometry(QRect(120, 260, 290, 35));
        upsw->setEchoMode(QLineEdit::Password);
        background = new QLabel(centralwidget);
        background->setObjectName(QString::fromUtf8("background"));
        background->setEnabled(true);
        background->setGeometry(QRect(0, 0, 530, 155));
        background->setPixmap(QPixmap(QString::fromUtf8(":/Resource/background.png")));
        signIn = new QPushButton(centralwidget);
        signIn->setObjectName(QString::fromUtf8("signIn"));
        signIn->setGeometry(QRect(120, 345, 290, 40));
        register_2 = new QPushButton(centralwidget);
        register_2->setObjectName(QString::fromUtf8("register_2"));
        register_2->setGeometry(QRect(10, 380, 70, 25));
        picture = new QLabel(centralwidget);
        picture->setObjectName(QString::fromUtf8("picture"));
        picture->setGeometry(QRect(220, 110, 90, 90));
        picture->setPixmap(QPixmap(QString::fromUtf8(":/Resource/oqpicture.png")));
        uid = new QLineEdit(centralwidget);
        uid->setObjectName(QString::fromUtf8("uid"));
        uid->setGeometry(QRect(120, 210, 290, 35));
        LoginWindow->setCentralWidget(centralwidget);

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LoginWindow)
    {
        LoginWindow->setWindowTitle(QApplication::translate("LoginWindow", "Login", nullptr));
        upsw->setText(QString());
        upsw->setPlaceholderText(QApplication::translate("LoginWindow", "\345\257\206\347\240\201", nullptr));
        background->setText(QString());
        signIn->setText(QApplication::translate("LoginWindow", "\347\231\273\345\275\225", nullptr));
        register_2->setText(QApplication::translate("LoginWindow", "\346\263\250\345\206\214\350\264\246\345\217\267", nullptr));
        picture->setText(QString());
        uid->setPlaceholderText(QApplication::translate("LoginWindow", "OQ\345\217\267\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
