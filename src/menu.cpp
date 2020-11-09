#include <iostream>
#include <windows.h>
#include <cstdlib>
#include "menu.h"

#include "cajero.h"
#include "globales.h"
#include "tarjeta.h"
#include "GUI.h"

using namespace std;

void iniciarPrograma() {

    Sleep(1500);
    GUIreiniciar();
    cout << "\n\t\t\t\t\t\tIniciando el programa. Por favor, espere....." << endl;
    cout << "\n\t\t\t\t\t\tCargando....." << endl;
    Sleep(1500);


}

void salirPrograma() {
    Sleep(1000);
    GUImsgExito();
    cout << "\t\t\t\t\tSaliendo del programa..." << endl;
    Sleep(2000);
    system("cls");
    cerr << "\n\n\t\t\t\t\t||---------------------ALERTA--------------------||" << endl;
    cerr << "\n\t\t\t\t\tSe ha salido del programa de manera exitosa. " << endl;
    cerr << "\t\t\t\t\t||-----------------------------------------------||" << endl;
    Sleep(8000);
    exit(0);
}

void cerrarPrograma() {
    GUImsgError();
    Sleep(1000);
    cerr << "\n\n\t\t\t\t\t||---------------------ALERTA--------------------||" << endl;
    cerr << "\n\t\t\t\t\tSe ha excedido el numero de intentos (3). " << endl;
    cerr << "\n\t\t\t\t\tSe ha cerrado el programa por motivos de seguridad." << endl;
    cerr << "\t\t\t\t\t||-----------------------------------------------||" << endl;
    Sleep(8000);
    exit(0);
}


void menuInicio() {
    GUIreiniciar();
    if (intentos == 0)
    	cerrarPrograma();
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t||-------------------------------------------||" << endl;
    cout << "\t\t\t\t\t||             CAJERO AUTOMATICO             ||" << endl;
    cout << "\t\t\t\t\t||-------------------------------------------||";
    cout << "\n\t\t\t\t\t||\t      INICIO DE SESION  \t     ||" << endl;
    cout << "\t\t\t\t\t||-------------------------------------------||" << endl;
    cout << "\t\t\t\t\tEstimado cliente, favor introduzca los siguientes datos. " << endl;
    cout << "\n\t\t\t\t\tNumero de tarjeta de credito: ";
    cin >> usuarios[ind].tarjeta;
    cout << "\n\t\t\t\t\tMes de Expiracion: ";
    fflush(stdin);
    cin >> usuarios[ind].fechaExpiracion.mes;
    cout << "\n\t\t\t\t\tAnio de Expiracion: ";
    fflush(stdin);
    cin >> usuarios[ind].fechaExpiracion.anio;
    cout << "\n\t\t\t\t\tCodigo PIN: ";
    cin >> usuarios[ind].NIP;
    ind = asignarIndice();


    if (esRegistroValido(usuarios[ind].tarjeta, usuarios[ind].fechaExpiracion.mes, usuarios[ind].fechaExpiracion.anio,
                         usuarios[ind].NIP)) {
    	GUIaccesoConcedido();
    }
    else {
    	intentos--;
    	GUIaccesoDenegado();
    	menuInicio();
    }
}


void menuPrincipal() {
    Sleep(1000);
    GUIreiniciar();
    int opcion{};
    cout << "\n\t\t\t	///////////////////////////////////////////////////////////" << endl;
    cout << "\t\t\t\t                      CAJERO AUTOMATICO                " << endl;
    cout << "\t\t\t	///////////////////////////////////////////////////////////" << endl;
    cout << "\t\t\t	|1. Depositar Dinero " << "------------------|" << "#Cnb81353" << " |" << endl;
    cout << "\t\t\t	|2. Retirar Dinero " << "-----------------|" << " |" << endl;
    cout << "\t\t\t	|3. Realizar Transferencia " << "-----------------|" << " |" << endl;
    cout << "\t\t\t	|4. Ver Estado de Cuenta " << "--------------------|" << " |" << endl;
    cout << "\t\t\t	|5. Cambiar Numero NIP " << "----------------------|" << " |" << endl;
    cout << "\t\t\t	|6. Volver al menu de Inicio de Sesion " << "----------------------|" << " |" << endl;
    cout << "\t\t\t	|7. Salir del Programa " << "----------------------|" << " |" << endl;
    cout << "\t\t\t	 ________________________________________________________" << endl;
    cout << "\n";
    cout << "\t\t\t	| Ubicacion: " << "-------|" << " Managua, Nicaragua |" << endl;
    cout << "\t\t\t	 ________________________________________________________" << endl;
    cout << "\t\t\t	| Por favor, seleccione la opcion del menu que se ajuste |" << endl;
    cout << "\t\t\t	| a sus necesidades." << endl;
    cout << " " << endl;
    cout << "\t\t\t	///////////////////////////////////////////////////////////" << endl;
    cout << "\t\t\t	| # Este es un menu generado por computadora y las transacciones |" << endl;
    cout << "\t\t\t	| no requieren una firma autorizada #" << endl;
    cout << "\t\t\t	///////////////////////////////////////////////////////////" << endl;
    cout << "\t\t\t	Opcion a seleccionar: ";
    fflush(stdin);
    cin >> opcion;
    switch (opcion) {
        case 1:
            depositar();
            break;
        case 2:
            retirar();
            break;
        case 3:
            transferir();
            break;
        case 4:
            verEstadoCuenta();
            break;
        case 5:
            cambiarPIN();
            break;
        case 6:
            ind = (ind < 5) ? ind + 1 : 0; //Controla el indice del arreglo de estructuras
            intentos = 3;
            menuInicio();
            break;
        case 7:
            salirPrograma();
            break;
        default:
            cout << "\n\t\t\t\tOpcion no valida. Favor, intentar de nuevo." << endl;
            menuPrincipal();
    }
}

void menuAuxiliar() {
    int opcion{};
    GUIreiniciar();
    cout << "\n\t\t\t	///////////////////////MENU OPCION/////////////////////////" << endl;
    cout << "\t\t\t\t Por favor, seleccione una de las siguientes opciones: " << endl;
    cout << "\t\t\t	///////////////////////////////////////////////////////////" << endl;
    cout << "\t\t\t	|1. Inicio de Sesion " << "------------------|" << "#Dfk41853" << " |" << endl;
    cout << "\t\t\t	|2. Volver al Menu Principal " << "-----------------|" << " |" << endl;
    cout << "\t\t\t	|3. Salir del Programa " << "-----------------|" << " |" << endl;
    cout << "\t\t\t	///////////////////////////////////////////////////////////" << endl;
    cout << "\t\t\t	Opcion a seleccionar: ";
    fflush(stdin);
    cin >> opcion;

    switch (opcion) {
        case 1:
            ind = (ind < 5) ? ind + 1 : 0; //Controla el indice del arreglo de estructuras
            intentos = 3;
            menuInicio();
            break;
        case 2:
            menuPrincipal();
            break;
        case 3:
            salirPrograma();
            break;
        default:
            cout << "\n\t\t\tOpcion Invalida. Por favor, intentelo de nuevo,";
            menuAuxiliar();
    }

}

