#ifndef TARJETA_H
#define TARJETA_H
#include <string>
using namespace std;

void vectorizar(string cadena, int longitud , int vector[]);
bool verificarTarjeta(int * vector, int longitud);
bool esFechaValida(int mes, int anio);
bool esTarjetaValida(string tarjeta, int longitud);
bool esRegistroValido(string cadena, int mes, int anio, int Pin);

#endif //MAIN_CPP_TARJETA_H
