/*
Nombre: ArbolB_SGRC.cpp
Autor: Sebastian Guadalupe Rivera de la Cruz
Fecha: 5/3/2021
Descripción:
*/

#ifndef ARBOLB_SGRC_ARBOLB_H
#define ARBOLB_SGRC_ARBOLB_H

template <typename T, int Grado = 5>
class ArbolB {
public:
    //******************************************************************************************************************
    /** @brief Constructor por default de la clase.
     */
    ArbolB();
    //******************************************************************************************************************
    /** @brief Constructor de copias de la clase.
     *
     * @param a &Aacute;rbol a copiar.
     */
    ArbolB(const ArbolB<T,Grado> &a);
    //******************************************************************************************************************
    /** @brief Sobrecarga del operador de asignaci&oacute;n "=".
     *
     * @param a &Aacute;rbol que se asignar&aacute; al otro &aacute;rbol.
     * @return &Aacute;rbol a asignar.
     */
    ArbolB<T,Grado> & operator=(const ArbolB<T,Grado> &a);
    //******************************************************************************************************************
    /** @brief destructor de la clase.
     */
    ~ArbolB();
    //******************************************************************************************************************
    /** @brief M&eacute;todo que agrega un nuevo vertice al &aacute;rbol.
     *
     * @param val Valor del vertice al agregar.
     * @return True si se agreg&oacute;, False si ya existe.
     */
    void agregar(const T &val);
    //******************************************************************************************************************
    /** @brief M&eacute;todo que elimina un vertice del &aacute;rbol.
     *
     * @param val Valor del vertice a eliminar.
     * @throws Excepci&oacute;n "ABB<T>::ArbolVacio" si el &aacute;rbol no cuenta con elementos.
     * @return True si se elimin&oacute;, False si no existe.
     *
     */
    void eliminar(const T &val);
    //******************************************************************************************************************
    /** @brief M&eacute;todo que busca un vertice en la &aacute;rbol.
     *
     * @param val Valor del vertice a buscar.
     * @return True si se encontr&oacute;, False si no.
     */
    void buscar(const T &val) const;
    //******************************************************************************************************************
    /** @brief M&eacute;todo para imprimir el &aacute;rbol.
     *
     * @param orden Forma en que se va a imprimir el &aacute;rbol. (Dependiendo de la enumeraci&oacute;n FormasImpresion)
     */
    void imprimir(short orden) const;
    //******************************************************************************************************************
    bool estaVacio() const;
    //******************************************************************************************************************
    /** @brief Enumeraci&oacute;n utilizada para escoger la forma de impresi&oacute;n del &aacute;rbol.
     */
    enum FormasImpresion{
        ASCENDENTE = 1,      /** Imprimir el arbol de manera ascendente. */
        DESCENDENTE,         /** Imprimir el arbol de manera descendente. */
        POR_NIVELES          /** Imprimir el arbol por niveles. */
    };
    //******************************************************************************************************************

private:
    struct Vertice{
        Vertice();
        T clave[Grado];
        Vertice * hijo[Grado];
        unsigned tamClaves;
        // Num de hijos es tamClaves + 1

        /** @brief M&eacute;todo que determina si un vertice es hoja, es decir, no tiene hijos.
         *
         * @return True si es hoja, False si no.
         */
        bool esHoja() const;

    } *raiz;
    unsigned cantidadClaves;

    void agregarVertice(Vertice *&subRaiz, Vertice *&padre, const T &val);
    void partir(Vertice *subRaiz, Vertice *padre);
    
    void mezclar(Vertice *verticeA, Vertice *verticeB);
    bool buscar(const Vertice *verticeBusqueda, const T &val) const;
    bool eliminar(const Vertice *verticeBusqueda, const T &val);

};

#include "ArbolB.tpp"


#endif //ARBOLB_SGRC_ARBOLB_H
