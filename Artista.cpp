#include <iostream>
#include <fstream>
#include "Librerias/Artista.h"
nodo_artistas Artista :: insertar_artista(Artista artista) {

void Artista::imprimir_links(Artista artista){
    cout << artista.nom_real << endl;
    cout << artista.nom_artist << endl;
    cout << artista.pais_origen << endl;
    cout << artista.instrum_inter << endl;
}
nodo_artistas Artista :: insertar_artista(Artista artista){
    nodo_artistas artista_nuevo;
    artista_nuevo.id = artista.id;
    artista_nuevo.nom_artistico = artista.nom_artist;
    artista_nuevo.nom_real = artista.nom_real;
    artista_nuevo.pais_origen = artista.pais_origen;
    artista_nuevo.instru_interpre = artista.instrum_inter;
    cout << "Artista insertado" << endl;
    return artista_nuevo;
}

// Método para guardar la lista de Artistas en un archivo
void Artista::guardarEnArchivo(const string& nombreArchivo, const MiVector<Artista>& lista) {
    ofstream archivo(nombreArchivo);
    if (!archivo) {
        cerr << "Error al abrir el archivo para escritura." << endl;
        return;
    }

    for (size_t i = 1; i <= lista.size(); i++) {
        archivo << lista[i].getId() << ","
                << lista[i].getNomReal() << ","
                << lista[i].getNomArtist() << ","
                << lista[i].getPaisOrigen() << ","
                << lista[i].getInstrumInter() << endl;
    }

    archivo.close();
}

// Método para leer la lista de Artistas desde un archivo
void Artista::leerDesdeArchivo(const string& nombreArchivo, MiVector<Artista>& lista) {
    ifstream archivo(nombreArchivo);
    if (!archivo) {
        cerr << "Error al abrir el archivo para lectura." << endl;
        return;
    }

    lista.clear();

    int id;
    string nomReal, nomArtist, paisOrigen, instrumInter;
    while (archivo >> id) {
        archivo.ignore();
        getline(archivo, nomReal, ',');
        getline(archivo, nomArtist, ',');
        getline(archivo, paisOrigen, ',');
        getline(archivo, instrumInter);
        lista.push_back(Artista(id, nomReal, nomArtist, paisOrigen, instrumInter));
    }

    archivo.close();
}
