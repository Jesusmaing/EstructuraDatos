/*
Nombre: AVL.h
Autor: Jesus Martin Garcia Encinas
Fecha:  22/04/2021
Descripción: Archivo de cabecera de Arbol semibalanceado
*/
#ifndef ARBOLBINARIOBUSQUEDA_AVL_H
#define ARBOLBINARIOBUSQUEDA_AVL_H

#include <iostream>
#include "Cola.h"

template<typename T>
class AVL {
public:
    /** @brief Constructor por default de la clase.
*/
    AVL();

    /** @brief Constructor de copias de la clase.
     *
     * @param AB &Aacute;rbol a copiar.
     */
    AVL(const AVL<T> &AB);

    /** @brief destructor de la clase.
    */
    ~AVL();

    /** @brief Sobrecarga del operador de asignaci&oacute;n "=".
     *
     * @param AB &Aacute;rbol que se asignar&aacute; al otro &aacute;rbol.
     * @return &Aacute;rbol a asignar.
     */
    AVL<T> &operator=(const AVL<T> &AB);

    /** @brief  M&eacute;todo que agrega un nuevo nodo(v&eacute;rtice) el &aacute;rbol.
     *
     * @param _id id del nodo(v&eacute;rtice) a agregar.
     * @return Si el elemento se pudo agregar o no
     */
    bool AgregarElemento(const T &val);

    /** @brief  M&eacute;todo que elimina un nodo(v&eacute;rtice) el &aacute;rbol.
    *
    * @param _id id del nodo(v&eacute;rtice) a eliminar.
    * @return Si el elemento se pudo eliminar o no
    */
    bool EliminarElemento(const T &val);

    /** @brief  M&eacute;todo que verifica si se encuentra un nodo el &aacute;rbol.
    *
    * @param _id id de nodo a buscar
    * @return devuelve true si el elemento est&aacute; en &aacute;rbol, de lo contrario, delvolver&aacute; false.
    * @throws Excepci&oacute;n "GraficaVacia" si el &aacute;rbol no cuenta con elementos.
    */
    bool BuscarElemento(const T &val) const;

    /** @brief M&eacute;todo para obtener el n&uacute;mero de nodos(v&eacute;rtices) el &aacute;rbol.
    *
    * @return N&uacute;mero de nodos(v&eacute;rtices) del &aacute;rbol.
    * @throws Excepci&oacute;n "GraficaVacia" si el &aacute;rbol no cuenta con nodos.
    */
    unsigned NumVertices() const;

    /** @brief M&eacute;todo que vac&iacute; el &aacute;rbol.
   */
    void Vaciar();

    /** @brief M&eacute;todo que verifica si el &aacute;rbol. esta vacia o no.
    *
    * @return True si el &aacute;rbol est&aacute; vac&iacute;a, False si no lo esta.
    */
    bool EstaVacia() const;

    /** @brief M&eacute;todo que imprime  el &aacute;rbol.
     * @param orden 3 tipos de impresi&oacute;n... 1. ASCENDENTE, 2. DESCENDENTE, 3. POR NIVELES
    */
    void Imprimir(short orden) const;


    /** @class Clase utilizada para lanzar la excepci&oacute; &Aacute;rbolVacio en caso de que el &Aacute;rbol
     *          no tenga elementos.
     */
    class ArbolVacio : public std::exception {
    public:
        virtual const char *what() const throw();
    };


private:
    struct Nodo {
        Nodo(T _valor, Nodo *_hijoIzq = NULL, Nodo *_hijoDer = NULL, int _altura = 0);

        T valor;
        Nodo *hijoIzq, *hijoDer;
        int altura;

        bool tieneHijoIzq() const;

        bool tieneHijoDer() const;
    } *raiz;

    int numNodos;

    /**
     * @ M&eacute;todo auxiliar para eliminar todos los nodos a partir de una ra&iacute;z
     * @param _raiz un puntero a nodo que represente una ra&iacute;z local
     */
    void PodarNodo(Nodo *&subraiz);

    /**
     * @brief M&eacute;todo auxiliar privado para agregar un nodo a la ra&iacute;z
     * @param valor El valor que se va a agregar el &aacute;rbol
     * @param _raiz la ra&iacute;z local
     * @return un valor booleano para indicar si se pudo o no agregar un valor
     */
    bool Agregar(const T &valor, Nodo *&_raiz);

