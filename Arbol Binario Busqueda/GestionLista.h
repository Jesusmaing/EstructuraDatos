/*
Nombre: GestionLista.h
Autor: Jesus Martin Garcia Encinas
Fecha:  22/04/2021
Descripción: Archivo de cabecera para menú de Arbol semibalanceado
*/
#ifndef LISTA_GESTIONLISTA_H
#define LISTA_GESTIONLISTA_H

#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;
using std::string;
//*****************************************************************************************************************
/** @brief Enumeraci@oacute;n para definir el tipo de la clase plantilla Lista Enlazada Doble
 */
enum TIPO{
    INT = 1,
    DOUBLE,
    VECTOR,
};
//*****************************************************************************************************************
/** @brief Enumeraci@oacute;n para definir el tipo de operaciones para la Lista Enalazada Doble
 */
enum PRINCIPAL{
    AGREGAR = 1,
    ELIMINAR,
    BUSCAR,
    NUMNODOS,
    VACIAR,
    ESTAVACIA,
    ASCENDENTE,
    DESCENDENTE,
    NIVELES,

};
//************************************************************************************************************
/** @brief Menú para la creaci@oacute;n de un tipo de lista de la clase Lista Enlazada Doble...
 */
void menu_TIPO();
//*****************************************************************************************************************
/** @brief Menú para operación de la clase ListaEnlazadaSimple...
 */
void menu();
//*****************************************************************************************************************



#endif //LISTA_GESTIONLISTA_H
