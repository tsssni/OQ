#include "mysqltest.h"

mysqltest::mysqltest(QObject* parent)
    :QObject(parent)
{
    this->db = QSqlDatabase::addDatabase("QODBC");
        db.setHostName("127.0.0.1");
        db.setPort(3306);
        db.setDatabaseName("1");
        db.setUserName("root");
        db.setPassword("1234");
        bool ok = db.open();
        if (ok){
            qDebug()<<("success");
        }
        else {
            qDebug()<<"error open database because"<<db.lastError().text();
        }
        db.close();
}
bool mysqltest::find(QStringView id,QString& name,QStringView password){
    if(db.open()){
    QSqlQuery result =  this->db.exec(QString(" select * from qt where userid='%1'").arg(id));
        QString userIdValue;
        QString pswValue;
        QString nameValue;

        while(result.next()){
            userIdValue=result.value("userid").toString();
            nameValue=result.value("name").toString();
            pswValue=result.value("password").toString();
            if(id==userIdValue){
                if(pswValue==password){
                    name=nameValue;
                    return true;
                }
            }
        }
    }
    return false;
}

bool mysqltest::add(QStringView id,QStringView name,QStringView password){
    QSqlQuery query(this->db);
    query.prepare(QString("insert into qt(userid,password,name) values ( '%1','%2','%3')").arg(id).arg(password).arg(name));
    return query.exec();
}
