/*
Nombre: Grafica.tpp
Autor: Jesus Martin Garcia Encinas
Fecha: 09/04/2021
Descripción: Implementación de la plantilla clase Grafica que permite la manipulación de una Gráfica con sus métodos indispensables
*/

#include "Grafica.h"

template<typename T>
Grafica<T>::Grafica() : numNodos(0), numAristas(0), primero(NULL), ultimo(NULL) {

}

template<typename T>
Grafica<T>::~Grafica() {
    vaciar();
}


template<typename T>
Grafica<T> &Grafica<T>::operator=(const Grafica<T> &g) {
    if (this == &g) return *this;
    vaciar();
    Nodo *auxNodo = g.primero;
    while (auxNodo != NULL) {
        Agregar(auxNodo->id);
        auxNodo = auxNodo->siguiente;
    }
    auxNodo = g.primero;
    while (auxNodo != NULL) {
        typename Nodo::Arista *auxArista = auxNodo->primero;
        while (auxArista != NULL) {
            if (!Buscar(auxNodo->id, auxArista->adyacente->id))
                Agregar(auxNodo->id, auxArista->adyacente->id);
            auxArista = auxArista->siguiente;
        }
        auxNodo = auxNodo->siguiente;
    }

    return *this;

}

template<typename T>
void Grafica<T>::Agregar(const T &_id) {
    if (Buscar(_id)) return ;
    Nodo *nuevo = new Nodo (_id);
    if (numNodos == 0) primero = nuevo;

    else ultimo -> siguiente = nuevo;
    ultimo = nuevo;
    ++numNodos;
}

template<typename T>
void Grafica<T>::Agregar(const T &inicio, const T &fin) {
    Nodo *dirNodoInicio = DireccionVertice(inicio);
    if(dirNodoInicio == NULL) return ;
    Nodo *dirNodoFin = DireccionVertice(fin);
    if(dirNodoFin == NULL) return ;

    dirNodoInicio -> Agregar(dirNodoFin);
    dirNodoFin -> Agregar(dirNodoInicio);
    ++numAristas;



}


template<typename T>
Grafica<T>::Grafica(const Grafica<T> &g) : numNodos(0), numAristas(0) {
    *this = g;
}




template<typename T>
void Grafica<T>::Nodo::Agregar(Grafica::Nodo *_adyacente) {
    Arista *nuevo = new Arista(_adyacente);
    if (grado == 0) primera = nuevo;
    else ultima -> siguiente = nuevo;
    ultima = nuevo;
    grado++;

}

template<typename T>
void Grafica<T>::Nodo::Eliminar(Grafica::Nodo *_adyacente) {
    Arista *ant, *aux = DireccionArista(_adyacente, &ant);
    if(aux == NULL) return;
    if(ant == NULL) primera = primera->siguiente;
    else ant->siguiente = aux->siguiente;
    if(primera == NULL) ultima = NULL;
    delete aux;
    --grado;
}

template<typename T>
typename Grafica<T>::Nodo::Arista *Grafica<T>::Nodo::DireccionArista(Grafica::Nodo *_adyacente, Grafica::Nodo::Arista **pAnt) const {
    typename  Grafica<T>::Nodo::Arista *aux = primera;
    if(pAnt != NULL) *pAnt = NULL;
    while(aux != NULL && aux -> adyacente != _adyacente){
        if(pAnt != NULL) *pAnt = aux;
        aux= aux->siguiente;
    }
    return aux;
}

template<typename T>
bool Grafica<T>::Nodo::Buscar(Grafica::Nodo *_adyacente) const {
    Arista *aux = primera;
    while(aux != NULL && aux -> adyacente != _adyacente) aux = aux -> siguiente;
    return aux != NULL;
}





template<typename T>
unsigned Grafica<T>::ObtenerNumAristas() const {
    return numAristas;
}

template<typename T>
unsigned Grafica<T>::ObtenerNumNodos() const {
    return numNodos;
}

