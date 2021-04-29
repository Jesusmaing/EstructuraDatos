/*
Nombre: ClaseMatriz.cpp
Autor: Sebastian Guadalupe Rivera de la Cruz
Fecha: 5/1/2021
Descripción: Cabecera para el archivo "Utilerias.tpp"
*/

#ifndef CLASEMATRIZ_UTILERIAS_H
#define CLASEMATRIZ_UTILERIAS_H
enum Tipo{
    DOUBLE = 1,
    STRING,
    VECTOR
};
/**@brief Plantilla que permite la captura segura de cualquier tipo de dato ingresado.
 *
 * @param n Referencia del valor ingresado.
 * @param solicitud La sentencia de caracteres a imprimir.
 */
template <typename TIPO>
void CapturaSegura(TIPO &n, const char solicitud[]);


#include "Utilerias.tpp"
#endif //CLASEMATRIZ_UTILERIAS_H
