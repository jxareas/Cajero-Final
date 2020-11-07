#include <iostream>
#include <windows.h>
#include <ctype.h>
#include "operacionesCajero.h"
#include "menu.h"
#include "globals.h"
#include "tarjeta.h"
#include "GUI.h"
using namespace std;

void depositar()
{
    int opcion{};
    GUIreiniciar();
    cout << "\n\n\n\t\t\t	///////////////////////////////////////////////////////////"<<endl;
    cout << "\t\t\t\t\t\t REALIZAR DEPOSITO " << endl;
    cout << "\t\t\t	///////////////////////////////////////////////////////////"<<endl;
    cout << "\t\t\t	|1. 1000 C$"<<"------------------|"<<"#Cnb81353"<<" |"<<endl;
    cout << "\t\t\t	|2. 2500 C$"<<"-----------------|"<<" |"<<endl;
    cout << "\t\t\t	|3. 5000 C$"<<"-----------------|"<<" |"<<endl;
    cout << "\t\t\t	|4. 10'000 C$"<<"--------------------|"<<" |"<<endl;
    cout << "\t\t\t	|5. 25'000 C$"<<"----------------------|"<<" |"<<endl;
    cout << "\t\t\t	|6. Salir al Menu de Opciones"<<"----------------------|"<<" |"<<endl;
    cout << "\n\t\t\t	///////////////////////////////////////////////////////////"<<endl;
    cout << "\t\t\t	Opcion a seleccionar: ";
    cin >> opcion;
    switch (opcion)
    {
        case 1:
            usuario.saldo += 1000;
            break;
        case 2:
            usuario.saldo += 2000;
            break;
        case 3:
            usuario.saldo += 5000;
            break;
        case 4:
            usuario.saldo += 10000;
            break;
        case 5:
            usuario.saldo += 25000;
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


void retirar()
{
	GUIreiniciar();
	cout << "\t\t\t Ingrese la cantidad a retirar: ";
	cin >> usuario.retiro.monto;
	if (usuario.retiro.monto > usuario.retiro.limite) {
				GUIlimiteExcedido(usuario.retiro.limite);
	            retirar();
	        }
	        else if (usuario.retiro.monto > usuario.saldo) {
	            GUIsaldoInsuficiente();
	            retirar();
	        }
	        else {
	                usuario.saldo -= usuario.retiro.monto;
	                GUIoperacionExitosa();
	        }

}


void transferir()
{
	GUIreiniciar();
	cout << "\t\t\t Ingrese la tarjeta del usuario a transferir: ";
		cin >> usuario.transferencia.cuentaDestino;
		cout << "\t\t\t Ingrese la cantidad a transferir: ";
		cin >> usuario.transferencia.monto;

		if (esTarjetaValida(usuario.transferencia.cuentaDestino, usuario.transferencia.cuentaDestino.length()))
		{
			if (usuario.transferencia.monto > usuario.transferencia.limite) {
							GUIlimiteExcedido(usuario.transferencia.limite);
				            transferir();
				        }
				        else if (usuario.transferencia.monto > usuario.saldo) {
				            GUIsaldoInsuficiente();
				            transferir();
				        }
				        else {
				                usuario.saldo -= usuario.transferencia.monto;
				                GUIoperacionExitosa();
				        }
		} else {
			GUItarjetaInvalida();
			transferir();
		}
}




void verEstadoCuenta()
{
	GUIreiniciar();
	cout << "\n\n\n\t\t\t	///////////////////////////////////////////////////////////"<<endl;
	cout << "\t\t\t\t\t\t ESTADO DE CUENTA " << endl;
	cout << "\n\n\n\t\t\t	///////////////////////////////////////////////////////////"<<endl;
	cout << "\n\t\t\t\t Numero de tarjeta: " << usuario.tarjeta << endl;
	cout << "\n\t\t\t\t Fecha de Expiracion: " << usuario.fechaExpiracion.mes << "/" << usuario.fechaExpiracion.anio << endl;
	cout << "\n\t\t\t\t Saldo Disponible: " << usuario.saldo << endl;
	cout << "\n\t\t\t\t Codigo NIP: " << usuario.NIP << endl;
	cout << "\n\t\t\t	///////////////////////////////////////////////////////////"<<endl;
    system("pause");
    menuAuxiliar();
}

void cambiarPIN()
{
	GUIreiniciar();
    int numeroPin{}, opcion{};
    cout << "\n\n\n\t\t\t	///////////////////////////////////////////////////////////"<<endl;
    cout << "\t\t\t\t\t\t CAMBIO DE NUMERO PIN " << endl;
    cout << "\t\t\t\t\t Cuenta de usuario: " << usuario.tarjeta << endl;
    cout << "\n\t\t\t	///////////////////////////////////////////////////////////"<<endl;
    cout << "\n\t\t\t\t Estimado usuario, por favor digite su numero PIN." << endl;
    cout << "\n\t\t\t\t Codigo NIP a cambiar: ";
    cin >> numeroPin;
    if (numeroPin == PIN)
    {
        cout << "\n\t\t\t\tIntroduzca su nuevo codigo NIP: ";
        cin >> PIN;
        usuario.NIP = PIN;
        Sleep(1000);
        GUIoperacionExitosa();
    }
    else {
    	GUIpinInvalido();
    	cout << "\n\t\t\t\t\t Presione '1' para intentarlo de nuevo." << endl;
    	cout << "\n\t\t\t\t\t Presione otra tecla para llamar al menu auxiliar." << endl;
    	cout << "\t\t\t\t\t	Opcion a seleccionar: ";
        fflush(stdin);
        cin >> opcion;
        (opcion == 1) ? cambiarPIN() : menuAuxiliar();
    }
}
