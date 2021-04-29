//Nombre: Persona.cpp
//Fecha: 06/03/2021
//Autor: Jesus Martin Garcia Encinas
//Descripción: Métodos de la clase Persona

#include <fstream>
#include "Persona.h"
Persona::Persona(): Nombre(""), Apellido(""),Estamento(""){}

Persona::Persona(string _Nombre, string _Apellido, string _estamento):
Nombre(_Nombre), Apellido(_Apellido),Estamento(_estamento){}


string Persona::getPersona() const {
    return Nombre + " " + Apellido;
}

string Persona::getEstrato() const {
    return Estamento;
}


std::ostream &operator<<(std::ostream &fSalida, const Persona &persona) {
    fSalida << persona.getPersona() << ": ";
    if(persona.getEstrato() == "Noble") fSalida << "Noble";
    else fSalida << "Plebeyo";
    return fSalida;
}