template<typename T>
bool Grafica<T>::EstaVacia() {
    return numNodos == 0;
}

template<typename T>
bool Grafica<T>::Buscar(const T &inicio, const T &fin) {
    Nodo *dirNodoInicio = DireccionVertice(inicio);
    if(dirNodoInicio == NULL) return false;
    Nodo *dirNodoFin = DireccionVertice(fin);
    if(dirNodoFin == NULL) return false;
    return dirNodoInicio -> Buscar(dirNodoFin);
}

template<typename T>
void Grafica<T>::Eliminar(const T &inicio, const T &fin) {
    Nodo *dirNodoInicio = DireccionVertice(inicio);
    if(dirNodoInicio == NULL) return;
    Nodo *dirNodoFin = DireccionVertice(fin);
    if(dirNodoFin == NULL) return ;

    dirNodoInicio -> Eliminar(dirNodoFin);
    dirNodoFin -> Eliminar(dirNodoInicio);
    --numAristas;
}

template<typename T>
void Grafica<T>::Eliminar(const T &_id) {
    //IF ESTA VACIA BLABABLABa
    typename Grafica<T>::Nodo *ant,*dirVertice = DireccionVertice(_id, &ant);
    if(dirVertice == NULL) return;
    vaciar(_id);
    if(ant == NULL ) primero = primero -> siguiente;
    else ant -> siguiente = dirVertice->siguiente;
    if(primero == NULL) ultimo = NULL;
    delete dirVertice;
    --numNodos;
}






template<typename T>
typename Grafica<T>::Nodo *Grafica<T>::DireccionVertice(const T &_id, Nodo **pAnt) const {
    Nodo *aux = primero;
    if(pAnt != NULL) *pAnt = NULL;
    while(aux != NULL && aux -> id != _id){
        if (pAnt != NULL) *pAnt = aux;
        aux = aux -> siguiente;
    }
    return aux;
}


template<typename T>
bool Grafica<T>::Buscar(const T &_id) const {
    typename  Grafica<T>::Nodo *aux = primero;
    while(aux != NULL){
        if(aux->id == _id) return true;
        aux = aux -> siguiente;
    }
    return false;
}

template<typename T>
unsigned Grafica<T>::ObtenerGrado(const T &_id) const{
    Nodo *aux = DireccionVertice(_id);
    if(aux != NULL) return aux -> grado;
    else return -1;
}

template<typename T>
void Grafica<T>::vaciar() {
    while(!EstaVacia()) Eliminar(primero->id);
}

template<typename T>
void Grafica<T>::Imprimir() const {
    if(numNodos == 0){
        cout << "Gr\240fica vac\241a" << endl;
    }
    typename  Grafica<T>::Nodo *aux = primero;
    while(aux != NULL){
        if(aux-> grado > 0) Imprimir(aux -> id);
        else cout << aux -> id;
        aux = aux -> siguiente;
        cout << endl;
    }
    std::cout << "\b\b \b";
}

template<typename T>
void Grafica<T>::vaciar(const T &id) {

}

template<typename T>
void Grafica<T>::Imprimir(const T &_id) const {
    Nodo *dirVertice = DireccionVertice(_id);
    if (dirVertice == NULL) return;

    typename Grafica<T>::Nodo::Arista *aux = dirVertice->primera;
    std::cout << _id << " -> " ;
    if (dirVertice -> grado != 0){
        while(aux != NULL){
            std::cout << aux -> adyacente -> id << ", ";
            aux = aux -> siguiente;
        }
        std::cout << "\b\b \b";
    }
}


template<typename T>
Grafica<T>::Nodo::Nodo(T _id, Grafica::Nodo *sig, Grafica::Nodo *ant): siguiente(sig), id(_id), grado(0) {}

template<typename T>
Grafica<T>::Nodo::Arista::Arista(Grafica::Nodo *_adyacente, Grafica::Nodo::Arista *_sig, Grafica::Nodo::Arista *_ant): adyacente(_adyacente), siguiente(_sig) {}
