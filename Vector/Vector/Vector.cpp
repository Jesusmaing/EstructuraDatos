
/*
Nombre: PruebaVector.cpp
Autor: Sebastian Guadalupe Rivera de la Cruz
Fecha: 1/18/2021
Descripción:
*/

#include "Vector.h"
#include <iostream>

//**********************************************************************

Vector::Vector()
{
    establecerDimension(1); // ó dimension = 1
    componente = new double[1];
    componente[0] = 0;
}

//**********************************************************************

Vector::Vector(int dim)
{
    establecerDimension(dim);
    componente = new double[dim];
    for (int i = 0; i < dim; ++i) componente[i] = 0;

}

//**********************************************************************

Vector::Vector(int dim, double valorInicial)
{
    establecerDimension(dim);
    componente = new double[dim];
    for (int i = 0; i < dim; ++i) componente[i] = valorInicial;

}

//**********************************************************************

Vector::Vector(const Vector &v)
{
    establecerDimension(v.dimension);
    componente = new double [dimension];
    for (int i = 0; i < dimension; ++i) componente[i] = v.componente[i];
}

//**********************************************************************

Vector::~Vector()
{
    delete [] componente;
}

//**********************************************************************

void Vector::establecerComponente(int i, double comp)
{
    if(i < 0 || i >= dimension) throw std::out_of_range("\214ndice fuera de rango");
    componente[i] = comp;
}

//**********************************************************************

void Vector::establecerDimension(int dim)
{
    if(dim < 1 || dim > MAXDIM) throw std::logic_error("Dimensi\242n fuera de rango");
    dimension = dim;
}

//**********************************************************************


int Vector::obtenerDimension() const
{
    return dimension;
}

//**********************************************************************

double Vector::obtenerComp(int i) const
{
    if(i < 1 || i > MAXDIM) throw std::logic_error("\214ndice fuera de rango");
    return componente[i];
}

//**********************************************************************

void Vector::capturar()
{
    for (int i = 0; i < dimension; ++i) {
        std::cout << "Componente #" << (i+1) << ": ";
        std::cin >> componente[i];
    }
}

//**********************************************************************

void Vector::imprimir() const
{
    std::cout << "(";
    for (int i = 0; i < dimension; ++i) std::cout << componente[i] << ", ";
    std::cout << "\b\b)";
}

//**********************************************************************

//Vector Vector::sumar(Vector v) const
//{
//    if(dimension != v.dimension)throw std::logic_error("Dimensiones incompatibles para la suma");
//    Vector vSuma(dimension);
//    for (int i = 0; i < dimension; ++i) {
//        vSuma.componente[i] = componente[i] + v.componente[i];
//    }
//
//    return vSuma;
//}

//**********************************************************************

Vector Vector::restar(Vector v) const           //Pendiente
{
    if(dimension != v.dimension)throw std::logic_error("Dimensiones incompatibles para la suma");
    Vector vResta(dimension);
    for (int i = 0; i < dimension; ++i)
        vResta.componente[i] = componente[i] - v.componente[i];
    return  vResta;
}

//**********************************************************************

//Vector Vector::multiplicar(double escalar) const
//{
//    Vector vProducto(dimension);
//    for (int i = 0; i < dimension; ++i) vProducto.componente[i] = componente[i] * escalar;
//    return vProducto;
//}

//**********************************************************************

Vector Vector::multiplicar(Vector v) const      //Pendiente
{
    return v;

}

//**********************************************************************
#include <cmath>
double Vector::obtenerMagnitud() const
{
    double suma = 0;
    for (int i = 0; i < dimension; ++i) suma += componente[i] * componente[i];
    return std::sqrt(suma);
}

//**********************************************************************

Vector Vector::operator+(const Vector &v) const
{
    if(dimension != v.dimension)throw std::logic_error("Dimensiones incompatibles para la suma");
    Vector vSuma(dimension);
    for (int i = 0; i < dimension; ++i) {
        vSuma.componente[i] = componente[i] + v.componente[i];
    }

    return vSuma;
}

Vector Vector::operator*(double escalar) const
{
    Vector vProducto(dimension);
    for (int i = 0; i < dimension; ++i) vProducto.componente[i] = componente[i] * escalar;
    return vProducto;
}

Vector & Vector::operator=(const Vector &v) {
    if (this == &v) return *this;
    delete[] componente;
    establecerDimension(v.dimension);
    componente = new double[dimension];
    for (int i = 0; i < dimension; ++i) componente[i] = v.componente[i];
    return *this;
}

// Funciones amigs de Vector
Vector operator*(double escalar, const Vector &v)
{
    Vector vProducto(v.dimension);
    for (int i = 0; i < vProducto.dimension; ++i) vProducto.componente[i] = v.componente[i] * escalar;
    return vProducto;
    // o return v * escalar; y no hay nececidad de hacerlo amigo
}



