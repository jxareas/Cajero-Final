#include <windows.h>
#include <cstdlib>
#include <iostream>
#include <cstdlib>
#include "GUI.h"
#include "menu.h"
using namespace std;

void GUIreiniciar()
{
	system("cls");
	system("color 0f");
}

void GUIerror()
{
	system("cls");
	system("color 0c");
}

void GUItareaExitosa()
{
	system("cls");
	system("color 0a");
}

void GUIopcionInvalida()
{
	GUIerror();
	cout << "\n\n\t\t\t\t\t-------------------ALERTA------------------" << endl;
    cout << "\t\t\t\t\t Opcion Invalida. Por favor, intentelo de nuevo." << endl;
	cout << "\t\t\t\t\t||-------------------------------------------||" << endl;
	Sleep(2000);
}

void GUIlimiteExcedido(int limite)
{
	GUIerror();
			cout << "\n\n\t\t\t\t\t-------------------ALERTA------------------" << endl;
		    cout << "\t\t\t\t\t El monto debe ser menor a " << limite << endl;
			cout << "\t\t\t\t\t||-------------------------------------------||" << endl;
			Sleep(2000);
}

void GUIsaldoInsuficiente()
{
	GUIerror();
		cout << "\n\n\t\t\t\t\t-------------------ALERTA------------------" << endl;
	    cout << "\t\t\t\t\t Usted no tiene saldo suficiente para realizar esta operacion." << endl;
		cout << "\t\t\t\t\t||-------------------------------------------||" << endl;
		Sleep(2000);
}

void GUItarjetaInvalida()
{
	GUIerror();
			cout << "\n\n\t\t\t\t\t-------------------ALERTA------------------" << endl;
		    cout << "\t\t\t\t\t La tarjeta del destinatario es invalida." << endl;
			cout << "\t\t\t\t\t||-------------------------------------------||" << endl;
			Sleep(2000);
}

void GUIoperacionExitosa()
{
	GUItareaExitosa();
	cout << "\n\n\t\t\t\t\t-------------------ALERTA------------------" << endl;
    cout << "\t\t\t\t\t Se ha realizado la operacion de manera exitosa." << endl;
    cout << "\t\t\t\t\t||-------------------------------------------||" << endl;
    Sleep(2000);
    menuPrincipal();
}

void GUIpinInvalido()
{

	GUIerror();
	cout << "\n\n\t\t\t\t\t--------------------ALERTA------------------" << endl;
	    	cout << "\t\t\t\t\t\t      NUMERO PIN INVALIDO" << endl;
	    	cout << "\t\t\t\t\t||-------------------------------------------||" << endl;
	    	Sleep(1000);
}

