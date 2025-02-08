#ifndef ARTISTA_H
#define ARTISTA_H

#include <string>
#include "estructuras.h"
#include "MiVector.h"

using namespace std;

class Artista {
private:
    int id;
    string nom_real; 
    string nom_artist; 
    string pais_origen;  
    string instrum_inter;  

public:
    // Constructor por defecto necesario para MiVector
    Artista() : id(0), nom_real(""), nom_artist(""), pais_origen(""), instrum_inter("") {}

    // Constructor con parámetros
    Artista(int id, const string& nomReal, const string& nomArtist, const string& paisOrigen, const string& instrumInter)
        : id(id), nom_real(nomReal), nom_artist(nomArtist), pais_origen(paisOrigen), instrum_inter(instrumInter) {}

    // Getters
    int getId() const { return id; }
    string getNomReal() const { return nom_real; }
    string getNomArtist() const { return nom_artist; }
    string getPaisOrigen() const { return pais_origen; }
    string getInstrumInter() const { return instrum_inter; }

    void mostrarInformacion();
    nodo_artistas insertar_artista(Artista artista);

    // Métodos para guardar y leer desde archivo
    static void guardarEnArchivo(const string& nombreArchivo, const MiVector<Artista>& lista);
    static void leerDesdeArchivo(const string& nombreArchivo, MiVector<Artista>& lista);
};

#endif
