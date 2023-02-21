#ifndef MYSQLTEST_H
#define MYSQLTEST_H
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QApplication>
#include <QtWidgets/QMessageBox>
#include <QStringView>

class mysqltest : public QObject
{
public:
    mysqltest(QObject* parent = nullptr);
    QSqlDatabase db;
    bool find(QStringView id,QString& name,QStringView password);
    bool add(QStringView id,QStringView name,QStringView password);
};

#endif // MYSQLTEST_H
