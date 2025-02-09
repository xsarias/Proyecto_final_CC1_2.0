#include <iostream>
#include <fstream>
#include "Librerias/Links.h"
#include "Librerias/MiVector.h"

nodo_links Links::insertar_link(Links links) {
    nodo_links nuevo_link;
    nuevo_link.link_album = links.getLinkAlbum();
    nuevo_link.link_cancion = links.getLinkCancion();
    nuevo_link.nom_plat = links.getNomPlat();

    return nuevo_link;
}

// Método para guardar la lista de Links en un archivo
void Links::guardarEnArchivo(const string& nombreArchivo, const MiVector<Links>& lista) {
    ofstream archivo(nombreArchivo);
    if (!archivo) {
        cerr << "Error al abrir el archivo para escritura." << endl;
        return;
    }

    for (size_t i = 1; i <= lista.size(); i++) {  // Desde 1 por la estructura de MiVector
        archivo << lista[i].getId() << ","
                << lista[i].getIdAlbum() << ","
                << lista[i].getIdVersion() << ","
                << lista[i].getNomPlat() << ","
                << lista[i].getLinkAlbum() << ","
                << lista[i].getLinkCancion() << endl;
    }

    archivo.close();
}

// Método para leer la lista de Links desde un archivo
void Links::leerDesdeArchivo(const string& nombreArchivo, MiVector<Links>& lista) {
    ifstream archivo(nombreArchivo);
    if (!archivo) {
        cerr << "Error al abrir el archivo para lectura." << endl;
        return;
    }

    lista.clear();  // Limpiar la lista antes de cargar datos nuevos

    int id, idAlbum, idVersion;
    string nomPlat, linkAlbum, linkCancion;
    while (archivo >> id) { // Leer ID
        archivo.ignore();   // Ignorar la coma
        archivo >> idAlbum;
        archivo.ignore();
        archivo >> idVersion;
        archivo.ignore();
        getline(archivo, nomPlat, ',');
        getline(archivo, linkAlbum, ',');
        getline(archivo, linkCancion);
        lista.push_back(Links(id, idAlbum, idVersion, nomPlat, linkAlbum, linkCancion));
    }

    archivo.close();
}
