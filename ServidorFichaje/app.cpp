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
    this->isEan13Valid(ean13);
    ean13.remove(ean13.length());

    //TODO: validar ean13;

  m_baseDatos->checkInCheckOut(ean13);


}
bool App::isEan13Valid(QString ean13)
{
    int checkDigit;
    int sumForEach{0};
    int sumOdds{0};
 qDebug()<<ean13;
 //quitar el ultimo digito que es el de control y guardarlo para asegurarse que el checksum seaigual a este
 //pasos para el checksum
 //1.- sumar a cada uno de los digitos entre si
 //2.- sumar a cada impar ymultiplicarlo por 2
 //3.- sumar el resultado de 1 y 2
 //4.- restar el ultimo digito de la suma anterior(paso 3) a 10
 //5.- comprobar si es identico al substraido anteriormente
 //https://www.youtube.com/watch?v=Su3Bnzee-V4
 QVector<int> integerVector(13);
 for (int i = 0; i < integerVector.size(); ++i) {
   integerVector[i] = ean13[i].digitValue();
 }
checkDigit = integerVector[12];
integerVector.removeLast();
for (int i = 0; i < integerVector.size(); ++i) {

    sumForEach += integerVector[i];
     if (i % 2 == 0) {
           qDebug()<<"int odds "<< integerVector[i] <<"-.-";
         sumOdds += integerVector[i];

     }
}
sumOdds +=sumOdds;

qDebug()<<"sumodds: "<<sumOdds;//33*2
qDebug()<<"sumforeach: "<<sumForEach;//54
int result =sumForEach + sumOdds;
result = result % 10; //coje el ultimo digito
qDebug()<<"ultimo digito: "<<result;

result = 10 - result;
qDebug()<<"digito de control:"<<result;
}
