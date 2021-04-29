//Nombre: ColaImperio.cpp
//Fecha: 18/03/2021
//Autor: Jesus Martin Garcia Encinas
//Descripción: Aplicación de la estructura de dato COLA

#include <iostream>
#include<cstdlib>
#include "Cola.h"
#include "Imperio.h"
using namespace std;
int main() {
    try {
        srand(time(NULL));
        int tiempototal = 60 + rand() % 240;
        Imperio ROMANO;
        ROMANO.AbrirImperio(tiempototal);

        //Después de un tiempo se cierra el banco
        ROMANO.CerrarImperio();


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
