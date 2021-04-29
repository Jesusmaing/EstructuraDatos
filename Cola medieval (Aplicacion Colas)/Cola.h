//Nombre: cola.h
//Fecha: 18/03/2021
//Autor: Jesus Martin Garcia Encinas
//Descripción: Archivo de cabecera para la clase Cola

#ifndef PRUEBACOLA_COLA_H
#define PRUEBACOLA_COLA_H

#include <iostream>
#include "Persona.h"
template<typename T>
class Cola {
public:
//******************************************************************************************
    /** @brief Constructor por default de la clase.
    */
    Cola();
//******************************************************************************************
    /** @brief Constructor con par&aacute;metros de la clase.
    */
    Cola(const Cola<T> &c);
//******************************************************************************************
    /** @brief Sobrecarga del operador "=".
    *
     * @param c Cola que se asignar&aacute; a la otra cola.
     * @return Cola a asignar.
     */
    Cola <T> & operator=(const Cola<T> &c);
//******************************************************************************************
    /** @brief destructor de la clase.
    */
    ~Cola();
//******************************************************************************************
    /** @brief  M&eacute;todo que encola un nuevo elemento a la cola.
     *
     * @param val Valor del elemento a agregar.
     */
    void encolar(const T &val);
//******************************************************************************************
    /** @brief  M&eacute;todo que desencola un elemento de la cola.
     *
     */
    void desencolar();
//******************************************************************************************
    /** @brief  M&eacute;todo que obtiene el tamano de la cola.
     *
     * @return tamano de la cola
     */
    unsigned obtenerTam() const;
//******************************************************************************************
    /** @brief  M&eacute;todo para conocer si la cola est&aacute;
     *
     * @return devuelve true si est&aacute; vacia o false si no lo est&aacute;
     */
    bool estaVacia() const;
//******************************************************************************************
    /** @brief  M&eacute;todo para conocer el primer elemento de la cola
     *
     * @return primer elemento de la cola
     */
    const T & obtenerPrimero() const;
//******************************************************************************************
    /** @brief  M&eacute;todo para conocer el &uacute;timo elemento de la cola
     *
     * @return &uacute;ltimo elemento de la cola
     */
    const T & obtenerUltimo() const;
//******************************************************************************************
    /** @brief  M&eacute;todo para vaciar la cola completamente
     *
     */
    void vaciar();
//******************************************************************************************
    /** @brief  M&eacute;todo para imprimir los elementos de la cola
     *
     */
    void Imprimir() const;
    /** @class Clase utilizada para lanzar la excepci&oacute; colaVacia en caso de que la pila
     *          no tenga elementos.
     */
    class colaVacia : public std::exception {
    public:
        virtual const char * what() const throw();
    };

private:
    unsigned tam; /** Tamaño de la cola */
    struct Nodo{
        Nodo(T val, Nodo *sig = NULL);
        T valor;
        Nodo *siguiente;
    }*primero, *ultimo;
};

#include "Cola.tpp"
#endif //PRUEBACOLA_COLA_H
