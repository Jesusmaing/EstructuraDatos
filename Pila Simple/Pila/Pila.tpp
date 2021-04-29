/*
Nombre: Pila.tpp
Autor: Sebastian Guadalupe Rivera de la Cruz
Fecha: 14/02/2021
Descripción: Implementación de la clase (plantilla) Pila que permite crear y manejar Pilas en memoria dinámica de cualquier tipo.
*/

#include <iostream>
#include "Pila.h"

template <typename T /* = double */>
Pila<T>::Pila():tope(-1), capacidad(10), contenido(new T[10])
{

}

template <typename T>
Pila<T>::Pila(const Pila<T> &p):tope(-1), capacidad(0), contenido(NULL)
{
    *this = p;
}

template <typename T>
Pila<T> & Pila<T>::operator=(const Pila<T> &p)
{
    if(this == &p) return *this;
    delete [] contenido;
    tope = p.tope;
    capacidad = p.capacidad;
    contenido = new T[capacidad];
    for (int i = 0; i <= tope; ++i) contenido[i] = p.contenido[i];
    return * this;

}

template <typename T>
Pila<T>::~Pila()
{
    delete [] contenido;
}

template <typename T>
void Pila<T>::agregar(T valor)
{
    if(estaLlena()) redimensionar();
    contenido[++tope] = valor;
}

template <typename T>
void Pila<T>::eliminar()
{
    if(estaVacia()) throw PilaVacia();
    --tope;
}

template <typename T>
const T & Pila<T>::obtenerTope() const
{
    if(estaVacia()) throw PilaVacia();
    return contenido[tope];
}

template <typename T>
bool Pila<T>::estaVacia() const
{
    return tope == - 1;
}

template <typename T>
void Pila<T>::vaciar()
{

    tope = - 1;
}

template <typename T>
int Pila<T>::obtenerTam() const
{
    return tope + 1;
}

template <typename T>
int Pila<T>::obtenerCap() const
{
    return capacidad;
}


template <typename T>
void Pila<T>::imprimir() const
{
    if(estaVacia()) throw PilaVacia();
    for (int i = 0; i < tope; ++i) {
        std::cout << contenido[i] << std::endl;
    }
    std::cout << contenido[tope] << " << Tope" << std::endl;
}

template <typename T>
void Pila<T>::redimensionar()
{
    T * aux = contenido;
    capacidad *= 2;
    contenido = new T[capacidad];
    for (int i = 0; i <= tope; ++i) contenido[i] = aux[i];
    delete [] aux;
}

//mover a privado
template <typename T>
bool Pila<T>::estaLlena() const
{
    return tope == capacidad - 1;
}

template <typename T>
const char *Pila<T>::PilaVacia::what() const throw() {
    return "Error: Pila vac\241a";  //Acentos
}
