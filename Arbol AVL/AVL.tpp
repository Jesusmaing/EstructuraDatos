/*
Nombre: AVL.tpp
Autor: Jesus Martin Garcia Encinas
Fecha:  22/04/2021
Descripción: Implementación de Arbol semibalanceado
*/

#include "AVL.h"

template<typename T>
AVL<T>::AVL(): numNodos(0), raiz(NULL) {}

//**********************************************************************************************************************
template<typename T>
AVL<T>::AVL(const AVL<T> &a): numNodos(0), raiz(NULL) {
    *this = a;
}

//**********************************************************************************************************************
template<typename T>
AVL<T> &AVL<T>::operator=(const AVL<T> &a) {
    if (this == &a) return *this;
    Vaciar();
    copiarPreorden(a.raiz);
    return *this;
}

//**********************************************************************************************************************
template<typename T>
AVL<T>::~AVL() {
    Vaciar();
}

template<typename T>
bool AVL<T>::AgregarElemento(const T &val) {
    return Agregar(val, raiz);
}

//**********************************************************************************************************************
template<typename T>
bool AVL<T>::EliminarElemento(const T &val) {
    if(EstaVacia()) throw ArbolVacio();
    return Eliminar(val, raiz);
}

//**********************************************************************************************************************
template<typename T>
bool AVL<T>::BuscarElemento(const T &val) const {
    if (EstaVacia()) return false;
    return buscarNodo(raiz, val) != NULL;
}



//**********************************************************************************************************************
template<typename T>
void AVL<T>::Vaciar() {
    
    PodarNodo(raiz);
}

//**********************************************************************************************************************
template<typename T>
bool AVL<T>::EstaVacia() const {
    return numNodos == 0;
}

//**********************************************************************************************************************
template<typename T>
void AVL<T>::Imprimir(short orden) const {
    if (EstaVacia()) std::cout << "Arbol Vac\241o";
    else {
        switch (orden) {
            case 1: //ASCENDENTE
                ImprimirEnEntreOrden(raiz);
                break;
            case 2: //DESCENDENTE
                imprimirEntreOrdenInverso(raiz);
                break;
            case 3: //POR NIVELES
                imprimirPorNiveles();
                break;

        }
        std::cout << "\b\b \b";
    }
}

//**********************************************************************************************************************
template<typename T>
bool AVL<T>::Agregar(const T &valor, Nodo *&_raiz) {
    if (_raiz == NULL) {
        _raiz = new Nodo(valor);
        ++numNodos;
        return true;
    }

    if (valor == _raiz->valor) return false;

    if (valor < _raiz->valor) Agregar(valor, _raiz->hijoIzq);

    else Agregar(valor, _raiz->hijoDer);

    if (FactorBalance(_raiz) == -2) {
        if (FactorBalance(_raiz->hijoIzq) == 1) {
            RotacionDobleDer(_raiz);
        } else {
            RotacionSimpleDer(_raiz);
        }
    } else if (FactorBalance(_raiz) == 2) {
        if (FactorBalance(_raiz->hijoDer) == -1) {
            RotacionDobleIzq(_raiz);
        } else {
            RotacionSimpleIzq(_raiz);
        }
    }

    _raiz->altura = (ObtenerAltura(_raiz->hijoIzq) > ObtenerAltura(_raiz->hijoDer) ? ObtenerAltura(_raiz->hijoIzq)
                                                                                   : ObtenerAltura(_raiz->hijoDer)) + 1;

    return true;
}

