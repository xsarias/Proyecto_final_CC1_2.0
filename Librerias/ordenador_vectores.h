#ifndef ORDENADOR_ALBUM_H
#define ORDENADOR_ALBUM_H

#include "MiVector.h"

// Función para particionar el vector
template <typename T, typename K>
int particionar(MiVector<T>& vec, int inicio, int fin, K T::*clave) {
    T pivote = vec[fin];  // Elegimos el pivote en la última posición
    int i = inicio;        // Índice desde el primer elemento válido

    for (int j = inicio; j < fin; j++) {
        if (vec[j].*clave < pivote.*clave) {  // Comparación usando la clave
            std::swap(vec[i], vec[j]);
            i++;  // Mover el índice de elementos menores
        }
    }

    std::swap(vec[i], vec[fin]);  // Colocar el pivote en su posición correcta
    return i;
}

// Implementación de QuickSort adaptado a MiVector
template <typename T, typename K>
void quicksort(MiVector<T>& vec, int inicio, int fin, K T::*clave) {
    if (inicio < fin) {
        int indicePivote = particionar(vec, inicio, fin, clave);
        quicksort(vec, inicio, indicePivote - 1, clave);
        quicksort(vec, indicePivote + 1, fin, clave);
    }
}

// Función que retorna un nuevo vector ordenado
template <typename T, typename K>
MiVector<T> ordenarVector(const MiVector<T>& vec, K T::*clave) {
    MiVector<T> copia = vec;  // Hacer una copia del vector original
    if (copia.size() > 0) {
        quicksort(copia, 1, copia.size(), clave);  // Se ajusta para índices desde 1
    }
    return copia;  // Retornar el vector ordenado
}


#endif
