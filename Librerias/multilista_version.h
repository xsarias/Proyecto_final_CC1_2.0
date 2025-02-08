#ifndef MULTILISTA_VERSION_H
#define MULTILISTA_VERSION_H
#include "estructuras.h"
#include "MiVector.h"
#include <iostream>
#include <string>
using namespace std;

class Multilista_version{
    int num_dat; // Contador de datos
    int num_cab; // Contador de cabeceras
    MiVector<cabeza> lista_cabeceras; // Lista de cabeceras
    MiVector<nodo_versiones> lista_versiones; // Lista de datos

public:
    Multilista_version() : num_dat(0), num_cab(0) {}

    void insertar(nodo_versiones Dato);
    void insertar(cabeza Cabeza);
    bool Multilista_vacia();
    string retornar_dato(int x, string parametro);
    int retornar_pos(int x, string parametro);
    void por_titulo(int pos, string dato);
    void por_tipo_version(int pos, string dato);
    void por_anio(int pos, string dato);
    void por_pais_grab(int pos, string dato);
    void por_artista_princ(int pos, string dato);
    void por_ciudad(int pos, string dato);
    void por_genero(int pos, string dato);
    


};

// Implementaciones
void Multilista_version:: insertar(cabeza Cabeza) {
    lista_cabeceras.push_back(Cabeza);
    num_cab++;
}

void Multilista_version:: insertar(nodo_versiones Dato) {
    lista_versiones.push_back(Dato);
    num_dat = lista_versiones.size();
}

bool Multilista_version:: Multilista_vacia(){
    return num_dat == 0;
}
string Multilista_version::retornar_dato(int x, string parametro){

}
int Multilista_version::retornar_pos(int x, string parametro){

}
void Multilista_version::por_titulo(int pos, string dato){

}
void Multilista_version::por_tipo_version(int pos, string dato){

}
void Multilista_version::por_anio(int pos, string dato){

}
void Multilista_version::por_pais_grab(int pos, string dato){

}
void Multilista_version::por_artista_princ(int pos, string dato){

}
void Multilista_version::por_ciudad(int pos, string dato){

}
void Multilista_version::por_genero(int pos, string dato){
    
}

#endif