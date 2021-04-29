/*
Nombre: PruebaClaseVector.cpp
Autor: Sebastian Guadalupe Rivera de la Cruz
Fecha: 1/21/2021
Descripción:
*/

#ifndef PRUEBACLASEVECTOR_VECTOR_H
#define PRUEBACLASEVECTOR_VECTOR_H

#include <stdexcept>

#define MAXDIM 100

/** \breif Clase que representa a un vector anal@iacute;tico.
 *
 */
class Vector{
    // Operacion Escalar * Vector
    friend Vector operator*(double escalar, const Vector &v);
public:
    Vector();           //Constructor por Default
    Vector(int dim);    //Constructor u Operador de Conversión
    Vector(int dim, double valorInicial);

    Vector(const Vector &v);

    ~Vector();          //Destructor

    //**********************************************************************
    /** \brief M&eacute;todo que permite establecer el valor de una componente en un &iacute;ndice indicado.
     *
     * \param i int &iacute;ndice de la componente a establecer.
     * \param comp double valor a establecer de la componente.
     */
    void establecerComponente(int i, double comp);
    //**********************************************************************
    /** \brief  M&eacute;todo que establece la dimensi&oacute;n del vector.
     *
     * \param dim La dimensi&oacute;n a establecer.
     * \exception std::logic_error
     */
    void establecerDimension(int dim);
    //**********************************************************************
    /** \brief  M&eacute;todo que retorna la dimensi&oacute;n del vector.
     *
     * \return La dimensi&oacute;n del Vector.
     */
    int obtenerDimension() const;
    //**********************************************************************
    /** \brief  M&eacute;todo que retorna el valor de la componente en el &iacute;ndice indicado.
     *
     * \param i &Iacute;ndice de la componente que se desea obtener.
     * \return El valor de la componente en el &iacute;ndice indicado.
     */
    double obtenerComp(int i) const;
    //**********************************************************************
    /** \brief M&eacute;todo que retorna la norma del vector.
     *
     * \return Norma del vector.
     */
    double obtenerMagnitud() const;
    //**********************************************************************
    /** \brief M&eacute;todo que permite capturar las componentes del vector.
     *
     */
    void capturar();
    //**********************************************************************
    /** \brief M&eacute;todo que permite Imprimir las componentes del vector.
     *
     */
    void imprimir() const;
    //**********************************************************************
    /** \brief  M&eacute;todo que permite sumar dos vectores.
     *
     * \param v Vector que se sumar&aacute.
     * \return El vector resultande de la suma.
     */
//    Vector sumar(Vector v) const;
    //**********************************************************************
    /** \brief  M&eacute;todo que permite restar dos vectores.
     *
     * \param v Vector que se restar&aacute;.
     * \return El vector resultande de la resta.
     */
    Vector restar(Vector v) const;                      //Pendiente
    //**********************************************************************
    /** \brief M&eacute;todo que permite multiplicar un escalar a un vector.
     *
     * \param escalar Valor que multiplica al vector.
     * \return El vector resultante.
     */
    Vector multiplicar(double escalar) const;
    //**********************************************************************
    /** \brief M&eacute;todo que multiplica dos vectores mediante producto punto.
     *
     * \param v Vector que se multiplicar&aacute.
     * \return El vector resultante.
     */
    Vector multiplicar(Vector v) const;                 //Pendiente
    //**********************************************************************

    Vector operator+(const Vector &v) const;
    //Operacion Vector * Escalar
    Vector operator*(double escalar) const;
    Vector operator*(const Vector &v) const;
    Vector & operator=(const Vector &v);

private:
    int dimension;
    //double componente[MAXDIM];
    double *componente;


};


#endif //PRUEBACLASEVECTOR_VECTOR_H
