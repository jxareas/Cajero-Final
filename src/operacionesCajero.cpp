#include <iostream>
#include <windows.h>
#include "operacionesCajero.h"
#include "menu.h"
#include "globals.h"
#include "tarjeta.h"
using namespace std;

void depositar()
{
    int opcion{};
    cout << "\n\n\n\t\t\t	///////////////////////////////////////////////////////////"<<endl;
    cout << "\n\t\t\t REALIZAR DEPOSITO " << endl;
    cout << "\n\t\t\tCuenta de usuario: " << usuario.tarjeta << endl;
    cout << "\t\t\t	///////////////////////////////////////////////////////////"<<endl;
    cout << "\t\t\t	|1. 1000 C$"<<"------------------|"<<"#Cnb81353"<<" |"<<endl;
    cout << "\t\t\t	|2. 2500 C$"<<"-----------------|"<<" |"<<endl;
    cout << "\t\t\t	|3. 5000 C$"<<"-----------------|"<<" |"<<endl;
    cout << "\t\t\t	|4. 10'000 C$"<<"--------------------|"<<" |"<<endl;
    cout << "\t\t\t	|5. 25'000 C$"<<"----------------------|"<<" |"<<endl;
    cout << "\t\t\t	|6. Salir al Menu de Opciones"<<"----------------------|"<<" |"<<endl;
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
            menuOpcion();
            break;
        default: cout << "\n\t\t Opcion Invalida. Por favor, intentelo de nuevo." << endl;
            depositar();
    }
    cout << "\n\t\t Se ha realizado el deposito de manera exitosa." << endl;
    menuOpcion();
}


void retirar() {
	 int opcion{};
	    cout << "\n\n\n\t\t\t	///////////////////////////////////////////////////////////"<<endl;
	    cout << "\n\t\t\t REALIZAR RETIRO " << endl;
	    cout << "\n\t\t\ttCuenta de usuario: " << usuario.tarjeta << endl;
	    cout << "\t\t\t	///////////////////////////////////////////////////////////"<<endl;
	    cout << "\t\t\t	|1. 1000 C$"<<"------------------|"<<"#Cnb81353"<<" |"<<endl;
	    cout << "\t\t\t	|2. 2500 C$"<<"-----------------|"<<" |"<<endl;
	    cout << "\t\t\t	|3. 5000 C$"<<"-----------------|"<<" |"<<endl;
	    cout << "\t\t\t	Opcion a seleccionar: ";
	    cin >> opcion;
	    switch (opcion)
	        {
	            case 1:
	                usuario.saldo -= 1000;
	                break;
	            case 2:
	                usuario.saldo -= 2000;
	                break;
	            case 3:
	                usuario.saldo -= 5000;
	                break;
	            default: cout << "\n\t\t Opcion Invalida. Por favor, intentelo de nuevo." << endl;
	            retirar();
	        }
	    cout << "\n\t\t Se ha realizado el deposito de manera exitosa." << endl;
	        menuOpcion();
}


void transferir()
{
    int opcion{};
    cout << "\n\t\t   Ingrese el numero de la tarjeta destino para depositar:" << endl;
    cin >> usuario.deposito.cuentaDestino;


    if (esTarjetaValida(usuario.deposito.cuentaDestino, usuario.deposito.cuentaDestino.length())) {
        cout << "\t\tIngrese el monto a depositar. El monto debe ser menos a 10,000 cordobas:" << endl;
        cin >> usuario.deposito.monto;
        if (usuario.deposito.monto > usuario.deposito.limite) {
            cout << "\t\tEl monto debe ser menor a " << usuario.deposito.limite << " C$." << endl;
            Sleep(1000);
            transferir();
        }
        else if (usuario.deposito.monto > usuario.saldo) {
            cout << "\n\t\tUsted no cuenta con los saldos suficientes para realizar esta transaccion. Presione 1 para intentarlo de nuevo." << endl;
            cout << "\t\tPresione otra tecla para salir del Menu de Transferencia." << endl;
            cout << "\t\t	Opcion a seleccionar: ";
            cin >> opcion;
            (opcion == 1) ? transferir() : menuOpcion();
        }
        else {
                Sleep(1000);
                usuario.saldo -= usuario.deposito.monto;
                cout << "Se ha realizado el deposito de manera exitosa." << endl;
                menuOpcion();
        }
    }
    else {
        cout << "\n\t\tNumero de tarjeta invalido. Presione 1 para intentarlo de nuevo." << endl;
        cout << "\t\tPresione otra tecla para salir del Menu de Transferencia." << endl;
        cout << "\t\t	Opcion a seleccionar: ";
        cin >> opcion;
        (opcion == 1) ? transferir() : menuOpcion();

    }
    }



void verEstadoCuenta()
{
    cout << "\n\n\n\t\t	///////////////////////////////////////////////////////////"<<endl;
    cout << "\n\t\t ESTADO DE CUENTA ACTUAL " << endl;
    cout << "\n\t\t	///////////////////////////////////////////////////////////"<<endl;
    cout << "\n\t\tNumero de Tarjeta: " << usuario.tarjeta << endl;
    cout << "\n\t\tCodigo NIP: " << usuario.NIP << endl;
    cout << "\n\t\tFecha de Expiracion: " << usuario.fechaExpiracion.mes << "/" << usuario.fechaExpiracion.anio << endl;
    cout << "\n\t\tSaldo Disponible: " << usuario.saldo;
    cout << "\n\t\t	///////////////////////////////////////////////////////////"<<endl;
    menuOpcion();
}

void cambiarPIN()
{
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
        cout << "\n\n\t\t\t\t\t-------------------ALERTA------------------" << endl;
        cout << "\t\t\t\t\t Se ha cambiado el PIN de manera exitosa" << endl;
        cout << "\t\t\t\t\t||-------------------------------------------||" << endl;
        menuOpcion();
    }
    else {
        cout << "\n\t\tNumero Pin invalido. Presione 1 para intentarlo de nuevo." << endl;
        cout << "\t\tPresione otra tecla para salir del Menu de Cambio de PIN.";
        cin >> opcion;
        (opcion == 1) ? cambiarPIN() : menuOpcion();
    }
}
