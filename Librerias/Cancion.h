#ifndef CANCION_H
#define CANCION_H

#include "MiVector.h"
#include "multilista_cancion.h"
#include "estructuras.h"
#include "Artista.h"
#include "Version.h"
#include "Links.h"

Multilista_cancion multi_cancion;
cabeza nombre_artis = {"nombre artistico", 0};
cabeza nom_cancion = {"nombre canción", 0};
cabeza comp_let = {"compositor letra", 0};
cabeza comp_music = {"compositor musica", 0};
cabeza pais = {"Pais grabacion", 0};
cabeza ciudad = {"Ciudad grabación", 0};
cabeza genero_ = {"Género canción ", 0};
cabeza anio_pub = {"Año publicación", 0};
cabeza duracion_can = {"Duracion", 0 };
class Cancion {
private:
    int id;
    int id_album;
    string nombreCancion;
    string nom_artistico;  
    string duracion;  
    int numArtistasPrincipales;  
    string composLetra;  
    string composMusica;  
    string arrMusic;  
    string ciudadGrabacion; 
    string paisGrabacion; 
    int anioPublicacion; 
    string genero;  

public:
    Cancion() : id(0), id_album(0), nombreCancion(""), nom_artistico(""), genero(""), 
    anioPublicacion(0), duracion(""), composLetra(""), composMusica(""), 
    arrMusic(""), ciudadGrabacion(""), paisGrabacion(""), numArtistasPrincipales(0) {}

    // Constructor con parámetros
    Cancion(int id, int id_album, const string& nombreCancion, const string& nomArtistico, const string& genero, 
    int anioPublicacion, const string& duracion, const string& composLetra, const string& composMusica, 
    const string& arrMusic, const string& ciudadGrabacion, const string& paisGrabacion, 
    int numArtistasPrincipales)
    : id(id), id_album(id_album), nombreCancion(nombreCancion), nom_artistico(nomArtistico), 
    genero(genero), anioPublicacion(anioPublicacion), duracion(duracion), 
    composLetra(composLetra), composMusica(composMusica), arrMusic(arrMusic), 
    ciudadGrabacion(ciudadGrabacion), paisGrabacion(paisGrabacion), numArtistasPrincipales(numArtistasPrincipales) {}



    void insertar_cabeceras(); 
    void imprimir_lista(string parametro, int pos_cab);
    nodo_canciones insertar_cancion(Cancion cancion, MiVector<Links> links, MiVector<Artista> artista, MiVector<nodo_versiones> version);
    nodo_canciones insertar_cancion(Cancion cancion, MiVector<Links> links, MiVector<Artista> artista);
    void insertar_artista(Artista artista);

    // Getters
    int getId() const { return id; }
    string getNombreCancion() const { return nombreCancion; }
    string getNomArtistico() const { return nom_artistico; }
    string getGenero() const { return genero; }
    int getAnioPublicacion() const { return anioPublicacion; }
    string getDuracion() const { return duracion; }
    string getComposLetra() const { return composLetra; }
    string getComposMusica() const { return composMusica; }
    string getArrMusic() const { return arrMusic; }
    string getCiudadGrabacion() const { return ciudadGrabacion; }
    string getPaisGrabacion() const { return paisGrabacion; }
    int getIdAlbum() const { return id_album; }
    int getNumArtistasPrincipales() const { return numArtistasPrincipales; }
    

    // Setters
    void setNombre(const string& nuevoNombre) { nombreCancion = nuevoNombre; }
    void setNomArtistico(const string& nuevoNomArtistico) { nom_artistico = nuevoNomArtistico; }
    void setGenero(const string& nuevoGenero) { genero = nuevoGenero; }
    void setAnioPublicacion(int nuevoAnio) { anioPublicacion = nuevoAnio; }
    void setDuracion(const string& nuevaDuracion) { duracion = nuevaDuracion; }
    void setComposLetra(const string& nuevaComposLetra) { composLetra = nuevaComposLetra; }
    void setComposMusica(const string& nuevaComposMusica) { composMusica = nuevaComposMusica; }
    void setArrMusic(const string& nuevoArrMusic) { arrMusic = nuevoArrMusic; }
    void setCiudadGrabacion(const string& nuevaCiudad) { ciudadGrabacion = nuevaCiudad; }
    void setPaisGrabacion(const string& nuevoPais) { paisGrabacion = nuevoPais; }
    void setIdAlbum(int nuevoIdAlbum) { id_album = nuevoIdAlbum; }
    void setNumArtistasPrincipales(int nuevoNum) { numArtistasPrincipales = nuevoNum; }

    // Métodos para guardar y leer desde archivo
    static void guardarEnArchivo(const string& nombreArchivo, const MiVector<Cancion>& lista);
    static void leerDesdeArchivo(const string& nombreArchivo, MiVector<Cancion>& lista);
    static void eliminarDeArchivo(const string& nombreArchivo, MiVector<Cancion>& lista);
    static void actualizarDesdeArchivo(const string& nombreArchivo, MiVector<Cancion>& lista);

    
};

#endif 