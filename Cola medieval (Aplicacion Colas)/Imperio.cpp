//Nombre: Imperio.cpp
//Fecha: 18/03/2021
//Autor: Jesus Martin Garcia Encinas
//Descripción: Métodos para implementar un correcto funcionamiento de un Imperio


#include "Imperio.h"
//******************************************************************************************
Imperio::Imperio() : Horario(120), TiempoPersona(0), ReyArturoOcupado(false)  {

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


}
//******************************************************************************************
void Imperio::PasarPersona() {

        int GenerarNombre = rand() % maxNombres;
        int GenerarApellido = rand() % maxApellidos;
        string Estamento;
        if (rand() % 100 >= 60) Estamento = "Noble";
        else Estamento = "Plebeyo";
        clientes_espera.EncolarCiudadadano(Persona(nombres[GenerarNombre], apellidos[GenerarApellido], Estamento));

}
//******************************************************************************************
void Imperio::DespacharCliente(){
    if (!clientes_espera.estaVacia()) {
        PersonasAtentidas.encolar(PersonaActualAtendida);
        ReyArturoOcupado = false;
    }
}
//******************************************************************************************
void Imperio::AbrirImperio(unsigned horario) {
    Horario = horario;
    int NuevaPersona;
    int TiempoDeEspera = 1 + rand() % 5;
    do {

        NuevaPersona = 1 + rand() % 100;
        //Probabilidad del 20% de que entre un cliente al Imperio
        if(NuevaPersona >= 80) PasarPersona();
        if (TiempoDeEspera >= 0) {
            ImprimirConsola();
            TiempoDeEspera--;
            sleep(1);
            system("cls");
            Horario--;
            continue;
        }
        //Si la caja no está ocupada, se atiende al cliente y se le genera un tiempo de atención al azar...
        if (!ReyArturoOcupado && !clientes_espera.estaVacia()) {
            AtenderPersona();
            TiempoPersona = 5 + rand() % 20;
        } else {
            TiempoPersona--;
        }

        if (TiempoPersona <= 0){
            DespacharCliente();
        }
        ImprimirConsola();
        sleep(1);
        system("cls");
        Horario--;
    }while(Horario != 0);
    if(ReyArturoOcupado){
            DespacharCliente();
    }

        }
//******************************************************************************************
void Imperio::AtenderPersona() {
    if(!ReyArturoOcupado && !clientes_espera.estaVacia()){
        PersonaActualAtendida = clientes_espera.consultarPrimero();
        clientes_espera.desencolar();
        ReyArturoOcupado = true;
    }

}
//******************************************************************************************
void Imperio::ImprimirConsola() {

    cout << "Imperio ROMANO" << endl;
    cout << "El imperio se abrir\240 cuando se presione una tecla..." << endl << endl << endl;

    cout << "Tiempo Restante: " << Horario << endl << endl;

    if(!ReyArturoOcupado) cout << "Caja abierta" << endl << endl;
    else cout << "Caja cerrada" << endl << endl;

    cout << "Cliente Actual: " << PersonaActualAtendida.getPersona() << ": " << PersonaActualAtendida.getEstrato() << endl << endl;
    cout << "Tiempo atentido: " << TiempoPersona << endl << endl;
    cout << endl << endl;
    cout << "Personas esperando..." << endl;
    if(!clientes_espera.estaVacia()) clientes_espera.ImprimirCola();
    else cout << "ESPERANDO PERSONAS..." << endl;

}
//******************************************************************************************
void Imperio::CerrarImperio() {
    cout << "IMPERIO CERRADO" << endl << endl << endl << endl;
    cout << "PERSONAS ATENDIDAS:" << endl << endl << endl;
    PersonasAtentidas.Imprimir();
    cout << endl << endl << endl << endl;
    cout << "Personas que no pudieron ser atendidas..." << endl << endl;

    clientes_espera.ImprimirCola();
}


//******************************************************************************************



