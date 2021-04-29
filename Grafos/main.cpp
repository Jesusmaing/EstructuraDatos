/*
Nombre: main.cpp
Autor: Jesus Martin Garcia Encinas
Fecha: 09/04/2021
Descripción: Cliente para manipular los métodos de la clase Gráfica
*/

#include <iostream>
#include <cstdlib>
#include "Grafica.h"
#include "GestionLista.h"
#include "Utilerias.h"
#include "Vector.h"
using std::cout;
using std::cin;
using std::cerr;
using std::string;
using std::endl;

int main() {
    try {

        short opcion;
        cout << "Programa que para trabajar con 3 tipos diferentes de lista ordenadas...";
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
                case INT:    {
                    int valor1=0,  opcion1, valor2=0;
                    Grafica<int> g;
                    do {
                        do {
                            menu();
                            CapturaSegura(opcion1, "Elija una opci\242n de la lista: ");
                            if (opcion1 < 0 || opcion1 > 12) cout << "Fuera de rango..." << endl << endl;
                        } while (opcion1 < 0 || opcion1 > 12);
                        if (opcion1 == 0) {
                            system("pause");
                            return 0;
                        }
                        switch (opcion1) {
                            case AGREGAR_NODO:    {
                                CapturaSegura(valor1, "Ingrese el valor a agregar:");
                                g.Agregar(valor1);
                                cout << "Valor agregado correctamente" << endl;
                            }break;
                            case AGREGAR_ARISTA:   {
                                CapturaSegura(valor1, "Ingrese el primer extremo de la arista:");
                                CapturaSegura(valor2, "Ingrese el segundo extremo de la arista:");
                                g.Agregar(valor1,valor2);
                                cout << "Arista agregada correctamente..." << endl;
                            }break;
                            case ELIMINAR_NODO:     {
                                CapturaSegura(valor1, "Ingrese el valor del nodo a elimina:");
                                g.Eliminar(valor1);
                                cout << "Nodo eliminado correctamente..." << endl;
                            } break;
                            case ELIMINAR_ARISTA:     {
                                CapturaSegura(valor1, "Ingrese el primer extremo de la arista:");
                                CapturaSegura(valor2, "Ingrese el segundo extremo de la arista:");
                                g.Eliminar(valor1,valor2);
                                cout << "Arista eliminada correctamente..." << endl;
                            } break;
                            case BUSCAR_NODO:  {
                                CapturaSegura(valor1, "Ingrese el valor del nodo a buscar:");
                                g.Buscar(valor1) ? cout << "Nodo encontrado" : cout << "Nodo no encontrado";
                                cout << endl;
                            }break;
                            case BUSCAR_ARISTA:   {
                                CapturaSegura(valor1, "Ingrese el primer extremo de la arista:");
                                CapturaSegura(valor2, "Ingrese el segundo extremo de la arista:");
                                g.Buscar(valor1,valor2) ? cout << "Nodo encontrado" : cout << "Nodo no encontrado";
                                cout << endl;
                            }break;
                            case OBTENER_GRADO_NODO: {
                                CapturaSegura(valor1, "Ingrese el valor del nodo a buscar su grado:");
                                if (g.ObtenerGrado(valor1) != -1)
                                    cout << "El grado del nodo seleccionado es: " << g.ObtenerGrado(valor1);
                                else
                                    cout << "No existe el nodo ingresado...";
                                cout << endl;
                            }break;
                            case OBTENER_NODOS:{
                                cout << "Hay " << g.ObtenerNumNodos() << " nodos en total en la gr\240fica" << endl;
                            } break;
                            case OBTENER_ARISTAS:{
                                cout << "Hay " << g.ObtenerNumAristas() << " aristas en total en la gr\240fica" << endl;
                            } break;
                            case VACIAR:{
                                g.vaciar();
                                cout << "Gr\240fica vaciada correctamente..." << endl;
                            } break;
                            case VACIARNODO:{
                                CapturaSegura(valor1, "Ingrese el valor del nodo a vaciar:");
                                g.vaciar(valor1);
                                cout << "Nodo vaciado correctamente..." << endl;
                            } break;
                            case IMPRIMIR:{
                                g.Imprimir();
                                system("pause");
                            } break;
                        }
                        cout << endl;
                        system("pause");
                        system("cls");
                    }while(opcion1!= 0);
                } break;
                case DOUBLE:    {
                    int valor1=0,  opcion1, valor2=0;
                    Grafica<double> g;
                    do {
                        do {
                            menu();
                            CapturaSegura(opcion1, "Elija una opci\242n de la lista: ");
                            if (opcion1 < 0 || opcion1 > 12) cout << "Fuera de rango..." << endl << endl;
                        } while (opcion1 < 0 || opcion1 > 12);
                        if (opcion1 == 0) {
                            system("pause");
                            return 0;
                        }
                        switch (opcion1) {
                            case AGREGAR_NODO:    {
                                CapturaSegura(valor1, "Ingrese el valor a agregar:");
                                g.Agregar(valor1);
                                cout << "Valor agregado correctamente" << endl;
                            }break;
                            case AGREGAR_ARISTA:   {
                                CapturaSegura(valor1, "Ingrese el primer extremo de la arista:");
                                CapturaSegura(valor2, "Ingrese el segundo extremo de la arista:");
                                g.Agregar(valor1,valor2);
                                cout << "Arista agregada correctamente..." << endl;
                            }break;
                            case ELIMINAR_NODO:     {
                                CapturaSegura(valor1, "Ingrese el valor del nodo a elimina:");
                                g.Eliminar(valor1);
                                cout << "Nodo eliminado correctamente..." << endl;
                            } break;
                            case ELIMINAR_ARISTA:     {
                                CapturaSegura(valor1, "Ingrese el primer extremo de la arista:");
                                CapturaSegura(valor2, "Ingrese el segundo extremo de la arista:");
                                g.Eliminar(valor1,valor2);
                                cout << "Arista eliminada correctamente..." << endl;
                            } break;
                            case BUSCAR_NODO:  {
                                CapturaSegura(valor1, "Ingrese el valor del nodo a buscar:");
                                g.Buscar(valor1) ? cout << "Nodo encontrado" : cout << "Nodo no encontrado";
                                cout << endl;
                            }break;
                            case BUSCAR_ARISTA:   {
                                CapturaSegura(valor1, "Ingrese el primer extremo de la arista:");
                                CapturaSegura(valor2, "Ingrese el segundo extremo de la arista:");
                                g.Buscar(valor1,valor2) ? cout << "Nodo encontrado" : cout << "Nodo no encontrado";
                                cout << endl;
                            }break;
                            case OBTENER_GRADO_NODO: {
                                CapturaSegura(valor1, "Ingrese el valor del nodo a buscar su grado:");
                                if (g.ObtenerGrado(valor1) != -1)
                                    cout << "El grado del nodo seleccionado es: " << g.ObtenerGrado(valor1);
                                else
                                    cout << "No existe el nodo ingresado...";
                                cout << endl;
                            }break;
                            case OBTENER_NODOS:{
                                cout << "Hay " << g.ObtenerNumNodos() << " nodos en total en la gr\240fica" << endl;
                            } break;
                            case OBTENER_ARISTAS:{
                                cout << "Hay " << g.ObtenerNumAristas() << " aristas en total en la gr\240fica" << endl;
                            } break;
                            case VACIAR:{
                                g.vaciar();
                                cout << "Gr\240fica vaciada correctamente..." << endl;
                            } break;
                            case VACIARNODO:{
                                CapturaSegura(valor1, "Ingrese el valor del nodo a vaciar:");
                                g.vaciar(valor1);
                                cout << "Nodo vaciado correctamente..." << endl;
                            } break;
                            case IMPRIMIR:{
                                g.Imprimir();
                            } break;
                        }
                        cout << endl;
                        system("pause");
                        system("cls");
                    }while(opcion1!= 0);
                } break;
                case VECTOR:    {
                    int opcion1;
                    int tam;
                    Grafica<Vector> g;
                    do {
                        do {
                            menu();
                            CapturaSegura(opcion1, "Elija una opci\242n de la lista: ");
                            if (opcion1 < 0 || opcion1 > 12) cout << "Fuera de rango..." << endl << endl;
                        } while (opcion1 < 0 || opcion1 > 12);
                        if (opcion1 == 0) {
                            system("pause");
                            return 0;
                        }
                        switch (opcion1) {
                            case AGREGAR_NODO: {
                                do {
                                    CapturaSegura(tam, "\250 Cu\240ntos elementos tiene el vector a agregar? :");
                                } while (tam < 0);
                                Vector val;
                                val.redimensionar(tam);
                                cout << "\250 Que elemento desea agregar? " << endl;
                                cin >> val;
                                g.Agregar(val);
                                cout << "Valor agregado correctamente" << endl;
                            }break;
                            case AGREGAR_ARISTA:   {
                                do {
                                    CapturaSegura(tam, "\250 Cu\240ntos elementos tiene el vector del extremo inferior a agregar? :");
                                } while (tam < 0);
                                Vector val1;
                                val1.redimensionar(tam);
                                cout << "\250 Ingrese el id del vector para agregar su arista? " << endl;
                                cin >> val1;


                                do {
                                    CapturaSegura(tam, "\250 Cu\240ntos elementos tiene el vector del extremo superior a agregar? :");
                                } while (tam < 0);
                                Vector val2;
                                val2.redimensionar(tam);
                                cout << "\250 Ingrese el id del vector para agregar su arista? " << endl;
                                cin >> val2;
                                g.Agregar(val1,val2);
                                cout << "Arista agregada correctamente" << endl;
                            }break;
                            case ELIMINAR_NODO:     {
                                do {
                                    CapturaSegura(tam, "\250 Cu\240ntos elementos tiene el vector a eliminar? : ");
                                }while(tam < 0);
                                Vector val;
                                val.redimensionar(tam);
                                cout << "Ingrese el vector a eliminar: " << endl;
                                cin >> val;
                                g.Eliminar(val);
                                cout << "Nodo eliminado correctamente..." << endl;
                            } break;
                            case ELIMINAR_ARISTA:     {
                                do {
                                    CapturaSegura(tam, "\250 Cu\240ntos elementos tiene el vector del extremo inferior a eliminar? :");
                                } while (tam < 0);
                                Vector val1;
                                val1.redimensionar(tam);
                                cout << "\250 Ingrese el id del vector para eliminar su arista? " << endl;
                                cin >> val1;

                                do {
                                    CapturaSegura(tam, "\250 Cu\240ntos elementos tiene el vector del extremo superior a eliminar? :");
                                } while (tam < 0);
                                Vector val2;
                                val2.redimensionar(tam);
                                cout << "\250 Ingrese el id del vector para eliminar su arista? " << endl;
                                cin >> val2;

                                g.Eliminar(val1,val2);
                                cout << "Arista eliminada correctamente" << endl;
                            } break;
                            case BUSCAR_NODO:  {
                                do {
                                    CapturaSegura(tam, "\250 Cu\240ntos elementos tiene el vector a buscar? :");
                                }while(tam < 0);
                                Vector val;
                                val.redimensionar(tam);
                                cout << "Ingrese el vector a buscar: " << endl;
                                cin >> val;
                                g.Buscar(val) ? cout << "Nodo encontrado" : cout << "Nodo no encontrado";
                                cout << endl;
                            }break;
                            case BUSCAR_ARISTA:   {

                                do {
                                    CapturaSegura(tam, "\250 Cu\240ntos elementos tiene el vector del extremo inferior a buscar? :");
                                } while (tam < 0);
                                Vector val1;
                                val1.redimensionar(tam);
                                cout << "\250 Ingrese el id del vector para buscar su arista " << endl;
                                cin >> val1;

                                do {
                                    CapturaSegura(tam, "\250 Cu\240ntos elementos tiene el vector del extremo superior a buscar? :");
                                } while (tam < 0);
                                Vector val2;
                                val2.redimensionar(tam);
                                cout << "\250 Ingrese el id del vector para buscar su arista " << endl;

                                cin >> val2;
                                g.Buscar(val1,val2) ? cout << "Ariesta encontrada" : cout << "Arista no encontrada";
                                cout << endl;
                            }break;
                            case OBTENER_GRADO_NODO: {
                                do {
                                    CapturaSegura(tam, "\250 Cu\240ntos elementos tiene el vector a obtener su grado? :");
                                }while(tam < 0);
                                Vector val;
                                val.redimensionar(tam);
                                cout << "Ingrese el vector a obtener su grado: " << endl;
                                cin >> val;
                                if (g.ObtenerGrado(val) != -1)
                                    cout << "El grado del nodo seleccionado es: " << g.ObtenerGrado(val);
                                else
                                    cout << "No existe el nodo ingresado...";
                                cout << endl;
                            }break;
                            case OBTENER_NODOS:{
                                cout << "Hay " << g.ObtenerNumNodos() << " nodos en total en la gr\240fica" << endl;
                            } break;
                            case OBTENER_ARISTAS:{
                                cout << "Hay " << g.ObtenerNumAristas() << " aristas en total en la gr\240fica" << endl;
                            } break;
                            case VACIAR:{
                                g.vaciar();
                                cout << "Gr\240fica vaciada correctamente..." << endl;
                            } break;
                            case VACIARNODO:{
                                do {
                                    CapturaSegura(tam, "\250 Cu\240ntos elementos tiene el vector a vaciar? :");
                                }while(tam < 0);
                                Vector val;
                                val.redimensionar(tam);
                                cout << "Ingrese el vector a vaciar: " << endl;
                                cin >> val;
                                g.vaciar(val);
                                cout << "Nodo vaciado correctamente..." << endl;
                            } break;
                            case IMPRIMIR:{
                                g.Imprimir();
                            } break;
                        }
                        cout << endl;
                        system("pause");
                        system("cls");
                    }while(opcion1!= 0);
                } break;

            }
            system("pause");
            system("cls");

        }while (opcion != 0);
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
