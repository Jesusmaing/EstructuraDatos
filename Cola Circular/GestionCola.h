//
// Created by jesusmaing on 02/03/2021.
//

#ifndef PRUEBACOLA_GESTIONCOLA_H
#define PRUEBACOLA_GESTIONCOLA_H

#include <iostream>
#include "Utilerias.h"

enum menu1 { /** Enumeraci&oacute;n utilizada para determinar con que cola se trabajar@aacute;.*/
    SALIR,
    INT ,
    DOUBLE ,
    CHAR,

};

enum menu2 { /** Enumeraci&oacute;n utilizada para determinar con que funcion de la clase cola se trabajar@aacute;.*/
    ENCOLAR = 1,
    DESENCOLAR,
    IMPRIMIR,
    CONOCER_SI_ESTA_VACIA,
    OBTENER_TAMANO,
    VACIAR_COLA,
    OBTENER_PRIMER_VALOR,
    OBTENER_ULTIMO_VALOR
};

/** @brief Funci&oacute;n que presenta el men&uacute; de tipos de colas al usuario.
 *
 * @return Opci&oacute seleccionada.
 */
unsigned short menu_1();

/** @brief Funci&oacute;n que presenta el men&uacute; de operaciones con colas al usuario.
 *
 * @return Opci&oacute seleccionada.
 */
unsigned short menu_2();
#endif //PRUEBACOLA_GESTIONCOLA_H
