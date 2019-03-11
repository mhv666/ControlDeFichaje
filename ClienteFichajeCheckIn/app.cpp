#include "app.h"

App::App():
    m_configuracion{new Readconf()},
    m_webSocket{new WebSocket(m_configuracion->m_hostWs,m_configuracion->m_portWs.toInt())},
    m_jsonBuilder{new JsonBuilder()}
{


}
