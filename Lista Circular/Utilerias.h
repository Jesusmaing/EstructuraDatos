/*
Nombre: utilerias.h
Autor: Jesus Martin Garcia Encinas
Fecha: 26/03/2021
Descripción: implementación de funciones para utilerias
*/

#ifndef CLASEMATRIZ_UTILERIAS_H
#define CLASEMATRIZ_UTILERIAS_H

/**@brief Plantilla que permite la captura segura de cualquier tipo de dato ingresado.
 *
 * @param n Referencia del valor ingresado.
 * @param solicitud La sentencia de caracteres a imprimir.
 */
template <typename TIPO>
void CapturaSegura(TIPO &n, const char solicitud[]);


#include "Utilerias.tpp"
#endif //CLASEMATRIZ_UTILERIAS_H
