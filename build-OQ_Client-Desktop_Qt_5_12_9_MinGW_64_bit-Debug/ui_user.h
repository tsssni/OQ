/********************************************************************************
** Form generated from reading UI file 'user.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USER_H
#define UI_USER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_user
{
public:
    QPushButton *pushButton;
    QTextBrowser *textBrowser;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QTextBrowser *textBrowser_2;
    QTextBrowser *textBrowser_3;
    QTextBrowser *textBrowser_4;
    QTextBrowser *textBrowser_5;
    QTextBrowser *textBrowser_6;
    QPushButton *pushButton_2;

    void setupUi(QWidget *user)
    {
        if (user->objectName().isEmpty())
            user->setObjectName(QString::fromUtf8("user"));
        user->resize(356, 520);
        user->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton = new QPushButton(user);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(30, 30, 80, 80));
        pushButton->setMaximumSize(QSize(80, 80));
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border:none;\n"
"image: url(:/new/profile.jpg);"));
        textBrowser = new QTextBrowser(user);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(120, 50, 210, 70));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy);
        textBrowser->setMaximumSize(QSize(210, 70));
        QFont font;
        font.setPointSize(18);
        textBrowser->setFont(font);
        textBrowser->setLayoutDirection(Qt::LeftToRight);
        textBrowser->setStyleSheet(QString::fromUtf8("border:none;"));
        textBrowser->setOverwriteMode(false);
        label = new QLabel(user);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 150, 41, 21));
        QFont font1;
        font1.setPointSize(11);
        label->setFont(font1);
        label_2 = new QLabel(user);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 190, 31, 31));
        label_2->setFont(font1);
        label_3 = new QLabel(user);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 230, 51, 41));
        label_3->setFont(font1);
        label_4 = new QLabel(user);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(50, 290, 51, 21));
        label_4->setFont(font1);
        label_5 = new QLabel(user);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(50, 340, 51, 21));
        label_5->setFont(font1);
        textBrowser_2 = new QTextBrowser(user);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(100, 150, 231, 51));
        textBrowser_2->setStyleSheet(QString::fromUtf8("border:none;"));
        textBrowser_3 = new QTextBrowser(user);
        textBrowser_3->setObjectName(QString::fromUtf8("textBrowser_3"));
        textBrowser_3->setGeometry(QRect(100, 190, 231, 51));
        textBrowser_3->setStyleSheet(QString::fromUtf8("border:none;"));
        textBrowser_4 = new QTextBrowser(user);
        textBrowser_4->setObjectName(QString::fromUtf8("textBrowser_4"));
        textBrowser_4->setGeometry(QRect(100, 240, 231, 51));
        textBrowser_4->setStyleSheet(QString::fromUtf8("border:none;"));
        textBrowser_5 = new QTextBrowser(user);
        textBrowser_5->setObjectName(QString::fromUtf8("textBrowser_5"));
        textBrowser_5->setGeometry(QRect(100, 290, 231, 51));
        textBrowser_5->setStyleSheet(QString::fromUtf8("border:none;"));
        textBrowser_6 = new QTextBrowser(user);
        textBrowser_6->setObjectName(QString::fromUtf8("textBrowser_6"));
        textBrowser_6->setGeometry(QRect(100, 340, 231, 51));
        textBrowser_6->setStyleSheet(QString::fromUtf8("border:none;"));
        pushButton_2 = new QPushButton(user);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(90, 430, 171, 51));
        QFont font2;
        font2.setPointSize(14);
        pushButton_2->setFont(font2);
        pushButton_2->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(67, 142, 255);"));

        retranslateUi(user);

        QMetaObject::connectSlotsByName(user);
    } // setupUi

    void retranslateUi(QWidget *user)
    {
        user->setWindowTitle(QApplication::translate("user", "Form", nullptr));
        pushButton->setText(QString());
        textBrowser->setHtml(QApplication::translate("user", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:18pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:20pt;\">\347\224\250\346\210\267\345\220\215</span></p></body></html>", nullptr));
        label->setText(QApplication::translate("user", "\350\264\246\345\217\267", nullptr));
        label_2->setText(QApplication::translate("user", "\345\271\264\351\276\204", nullptr));
        label_3->setText(QApplication::translate("user", "\347\224\237\346\227\245", nullptr));
        label_4->setText(QApplication::translate("user", "\346\225\205\344\271\241", nullptr));
        label_5->setText(QApplication::translate("user", "\347\224\265\350\257\235", nullptr));
        pushButton_2->setText(QApplication::translate("user", "\347\274\226\350\276\221\350\265\204\346\226\231", nullptr));
    } // retranslateUi

};

namespace Ui {
    class user: public Ui_user {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USER_H
