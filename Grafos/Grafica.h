/*
Nombre: Grafica.h
Autor: Jesus Martin Garcia Encinas
Fecha: 09/04/2021
Descripción: Archivo de cabezera de plantilla clase Grafica que permite la manipulación de una Gráfica con sus métodos indispensables
*/

#ifndef GRAFOS_GRAFICA_H
#define GRAFOS_GRAFICA_H
#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;
template <typename T>
/**
 * @class  Clase Grafica
 * @tparam T Plantilla a Grafica
 */
class Grafica {
public:
    /** @brief Constructor por default de la clase.
    */
    Grafica();
    /** @brief Constructor de copias de la clase.
     *
     * @param l Gr&aacute;fica a copiar.
     */
    Grafica(const Grafica<T> &g); // *this = g
    /** @brief Sobrecarga del operador de asignaci&oacute;n "=".
     *
     * @param l Gr&aacute;fica que se asignar&aacute; a la otra Grafica.
     * @return Gr&aacute;fica a asignar.
     */
    Grafica<T> & operator=(const Grafica<T> &g);
    /** @brief destructor de la clase.
    */
     ~Grafica();

    /** @brief  M&eacute;todo que agrega un nuevo nodo(v&eacute;rtice) a la Gr&aacute;fica.
     *
     * @param _id id del nodo(v&eacute;rtice) a agregar.
     */
     void Agregar(const T & _id);
     /** @brief  M&eacute;todo que agrega una nueva arista a la Gr&aacute;fica.
     *
     * @param inicio. Extremo inicial de la arista
     * @param fin Extremo final de la arista
     */
     void Agregar(const T &inicio, const T &fin);
    /** @brief  M&eacute;todo que elimina un nodo(v&eacute;rtice) de la Gr&aacute;fica.
    *
    * @param _id id del nodo(v&eacute;rtice) a eliminar.
    */
     void Eliminar(const T & _id);
    /** @brief  M&eacute;todo que elimina una arista de la Gr&aacute;fica.
    *
    * @param inicio. Extremo inicial de la arista
    * @param fin Extremo final de la arista
    */
     void Eliminar(const T &inicio, const T &fin);
    /** @brief M&eacute;todo para obtener el n&uacute;mero de nodos(v&eacute;rtices) de la gr&aacute;fica.
    *
    * @return N&uacute;mero de nodos(v&eacute;rtices) de la gr&aacute;fica.
    * @throws Excepci&oacute;n "GraficaVacia" si la gr&aacute;fica no cuenta con nodos.
    */
     unsigned ObtenerNumNodos() const;
    /** @brief M&eacute;todo para obtener el n&uacute;mero de ariestas de la gr&aacute;fica.
    * @return N&uacute;mero de aristas de la gr&aacute;fica.
    */
     unsigned ObtenerNumAristas() const;
    /** @brief M&eacute;todo para obtener el grado de un nodo(v&eacute;rtice) la gr&aacute;fica.
    * @param _id id de nodo a devolver su grado
    * @return N&uacute;mero de aristas de la gr&aacute;fica.
    */
     unsigned ObtenerGrado(const T &_id) const;
    /** @brief  M&eacute;todo que verifica si se encuentra un nodo en la gr&aacute;fica.
    *
    * @param _id id de nodo a buscar
    * @return devuelve true si el elemento est&aacute; en gr&aacute;fica, de lo contrario, delvolver&aacute; false.
    * @throws Excepci&oacute;n "GraficaVacia" si la gr&aacute;fica no cuenta con elementos.
    */
     bool Buscar(const T &_id) const;
    /** @brief  M&eacute;todo que verifica si se encuentra una Arista en la gr&aacute;fica.
    *
    * @param inicio. Extremo inicial de la arista a buscar
    * @param fin Extremo final de la arista a buscar
    * @return devuelve true si la arista est&aacute; en la gr&aacute;fica, de lo contrario, delvolver&aacute; false.
    * @throws Excepci&oacute;n "GraficaVacia" si la gr&aacute;fica no cuenta con elementos.
    */
     bool Buscar(const T &inicio, const T &fin);
    /** @brief M&eacute;todo que imprime a la gr&aacute;fica.
    */
     void Imprimir() const;

