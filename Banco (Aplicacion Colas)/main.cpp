//Nombre: ColaMedieval.cpp
//Fecha: 06/03/2021
//Autor: Jesus Martin Garcia Encinas
//Descripción: Aplicación de colas

#include <iostream>
#include<cstdlib>
#include "Cola.h"
#include "ColaMedieval.h"

using namespace std;
int main() {
    try {
        int tiempototal = 60 + rand() % 240;
        system("pause");
        ColaMedieval BBVA; //Se funda el banco wuuuuuuu
        BBVA.generar_horario(tiempototal);
        BBVA.LLEGOELREY(); //PROMOCIONES DE CRÉDITO POR APERTURA!!
        BBVA.CerrarBanco(); // Por el covid19, el banco tuvo que clausurar la sucursal :(
        system("pause");
    }catch (out_of_range &exc){
        cerr << exc.what();
        system("pause");
    }catch (exception &exc){
        cerr << exc.what();
        system("pause");
    } catch (...) {
        cerr << "Ha ocurrido un error inesperado";
        system("pause");
    }
    return 0;
}
