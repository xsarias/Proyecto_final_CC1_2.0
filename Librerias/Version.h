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
    string tituloVer;  
    string tipVersion;  
    string artistaPrin;  
    string ciudadGrab;  
    string paisGra; 
    string genero;  
    int anio; 

public:
    // Constructores
    Version() : idVersion(0), idCancion(0), tituloVer(""), tipVersion(""), artistaPrin(""), anio(0), ciudadGrab(""), paisGra(""), genero("") {}

    Version(int id, int idCancion, const string& tituloVer, const string& tipVersion, const string&artistaPrin, int anio,
            const string& ciudadGrab = "", const string& paisGra = "",
            const string& genero = "")
        : idVersion(id), idCancion(idCancion), tituloVer(tituloVer), tipVersion(tipVersion), artistaPrin(artistaPrin), anio(anio),
          ciudadGrab(ciudadGrab), paisGra(paisGra), genero(genero) {}

    // Métodos
    void insertar_cabeceras(); 
    void imprimir_lista(string parametro, int pos_cab);
    nodo_versiones  insertar_version(Version version,  MiVector<Artista> artistas_version, MiVector<Links> links_version);

    // Getters
    int getIdVersion() const { return idVersion; }
    int getIdCancion() const { return idCancion; } 
    string getTituloVer() const { return tituloVer; }
    string getTipVersion() const { return tipVersion; }
    int getAnio() const { return anio; }
    string getCiudadGrab() const { return ciudadGrab; }
    string getPaisGra() const { return paisGra; }
    string getGenero() const { return genero; }
    string getArtistaPrincipal () const {return artistaPrin;}
    
    // Setters
    void setIdVersion(int nuevoIdVersion) { idVersion = nuevoIdVersion; }
    void setIdCancion(int nuevoIdCancion) { idCancion = nuevoIdCancion; }
    void setTituloVer(const string& nuevoTitulo) { tituloVer = nuevoTitulo; }
    void setTipVersion(const string& nuevoTipo) { tipVersion = nuevoTipo; }
    void setAnio(int nuevoAnio) { anio = nuevoAnio; }
    void setCiudadGrab(const string& nuevaCiudad) { ciudadGrab = nuevaCiudad; }
    void setPaisGra(const string& nuevoPais) { paisGra = nuevoPais; }
    void setGenero(const string& nuevoGenero) { genero = nuevoGenero; }
    void setArtistaPrincipal(const string& nuevoArtista) { artistaPrin = nuevoArtista; }

    // Métodos de archivos
    static void guardarEnArchivo(const string& nombreArchivo, const MiVector<Version>& lista);
    static void leerDesdeArchivo(const string& nombreArchivo, MiVector<Version>& lista);
    static void eliminarDeArchivo(const string& nombreArchivo, MiVector<Version>& lista);
    static void actualizarDesdeArchivo(const string& nombreArchivo, MiVector<Version>& lista);
    static Version buscarVersionConRelacionados(const string& nombreArchivoCancion,  
        const string& nombreArchivoLinks, 
        const string& nombreArchivoArtistas, 
        MiVector<Links>& listaLinks, 
        MiVector<Artista>& listaArtistas);
};

#endif
