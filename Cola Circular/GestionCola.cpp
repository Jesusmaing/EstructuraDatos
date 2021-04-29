/*
Nombre: GestionCola.h
Autor: JESUS MARTIN GARCIA ENCINAS
Fecha: 2/3/2021
*/


#include "GestionCola.h"



unsigned short menu_2() {
    system("cls");
    unsigned short d;

    std::cout << "0. Salir" << std::endl;
    std::cout << "1. Encolar" << std::endl;
    std::cout << "2. Desencolar" << std::endl;
    std::cout << "3. Imprimir cola" << std::endl;
    std::cout << "4. Conocer si la cola est\240 vac\241a" << std::endl;
    std::cout << "5. Obtener el tama\244o de la cola" << std::endl;
    std::cout << "6. Vaciar la cola" << std::endl;
    std::cout << "7. Obtener primer valor de la cola" << std::endl;
    std::cout << "8. Obtener \243ltimo valor de la cola" << std::endl;


    do {
        CapturaSegura(d,"Digite una opci\242n:\377");
    }while(d < 0 || d > 8);
    return d;
}

unsigned short menu_1(){
    system("cls");
    unsigned short d;
    std::cout << "0. Salir"         << std::endl;
    std::cout << "1. COLA TIPO INT" << std::endl;
    std::cout << "2. COLA TIPO DOUBLE" << std::endl;
    std::cout << "3. COLA TIPO CHAR" << std::endl;

    do {
        CapturaSegura(d,"Digite una opci\242n:\377");
    }while(d < 0 || d > 3);
    return d;
}

