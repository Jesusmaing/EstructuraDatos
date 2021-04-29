/*
Nombre: Vector.cpp
Autor: Jesus Martin Garcia Encinas
Fecha: 27/04/2021
Descripción: Implementación de la clase Vector que permite crear y manejar vectores en memoria dinámica.
*/

#include "Vector.h"
#include <iostream>

//**********************************************************************************************************************

Vector::Vector(char n /* = 'X' */): dimension(0), nombre(n)
{
    establecerDimension(1); // ó dimension = 1
    componente = new double[1];
    componente[0] = 0;
}

//**********************************************************************************************************************
Vector::Vector(int dim, char n /* = 'X' */): dimension(dim), nombre(n)
{
    componente = new double[dim];
    for (int i = 0; i < dim; ++i) componente[i] = 0;

}

//**********************************************************************************************************************

Vector::Vector(int dim, double valorInicial, char n /* = 'X' */): dimension(dim), nombre(n)
{
    componente = new double[dim];
    for (int i = 0; i < dim; ++i) componente[i] = valorInicial;

}

//**********************************************************************************************************************

Vector::Vector(const Vector &v): dimension(0),  componente(NULL), nombre(v.nombre)
{
    *this = v;
}

//**********************************************************************************************************************

Vector::~Vector()
{
    delete [] componente;
}

//**********************************************************************************************************************

void Vector::establecerComponente(int i, double comp)
{
    if(i < 0 || i >= dimension) throw std::out_of_range("\214ndice fuera de rango");
    componente[i] = comp;
}

//**********************************************************************************************************************

void Vector::establecerDimension(int dim)
{
    if(dim < 1) throw std::logic_error("Dimensi\242n fuera de rango");
    dimension = dim;
}

//**********************************************************************************************************************


int Vector::obtenerDimension() const
{
    return dimension;
}

//**********************************************************************************************************************

double Vector::obtenerComp(int i) const
{
    if(i < 0 || i > dimension) throw std::logic_error("\214ndice fuera de rango");
    return componente[i];
}

//**********************************************************************************************************************

void Vector::capturar()
{
    for (int i = 0; i < dimension; ++i) {
        std::cout << "Componente #" << (i+1) << ": ";
        std::cin >> componente[i];
    }
}

//**********************************************************************************************************************

void Vector::imprimir() const
{
    std::cout << "(";
    for (int i = 0; i < dimension; ++i) std::cout << componente[i] << ", ";
    std::cout << "\b\b)";
}
//**********************************************************************************************************************
#include <cmath>
double Vector::obtenerMagnitud() const
{
    double suma = 0;
    for (int i = 0; i < dimension; ++i) suma += componente[i] * componente[i];
    return std::sqrt(suma);
}
//**********************************************************************************************************************
Vector & Vector::operator=(const Vector &v)
        {
    if (this == &v) return *this;
    delete [] componente;
    establecerDimension(v.dimension);
    componente = new double[dimension];
    for (int i = 0; i < dimension; ++i) componente[i] = v.componente[i];
    return *this;
}
//**********************************************************************************************************************
Vector Vector::operator+(const Vector &v) const
{
    if(dimension != v.dimension)throw std::logic_error("Dimensiones incompatibles para la suma");
    Vector vSuma(dimension);
    for (int i = 0; i < dimension; ++i) {
        vSuma.componente[i] = componente[i] + v.componente[i];
    }
    return vSuma;
}
//**********************************************************************************************************************
Vector Vector::operator-(const Vector &v) const
{
    if(dimension != v.dimension)throw std::logic_error("Dimensiones incompatibles para la resta");
    Vector vResta(dimension);
    for (int i = 0; i < dimension; ++i) {
        vResta.componente[i] = componente[i] - v.componente[i];
    }
    return vResta;
}
//**********************************************************************************************************************
Vector Vector::operator*(double escalar) const
{
    Vector vProducto(dimension);
    for (int i = 0; i < dimension; ++i) vProducto.componente[i] = componente[i] * escalar;
    return vProducto;
}
//**********************************************************************************************************************
double Vector::operator*(const Vector &v) const
{
    if(dimension != v.dimension)throw std::logic_error("Dimensiones incompatibles para la multiplicación");
    double producto = 0;
    for (int i = 0; i < dimension; ++i) {
        producto += componente[i] * v.componente[i];
    }
    return producto;
}
//******************************************************************************************************************

