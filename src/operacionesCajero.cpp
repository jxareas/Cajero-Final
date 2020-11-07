#include <iostream>
#include <windows.h>
#include "operacionesCajero.h"
#include "menu.h"
#include "globals.h"
#include "tarjeta.h"
#include "GUI.h"

using namespace std;

void esTransaccionValida(int monto, int limite) {
    if (monto < 0) {
        GUIsaldoNegativo();
    } else if (monto > limite) {
        GUIlimiteExcedido(limite);
        menuPrincipal();
    } else if (monto > usuarios[ind].saldo) {
        GUIsaldoInsuficiente();
        menuPrincipal();
    } else {
        usuarios[ind].saldo -= monto;
        GUIoperacionExitosa();
    }
}

void depositar() {
    int opcion{};
    GUIreiniciar();
    cout << "\n\n\n\t\t\t	///////////////////////////////////////////////////////////" << endl;
    cout << "\t\t\t\t\t\t REALIZAR DEPOSITO " << endl;
    cout << "\t\t\t	///////////////////////////////////////////////////////////" << endl;
    cout << "\t\t\t	|1. 1000 C$" << "------------------|" << "#Cnb81353" << " |" << endl;
    cout << "\t\t\t	|2. 2500 C$" << "-----------------|" << " |" << endl;
    cout << "\t\t\t	|3. 5000 C$" << "-----------------|" << " |" << endl;
    cout << "\t\t\t	|4. 10'000 C$" << "--------------------|" << " |" << endl;
    cout << "\t\t\t	|5. 25'000 C$" << "----------------------|" << " |" << endl;
    cout << "\t\t\t	|6. Salir al Menu de Opciones" << "----------------------|" << " |" << endl;
    cout << "\n\t\t\t	///////////////////////////////////////////////////////////" << endl;
    cout << "\t\t\t	Opcion a seleccionar: ";
    cin >> opcion;
    switch (opcion) {
        case 1:
            usuarios[ind].saldo += 1000;
            break;
        case 2:
            usuarios[ind].saldo += 2000;
            break;
        case 3:
            usuarios[ind].saldo += 5000;
            break;
        case 4:
            usuarios[ind].saldo += 10000;
            break;
        case 5:
            usuarios[ind].saldo += 25000;
            break;
        case 6:
            menuAuxiliar();
            break;
        default:
            GUIopcionInvalida();
            depositar();
    }
    GUIoperacionExitosa();
}


void retirar() {
    GUIreiniciar();
    cout << "\t\t\t LIMITE DE TRANSFERENCIA: " << usuarios[ind].retiro.limite << endl;
    cout << "\t\t\t Ingrese la cantidad a retirar: ";
    cin >> usuarios[ind].retiro.monto;
    esTransaccionValida(usuarios[ind].retiro.monto, usuarios[ind].retiro.limite);
}


void transferir() {
    GUIreiniciar();
    cout << "\t\t\t LIMITE DE TRANSFERENCIA: " << usuarios[ind].transferencia.limite << endl;
    cout << "\t\t\t Ingrese la tarjeta del usuario a transferir: ";
    cin >> usuarios[ind].transferencia.cuentaDestino;
    if (usuarios[ind].transferencia.cuentaDestino == usuarios[ind].tarjeta) {
        GUItarjetaInvalida();
    }
    cout << "\t\t\t Ingrese la cantidad a transferir: ";
    cin >> usuarios[ind].transferencia.monto;

    if (esTarjetaValida(usuarios[ind].transferencia.cuentaDestino,
                        usuarios[ind].transferencia.cuentaDestino.length())) {
        esTransaccionValida(usuarios[ind].transferencia.monto, usuarios[ind].transferencia.limite);
    } else {
        GUItarjetaInvalida();
    }
}


void verEstadoCuenta() {
    GUIreiniciar();
    cout << "\n\n\n\t\t\t	///////////////////////////////////////////////////////////" << endl;
    cout << "\t\t\t\t\t\t ESTADO DE CUENTA " << endl;
    cout << "\n\n\n\t\t\t	///////////////////////////////////////////////////////////" << endl;
    cout << "\n\t\t\t\t Numero de tarjeta: " << usuarios[ind].tarjeta << endl;
    cout << "\n\t\t\t\t Fecha de Expiracion: " << usuarios[ind].fechaExpiracion.mes << "/"
         << usuarios[ind].fechaExpiracion.anio
         << endl;
    cout << "\n\t\t\t\t Saldo Disponible: " << usuarios[ind].saldo << endl;
    cout << "\n\t\t\t\t Codigo NIP: " << usuarios[ind].NIP << endl;
    cout << "\n\t\t\t	///////////////////////////////////////////////////////////" << endl;
    system("pause");
    menuPrincipal();
}

void cambiarPIN() {
    GUIreiniciar();
    int numeroPin{}, opcion{};
    cout << "\n\n\n\t\t\t	///////////////////////////////////////////////////////////" << endl;
    cout << "\t\t\t\t\t\t CAMBIO DE NUMERO PIN " << endl;
    cout << "\t\t\t\t\t Cuenta de usuario: " << usuarios[ind].tarjeta << endl;
    cout << "\n\t\t\t	///////////////////////////////////////////////////////////" << endl;
    cout << "\n\t\t\t\t Estimado usuario, por favor digite su numero PIN." << endl;
    cout << "\n\t\t\t\t Codigo NIP a cambiar: ";
    cin >> numeroPin;
    if (numeroPin == PIN[ind]) {
        cout << "\n\t\t\t\tIntroduzca su nuevo codigo NIP: ";
        cin >> PIN[ind];
        usuarios[ind].NIP = PIN[ind];
        Sleep(1000);
        GUIoperacionExitosa();
    } else {
        GUIpinInvalido();
        cout << "\n\t\t\t\t\t Presione '1' para intentarlo de nuevo." << endl;
        cout << "\n\t\t\t\t\t Presione otra tecla para llamar al menu auxiliar." << endl;
        cout << "\t\t\t\t\t	Opcion a seleccionar: ";
        fflush(stdin);
        cin >> opcion;
        (opcion == 1) ? cambiarPIN() : menuAuxiliar();
    }
}
