#ifndef BASEDATOS_H
#define BASEDATOS_H
#include <QSqlQuery>

class BaseDatos
{
public:
    BaseDatos(QString hostname,int port, QString database,QString user,QString pass );
    void connectDatabase(QString hostname,int port, QString database,QString user,QString pass);
private:
    QSqlDatabase mdb  ;
    QString m_hostName;
    int     m_port    ;
    QString m_dataBase;
    QString m_user    ;
    QString m_pass    ;
};

#endif // BASEDATOS_H
