//
// Created by jesusmaing on 24/02/2021.
//

#include "Cola.h"

Cola::Cola() {

}

Cola::~Cola() {

}

void Cola::Imprimir() const {

}

void Cola::Vaciar() {

}
template <typename T>
const T &Cola::obtenerPrimero() const {
    return <#initializer#>;
}

bool Cola::EstaVacia() const {
    return false;
}

unsigned Cola::ObtenerTam() const {
    return 0;
}

void Cola::Desencolar() {

}
template <typename T>
void Cola::Encolar(const T &val) {

}
template <typename T>
Cola<T> &Cola::operator=(const Cola<T> &c) {
    return <#initializer#>;
}

template <typename T>
void Cola<T>::Encolar(const T &val){
    Elemento *nuevo = new Elemento(val);
    if(EstaVacia()) primero = nuevo;
    else ultimo -> sig = nuevo;

}

