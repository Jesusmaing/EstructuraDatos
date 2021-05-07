/*
Nombre: ArbolB_SGRC.cpp
Autor: Sebastian Guadalupe Rivera de la Cruz
Fecha: 5/3/2021
Descripción:
*/

#include "ArbolB.h"
template<typename T, int Grado>
ArbolB<T, Grado>::ArbolB(): cantidadClaves(0), raiz(NULL)
{

}

template<typename T, int Grado>
ArbolB<T, Grado>::ArbolB(const ArbolB<T, Grado> &a): cantidadClaves(0), raiz(NULL)
{

}

template<typename T, int Grado>
ArbolB<T, Grado> &ArbolB<T, Grado>::operator=(const ArbolB<T, Grado> &a)
        {

}

template<typename T, int Grado>
ArbolB<T, Grado>::~ArbolB()
{

}

template<typename T, int Grado>
void ArbolB<T, Grado>::agregar(const T &val)
{
    if(estaVacio()){
        raiz->clave[0] = val;
        raiz->tamClaves++;
    }else{
        agregarVertice(raiz, NULL, val);
    }
}

template<typename T, int Grado>
void ArbolB<T, Grado>::eliminar(const T &val)
{
	if (buscar(raiz, val)) eliminar();
}

template<typename T, int Grado>
void ArbolB<T, Grado>::buscar(const T &val) const
{
	if (buscar(raiz, val)) std::cout << "El valor " << val << " se encuentra en el \24rbol.";
	else std::cout << "No existe el valor " << val << " dentro del \240rbol.";
}

template<typename T, int Grado>
bool ArbolB<T, Grado>::estaVacio() const
{
    return cantidadClaves == 0;
}

template<typename T, int Grado>
void ArbolB<T, Grado>::imprimir(short orden) const
{

}

template<typename T, int Grado>
void ArbolB<T, Grado>::agregarVertice(ArbolB::Vertice *&subRaiz, ArbolB::Vertice *&padre, const T &val)
{// subraiz = padre->hijo[i]
    //Si es hoja, se recorre ese arreglo hasta que encuentre su posicion.
    if(subRaiz->esHoja()){
        int i;
        // Recorremos las claves del padre tras agregar/subir una nueva.
        for(i = 0; i < subRaiz->tamClaves; ++i)
            if(subRaiz->clave[i] >= val) break;

        //Al encontrar su lugar, se inserta en su posición en el arreglo.
        for (int j = subRaiz->tamClaves; j > i; j--)
            subRaiz->clave[j] = subRaiz->clave[j - 1];
        subRaiz->clave[i] = val;
        subRaiz->tamClaves++;
    //Si no es hoja, se busca la posición del hijo (en orden).
    }else{
        int i;
        for(i = 0; i < subRaiz->tamClaves; ++i) {
            if(subRaiz->clave[i] >= val) {
                agregarVertice(subRaiz->hijo[i], subRaiz, val);
                break;
            }
        }
        if(i == subRaiz->tamClaves) agregarVertice(subRaiz->hijo[subRaiz->tamClaves], subRaiz, val);

    }

    if(subRaiz->tamClaves == Grado) {
        partir(subRaiz, padre); //Si se llega el tamaño max, se parte.
    }
}

template<typename T, int Grado>
void ArbolB<T, Grado>::partir(ArbolB::Vertice *subRaiz, ArbolB::Vertice *padre)
{
    unsigned indice = ((Grado-1)/2);

    Vertice *hDer = new Vertice();
    for(unsigned i = 0; i < (Grado - 1) - indice; ++i)
        hDer->clave[i] = subRaiz->clave[i+indice+1];
    subRaiz->tamClaves = indice;

    if(subRaiz == raiz){
        Vertice *nRaiz = new Vertice();
        nRaiz->clave[0] = subRaiz->clave[indice];
        raiz = nRaiz;

        raiz->hijo[0] = subRaiz;
        raiz->hijo[1] = hDer;
    }else{
        int i;
        // Recorremos las claves del padre para agregar/subir una nueva.
        for(i = 0; i < padre->tamClaves; ++i)
            if(padre->clave[i] >= subRaiz->clave[indice]) break;

        //Al encontrar su lugar, se inserta en su posición en el arreglo.
        for (int j = padre->tamClaves; j > i; j--)
            padre->clave[j] = padre->clave[j - 1];
        padre->clave[i] = subRaiz->clave[indice];
        padre->tamClaves++;

        padre->hijo[i + 1] = hDer;
    }

}

template<typename T, int Grado>
bool ArbolB<T, Grado>::Vertice::esHoja() const
{
    return hijo[0] == NULL;
}

template<typename T, int Grado>
ArbolB<T, Grado>::Vertice::Vertice(): tamClaves(0)
{
    for(int i = 0; i < Grado; ++i)
        hijo[i] = NULL;
}


template<typename T, int Grado>
void ArbolB<T, Grado>::mezclar(ArbolB::Vertice *verticeA, ArbolB::Vertice *verticeB) {

}

template<typename T, int Grado>
bool ArbolB<T, Grado>::buscar(const ArbolB::Vertice *verticeBusqueda, const T &val) const {
	if (verticeBusqueda->tamClaves != 0) {
		// Recorremos las claves del vértice.
		for (int i = 0; i < verticeBusqueda->clave[verticeBusqueda->tamClaves]; ++i) {
			if (verticeBusqueda->clave[i] == val) return true;
		}
		
		// Analizamos cada uno de sus hijos.
		for (int i = 0; verticeBusqueda->hijo[i] != NULL; ++i) {
			if (buscar(verticeBusqueda->hijo[i], val)) return true;
		}
		
	}
	
	return false;
}

template<typename T, int Grado>
bool ArbolB<T, Grado>::eliminar(const ArbolB::Vertice *verticeBusqueda, const T &val) {
	if (verticeBusqueda->tamClaves != 0) {
		// Recorremos las claves del vértice.
		for (int i = 0; i < verticeBusqueda->clave[verticeBusqueda->tamClaves]; ++i) {
			if (verticeBusqueda->clave[i] == val) {
				// Eliminamos el valor.
				verticeBusqueda->clave[i] = NULL;
				
				// Verificamos la cantidad de elementos restantes en el vértice.
				if (verticeBusqueda->tamClaves - 1 < ((Grado - 1) / 2)) {
					// todo Mezclar, pedir prestado, subir...
				} else {
					// Recorremos a la izquierda los valores restantes;
					for (int j = i; j < verticeBusqueda->tamClaves; ++j) {
						verticeBusqueda->clave[i] = verticeBusqueda->clave[i + 1];
					}
					
					verticeBusqueda->tamClaves--;
				}
				
				return true;
			}
		}
		
		// Recorremos cada uno de sus hijos.
		for (int i = 0; verticeBusqueda->hijo[i] != NULL; ++i) {
			if (buscar(verticeBusqueda->hijo[i], val)) return true;
		}
	}
	
	return false;
}
