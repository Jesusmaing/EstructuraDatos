//
// Created by jesusmaing on 02/03/2021.
//

#ifndef PRUEBACOLA_UTILERIAS_H
#define PRUEBACOLA_UTILERIAS_H

#include <iostream>
#include <limits>
#include <cstdlib>
/**@brief Plantilla que permite la captura segura de cualquier tipo de dato ingresado.
 *
 * @param n Referencia del valor ingresado.
 * @param solicitud La sentencia de caracteres a imprimir.
 */
template <typename TIPO>
void CapturaSegura(TIPO &n, const char solicitud[]);

#include "Utilerias.tpp"
#endif //PRUEBACOLA_UTILERIAS_H
