#include <iostream>
#include <thread>
#include "Server.h"
#include "Client.h"
#include <string>

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

    cout << "Nodo terminal Luces" << endl << endl;
    cout << "Desea enviar un mensaje? 1 => Si, 0 => No: ";
    int opcion;
    cin >> opcion;

    if (opcion == 0) {
        cout << "No se enviarán mensajes." << endl << endl;
    } else {
        bool seguir = true;
        while (seguir) {
            string red;
            char mensaje[256];
            auto *c = new Client();

            cout << endl << "A cual red desea enviar un mensaje?: ";
            cin >> red;
            cin.ignore();
            cout << endl << "Cual es el mensaje?: ";
            cin.getline(mensaje, 255);

            string paquete = "25.0.2.5\n";
            paquete += red;
            paquete += "\nIntercambio de Mensajes\n1\n";
            paquete += mensaje;
            paquete += "\n";

            c->prepararMensaje(red, paquete);

            cout << "Desea enviar otro mensaje? 1 => Si, 0 => No: ";
            cin >> opcion;

            if (opcion == 0) {
                seguir = false;
                cout << "No se enviarán mensajes." << endl << endl;
            }
        }
    }

    hiloC.join();
    hiloL.join();
    return 0;
}