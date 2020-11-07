#include <iostream>
#include "tarjeta.h"
#include "globals.h"
using namespace std;

void vectorizar(string x, int n, int V[]) //Modifica un vector (por referencia), dada una cadena de caracteres y su indice.
{
	try {
        for (int i = 0; i < n; i++) {
            if (isdigit(x[i]))
                V[i] = x[i] - '0';
            else throw invalid_argument("\n\n\t\t\t\t\t\tEl numero de la tarjeta contiene caracteres no numericos");
        }
	}
catch(const invalid_argument& e) {

	}
}



bool verificarTarjeta(int * vector, int n)
{

    int sum{};

    for (int i = n - 2; i >= 0; i -= 2) //Transformacion de componentes impares
    {
        vector[i] = 2 * vector[i];
        if (vector[i] > 9)
        {
            vector[i] = vector[i] / 100 + (vector[i] / 10) % 10 + vector[i] % 10; //Suma de sus digitos mediante aritmetica modular
        }
    }

    for (int j = 0; j < n; j++) //Sumatoria
    {
        sum += vector[j];
    }
    return (sum % 10 == 0);
}

bool esTarjetaValida(string x, int n)
{
    int tarjeta[n];
    vectorizar(move(x), n, tarjeta);
    return verificarTarjeta(tarjeta, n);
}

bool esFechaValida(int mes, int anio)
{
    if (mes < 0 || mes > 12 || anio < 2020)
        return false;
    else if (anio == 2020)
        return (mes == 12);

    else return true;

}


bool esRegistroValido(string cadena, int mes, int anio, int Pin)
{
	return (esTarjetaValida(cadena, cadena.length()) && esFechaValida(mes, anio) && Pin == PIN);
}


