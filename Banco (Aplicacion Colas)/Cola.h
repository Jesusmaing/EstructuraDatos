/*
Nombre: Cola.h
Autor: JESUS MARTIN GARCIA ENCINAS
Fecha: 2/3/2021
*/

#ifndef PRUEBACOLA_COLA_H
#define PRUEBACOLA_COLA_H

#include <iostream>

template<typename T>
class Cola {
public:
    Cola();
    Cola(const Cola<T> &c);
    Cola <T> & operator=(const Cola<T> &c);
    ~Cola();
    void encolar(const T &val);
    void desencolar();
    unsigned obtenerTam() const;
    bool estaVacia() const;
    const T & obtenerPrimero() const;
    void vaciar();
    void Imprimir() const;
private:
    unsigned tam;
    struct Nodo{
        Nodo(T val, Nodo *sig = NULL);
        T valor;
        Nodo *siguiente;
    }*primero, *ultimo;
};

#include "Cola.tpp"
#endif //PRUEBACOLA_COLA_H
