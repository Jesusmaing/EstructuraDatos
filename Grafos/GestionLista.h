/*
Nombre: GestionLista.h
Autor: Jesus Martin Garcia Encinas
Fecha: 09/04/2021
Descripción: Archivo de cabecera para menú de Gráfica
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
    AGREGAR_NODO = 1,
    AGREGAR_ARISTA,
    ELIMINAR_NODO,
    ELIMINAR_ARISTA,
    BUSCAR_NODO,
    BUSCAR_ARISTA,
    OBTENER_GRADO_NODO,
    OBTENER_NODOS,
    OBTENER_ARISTAS,
    VACIAR,
    VACIARNODO,
    IMPRIMIR
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
