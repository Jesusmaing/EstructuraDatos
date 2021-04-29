/*
Nombre: ListaEnlazadaSimple
Autor: Jesus Martin Garcia Encinas
Fecha: 08/03/2021
Descripción: Implementación de una ListaEnlazadaSimple
*/

#include <iostream>
#include "ListaEnlazadaSimple.h"
#include "GestionLista.h"
#include "Utilerias.h"

using std::cout;
using std::cerr;
int main() {
    try {
        unsigned short decision;
        ListaEnlazadaSimple<double> lista;
        do {
            menu();

            double valor;
            int pos;
            CapturaSegura(decision, "Por favor,seleccione una opci\242n: ");
            if (decision == 0) break;
            system("cls");
            switch (decision) {
                case 1:
                    cout << "Agregar un elemento al principio de la lista..." << endl;
                    CapturaSegura(valor, "Ingrese el valor a agregar: ");
                    lista.agregarAlPrincipio(valor);
                    break;
                case 2:
                    cout << "Agregar un elemento al final de la lista..." << endl;
                    CapturaSegura(valor, "Ingrese el valor a agregar: ");
                    lista.agregarAlFinal(valor);
                    break;
                case 3:
                    cout << "Agregar un elemento en una posici\242n de la lista..." << endl;
                    CapturaSegura(valor, "Ingrese el valor a agregar: ");
                    CapturaSegura(pos, "Ingrese la posici\242n para agregar el valor: ");
                    lista.agregarEnPosicion(valor, pos);
                    break;
                case 4:
                    cout << "Se eliminar\240 el primer elemento de la lista el cual es..." << lista.obtenerPrimero()
                         << endl;
                    lista.eliminarDelPrincipio();
                    cout << "Se ha eliminado correctamente :)" << endl;
                    break;
                case 5:
                    cout << "Se eliminar\240 el \243ltimo elemento de la lista el cual es..." << lista.obtenerUltimo()
                         << endl;
                    lista.eliminarDelFinal();
                    cout << "Se ha eliminado correctamente :)" << endl;
                    break;
                case 6:
                    CapturaSegura(pos, "Ingrese la posici\242n del valor para eliminar: ");
                    cout << "Se eliminar\240 el elemento # " << pos << "de la lista el cual es..."
                         << lista.obtenerEnPosicion(pos) << endl;
                    lista.eliminarDePosicion(pos);
                    break;
                case 7:
                    cout << "Se buscar\240 si un valor de la lista se encuentra en ella" << endl;
                    CapturaSegura(valor, "Ingrese el valor para buscar: ");
                    lista.buscar(valor) ? cout << "Se encuentra en la lista" : cout << "No se encuentra en la lista";
                    cout << endl;
                    break;
                case 8:
                    cout << "Se buscar\240 un elemento en una posici\242n de la lista enlazada" << endl;
                    CapturaSegura(valor, "Ingrese el valor para buscar: ");
                    if (lista.buscarPosicion(valor) != -1)
                        cout << "El valor se encuentra en" << lista.buscarPosicion(valor);
                    break;
                case 9:
                    lista.estaVacia() ? cout << "La lista est\240 vacia" : cout << "La lista no est\240 vacia";
                    cout << endl;
                    break;
                case 10:
                    cout << "El primer elemento de la lista es: " << lista[0] << endl;
                    break;
                case 11:
                    cout << "El \243ltimo elemento de la lista es: " << lista.obtenerUltimo() << endl;
                    break;
                case 12:
                    CapturaSegura(pos, "Ingrese la posici\242n para buscar el valor: ");
                    cout << "El elemento de la lista en la posici\242 # " << pos << " es: "
                         << lista[pos] << endl;
                    break;
                case 13:
                    cout << "Se modificar\240 el valor en determinada posici\242n" << endl;
                    CapturaSegura(valor, "Ingrese el valor nuevo: ");
                    CapturaSegura(pos, "Ingrese la posici\242n para modificar el valor: ");
                    lista[pos] = valor;
                    break;
                case 14:
                    lista.estaVacia() ? cout << "Lista vacia" :
                    cout << "El n\243mero de elementos de la lista es de: " << lista.obtenerTam();
                    cout << endl;
                    break;
                case 15:
                    if (!lista.estaVacia()) {
                        lista.vaciar();
                        cout << "Se ha vaciado la lista correctamente" << endl;
                    }
                    else cout << "La lista ya est\240 vacia";
                    break;
                case 16:
                    lista.imprimir();
                    break;
            }
            cout << endl;
            system("pause");
        } while (decision != 0);
    }catch (std::out_of_range &exc){
        cerr << exc.what();
        system("pause");
    }catch (std::exception &exc){
        cerr << exc.what();
        system("pause");
    } catch (...) {
        cerr << "Ha ocurrido un error inesperado";
        system("pause");
    }





    return 0;
}
