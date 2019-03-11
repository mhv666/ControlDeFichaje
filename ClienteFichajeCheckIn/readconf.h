#ifndef READCONF_H
#define READCONF_H
#include <QString>
#include <QHostAddress>

class Readconf
{
public:
    void leerConfiguracion();
    QString m_portWs{};
    QHostAddress m_hostWs{};
    Readconf();
};

#endif // READCONF_H
