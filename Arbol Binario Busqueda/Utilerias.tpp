/*
Nombre: utilerias.tpp
Autor: Jesus Martin Garcia Encinas
Fecha: 22/04/2021
Descripción: Funciones para utilerias
*/

#include <iostream>
#include <limits>
#include "Utilerias.h"

template <typename TIPO>
void CapturaSegura(TIPO &n, const char solicitud[])
{
    while(true){
        std::cout << solicitud;
        std::cin >> n;

        if(std::cin.bad()) throw " Error irrecoverable en el flujo de entrada";

        if(std::cin.fail()){
            std::cout << " El valor introducido no es un n\243mero\n" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<int>::max(),'\n');
            continue;
        }
        break;
    }
}
