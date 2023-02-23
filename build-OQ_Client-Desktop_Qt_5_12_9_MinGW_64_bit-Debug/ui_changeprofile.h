/********************************************************************************
** Form generated from reading UI file 'changeprofile.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEPROFILE_H
#define UI_CHANGEPROFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_changeprofile
{
public:
    QLabel *label;
    QTextEdit *textEdit;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QTextEdit *textEdit_2;
    QTextEdit *textEdit_3;
    QTextEdit *textEdit_4;
    QPushButton *pushButton;
    QTextEdit *textEdit_5;

    void setupUi(QWidget *changeprofile)
    {
        if (changeprofile->objectName().isEmpty())
            changeprofile->setObjectName(QString::fromUtf8("changeprofile"));
        changeprofile->resize(390, 526);
        changeprofile->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label = new QLabel(changeprofile);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 50, 54, 16));
        QFont font;
        font.setPointSize(11);
        label->setFont(font);
        textEdit = new QTextEdit(changeprofile);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(80, 40, 241, 31));
        textEdit->setStyleSheet(QString::fromUtf8(""));
        label_2 = new QLabel(changeprofile);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 100, 51, 31));
        label_2->setFont(font);
        label_3 = new QLabel(changeprofile);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 160, 41, 31));
        label_3->setFont(font);
        label_4 = new QLabel(changeprofile);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 220, 41, 31));
        label_4->setFont(font);
        label_5 = new QLabel(changeprofile);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 280, 41, 31));
        label_5->setFont(font);
        textEdit_2 = new QTextEdit(changeprofile);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(80, 220, 241, 31));
        textEdit_3 = new QTextEdit(changeprofile);
        textEdit_3->setObjectName(QString::fromUtf8("textEdit_3"));
        textEdit_3->setGeometry(QRect(80, 280, 241, 31));
        textEdit_4 = new QTextEdit(changeprofile);
        textEdit_4->setObjectName(QString::fromUtf8("textEdit_4"));
        textEdit_4->setGeometry(QRect(80, 160, 241, 31));
        pushButton = new QPushButton(changeprofile);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(120, 400, 151, 61));
        QFont font1;
        font1.setPointSize(18);
        pushButton->setFont(font1);
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(79, 157, 236);"));
        textEdit_5 = new QTextEdit(changeprofile);
        textEdit_5->setObjectName(QString::fromUtf8("textEdit_5"));
        textEdit_5->setGeometry(QRect(80, 100, 241, 31));
        textEdit_5->setStyleSheet(QString::fromUtf8(""));

        retranslateUi(changeprofile);

        QMetaObject::connectSlotsByName(changeprofile);
    } // setupUi

    void retranslateUi(QWidget *changeprofile)
    {
        changeprofile->setWindowTitle(QApplication::translate("changeprofile", "Form", nullptr));
        label->setText(QApplication::translate("changeprofile", "\346\230\265\347\247\260", nullptr));
        label_2->setText(QApplication::translate("changeprofile", "\345\271\264\351\276\204", nullptr));
        label_3->setText(QApplication::translate("changeprofile", "\347\224\237\346\227\245", nullptr));
        label_4->setText(QApplication::translate("changeprofile", "\346\225\205\344\271\241", nullptr));
        label_5->setText(QApplication::translate("changeprofile", "\347\224\265\350\257\235", nullptr));
        pushButton->setText(QApplication::translate("changeprofile", "\344\277\235\345\255\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class changeprofile: public Ui_changeprofile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEPROFILE_H
