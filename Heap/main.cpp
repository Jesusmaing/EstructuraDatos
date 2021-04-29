/*
Nombre: Arbol HEAP
Autor: Jesus Martin Garcia Encinas
Fecha: 28/04/2021
Descripción: Aplicación de un Árbol binario semicompleto semiordenado
*/


#include <iostream>
#include <cstdlib>
#include "GestionArbol.h"
#include "Utilerias.h"
#include "Heap.h"
#include "Vector.h"

using std::cout;
using std::cin;
using std::cerr;
using std::string;
using std::endl;

int main() {
    try {

        short opcion;
        cout << "Programa que para trabajar con 3 tipos diferentes de arbol semicompleto semibalanceado...";
        cout << endl;
        system("pause");
        menu_TIPO();
        /***********************************************
        *   CAPTURAR DE MANERA SEGURA LA OPCIÓN        *
        ************************************************/
        do {
            CapturaSegura(opcion, "Elija una opci\242n: ");
            if (opcion < 0 || opcion > 3) cout << "Fuera de rango..." << endl << endl;
        } while (opcion < 0 || opcion > 3);
        if (opcion == 0) {
            system("pause");
            return 0;
        }
        system("pause");
        system("cls");
        do {

            /**************************************************/
            switch (opcion) {
                case INT: {
                    Heap<int, minimo> arbol;
                    int valor, opcion1;
                    do {
                        do {
                            menu();
                            CapturaSegura(opcion1, "Elija una opci\242n de la \240rbol: ");
                            if (opcion1 < 0 || opcion1 > 8) cout << "Fuera de rango..." << endl << endl;
                        } while (opcion1 < 0 || opcion1 > 8);
                        if (opcion1 == 0) {
                            system("pause");
                            return 0;
                        }
                        switch (opcion1) {
                            case AGREGAR: {
                                CapturaSegura(valor, "Ingrese el valor a agregar:");
                                arbol.AgregarElemento(valor);
                                cout << "Nodo agregado correctamente";
                                cout << endl;
                            }
                                break;
                            case ELIMINAR: {
                                arbol.EliminarRaiz();
                                cout << "Nodo eliminado correctamente";
                                cout << endl;
                            }
                                break;
                            case ELEMENTORAIZ: {
                                cout << "El elemento de la ra\41z del \240rbol es: " << arbol.ObtenerElementoRaiz()
                                     << endl;
                            }
                                break;
                            case ESTAVACIA: {
                                arbol.EstaVacia() ? cout << "\265rbol vac\241o" : cout << "\265rbol no vac\241o";
                                cout << endl;
                            }
                                break;
                            case VACIAR: {
                                arbol.Vaciar();
                                cout << "\240rbol vaciado correctamente" << endl;
                            }
                                break;
                            case NUMELEMENTOS: {
                                cout << "Elementos del \240rbol: " << arbol.ObtenerNumeroElementos() << endl;
                            }
                                break;
                            case CAPACIDAD: {
                                cout << "Capacidad del \240rbol: " << arbol.ObtenerCapacidad() << endl;
                            }
                                break;
                            case IMPRIMIR: {
                                arbol.Imprimir();
                            }
                                break;
                        }
                        cout << endl;
                        system("pause");
                        system("cls");
                    } while (opcion1 != 0);
                }
                    break;
                case DOUBLE: {
                    Heap<double, maximo> arbol;
                    int valor, opcion1;
                    do {
                        do {
                            menu();
                            CapturaSegura(opcion1, "Elija una opci\242n de la \240rbol: ");
                            if (opcion1 < 0 || opcion1 > 8) cout << "Fuera de rango..." << endl << endl;
                        } while (opcion1 < 0 || opcion1 > 8);
                        if (opcion1 == 0) {
                            system("pause");
                            return 0;
                        }
                        switch (opcion1) {
                            case AGREGAR: {
                                CapturaSegura(valor, "Ingrese el valor a agregar:");
                                arbol.AgregarElemento(valor);
                                cout << "Nodo agregado correctamente";
                                cout << endl;
                            }
                                break;
                            case ELIMINAR: {
                                arbol.EliminarRaiz();
                                cout << "Nodo eliminado correctamente";
                                cout << endl;
                            }
                                break;
                            case ELEMENTORAIZ: {
                                cout << "El elemento de la ra\41z del \240rbol es: " << arbol.ObtenerElementoRaiz()
                                     << endl;
                            }
                                break;
                            case ESTAVACIA: {
                                arbol.EstaVacia() ? cout << "\265rbol vac\241a" : cout << "\265rbol no vaci\241a";
                                cout << endl;
                            }
                                break;
                            case VACIAR: {
                                arbol.Vaciar();
                                cout << "\265rbol vaciado correctamente" << endl;
                            }
                                break;
                            case NUMELEMENTOS: {
                                cout << "Elementos del \240rbol: " << arbol.ObtenerNumeroElementos() << endl;
                            }
                                break;
                            case CAPACIDAD: {
                                cout << "Capacidad del \240rbol: " << arbol.ObtenerCapacidad() << endl;
                            }
                                break;
                            case IMPRIMIR: {
                                arbol.Imprimir();
                            }
                                break;
                        }
                        cout << endl;
                        system("pause");
                        system("cls");
                    } while (opcion1 != 0);
                }
                    break;
                case VECTOR: {
                    int opcion1;
                    int tam;
                    Heap<Vector, maximo> arbol;
                    do {
                        do {
                            menu();
                            CapturaSegura(opcion1, "Elija una opci\242n de la \240rbol: ");
                            if (opcion1 < 0 || opcion1 > 8) cout << "Fuera de rango..." << endl << endl;
                        } while (opcion1 < 0 || opcion1 > 8);
                        if (opcion1 == 0) {
                            system("pause");
                            return 0;
                        }
                        switch (opcion1) {
                            case AGREGAR: {
                                do {
                                    CapturaSegura(tam, "\250 Cu\240ntos elementos tiene el vector a agregar? :");
                                } while (tam < 0);
                                Vector val;
                                val.redimensionar(tam);
                                cout << "\250 Que elemento desea agregar? " << endl;
                                cin >> val;
                                arbol.AgregarElemento(val);
                                cout << "Nodo agregado correctamente";
                                cout << endl;
                            }
                                break;
                            case ELIMINAR: {
                                arbol.EliminarRaiz();
                                cout << "Nodo eliminado correctamente";
                                cout << endl;
                            }
                                break;
                            case ELEMENTORAIZ: {
                                cout << "El elemento de la ra\41z del \240rbol es: " << arbol.ObtenerElementoRaiz()
                                     << endl;
                            }
                                break;
                            case VACIAR: {
                                arbol.Vaciar();
                                cout << "\265rbol vaciado correctamente" << endl;
                            }
                                break;
                            case ESTAVACIA: {
                                arbol.EstaVacia() ? cout << "\240rbol vac\241o" : cout << "\240rbol no vaci\241o";
                                cout << endl;
                            }
                                break;
                            case NUMELEMENTOS: {
                                cout << "Elementos del \240rbol: " << arbol.ObtenerNumeroElementos() << endl;
                            }
                                break;
                            case CAPACIDAD: {
                                cout << "Capacidad del \240rbol: " << arbol.ObtenerCapacidad() << endl;
                            }
                                break;
                            case IMPRIMIR: {
                                arbol.Imprimir();
                            }
                                break;

                        }
                        cout << endl;
                        system("pause");
                        system("cls");
                    } while (opcion1 != 0);
                }
                    break;
            }
            system("pause");
            system("cls");

        } while (opcion != 0);
    } catch (std::out_of_range &exc) {
        cerr << exc.what();
        system("pause");
    } catch (std::exception &exc) {
        cerr << exc.what();
        system("pause");
    } catch (...) {
        cerr << "Ha ocurrido un error inesperado";
        system("pause");
    }
    return 0;
}
