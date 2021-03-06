#include <QDebug>
#include <QString>
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

QString document_qstring = document.dump().c_str();
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

QString JsonBuilder::extraerEan13(QString jsonDocument)
{
json parsedJson = json::parse(jsonDocument.toStdString());
qDebug() << parsedJson.dump().c_str();


json session = parsedJson["session"];
json ean13  = session["ean13"];

QString ean13Value{ean13.get<std::string>().c_str()};

    return ean13Value;

}
