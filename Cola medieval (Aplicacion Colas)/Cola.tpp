//Nombre: cola.tpp
//Fecha: 18/03/2021
//Autor: Jesus Martin Garcia Encinas
//Descripción: Métodos de la clase plantilla cola


#include "Cola.h"

template<typename T>
Cola<T>::Cola():tam(0), primero(NULL), ultimo(NULL) {}

template<typename T>
Cola<T>::Cola(const Cola<T> &c): tam(0), primero(NULL), ultimo(NULL)
{
    *this = c;
}

template<typename T>
Cola<T> &Cola<T>::operator=(const Cola<T> &c)
{
    if(this == &c) return *this;
    vaciar();
    Nodo *aux= c.primero;
    while(aux != NULL){
        encolar(aux -> valor);
        aux = aux -> siguiente;
    }
    return *this;
}

template<typename T>
Cola<T>::~Cola()
{
    vaciar();
}

template<typename T>
void Cola<T>::encolar(const T &val)
{
    Nodo *nuevo = new Nodo(val);
    if(estaVacia()) primero = nuevo;
    else ultimo->siguiente=nuevo;
    ultimo = nuevo;
}

template<typename T>
void Cola<T>::desencolar() // pendiente
{
    if(estaVacia()) throw colaVacia();
    Nodo *auxSalir = primero;
    primero = primero -> siguiente;
    if (primero == NULL) ultimo = NULL;
    delete auxSalir;
    --tam;
}

template<typename T>
unsigned Cola<T>::obtenerTam() const
{
    return tam;
}

template<typename T>
bool Cola<T>::estaVacia() const
{
    return primero == NULL;
}

template<typename T>
const T &Cola<T>::obtenerPrimero() const
{
    if(estaVacia()) throw colaVacia();
    return primero -> valor;
}

template<typename T>
const T &Cola<T>::obtenerUltimo() const
{
    if(estaVacia()) throw colaVacia();
    return ultimo -> valor;
}



template<typename T>
void Cola<T>::vaciar()
{
    while(!estaVacia()) desencolar();
}

template<typename T>
void Cola<T>::Imprimir() const
{
    Nodo *aux = primero;
    if(estaVacia()) {
        std::cout << "Pila Vac\241a" << std::endl;
        return;
    }
    while(aux != NULL){

        std::cout << aux->valor << std::endl;
        aux = aux -> siguiente;
    }
    std::cout << "\b\b \b";
}



template<typename T>
Cola<T>::Nodo::Nodo(T val, Nodo *sig /* = NULL */):valor(val), siguiente(sig){};


template <typename T>
const char *Cola<T>::colaVacia::what() const throw() {
    return "Error: Cola vac\241a";
}    //******************************************************************************************