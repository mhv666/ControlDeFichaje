#include "app.h"

App::App(): 
    m_configuracion{new ReadConf()},
    m_webSocket{new WebSocket(m_configuracion->m_portWs.toInt()) },
    m_baseDatos{new BaseDatos(m_configuracion->m_host,m_configuracion->m_port.toInt(),m_configuracion->m_nombreBaseDatos,m_configuracion->m_nombreUsuario,m_configuracion->m_passUsuario)},
    m_jsonBuilder{new JsonBuilder()}
{
    connect(m_webSocket,&WebSocket::sendDatosUsuario,this , &App::recibirDatosUsuario);
    QString nombre = "marti";
    QString apellido ="h";
    bool ok = true;
    QString hora ="12pm";
    m_jsonBuilder->IniciarSessionOk(nombre,apellido,ok,hora);

}


void App::recibirDatosUsuario(DatosCliente datos)
{
    //TODO: sacar el ean13 del documento json y pasarlo al checkInCheckOut(Qstring ean13)

    QString ean13;

    ean13 = m_jsonBuilder->extraerEan13(datos.mensaje);
    qDebug()<<"gbhtbhth"<< ean13.toInt();
    //TODO: validar ean13;

  m_baseDatos->checkInCheckOut(ean13);


}

