//
// Created by jesusmaing on 24/02/2021.
//

#ifndef COLA_COLA_H
#define COLA_COLA_H

#include <iostream>
template <typename T>;
class Cola {

public:

    Cola();
    Cola(const cola<T> &c);
    ~Cola();
    Cola<T> & operator = (const Cola<T> &c);
    void Encolar(const T &val);
    void Desencolar();
    unsigned ObtenerTam() const;
    bool EstaVacia() const;
    const T & obtenerPrimero() const;
    void Vaciar();
    void Imprimir() const;
private:
    unsigned tam;
    struct Elemento{
        T valor;
        Elemento *sig;
        Elemento(T val, Elemento *sig = NULL)
    }*primero, *ultimo;

};


};




#endif //COLA_COLA_H
