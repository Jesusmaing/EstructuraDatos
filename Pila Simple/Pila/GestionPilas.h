/*
Nombre: GestionPilas.h
Autor: Sebastian Guadalupe Rivera de la Cruz
Fecha: 14/02/2021
Descripción: Archivo cabecera de GestionPilas.h.
*/

#ifndef PILADINAMICA_SGRC_GESTIONPILAS_H
#define PILADINAMICA_SGRC_GESTIONPILAS_H

#include <iostream>
#include "Utilerias.h"

enum Opciones{
    AGREGAR = 1,
    ELIMINAR,
    OBTENERTOPE,
    ESTAVACIA,
    VACIAR,
    TAMANIO,
    CAPACIDAD,
    IMPRIMIR
};

/** @brief Funci&oacute;n que presenta el men&uacute; de operaciones con pilas al usuario.
 *
 * @return Opci&oacute seleccionada.
 */
short menuOperaciones();

// Trate de hacer funciones gestion para las pilas pero me daba errores :(
//template<typename T>
//void opEliminar(Pila<T> &p);
//
//template<typename T>
//void opObtenerTope(Pila<T> &p);
//
//template<typename T>
//void opVaciar(Pila<T> &p);
//
//template<typename T>
//void opObtenerTam(Pila<T> &p);
//
//template<typename T>
//void opCapacidad(Pila<T> &p);
//
//template<typename T>
//void opImprimir(Pila<T> &p);

#endif //PILADINAMICA_SGRC_GESTIONPILAS_H
