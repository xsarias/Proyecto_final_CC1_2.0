#ifndef VERSION_H
#define VERSION_H

#include <string>
#include "MiVector.h"
#include "multilista_version.h"
#include "Links.h"
#include "estructuras.h"
#include "Artista.h"
using namespace std;
Multilista_version multi_version;

cabeza titulo_ver = {"tituloVer", 0};
cabeza tipoVers = {"tipoVer", 0};
cabeza anioPub = {"anio_pub", 0};
cabeza paisGrab = {"pais_grab", 0};
cabeza artistaPrinc = {"artista_princ", 0};
cabeza ciudad_Grab = {"Ciudad grabación", 0};
cabeza genero_ver = {"Género canción ", 0};

class Version {
private:
    int idVersion;
    int idCancion;  // ID foráneo de la canción
    int idAlbum;    // ID foráneo del álbum
    string tituloVer;  
    string tipVersion;  
    string artistasPrin;  
    string ciudadGrab;  
    string paisGra;  
    string arrMusic;  
    string genero;  
    int anio; 
    MiVector<nodo_links> listLinksVers;  

public:
    // Constructores
    Version() : idVersion(0), idCancion(0), idAlbum(0), tituloVer(""), tipVersion(""), anio(0), ciudadGrab(""), paisGra(""), genero(""), arrMusic("") {}

    Version(int id, int idCancion, int idAlbum, const string& tituloVer, const string& tipVersion, int anio,
            const string& ciudadGrab = "", const string& paisGra = "",
            const string& genero = "", const string& arrMusic = "")
        : idVersion(id), idCancion(idCancion), idAlbum(idAlbum), tituloVer(tituloVer), tipVersion(tipVersion), anio(anio),
          ciudadGrab(ciudadGrab), paisGra(paisGra), genero(genero), arrMusic(arrMusic) {}

    // Métodos
    void insertar_cabeceras(); 
    void imprimir_lista(string parametro, int pos_cab);
    nodo_versiones  insertar_version(Version version,  MiVector<Artista> artistas_version, MiVector<Links> links_version);

    // Getters
    int getIdVersion() const { return idVersion; }
    int getIdCancion() const { return idCancion; } // Nuevo getter
    int getIdAlbum() const { return idAlbum; }     // Nuevo getter
    string getTituloVer() const { return tituloVer; }
    string getTipVersion() const { return tipVersion; }
    int getAnio() const { return anio; }
    string getCiudadGrab() const { return ciudadGrab; }
    string getPaisGra() const { return paisGra; }
    string getGenero() const { return genero; }
    string getArrMusic() const { return arrMusic; }

    // Métodos de archivos
    static void guardarEnArchivo(const string& nombreArchivo, const MiVector<Version>& lista);
    static void leerDesdeArchivo(const string& nombreArchivo, MiVector<Version>& lista);
    static void eliminarDeArchivo(const string& nombreArchivo, MiVector<Version>& lista);

};

#endif
