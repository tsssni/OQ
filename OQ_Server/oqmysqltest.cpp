#include "oqmysqltest.h"

OQMySqlTest::OQMySqlTest(QObject* parent)
    :QObject(parent)
{
    this->mDataBase = QSqlDatabase::addDatabase("QODBC");
        mDataBase.setHostName("127.0.0.1");
        mDataBase.setPort(3306);
        mDataBase.setDatabaseName("1");
        mDataBase.setUserName("root");
        mDataBase.setPassword("1234");
        bool ok = mDataBase.open();
        if (ok){
            qDebug()<<("success");
        }
        else {
            qDebug()<<"error open database because"<<mDataBase.lastError().text();
        }
        mDataBase.close();
}
bool OQMySqlTest::find(QStringView id,QString& name,QStringView password){
    if(this->mDataBase.open()){
    QSqlQuery result =  this->mDataBase.exec(QString(" select * from qt where userid='%1'").arg(id));
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
bool OQMySqlTest::add(QStringView id,QStringView name,QStringView password){
    QSqlQuery query(this->mDataBase);
    query.prepare(QString("insert into qt(userid,password,name) values ( '%1','%2','%3')").arg(id).arg(password).arg(name));
    return query.exec();
}
bool OQMySqlTest::save(QStringView senderid,QStringView receiverid,QStringView text,const QDateTime& t){
    if(this->mDataBase.open()){
        QSqlQuery query(this->mDataBase);
        query.prepare(QString("insert into message(text,sender,receiver,time) values(:text,:senderid,:receiverid,:t)"));
        query.bindValue(":senderid",senderid.toString());
        query.bindValue(":receiverid",receiverid.toString());
        query.bindValue(":text",text.toString());
        query.bindValue(":t",t);
        return query.exec();

    }
    return false;
}
bool OQMySqlTest::history(QStringView senderid, QStringView receiverid, const QDateTime& t,QVector<QString>& text,QVector<QDateTime>& time,QVector<QString>& sender,QVector<QString>& receiver){
    if(this->mDataBase.open()){
        QSqlQuery query(this->mDataBase);
        query.prepare(QString("select sender,text,receiver,time from message where (sender=:senderid and receiver=:receiverid and time>=:t) or (sender=:receiverid and receiver=:senderid and time>=:t)"));
        query.bindValue(":senderid",senderid.toString());
        query.bindValue(":receiverid",receiverid.toString());
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
bool OQMySqlTest::getname(QStringView id, QString &name){
    if(this->mDataBase.open()){
        QSqlQuery query(this->mDataBase);
        query.prepare(QString("select name from qt where userid=:id"));
        query.bindValue(":id",id.toString());
        query.exec();
        while(query.next()){
            name=query.value("name").toString();
            return true;
        }
    }
    return false;
}
bool OQMySqlTest::regist(QStringView name, QStringView password, QString& id){
    if(this->mDataBase.open()){
        QSqlQuery query(this->mDataBase);
        query.prepare(QString("select max(userid) as userid from qt"));
        query.exec();
        query.next();
        int idnumber = query.value("userid").toInt();
        id = QString::number(idnumber+1);
        query.clear();
        query.prepare(QString("insert into information (userid,name) values(:userid,:name)"));
        query.bindValue(":userid",id);
        query.bindValue(":name",name.toString());
        query.exec();
        return this->add(id,name,password);
    }
    return false;
}
bool OQMySqlTest::update(QStringView id,QStringView name, QStringView gender, QStringView age, QStringView address){
    if(this->mDataBase.open()){
        QSqlQuery query(this->mDataBase);
        query.prepare("update information set name=:name, gender=:gender,age=:age,address=:address where userid=:id");
        query.bindValue(":name",name.toString());
        query.bindValue(":gender",gender.toString());
        query.bindValue(":age",age.toString());
        query.bindValue(":address",address.toString());
        query.bindValue(":id",id.toString());
        return query.exec();
    }
    return false;
}
bool OQMySqlTest::show(QStringView id,QString &name, QString &gender, QString &age, QString &address){
    if(this->mDataBase.open()){
        QSqlQuery query(this->mDataBase);
        query.prepare("select * from information where userid=:id");
        query.bindValue(":id",id.toString());
        query.exec();
        query.next();
        name=query.value("name").toString();
        gender=query.value("gender").toString();
        age=query.value("age").toString();
        address=query.value("address").toString();
        return true;
    }
    return false;
}
