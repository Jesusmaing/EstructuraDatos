/*
Nombre: main.cpp
Autor: Sebastian Guadalupe Rivera de la Cruz
Fecha: 14/02/2021
Descripción; Programa principal que permite probar la clase Pila con tres diferentes tipos(Double, String, Vector).
*/

#include <iostream>
#include "Pila.h"
#include "Vector.h"
#include "Utilerias.h"
using namespace std;

void Imprimir_menu1(){
    cout << "Elija el tipo de Pila." << endl;
    cout << "0)Salir" << endl;
    cout << "1)Tipo Double" << endl;
    cout << "2)Tipo String" << endl;
    cout << "3)Tipo Vector(doubles)" << endl;

}




int main() {
    try{
        short opcion;
        cout << "Programa que utiliza las plantillas de pilas para trabajar con 3 tipos diferentes..." << endl;
        do{
                Imprimir_menu1();

        /***********************************************
        *   CAPTURAR DE MANERA SEGURA LA OPCIÓN        *
        ************************************************/
            do {
                CapturaSegura(opcion, "Elija opci\242n: ");
                if (opcion < 0 || opcion > 3) cout << "Fuera de rango..." << endl << endl;
            } while (opcion < 0 || opcion > 3);
            if (opcion == 0) {
                system("pause");
                return 0;
            }
            system("cls");
        /**************************************************/
            switch (opcion) {
                case DOUBLE: {
                    Pila<> pilaD;
                    do{
                        opcion = menuOperaciones();
                        if (opcion == 0) {
                            system("pause");
                            break;
                        }
                        switch (opcion) {
                            case AGREGAR: {
                                unsigned int cantidad;
                                double valor;
                                cout << "\250Cuantos elementos desea agregar?: ";
                                cin >> cantidad;
                                for (unsigned int i = 0; i < cantidad; ++i) {
                                    cout << "Ingrese el elemento #" << i + 1 << " : ";
                                    cin >> valor;
                                    pilaD.agregar(valor);
                                }
                                break;
                            }
                            case ELIMINAR: {
                                unsigned int cantidad;
                                cout << "\250Cuantos elementos desea eliminar?: ";
                                std::cin >> cantidad;
                                for (unsigned int i = 0; i < cantidad; ++i) pilaD.eliminar();
                                break;
                            }
                            case OBTENERTOPE:
                                cout << "Tope: \n" << pilaD.obtenerTope() << endl;
                                break;
                            case ESTAVACIA:
                                if(pilaD.estaVacia()) cout << "La pila esta vac\241a..." << endl;
                                else cout << "La pila no esta vac\241a..." << endl;
                                break;
                            case VACIAR:
                                pilaD.vaciar();
                                cout << "La pila se ha vaciado con \202xito." << std::endl;
                                break;
                            case TAMANIO:
                                cout << "El tama\244o actual de la pila es de " << pilaD.obtenerTam() << " elementos." << endl;
                                break;
                            case CAPACIDAD:
                                cout << "La capacidad actual de la pila es de " << pilaD.obtenerCap() << " elementos." << endl;
                                break;
                            case IMPRIMIR:
                                pilaD.imprimir();
                                break;
                        }
                        system("pause");
                        system("cls");
                    } while (opcion != 0);
                    break;
                }
                case STRING: {
                    Pila<string> pilaS;
                    do{
                        opcion = menuOperaciones();
                        if (opcion == 0) {
                            system("pause");
                            break;
                        }
                        system("cls");
                        switch (opcion) {
                            case AGREGAR: {
                                unsigned int cantidad;
                                string valor;
                                cout << "\250Cuantos elementos desea agregar?: ";
                                cin >> cantidad;
                                for (unsigned int i = 0; i < cantidad; ++i) {
                                    cout << "Ingrese el elemento #" << i + 1 << " : ";
                                    cin >> valor;
                                    pilaS.agregar(valor);
                                }
                                break;
                            }
                            case ELIMINAR: {
                                unsigned int cantidad;
                                std::cout << "\250Cuantos elementos desea eliminar?: ";
                                std::cin >> cantidad;
                                for (unsigned int i = 0; i < cantidad; ++i) pilaS.eliminar();
                                break;
                            }
                            case OBTENERTOPE:
                                std::cout << "Tope: \n" << pilaS.obtenerTope() << std::endl;
                                break;
                            case ESTAVACIA:
                                if(pilaS.estaVacia()) cout << "La pila esta vac\241a..." << endl;
                                else cout << "La pila no esta vac\241a..." << endl;
                                break;
                            case VACIAR:
                                pilaS.vaciar();
                                std::cout << "La pila se ha vaciado con \202xito." << std::endl;
                                break;
                            case TAMANIO:
                                std::cout << "El tama\244o actual de la pila es de " << pilaS.obtenerTam() << " elementos." << std::endl;
                                break;
                            case CAPACIDAD:
                                std::cout << "La capacidad actual de la pila es de " << pilaS.obtenerCap() << " elementos." << std::endl;
                                break;
                            case IMPRIMIR:
                                pilaS.imprimir();
                                break;
                        }
                        system("pause");
                        system("cls");
                    } while (opcion != 0);
                    break;
                }
                case VECTOR: {
                    Pila<Vector> pilaV;
                    do{
                        opcion = menuOperaciones();
                        if (opcion == 0) {
                            system("pause");
                            break;
                        }
                        unsigned int cantidad;
                        int t;
                        switch (opcion) {
                            case AGREGAR: {
                                cout << "\250Cuantos vectores desea agregar?: ";
                                cin >> cantidad;
                                CapturaSegura(t,"Ingrese el tama\244o de los vectores: ");
                                Vector vector(t);
                                for (unsigned int i = 0; i < cantidad; ++i) {
                                    cout << "Vector # " << i+1 << endl;
                                    cin >> vector;
                                    pilaV.agregar(vector);
                                }
                                break;
                            }
                            case ELIMINAR: {
                                unsigned int cantidad;
                                std::cout << "\250Cuantos elementos desea eliminar?: ";
                                std::cin >> cantidad;
                                for (unsigned int i = 0; i < cantidad; ++i) pilaV.eliminar();
                                break;
                            }
                            case OBTENERTOPE:
                                std::cout << "Tope: \n" << pilaV.obtenerTope() << std::endl;
                                break;
                            case ESTAVACIA:
                                if(pilaV.estaVacia()) cout << "La pila esta vac\241a..." << endl;
                                else cout << "La pila no esta vac\241a..." << endl;
                                break;
                            case VACIAR:
                                pilaV.vaciar();
                                std::cout << "La pila se ha vaciado con \202xito." << std::endl;
                                break;
                            case TAMANIO:
                                std::cout << "El tama\244o actual de la pila es de " << pilaV.obtenerTam() << " elementos." << std::endl;
                                break;
                            case CAPACIDAD:
                                std::cout << "La capacidad actual de la pila es de " << pilaV.obtenerCap() << " elementos." << std::endl;
                                break;
                            case IMPRIMIR:
                                pilaV.imprimir();
                                break;
                        }
                        system("pause");
                        system("cls");
                    } while (opcion != 0);
                    break;
                }
            }


        } while (opcion != 0);
    }catch (std::exception &exc){
        std::cerr << exc.what();
        system("pause");
    } catch (...) {
        std::cerr << "Ha ocurrido un error inesperado";
        system("pause");
    }
    return 0;
}
