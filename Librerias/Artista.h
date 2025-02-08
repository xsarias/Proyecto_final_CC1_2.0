#ifndef ARTISTA_H
#define ARTISTA_H
#include <string>
using namespace std;
class Artista {
    private:
        string nom_real; 
        string nom_artist; 
        string pais_origen;  
        string instrum_inter;  
    
    public:
        // Constructor
        Artista() : nom_real(""), nom_artist(""), pais_origen(""), instrum_inter("") {}
        Artista(const string& nomReal, const string& nomArtist, const string& paisOrigen, const string& instrumInter)
            : nom_real(nomReal), nom_artist(nomArtist), pais_origen(paisOrigen), instrum_inter(instrumInter) {}
    
        // Getters
        string getNomReal() const { return nom_real; }
        string getNomArtist() const { return nom_artist; }
        string getPaisOrigen() const { return pais_origen; }
        string getInstrumInter() const { return instrum_inter; }
        void mostrarInformacion();
};


#endif