#include <iostream>
#include "cmake-build-debug/Cola.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Cola p;
    p.Encolar(10);
    p.Desencolar();
    p.obtenerPrimero();
    p.ObtenerTam();
    p.EstaVacia();
    p.Vaciar();
    p.Imprimir();


    return 0;
}
