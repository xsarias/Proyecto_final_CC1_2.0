#ifndef VERSION_H
#define VERSION_H
#include <string>
#include "MiVector.h"
#include "Links.h"
using namespace std;

class Version {
private:
    string tituloVer;  
    string tipVersion;  
    MiVector<string> artistasPrin;  
    string ciudadGrab;  
    string paisGra;  
    string arrMusic;  
    string genero;  
    int anio; 
    MiVector<Links> listLinksVers;  

public:
    // Constructor
    Version() :  tituloVer(""), tipVersion(""), anio(0), ciudadGrab(""), paisGra(""), genero(""), arrMusic("") {};

    Version(const string& tituloVer, const string& tipVersion, int anio,
            const string& ciudadGrab = "", const string& paisGra = "",
            const string& genero = "", const string& arrMusic = "")
        : tituloVer(tituloVer), tipVersion(tipVersion), anio(anio),
          ciudadGrab(ciudadGrab), paisGra(paisGra), genero(genero), arrMusic(arrMusic) {}
    

};
#endif