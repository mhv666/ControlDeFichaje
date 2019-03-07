#include <QDebug>
#include <QString>


#include <iostream>
#include "basedatos.h"

BaseDatos::BaseDatos(QString hostname,int port, QString database,QString user,QString pass )
{


connectDatabase(hostname,port,database,user,pass);
}

void BaseDatos::connectDatabase(QString hostname, int port, QString database, QString user,QString pass)
{


    mdb = QSqlDatabase::addDatabase("QPSQL");
    /*
    mdb.setHostName("127.0.0.1");
    mdb.setPort(5432);
    mdb.setDatabaseName("Fichaje");
    mdb.setUserName("usuario");
    mdb.setPassword("1234");
    */

    mdb.setHostName(hostname);
    mdb.setPort(port);
    mdb.setDatabaseName(database);
    mdb.setUserName(user);
    mdb.setPassword(pass);
    bool ok = mdb.open();

    //QSqlError error = db.lastError();
    //qDebug()<<"error: "<< error;

    if(ok)
    {
        qDebug()<<"Conexion ok";

    }
}

