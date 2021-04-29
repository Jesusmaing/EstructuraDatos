//Nombre: Imperio.cpp
//Fecha: 18/03/2021
//Autor: Jesus Martin Garcia Encinas
//Descripción: Archivo de cabecera para la clase Imperio

#ifndef PRUEBACOLA_IMPERIO_H
#define PRUEBACOLA_IMPERIO_H


#include <string>
#include <ctime>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include "Cola.h"
#include <fstream>
#include <unistd.h>
#include "Persona.h"
#include "ColaMedieval.h"

using std::string;
using std::cout;
using std::endl;


class Imperio {
public:

    //******************************************************************************************
    /** @brief Constructor por default de la clase.
    */
    Imperio();
    //******************************************************************************************
    /** @brief Añadir a la cola tipo string un nombre simulando personas haceindo fila
     *
    */
    void PasarPersona();
    //******************************************************************************************
    /** @brief Elimina la persona atentida y pone un bool en false
     *
    */
    void DespacharCliente();
    //******************************************************************************************
    /** @brief Funci&oacute;n principal de la clase Imperio, para manipular los dem@aacutes m@eacute;todos
     *
    */
    void AbrirImperio(unsigned horario);
    //******************************************************************************************
    /** @brief Desencolar el @uacute;ltimo elemento de la cola y coloca una variable bool en true simulando que el rey est&aacute; ocupado
      *
     */
    void AtenderPersona();
    //******************************************************************************************
    /** @brief Imprime los datos del imperio
      *
     */
    void ImprimirConsola();
//******************************************************************************************
    /** @brief Imprime las personas que no pudieron ser atentidas y estaban en la cola esperando...
      *
     */
    void CerrarImperio();
//******************************************************************************************
private:
    unsigned Horario; //TIEMPO DE ATENCIÓN DEL IMPERIO
    unsigned TiempoPersona; //TIEMPO DE ATENCIÓN POR PERSONA
    bool ReyArturoOcupado; //CONOCER SI EL REY ARTURO ESTÁ OCUPADO
    ColaMedieval clientes_espera; //COLA  DE PERSONAS ESPERANDO ORDENADA TOMANDO COMO PRIORIDAD LOS NOBLES

    Persona PersonaActualAtendida;
    Cola<Persona> PersonasAtentidas; //COLA PARA GUARDAR TODAS LAS PERSONAS ATENDIDAS EN EL HORARIO

    /** puntero que apunta a un arreglo dinámico creado en el constructor */
    string *nombres;
    /** puntero que apunta a un arreglo dinámico creado en el constructor */
    string *apellidos;
    int maxNombres; //Número de nombres del archivo nombres.txt
    int maxApellidos; //Número de apellidos del archivo apellidos.txt



};


#endif //PRUEBACOLA_IMPERIO_H
