#ifndef BUSQUEDA_BINARIA_H
#define BUSQUEDA_BINARIA_H
#include <iostream>
#include <string>
#include "MiVector.h"
using namespace std;

template <typename T>
class Busqueda_binaria {
public:
    // Constructor que recibe un vector
    Busqueda_binaria(MiVectorT>& datos) : datos(datos) {}

    // Método de búsqueda binaria (iterativo)
    int busqueda_binaria(T clave) {
        int izq = 0, der = datos.size();

        while (izq <= der) {
            int mid = izq + (der - izq) / 2;

            if (datos[mid] == clave) return mid;
            if (datos[mid] < clave) izq = mid + 1;
            else der = mid - 1;
        }
        return -1;  // No encontrado
    }

private:
    std::vector<T>& datos;
};
#endif