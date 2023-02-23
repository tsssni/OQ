/********************************************************************************
** Form generated from reading UI file 'registerwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWINDOW_H
#define UI_REGISTERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegisterWindow
{
public:
    QLineEdit *uid;
    QLineEdit *upsw;
    QLineEdit *upsw2;
    QLineEdit *vcode;
    QPushButton *registerbutton;
    QLabel *picture;
    QLabel *word1;
    QLabel *word2;

    void setupUi(QWidget *RegisterWindow)
    {
        if (RegisterWindow->objectName().isEmpty())
            RegisterWindow->setObjectName(QString::fromUtf8("RegisterWindow"));
        RegisterWindow->resize(400, 470);
        RegisterWindow->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	background-color: rgb(255,255,255);\n"
"}\n"
"QLineEdit\n"
"{\n"
"	border:none;\n"
"	border-bottom:1px solid rgb(229,229,229);\n"
"	font:18px;\n"
"}\n"
"QLineEdit#vcode\n"
"{\n"
"	border-radius:5px;\n"
"	border:2px solid rgb(220,220,220);\n"
"	font:18px;\n"
"}\n"
"QPushButton\n"
"{\n"
"	background-color: rgb(7,188,252);\n"
"	border-radius:5px;\n"
"	font:18px;\n"
"	font-weight:500;\n"
"	color:white;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	background-color: rgb(6, 201, 255);\n"
"}\n"
"QLabel{\n"
"	background-color: rgb(0,0,0,0%);\n"
"}\n"
"QLabel#word1{\n"
"	font:40px;\n"
"	font-weight:500;\n"
"	color:white;\n"
"}\n"
"QLabel#word2{\n"
"	font:18px;\n"
"	font-weight:500;\n"
"	color:white;\n"
"}"));
        uid = new QLineEdit(RegisterWindow);
        uid->setObjectName(QString::fromUtf8("uid"));
        uid->setGeometry(QRect(70, 170, 231, 31));
        upsw = new QLineEdit(RegisterWindow);
        upsw->setObjectName(QString::fromUtf8("upsw"));
        upsw->setGeometry(QRect(70, 220, 231, 31));
        upsw2 = new QLineEdit(RegisterWindow);
        upsw2->setObjectName(QString::fromUtf8("upsw2"));
        upsw2->setGeometry(QRect(70, 260, 231, 31));
        vcode = new QLineEdit(RegisterWindow);
        vcode->setObjectName(QString::fromUtf8("vcode"));
        vcode->setGeometry(QRect(70, 310, 101, 31));
        registerbutton = new QPushButton(RegisterWindow);
        registerbutton->setObjectName(QString::fromUtf8("registerbutton"));
        registerbutton->setGeometry(QRect(70, 400, 111, 41));
        picture = new QLabel(RegisterWindow);
        picture->setObjectName(QString::fromUtf8("picture"));
        picture->setGeometry(QRect(0, 0, 400, 140));
        picture->setPixmap(QPixmap(QString::fromUtf8(":/Resource/background2.png")));
        word1 = new QLabel(RegisterWindow);
        word1->setObjectName(QString::fromUtf8("word1"));
        word1->setGeometry(QRect(50, 20, 221, 81));
        word2 = new QLabel(RegisterWindow);
        word2->setObjectName(QString::fromUtf8("word2"));
        word2->setGeometry(QRect(50, 90, 151, 31));

        retranslateUi(RegisterWindow);

        QMetaObject::connectSlotsByName(RegisterWindow);
    } // setupUi

    void retranslateUi(QWidget *RegisterWindow)
    {
        RegisterWindow->setWindowTitle(QApplication::translate("RegisterWindow", "Register", nullptr));
        uid->setPlaceholderText(QApplication::translate("RegisterWindow", "\346\230\265\347\247\260", nullptr));
        upsw->setPlaceholderText(QApplication::translate("RegisterWindow", "\345\257\206\347\240\201", nullptr));
        upsw2->setPlaceholderText(QApplication::translate("RegisterWindow", "\347\241\256\350\256\244\345\257\206\347\240\201", nullptr));
        vcode->setPlaceholderText(QApplication::translate("RegisterWindow", "\351\252\214\350\257\201\347\240\201", nullptr));
        registerbutton->setText(QApplication::translate("RegisterWindow", "\347\253\213\345\215\263\346\263\250\345\206\214", nullptr));
        picture->setText(QString());
        word1->setText(QApplication::translate("RegisterWindow", "\346\254\242\350\277\216\346\263\250\345\206\214OQ", nullptr));
        word2->setText(QApplication::translate("RegisterWindow", "\346\257\217\344\270\200\345\244\251\357\274\214\344\271\220\345\234\250\346\262\237\351\200\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterWindow: public Ui_RegisterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWINDOW_H
