//Nombre: Persona.cpp
//Fecha: 06/03/2021
//Autor: Jesus Martin Garcia Encinas
//Descripción: Métodos de la clase Persona

#include <fstream>
#include "Persona.h"

Persona::Persona()
{
    std::ifstream nombre("../nombres.txt");
    std::string linea;
    if (nombre.is_open()) {
        (getline(nombre, linea));
        int valorN = atoi(linea.c_str());
        maxNombres = valorN;
        string *NOMBRES= new string[valorN];
        nombres = NOMBRES;
        for (int i = 0; i <valorN; ++i) {
            nombre >> NOMBRES[i];
            //std::cout << *(nombres+i)<< "    " << std::endl;
        }
        nombre.close();
    }

    std::ifstream apellido("../apellidos.txt");
    std::string ln;

    if (apellido.is_open()) {
        (getline(apellido, ln));
        int valorA = atoi(ln.c_str());
        maxApellidos = valorA;
        string *APELLIDOS= new string[valorA];
        apellidos = APELLIDOS;
        for (int i = 0; i < valorA; ++i) {
            apellido >> APELLIDOS[i];
            //std::cout << *(puntero+i)<< "    " << std::endl;
        }apellido.close();
    }

    //std::cout << endl <<*(nombres+9)<< " " << endl;
}



void Persona::SetCliente() {

    int i,j,k;
    i  = 1 + rand()%maxNombres-1;
    j  = 1 + rand()%maxApellidos-1;
    //cout << n << endl;
    _Persona = *(nombres+i) + " " + *(apellidos+j);

    k = rand()%1;
    switch (k) {
        case 0: _Estamento = "Noble";   break;
        case 1: _Estamento = "Plebeyo"; break;
    }
}

string Persona::getPersona() {
    return _Persona;
}

string Persona::getEstamento(){
    return _Estamento;
}


Persona::~Persona() {
    delete[] nombres;
    delete[] apellidos;
}

