#ifndef MI_VECTOR_H
#define MI_VECTOR_H

#include <iostream>
#include <stdexcept> // Para std::out_of_range

template <typename T>
class MiVector {
private:
    T* datos;
    size_t capacidad;
    size_t tam;

    void expandir();

public:
    MiVector();
    ~MiVector();
    MiVector(const MiVector& otro);
    MiVector& operator=(const MiVector& otro);

    void push_back(T valor);
    void pop_back();
    void erase(size_t i);
    T& operator[](size_t i);
    const T& operator[](size_t i) const;
    size_t size() const;
    void clear();
};

// Implementaciones

template <typename T>
MiVector<T>::MiVector() : capacidad(1), tam(1) {
    datos = new T[capacidad]; // Reservar memoria
}

template <typename T>
MiVector<T>::~MiVector() {
    delete[] datos;
}

template <typename T>
MiVector<T>::MiVector(const MiVector& otro) : datos(nullptr), capacidad(0), tam(1) {
    *this = otro;
}

// Nuevo método erase para eliminar un elemento en la posición `i`
template <typename T>
void MiVector<T>::erase(size_t i) {
    if (i == 0 || i >= tam) { // Validar índice (sin incluir el 0)
        throw std::out_of_range("Índice fuera de rango");
    }

    for (size_t j = i; j < tam - 1; j++) {
        datos[j] = datos[j + 1]; // Desplazar elementos a la izquierda
    }
    
    tam--; // Reducir tamaño
}

template <typename T>
MiVector<T>& MiVector<T>::operator=(const MiVector& otro) {
    if (this != &otro) {
        delete[] datos;
        tam = otro.tam;
        capacidad = otro.capacidad;
        datos = new T[capacidad];
        for (size_t i = 1; i < tam; i++) { // Desde 1
            datos[i] = otro.datos[i];
        }
    }
    return *this;
}

template <typename T>
void MiVector<T>::expandir() {
    size_t nueva_capacidad = (capacidad == 0) ? 2 : capacidad * 2;
    T* nuevo_datos = new T[nueva_capacidad];

    for (size_t i = 1; i < tam; i++) { // Copiar desde 1
        nuevo_datos[i] = datos[i];
    }

    delete[] datos;
    datos = nuevo_datos;
    capacidad = nueva_capacidad;
}

template <typename T>
void MiVector<T>::push_back(T valor) {
    if (tam >= capacidad) {
        expandir();
    }
    datos[tam] = valor; // Insertar en `tam`
    tam++; // Incrementar tamaño
}

template <typename T>
void MiVector<T>::pop_back() {
    if (tam > 1) { // No reducir por debajo de 1
        tam--;
    }
}

template <typename T>
T& MiVector<T>::operator[](size_t i) {
    if (i == 0 || i >= tam) { // Evitar acceso a índice 0
        throw std::out_of_range("Índice fuera de rango");
    }
    return datos[i];
}

template <typename T>
const T& MiVector<T>::operator[](size_t i) const {
    if (i == 0 || i >= tam) {
        throw std::out_of_range("Índice fuera de rango");
    }
    return datos[i];
}

template <typename T>
size_t MiVector<T>::size() const {
    return tam - 1; 
}

template <typename T>
void MiVector<T>::clear() {
    delete[] datos;
    datos = new T[1]; // Resetear memoria
    capacidad = 1;
    tam = 1;
}

#endif
