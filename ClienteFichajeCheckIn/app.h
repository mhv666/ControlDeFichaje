#ifndef APP_H
#define APP_H

#include "readconf.h"
#include "jsonbuilder.h"
#include "websocket.h"
class App:public QObject
{
    Q_OBJECT
public:
    App();
    Readconf     *m_configuracion = nullptr;
    WebSocket    *m_webSocket     = nullptr;
    JsonBuilder  *m_jsonBuilder   = nullptr;


};

#endif // APP_H
