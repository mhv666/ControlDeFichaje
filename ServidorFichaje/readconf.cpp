#include <iostream>
#include <QString>
#include <QTextStream>
#include <QFile>
#include <QDebug>
#include "readconf.h"
ReadConf::ReadConf()
{
 leerConfiguracion();
}

void ReadConf::leerConfiguracion()
{

QFile configuracion("configuracion.conf");

    if (configuracion.exists()) {

        if (configuracion.open(QIODevice::ReadOnly))
          {
            QTextStream in(&configuracion);
            while (!in.atEnd())
            {
              QString indice = in.readLine().split(":").at(0);
              QString contenido = in.readLine().split(":").at(1);
               if (indice == "host") m_host = contenido ;
               if (indice == "port") m_port = contenido ;
               if (indice == "baseDatos") m_nombreBaseDatos = contenido ;
               if (indice == "usuario") m_nombreUsuario = contenido ;
               if (indice == "passUsuario") m_passUsuario = contenido ;
               if (indice == "portWs") m_portWs = contenido;
            }
            configuracion.close();
        }else{
        qDebug()<<"Error al abrir configuracion.conf";
        }

    }else{
        qDebug()<<"No existe el archivo configuracion.conf";
    }
}
