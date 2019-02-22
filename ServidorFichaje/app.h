#ifndef APP_H
#define APP_H
#include "basedatos.h"
#include "websocket.h"
#include "jsonbuilder.h"

class App
{
public:
    App();
    BaseDatos    *m_baseDatos   = nullptr;
    WebSocket    *m_webSocket   = nullptr;
    JsonBuilder  *m_jsonBuilder = nullptr;

};

#endif // APP_H