bool Vector::operator==(const Vector &v) const
{
    if(dimension != v.dimension)throw std::logic_error("Dimensiones incompatibles para la multiplicación");
    for (int i = 0; i < dimension; ++i) {
        if (componente[i] == v.componente[i]) return true;
    }
    return false;
}
//******************************************************************************************************************
bool Vector::operator!=(const Vector &v) const
{
    if(dimension != v.dimension)throw std::logic_error("Dimensiones incompatibles para la multiplicación");
    for (int i = 0; i < dimension; ++i) {
        if (componente[i] == v.componente[i]) return false;
    }
    return true;
}
//******************************************************************************************************************

bool Vector::operator<(const Vector &v) const
{
   return obtenerMagnitud() < v.obtenerMagnitud();
}

bool Vector::operator>(const Vector &v) const
{
    return obtenerMagnitud() > v.obtenerMagnitud();
}
//******************************************************************************************************************
bool Vector::operator<=(const Vector &v) const
{
    return obtenerMagnitud() <= v.obtenerMagnitud();
}

bool Vector::operator>=(const Vector &v) const
{
    return obtenerMagnitud() >= v.obtenerMagnitud();
}
//******************************************************************************************************************

Vector Vector::operator++()
{
    for (int i = 0; i < dimension; ++i) ++componente[i];
    return *this;
}
//**********************************************************************************************************************
Vector Vector::operator++(int)
{
    Vector c = *this;
    for (int i = 0; i < dimension; ++i) ++componente[i];
    return c;
}
//**********************************************************************************************************************
const double & Vector::operator[](int i) const
{
    if(i < 0 || i > dimension) throw std::out_of_range("\214ndice fuera de rango");
    return componente[i];
}
//**********************************************************************************************************************
double & Vector::operator[](int i)
{
    if(i < 0 || i > dimension) throw std::out_of_range("\214ndice fuera de rango");
    return componente[i];
}
//**********************************************************************************************************************
void Vector::redimensionar(int dim)
{
    if(dim == dimension) return;
    int dimVieja = dimension;
    establecerDimension(dim);
    double *aux = componente;
    componente = new double [dimension];
    if(dimension < dimVieja) {
        for (int i = 0; i < dimension; ++i) componente[i] = aux[i];
    }else{
        for (int i = 0; i < dimVieja; ++i) componente[i] = aux[i];
        for (int i = dimVieja; i < dimension; ++i) componente[i] = 0;
    }
    delete [] aux;
}

// Funciones externas/amigas de Vector
Vector operator*(double escalar, const Vector &v)
{
    Vector vProducto(v.dimension);
    for (int i = 0; i < vProducto.dimension; ++i) vProducto.componente[i] = v.componente[i] * escalar;
    return vProducto;
}
//**********************************************************************************************************************
std::ostream & operator<<(std::ostream &fSalida, const Vector &v)
{
    fSalida << "(";
    for (int i = 0; i < v.dimension; ++i) fSalida << v.componente[i] << ", ";
    fSalida << "\b\b)";
    return fSalida;
}
//**********************************************************************************************************************
std::istream & operator>>(std::istream &fentrada, Vector &v)
{
    for (int i = 0; i < v.dimension; ++i) {
        std::cout << "Componente #" << (i+1) << ": ";
        fentrada >> v.componente[i];
    }
    return fentrada;
}
//**********************************************************************************************************************


