#ifndef NODO_TERMINAL_DISPATCHER_H
#define NODO_TERMINAL_DISPATCHER_H
#include <iostream>

using namespace std;

class Dispatcher {
public:
    Dispatcher();
    void llenarDispatcher();
    string idRed[6];
    string idSalida[6];
    int dist[6];
};

#endif //NODO_TERMINAL_DISPATCHER_H