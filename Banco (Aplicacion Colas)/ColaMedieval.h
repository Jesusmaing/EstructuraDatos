//Nombre: ColaMedieval.cpp
//Fecha: 06/03/2021
//Autor: Jesus Martin Garcia Encinas
//Descripción: Archivo de cabecera para la clase banco

#ifndef PRUEBACOLA_COLAMEDIEVAL_H
#define PRUEBACOLA_COLAMEDIEVAL_H


#include <string>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include "Cola.h"

#include <unistd.h>
#include "Persona.h"


using std::string;
using std::cout;
using std::endl;


class ColaMedieval {
public:

    //******************************************************************************************
    /** @brief Constructor por default de la clase.
    */
    ColaMedieval();
    //******************************************************************************************
    /** @brief Añadir a la cola tipo string un nombre simulando personas haceindo fila
     *
    */
    void PasarCiudadano();
    //******************************************************************************************
    /** @brief Elimina el nombre del Ciudadano atentido y pone un bool en false
     *
    */
    void DespacharCiudadano();
    //******************************************************************************************
    /** @brief Funci@oacute;n principal de la clase ColaMedieval, para manipular los dem@aacutes m@eacute;todos
     *
    */
    void LLEGOELREY();
    //******************************************************************************************
    /** @brief Desencolar el @uacute;ltimo elemento de la cola y coloca una variable bool en true simulando caja ocupada
      *
     */
    void AtenderCliente();
    //******************************************************************************************
    /** @brief Imprime los datos del banco
      *
     */
    void ImprimirConsola();
//******************************************************************************************
    /** @brief Imprime las personas que no pudieron ser atentidas y estaban en la cola esperando...
      *
     */
    void CerrarBanco();
//******************************************************************************************
    /** @brief Establece el horario de atenci@oacute;n del banco
      *
     */

    void generar_horario(int _tiempototal);
private:
    int tiempototal;
    int TiempoCliente;
    bool EstaOcupada;
    Cola<string> cola;
    Cola<string> ColaNobles;
    Cola<string> ColaPlebeyos;


    Persona Ciudadano;

    //Cartera de Ciudadano
    string NombreAtendido;
    string EstamentoAtendido;
};


#endif //PRUEBACOLA_COLAMEDIEVAL_H
