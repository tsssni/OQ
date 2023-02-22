#include "mysqltest.h"

mysqltest::mysqltest(){
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
bool mysqltest::find(QString id,QString& name,QString password){
    if(this->db.open()){
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
bool mysqltest::add(QString id,QString name,QString password){
    QSqlQuery query(this->db);
    query.prepare(QString("insert into qt(userid,password,name) values ( '%1','%2','%3')").arg(id).arg(password).arg(name));
    return query.exec();
}
bool mysqltest::save(QString senderid,QString receiverid,QString text,QDateTime t){
    if(this->db.open()){
        QSqlQuery query(this->db);
        query.prepare(QString("insert into message(text,sender,receiver,time) values(:text,:senderid,:receiverid,:t)"));
        query.bindValue(":senderid",senderid);
        query.bindValue(":receiverid",receiverid);
        query.bindValue(":text",text);
        query.bindValue(":t",t);
        return query.exec();

    }
    return false;
}
bool mysqltest::history(QString senderid, QString receiverid, QDateTime t,QVector<QString>& text,QVector<QDateTime>& time,QVector<QString>& sender,QVector<QString>& receiver){
    if(this->db.open()){
        QSqlQuery query(this->db);
        query.prepare(QString("select sender,text,receiver,time from message where (sender=:senderid and receiver=:receiverid and time>=:t) or (sender=:receiverid and receiver=:senderid and time>=:t)"));
        query.bindValue(":senderid",senderid);
        query.bindValue(":receiverid",receiverid);
        query.bindValue(":t",t.toString("yyyy-MM-dd hh:mm:ss"));
        query.exec();
        QString ppp;
        while(query.next()){
            sender.push_back(query.value("sender").toString());
            receiver.push_back(query.value("receiver").toString());
            text.push_back(query.value("text").toString());
            time.push_back(query.value("time").toDateTime());
        }
        return true;
    }
    return false;
}
bool mysqltest::getname(QString id, QString &name){
    if(this->db.open()){
        QSqlQuery query(this->db);
        query.prepare(QString("select name from qt where userid=:id"));
        query.bindValue(":id",id);
        query.exec();
        while(query.next()){
            name=query.value("name").toString();
            return true;
        }
    }
    return false;
}
