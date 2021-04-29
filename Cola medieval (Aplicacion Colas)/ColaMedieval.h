//Nombre: cola.h
//Fecha: 18/03/2021
//Autor: Jesus Martin Garcia Encinas
//Descripción: Archivo de cabecera para la clase ColaMedieval

#ifndef PRUEBACOLA_COLAMEDIEVAL_H
#define PRUEBACOLA_COLAMEDIEVAL_H

#include "Persona.h"
#include "Cola.h"
class ColaMedieval {
public:
    //******************************************************************************************
    /** @brief Constructor por default de la clase.
    */
    ColaMedieval();
    /** @brief Constructor con par@aacute;metros de la clase.
     */
    ColaMedieval(const ColaMedieval &c);
    /** @brief Sobrecarga del operador "=".

     * @param c Cola que se asignar&aacute; a la otra cola.
     * @return Cola a asignar.
     */
    ColaMedieval & operator=(const ColaMedieval &c);
    /** @brief Destructor cde la clase.
     */
    ~ColaMedieval();

    /** @brief  M&eacute;todo que encola un nuevo elemento a la cola de Nobles o de Plebeyos dependiendo de los p&aacute;rametros.
     *
     * @param Persona &p Objeto del tipo persona a encolar.
     */
    void EncolarCiudadadano(const Persona &p);

    /** @brief  M&eacute;todo que devuelve el primer objeto tipo Persona de la cola
     * @return Objeto tipo persona
     */
    Persona consultarPrimero() const;

    /** @brief  M&eacute;todo que devuelve el &uacute;ltimo objeto tipo Persona de la cola
     * @return Objeto tipo persona
     */
    Persona ConsultarUltimo() const;
    /** @brief  M&eacute;todo que desencola un elemento de la cola.
     *
     */
    void desencolar();
    /** @brief  M&eacute;todo que obtiene la cantidad de nobles de la cola
     *
     * @return Cantidad de nobles de la cola
     */
    unsigned CantidadNobles() const;
    /** @brief  M&eacute;todo que obtiene la cantidad de plebeyos de la cola
     *
     * @return Cantidad de plebeyos de la cola
     */
    unsigned CantidadPlebeyos() const;
    /** @brief  M&eacute;todo que obtiene la cantidad de personas de la cola
     *
     * @return Cantidad de personas de la cola
     */

    unsigned ConsultarCantidadCiudadadanos() const;
    /** @brief  M&eacute;todo para conocer si las colas est&aacute;n vac&iacute;as
     *
     * @return devuelve true si est&aacute; vacia o false si no lo est&aacute;
     */
    bool estaVacia() const;
    /** @brief  M&eacute;todo para imprimir los elementos de la cola
     *
     */
    void ImprimirCola() const;

private:
    Cola<Persona> ColaNobles;
    Cola<Persona> ColaPlebeyos;
};


#endif //PRUEBACOLA_COLAMEDIEVAL_H
