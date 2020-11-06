#ifndef DATOS_H_
#define DATOS_H_
#include <iostream>
using namespace std;

struct FechaExpiracion {
    int mes;
    int anio;
};

struct Deposito {
    string cuentaDestino {};
    int monto {};
    const int limite {10000};
};

struct Cliente {
    string tarjeta {};
    FechaExpiracion fechaExpiracion {};
    Deposito datosDeposito {};
    int NIP {};
    double saldo {};
};

#endif /* DATOS_H_ */
