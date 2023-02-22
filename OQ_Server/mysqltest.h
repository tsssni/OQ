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
class mysqltest
{
public:
    mysqltest();
    QSqlDatabase db;
    bool find(QString id,QString& name,QString password);
    bool add(QString id,QString name,QString password);
    bool save(QString senderid,QString receiverid,QString text,QDateTime t);
    bool history(QString senderid, QString receiverid, QDateTime t,QVector<QString>& text,QVector<QDateTime>& time,QVector<QString>& sender,QVector<QString>& receiver);
    bool getname(QString id,QString& name);
};

#endif // MYSQLTEST_H
