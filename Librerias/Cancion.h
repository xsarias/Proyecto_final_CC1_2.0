#ifndef CANCION_H
#define CANCION_H

#include "MiVector.h"
#include "multilista_cancion.h"
#include "estructuras.h"
#include "Artista.h"
#include "Version.h"
#include "Links.h"

Multilista_cancion multi_cancion;

class Cancion {
private:
    int id;
    string nombreCancion;
    string nom_artistico;  
    string duracion;  
    MiVector<Artista> listArtistas;
    int numArtistasPrincipales;  
    string composLetra;  
    string composMusica;  
    string arrMusic;  
    string ciudadGrabacion; 
    string paisGrabacion; 
    int anioPublicacion; 
    string genero;  
    MiVector<nodo_links> listPlataf;  
    MiVector<Version> listVersiones;

    cabeza nombre_artis = {"nombre artistico", 0};
    cabeza nom_cancion = {"nombre canción", 0};
    cabeza comp_let = {"compositor letra", 0};
    cabeza comp_music = {"compositor musica", 0};
    cabeza pais = {"Pais grabacion", 0};
    cabeza ciudad = {"Ciudad grabación", 0};
    cabeza genero_ = {"Género canción ", 0};
    cabeza anio_pub = {"Año publicación", 0};

public:
    // Constructor por defecto necesario para MiVector
    Cancion() : id(0), nombreCancion(""), nom_artistico(""), genero(""), anioPublicacion(0), duracion("") {}
    
    // Constructor con parámetros
    Cancion(int id, const string& nombreCancion, const string& nomArtistico, const string& genero, int anioPublicacion, const string& duracion)
    : id(id), nombreCancion(nombreCancion), nom_artistico(nomArtistico), genero(genero), anioPublicacion(anioPublicacion), duracion(duracion) {}

    void insertar_cabeceras(); 
    void imprimir_lista(string parametro, int pos_cab);
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

    // Métodos para guardar y leer desde archivo
    static void guardarEnArchivo(const string& nombreArchivo, const MiVector<Cancion>& lista);
    static void leerDesdeArchivo(const string& nombreArchivo, MiVector<Cancion>& lista);
    
    
};

#endif 
