#include <QDebug>

#include <QJsonObject>
#include "json.hpp"
#include "jsonbuilder.h"

using json = nlohmann::json;
JsonBuilder::JsonBuilder()
{

}


void JsonBuilder::IniciarSessionOk(QString nombre,QString apellido, bool isCheckIn, QString hora)
{
json document;
json empleado;

QString mensaje = "Hola " + nombre + " " + apellido + "bienvenido ha" + (isCheckIn ? "entrado" :"salido") + " a las: "+hora ;
empleado["Nombre"]    =    nombre.toStdString();
empleado["Apellidos"] =  apellido.toStdString();
empleado["Mensaje"]   =   mensaje.toStdString();

document["session"]= empleado;

qDebug()<<document.dump().c_str();

}

void JsonBuilder::IniciarSessionRejected()
{
    json document;
    json empleado;

    QString mensaje = "Usuario o password no reconocido " ;
    empleado["Mensaje"]   =   mensaje.toStdString();

    document["session"]= empleado;

    qDebug()<<document.dump().c_str();
}
