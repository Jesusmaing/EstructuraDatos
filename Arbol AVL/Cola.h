/*
Nombre: Cola.h
Autor: Jesus Martin Garcia Encinas
Fecha: 22/04/2021
Descripción: Cola enlazada
*/

#ifndef UNTITLED_COLA_H
#define UNTITLED_COLA_H


template<typename T>
class Cola {

public:
    /**
     * @brief Constructor de la clase.
     */
    Cola();

    /**
     * @brief Destructor de la clase
     */
    ~Cola();

    /**
     * @brief Constructor de copias de la clase
     * @param C Una referencia a una cola
     */
    Cola(const Cola<T> &C);

    /**
     * @brief El operador igual sobrecargado para copiar los elementos de una cola a otra
     * @param C La referencia a otra cola
     * @return Regresa una cola con los elementos de otra
     */
    Cola<T> &operator=(const Cola<T> &C);

    /**
     * @brief Método para AgregarElemento un elemento al final de la cola
     * @param valor el valor que tendrá el elemento que se agregará a la cola
     */
    void Encolar(const T &valor);

    /**
     * @brief Método para EliminarElemento el elemento al frente de la cola
     */
    void Desencolar();

    /**
     * @brief Método para obtener el valor del elemento al inicio de la cola.
     * @return El valor del elemento al frente de la cola.
     */
    T ObtenerPrimero();

    /**
     * @brief Método para conocer el elemento al final de la cola.
     * @return El valor del elemento al final de la cola
     */
    unsigned ObtenerFinal();

    /**
     * @brief Método para conocer si la cola está vacía o no
     * @return Un valor booleano que nos indica true si está vacía o false si tiene elemento
     */
    bool EstaVacia() const;

    /**
     * @brief Método para quitar a todos los elementos de la cola
     */
    void Vaciar();

    /**
     * @brief Método para obtener el tamaño de la cola
     */
    unsigned ObtenerTam();

    /**
     * @brief Método para Imprimir la cola
     */
    void imprimir();


private:
    struct Elemento {
        T valor;
        Elemento *sig;

        Elemento(T v, Elemento *sig = NULL) : valor(v), sig(sig) {}
    };

    Elemento *fondo;
    int numELem;

};

#include "Cola.tpp"

#endif //UNTITLED_COLA_H
