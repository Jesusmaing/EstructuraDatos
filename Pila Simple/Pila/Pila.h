/*
Nombre: Pila.h
Autor: Sebastian Guadalupe Rivera de la Cruz
Fecha: 14/02/2021
Descripción: Clase (plantilla) Pila que permite crear y manejar Pilas en memoria dinámica de cualquier tipo.
*/

#ifndef PILADINAMICA_SGRC_PILA_H
#define PILADINAMICA_SGRC_PILA_H

#include <iostream>
/** @class Clase que crea una estructura de pila y permite realizar todas sus modificaciones.
 *          Crea la pila en memoria din&aacute;mica y se expande al doble de su tamaño si se llena.
 * @tparam T Tipo de los elementos de la pila
 */
template <typename T = double>
class Pila {
public:
    //******************************************************************************************************************
    /** @brief Constructor por default de la clase.
     */
    Pila();
    //******************************************************************************************************************
    /** @brief Constructor de copias de la clase.
     *
     * @param p Pila a copiar.
     */
    Pila(const Pila<T> &p);
    //******************************************************************************************************************
    /** @brief Sobrecarga del operador de asignaci&oacute;n "=".
     *
     * @param p Pila que se asignar&aacute; a la otra pila.
     * @return Pila a asignar.
     */
    Pila & operator=(const Pila &p);
    //******************************************************************************************************************
    /** @brief destructor de la clase.
     */
    ~Pila();
    //******************************************************************************************************************
    /** @brief  M&eacute;todo que agrega un nuevo elemento al tope de pila.
     *
     * @param valor Valor del elemento a agregar.
     */
    void agregar(T valor);
    //******************************************************************************************************************
    /** @brief  M&eacute;todo que elimina el elemento al tope de la pila.
     *
     * @throws Excepci&oacute;n "PilaVacia" si la pila no cuenta con elementos.
     */
    void eliminar();
    //******************************************************************************************************************
    /** @brief M&eacute;todo que retorna el elemento al tope de la fila.
     *
     * @throws Excepci&oacute;n "PilaVacia" si la pila no cuenta con elementos.
     * @return Elemento al tope de la pila.
     */
    const T & obtenerTope() const;
    //******************************************************************************************************************
    /** @brief M&eacute;todo que verifica si la pila esta vacia o no.
     *
     * @return True si la pila esta vacia, False si no lo esta.
     */
    bool estaVacia() const;
    //******************************************************************************************************************
    /** @brief M&eacute;todo que vac&iacute; a la pila.
     */
    void vaciar();
    //******************************************************************************************************************
    /** @brief M&eacute;todo que obtiene el tamaño de la pila.
     *
     * @return Tamaño de la pila.
     */
    int obtenerTam()const;
    //******************************************************************************************************************
    /** @brief M&eacute;todo que obtiene la capacidad de la pila.
     *
     * @return Capacidad de la pila
     */
    int obtenerCap() const;
    //******************************************************************************************************************
    /** @brief M&eacute;todo que imprime a la pila.
     *
     * @throws Excepci&oacute;n "PilaVacia" si la pila no cuenta con elementos.
     */
    void imprimir() const;
    //******************************************************************************************************************
    /** @class Clase utilizada para lanzar la excepci&oacute; PilaVacia en caso de que la pila
     *          no tenga elementos.
     */
    class PilaVacia : public std::exception {
    public:
        virtual const char * what() const throw();
    };

private:
    int capacidad; /** Capacidad de la pila */
    int tope; /** Tope de la pila */
    T * contenido; /** Arreglo din&aacute;mico de la Pila */

    /** @brief M&eacute;todo que expande la capacidad de la pila al doble.
     */
    void redimensionar();

    /** @brief M&eacute;todo que verifica si la pila esta llena o no.
     *
     * @return True si la pila esta llena, False si no lo esta.
     */
    bool estaLlena() const;
};

#include "Pila.tpp"
#endif //PILADINAMICA_SGRC_PILA_H
