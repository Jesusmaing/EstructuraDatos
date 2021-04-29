/*
Nombre: Utilerias.tpp
Autor: JESUS MARTIN GARCIA ENCINAS
Fecha: 2/3/2021
*/



#include "Utilerias.h"

template <typename TIPO>
void CapturaSegura(TIPO &n, const char solicitud[])
{
    while(true){
        std::cout << solicitud;
        std::cin >> n;

        if(std::cin.bad()) throw " Error irrecuperable en el flujo de entrada";

        if(std::cin.fail()){
            std::cout << " El valor introducido no es un n\243mero\n" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<int>::max(),'\n');
            continue;
        }
        break;
    }
}