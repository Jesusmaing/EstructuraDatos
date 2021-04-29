/*
Nombre: PruebaPilas.cpp
Autor: Sebastian Guadalupe Rivera de la Cruz
Fecha: 2/4/2021
Descripción:
*/

#include <iostream>
#include "Pila.h"

Pila::Pila():tope(-1){}

Pila::Pila(int tope, double *contenido) : tope(tope)
{

}

bool Pila::agregar(double valor)
{
    if(estaLlena()) throw false;
    contenido[++tope] = valor;
}

void Pila::eliminar()
{

}

double Pila::obtenerTope() const
{
    return 0;
}

bool Pila::estaVacia() const
{
    return false;
}

bool Pila::estaLlena() const
{
    return tope == TAM-1;
}

int Pila::tam() const
{
    return 0;
}

int Pila::capacidad() const
{
    return TAM;
}

void Pila::vaciar()
{

}

void Pila::imprimir() const
{
    for (int i = 0; i <= tope; ++i) {
        std::cout << contenido[i] << ", ";
    }

    std::cout <<"\b\b < Tope";
}

