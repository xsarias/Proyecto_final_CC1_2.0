#ifndef MULTILISTA_VERSION_H
#define MULTILISTA_VERSION_H
#include "estructuras.h"
#include "MiVector.h"
#include <iostream>
#include <string>
using namespace std;

class Multilista_version{
    int num_dat; // Contador de datos
    int num_cab; // Contador de cabeceras
    int pos_cab, cab;
    MiVector<cabeza> lista_cabeceras; // Lista de cabeceras
    MiVector<nodo_versiones> lista_versiones; // Lista de datos

public:
    Multilista_version() : num_dat(0), num_cab(0) {}

    void insertar(nodo_versiones Dato);
    void insertar(cabeza Cabeza);
    bool Multilista_vacia();
    string retornar_dato(int x, string parametro);
    int retornar_pos(int x, string parametro);
    void por_titulo(int pos, string dato);
    void por_tipo_version(int pos, string dato);
    void por_anio(int pos, string dato);
    void por_pais_grab(int pos, string dato);
    void por_artista_princ(int pos, string dato);
    void por_ciudad(int pos, string dato);
    void por_genero(int pos, string dato);
    


};

// Implementaciones
void Multilista_version:: insertar(cabeza Cabeza) {
    lista_cabeceras.push_back(Cabeza);
    num_cab++;
}

void Multilista_version:: insertar(nodo_versiones Dato) {
    lista_versiones.push_back(Dato);
    num_dat = lista_versiones.size();
}

