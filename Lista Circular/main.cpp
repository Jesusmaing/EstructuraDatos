/*
Nombre: ListaCircular.tpp
Autor: Jesus Martin Garcia Encinas
Fecha: 26/03/2021
Descripción: Aplicación de una lista enlazada doble
*/


#include <iostream>
#include <cstdlib>
#include "GestionLista.h"
#include "Utilerias.h"
#include "Lista.h"
#include "Vector.h"
using std::cout;
using std::cin;
using std::cerr;
using std::string;
using std::endl;



int main() {
    try {

        short opcion;
        cout << "Programa que para trabajar con 3 tipos diferentes de lista doblemente circular...";
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
                    int valor,  opcion1;
                    Lista<int> lista;
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
                            case AGREGAR:    {
                                CapturaSegura(valor, "Ingrese el valor a agregar:");
                                lista.agregar(valor);
                                cout << "Valor agregado correctamente" << endl;
                            }break;
                            case ELIMINAR:   {
                                if(lista.estaVacia()) cout << "La lista esta vac\241a..." << endl;
                                else {
                                    cout << "Se ha eliminado el elemento: " << lista.eliminar() << endl;
                                }
                                break;
                            }
                            case ELIMINAROCURRENCIA:   {
                                if(lista.estaVacia()) cout << "La lista esta vac\241a..." << endl;
                                else {
                                    CapturaSegura(valor, "Ingrese el valor a eliminar:");
                                    lista.eliminarPrimeraOcurrencia(valor);
                                    cout << "Se ha eliminado correctamente..." << endl;
                                }
                                break;
                            }

                            case ELIMINARPOROCURRENCIAS:   {
                                if(lista.estaVacia()) cout << "La lista esta vac\241a..." << endl;
                                else {
                                    CapturaSegura(valor, "Ingrese el valor a eliminar:");
                                    lista.eliminarTodaOcurrencia(valor);
                                    cout << "Se ha eliminado correctamente... " << endl;
                                }
                                break;
                            }

                            case AVANZARCABEZA:   {
                                if(lista.estaVacia()) cout << "La lista esta vac\241a..." << endl;
                                else {
                                    lista.avanzar();
                                    cout << "Se ha avanzado a la siguiente posici\242n... " << endl;
                                }
                                break;
                            }

                            case RETROCEDERCABEZA:   {
                                if(lista.estaVacia()) cout << "La lista esta vac\241a..." << endl;
                                else {
                                    lista.retroceder();
                                    cout << "Se ha retrocedido a la anterior posici\242n... " << endl;
                                }
                                break;
                            }

                            case CONOCERCABEZA:   {
                                if(lista.estaVacia()) cout << "La lista esta vac\241a..." << endl;
                                else {
                                    cout << "El valor actual de la cabeza es.. " << lista.obtenerValor() << endl;
                                }
                                break;
                            }

                            case BUSCAR:     {
                                CapturaSegura(valor, "Ingrese el valor a buscar:");
                                lista.buscar(valor) ? cout << "Valor encontrado" : cout
                                        << "Valor no encontrado";
                                cout << endl;
                            } break;
                            case VACIAR:     {
                                lista.vaciar();
                                cout << "Lista vaciada correctamente" << endl;
                            } break;
                            case ESTAVACIA:  {
                                lista.estaVacia() ? cout << "Lista vac\241a" : cout << "Lista no vaci\241a";
                                cout << endl;
                            }break;
                            case TAMLISTA:   {
                                cout << "El tamano de la lista es de: " << lista.obtenerTam() << endl;
                            }break;
                            case IMPRIMIR: {
                                lista.imprimir();
                            }break;


                        }
                        cout << endl;
                        system("pause");
                        system("cls");
                    }while(opcion1!= 0);
                } break;

                case DOUBLE: {
                    int valor,  opcion1;
                    Lista<double> lista;
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
                            case AGREGAR:    {
                                CapturaSegura(valor, "Ingrese el valor a agregar:");
                                lista.agregar(valor);
                                cout << "Valor agregado correctamente" << endl;
                            }break;
                            case ELIMINAR:   {
                                if(lista.estaVacia()) cout << "La lista esta vac\241a..." << endl;
                                else {
                                    cout << "Se ha eliminado el elemento: " << lista.eliminar() << endl;
                                }
                                break;
                            }
                            case ELIMINAROCURRENCIA:   {
                                if(lista.estaVacia()) cout << "La lista esta vac\241a..." << endl;
                                else {
                                    CapturaSegura(valor, "Ingrese el valor a eliminar:");
                                    lista.eliminarPrimeraOcurrencia(valor);
                                    cout << "Se ha eliminado correctamente..." << endl;
                                }
                                break;
                            }

                            case ELIMINARPOROCURRENCIAS:   {
                                if(lista.estaVacia()) cout << "La lista esta vac\241a..." << endl;
                                else {
                                    CapturaSegura(valor, "Ingrese el valor a eliminar:");
                                    lista.eliminarTodaOcurrencia(valor);
                                    cout << "Se ha eliminado correctamente... " << endl;
                                }
                                break;
                            }

                            case AVANZARCABEZA:   {
                                if(lista.estaVacia()) cout << "La lista esta vac\241a..." << endl;
                                else {
                                    lista.avanzar();
                                    cout << "Se ha avanzado a la siguiente posici\242n... " << endl;
                                }
                                break;
                            }

                            case RETROCEDERCABEZA:   {
                                if(lista.estaVacia()) cout << "La lista esta vac\241a..." << endl;
                                else {
                                    lista.retroceder();
                                    cout << "Se ha retrocedido a la anterior posici\242n... " << endl;
                                }
                                break;
                            }

                            case CONOCERCABEZA:   {
                                if(lista.estaVacia()) cout << "La lista esta vac\241a..." << endl;
                                else {
                                    cout << "El valor actual de la cabeza es.. " << lista.obtenerValor() << endl;
                                }
                                break;
                            }

                            case BUSCAR:     {
                                CapturaSegura(valor, "Ingrese el valor a buscar:");
                                lista.buscar(valor) ? cout << "Valor encontrado" : cout
                                        << "Valor no encontrado";
                                cout << endl;
                            } break;
                            case VACIAR:     {
                                lista.vaciar();
                                cout << "Lista vaciada correctamente" << endl;
                            } break;
                            case ESTAVACIA:  {
                                lista.estaVacia() ? cout << "Lista vac\241a" : cout << "Lista no vaci\241a";
                                cout << endl;
                            }break;
                            case TAMLISTA:   {
                                cout << "El tamano de la lista es de: " << lista.obtenerTam() << endl;
                            }break;
                            case IMPRIMIR: {
                                lista.imprimir();
                            }break;
                        }
                        cout << endl;
                        system("pause");
                        system("cls");
                    }while(opcion1!= 0);
                } break;

                case VECTOR: {
                    int opcion1, tam=0;
                    Lista<Vector> lista;
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
                            case AGREGAR:    {
                                do {
                                    CapturaSegura(tam, "\250 Cu\240ntos elementos tiene el vector a agregar? :");
                                }while(tam < 0);
                                Vector val;
                                val.redimensionar(tam);
                                cout << "\250 Que elemento desea agregar? " << endl;
                                cin >> val;
                                lista.agregar(val);
                                cout << "Valor agregado correctamente" << endl;
                            }break;
                            case ELIMINAR:   {
                                if(lista.estaVacia()) cout << "La lista esta vac\241a..." << endl;
                                else {
                                    cout << "Se ha eliminado el elemento: " << lista.eliminar() << endl;
                                }

                            }break;
                            case ELIMINAROCURRENCIA:   {
                                do {
                                    CapturaSegura(tam, "\250 Cu\240ntos elementos tiene el vector a eliminar? : ");
                                }while(tam < 0);
                                Vector val;
                                val.redimensionar(tam);
                                cout << "Ingrese el vector a eliminar: " << endl;
                                cin >> val;
                                lista.eliminarPrimeraOcurrencia(val);
                                cout << "Se ha eliminado correctamente..." << endl;
                                }break;


                            case ELIMINARPOROCURRENCIAS:   {
                                do {
                                    CapturaSegura(tam, "\250 Cu\240ntos elementos tiene el vector a eliminar? : ");
                                }while(tam < 0);
                                Vector val;
                                val.redimensionar(tam);
                                cout << "Ingrese el vector a eliminar: " << endl;
                                cin >> val;
                                lista.eliminarTodaOcurrencia(val);
                                cout << "Se ha eliminado correctamente..." << endl;
                                }break;

                            case AVANZARCABEZA:   {
                                if(lista.estaVacia()) cout << "La lista esta vac\241a..." << endl;
                                else {
                                    lista.avanzar();
                                    cout << "Se ha avanzado a la siguiente posici\242n... " << endl;
                                }
                                break;
                            }

                            case RETROCEDERCABEZA:   {
                                if(lista.estaVacia()) cout << "La lista esta vac\241a..." << endl;
                                else {
                                    lista.retroceder();
                                    cout << "Se ha retrocedido a la anterior posici\242n... " << endl;
                                }
                                break;
                            }

                            case CONOCERCABEZA:   {
                                if(lista.estaVacia()) cout << "La lista esta vac\241a..." << endl;
                                else {
                                    cout << "El valor actual de la cabeza es.. " << lista.obtenerValor() << endl;
                                }
                                break;
                            }

                            case BUSCAR:      {
                                do {
                                    CapturaSegura(tam, "\250 Cu\240ntos elementos tiene el vector a buscar? :");
                                }while(tam < 0);
                                Vector val;
                                val.redimensionar(tam);
                                cout << "Ingrese el vector a buscar: " << endl;
                                cin >> val;
                                lista.buscar(val) ? cout << "Vector encontrado" : cout << "Vector no encontrado";
                                cout << endl;
                            }break;
                            case VACIAR:     {
                                lista.vaciar();
                                cout << "Lista vaciada correctamente" << endl;
                            } break;
                            case ESTAVACIA:  {
                                lista.estaVacia() ? cout << "Lista vac\241a" : cout << "Lista no vaci\241a";
                                cout << endl;
                            }break;
                            case TAMLISTA:   {
                                cout << "El tamano de la lista es de: " << lista.obtenerTam() << endl;
                            }break;
                            case IMPRIMIR: {
                                lista.imprimir();
                            }break;
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
