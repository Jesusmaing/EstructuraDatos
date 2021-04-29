/*
Nombre: GestionLista.cpp
Autor: Jesus Martin Garcia Encinas
Fecha: 22/04/2021
Descripción: Menú para gestión de Árbol semibalanceado
*/
#include "GestionLista.h"

void menu_TIPO(){
    system("cls");
    cout << " \n\nSELECCIONE UN TIPO DE LISTA ENLAZADA...  " << endl;
    cout << "-----------------------------------------------------------------------------" << endl;
    cout << "|* 0. SALIR                                                                  " << endl;
    cout << "|* 1. TIPO ENTERO (INT)                                                      " << endl;
    cout << "|* 2. TIPO DOUBLE                                                            " << endl;
    cout << "|* 3. TIPO VECTOR(DOUBLE)                                                            " << endl;
    cout << "-----------------------------------------------------------------------------" << endl;

}
void menu() {
    system("cls");
    cout << " \n\nSELECCIONE UNA OPERACION PARA LA GESTION DE LA CLASE LISTA ENLAZADA...  " << endl;
    cout << "-----------------------------------------------------------------------------" << endl;
    cout << "|* 0. SALIR                                                                  " << endl;
    cout << "|* 1.Agregar un nodo (Sin repeticiones)                                      " << endl;
    cout << "|* 2.Eliminar un nodo                                                        " << endl;
    cout << "|* 3.Buscar un nodo                                                          " << endl;
    cout << "|* 4.Numero de nodos del \240rbol                                            " << endl;
    cout << "|* 5.Vaciar el \240rbol                                                      " << endl;
    cout << "|* 6.Conocer si el \240rbol est\240 vac\241o                                 " << endl;
    cout << "|* 7.Imprimir el \240rbol de forma ascendente                                " << endl;
    cout << "|* 8.Imprimir el \240rbol de forma descendente                              " << endl;
    cout << "|* 9.Imprimir el \240rbol por niveles                                       " << endl;
    cout << "-----------------------------------------------------------------------------" << endl;
}
