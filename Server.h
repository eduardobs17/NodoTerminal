#ifndef NODO_TERMINAL_SERVER_H
#define NODO_TERMINAL_SERVER_H
#include <string>
#include "Mensaje.h"

class Server {
public:
    explicit Server(int);
    void analizarPaquete(int, int);
    void error(const char*);
    void socketS(int);

private:
    int portno;
    Mensaje* msj;
};

#endif //NODO_TERMINAL_SERVER_H
