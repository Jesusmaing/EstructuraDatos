/*
Nombre: Heap.h
Autor: Jesus Martin Garcia Encinas
Fecha: 27/04/2021
Descripción: Clase Heap que permite crear y manejar arboles binarios semicompletos semiordenados en memoria dinámica..
*/

#ifndef HEAP_H
#define HEAP_H

//**********************************************************************************************************************
/** @brief M&eacute;todo que funciona como plantilla de orden m&iacute;nimo para el heap.
 *
 * @tparam T Tipo de los elementos a guardar en el &aacute;rbol heap.
 * @param a Elemento A a comparar.
 * @param b Elemento B a comparar.
 * @return True si A <= B, false si no.
 */
template<typename T>
bool minimo(const T &a, const T &b);
//**********************************************************************************************************************
/** @brief M&eacute;todo que funciona como plantilla de orden m&aacute;nimo para el heap.
 *
 * @tparam T Tipo de los elementos a guardar en el &aacute;rbol heap.
 * @param a Elemento A a comparar.
 * @param b Elemento B a comparar.
 * @return True si A >= B, false si no.
 */
template<typename T>
bool maximo(const T &a, const T &b);
//**********************************************************************************************************************
/** @class Clase plantilla que crea un &aacute;rbol binario heap m&iacute;nimo o m&aacute;nimo, mediante el uso de un arreglo
 *          en memoria din&aacute;mica.
 *
 * @tparam T Tipo de los elementos a guardar en el &aacute;rbol heap.
 * @tparam tipoH Tipo de heap (M&iacute;nimo o M&aacute;nimo)
 */
template<typename T, bool(*tipoH)(const T &a, const T &b) = &minimo>
class Heap {
public:
    //******************************************************************************************************************
    /** @brief Constructor por default de la clase.
     */
    Heap();
    //******************************************************************************************************************
    /** @brief Constructor de copias de la clase.
     *
     * @param h &Aacute;rbol a copiar.
     */
    Heap(const Heap<T, tipoH> &h); //*this = g
    //******************************************************************************************************************
    /** @brief Sobrecarga del operador de asignaci&oacute;n "=".
     *
     * @param h &Aacute;rbol que se asignar&aacute; al otro &aacute;rbol.
     * @return &Aacute;rbol a asignar.
     */
    Heap<T, tipoH> &operator=(const Heap<T, tipoH> &h);
    //******************************************************************************************************************
    /** @brief destructor de la clase.
     */
    ~Heap();
    //******************************************************************************************************************
    /** @brief M&eacute;todo que agrega un nuevo elemento al &aacute;rbol.
     *
     * @param val Valor del elemento a agregar
     */
    void AgregarElemento(T val);
    //******************************************************************************************************************
    /** @brief M&eacute;todo que elimina a la ra&iacute;z del &aacute;rbol.
     *
     * @throws Excepci&oacute;n "Heap<T>::HeapEmpty" si el &aacute;rbol no cuenta con elementos.
     */
    void EliminarRaiz();
    //******************************************************************************************************************
    /** @brief M&eacute;todo que retorna la ra&iacute;z del &aacute;rbol.
     *
     * @return La ra&iacute;z del &aacute;rbol.
     */
    T ObtenerElementoRaiz();
    //******************************************************************************************************************
    /** @brief M&eacute;todo que verifica si el &aacute;rbol esta vaciacute;o o no.
     *
     * @return True si el &aacute;rbol est&aacute; vac&iacute;a, False si no lo esta.
     */
    bool EstaVacia() const;
    //******************************************************************************************************************
    /** @brief M&eacute;todo que vacia al &aacute;rbol.
     */
    void Vaciar();
    //******************************************************************************************************************
    /** @brief M&eacute;todo para obtener el n&uacute;mero de elmentos en el &aacute;rbol.
     *
     * @return N&uacute;mero de elmentos.
     */
    unsigned ObtenerNumeroElementos() const;
    //******************************************************************************************************************
    /** @brief M&eacute;todo para obtener la capacidad actual del &aacute;rbol.
     *
     * @return Capacidad actual del.
     */
    unsigned ObtenerCapacidad() const;
    //******************************************************************************************************************
    /** @brief M&eacute;todo para Imprimir el &aacute;rbol.
     */
    void Imprimir() const;
    //******************************************************************************************************************
    /** @class Clase utilizada para lanzar la excepci&oacute; HeapEmpty en caso de que el &aacute;rbol
     *          no tenga elementos.
     */
    class HeapEmpty : public std::exception {
    public:
        virtual const char *what() const throw();
    };
    //******************************************************************************************************************
private:
    unsigned capacidad;     /** Capacidad actual del arreglo / &aacute;rbol. */
    unsigned ultimo;        /** &Iacute;ndice del ultimo valor en el &aacute;rbol. */
    T *arreglo;             /** Arreglo din&aacute;mico que guarada los elementos del &aacute;rbol. */

    //******************************************************************************************************************
    /** @brief M&eacute;todo auxiliar para Redimensionar el arreglo en caso de que este se llene.
     */
    void Redimensionar();
    //******************************************************************************************************************
    /** @brief M&eacute;todo auxiliar recursivo para empujar un elemento hacia arriba del heap.
     *
     * @param i Elemento a empujar
     */
    void EmpujarArriba(unsigned i);
    //******************************************************************************************************************
    /** @brief M&eacute;todo auxiliar recursivo para empujar un elemento hacia abajo del heap.
     *
     * @param i Elemento a empujar
     */
    void EmpujarAbajo(unsigned i);
    //******************************************************************************************************************
    /** @brief M&eacute;todo auxiliar para Intercambiar dos valores del arreglo a partir de sus indices.
     *
     * @param iA &Iacute;ndice "A" a Intercambiar.
     * @param iB &Iacute;ndice "B" a Intercambiar.
     */
    void Intercambiar(unsigned iA, unsigned iB);
    //******************************************************************************************************************
};

#include "Heap.tpp"

#endif
