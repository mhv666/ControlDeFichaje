#include <QDebug>
#include <iostream>
#include "basedatos.h"

BaseDatos::BaseDatos(QString hostname,int port, QString database,QString user,QString pass )
{
///asignar valores a los campos de clase
}

void BaseDatos::connectDatabase()
{

    mdb = QSqlDatabase::addDatabase("QPSQL");
    mdb.setHostName("127.0.0.1");
    mdb.setPort(5432);
    mdb.setDatabaseName("Fichaje");
    mdb.setUserName("usuario");
    mdb.setPassword("1234");


    bool ok = mdb.open();

    //QSqlError error = db.lastError();
    //qDebug()<<"error: "<< error;

    if(ok)
    {
        qDebug()<<"Conexion ok";

    }
}

