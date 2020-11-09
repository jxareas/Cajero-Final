#ifndef MAIN_CPP_GLOBALS_H
#define MAIN_CPP_GLOBALS_H
#include <iostream>
using namespace std;

struct FechaExpiracion {
    int mes;
    int anio;
};

struct Transferencia {
    string cuentaDestino{};
    int monto{};
    const int limite{10000};
};

struct Retiro {
    int monto;
    const int limite{5000};
};

struct Cliente {
    string tarjeta{};
    FechaExpiracion fechaExpiracion{};
    Transferencia transferencia{};
    Retiro retiro{};
    int NIP{};
    double saldo{};
};


extern int ind;
extern int intentos;
extern int PIN[];
extern Cliente usuarios[];


#endif //MAIN_CPP_GLOBALS_H
