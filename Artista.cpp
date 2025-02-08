#include <iostream>
#include "Librerias/Artista.h"

nodo_artistas Artista :: insertar_artista(Artista artista){
    nodo_artistas artista_nuevo;
    artista_nuevo.nom_artistico = artista.nom_artist;
    artista_nuevo.nom_real = artista.nom_real;
    artista_nuevo.pais_origen = artista.pais_origen;
    artista_nuevo.instru_interpre = artista.instrum_inter;
    cout<<"artista insertado"<<endl;
    return artista_nuevo;
}