    /** @brief M&eacute;todo que verifica si la gr&aacute;fica esta vacia o no.
    *
    * @return True si la gr&aacute;fica est&aacute; vac&iacute;a, False si no lo esta.
    */
     bool EstaVacia();
     /** @brief M&eacute;todo que vac&iacute; a la gr&aacute;fica.
    */
     void vaciar();
    /** @brief M&eacute;todo que vac&iacute; a un nodo de la gr&aacute;fica.
     * @param id ID del nodo(v&eacute;rtice) a vaciar
    */
     void vaciar(const T &id);



private:
    unsigned numNodos , numAristas;
    /**
     * Estructura para crear un vertice en una gr&aacute;fica
     */
    struct Nodo{
        /** @brief Constructor de la estructura.
         * @param _id Valor del v&eacute;rtice
         * @param ant Puntero del siguiente v&eacute;rtice
         * @param sig Puntero del  v&eacute;rtice anterior
     */
        Nodo(T _id, Nodo *sig = NULL, Nodo *ant = NULL);
        /*@{*/
        T id; /**< Valor del v&eacute;rtice */
        Nodo *siguiente; /**< Puntero de la posici&oacute;n del siguiente v&eacute;rtice */
        int grado; /**< Total de aristas de un v&eacute;rtice */
        /*@}*/

        /**
         * Estructura para crear aristas en un v&eacute;rtice localizado dentro de una gr&aacute;fica
         */
        struct Arista {
            /** @brief Constructor de la estructura.
             * @param _adyacente Nodo adyacente del v&eacute;rtice
             * @param _sig &Uacute;ltimo extremo del v&eacute;rtice
             * @param _ant Primer extremo del v&eacute;rtice
         */
            Arista(Nodo *_adyacente, Arista *_sig = NULL, Arista *_ant = NULL);
            /*@{*/
            Nodo *adyacente; /**< Puntero para guardar el nodo adyacente */
            Arista *siguiente;  /**< Puntero para la posici&oacute;n de la siguiente arista */
            /*@}*/
        }*primera, *ultima;


         /** @brief  M&eacute;todo que agrega una nueva arista a la Gr&aacute;fica.
         *
         * @param _adyacente Nodo adyacente para agregar la conexi&oacute;n
         */
        void Agregar(Nodo *_adyacente);
        /** @brief  M&eacute;todo para buscar una arista en la Gr&aacute;fica
        *
        * @param _adyacente Nodo adyacente para buscar la conexi&oacute;n
        * @return devuelve true si la arista est&aacute; en gr&aacute;fica, de lo contrario, delvolver&aacute; false.
        */
        bool Buscar(Nodo *_adyacente) const;
        /** @brief  M&eacute;todo que elimina una arista de la Gr&aacute;fica.
        *
        * @param _adyacente Nodo adyacente para eliminar la conexi&oacute;n
        */
        void Eliminar (Nodo *_adyacente);
        /** @brief  M&eacute;todo que busca la direccion de una arista en la Gr&aacute;fica.
        *
        * @param _adyacente Nodo adyacente para buscar la conexi&oacute;n
        * @param pAnt
        * @return Retorna el pbjeto tipo nodo en la posici&oacute;n encontrada
        */
        typename Nodo::Arista *DireccionArista(Nodo *_adyacente , typename Nodo::Arista **pAnt = NULL) const;

    }*primero,*ultimo;
    /** @brief  M&eacute;todo que busca la direccion de un v&eacute;rtice en la Gr&aacute;fica.
    *
    * @param _adyacente Nodo adyacente para buscar la conexi&oacute;n
    * @param pAnt
    * @return Retorna el pbjeto tipo nodo en la posici&oacute;n encontrada
    */
    Nodo *DireccionVertice(const T &_id, Nodo **pAnt = NULL) const;
    /** @brief M&eacute;todo que imprime las aristas de la gr&aacute;fica.
     * @param id ID del nodo(v&eacute;rtice) a imprimir su arista
    */
    void Imprimir(const T &_id) const;
};




#include "Grafica.tpp"
#endif //GRAFOS_GRAFICA_H
