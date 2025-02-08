#ifndef ALBUM_H
#define ALBUM_H

#include "MiVector.h"
#include "multilista_album.h"
#include "estructuras.h"
#include "Artista.h"
#include "Links.h"
#include <fstream>

Multilista_album multi_album;

class Album {
private:
    int id;
    string titulo_alb;
    string nombre_art;
    string pais_grab;
    int anio_pub;
    string cover_art;
    string fotogra;
    string editora;
    string estudio_grab;
    MiVector<nodo_links> lista_links;
    MiVector<nodo_canciones> lista_canciones;

    cabeza titulo = {"titulo", 0};
    cabeza nom_artis = {"nombre_artis", 0};
    cabeza anio_publi = {"anio_pub", 0};
    cabeza cover = {"cover", 0};
    cabeza fotografia = {"fotografia", 0};
    cabeza estudio_grabaci = {"estudio_grab", 0};
    cabeza editorial = {"editora", 0};

public:
    // Constructores
    Album() : id(0), titulo_alb(""), nombre_art(""), pais_grab(""), anio_pub(0),
              cover_art(""), fotogra(""), editora(""), estudio_grab("") {}

    Album(int id, const string& tituloAlb, const string& nombreArt, const string& paisGrab, int anioPub,
          const string& coverArt = "", const string& fotogra = "", const string& editora = "",
          const string& estudioGrab = "")
        : id(id), titulo_alb(tituloAlb), nombre_art(nombreArt), pais_grab(paisGrab), anio_pub(anioPub),
          cover_art(coverArt), fotogra(fotogra), editora(editora), estudio_grab(estudioGrab) {}
<<<<<<< HEAD
        void insertar_cabeceras(); 
        void imprimir_lista(string parametro, int pos_cab);
        void insertar_album(Album cancion, MiVector<nodo_canciones>canciones_album, MiVector<Links> links_album);
=======

    // Métodos
    void insertar_cabeceras();
    void imprimir_lista(string parametro, int pos_cab);
    void insertar_album(Album album);

    // Métodos de archivos
    static void guardarEnArchivo(const string& nombreArchivo, const MiVector<Album>& lista);
    static void leerDesdeArchivo(const string& nombreArchivo, MiVector<Album>& lista);

    // Getters
    int getId() const { return id; }
    string getTitulo() const { return titulo_alb; }
    string getNombreArt() const { return nombre_art; }
    string getPaisGrab() const { return pais_grab; }
    int getAnioPub() const { return anio_pub; }
    string getCoverArt() const { return cover_art; }
    string getFotogra() const { return fotogra; }
    string getEditora() const { return editora; }
    string getEstudioGrab() const { return estudio_grab; }
>>>>>>> 7dd8cbdc2217029d7c0c01d9ec6273f631cdd902
};

#endif
