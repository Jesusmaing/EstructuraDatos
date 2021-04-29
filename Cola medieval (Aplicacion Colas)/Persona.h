//Nombre: Persona.h
//Fecha: 06/03/2021
//Autor: Jesus Martin Garcia Encinas
//Descripción: Archivo de cabecera para la clase Persona

#ifndef PRUEBACOLA_PERSONA_H
#define PRUEBACOLA_PERSONA_H


#include <cstring>
#include <iostream>
#include <cstdlib>
#include <ctime>

using std::string;
using std::cout;
using std::endl;


class Persona {
public:
    //******************************************************************************************
    /** @brief Constructor por default de la clase.
    */
    Persona();
    /** @brief destructor por default de la clase.
    */
    Persona(string _Nombre, string _Apellido, string _estamento);

    string getPersona() const;
    string getEstrato() const;
    friend std::ostream  &operator << (std::ostream &fSalida, const Persona &persona);
private:
    string Nombre;
    string Apellido;
    string Estamento;

};


#endif //PRUEBACOLA_PERSONA_H
