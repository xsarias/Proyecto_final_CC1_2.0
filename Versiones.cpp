#include "Librerias/Version.h"
#include <iostream>

void Version :: insertar_cabeceras(){
    multi_version.insertar(titulo_ver);
    multi_version.insertar(tipoVers);
    multi_version.insertar(anioPub);
    multi_version.insertar(paisGrab);
    multi_version.insertar(artistaPrinc);
    multi_version.insertar(ciudad_Grab);
    multi_version.insertar(genero_ver);
} 
void Version ::insertar_cancion(Version version){
    nodo_versiones version_nueva;
    version_nueva.titulos = version.tituloVer;
    version_nueva.tipo_version = version.tipVersion;
    version_nueva.anio_pub = version.anio;
    version_nueva.pais_grab = version.paisGra;
    version_nueva.artista_princ = version.artistasPrin;
    version_nueva.ciudad_grab = version.ciudadGrab;
    version_nueva.genero = version.genero;


}