#include "app.h"

App::App():
    ///TODO: Crear un programa nuevo en qt para leer un archivo de
    /// Configuracion.
    m_webSocket{new WebSocket(3344) },
    m_baseDatos{new BaseDatos()},
    m_jsonBuilder{new JsonBuilder()}
{

}
