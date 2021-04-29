/*
Nombre: Lista.tpp
Autor: Jesus Martin Garcia Encinas
Fecha: 26/03/2021
Descripción: Implementacion plantilla de la clase Lista.
*/

#include "Lista.h"
//*************************************************************************
template<typename T>
Lista<T>::Lista():tam(0), cabeza(NULL){}
//*************************************************************************
template<typename T>
Lista<T>::Lista(const Lista<T> &l):tam(0), cabeza(NULL)
{
    *this = l;
}
//*************************************************************************
template<typename T>
Lista<T> &Lista<T>::operator=(const Lista<T> &l)
{
    if(this == &l) return *this;
    vaciar();
    Nodo *aux = l.cabeza;
    for(int i = 0; i < l.tam; i++){
        agregar(aux -> valor);
        aux = aux -> anterior;
    }
    return *this;
}
//*************************************************************************
template<typename T>
Lista<T>::~Lista()
{
    vaciar();
}
//*************************************************************************
template<typename T>
void Lista<T>::agregar(const T &val)
{
    if(estaVacia()){
        Nodo *nuevo = new Nodo(val);
        cabeza->anterior = nuevo;
        cabeza->siguiente = cabeza;
    }else{
        Nodo *nuevo = new Nodo(val, cabeza->siguiente, cabeza);

        cabeza->siguiente = nuevo;
        cabeza->siguiente->anterior = nuevo;
    }

    ++tam;
}
//*************************************************************************
template<typename T>
T Lista<T>::eliminar()
{
    if(estaVacia()) throw ListaVacia();
    Nodo *porSalir = cabeza->siguiente;
    if(tam != 1){
        cabeza->siguiente = porSalir->siguiente;
        porSalir->siguiente->anterior = cabeza;
    }else{
        cabeza = NULL;
    }
    T auxPorSalir = porSalir->valor;
    delete porSalir;
    --tam;
    return auxPorSalir;
}
//*************************************************************************
template<typename T>
void Lista<T>::eliminarPrimeraOcurrencia(const T &val)
{
    if (estaVacia()) throw ListaVacia();
    Nodo *auxCabeza = cabeza;
    if (cabeza->valor == val) {
        retroceder();
        eliminar();
        avanzar();
        return;
    }
    avanzar();
    for (unsigned  i = 1; i < tam; i++) {
        if (cabeza->valor == val) {
            retroceder();
            eliminar();
            break;
        }
        avanzar();
    }
    cabeza = auxCabeza;
}
//*************************************************************************
template<typename T>
void Lista<T>::eliminarTodaOcurrencia(const T &val)
{
    if(estaVacia()) throw ListaVacia();
    while(buscar(val))
        eliminarPrimeraOcurrencia(val);
}
//*************************************************************************
template<typename T>
bool Lista<T>::buscar(const T &val)
{
    for(unsigned i = 0; i < tam; i++) {
        if(cabeza->valor != val) avanzar();
        else return true;
    }
    return false;
}
//*************************************************************************
template<typename T>
void Lista<T>::vaciar()
{
    if(!estaVacia()) while(!estaVacia()) eliminar();
}
//*************************************************************************
template<typename T>
void Lista<T>::avanzar()
{
    if(!estaVacia())cabeza = cabeza->siguiente;
}
//*************************************************************************
template<typename T>
void Lista<T>::retroceder()
{
    if(!estaVacia())cabeza = cabeza->anterior;
}
//*************************************************************************
template<typename T>
const T &Lista<T>::obtenerValor()
{
    if(estaVacia()) throw ListaVacia();
    return cabeza->valor;
}
//*************************************************************************
template<typename T>
void Lista<T>::modificar(const T &val)
{
    if(estaVacia()) throw ListaVacia();
    cabeza->valor = val;
}
//*************************************************************************
template<typename T>
unsigned Lista<T>::obtenerTam() const
{
    return tam;
}
//*************************************************************************

template<typename T>
bool Lista<T>::estaVacia() const
{
    return tam == 0;
}
//*************************************************************************
template<typename T>
void Lista<T>::imprimir() const
{
    if(estaVacia()) {
        std::cout << "Lista Vac\241a" << std::endl;
        return;
    }
    Nodo *aux = cabeza;
    std::cout << "Cabeza -> ";
    for(unsigned i = 0; i < tam; i++){
        std::cout << aux -> valor << ", ";
        aux = aux->siguiente;
    }
    std::cout << "\b\b \b";
}
//*************************************************************************
template <typename T>
const char *Lista<T>::ListaVacia::what() const throw() {
    return "Error: Lista vac\241a";
}
//*************************************************************************
template<typename T>
Lista<T>::Nodo::Nodo(T val, Lista::Nodo *sig, Lista::Nodo *ant):valor(val), siguiente(sig), anterior(ant) {}
//*************************************************************************
