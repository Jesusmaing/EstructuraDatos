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
    //******************************************************************************************
    ~Persona();
    //******************************************************************************************}
    /** @brief Generar una persona con nombre al azar apartir de un arreglo
     *
     */
    //******************************************************************************************}
    void SetCliente();
    /** @brief Obtener nombre completo de persona
     *
     * @return Nombre completo de la persona
     */
    string getPersona();
    string getEstamento();
private:
    string *nombres; /** puntero que apunta a un arreglo dinámico creado en el constructor */
    string *apellidos; /** puntero que apunta a un arreglo dinámico creado en el constructor */
    int maxNombres;
    int maxApellidos;
    string _Persona;
    string _Estamento;


};


#endif //PRUEBACOLA_PERSONA_H
