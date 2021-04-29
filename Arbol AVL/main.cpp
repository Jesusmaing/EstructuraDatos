/*
Nombre: Arbol semibalanceado
Autor: Jesus Martin Garcia Encinas
Fecha: 22/04/2021
Descripción: Aplicación de una arbol semibalanceado
*/


#include <iostream>
#include <cstdlib>
#include "GestionLista.h"
#include "Utilerias.h"
#include "AVL.h"
#include "Vector.h"

using std::cout;
using std::cin;
using std::cerr;
using std::string;
using std::endl;


int main() {
    try {

        short opcion;
        cout << "Programa que para trabajar con 3 tipos diferentes de arbol semibalanceado...";
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
                    int valor, opcion1;
                    AVL<int> arbol;
                    do {
                        do {
                            menu();
                            CapturaSegura(opcion1, "Elija una opci\242n de la arbol: ");
                            if (opcion1 < 0 || opcion1 > 9) cout << "Fuera de rango..." << endl << endl;
                        } while (opcion1 < 0 || opcion1 > 9);
                        if (opcion1 == 0) {
                            system("pause");
                            return 0;
                        }
                        switch (opcion1) {
                            case AGREGAR: {
                                CapturaSegura(valor, "Ingrese el valor a agregar:");
                                arbol.AgregarElemento(valor) ? cout << "Nodo agregado correctamente" : cout
                                        << "No se ha podido agregar el nodo";
                                cout << endl;
                            }
                                break;
                            case ELIMINAR: {
                                CapturaSegura(valor, "Ingrese el valor a eliminar:");
                                arbol.EliminarElemento(valor) ? cout << "Nodo eliminado correctamente" : cout
                                        << "No se ha podido eliminar el nodo";
                                cout << endl;
                            }
                                break;
                            case BUSCAR: {
                                CapturaSegura(valor, "Ingrese el valor a buscar:");
                                arbol.BuscarElemento(valor) ? cout << "Valor encontrado" : cout
                                        << "Valor no encontrado";
                                cout << endl;
                            }
                                break;
                            case NUMNODOS: {
                                cout << "El tama\244o de la arbol es de: " << arbol.NumVertices() << endl;
                            }
                                break;
                            case VACIAR: {
                                arbol.Vaciar();
                                cout << "arbol vaciado correctamente" << endl;
                            }
                                break;
                            case ESTAVACIA: {
                                arbol.EstaVacia() ? cout << "arbol vac\241a" : cout << "arbol no vaci\241a";
                                cout << endl;
                            }
                                break;
                            case ASCENDENTE: {
                                arbol.Imprimir(1);
                            }
                                break;
                            case DESCENDENTE: {
                                arbol.Imprimir(2);
                            }
                                break;
                            case NIVELES: {
                                arbol.Imprimir(3);
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
                    int valor, opcion1;
                    AVL<double> arbol;
                    do {
                        do {
                            menu();
                            CapturaSegura(opcion1, "Elija una opci\242n de la arbol: ");
                            if (opcion1 < 0 || opcion1 > 9) cout << "Fuera de rango..." << endl << endl;
                        } while (opcion1 < 0 || opcion1 > 9);
                        if (opcion1 == 0) {
                            system("pause");
                            return 0;
                        }
                        switch (opcion1) {
                            case AGREGAR: {
                                CapturaSegura(valor, "Ingrese el valor a agregar:");
                                arbol.AgregarElemento(valor) ? cout << "Nodo agregado correctamente" : cout
                                        << "No se ha podido agregar el nodo";
                                cout << endl;
                            }
                                break;
                            case ELIMINAR: {
                                CapturaSegura(valor, "Ingrese el valor a eliminar:");
                                arbol.EliminarElemento(valor) ? cout << "Nodo eliminado correctamente" : cout
                                        << "No se ha podido eliminar el nodo";
                                cout << endl;
                            }
                                break;
                            case BUSCAR: {
                                CapturaSegura(valor, "Ingrese el valor a buscar:");
                                arbol.BuscarElemento(valor) ? cout << "Valor encontrado" : cout
                                        << "Valor no encontrado";
                                cout << endl;
                            }
                                break;
                            case NUMNODOS: {
                                cout << "El tama\244o de la arbol es de: " << arbol.NumVertices() << endl;
                            }
                                break;
                            case VACIAR: {
                                arbol.Vaciar();
                                cout << "arbol vaciado correctamente" << endl;
                            }
                                break;
                            case ESTAVACIA: {
                                arbol.EstaVacia() ? cout << "arbol vac\241a" : cout << "arbol no vaci\241a";
                                cout << endl;
                            }
                                break;
                            case ASCENDENTE: {
                                arbol.Imprimir(1);
                            }
                                break;
                            case DESCENDENTE: {
                                arbol.Imprimir(2);
                            }
                                break;
                            case NIVELES: {
                                arbol.Imprimir(3);
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
                    AVL<Vector> arbol;
                    do {
                        do {
                            menu();
                            CapturaSegura(opcion1, "Elija una opci\242n de la arbol: ");
                            if (opcion1 < 0 || opcion1 > 9) cout << "Fuera de rango..." << endl << endl;
                        } while (opcion1 < 0 || opcion1 > 9);
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
                                arbol.AgregarElemento(val) ? cout << "Nodo agregado correctamente" : cout
                                        << "No se ha podido agregar el nodo";
                                cout << endl;
                            }
                                break;
                            case ELIMINAR: {
                                do {
                                    CapturaSegura(tam, "\250 Cu\240ntos elementos tiene el vector a eliminar? : ");
                                } while (tam < 0);
                                Vector val;
                                val.redimensionar(tam);
                                cout << "Ingrese el vector a eliminar: " << endl;
                                cin >> val;
                                arbol.EliminarElemento(val) ? cout << "Nodo eliminado correctamente" : cout
                                        << "No se ha podido eliminar el nodo";
                                cout << endl;
                            }
                                break;
                            case BUSCAR: {
                                do {
                                    CapturaSegura(tam, "\250 Cu\240ntos elementos tiene el vector a buscar? :");
                                } while (tam < 0);
                                Vector val;
                                val.redimensionar(tam);
                                cout << "Ingrese el vector a buscar: " << endl;
                                cin >> val;
                                arbol.BuscarElemento(val) ? cout << "Vector encontrado" : cout
                                        << "Vector no encontrado";
                                cout << endl;
                            }
                                break;
                            case NUMNODOS: {
                                cout << "El tamano de la arbol es de: " << arbol.NumVertices() << endl;
                            }
                                break;
                            case VACIAR: {
                                arbol.Vaciar();
                                cout << "arbol vaciada correctamente" << endl;
                            }
                                break;
                            case ESTAVACIA: {
                                arbol.EstaVacia() ? cout << "arbol vac\241a" : cout << "arbol no vaci\241a";
                                cout << endl;
                            }
                                break;
                            case ASCENDENTE: {
                                arbol.Imprimir(1);
                            }
                                break;
                            case DESCENDENTE: {
                                arbol.Imprimir(2);
                            }
                                break;
                            case NIVELES: {
                                arbol.Imprimir(3);
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
