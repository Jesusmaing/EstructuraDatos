/*
Nombre: GestionLista.cpp
Autor: Jesus Martin Garcia Encinas
Fecha: 26/03/2021
Descripción: Menú para gestión de ListaOrdenada
*/
#include "GestionLista.h"

void menu_TIPO(){
    system("cls");
    cout << " \n\nSELECCIONE UN TIPO DE LISTA ENLAZADA...  " << endl;
    cout << "-----------------------------------------------------------------------------" << endl;
    cout << "|* 0. SALIR                                                                  " << endl;
    cout << "|* 1. TIPO ENTERO (INT)                                                      " << endl;
    cout << "|* 2. TIPO DOUBLE                                                            " << endl;
    cout << "|* 3. TIPO VECTOR(DOUBLE)                                                    " << endl;
    cout << "-----------------------------------------------------------------------------" << endl;

}
void menu() {
    system("cls");
    cout << " \n\nSELECCIONE UNA OPERACION PARA LA GESTION DE LA CLASE LISTA ENLAZADA...  " << endl;
    cout << "-----------------------------------------------------------------------------" << endl;
    cout << "|* 0. SALIR                                                                  " << endl;
    cout << "|* 1.Agregar un elemento                                                     " << endl;
    cout << "|* 2.Eliminar elemento                                                       " << endl;
    cout << "|* 3.Eliminar un elemento (primera ocurrencia)                               " << endl;
    cout << "|* 4.Eliminar un elemento (toda ocurrencia)                                  " << endl;
    cout << "|* 5.Avanzar cabeza                                                          " << endl;
    cout << "|* 6.Retroceder cabeza                                                       " << endl;
    cout << "|* 7.Conocer elemento de la cabeza                                           " << endl;
    cout << "|* 8.Buscar un elemento                                                      " << endl;
    cout << "|* 9.Vaciar la lista                                                         " << endl;
    cout << "|* 10.Conocer si la lista est\240 vac\241a                                   " << endl;
    cout << "|* 11.Conocer el tamano de la lista                                          " << endl;
    cout << "|* 12.Imprimir la lista                                                      " << endl;
    cout << "-----------------------------------------------------------------------------" << endl;
}
