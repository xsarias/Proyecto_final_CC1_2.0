#ifndef MULTILISTA_ALBUM_H
#define MULTILISTA_ALBUM_H
#include <iostream>
#include <string>
#include "estructuras.h"
using namespace std;

class Multilista_album{
    int num_dat, num_cab;
     // Contadores de datos y cabeceras
    MiVector<cabeza>lista_cabeceras; // Puntero a la lista de cabeceras
    MiVector<nodo_album>lista_datos;      // Puntero al primer nodo de datos

public:
    Multilista_album() { 
        num_dat=0;
        num_cab=0; 
    }

    void insertar(nodo_album Dato);
    void insertar(cabeza Cabeza);
    bool Multilista_vacia();
    string retornar_dato(int x,  std::string parametro);
    int retornar_pos(int x, std::string parametro);
    void ordenar_alfabeticamente(int pos, std::string dato, std::string atributo, std::string apuntador);
    void ordenar_anio(nodo_album nodo);
    void ordenar_genero(nodo_album nodo);
    void por_compositor(nodo_album nodo,  std::string comp);
    void por_interprete(nodo_album nodo, std::string interp);
    void ordenar_descendentemente_anio(nodo_album nodo, cabeza cab_gen);
    bool lista_llena();
};
#endif