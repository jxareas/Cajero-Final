#include <windows.h>
#include <cstdlib>
#include <iostream>
#include "GUI.h"

#include "cajero.h"
#include "menu.h"

using namespace std;

void GUIreiniciar() {
    system("cls");
    system("color 0f");
}

void GUImsgError() {
    system("cls");
    system("color 0c");
}

void GUImsgExito() {
    system("cls");
    system("color 0a");
}

void GUIaccesoConcedido()
{
    GUImsgExito();
    cout << "\n\n\t\t\t\t\t----------------------ALERTA------------------" << endl;
    cout << "\n\t\t\t\t\t\t\t ACCESO CONCEDIDO." << endl;
    cout << "\t\t\t\t\t||-------------------------------------------||" << endl;
    Sleep(1500);
    menuPrincipal();
}

void GUIaccesoDenegado()
{
    GUImsgError();
    cout << "\n\n\t\t\t\t\t----------------------ALERTA------------------" << endl;
    cout << "\n\t\t\t\t\t\t\t ACCESO DENEGADO." << endl;
    cout << "\t\t\t\t\t||-------------------------------------------||" << endl;
    Sleep(1500);
}

void GUIopcionInvalida() {
    GUImsgError();
    cout << "\n\n\t\t\t\t\t-------------------ALERTA------------------" << endl;
    cout << "\t\t\t\t\t Opcion Invalida. Por favor, intentelo de nuevo." << endl;
    cout << "\t\t\t\t\t||-------------------------------------------||" << endl;
    Sleep(2000);
}

void GUIlimiteExcedido(int limite) {
    GUImsgError();
    cout << "\n\n\t\t\t\t\t-------------------ALERTA------------------" << endl;
    cout << "\t\t\t\t\t El monto debe ser menor o igual a " << limite << endl;
    cout << "\t\t\t\t\t||-------------------------------------------||" << endl;
    Sleep(2000);
}

void GUIsaldoInsuficiente() {
    GUImsgError();
    cout << "\n\n\t\t\t\t\t-------------------ALERTA------------------" << endl;
    cout << "\t\t\t\t\t Usted no tiene saldo suficiente para realizar esta operacion." << endl;
    cout << "\t\t\t\t\t||-------------------------------------------||" << endl;
    Sleep(2000);
}

void GUItarjetaInvalida() {
    GUImsgError();
    cout << "\n\n\t\t\t\t\t-------------------ALERTA------------------" << endl;
    cout << "\t\t\t\t\t La tarjeta del destinatario es invalida." << endl;
    cout << "\t\t\t\t\t||-------------------------------------------||" << endl;
    Sleep(2000);
    transferir();
}

void GUIoperacionExitosa() {
    GUImsgExito();
    cout << "\n\n\t\t\t\t\t-------------------ALERTA------------------" << endl;
    cout << "\t\t\t\t\t Se ha realizado la operacion de manera exitosa." << endl;
    cout << "\t\t\t\t\t||-------------------------------------------||" << endl;
    Sleep(2000);
    menuPrincipal();
}

void GUIsaldoNegativo() {
    GUImsgError();
    cout << "\n\n\t\t\t\t\t--------------------ERROR------------------" << endl;
    cout << "\t\t\t\t\t   El saldo ingresado NO puede ser negativo." << endl;
    cout << "\t\t\t\t\t||-------------------------------------------||" << endl;
    Sleep(1000);
    menuPrincipal();
}

void GUIpinInvalido() {

    GUImsgError();
    cout << "\n\n\t\t\t\t\t--------------------ALERTA------------------" << endl;
    cout << "\t\t\t\t\t\t      NUMERO PIN INVALIDO" << endl;
    cout << "\t\t\t\t\t||-------------------------------------------||" << endl;
    Sleep(1000);
}

