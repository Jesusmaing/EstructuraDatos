//Nombre: ColaMedieval.cpp
//Fecha: 06/03/2021
//Autor: Jesus Martin Garcia Encinas
//Descripción: Métodos para implementar un correcto funcionamiento de un banco


#include "ColaMedieval.h"
//******************************************************************************************
ColaMedieval::ColaMedieval() : NombreAtendido(""), tiempototal(0), EstamentoAtendido(""),
                               TiempoCliente(0){}
//******************************************************************************************
void ColaMedieval::PasarCiudadano() {
    Ciudadano.SetCliente();
    if (Ciudadano.getEstamento() == "Noble")
    cola.encolar(Ciudadano.getPersona());
}




//******************************************************************************************
void ColaMedieval::DespacharCiudadano(){
    if (!cola.estaVacia()) {
        NombreAtendido = "";
        EstaOcupada = false;
    }
}
//******************************************************************************************
void ColaMedieval::LLEGOELREY() {

    int nuevoCliente;
    int TiempoDeEspera = 1 + rand() % 5;
    do {
        nuevoCliente = 1 + rand() % 100;
        //Probabilidad del 20% de que entre un Ciudadano al banco
        if(nuevoCliente >= 80) PasarCiudadano();
        if (TiempoDeEspera >= 0) {
            ImprimirConsola();
            TiempoDeEspera--;
            sleep(1);
            system("cls");
            tiempototal--;
            continue;
        }
        //Si la caja no está ocupada, se atiende al Ciudadano y se le genera un tiempo de atención al azar...
        if (!EstaOcupada) {
            AtenderCliente();
            TiempoCliente = 5 + rand() % 20;
        } else {
            TiempoCliente--;
        }

        if (TiempoCliente <= 0){
            DespacharCiudadano();
        }
        ImprimirConsola();
        sleep(1);
        system("cls");
        tiempototal--;
    }while(tiempototal != 0);
    if(EstaOcupada){
        DespacharCiudadano();
    }

        }
//******************************************************************************************
void ColaMedieval::AtenderCliente() {
    if(!EstaOcupada && !cola.estaVacia()) {
        NombreAtendido = cola.obtenerPrimero();
        NombreAtendido = "";
        cola.desencolar();
        EstaOcupada = true;
    }

}
//******************************************************************************************
void ColaMedieval::ImprimirConsola() {

    cout << "BIENVENIDOS A LOS TIEMPOS MEDIEVALES..." << endl;
    cout << "El banco se abrir\240 cuando se presione una tecla..." << endl << endl << endl;

    cout << "Tiempo Restante: " << tiempototal << endl << endl;

    if(!EstaOcupada) cout << "Caja abierta" << endl << endl;
    else cout << "Caja cerrada" << endl << endl;

    cout << "Persona actual: " << NombreAtendido << " estamento: " << EstamentoAtendido <<endl << endl;
    cout << "Tiempo atentido: " << TiempoCliente << endl << endl;;
    cout << endl << endl;
    cout << "Personas esperando..." << endl;
    if(!cola.estaVacia()) cola.Imprimir();
    else cout << "ESPERANDO CLIENTES..." << endl;
}
//******************************************************************************************
void ColaMedieval::CerrarBanco() {
    cout << "Personas que no pudieron ser atendidas..." << endl;
    cola.Imprimir();
}

void ColaMedieval::generar_horario(int _tiempototal) {
    tiempototal = _tiempototal;
}
//******************************************************************************************



