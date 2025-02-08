#ifndef VERSION_H
#define VERSION_H
#include <string>
#include "MiVector.h"
#include "multilista_version.h"
#include "Links.h"
#include "estructuras.h"
using namespace std;
Multilista_version multi_version;
class Version {
private:
    string tituloVer;  
    string tipVersion;  
    string artistasPrin;  
    string ciudadGrab;  
    string paisGra;  
    string arrMusic;  
    string genero;  
    int anio; 
    MiVector<nodo_links> listLinksVers;  
    cabeza titulo_ver = {"tituloVer", 0};
    cabeza  tipoVers = {"tipoVer", 0};
    cabeza anioPub = {"anio_pub", 0};
    cabeza paisGrab = {"pais_grab", 0};
    cabeza artistaPrinc = {"artista_princ", 0};
    cabeza ciudad_Grab = {"Ciudad grabación", 0};
    cabeza genero_ver = {"Género canción ", 0};
    


public:
    // Constructor
    Version() :  tituloVer(""), tipVersion(""), anio(0), ciudadGrab(""), paisGra(""), genero(""), arrMusic("") {};

    Version(const string& tituloVer, const string& tipVersion, int anio,
            const string& ciudadGrab = "", const string& paisGra = "",
            const string& genero = "", const string& arrMusic = "")
        : tituloVer(tituloVer), tipVersion(tipVersion), anio(anio),
          ciudadGrab(ciudadGrab), paisGra(paisGra), genero(genero), arrMusic(arrMusic) {}
    void insertar_cabeceras(); 
    void imprimir_lista(string parametro, int pos_cab);
    void insertar_cancion(Version version);

};
#endif