/*
Nombre: ColaCircular.tpp
Autor: JESUS MARTIN GARCIA ENCINAS
Fecha: 2/3/2021
*/


#include "ColaCircular.h"

template<typename T>
ColaCircular<T>::ColaCircular():tam(0), ultimo(NULL) {}
//******************************************************************************************
template<typename T>
ColaCircular<T>::ColaCircular(const ColaCircular<T> &c): tam(0), ultimo(NULL)
{
    *this = c;
}
//******************************************************************************************


template<typename T>
ColaCircular<T> &ColaCircular<T>::operator=(const ColaCircular<T> &c)
{
    if(this == &c) return *this;
    vaciar();
    if (!c.estaVacia()) {
    Nodo *aux= (c.ultimo) -> siguiente;
        do {
            encolar(aux->valor);
            aux = aux->siguiente;
        } while (aux != (c.ultimo)->siguiente);
    }
    return *this;
}
//******************************************************************************************
template<typename T>
ColaCircular<T>::~ColaCircular()
{
    vaciar();
}

/*********************** TAREAAAAAA ***************/
template<typename T>
void ColaCircular<T>::encolar(const T &val)
{
    Nodo *nuevo = new Nodo(val);
    if(estaVacia()){
        ultimo = nuevo;
        ultimo -> siguiente = nuevo;
    }
    else {
       nuevo -> siguiente = ultimo -> siguiente;
       ultimo -> siguiente = nuevo;
       ultimo = nuevo;
    }
    tam++;
}
//******************************************************************************************
/*********************** TAREAAAAAA ***************/
template<typename T>
void ColaCircular<T>::desencolar() // pendiente
{
    if(estaVacia()) throw ColaVacia();
    Nodo *auxSalir = ultimo -> siguiente;
    ultimo -> siguiente = (ultimo -> siguiente -> siguiente);
    if(ultimo -> siguiente == NULL) ultimo = NULL;
    delete auxSalir;
    --tam;
}
//******************************************************************************************
template<typename T>
unsigned ColaCircular<T>::obtenerTam() const
{
    return tam;
}
//******************************************************************************************
template<typename T>
bool ColaCircular<T>::estaVacia() const
{
    return (tam == 0);
}
//******************************************************************************************
template<typename T>
const T &ColaCircular<T>::obtenerPrimero() const
{
    if(estaVacia()) throw ColaVacia();
    return  ultimo->siguiente -> valor;
}
template<typename T>
//******************************************************************************************
const T &ColaCircular<T>::obtenerUltimo() const
{
    if(estaVacia()) throw ColaVacia();
    return  ultimo-> valor;
}
//******************************************************************************************
template<typename T>
void ColaCircular<T>::vaciar()
{
    while(!estaVacia()) desencolar();
}
//******************************************************************************************
template<typename T>
void ColaCircular<T>::Imprimir() const
{

    Nodo *aux = ultimo -> siguiente;
    if(estaVacia()) {
        std::cout << "Cola Vac\241a" << std::endl;
        return;
    }
    do {
        std::cout << aux -> valor << ", ";
        aux = aux -> siguiente;
    } while (aux != ultimo -> siguiente);
    std::cout << "\b\b \b" <<std::endl;
    }
//******************************************************************************************
template<typename T>
ColaCircular<T>::Nodo::Nodo(T val, Nodo *sig /* = NULL */):valor(val), siguiente(sig){}
//******************************************************************************************
template <typename T>
const char *ColaCircular<T>::ColaVacia::what() const throw() {
    return "Error: Cola vac\241a";
}    //******************************************************************************************