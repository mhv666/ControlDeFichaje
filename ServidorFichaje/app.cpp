#include "app.h"

App::App(): 
    m_configuracion{new ReadConf()},
    m_webSocket{new WebSocket(m_configuracion->m_portWs.toInt()) },
    m_baseDatos{new BaseDatos(m_configuracion->m_host,m_configuracion->m_port.toInt(),m_configuracion->m_nombreBaseDatos,m_configuracion->m_nombreUsuario,m_configuracion->m_passUsuario)},
    m_jsonBuilder{new JsonBuilder()}
{
    connect(m_webSocket,&WebSocket::sendDatosUsuario,this , &App::recibirDatosUsuario);



}


void App::recibirDatosUsuario(DatosCliente datos)
{

}

