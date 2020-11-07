#ifndef DATOS_H_
#define DATOS_H_

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

#endif /* DATOS_H_ */
