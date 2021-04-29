/*
Nombre: ListaEnlazadaSimple.tpp
Autor: Jesus Martin Garcia Encinas
Fecha: 08/03/2021
Descripción: Implementacion plantilla de la clase ListaEnlazadaSimple.
*/

#include "ListaEnlazadaSimple.h"
//**********************************************************************************************************************
template<typename T>
ListaEnlazadaSimple<T>::ListaEnlazadaSimple():tam(0), primero(NULL), ultimo(NULL) {}
//**********************************************************************************************************************
template<typename T>
ListaEnlazadaSimple<T>::ListaEnlazadaSimple(const ListaEnlazadaSimple<T> &l): tam(0), primero(NULL), ultimo(NULL)
{
    *this = l;
}
//**********************************************************************************************************************
template<typename T>
ListaEnlazadaSimple<T> &ListaEnlazadaSimple<T>::operator=(const ListaEnlazadaSimple<T> &l)
{
    if(this == &l) return *this;
    vaciar();
    Nodo *aux = l.primero;
    while(aux != NULL){
        agregarAlFinal(aux -> valor);
        aux = aux -> siguiente;
    }
    return *this;
}
//**********************************************************************************************************************
template<typename T>
ListaEnlazadaSimple<T>::~ListaEnlazadaSimple()
{
    vaciar();
}
//**********************************************************************************************************************
template<typename T>
void ListaEnlazadaSimple<T>::agregarAlPrincipio(const T &val)
{
    Nodo *auxEntrar = new Nodo(val, primero);
    if(estaVacia()) ultimo = auxEntrar;
    primero = auxEntrar;
    ++tam;
}
//**********************************************************************************************************************
template<typename T>
void ListaEnlazadaSimple<T>::agregarAlFinal(const T &val)
{
    Nodo *nuevo = new Nodo(val);
    if(estaVacia()) primero = nuevo;
    else ultimo->siguiente=nuevo;
    ultimo = nuevo;
    ++tam;
}
//**********************************************************************************************************************
template<typename T>
void ListaEnlazadaSimple<T>::agregarEnPosicion(int pos, const T &val)
{
    if(pos <= 0) agregarAlPrincipio(val);
    else if(pos >= tam) agregarAlFinal(val);
    else{
        Nodo *ant = primero;
        for (int i = 1; i < pos; ++i) ant = ant->siguiente;
        Nodo *nuevo = new Nodo(val, ant->siguiente);
        ant -> siguiente = nuevo;
        tam++;
    }
}
//**********************************************************************************************************************
template<typename T>
void ListaEnlazadaSimple<T>::eliminarDelPrincipio()
{
    if(estaVacia()) throw ListaVacia();
    Nodo *auxSalir = primero;
    primero = primero -> siguiente;
    if (primero == NULL) ultimo = NULL;
    delete auxSalir;
    --tam;
}
//**********************************************************************************************************************
template<typename T>
void ListaEnlazadaSimple<T>::eliminarDelFinal()
{
    if(estaVacia()) throw ListaVacia();
    Nodo *ant = primero;
    while (ant != ultimo && ant->siguiente != ultimo) ant = ant->siguiente;
    ant -> siguiente = NULL;
    delete ultimo;
    if(tam == 1) primero = ultimo = NULL;
    else ultimo = ant;
    --tam;
}
//**********************************************************************************************************************
template<typename T>
void ListaEnlazadaSimple<T>::eliminarDePosicion(int pos)
{
    if(estaVacia()) throw ListaVacia();
    if(pos <= 0) eliminarDelPrincipio();
    else if(pos >= tam-1) eliminarDelFinal();
    else{
        Nodo *ant = primero;
        for (int i = 1; i < pos; ++i) ant = ant ->siguiente;
        Nodo *porSalir = ant->siguiente;
        ant->siguiente = porSalir->siguiente;
        delete porSalir;
        --tam;
    }
}
//**********************************************************************************************************************
template<typename T>
bool ListaEnlazadaSimple<T>::buscar(const T &val) const
{
    if(estaVacia()) throw ListaVacia();
    Nodo *aux = primero;
    while (aux != NULL && aux->valor != val) aux = aux->siguiente;
    return aux != NULL;
}
//**********************************************************************************************************************
template<typename T>
int ListaEnlazadaSimple<T>::buscarPosicion(const T &val) const
{
    if(estaVacia()) throw ListaVacia();
    int indice = 0;
    Nodo *aux = primero;
    while(aux != NULL){
        if(aux -> valor == val) return indice;
        aux = aux -> siguiente;
        indice++;
    }
    return -1;
}
//**********************************************************************************************************************
template<typename T>
const T &ListaEnlazadaSimple<T>::obtenerPrimero() const
{
    if(estaVacia()) throw ListaVacia();
    return primero->valor;
}
//**********************************************************************************************************************
template<typename T>
const T &ListaEnlazadaSimple<T>::obtenerUltimo() const
{
    if(estaVacia()) throw ListaVacia();
    return ultimo->valor;
}
//**********************************************************************************************************************
template<typename T>
const T &ListaEnlazadaSimple<T>::obtenerEnPosicion(int pos) const
{
    if(estaVacia()) throw ListaVacia();
    if(pos <= 0) return obtenerPrimero();
    else if(pos >= tam-1) return obtenerUltimo();
    else{
        Nodo *aux = primero;
        for (int i = 0; i < pos; ++i) aux = aux -> siguiente;
        return aux->valor;
    }
}
//**********************************************************************************************************************
template<typename T>
void ListaEnlazadaSimple<T>::modificarEnPosicion(int pos, const T &val)
{
    if(estaVacia()) throw ListaVacia();
    if(pos < 0) pos = 0;
    else if(pos >= tam) pos = tam-1;
    Nodo *aux = primero;
    for (int i = 0; i < pos; ++i) aux = aux -> siguiente;
    aux->valor = val;
}
//**********************************************************************************************************************
template<typename T>
const T & ListaEnlazadaSimple<T>::operator[](int i) const
{
    if(estaVacia()) throw ListaVacia();
    if(i < 0) i = 0;
    else if(i >= tam) i = tam-1;
    Nodo *aux = primero;
    for (int j = 0; j < i; ++j) aux = aux->siguiente;
    return aux->valor;
}
//**********************************************************************************************************************
template<typename T>
T & ListaEnlazadaSimple<T>::operator[](int i)
{
    if(estaVacia()) throw ListaVacia();
    if(i < 0) i = 0;
    else if(i >= tam) i = tam-1;
    Nodo *aux = primero;
    for (int j = 0; j < i; ++j) aux = aux->siguiente;
    return aux->valor;
}
//**********************************************************************************************************************
template<typename T>
unsigned ListaEnlazadaSimple<T>::obtenerTam() const
{
    return tam;
}
//**********************************************************************************************************************
template<typename T>
void ListaEnlazadaSimple<T>::vaciar()
{
    while(!estaVacia()) eliminarDelPrincipio();
}
//**********************************************************************************************************************
template<typename T>
bool ListaEnlazadaSimple<T>::estaVacia() const
{
    return primero == NULL;
}
//**********************************************************************************************************************
template<typename T>
void ListaEnlazadaSimple<T>::imprimir() const
{
    if(estaVacia()) {
        std::cout << "Lista Vac\241a" << std::endl;
        return;
    }
    Nodo *aux = primero;
    while(aux != NULL){
        std::cout << aux -> valor << ", ";
        aux = aux -> siguiente;
    }
    std::cout << "\b\b \b";
}
//**********************************************************************************************************************
template <typename T>
const char *ListaEnlazadaSimple<T>::ListaVacia::what() const throw() {
    return "Error: Lista vac\241a";
}
//**********************************************************************************************************************
template<typename T>
ListaEnlazadaSimple<T>::Nodo::Nodo(T val, Nodo *sig /* = NULL */):valor(val), siguiente(sig){}
//**********************************************************************************************************************