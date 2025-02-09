#ifndef ARTISTA_H
#define ARTISTA_H

#include <string>
#include "estructuras.h"
#include "MiVector.h"

using namespace std;

class Artista {
private:
    int id;
    int id_cancion;
    int id_version;
    string nom_real; 
    string nom_artist; 
    string pais_origen;  
    string instrum_inter;  

public:
    // Constructor por defecto necesario para MiVector
    Artista() : id(0), id_cancion(0), id_version(0), nom_real(""), nom_artist(""), pais_origen(""), instrum_inter("") {}

    // Constructor con parámetros
    Artista(int id, int id_cancion, int id_version, const string& nomReal, const string& nomArtist, const string& paisOrigen, const string& instrumInter)
        : id_cancion(id_cancion), id_version(id_version), nom_real(nomReal), nom_artist(nomArtist), pais_origen(paisOrigen), instrum_inter(instrumInter) {}

    // Getters
    
    string getNomReal() const { return nom_real; }
    string getNomArtist() const { return nom_artist; }
    string getPaisOrigen() const { return pais_origen; }
    string getInstrumInter() const { return instrum_inter; }
    int getId() const { return id; }
    int getIdCancion() const { return id_cancion; }
    int getIdVersion() const { return id_version; }
    void mostrarInformacion();
    void imprimir_artista(Artista Artista);
    nodo_artistas insertar_artista(Artista artista);

    // Setters
    void setId(int nuevoId) { id = nuevoId; }
    void setIdCancion(int nuevoIdCancion) { id_cancion = nuevoIdCancion; }
    void setIdVersion(int nuevoIdVersion) { id_version = nuevoIdVersion; }
    void setNomReal(const string& nuevoNomReal) { nom_real = nuevoNomReal; }
    void setNomArtist(const string& nuevoNomArtist) { nom_artist = nuevoNomArtist; }
    void setPaisOrigen(const string& nuevoPaisOrigen) { pais_origen = nuevoPaisOrigen; }
    void setInstrumInter(const string& nuevoInstrumInter) { instrum_inter = nuevoInstrumInter; }


    // Métodos para guardar y leer desde archivo
    static void guardarEnArchivo(const string& nombreArchivo, const MiVector<Artista>& lista);
    static void leerDesdeArchivo(const string& nombreArchivo, MiVector<Artista>& lista);
    static void eliminarDeArchivo(const string& nombreArchivo, MiVector<Artista>& lista);
    static void actualizarDesdeArchivo(const string& nombreArchivo, MiVector<Artista>& lista);

};


#endif
