#include <QJsonObject>
#include "jsonbuilder.h"
#include "json.hpp"

using json = nlohmann::json;
JsonBuilder::JsonBuilder()
{

}
QString JsonBuilder::crearJsonChekcInOut(QString ean13)
{
//empleado{
//  ean13: codigo ean13
//}
//
    json document;
    json empleado;

empleado["ean13"]    =    ean13.toStdString();
document["session" ] =    empleado;

QString document_qstring = document.dump().c_str();
 return document_qstring;
}
