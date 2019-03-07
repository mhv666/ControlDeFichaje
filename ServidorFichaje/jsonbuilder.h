#ifndef JSONBUILDER_H
#define JSONBUILDER_H


class JsonBuilder
{
public:
    JsonBuilder();
    void IniciarSessionOk(QString nombre, QString apellido, bool isCheckIn, QString hora);
    void IniciarSessionRejected();

};

#endif // JSONBUILDER_H
