#include <QDebug>
#include <QTimer>
#include "websocket.h"

WebSocket::WebSocket( const QHostAddress ip, const quint16 port)
{
    ///Wait to main application exec loop
    QTimer::singleShot(0,this,SLOT(go()));
    ///Add to url the rigth address
    m_url.setScheme("ws");
    m_url.setHost(ip.toString());
    m_url.setPort(port);
}
WebSocket::~WebSocket()
{
 if (m_connected) disconnect();
 delete m_webSocket;
}
