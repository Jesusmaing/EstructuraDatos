/*
Nombre: GestionLista.h
Autor: Jesus Martin Garcia Encinas
Fecha:  27/04/2021
Descripción: Archivo de cabecera para menú de Arbol semibalanceado
*/
#ifndef LISTA_GESTIONARBOL_H
#define LISTA_GESTIONARBOL_H

#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;
using std::string;
//*****************************************************************************************************************
/** @brief Enumeraci@oacute;n para definir el tipo de la clase
 */
enum TIPO{
    INT = 1,
    DOUBLE,
    VECTOR,
};
//*****************************************************************************************************************
/** @brief Enumeraci@oacute;n para definir el tipo de operaciones para el &aacute;rbol
 */
enum PRINCIPAL{
    AGREGAR = 1,
    ELIMINAR,
    ELEMENTORAIZ,
    ESTAVACIA,
    VACIAR,
    NUMELEMENTOS,
    CAPACIDAD,
    IMPRIMIR,

};
//************************************************************************************************************
/** @brief Men&uacute; para la creaci&oacute;n de un tipo del &aacute;rbol...
 */
void menu_TIPO();
//*****************************************************************************************************************
/** @brief Menú para operación de la clase heap...
 */
void menu();
//*****************************************************************************************************************



#endif
