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
void WebSocket::go()
{
    m_webSocket = new QWebSocket();
        connect(m_webSocket, SIGNAL(connected()),this,SLOT(connected()));
        connect(m_webSocket, SIGNAL(disconnected()),this,SLOT(disconnected()));
        connect(m_webSocket, SIGNAL(textMessageReceived(QString)),this,SLOT(reciveMessage(QString)));

    m_webSocket->open(m_url);
}
void WebSocket::connected()
{


}
void WebSocket::disconnected()
{

}
void WebSocket::sendMessage(QString message)
{

    m_webSocket->sendTextMessage(message);

}
void WebSocket::reciveMessage(QString message)
{

}
