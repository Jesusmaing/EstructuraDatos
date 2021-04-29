/*
Nombre: Lista.h
Autor: Jesus Martin Garcia Encinas
Fecha: 26/02/2021
Descripción: Clase que permite crear listas circulares doblemente enlazadas.
*/

#ifndef LISTACIRCULAR_SGRC_LISTA_H
#define LISTACIRCULAR_SGRC_LISTA_H

#include <iostream>

template <typename T>
class Lista{
public:

//ASEGURAR UN BUEN FUNCIONAMIENTO DE LA CLASE
//******************************************//
//       * CONSTRUCTOR DE LA CLASE          //
//       * CONSTRUCTOR DE COPIAS            //
//       * DESTRUCTOR                       //
//       * SOOBRECARGA DEL OPERADOR =       //
//******************************************//
    //******************************************************************************************************************
    /** @brief Constructor por default de la clase.
     */
    Lista();
    //******************************************************************************************************************
    /** @brief Constructor de copias de la clase.
     *
     * @param l Lista a copiar.
     */
    Lista(const Lista<T> &l);
    //******************************************************************************************************************
    /** @brief Sobrecarga del operador de asignaci&oacute;n "=".
     *
     * @param l Lista que se asignar&aacute; a la otra listq.
     * @return Lista a asignar.
     */
    Lista<T> & operator=(const Lista<T> &l);
    //******************************************************************************************************************
    /** @brief destructor de la clase.
    */
    ~Lista();


    //******************************************************************************************************************
    /** @brief  M&eacute;todo que agrega un nuevo elemento a la lista.
     *
     * @param val Valor del elemento a agregar.
     */
    void agregar(const T &val);
    //******************************************************************************************************************
    /** @brief  M&eacute;todo que elimina al primer elemento de la lista.
     *
     * @throws Excepci&oacute;n "ListaVacia" si la lista no cuenta con elementos.
     * @return Valor Eliminado
     */
     T eliminar();
    //******************************************************************************************************************
    /** @brief  M&eacute;todo que elimina al primer elemento coincidiente al p&aacute;rametro.
     *  @param val Valor del elemento a eliminar.
     * @throws Excepci&oacute;n "ListaVacia" si la lista no cuenta con elementos.
     */
    void eliminarPrimeraOcurrencia(const T &val);
    //******************************************************************************************************************
    /** @brief  M&eacute;todo que elimina todos los elementos coincidiente al p&aacute;rametro.
     *  @param val Valor del elemento a eliminar.
     * @throws Excepci&oacute;n "ListaVacia" si la lista no cuenta con elementos.
     */
    void eliminarTodaOcurrencia(const T &val);
    //******************************************************************************************************************
    /** @brief M&eacute;todo que verifica si un elemento se encuentra en la lista.
    *
    * @param val Valor del elemento a buscar.
    * @return True si el elemento est&aacute; en lista, False si no se encuentra.
    * @throws Excepci&oacute;n ListaVacia si la lista no cuenta con elementos.
    */
    bool buscar(const T &val);
    //******************************************************************************************************************
    /** @brief M&eacute;todo que vac&iacute; a la lista.
     */
    void vaciar ();
    //******************************************************************************************************************
    /** @brief M&eacute;todo que mueve la cabeza a la posici&oacute;n consiguiente;
     */
    void avanzar();
    //******************************************************************************************************************
    /** @brief M&eacute;todo que mueve la cabeza a la posici&oacute;n anterior;
     */
    void retroceder();
    //******************************************************************************************************************
    /**@brief M&eacute;todo para obtener el valor de la cabeza.
     *
     * @throws Excepci&oacute;n ListaVacia si la lista no cuenta con elementos.
     * @return Valor de la cabeza
     */
    const T &obtenerValor();
    //******************************************************************************************************************
    /** @brief M&eacute;todo para modificar el elemento en la cabeza.
     *
     * @param val Nuevo valor de la cabeza.
     * @throws Excepci&oacute;n " ListaVacia si la lista no cuenta con elementos.
     */
    void modificar(const T &val);
    //******************************************************************************************************************
    /** @brief M&eacute;todo que obtiene el tamaño de la lista.
     *
     * @return Tamaño de la lista.
     */
    unsigned obtenerTam() const;
    //******************************************************************************************************************
    /** @brief M&eacute;todo que verifica si la lista esta vacia o no.
     *
     * @return True si la lista est&aacute; vac&iacute;a, False si no lo esta.
     */
    bool estaVacia() const;
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
private:
    unsigned tam;        /** Tamaño de la lista */
    struct Nodo{
        explicit Nodo(T val, Nodo *sig = NULL, Nodo *ant = NULL);
        T valor;         /** Valor del elemento */
        Nodo *siguiente; /** Puntero al siguiente elemento */
        Nodo *anterior;  /** Puntero al elemento anterior */
    }*cabeza;  /** Punteros al primer y ultimo elemento de la lista (Valor y puntero del siguiente elemento */

};

#include "Lista.tpp"
#endif //LISTACIRCULAR_SGRC_LISTA_H
