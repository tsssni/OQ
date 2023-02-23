#ifndef MYSQLTEST_H
#define MYSQLTEST_H
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QApplication>
#include <QtWidgets/QMessageBox>
#include <string>
#include <qdatetime.h>
#include <qvector.h>
#include<iostream>
class OQMySqlTest : public QObject
{
public:
    OQMySqlTest(QObject* parent = nullptr);
    bool find(QStringView id,QString& name,QStringView password);
    bool add(QStringView id,QStringView name,QStringView password);
    bool save(QStringView senderid,QStringView receiverid,QStringView text,const QDateTime& t);
    bool history(QStringView senderid, QStringView receiverid, const QDateTime& t,QVector<QString>& text,QVector<QDateTime>& time,QVector<QString>& sender,QVector<QString>& receiver);
    bool getname(QStringView id,QString& name);
    bool regist(QStringView name, QStringView password, QString& id);
private:
    QSqlDatabase mDataBase;
};

#endif // MYSQLTEST_H
