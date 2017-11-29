#include "Mensaje.h"
#include <sstream>
#include <utility>

using namespace std;

/** Constructor. */
Mensaje::Mensaje() {
    paq = "";
    contenido = "";
}

/** Agrega la IP fuente al mensaje. */
void Mensaje::setDirFuente(string ipFuente) {
    paq += ipFuente;
    paq += "\n"; //caracter de division
}

/** Agrega la IP destino al mensaje. */
void Mensaje::setDirDestino(string ipDestino) {
    paq += ipDestino;
    paq += "\n"; //caracter de division
}

/** Agrega la acción realizada al mensaje. */
void Mensaje::setAccion(string accion) {
    paq += accion;
    paq += "\n"; //caracter de division
}

/** Agrega el id de la acción al mensaje. */
void Mensaje::setIdAccion(int id) {
    ostringstream streamAux;
    streamAux << id;
    string aux = streamAux.str();

    paq += aux;
    paq += "\n"; //caracter de division
}

/** Agrega el mensaje que se desea transmitir. */
void Mensaje::setMensaje(string msg) {
    contenido = msg;
    paq += msg;
    paq += '\n';
}

/**
 * Establece el paquete del mensaje.
 * @param p El paquete
 */
void Mensaje::setPaquete(string p) {
    paq = std::move(p);
}

/** Divide la información del paquete. */
vector<string> Mensaje::obtenerInfo() {
    vector<string> info;
    int counter = 0;
    string aux;

    for (char x : paq) {
        if (x != '\n' && x != '\000') {
            aux += x;
        } else {
            info.push_back(aux);
            aux = "";
            counter++;
        }
    }

    return info;
}

/** Retorna el paquete completo, es decir, lo que se va a transmitir a otras redes. */
string Mensaje::getPaquete() {
    return paq;
}