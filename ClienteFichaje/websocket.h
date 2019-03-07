#ifndef WEBSOCKET_H
#define WEBSOCKET_H

#include <QtCore/QObject>
#include <QtWebSockets/QWebSocket>
#include <QObject>

class QWebSocket;

class WebSocket : public QObject
{
    Q_OBJECT
private:
    QWebSocket * m_webSocket;
    QUrl  m_url;
    bool m_connected;

public:
    explicit WebSocket(const QHostAddress ip, const quint16 port);
    ~WebSocket();
    void sendMessage(QString message);

signals:
    void proccesMessage(QString message);
     void closed();

public slots:
      void go();
      void connected();
      void disconnected();
      void recivMessage(QString message);

};

#endif // WEBSOCKET_H
