#ifndef ALBUM_H
#define ALBUM_H

#include "MiVector.h"
#include "multilista_album.h"
#include "estructuras.h"
#include "Artista.h"
#include "Links.h"
#include <fstream>
#include "Cancion.h"

Multilista_album multi_album;

    cabeza titulo = {"titulo", 0};
    cabeza nom_artis = {"nombre_artis", 0};
    cabeza anio_publi = {"anio_pub", 0};
    cabeza cover = {"cover", 0};
    cabeza fotografia = {"fotografia", 0};
    cabeza estudio_grabaci = {"estudio_grab", 0};
    cabeza editorial = {"editora", 0};
    cabeza pais = {"Pais",0};

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

public:
    // Constructores
    Album() : id(0), titulo_alb(""), nombre_art(""), pais_grab(""), anio_pub(0),
              cover_art(""), fotogra(""), editora(""), estudio_grab("") {}

    Album(int id, const string& tituloAlb, const string& nombreArt, const string& paisGrab, int anioPub,
          const string& coverArt = "", const string& fotogra = "", const string& editora = "",
          const string& estudioGrab = "")
        : id(id), titulo_alb(tituloAlb), nombre_art(nombreArt), pais_grab(paisGrab), anio_pub(anioPub),
          cover_art(coverArt), fotogra(fotogra), editora(editora), estudio_grab(estudioGrab) {}
      
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

    // Setters
    void setId(int nuevoId) { id = nuevoId; }
    void setTitulo(const string& nuevoTitulo) { titulo_alb = nuevoTitulo; }
    void setNombreArt(const string& nuevoNombreArt) { nombre_art = nuevoNombreArt; }
    void setPaisGrab(const string& nuevoPaisGrab) { pais_grab = nuevoPaisGrab; }
    void setAnioPub(int nuevoAnioPub) { anio_pub = nuevoAnioPub; }
    void setCoverArt(const string& nuevoCoverArt) { cover_art = nuevoCoverArt; }
    void setFotogra(const string& nuevaFotogra) { fotogra = nuevaFotogra; }
    void setEditora(const string& nuevaEditora) { editora = nuevaEditora; }
    void setEstudioGrab(const string& nuevoEstudioGrab) { estudio_grab = nuevoEstudioGrab; }

    // Métodos
    void insertar_cabeceras();
    void imprimir_lista(string parametro, int pos_cab);
    void insertar_album(Album cancion, MiVector<nodo_canciones>canciones_album, MiVector<Links> links_album);
    bool consultar_por_atributoAlbum(string atributo, int cabecera);

    // Métodos de archivos
    static void guardarEnArchivo(const string& nombreArchivo);
    static void leerDesdeArchivo(const string& nombreArchivo);
    static void eliminarDeArchivo(const string& nombreArchivo);
    static void actualizarDesdeArchivo(const string& nombreArchivo);
    static Album buscarAlbumConRelacionados(const string& nombreArchivoAlbum,  
      const string& nombreArchivoLinks, 
      const string& nombreArchivoCanciones,
      MiVector<Links> &listaLinks,
      MiVector<Cancion> &listaCanciones);

   
};

#endif
