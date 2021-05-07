/*
Nombre: Fleury.tpp
Autor: Jesus Martin Garcia Encinas
Fecha: 06/05/2021
Descripción: Implementación del algoritmo de Fleury para realizar un paseo de euler
*/



#include <iostream>
#include "Grafica.h"
#include <cstdlib>

using std::cout; using std::out_of_range;
using std::cerr; using std::exception;
using std::endl;

int main() {
    try {
        Grafica<char> grafo;
        cout << "Se imprimir\240 la gr\240fica..." << endl;
        grafo.Archivo("grafica.txt");
        grafo.Imprimir();
        cout << endl;

        cout << "Se empezara a hacer el algortimo..." << endl;
        grafo.Fleury('h');
        system("pause");
    } catch (out_of_range &exc) {
        cerr << exc.what();
        system("pause");
    } catch (exception &exc) {
        cerr << exc.what();
        system("pause");
    } catch (...) {
        cerr << "Ha ocurrido un error inesperado";
        system("pause");
    }
    return 0;

}
