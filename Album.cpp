#include <iostream>
#include <fstream>
#include "Librerias/Album.h"

using namespace std;

void Album::insertar_cabeceras() {
    multi_album.insertar(titulo);
    multi_album.insertar(nom_artis);
    multi_album.insertar(anio_publi);
    multi_album.insertar(cover);
    multi_album.insertar(fotografia);
    multi_album.insertar(estudio_grabaci);
    multi_album.insertar(editorial);
}

void Album ::insertar_album(Album album, MiVector<nodo_canciones>canciones_album, MiVector<Links> links_album){
    nodo_album album_nuevo;
    album_nuevo.id = album.id;
    album_nuevo.titulo = album.titulo_alb;
    album_nuevo.nom_artis = album.nombre_art;
    album_nuevo.cover = album.cover_art;
    album_nuevo.fotografia = album.fotogra;
    album_nuevo.editora = album.editora;
    album_nuevo.estudio_grab = album.estudio_grab;
    album_nuevo.anio_pub = album.anio_pub;
    for(int i=1; i<= canciones_album.size(); i++){
        album_nuevo.lista_caciones.push_back(canciones_album[i]);
    }
    for(int j=1; j<=links_album.size(); j++){
        album_nuevo.lista_links.push_back(links_album[j].insertar_link(links_album[j]));
    }
    
    multi_album.insertar(album_nuevo);
    cout << "Álbum insertado" << endl;
}

// Guardar lista de álbumes en archivo
void Album::guardarEnArchivo(const string& nombreArchivo, const MiVector<Album>& lista) {
    ofstream archivo(nombreArchivo);
    if (!archivo) {
        cerr << "Error al abrir el archivo para escritura." << endl;
        return;
    }

    for (size_t i = 1; i <= lista.size(); i++) {
        archivo << lista[i].getId() << ","
                << lista[i].getTitulo() << ","
                << lista[i].getNombreArt() << ","
                << lista[i].getPaisGrab() << ","
                << lista[i].getAnioPub() << ","
                << lista[i].getCoverArt() << ","
                << lista[i].getFotogra() << ","
                << lista[i].getEditora() << ","
                << lista[i].getEstudioGrab() << endl;
    }

    archivo.close();
}

// Leer lista de álbumes desde archivo
void Album::leerDesdeArchivo(const string& nombreArchivo, MiVector<Album>& lista) {
    ifstream archivo(nombreArchivo);
    if (!archivo) {
        cerr << "Error al abrir el archivo para lectura." << endl;
        return;
    }

    lista.clear();

    int id, anioPub;
    string tituloAlb, nombreArt, paisGrab, coverArt, fotogra, editora, estudioGrab;

    while (archivo >> id) {
        archivo.ignore();
        getline(archivo, tituloAlb, ',');
        getline(archivo, nombreArt, ',');
        getline(archivo, paisGrab, ',');
        archivo >> anioPub;
        archivo.ignore();
        getline(archivo, coverArt, ',');
        getline(archivo, fotogra, ',');
        getline(archivo, editora, ',');
        getline(archivo, estudioGrab);

        lista.push_back(Album(id, tituloAlb, nombreArt, paisGrab, anioPub, coverArt, fotogra, editora, estudioGrab));
    }

    archivo.close();
}
