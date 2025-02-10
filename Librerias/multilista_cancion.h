#ifndef MULTILISTA_CANCION_H
#define MULTILISTA_CANCION_H

#include "estructuras.h"
#include "MiVector.h"
#include <iostream>
#include <string>
using namespace std;

class Multilista_cancion {
    int num_dat; // Contador de datos
    int num_cab; // Contador de cabeceras
    MiVector<cabeza> lista_cabeceras; // Lista de cabeceras
    MiVector<nodo_canciones> lista_datos; // Lista de datos

public:
    

    void insertar(nodo_canciones Dato);
    void insertar(cabeza Cabeza);
    bool Multilista_vacia();
    string retornar_dato(int x, string parametro);
    int retornar_pos(int x, string parametro);
    void por_nom_artistico(int pos, string dato);
    void por_nom_cancion(int pos, string dato);
    void por_anio_pub(int pos, string dato);
    void por_genero(int pos, string dato);
    void por_compositor_letra(int pos, string dato);
    void por_compositor_musica(int pos, string dato);
    void por_pais(int pos, string dato);
    void por_ciudad(int pos, string dato);
    void por_duracion(int pos, string dato);
    bool lista_llena();
};

// Implementaciones

void Multilista_cancion::insertar(cabeza Cabeza) {
    lista_cabeceras.push_back(Cabeza);
    num_cab++;
}

void Multilista_cancion::insertar(nodo_canciones Dato) {
    lista_datos.push_back(Dato);
    num_dat = lista_datos.size();
    por_nom_artistico(num_dat, lista_datos[num_dat].nom_artistico);
    por_anio_pub(num_dat, to_string(lista_datos[num_dat].anioPublicacion));
    por_ciudad(num_dat, lista_datos[num_dat].ciudadGrabacion);
    por_compositor_letra(num_dat, lista_datos[num_dat].composLetra);
    por_compositor_musica(num_dat, lista_datos[num_dat].composMusica);
    por_genero(num_dat, lista_datos[num_dat].genero);
    por_nom_cancion(num_dat, lista_datos[num_dat].nom_cancion);
    por_pais(num_dat, lista_datos[num_dat].paisGrabacion);
    por_duracion(num_dat, lista_datos[num_dat].duracion);
}

void Multilista_cancion::por_nom_artistico(int pos, string dato) {
    int pos_cab = 1;
    int cab = lista_cabeceras[pos_cab].pos_cabeza;
    if (cab == 0 || dato < retornar_dato(cab, "nombre_artistico")) {
        lista_datos[pos].sig_nombre_artistico = cab;
        lista_cabeceras[pos_cab].pos_cabeza = pos;
    } else {
        int ant = cab;
        int sig = retornar_pos(cab, "sig_nombre_artistico");

        while (sig != 0 && dato > retornar_dato(sig, "nombre_artistico")) {
            ant = sig;
            sig = retornar_pos(sig, "sig_nombre_artistico");
        }
        lista_datos[pos].sig_nombre_artistico = sig;
        lista_datos[ant].sig_nombre_artistico = pos;
    }
}
void Multilista_cancion::por_nom_cancion(int pos, string dato) {
    int pos_cab = 2;
    int cab = lista_cabeceras[pos_cab].pos_cabeza;
    if (cab == 0 || dato < retornar_dato(cab, "nom_cancion")) {
        lista_datos[pos].sig_nom_cancion = cab;
        lista_cabeceras[pos_cab].pos_cabeza = pos;
    } else {
        int ant = cab;
        int sig = retornar_pos(cab, "sig_nom_cancion");

        while (sig != 0 && dato > retornar_dato(sig, "nombre_artistico")) {
            ant = sig;
            sig = retornar_pos(sig, "sig_nom_cancion");
        }
        lista_datos[pos].sig_nom_cancion = sig;
        lista_datos[ant].sig_nom_cancion = pos;
    }
}
void Multilista_cancion::por_anio_pub(int pos, string dato) {
    int pos_cab = 8;
    int cab = lista_cabeceras[pos_cab].pos_cabeza;
    if (cab == 0 || dato < retornar_dato(cab, "anioPublicacion")) {
        lista_datos[pos].sig_anio_pub = cab;
        lista_cabeceras[pos_cab].pos_cabeza = pos;
    } else {
        int ant = cab;
        int sig = retornar_pos(cab, "sig_anio_pub");

        while (sig != 0 && dato > retornar_dato(sig, "anioPublicacion")) {
            ant = sig;
            sig = retornar_pos(sig, "sig_anio_pub");
        }
        lista_datos[pos].sig_anio_pub = sig;
        lista_datos[ant].sig_anio_pub = pos;
    }
}
void Multilista_cancion::por_genero(int pos, string dato) {
    int pos_cab = 7;
    int cab = lista_cabeceras[pos_cab].pos_cabeza;
    if (cab == 0 || dato < retornar_dato(cab, "genero")) {
        lista_datos[pos].sig_genero = cab;
        lista_cabeceras[pos_cab].pos_cabeza = pos;
    } else {
        int ant = cab;
        int sig = retornar_pos(cab, "sig_genero");

        while (sig != 0 && dato > retornar_dato(sig, "genero")) {
            ant = sig;
            sig = retornar_pos(sig, "sig_genero");
        }
        lista_datos[pos].sig_genero = sig;
        lista_datos[ant].sig_genero = pos;
    }
}
void Multilista_cancion::por_compositor_letra(int pos, string dato) {
    int pos_cab = 3;
    int cab = lista_cabeceras[pos_cab].pos_cabeza;
    if (cab == 0 || dato < retornar_dato(cab, "composLetra")) {
        lista_datos[pos].sig_comp_let = cab;
        lista_cabeceras[pos_cab].pos_cabeza = pos;
    } else {
        int ant = cab;
        int sig = retornar_pos(cab, "sig_comp_let");

        while (sig != 0 && dato > retornar_dato(sig, "composLetra")) {
            ant = sig;
            sig = retornar_pos(sig, "sig_comp_let");
        }
        lista_datos[pos].sig_comp_let = sig;
        lista_datos[ant].sig_comp_let = pos;
    }
}

