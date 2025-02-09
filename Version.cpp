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

nodo_versiones Version::insertar_version(Version version, MiVector<Artista> artistas_version, MiVector<Links> links_version) {
    nodo_versiones version_nueva;
    version_nueva.id = version.idVersion;
    version_nueva.titulos = version.tituloVer;
    version_nueva.tipo_version = version.tipVersion;
    version_nueva.anio_pub = version.anio;
    version_nueva.pais_grab = version.paisGra;
    version_nueva.artista_princ = version.artistasPrin;
    version_nueva.ciudad_grab = version.ciudadGrab;
    version_nueva.genero = version.genero;
    for(int i=1; i<= artistas_version.size(); i++){
        version_nueva.lista_artistas.push_back(artistas_version[i].insertar_artista(artistas_version[i]));
    }
    for(int i=1; i<= links_version.size(); i++){
        version_nueva.lista_links.push_back(links_version[i].insertar_link(links_version[i]));
    }
    multi_version.insertar(version_nueva);
    return version_nueva;
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
                << lista[i].getIdCancion() << "," // Nuevo campo
                << lista[i].getIdAlbum() << ","   // Nuevo campo
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

    int id, idCancion, idAlbum, anio;
    string tituloVer, tipVersion, ciudadGrab, paisGra, genero, arrMusic;

    while (archivo >> id) {
        archivo.ignore();
        archivo >> idCancion; archivo.ignore(); // Leer idCancion
        archivo >> idAlbum; archivo.ignore();   // Leer idAlbum
        getline(archivo, tituloVer, ',');
        getline(archivo, tipVersion, ',');
        archivo >> anio;
        archivo.ignore();
        getline(archivo, ciudadGrab, ',');
        getline(archivo, paisGra, ',');
        getline(archivo, genero, ',');
        getline(archivo, arrMusic);

        lista.push_back(Version(id, idCancion, idAlbum, tituloVer, tipVersion, anio, ciudadGrab, paisGra, genero, arrMusic));
    }

    archivo.close();
}
