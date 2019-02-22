#include <QDebug>
#include "basedatos.h"

BaseDatos::BaseDatos()
{

}
///TODO: Crear un programa nuevo en qt para leer un archivo de
/// Configuracion.
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
