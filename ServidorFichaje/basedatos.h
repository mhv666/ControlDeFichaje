#ifndef BASEDATOS_H
#define BASEDATOS_H
#include <QSqlQuery>

class BaseDatos
{
public:
    BaseDatos();
    void connectDatabase();
private:
    QSqlDatabase mdb;
};

#endif // BASEDATOS_H
