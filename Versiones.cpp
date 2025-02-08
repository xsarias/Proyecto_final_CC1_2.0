#include "Librerias/Version.h"
#include <iostream>
#include <fstream>

using namespace std;

void Version::insertar_cabeceras() {
    multi_version.insertar(titulo_ver);
    multi_version.insertar(tipoVers);
    multi_version.insertar(anioPub);
    multi_version.insertar(paisGrab);
    multi_version.insertar(artistaPrinc);
    multi_version.insertar(ciudad_Grab);
    multi_version.insertar(genero_ver);
}

void Version::insertar_version(Version version) {
    nodo_versiones version_nueva;
    version_nueva.id = version.getIdVersion();
    version_nueva.titulos = version.getTituloVer();
    version_nueva.tipo_version = version.getTipVersion();
    version_nueva.anio_pub = version.getAnio();
    version_nueva.pais_grab = version.getPaisGra();
    version_nueva.artista_princ = version.getArrMusic();
    version_nueva.ciudad_grab = version.getCiudadGrab();
    version_nueva.genero = version.getGenero();
}

// Guardar lista de versiones en archivo
void Version::guardarEnArchivo(const string& nombreArchivo, const MiVector<Version>& lista) {
    ofstream archivo(nombreArchivo);
    if (!archivo) {
        cerr << "Error al abrir el archivo para escritura." << endl;
        return;
    }

    for (size_t i = 1; i <= lista.size(); i++) {
        archivo << lista[i].getIdVersion() << ","
                << lista[i].getTituloVer() << ","
                << lista[i].getTipVersion() << ","
                << lista[i].getAnio() << ","
                << lista[i].getCiudadGrab() << ","
                << lista[i].getPaisGra() << ","
                << lista[i].getGenero() << ","
                << lista[i].getArrMusic() << endl;
    }

    archivo.close();
}

// Leer lista de versiones desde archivo
void Version::leerDesdeArchivo(const string& nombreArchivo, MiVector<Version>& lista) {
    ifstream archivo(nombreArchivo);
    if (!archivo) {
        cerr << "Error al abrir el archivo para lectura." << endl;
        return;
    }

    lista.clear();

    int id, anio;
    string tituloVer, tipVersion, ciudadGrab, paisGra, genero, arrMusic;

    while (archivo >> id) {
        archivo.ignore();
        getline(archivo, tituloVer, ',');
        getline(archivo, tipVersion, ',');
        archivo >> anio;
        archivo.ignore();
        getline(archivo, ciudadGrab, ',');
        getline(archivo, paisGra, ',');
        getline(archivo, genero, ',');
        getline(archivo, arrMusic);

        lista.push_back(Version(id, tituloVer, tipVersion, anio, ciudadGrab, paisGra, genero, arrMusic));
    }

    archivo.close();
}
