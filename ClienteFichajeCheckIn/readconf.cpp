#include <iostream>
#include <QString>
#include <QTextStream>
#include <QFile>
#include <QDebug>

#include "readconf.h"

Readconf::Readconf()
{
    leerConfiguracion();
}
void Readconf::leerConfiguracion()
{
    QFile configuracion("configuracion.conf");
    if (configuracion.exists()) {
        if (configuracion.open(QIODevice::ReadOnly))
          {
            QTextStream in(&configuracion);
            while (!in.atEnd())
            {
                QString linea = in.readLine();

                if ( linea.contains(":")) {

                    QString indice = linea.split(":").at(0);
                    QString contenido = linea.split(":").at(1);

                     if (indice == "portWs") m_portWs = contenido;
                     if (indice == "host")   m_hostWs = contenido;


                  }
            }
            configuracion.close();
        }else{
        qDebug()<<"Error al abrir configuracion.conf";
        }

    }else{
        qDebug()<<"No existe el archivo configuracion.conf";
    }


}

