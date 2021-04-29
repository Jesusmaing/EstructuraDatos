//Nombre: Imperio.cpp
//Fecha: 18/03/2021
//Autor: Jesus Martin Garcia Encinas
//Descripción: Métodos para implementar un correcto funcionamiento de una cola medieval

#include "ColaMedieval.h"

ColaMedieval::ColaMedieval(){}

ColaMedieval::ColaMedieval(const ColaMedieval &c) {

}

ColaMedieval &ColaMedieval::operator=(const ColaMedieval &c) {
    if(this == &c) return *this;
    ColaNobles = c.ColaNobles;
    ColaPlebeyos = c.ColaPlebeyos;
    return *this;
}

ColaMedieval::~ColaMedieval(){}

void ColaMedieval::EncolarCiudadadano(const Persona &p) {

    (p.getEstrato() == "Noble") ? ColaNobles.encolar(p) : ColaPlebeyos.encolar(p);

}

Persona ColaMedieval::consultarPrimero() const {
    if(!ColaNobles.estaVacia()) return ColaNobles.obtenerPrimero();
    else return ColaPlebeyos.obtenerPrimero();
}

Persona ColaMedieval::ConsultarUltimo() const {
    if(!ColaNobles.estaVacia()) return ColaNobles.obtenerUltimo();
    else return ColaPlebeyos.obtenerUltimo();
}

void ColaMedieval::desencolar() {
    if(!ColaNobles.estaVacia()) ColaNobles.desencolar();
    else ColaPlebeyos.desencolar();
}

unsigned ColaMedieval::CantidadNobles() const {
    return ColaNobles.obtenerTam();
}

unsigned ColaMedieval::CantidadPlebeyos() const {
    return ColaPlebeyos.obtenerTam();
}

unsigned ColaMedieval::ConsultarCantidadCiudadadanos() const {
    return ColaNobles.obtenerTam() + ColaPlebeyos.obtenerTam();
}

bool ColaMedieval::estaVacia() const {
    if(ColaNobles.estaVacia() && ColaPlebeyos.estaVacia()) return true;
    else return false;
}

void ColaMedieval::ImprimirCola() const {
    if (estaVacia()) std::cout << "Cola Vacia" << endl;
    // MIENTRAS HAYA NOBLES EN LA COLA, SE VA A IMPRIMIR
    if(!ColaNobles.estaVacia()) ColaNobles.Imprimir();
    // MIENTRAS HAYA PLEBEYOS EN LA COLA, SE VA A IMPRIMIR
    if(!ColaPlebeyos.estaVacia())ColaPlebeyos.Imprimir();
    }

