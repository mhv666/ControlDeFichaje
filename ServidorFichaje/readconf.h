#ifndef READCONF_H
#define READCONF_H
#include <QString>

class ReadConf
{
public:
    void leerConfiguracion();
    QString m_host{};
    QString m_port{};
    QString m_nombreBaseDatos{};
    QString m_nombreUsuario{};
    QString m_passUsuario{};
    QString m_portWs{};
    ReadConf();
};

#endif // READCONF_H
