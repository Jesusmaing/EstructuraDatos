/*
Nombre: GestionPilas.cpp
Autor: Sebastian Guadalupe Rivera de la Cruz
Fecha: 14/02/2021
Descripción: Archivo de implementación de GestionPilas.h.
*/

#include "GestionPilas.h"

short menuOperaciones()
{
    short opcionMenu;
    std::cout << "Elija la operaci\242n que desee realizar con la pila:" << std::endl;
    std::cout << "0)Salir" << std::endl;
    std::cout << "1)Agregar un nuevo elemento" << std::endl;
    std::cout << "2)Eliminar el elemento en el tope" << std::endl;
    std::cout << "3)Obtener el valor del tope" << std::endl;
    std::cout << "4)Conocer si la pila est\240 vac\241a" << std::endl;
    std::cout << "5)Vaciar la pila" << std::endl;
    std::cout << "6)Conocer el tama\244o de la pila" << std::endl;
    std::cout << "7)Conocer la capacidad de la pila" << std::endl;
    std::cout << "8)Imprimir los elementos de la pila" << std::endl;
    do {
        CapturaSegura(opcionMenu, "Elija opci\242n: ");
        if (opcionMenu < 0 || opcionMenu > 8) std::cout << "Fuera de rango..." << std::endl;
    } while (opcionMenu < 0 || opcionMenu > 8);
    std::cout << std::endl;
    system("cls");
    return opcionMenu;
}

//
//template<typename T>
//void opEliminar(Pila<T> &p)
//{
//    unsigned int cantidad;
//    std::cout << "\250Cuantos elementos desea eliminar?: ";
//    std::cin >> cantidad;
//    for (int i = 0; i < cantidad; ++i) p.eliminar();
//}
//
//template<typename T>
//void opObtenerTope(T &p)
//{
//    std::cout << "Tope: \n" << p.obtenerTope() << std::endl;
//}
//
//template<typename T>
//void opVaciar(Pila<T> &p)
//{
//    p.vaciar();
//    std::cout << "La pila se ha vaciado con \202xito." << std::endl;
//}
//
//template<typename T>
//void opObtenerTam(Pila<T> &p)
//{
//    std::cout << "El tama\244o actual de la pila es de " << p.obtenerTam() << " elementos." << std::endl;
//}
//
//
//template<typename T>
//void opCapacidad(Pila<T> &p)
//{
//    std::cout << "La capacidad actual de la pila es de " << p.obtenerCap() << " elementos." << std::endl;
//}
//
//template<typename T>
//void opImprimir(Pila<T> &p)
//{
//    p.imprimir();
//}

