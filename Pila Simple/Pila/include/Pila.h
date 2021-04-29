/*
Nombre: PruebaPilas.cpp
Autor: Sebastian Guadalupe Rivera de la Cruz
Fecha: 2/4/2021
Descripción:
*/

#ifndef PRUEBAPILAS_PILA_H
#define PRUEBAPILAS_PILA_H
#define TAM 10


class Pila {
public:
    Pila();

    Pila(int tope, double *contenido);

    bool agregar(double valor);
    void eliminar();
    double obtenerTope() const;
    bool estaVacia() const;
    bool estaLlena() const;
    int tam()const;
    int capacidad() const;
    void vaciar();
    void imprimir() const;

private:
    int tope;
    double contenido[TAM];
};


#endif //PRUEBAPILAS_PILA_H
