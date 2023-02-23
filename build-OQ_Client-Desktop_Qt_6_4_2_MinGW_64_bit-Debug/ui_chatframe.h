/********************************************************************************
** Form generated from reading UI file 'chatframe.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATFRAME_H
#define UI_CHATFRAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatFrame
{
public:

    void setupUi(QWidget *ChatFrame)
    {
        if (ChatFrame->objectName().isEmpty())
            ChatFrame->setObjectName("ChatFrame");
        ChatFrame->resize(400, 300);

        retranslateUi(ChatFrame);

        QMetaObject::connectSlotsByName(ChatFrame);
    } // setupUi

    void retranslateUi(QWidget *ChatFrame)
    {
        ChatFrame->setWindowTitle(QCoreApplication::translate("ChatFrame", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatFrame: public Ui_ChatFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATFRAME_H
