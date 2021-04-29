/*
Nombre: Heap.tpp
Autor: Jesus Martin Garcia Encinas
Fecha: 27/04/2021
Descripción: Implementación de la clase Heap que permite crear y manejar arboles binarios semicompletos semiordenados en memoria dinámica..
*/

#include "Heap.h"

#define CAPINICIAL 31


template<typename T>
bool minimo(const T &a, const T &b) {
    return a <= b;
}

template<typename T>
bool maximo(const T &a, const T &b) {
    return a >= b;
}
//********************************************************
//ASEGURAR EL BUEN FUNCIONAMIENTO DE LA CLASE
//*CONSTRUCTOR POR DEFAULT
//*CONSTRUCTOR DE COPIAS
//*OPERADOR = SOBRECARGADO
//*DESTRUCTOR
//********************************************************

template<typename T, bool (*tipoH)(const T &a, const T &b)>
Heap<T, tipoH>::Heap(): ultimo(-1), capacidad(CAPINICIAL), arreglo(new T[CAPINICIAL]) {}

//**********************************************************************************************************************
template<typename T, bool (*tipoH)(const T &a, const T &b)>
Heap<T, tipoH>::Heap(const Heap<T, tipoH> &h): ultimo(-1), capacidad(CAPINICIAL), arreglo(new T[CAPINICIAL]) {
    *this = h;
}

//**********************************************************************************************************************
template<typename T, bool (*tipoH)(const T &a, const T &b)>
Heap<T, tipoH> &Heap<T, tipoH>::operator=(const Heap<T, tipoH> &h) {
    if (this == &h) return *this;
    delete[] arreglo;
    establecerDimension(h.dimension);
    arreglo = new T[arreglo];
    for (int i = 0; i < capacidad; ++i) arreglo[i] = h.arreglo[i];
    return *this;
}

//**********************************************************************************************************************
template<typename T, bool (*tipoH)(const T &a, const T &b)>
Heap<T, tipoH>::~Heap() {
    delete[] arreglo;
}

//********************************************************
//MÉTODOS PÚBLICOS
//*Agregar un nuevo elemento
//*Eliminar un elemento (El de la raíz)
//*Obtener el elemento al frente (El de la raíz)
//*Conocer si el montón está vacío
//*Vaciar el montón
//*Conocer el números de elementos
//*Conocer la capacidad del montón
//*Imprimir los elementos del montón
//********************************************************
template<typename T, bool (*tipoH)(const T &a, const T &b)>
void Heap<T, tipoH>::AgregarElemento(T val) {
    if (ultimo == capacidad - 1) Redimensionar();
    arreglo[++ultimo] = val;
    EmpujarArriba(ultimo);
}

//**********************************************************************************************************************
template<typename T, bool (*tipoH)(const T &a, const T &b)>
void Heap<T, tipoH>::EliminarRaiz() {
    if (EstaVacia()) throw HeapEmpty();
    arreglo[0] = arreglo[ultimo--];
    EmpujarAbajo(0);
}

//**********************************************************************************************************************
template<typename T, bool (*tipoH)(const T &a, const T &b)>
T Heap<T, tipoH>::ObtenerElementoRaiz() {
    if (EstaVacia()) throw HeapEmpty();
    return arreglo[0];
}
//**********************************************************************************************************************
template<typename T, bool (*tipoH)(const T &a, const T &b)>
bool Heap<T, tipoH>::EstaVacia() const {
    return ultimo == -1;
}

//**********************************************************************************************************************
template<typename T, bool (*tipoH)(const T &a, const T &b)>
void Heap<T, tipoH>::Vaciar() {
    ultimo = -1;
}

//**********************************************************************************************************************
template<typename T, bool (*tipoH)(const T &a, const T &b)>
unsigned Heap<T, tipoH>::ObtenerNumeroElementos() const {
    return ultimo + 1;
}

//******************************************************************************************************************
template<typename T, bool (*tipoH)(const T &a, const T &b)>
unsigned Heap<T, tipoH>::ObtenerCapacidad() const {
    return capacidad;
}

//******************************************************************************************************************
template<typename T, bool (*tipoH)(const T &a, const T &b)>
void Heap<T, tipoH>::Imprimir() const {
    if (EstaVacia()) std::cout << "El \240rbol esta vac\241o..." << std::endl;
    else {
        for (int i = 0; i <= ultimo; ++i) {
            std::cout << arreglo[i] << ", ";
        }
        std::cout << "\b\b \b";
    }
}
template<typename T, bool (*tipoH)(const T &a, const T &b)>
const char *Heap<T, tipoH>::HeapEmpty::what() const throw() {
    return "Error: \265rbol vac\241o";
}

//********************************************************
//MÉTODOS PÚBLICOS
//Redimensionar el arreglo que contiene los elementos del montón para un nivel más (cada nivel n puede contener 2n nodos)
//Empujar hacia arriba
//Empujar hacia abajo
//********************************************************

//**********************************************************************************************************************
template<typename T, bool (*tipoH)(const T &a, const T &b)>
void Heap<T, tipoH>::Redimensionar() {
    T *aux = arreglo;
    capacidad = capacidad * 2 + 1;
    arreglo = new T[capacidad];
    for (int i = 0; i <= ultimo; ++i) arreglo[i] = aux[i];
    delete[] aux;
}

//**********************************************************************************************************************
template<typename T, bool (*tipoH)(const T &a, const T &b)>
void Heap<T, tipoH>::EmpujarArriba(unsigned i) {
    unsigned padre = (i - 1) / 2;
    if (i != 0 && tipoH(arreglo[i], arreglo[padre])) {
        Intercambiar(padre, i);
        EmpujarArriba(padre);
    }
}

//**********************************************************************************************************************
template<typename T, bool (*tipoH)(const T &a, const T &b)>
void Heap<T, tipoH>::EmpujarAbajo(unsigned i) {
    unsigned hijoIzq = (2 * i + 1);
    unsigned hijoDer = (2 * i + 2);
    unsigned aux = i;
    if (hijoIzq < ultimo && tipoH(arreglo[hijoIzq], arreglo[i])) aux = hijoIzq;
    if (hijoDer < ultimo && tipoH(arreglo[hijoDer], arreglo[aux])) aux = hijoDer;
    if (aux != i) {
        Intercambiar(i, aux);
        EmpujarAbajo(aux);
    }
}

//**********************************************************************************************************************
template<typename T, bool (*tipoH)(const T &a, const T &b)>
void Heap<T, tipoH>::Intercambiar(unsigned iA, unsigned iB) {
    T aux = arreglo[iA];
    arreglo[iA] = arreglo[iB];
    arreglo[iB] = aux;
}