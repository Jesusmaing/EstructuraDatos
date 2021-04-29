/*
Nombre: Vector.cpp
Autor: Sebastian Guadalupe Rivera de la Cruz
Fecha: 14/02/2021
Descripción: Clase Vector que permite crear y manejar vectores en memoria dinámica.
*/

#ifndef PRUEBACLASEVECTOR_VECTOR_H
#define PRUEBACLASEVECTOR_VECTOR_H


#include <iostream>

#define MAXDIM 100

/** @class Vector Clase que representa a un vector anal@iacute;tico.
 */
class Vector{
    //******************************************************************************************************************
    /**@brief Sobrecarga del operador "*" para realizar el producto de un vector
     *          por un escalar de manera conmutativa.
     *
     * @param escalar Escalar que multiplica a la instancia.
     * @param v Vector que se multiplicar&aacute;
     * @return Producto del Vector por el escalar.
     */
    friend Vector operator*(double escalar, const Vector &v);
    //******************************************************************************************************************
    /** @brief Sobrecarga del operador "<<" para imprimir un vector.
     *
     * @param fSalida flujo de salida.
     * @param v Vector a imprimir.
     * @return Flujo de salida a imprimir.
     */
    friend std::ostream & operator<<(std::ostream &fSalida, const Vector &v);
    //******************************************************************************************************************
    /** @brief Sobrecarga del operador ">>" para capturar un vector.
     *
     * @param fEntrada flujo de entrada.
     * @param v Vector Matriz a capturar.
     * @return Flujo de salida a capturar.
     */
    friend std::istream & operator>>(std::istream &fentrada, Vector &v);
    //******************************************************************************************************************
public:
    //******************************************************************************************************************
    /** @brief Constructor de la clase.
     *
     * @param n Nombre del vector.
     */
    explicit Vector(char n = 'X');
    //******************************************************************************************************************
    /** @brief Constructor de dos parametros de la clase.
     *
     * @param dim Dimensi&oacute;n del vector.
     * @param n Nombre del vector.
     */
    explicit Vector(int dim, char n = 'X');
    //******************************************************************************************************************
    /** @brief Constructor de tres parametros de la clase.
     *
     * @param dim Dimensi&oacute;n del vector.
     * @param valorInicial Valor que se asignar&aacute; a todos los elementos del vector.
     * @param n Nombre del vector.
     */
    Vector(int dim, double valorInicial, char n = 'X');
    //******************************************************************************************************************
    /** @brief Constructor de copias de la clase.
     *
     * @param v Vector a copiar
     */
    Vector(const Vector &v);
    //******************************************************************************************************************
    /** @brief Destuctor de la clase.
     */
    ~Vector();
    //******************************************************************************************************************
    /** @brief M&eacute;todo que permite establecer el valor de una componente en un &iacute;ndice indicado.
     *
     * @param i int &iacute;ndice de la componente a establecer.
     * @param comp double valor a establecer de la componente.
     */
    void establecerComponente(int i, double comp);
    //******************************************************************************************************************
    /** @brief  M&eacute;todo que retorna la dimensi&oacute;n del vector.
     *
     * @return La dimensi&oacute;n del Vector.
     */
    int obtenerDimension() const;
    //******************************************************************************************************************
    /** @brief  M&eacute;todo que retorna el valor de la componente en el &iacute;ndice indicado.
     *
     * @param i &Iacute;ndice de la componente que se desea obtener.
     * @return El valor de la componente en el &iacute;ndice indicado.
     */
    double obtenerComp(int i) const;
    //******************************************************************************************************************
    /** @brief M&eacute;todo que retorna la norma del vector.
     *
     * @return Norma del vector.
     */
    double obtenerMagnitud() const;
    //******************************************************************************************************************
    /** @brief M&eacute;todo que permite capturar las componentes del vector.
     *
     */
    void capturar();
    //******************************************************************************************************************
    /** @brief M&eacute;todo que permite Imprimir las componentes del vector.
     *
     */
    void imprimir() const;
    //******************************************************************************************************************
    /** @brief Sobrecarga del operador "=".
     *
     * @param v Vector que se asignara a otro vector.
     * @return Vector a asignar.
     */
    Vector & operator=(const Vector &v);
    //******************************************************************************************************************
    /** @brief  Sobrecarga del operador "+" para realizar la suma de dos vectores.
     *
     * @param v Vector que se sumar&aacute.
     * @return El vector resultande de la suma.
     */
    Vector operator+(const Vector &v) const;
    //******************************************************************************************************************
    /** @brief  Sobrecarga del operador "-" para realizar la resta de dos vectores.
     *
     * @param v Vector que se restar&aacute;.
     * @return El vector resultande de la resta.
     */
    Vector operator-(const Vector &v) const;
    //******************************************************************************************************************
    /** @brief Sobrecarga del operador "*" para realizar el producto de un vector por un escalar.
     *
     * @param escalar Valor que multiplica al vector.
     * @return El vector resultante.
     */
    Vector operator*(double escalar) const;
    //******************************************************************************************************************
    /** @brief Sobrecarga del operador "*" para realizar el producto de dos vectores.
     *
     * @param v Vector que se multiplicar&aacute.
     * @return El vector resultante.
     */
    double operator*(const Vector &v) const;
    //******************************************************************************************************************
    /** @brief Sobrecarga del operador "++" para sumar una unidad a un vector
     *
     * @return El vector resultante.
     */
    Vector operator++();
    //******************************************************************************************************************
    /** @brief Sobrecarga del operador "++" para sumar una unidad a un vector
     *
     * @return El vector resultante.
     */
    Vector operator++(int);
    //******************************************************************************************************************
    /** @brief Sobrecarga del operador "[]" para a un elemento del vector. rvalue
     *
     * @param i &Iacute;ndice a acceder.
     * @exception out_of_range Se lanza si el &iacutendice esta fuera de rango.
     * @return La componente que se desea acceder.
     */
    const double & operator[](int i) const;
    //******************************************************************************************************************
    /** @brief Sobrecarga del operador "[]" para a un elemento del vector. lvalue
     *
     * @param i &Iacute;ndice a acceder.
     * @exception out_of_range Se lanza si el &iacutendice esta fuera de rango.
     * @return La componente que se desea acceder.
     */
    double & operator[](int i);
    //******************************************************************************************************************
    /** @brief M&eacute;todo que cambia la dimensi&oacute;n del vector.
     *
     * @param dim La nueva dimensi&oacute;n
     */
    void redimensionar(int dim);
    //******************************************************************************************************************
private:
    int dimension;  /** Dimensi&oacuten del vector */
    double *componente; /** Arreglo din&aacute;mico del vector */
    const char nombre; /** Nombre del vector */

    //******************************************************************************************************************
    /** @brief  M&eacute;todo de utiler&iacute;a que establece la dimensi&oacute;n del vector.
     *
     * @param dim La dimensi&oacute;n a establecer.
     * @exception std::logic_error
     */
    void establecerDimension(int dim);
    //******************************************************************************************************************
};


#endif //PRUEBACLASEVECTOR_VECTOR_H
