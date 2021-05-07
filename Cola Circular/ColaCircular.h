/*
Nombre: ColaCircular.h
Autor: JESUS MARTIN GARCIA ENCINAS
Fecha: 2/3/2021
*/

#ifndef PRUEBACOLA_COLACIRCULAR_H
#define PRUEBACOLA_COLACIRCULAR_H

#include <iostream>

template<typename T>
class ColaCircular {
public:

    //******************************************************************************************
    /** @brief Constructor por default de la clase.
    */
    ColaCircular();
    //******************************************************************************************
   /** @brief Constructor con par@aacute;metros de la clase.
    */
    ColaCircular(const ColaCircular<T> &c);
    //******************************************************************************************
    /** @brief Sobrecarga del operador "=".
    *
     * @param c Cola que se asignar&aacute; a la otra cola.
     * @return Cola a asignar.
     */
    ColaCircular <T> & operator=(const ColaCircular<T> &c);
    //******************************************************************************************
    /** @brief destructor por default de la clase.
    */
    ~ColaCircular();
    //******************************************************************************************
    /** @brief  M@eacute;todo que encola un nuevo elemento a la cola.
     *
     * @param val Valor del elemento a agregar.
     */
    void encolar(const T &val);
    //******************************************************************************************
    /** @brief  M@eacute;todo que desencola un elemento de la cola.
     *
     */
    //******************************************************************************************
    void desencolar();
    /** @brief  M@eacute;todo que obtiene el tamano de la cola.
     *
     * @return tamano de la cola
     */
    unsigned obtenerTam() const;
    //******************************************************************************************
    /** @brief  M@eacute;todo para conocer si la cola est@aacute;
     *
     * @return devuelve true si est@aacute; vacia o false si no lo est@aacute;
     */
    bool estaVacia() const;
    //******************************************************************************************
    /** @brief  M@eacute;todo para conocer el primer elemento de la cola
     *
     * @return primer elemento de la cola
     */
    const T & obtenerPrimero() const;
    //******************************************************************************************
    /** @brief  M@eacute;todo para conocer el @uacute;timo elemento de la cola
     *
     * @return @uacute;ltimo elemento de la cola
     */
    const T & obtenerUltimo() const;
    //******************************************************************************************
    /** @brief  M@eacute;todo para vaciar la cola completamente
     *
     */
     
    void vaciar();
    //******************************************************************************************
    /** @brief  M@eacute;todo para imprimir los elementos de la cola
     *
     */
    void Imprimir() const;
    //******************************************************************************************
    /** @class Clase utilizada para lanzar la excepci&oacute; colaVacia en caso de que la pila
 *          no tenga elementos.
 */
    class ColaVacia : public std::exception {
    public:
        virtual const char * what() const throw();
    };

private:
    unsigned tam;
    struct Nodo{
        Nodo(T val, Nodo *sig = NULL);
        T valor;
        Nodo *siguiente;
    }*ultimo;
};

#include "ColaCircular.tpp"
#endif //PRUEBACOLA_COLACIRCULAR_H
