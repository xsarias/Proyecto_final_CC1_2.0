#ifndef ALBUM_H
#define ALBUM_H
#include "MiVector.h"
#include "multilista_album.h"
#include "estructuras.h"
#include "Artista.h"
#include "Links.h"

Multilista_album multi_album;
class Album{
private:
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
    
    // Constructor
    Album(const string& tituloAlb, const string& nombreArt, const string& paisGrab, int anioPub,
          const string& coverArt = "", const string& fotogra = "", const string& editora = "",
          const string& estudioGrab = "")
        : titulo_alb(tituloAlb), nombre_art(nombreArt), pais_grab(paisGrab), anio_pub(anioPub),
          cover_art(coverArt), fotogra(fotogra), editora(editora), estudio_grab(estudioGrab) {}
        void insertar_cabeceras(); 
        void imprimir_lista(string parametro, int pos_cab);
        void insertar_album(Album cancion, MiVector<nodo_canciones>canciones_album, MiVector<Links> links_album);
};


#endif