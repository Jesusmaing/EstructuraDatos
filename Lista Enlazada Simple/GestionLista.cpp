/*
Nombre: GestionLista.cpp
Autor: Jesus Martin Garcia Encinas
Fecha: 08/03/2021
Descripción: Menú para gestión de ListaEnlazadaSimple
*/
#include "GestionLista.h"



void menu() {
    system("cls");
    cout << " \n\nSELECCIONE UNA OPERACION PARA LA GESTION DE LA CLASE LISTA ENLAZADA...  " << endl;
    cout << "-----------------------------------------------------------------------------" << endl;
    cout << "|* 0. SALIR                                                                  " << endl;
    cout << "|* 1.Agregar un elemento al principio de la lista                            " << endl;
    cout << "|* 2.Agregar un elemento al final de la lista                                " << endl;
    cout << "|* 3.Agregar un elemento a la lista en una posici\242n indicada (\241ndice)  " << endl;
    cout << "|* 4.Eliminar un elemento del principio de la lista                          " << endl;
    cout << "|* 5.Eliminar un elemento del final de la lista                              " << endl;
    cout << "|* 6.Eliminar un elemento de la lista de la posiciz\242n indicada (\241ndice)" << endl;
    cout << "|* 7.Buscar un valor en la lista                                             " << endl;
    cout << "|* 8.Buscar la posici\242n de un valor en la lista (primera ocurrencia)      " << endl;
    cout << "|* 9.Conocer si la lista est\240 vac\241a                                    " << endl;
    cout << "|* 10.Obtener el primer elemento de la lista                                 " << endl;
    cout << "|* 11.Obtener el \243ltimo elemento de la lista                              " << endl;
    cout << "|* 12.Obtener el elemento de la lista en cierta posici\242n (\241ndice)      " << endl;
    cout << "|* 13.Modificar el elemento de la lista en cierta posici\242n (\241ndice)    " << endl;
    cout << "|* 14.Obtener el n\243mero de elementos que contiene la lista                " << endl;
    cout << "|* 15.Vaciar la lista                                                        " << endl;
    cout << "|* 16.Imprimir la lista                                                      " << endl;
    cout << "-----------------------------------------------------------------------------" << endl;
}