void Multilista_cancion::por_compositor_musica(int pos, string dato) {
    int pos_cab = 4;
    int cab = lista_cabeceras[pos_cab].pos_cabeza;
    if (cab == 0 || dato < retornar_dato(cab, "composMusica")) {
        lista_datos[pos].sig_comp_music = cab;
        lista_cabeceras[pos_cab].pos_cabeza = pos;
    } else {
        int ant = cab;
        int sig = retornar_pos(cab, "sig_comp_mus");

        while (sig != 0 && dato > retornar_dato(sig, "composMusica")) {
            ant = sig;
            sig = retornar_pos(sig, "sig_comp_mus");
        }
        lista_datos[pos].sig_comp_music = sig;
        lista_datos[ant].sig_comp_music = pos;
    }
}
void Multilista_cancion::por_pais(int pos, string dato) {
    int pos_cab = 5;
    int cab = lista_cabeceras[pos_cab].pos_cabeza;
    if (cab == 0 || dato < retornar_dato(cab, "paisGrabacion")) {
        lista_datos[pos].sig_pais = cab;
        lista_cabeceras[pos_cab].pos_cabeza = pos;
    } else {
        int ant = cab;
        int sig = retornar_pos(cab, "sig_pais");

        while (sig != 0 && dato > retornar_dato(sig, "paisGrabacion")) {
            ant = sig;
            sig = retornar_pos(sig, "sig_pais");
        }
        lista_datos[pos].sig_pais= sig;
        lista_datos[ant].sig_pais = pos;
    }
}
void Multilista_cancion::por_ciudad(int pos, string dato) {
    int pos_cab = 6;
    int cab = lista_cabeceras[pos_cab].pos_cabeza;
    if (cab == 0 || dato < retornar_dato(cab, "ciudadGrabacion")) {
        lista_datos[pos].sig_ciudad = cab;
        lista_cabeceras[pos_cab].pos_cabeza = pos;
    } else {
        int ant = cab;
        int sig = retornar_pos(cab, "sig_ciudad");

        while (sig != 0 && dato > retornar_dato(sig, "ciudadGrabacion")) {
            ant = sig;
            sig = retornar_pos(sig, "sig_ciudad");
        }
        lista_datos[pos].sig_ciudad= sig;
        lista_datos[ant].sig_ciudad = pos;
    }

}
void Multilista_cancion::por_duracion(int pos, string dato){
    int pos_cab = 9;
    int cab = lista_cabeceras[pos_cab].pos_cabeza;
    if (cab == 0 || dato < retornar_dato(cab, "duracion")) {
        lista_datos[pos].sig_duracion = cab;
        lista_cabeceras[pos_cab].pos_cabeza = pos;
    } else {
        int ant = cab;
        int sig = retornar_pos(cab, "sig_duracion");

        while (sig != 0 && dato > retornar_dato(sig, "duracion")) {
            ant = sig;
            sig = retornar_pos(sig, "sig_duracion");
        }
        lista_datos[pos].sig_duracion= sig;
        lista_datos[ant].sig_duracion = pos;
    }    
}

int Multilista_cancion::retornar_pos(int x, string parametro) {
    if (parametro == "sig_genero") return lista_datos[x].sig_genero;
    if (parametro == "sig_nom_cancion") return lista_datos[x].sig_nom_cancion;
    if (parametro == "sig_anio_pub") return lista_datos[x].sig_anio_pub;
    if (parametro == "sig_nombre_artistico") return lista_datos[x].sig_nombre_artistico;
    if (parametro == "sig_comp_let") return lista_datos[x].sig_comp_let;
    if (parametro == "sig_comp_mus") return lista_datos[x].sig_comp_music;
    if (parametro == "sig_pais") return lista_datos[x].sig_pais;
    if (parametro == "sig_ciudad") return lista_datos[x].sig_ciudad;
    if (parametro == "pos_cabeza") return lista_cabeceras[x].pos_cabeza;
    if(parametro == "sig_duracion") return lista_datos[x].sig_duracion;
    return -1;
}

string Multilista_cancion::retornar_dato(int x, string parametro) {
    
    if (parametro == "nom_cancion") return lista_datos[x].nom_cancion;
    if (parametro == "nombre_artistico") return lista_datos[x].nom_artistico;
    if (parametro == "duracion") return lista_datos[x].duracion;
    if (parametro == "numArtistasPrincipales") return to_string(lista_datos[x].numArtistasPrincipales);
    if (parametro == "composLetra") return lista_datos[x].composLetra;
    if (parametro == "composMusica") return lista_datos[x].composMusica;
    if (parametro == "arrMusic") return lista_datos[x].arrMusic;
    if (parametro == "ciudadGrabacion") return lista_datos[x].ciudadGrabacion;
    if (parametro == "paisGrabacion") return lista_datos[x].paisGrabacion;
    if (parametro == "anioPublicacion") return to_string(lista_datos[x].anioPublicacion);
    if (parametro == "genero") return lista_datos[x].genero;
    if (parametro == "nombreCabeza") return lista_cabeceras[x].nombre_list;
    return "Parámetro desconocido";
}
bool Multilista_cancion::Multilista_vacia() {
    return num_dat == 0;
}

bool Multilista_cancion::lista_llena() {
    return false; // Con punteros, no hay límite fijo de tamaño
}




#endif