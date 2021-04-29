/*
Nombre: Cola.tpp
Autor: Jesus Martin Garcia Encinas
Fecha: 22/04/2021
Descripción: implementación de funciones para Cola enlazada
*/

#include "Cola.h"

// Constructor
template<typename T>
Cola<T>::Cola(): fondo(NULL), numELem(0) {
}


// Constructor de copias
template<typename T>
Cola<T>::Cola(const Cola<T> &C): fondo(NULL), numELem(0) {
    *this = C;
}

template<typename T>
Cola<T> &Cola<T>::operator=(const Cola<T> &C) {
    if (this == &C) return *this;
    Vaciar();
    if (!C.EstaVacia()) {
        Elemento *aux = C.fondo->sig;
        do {
            Encolar(aux->valor);
            aux = aux->sig;
        } while (aux != C.fondo->sig);
    }
    return *this;
}

// Destructor
template<typename T>
Cola<T>::~Cola() {
    Vaciar();
}

template<typename T>
void Cola<T>::Encolar(const T &valor) {

    Elemento *nuevo = new Elemento(valor, EstaVacia() ? NULL : fondo->sig);

    EstaVacia() ? nuevo->sig = nuevo : fondo->sig = nuevo;

    fondo = nuevo;

    ++numELem;
}

template<typename T>
void Cola<T>::Desencolar() {
    Elemento *aux = fondo->sig;
    numELem == 1 ? fondo = NULL : fondo->sig = aux->sig;
    delete aux;
    --numELem;
}

template<typename T>
unsigned Cola<T>::ObtenerTam() {
    return numELem;
}

template<typename T>
unsigned Cola<T>::ObtenerFinal() {
    return fondo->valor;
}

template<typename T>
T Cola<T>::ObtenerPrimero() {
    return fondo->sig->valor;
}


template<typename T>
bool Cola<T>::EstaVacia() const {
    return fondo == NULL;
}

template<typename T>
void Cola<T>::Vaciar() {
    while (!EstaVacia()) {
        Desencolar();
    }
}

// Función Imprimir para pruebas
template<typename T>
void Cola<T>::imprimir() {
    if (EstaVacia()) std::cout << "Cola Vac\241a" << std::endl;
    else {
        Elemento *aux = fondo->sig;
        do {
            std::cout << "Cliente: " << aux->valor << " <- ";
            aux = aux->sig;
        } while (aux != fondo->sig);
        std::cout << "\b\b\b   " << std::endl;
    }
}


