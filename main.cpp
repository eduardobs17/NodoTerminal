#include <iostream>
#include <thread>
#include "Server.h"
#include "Client.h"

using namespace std;

//Puertos
//RouterCarritos recibe de Terminal en 2001
//RouterLegos recibe de Terminal en 2002
//Terminal recibe de RouterCarritos en 2000
//Terminal recibe de RouterLegos en 2003

void interfazLC() {
    auto * sL = new Server(2000);
    sL->socketS(1);
}

void interfazLL() {
    auto * sC = new Server(2003);
    sC->socketS(1);
}

int main() {
    cout << endl;

    thread hiloL(interfazLC);
    thread hiloC(interfazLL);

    cout << "Router Luces - Carritos" << endl << endl;
    cout << "Desea enviar un mensaje? 1 => Si, 0 => No: ";
    int opcion;
    cin >> opcion;

    if (opcion == 0) {
        cout << "No se enviarán mensajes." << endl;
    } else {
        bool seguir = true;
        while (seguir) {
            string red;
            string mensaje;
            auto *c = new Client();

            cout << endl << "A cual red desea enviar un mensaje?: ";
            cin >> red;
            cout << endl << "Cual es el mensaje?: ";
            cin >> mensaje;

            c->prepararMensaje(red, mensaje);

            cout << "Desea enviar otro mensaje? 1 => Si, 0 => No: ";
            cin >> opcion;

            if (opcion == 0) {
                seguir = false;
                cout << "No se enviarán mensajes." << endl;
            }
        }
    }

    hiloC.join();
    hiloL.join();
    return 0;
}