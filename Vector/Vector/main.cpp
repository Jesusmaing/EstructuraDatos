#include <iostream>
#include <limits>

#include "Vector.h"

using namespace std;

int main()
{
    try{
        Vector v(3), w(3), z(3), y;

        cout << "Suma de dos Vectores" << endl;

        cout << "Capturando las " << v.obtenerDimension() << " del primer vector..." << endl;
        v.capturar();

        cout << "Capturando las " << w.obtenerDimension() << " del segundo vector..." << endl;
        w.capturar();

        y = z = v + w;
        z = v * 5;

       //z = v.sumar(w);

        cout << "V: ";
        v.imprimir();
        cout << endl;
        cout << "W: ";
        w.imprimir();
        cout << endl;
        cout << "V + W: ";
        y.imprimir();
        cout << endl;
        cout << "V * 5: ";
        z.imprimir();
        cout << endl;


    }catch(out_of_range &exc){
        cout << "\nError: " << exc.what() << endl;
    }catch(logic_error &exc){
        cout << "\nError: " << exc.what() << endl;
    }catch(bad_alloc &exc){
        cout << "\nError: " << exc.what() << endl;
    }

    return 0;
}
