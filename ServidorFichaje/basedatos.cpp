#include <QDebug>
#include <QString>
#include <iostream>
#include <QDateTime>
#include "basedatos.h"

BaseDatos::BaseDatos(QString hostname,int port, QString database,QString user,QString pass )
{
connectDatabase(hostname,port,database,user,pass);
}

void BaseDatos::connectDatabase(QString hostname, int port, QString database, QString user,QString pass)
{


    m_db = QSqlDatabase::addDatabase("QPSQL");
    /*
    mdb.setHostName("127.0.0.1");
    mdb.setPort(5432);
    mdb.setDatabaseName("Fichaje");
    mdb.setUserName("usuario");
    mdb.setPassword("1234");
    */

    m_db.setHostName(hostname);
    m_db.setPort(port);
    m_db.setDatabaseName(database);
    m_db.setUserName(user);
    m_db.setPassword(pass);
    bool ok = m_db.open();

    //QSqlError error = db.lastError();
    //qDebug()<<"error: "<< error;

    if(ok)
    {
        qDebug()<<"Conexion ok";

    }
}

bool BaseDatos::checkInCheckOut(QString ean13)
{
bool ok = m_db.open();

if(ok)
{
  int idTrabajador;
  int idEntradaSalida ;
  QSqlQuery selectIdTrabajador;
  QSqlQuery selectIdEntradaSalida;


  selectIdTrabajador.prepare("SELECT id_trabajador FROM trabajador WHERE  ean13_trabajador = :ean13_trabajador LIMIT 1 ;");
  selectIdTrabajador.bindValue(":ean13_trabajador", ean13.toInt());
  selectIdTrabajador.exec();

  idTrabajador = selectIdTrabajador.value(0).toInt();

  selectIdEntradaSalida.prepare("SELECT id_entrada_salida FROM trabajador_in_out WHERE id_trabajador_in_out = :idTrabajador ORDER BY timestamp DESC  LIMIT 1;") ;
  selectIdEntradaSalida.bindValue(":idTrabajador",idTrabajador);
  selectIdEntradaSalida.exec();
  if (selectIdEntradaSalida.size() < 1)
  {
      idEntradaSalida = 1;//1 == entrada , 2 == salida
       m_db.transaction();
      QSqlQuery insertQuery;
      QDateTime timestamp;
      insertQuery.prepare("INSERT INTO trabajador_in_out (id_entrada_salida,id_trabajador,time) VALUES (:id_entrada_salida, :id_trabajador, :time);");
      ///TODO: insertar los valores correspondientes
      insertQuery.bindValue(":id_entrada_salida",idEntradaSalida);
      insertQuery.bindValue(":id_trabajador",idTrabajador);
      timestamp = QDateTime::currentDateTime();
      insertQuery.bindValue(":time",timestamp.toString());
      bool commitOk = m_db.commit();
      return commitOk;
  }else{
      idEntradaSalida = selectIdEntradaSalida.value(0).toInt();

      //1 == entrada , 2 == salida

      if (idEntradaSalida == 1) {
        idEntradaSalida = 2;
      }else{
        idEntradaSalida = 1;
      }



      m_db.transaction();
      QSqlQuery insertQuery;
      QDateTime timestamp;
      insertQuery.prepare("INSERT INTO trabajador_in_out (id_entrada_salida,id_trabajador,timestamp) VALUES (:id_entrada_salida, :id_trabajador, :timestamp);");
      ///TODO: insertar los valores correspondientes
      insertQuery.bindValue(":id_entrada_salida",idEntradaSalida);
      insertQuery.bindValue(":id_trabajador",idTrabajador);
      timestamp = QDateTime::currentDateTime();
      insertQuery.bindValue(":timestamp",timestamp.toString());
      bool commitOk = m_db.commit();
      return commitOk;



  }



}

}