    /**
     * @brief M&eacute;todo auxiliar  para eliminar un nodo del &aacute;rbol
     * @param valor El valor que se va a eliminar
     * @param _raiz la ra&iacute;z local
     * @return un valor booleando indicando si se pudo eliminar el nodo
     */
    bool Eliminar(const T &valor, Nodo *&_raiz);

    /**
     * @brief M&eacute;todo auxiliar  para buscar un valor
     * @param subRaiz V&eacute;rtice subra&iacute;z
     * @param val Valor a buscar
     * @return V&eacute;rtice encontrado
     */
    Nodo *buscarNodo(Nodo *subRaiz, const T &val) const;

    /**
     * @brief M&eacute;todo auxiliar para buscar la direcci&oacute;n del mayor valor
     * @param subRaiz V&eacute;rtice subra&iacute;z
     * @return V&eacute;rtice mayor
     */
    Nodo *&buscarDirMayor(Nodo *&subRaiz);

    /**
     * @brief M&eacute;todo auxiliar para buscar la direcci&oacute;n del padre
     * @param subRaiz V&eacute;rtice subra&iacute;z
     * @param hijo V&eacute;rtce hijo
     * @return V&eacute;rtice padre
     */
    Nodo *buscarDirPadre(Nodo *&subRaiz, const Nodo *hijo) const;

    /**
     * @brief M&eacute;todo auxiliar  privado para imprimir un &aacute;rbol de forma descendiente
     * @param _raiz una ra&iacute;z local
     */
    void imprimirEntreOrdenInverso(Nodo *subRaiz) const;

    /**
     * @brief M&eacute;todo auxiliar  privado para imprimir un &aacute;rbol por niveles
     */
    void imprimirPorNiveles() const;

    /**
     * @brief M&eacute;todo auxiliar privado para copiar un &aacute;rbol en forma preorden
     * @param _raiz una ra&iacute;z local
     */
    void copiarPreorden(Nodo *subRaiz);

    /**
     * @brief M&eacute;todo auxiliar para imprimir el &aacute;rbol en Entre Orden
     * @param _raiz un puntero a nodo que representa a una ra&iacute;z local del &aacute;rbol
     */
    void ImprimirEnEntreOrden(Nodo *subRaiz) const;


    /**
     * @brief M&eacute;todo para aplicar una rotaci&oacute;n simple a la derecha.
     * @param R Una ra&iacute;z desde donde se va a rotar.
     */
    void RotacionSimpleDer(Nodo *&R);

    /**
     * @brief M&eacute;todo para aplicar una rotaci&oacute;n simple a la izquierda.
     * @param R Una ra&iacute;z desde donde se va a rotar.
     */
    void RotacionSimpleIzq(Nodo *&R);

    /**
     * @brief M&eacute;todo para aplicar una rotaci&oacute;n doble a la derecha.
     * @param R Una ra&iacute;z desde donde se va a rotar.
     */
    void RotacionDobleDer(Nodo *&R);

    /**
     * @brief M&eacute;todo para aplicar una rotaci&oacute;n doble a la izquierda.
     * @param R Una ra&iacute;z desde donde se va a rotar.
     */
    void RotacionDobleIzq(Nodo *&R);

    /**
     * @brief M&eacute;todo para obtener el factor de balance de las ra&iacute;ces.
     * @param _raiz Una ra&iacute;z.
     * @return Regresa un entero indicando el factor de balance.
     */
    int FactorBalance(Nodo *_raiz);


    /** @brief M&eacute;todo auxiliar para obtener el n&uacute;mero de aristas del &aacute;rbol.
    * @return Altura del &aacute;rbol
    */
    int ObtenerAltura(Nodo *_raiz);


    /**
     * @brief M&eacute;todo para intercambiar  la ra&iacute;z antigua por la nueva (usado en el m&eacute;todo de eliminar).
     * @param raiz_antigua La ra&iacute;z en la posici&oacute;n que se va eliminar.
     * @param _raiz La ra&iacute;z que va a tomar el lugar de la ra&iacute;z anterior.
     */
    void IntercambiarPadre(Nodo *&raiz_antigua, Nodo *&_raiz);

};


#include "AVL.tpp"

#endif //ARBOLBINARIOBUSQUEDA_AVL_H