//**********************************************************************************************************************
template<typename T>
bool AVL<T>::Eliminar(const T &valor, Nodo *&_raiz) {
    if (_raiz == NULL) {
        return false;
    } else {
        if (valor < _raiz->valor) {
            return Eliminar(valor, _raiz->hijoIzq);
        } else if (valor > _raiz->valor) {
            return Eliminar(valor, _raiz->hijoDer);
        } else {
            Nodo *raiz_anterior = _raiz;
            if (_raiz->hijoIzq == NULL) {
                _raiz = _raiz->hijoDer;
            } else if (_raiz->hijoDer == NULL) {
                _raiz = _raiz->hijoIzq;
            } else {
                IntercambiarPadre(raiz_anterior, raiz_anterior->hijoIzq);
            }
            delete raiz_anterior;
            if (FactorBalance(_raiz) == -2) {
                if (FactorBalance(_raiz->hijoIzq) == 1) {
                    RotacionDobleDer(_raiz);
                } else {
                    RotacionSimpleDer(_raiz);
                }
            } else if (FactorBalance(_raiz) == 2) {
                if (FactorBalance(_raiz->hijoDer) == -1) {
                    RotacionDobleIzq(_raiz);
                } else {
                    RotacionSimpleIzq(_raiz);
                }
            }

            _raiz->altura =
                    (ObtenerAltura(_raiz->hijoIzq) > ObtenerAltura(_raiz->hijoDer) ? ObtenerAltura(_raiz->hijoIzq)
                                                                                   : ObtenerAltura(_raiz->hijoDer)) + 1;

            return true;

        }
    }
}

//**********************************************************************************************************************
template<typename T>
typename AVL<T>::Nodo *AVL<T>::buscarNodo(Nodo *subRaiz, const T &val) const {
    if (subRaiz == NULL) return NULL;
    if (subRaiz->valor == val) return subRaiz;
    else if (val < subRaiz->valor) return buscarNodo(subRaiz->hijoIzq, val);
    else return buscarNodo(subRaiz->hijoDer, val);
}

//**********************************************************************************************************************
template<typename T>
void AVL<T>::PodarNodo(Nodo *&subraiz) {
    if(raiz == NULL) throw ArbolVacio();
    if (subraiz != NULL) {
        PodarNodo(subraiz->hijoIzq);
        PodarNodo(subraiz->hijoDer);
        delete subraiz;
        --numNodos;
        subraiz = NULL;
    }
}

//**********************************************************************************************************************
template<typename T>
typename AVL<T>::Nodo *&AVL<T>::buscarDirMayor(Nodo *&subRaiz) {
    if(raiz == NULL) throw ArbolVacio("El arbol est\240 vac\243o");
    if (subRaiz == NULL) return subRaiz;
    if (subRaiz->tieneHijoDer()) return buscarDirMayor(subRaiz->hijoDer);
    return subRaiz;
}

//**********************************************************************************************************************
template<typename T>
typename AVL<T>::Nodo *AVL<T>::buscarDirPadre(Nodo *&subRaiz, const Nodo *hijo) const {
    if(raiz == NULL) throw ArbolVacio("El arbol est\240 vac\243o");
    if (subRaiz == NULL || hijo == NULL) return NULL;
    if (subRaiz->hijoIzq == hijo || subRaiz->hijoDer == hijo) return subRaiz;
    else if (hijo->valor < subRaiz->valor) return buscarDirPadre(subRaiz->hijoIzq, hijo);
    else return buscarDirPadre(subRaiz->hijoDer, hijo);
}
//**********************************************************************************************************************

template<typename T>
void AVL<T>::ImprimirEnEntreOrden(Nodo *subRaiz) const {
    if(raiz == NULL) throw ArbolVacio();
    if (subRaiz != NULL) {
        ImprimirEnEntreOrden(subRaiz->hijoIzq);
        std::cout << subRaiz->valor << ", ";
        ImprimirEnEntreOrden(subRaiz->hijoDer);
    }
}

//**********************************************************************************************************************
template<typename T>
void AVL<T>::imprimirEntreOrdenInverso(Nodo *subRaiz) const {
    if(raiz == NULL) throw ArbolVacio();
    if (subRaiz != NULL) {
        imprimirEntreOrdenInverso(subRaiz->hijoDer);
        std::cout << subRaiz->valor << ", ";
        imprimirEntreOrdenInverso(subRaiz->hijoIzq);
    }
}