bool Multilista_version:: Multilista_vacia(){
    return num_dat == 0;
}
string Multilista_version::retornar_dato(int x, string parametro){
    if(parametro == "titulos") return lista_versiones[x].titulos;
    if(parametro == "tipo_version") return lista_versiones[x].tipo_version;
    if(parametro == "pais_grab") return lista_versiones[x].pais_grab;
    if(parametro == "artista_princ") return lista_versiones[x].artista_princ;
    if(parametro == "ciudad_grab") return lista_versiones[x].ciudad_grab;
    if(parametro == "genero") return lista_versiones[x].genero;
    if(parametro == "anio_pub") return lista_versiones[x].anio_pub;
    return "Parametro desconocido";


}
int Multilista_version::retornar_pos(int x, string parametro){
    if(parametro == "sig_titulo") return lista_versiones[x].sig_titulo;
    if(parametro == "sig_tipoVers") return lista_versiones[x].sig_tipoVers;
    if(parametro == "sig_paisGrab") return lista_versiones[x].sig_paisGrab;
    if(parametro == "sig_artistaPrinc") return lista_versiones[x].sig_artistaPrinc;
    if(parametro == "sig_ciudadGrab") return lista_versiones[x].sig_ciudadGrab;
    if(parametro == "sig_genero") return lista_versiones[x].sig_genero;
    if(parametro == "sig_anioPub") return lista_versiones[x].sig_anioPub;
    return -1;

}
void Multilista_version::por_titulo(int pos, string dato){
    pos_cab = 1;
    cab = lista_cabeceras[pos_cab].pos_cabeza;
    if (cab == 0 || dato < retornar_dato(cab, "titulos")) {
        lista_versiones[pos].sig_genero = cab;
        lista_cabeceras[pos_cab].pos_cabeza = pos;
    } else {
        int ant = cab;
        int sig = retornar_pos(cab, "sig_titulo");

        while (sig != 0 && dato > retornar_dato(sig, "titulos")) {
            ant = sig;
            sig = retornar_pos(sig, "sig_titulo");
        }
        lista_versiones[pos].sig_titulo = sig;
        lista_versiones[ant].sig_titulo = pos;
    }
}
void Multilista_version::por_tipo_version(int pos, string dato){
    pos_cab = 2;
    cab = lista_cabeceras[pos_cab].pos_cabeza;
    if (cab == 0 || dato < retornar_dato(cab, "tipo_version")) {
        lista_versiones[pos].sig_tipoVers = cab;
        lista_cabeceras[pos_cab].pos_cabeza = pos;
    } else {
        int ant = cab;
        int sig = retornar_pos(cab, "sig_tipoVers");

        while (sig != 0 && dato > retornar_dato(sig, "tipo_version")) {
            ant = sig;
            sig = retornar_pos(sig, "sig_tipoVers");
        }
        lista_versiones[pos].sig_tipoVers = sig;
        lista_versiones[ant].sig_tipoVers = pos;
    }

}
void Multilista_version::por_anio(int pos, string dato){
    pos_cab = 3;
    cab = lista_cabeceras[pos_cab].pos_cabeza;
    if (cab == 0 || dato < retornar_dato(cab, "anio_pub")) {
        lista_versiones[pos].sig_anioPub = cab;
        lista_cabeceras[pos_cab].pos_cabeza = pos;
    } else {
        int ant = cab;
        int sig = retornar_pos(cab, "sig_anioPub");

        while (sig != 0 && dato > retornar_dato(sig, "anio_pub")) {
            ant = sig;
            sig = retornar_pos(sig, "sig_anioPub");
        }
        lista_versiones[pos].sig_anioPub = sig;
        lista_versiones[ant].sig_anioPub= pos;
    }

}
void Multilista_version::por_pais_grab(int pos, string dato){
    pos_cab = 4;
    cab = lista_cabeceras[pos_cab].pos_cabeza;
     if (cab == 0 || dato < retornar_dato(cab, "pais_grab")) {
        lista_versiones[pos].sig_paisGrab = cab;
        lista_cabeceras[pos_cab].pos_cabeza = pos;
    } else {
        int ant = cab;
        int sig = retornar_pos(cab, "sig_paisGrab");

        while (sig != 0 && dato > retornar_dato(sig, "pais_grab")) {
            ant = sig;
            sig = retornar_pos(sig, "sig_paisGrab");
        }
        lista_versiones[pos].sig_paisGrab = sig;
        lista_versiones[ant].sig_paisGrab= pos;
    }

}
void Multilista_version::por_artista_princ(int pos, string dato){
    pos_cab = 5;
    cab = lista_cabeceras[pos_cab].pos_cabeza;
     if (cab == 0 || dato < retornar_dato(cab, "artista_princ")) {
        lista_versiones[pos].sig_artistaPrinc = cab;
        lista_cabeceras[pos_cab].pos_cabeza = pos;
    } else {
        int ant = cab;
        int sig = retornar_pos(cab, "sig_artistaPrinc");

        while (sig != 0 && dato > retornar_dato(sig, "artista_princ")) {
            ant = sig;
            sig = retornar_pos(sig, "sig_artistaPrinc");
        }
        lista_versiones[pos].sig_artistaPrinc = sig;
        lista_versiones[ant].sig_artistaPrinc= pos;
    }

}
void Multilista_version::por_ciudad(int pos, string dato){
    pos_cab = 6;
    cab = lista_cabeceras[pos_cab].pos_cabeza;
     if (cab == 0 || dato < retornar_dato(cab, "ciudad_grab")) {
        lista_versiones[pos].sig_ciudadGrab = cab;
        lista_cabeceras[pos_cab].pos_cabeza = pos;
    } else {
        int ant = cab;
        int sig = retornar_pos(cab, "sig_ciudadGrab");

        while (sig != 0 && dato > retornar_dato(sig, "ciudad_grab")) {
            ant = sig;
            sig = retornar_pos(sig, "sig_ciudadGrab");
        }
        lista_versiones[pos].sig_ciudadGrab = sig;
        lista_versiones[ant].sig_ciudadGrab = pos;
    }

}
void Multilista_version::por_genero(int pos, string dato){
    pos_cab = 7;
    cab = lista_cabeceras[pos_cab].pos_cabeza;
     if (cab == 0 || dato < retornar_dato(cab, "genero")) {
        lista_versiones[pos].sig_genero = cab;
        lista_cabeceras[pos_cab].pos_cabeza = pos;
    } else {
        int ant = cab;
        int sig = retornar_pos(cab, "sig_genero");

        while (sig != 0 && dato > retornar_dato(sig, "genero")) {
            ant = sig;
            sig = retornar_pos(sig, "sig_genero");
        }
        lista_versiones[pos].sig_genero = sig;
        lista_versiones[ant].sig_genero= pos;
    }
    
}

#endif