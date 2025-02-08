#ifndef CANCION_H
#define CANCION_H
#include "MiVector.h"
#include "multilista_cancion.h"
#include "estructuras.h"
#include "Artista.h"
#include "Version.h"
Multilista_cancion multi_cancion;
class Cancion {
private:
    
    string nombreCancion;
    string nom_artistico;  
    string duracion;  
    MiVector<Artista>listArtistas;
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
    Cancion(const string& nombreCancion, const string& nomArtistico, const string& genero, int anioPublicacion, const string& duracion,
        const string& composLetra = "", const string& composMusica = "", const string& arrMusic = "",
        const string& ciudadGrabacion = "", const string& paisGrabacion = "", int numArtistasPrincipales = 0)
    : nombreCancion(nombreCancion), nom_artistico(nomArtistico), genero(genero), anioPublicacion(anioPublicacion), duracion(duracion),
    composLetra(composLetra), composMusica(composMusica), arrMusic(arrMusic),
    ciudadGrabacion(ciudadGrabacion), paisGrabacion(paisGrabacion), numArtistasPrincipales(numArtistasPrincipales) {}
    void insertar_cabeceras(); 
    void imprimir_lista(string parametro, int pos_cab);
    void insertar_cancion(Cancion cancion);
};

#endif
