#ifndef NODO_TERMINAL_MENSAJE_H
#define NODO_TERMINAL_MENSAJE_H
#include <vector>
#include <string>

using namespace std;

class Mensaje {
public:
    Mensaje();

    void setPaquete(string);

    string getPaquete();
    vector<string> obtenerInfo();

private:
    //ipFuente
    //ipDestino
    //accion
    //idAccion
    //mensaje
    string paq;
};

#endif //NODO_TERMINAL_MENSAJE_H