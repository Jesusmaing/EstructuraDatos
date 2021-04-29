/*
Nombre: ListaEnlazadaSimple.h
Autor: Jesus Martin Garcia Encinas
Fecha: 08/03/2021
Descripción: Implementación de la clase plantilla ListaEnlazadaSimple
*/

#ifndef LISTAENLAZADA_SGRC_LISTA_H
#define LISTAENLAZADA_SGRC_LISTA_H



#include <iostream>
/** @class ListaEnlazadaSimple Clase que crea una estructura de lista y permite realizar todas sus modificaciones.
 *
 * @tparam T Tipo de los elementos a guardar en la lista.
 */
template <typename T>
class ListaEnlazadaSimple {
public:
    //******************************************************************************************************************
    /** @brief Constructor por default de la clase.
     */
    ListaEnlazadaSimple();
    //******************************************************************************************************************
    /** @brief Constructor de copias de la clase.
     *
     * @param l ListaEnlazadaSimple a copiar.
     */
    ListaEnlazadaSimple(const ListaEnlazadaSimple<T> &l);
    //******************************************************************************************************************
    /** @brief Sobrecarga del operador de asignaci&oacute;n "=".
     *
     * @param l ListaEnlazadaSimple que se asignar&aacute; a la otra listq.
     * @return ListaEnlazadaSimple a asignar.
     */
    ListaEnlazadaSimple<T> & operator=(const ListaEnlazadaSimple<T> &l);
    //******************************************************************************************************************
    /** @brief destructor de la clase.
    */
    ~ListaEnlazadaSimple();
    //******************************************************************************************************************
    /** @brief  M&eacute;todo que agrega un nuevo elemento al principio de la lista.
     *
     * @param val Valor del elemento a agregar.
     */
    void agregarAlPrincipio(const T &val);
    //******************************************************************************************************************
    /** @brief  M&eacute;todo que agrega un nuevo elemento al final de la lista.
     *
     * @param val Valor del elemento a agregar.
     */
    void agregarAlFinal(const T &val);
    //******************************************************************************************************************
    /** @brief  M&eacute;todo que agrega un nuevo elemento en una posici&oacute;n dada.
     *
     * @param pos Posici&oacute;n del elemento a agregar.
     * @param val Valor del elemento a agregar.
     */
    void agregarEnPosicion(int pos, const T &val);
    //******************************************************************************************************************
    /** @brief  M&eacute;todo que elimina al primer elemento de la lista.
     *
     * @throws Excepci&oacute;n "ListaVacia" si la lista no cuenta con elementos.
     */
    void eliminarDelPrincipio();
    //******************************************************************************************************************
    /** @brief  M&eacute;todo que elimina al &uacute;ltimo elemento de la lista.
    *
    * @throws Excepci&oacute;n "ListaVacia" si la lista no cuenta con elementos.
    */
    void eliminarDelFinal();
    //******************************************************************************************************************
    /** @brief  M&eacute;todo que elimina a un elemento en una posici&oacute;n dada.
    *
    * @param pos Posici&oacute;n del elemento a eliminar.
    * @throws Excepci&oacute;n "ListaVacia" si la lista no cuenta con elementos.
    */
    void eliminarDePosicion(int pos);
    //******************************************************************************************************************
    /** @brief  M&eacute;todo que verifica si se encuentra un elemento en la lista.
     *
     * @param val Valor del elemento a buscar.
     * @return True si el elemento est&aacute; en lista, False si no se encuentra.
     * @throws Excepci&oacute;n "ListaVacia" si la lista no cuenta con elementos.
     */
    bool buscar(const T &val) const;
    //******************************************************************************************************************
    /** @brief  M&eacute;todo que busca la posici&oacute;n de un elemento en la lista.
     *
     * @param val Valor del elemento a buscar.
     * @return &Iacute;ndice del elemento. (Retorna -1 si no se encontr&oacute;)
     * @throws Excepci&oacute;n "ListaVacia" si la lista no cuenta con elementos.
     */
    int buscarPosicion(const T &val) const;
    //******************************************************************************************************************
    /** @brief M&eacute;todo que verifica si la lista esta vacia o no.
     *
     * @return True si la lista est&aacute; vac&iacute;a, False si no lo esta.
     */
    bool estaVacia() const;
    //******************************************************************************************************************
    /** @brief M&eacute;todo para obtener el primer elemento de la lista.
     *
     * @return Primer elemento en la ListaEnlazadaSimple.
     * @throws Excepci&oacute;n "ListaVacia" si la lista no cuenta con elementos.
     */
    const T &obtenerPrimero() const;
    //******************************************************************************************************************
    /** @brief M&eacute;todo para obtener el &uacute;ltimo elemento de la lista.
     *
     * @return &Uacute;ltimo elemento en la ListaEnlazadaSimple.
     * @throws Excepci&oacute;n "ListaVacia" si la lista no cuenta con elementos.
     */
    const T &obtenerUltimo() const;
    //******************************************************************************************************************
    /** @brief M&eacute;todo para obtener un elemento en la posici&oacute;n dada.
     *
     * @param pos Posici&oacute;n del elemento a obtener.
     * @return Elemento en la posici&oacute;n de la ListaEnlazadaSimple.
     * @throws Excepci&oacute;n "ListaVacia" si la lista no cuenta con elementos.
     */
    const T &obtenerEnPosicion(int pos) const;
    //******************************************************************************************************************
    /** @brief M&eacute;todo para modificar un elemento en la posici&oacute;n dada.
     *
     * @param pos Posici&oacute;n del elemento a modificar.
     * @param val Nuevo valor del elemento.
     * @throws Excepci&oacute;n "ListaVacia" si la lista no cuenta con elementos.

     */
    void modificarEnPosicion(int pos, const T &val);
    //******************************************************************************************************************
     /** @brief Sobrecarga del operador "[]" para a un elemento de la lista. rvalue
     *
     * @param i &Iacute;ndice a acceder.
     * @return La componente que se desea acceder.
     * @throws Excepci&oacute;n "ListaVacia" si la lista no cuenta con elementos.
     */
    const T & operator[](int i) const;
    //******************************************************************************************************************
    /** @brief Sobrecarga del operador "[]" para a un elemento de la lista. lvalue
     *
     * @param i &Iacute;ndice a acceder.
     * @return La componente que se desea acceder.
     * @throws Excepci&oacute;n "ListaVacia" si la lista no cuenta con elementos.
     */
    T & operator[](int i);
    //******************************************************************************************************************
    /** @brief M&eacute;todo que obtiene el tamaño de la lista.
     *
     * @return Tamaño de la lista.
     */
    unsigned obtenerTam() const;
    //******************************************************************************************************************
    /** @brief M&eacute;todo que vac&iacute; a la lista.
     */
    void vaciar();
    //******************************************************************************************************************
    /** @brief M&eacute;todo que imprime a la lista.
     */
    void imprimir() const;
    //******************************************************************************************************************
    /** @class Clase utilizada para lanzar la excepci&oacute; ListaVacia en caso de que la lista
     *          no tenga elementos.
     */
    class ListaVacia : public std::exception {
    public:
        virtual const char * what() const throw();
    };
    //******************************************************************************************************************
private:
    unsigned tam;        /** Tamaño de la lista */
    struct Nodo{
        Nodo(T val, Nodo *sig = NULL);
        T valor;         /** Valor del elemento */
        Nodo *siguiente; /** Puntero al siguiente elemento */
    }*primero, *ultimo;  /** Punteros al primer y ultimo elemento de la lista (Valor y puntero del siguiente elemento */
};

#include "ListaEnlazadaSimple.tpp"

#endif //LISTAENLAZADA_SGRC_LISTA_H