//**********************************************************************************************************************
template<typename T>
void AVL<T>::imprimirPorNiveles() const {
    if(raiz == NULL) throw ArbolVacio();
    Cola<Nodo *> cNodos;
    Nodo *aux;
    cNodos.Encolar(raiz);
    while (!cNodos.EstaVacia()) {
        aux = cNodos.ObtenerPrimero();
        cNodos.Desencolar();
        std::cout << aux->valor << ", ";
        if (aux->tieneHijoIzq()) cNodos.Encolar(aux->hijoIzq);
        if (aux->tieneHijoDer()) cNodos.Encolar(aux->hijoDer);
    }
}

//**********************************************************************************************************************
template<typename T>
void AVL<T>::copiarPreorden(Nodo *subRaiz) {
    if (subRaiz != NULL) {
        AgregarElemento(subRaiz);
        copiarPreorden(subRaiz->hijoIzq);
        copiarPreorden(subRaiz->hijoDer);
    }
}

template<typename T>
unsigned AVL<T>::NumVertices() const {
    return numNodos;
}





//**********************************************************************************************************************
template<typename T>
bool AVL<T>::Nodo::tieneHijoIzq() const {
    return hijoIzq != NULL;
}

//**********************************************************************************************************************
template<typename T>
bool AVL<T>::Nodo::tieneHijoDer() const {
    return hijoDer != NULL;
}

template<typename T>
AVL<T>::Nodo::Nodo(T _valor, AVL::Nodo *_hijoIzq, AVL::Nodo *_hijoDer, int _altura):  valor(_valor), hijoIzq(_hijoIzq),
                                                                                      hijoDer(_hijoDer),
                                                                                      altura(_altura) {}


//**********************************************************************************************************************
//**********************************************************************************************************************


template<typename T>
const char *AVL<T>::ArbolVacio::what() const throw() {
    return "Error: \240rbol vac\241o";
}

template<typename T>
void AVL<T>::RotacionSimpleDer(AVL::Nodo *&R) {
    Nodo *aux = R->hijoIzq;
    R->hijoIzq = aux->hijoDer;
    aux->hijoDer = R;
    R = aux;
    if (ObtenerAltura(R->hijoDer->hijoIzq) > ObtenerAltura(R->hijoDer->hijoDer)) {
        R->hijoDer->altura = ObtenerAltura(R->hijoDer->hijoIzq) + 1;
    } else {
        R->hijoDer->altura = ObtenerAltura(R->hijoDer->hijoDer) + 1;
    }
}

template<typename T>
void AVL<T>::RotacionSimpleIzq(AVL::Nodo *&R) {
    Nodo *aux = R->hijoDer;
    R->hijoDer = aux->hijoIzq;
    aux->hijoIzq = R;
    R = aux;
    if (ObtenerAltura(R->hijoIzq->hijoDer) > ObtenerAltura(R->hijoIzq->hijoIzq)) {
        R->hijoIzq->altura = ObtenerAltura(R->hijoIzq->hijoIzq) + 1;
    } else {
        R->hijoIzq->altura = ObtenerAltura(R->hijoIzq->hijoDer) + 1;
    }
}

template<typename T>
void AVL<T>::RotacionDobleDer(AVL::Nodo *&R) {
    RotacionSimpleIzq(R->hijoIzq);
    RotacionSimpleDer(R);
}

template<typename T>
void AVL<T>::RotacionDobleIzq(AVL::Nodo *&R) {
    RotacionSimpleDer(R->hijoDer);
    RotacionSimpleIzq(R);
}

template<typename T>
int AVL<T>::FactorBalance(AVL::Nodo *_raiz) {
    if (_raiz == NULL) return 0;
    return ObtenerAltura(_raiz->hijoDer) - ObtenerAltura(_raiz->hijoIzq);
}

template<typename T>
int AVL<T>::ObtenerAltura(AVL::Nodo *_raiz) {
    return _raiz == NULL ? 0 : _raiz->altura;

}

template<typename T>
void AVL<T>::IntercambiarPadre(AVL::Nodo *&raiz_antigua, AVL::Nodo *&_raiz) {
    if (_raiz->hijoDer != NULL) {
        IntercambiarPadre(raiz_antigua, _raiz->hijoDer);
    } else {
        raiz_antigua->valor = _raiz->valor;
        raiz_antigua = _raiz;
        _raiz = _raiz->hijoIzq;
    }
}
