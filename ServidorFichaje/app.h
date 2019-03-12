#ifndef APP_H
#define APP_H
#include <QtCore/QObject>
#include <QtCore/QList>
#include <QtCore/QByteArray>
#include "basedatos.h"
#include "websocket.h"
#include "jsonbuilder.h"
#include "readconf.h"
class App:public QObject
{
    Q_OBJECT
public:
    App();
    ReadConf     *m_configuracion = nullptr;
    BaseDatos    *m_baseDatos     = nullptr;
    WebSocket    *m_webSocket     = nullptr;
    JsonBuilder  *m_jsonBuilder   = nullptr;
    bool isEan13Valid(QString ean13);
public slots:
    void recibirDatosUsuario(DatosCliente datos);
};

#endif // APP_H
