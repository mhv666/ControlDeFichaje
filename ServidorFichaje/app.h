#ifndef APP_H
#define APP_H
#include "basedatos.h"
#include "websocket.h"
#include "jsonbuilder.h"
#include "readconf.h"
class App
{
public:
    App();
    ReadConf     *m_configuracion = nullptr;
    BaseDatos    *m_baseDatos   = nullptr;
    WebSocket    *m_webSocket   = nullptr;
    JsonBuilder  *m_jsonBuilder = nullptr;

};

#endif // APP_H
