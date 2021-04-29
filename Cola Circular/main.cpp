/*
Nombre: Cola Circular
Autor: JESUS MARTIN GARCIA ENCINAS
Fecha: 2/3/2021
*/


#include <iostream>
#include <cstdlib>
#include <string>

#include "Utilerias.h"
#include "GestionCola.h"
#include "ColaCircular.h"


using namespace std;
int main() {
    try {
        int cantidad = 0;
        unsigned short opcion_menu1;
        unsigned short opcion_menu2;
        do {
            system("cls");
            opcion_menu1 = menu_1();

            switch (opcion_menu1) {
            case SALIR:       break;
            case INT:    {
                ColaCircular<int> colaI;
                do {
                    opcion_menu2 = menu_2();
                    system("cls");
                    switch (opcion_menu2) {
                        case ENCOLAR:              {
                            int valor;
                            CapturaSegura(cantidad, "\250Cu\240ntos elementos desea encolar?: ");
                            for (int i = 0; i < cantidad; ++i) {
                                CapturaSegura(valor, "Ingrese el elemento");
                                colaI.encolar(valor);
                            }
                        }  break;
                        case DESENCOLAR:           {
                            if (colaI.estaVacia()) cout << "La cola est\240  vac\241a..." << endl;
                            else {
                                CapturaSegura(cantidad, "\250Cu\240ntos elementos desea desencolar?: ");
                                for (int i = 0; i < cantidad; ++i) colaI.desencolar();
                            }
                        }  break;
                        case IMPRIMIR:             {
                            colaI.Imprimir();
                        }  break;
                        case CONOCER_SI_ESTA_VACIA:{
                            if (colaI.estaVacia()) cout << "La cola est\240 vac\241a..." << endl;
                            else cout << "La cola no est\240 vac\241a..." << endl;
                        }  break;
                        case OBTENER_TAMANO:       {
                            cout << "El tama\244o es " << colaI.obtenerTam() << " elementos."
                                 << endl;

                        }  break;
                        case VACIAR_COLA:          {
                            if (colaI.estaVacia()) cout << "La cola esta vac\241a..." << endl;
                            else colaI.vaciar();
                            cout << "La cola se ha vaciado correctamente." << endl;

                        }  break;
                        case OBTENER_PRIMER_VALOR: {
                            if (colaI.estaVacia()) cout << "La cola est\240  vac\241a..." << endl;
                            else {
                                cout << "Primero: \n" << colaI.obtenerPrimero() << endl;
                            }
                        }  break;
                        case OBTENER_ULTIMO_VALOR: {
                            if (colaI.estaVacia()) cout << "La cola est\240  vac\241a..." << endl;
                            else {
                                cout << "\351ltimo: \n" << colaI.obtenerUltimo() << endl;
                            }
                        }  break;
                    }
                    system("pause");
                }while(opcion_menu2 != 0);
            }break;
            case DOUBLE: {
                ColaCircular<double> colaI;
                do {
                    opcion_menu2 = menu_2();
                    system("cls");
                    switch (opcion_menu2) {
                        case ENCOLAR:              {
                            double valor;
                            CapturaSegura(cantidad, "\250Cu\240ntos elementos desea encolar?: ");
                            for (int i = 0; i < cantidad; ++i) {
                                CapturaSegura(valor, "Ingrese el elemento");
                                colaI.encolar(valor);
                            }
                        }  break;
                        case DESENCOLAR:           {
                            if (colaI.estaVacia()) cout << "La cola est\240  vac\241a..." << endl;
                            else {
                                CapturaSegura(cantidad, "\250Cu\240ntos elementos desea desencolar?: ");
                                for (int i = 0; i < cantidad; ++i) colaI.desencolar();
                            }
                        }  break;
                        case IMPRIMIR:             {
                            colaI.Imprimir();
                        }  break;
                        case CONOCER_SI_ESTA_VACIA:{
                            if (colaI.estaVacia()) cout << "La cola est\240 vac\241a..." << endl;
                            else cout << "La cola no est\240 vac\241a..." << endl;
                        }  break;
                        case OBTENER_TAMANO:       {
                            cout << "El tama\244o es " << colaI.obtenerTam() << " elementos."
                                 << endl;

                        }  break;
                        case VACIAR_COLA:          {
                            colaI.vaciar();
                            cout << "La cola se ha vaciado correctamente." << endl;

                        }  break;
                        case OBTENER_PRIMER_VALOR: {
                            if (colaI.estaVacia()) cout << "La cola est\240  vac\241a..." << endl;
                            else {
                                cout << "Primero: \n" << colaI.obtenerPrimero() << endl;
                            }
                        }  break;
                        case OBTENER_ULTIMO_VALOR: {
                            if (colaI.estaVacia()) cout << "La cola est\240  vac\241a..." << endl;
                            else {
                                cout << "\351ltimo: \n" << colaI.obtenerUltimo() << endl;
                            }
                        }  break;
                    }
                    system("pause");
                }while(opcion_menu2 != 0);
            }break;
            case CHAR:   {
                ColaCircular<char> colaI;
                do {
                    opcion_menu2 = menu_2();
                    system("cls");
                    switch (opcion_menu2) {
                        case ENCOLAR:              {
                            char valor;

                            CapturaSegura(cantidad, "\250Cu\240ntos elementos desea encolar?: ");
                            for (int i = 0; i < cantidad; ++i) {
                                cout << "Ingrese el elemento #" << i + 1 << " : ";
                                cin >> valor;
                                colaI.encolar(valor);
                            }
                        }  break;
                        case DESENCOLAR:           {
                            if (colaI.estaVacia()) cout << "La cola est\240  vac\241a..." << endl;
                            else {
                                CapturaSegura(cantidad, "\250Cu\240ntos elementos desea desencolar?: ");
                                for (int i = 0; i < cantidad; ++i) colaI.desencolar();
                            }
                        }  break;
                        case IMPRIMIR:             {
                            colaI.Imprimir();
                        }  break;
                        case CONOCER_SI_ESTA_VACIA:{
                            if (colaI.estaVacia()) cout << "La cola est\240 vac\241a..." << endl;
                            else cout << "La cola no est\240 vac\241a..." << endl;
                        }  break;
                        case OBTENER_TAMANO:       {
                            cout << "El tama\244o es " << colaI.obtenerTam() << " elementos."
                                 << endl;

                        }  break;
                        case VACIAR_COLA:          {
                            colaI.vaciar();
                            cout << "La cola se ha vaciado correctamente." << endl;

                        }  break;
                        case OBTENER_PRIMER_VALOR: {
                            if (colaI.estaVacia()) cout << "La cola est\240  vac\241a..." << endl;
                            else {
                                cout << "Primero: \n" << colaI.obtenerPrimero() << endl;
                            }
                        }  break;
                        case OBTENER_ULTIMO_VALOR: {
                            if (colaI.estaVacia()) cout << "La cola est\240  vac\241a..." << endl;
                            else {
                                cout << "\351ltimo: \n" << colaI.obtenerUltimo() << endl;
                            }
                        }  break;
                    }
                    system("pause");
                }while(opcion_menu2 != 0);
            }break;
            }
        }while (opcion_menu1 != 0);
    }catch (out_of_range &exc){
        cerr << exc.what();
        system("pause");
    }catch (exception &exc){
        cerr << exc.what();
        system("pause");
    } catch (...) {
        cerr << "Ha ocurrido un error inesperado";
        system("pause");
    }
    return 0;
}
