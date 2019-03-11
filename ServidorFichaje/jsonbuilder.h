#ifndef JSONBUILDER_H
#define JSONBUILDER_H
#include <QString>

class JsonBuilder
{
public:
    JsonBuilder();
    void IniciarSessionOk(QString nombre, QString apellido, bool isCheckIn, QString hora);
    void IniciarSessionRejected();
    QString extraerEan13(QString jsonDocument);
};

#endif // JSONBUILDER_H
