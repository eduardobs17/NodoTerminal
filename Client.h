#ifndef NODO_TERMINAL_CLIENT_H
#define NODO_TERMINAL_CLIENT_H
#include <string>
#include "Dispatcher.h"

using namespace std;

class Client {
public:
    Client();
    void error(const char*);
    int socketC(char*, char*, string);
    void prepararMensaje(string, string);

private:
    Dispatcher* d;
    char* ipCarritos;
    char* ipLegos;
    char* portLegos;
    char* portCarritos;
};

#endif //NODO_TERMINAL_CLIENT_H