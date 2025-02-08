#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H
#include <string>
#include "MiVector.h"
using namespace std;

struct cabeza{
    string nombre_list;
    int pos_cabeza;
};
struct nodo_links{
    int id;
    string nom_plat;
    string link_album;
    string link_cancion;
    int sig_nomPlata, sig_linkAlb, sig_linkCan;
};
struct nodo_artistas{
    int id;
    string nom_real;
    string nom_artistico;
    string pais_origen;
    string instru_interpre;
    int sig_nomReal, sig_nomArtistico, sig_paisOri, sig_instrumento;
};

struct nodo_versiones{
    int id; 
    string titulos, tipo_version, pais_grab, artista_princ, ciudad_grab, genero;
    int anio_pub;
    MiVector<nodo_links> lista_links;
    MiVector<nodo_artistas> lista_artistas;
    int sig_titulo, sig_tipoVers, sig_paisGrab, sig_artistaPrinc;
    int sig_ciudadGrab, sig_genero, sig_anioPub;
};


struct nodo_canciones{
    int id;
    string nom_artistico;
    string nom_cancion;
    string duracion;
    MiVector<nodo_artistas> list_artist;  
    int numArtistasPrincipales;  
    string composLetra;  
    string composMusica;  
    string arrMusic;  
    string ciudadGrabacion; 
    string paisGrabacion; 
    int anioPublicacion; 
    string genero;
    MiVector<nodo_links> list_links;
    MiVector<nodo_versiones> list_versiones;
    int sig_nom_cancion;
    int sig_nombre_artistico;
    int sig_comp_let;
    int sig_comp_music;
    int sig_pais;
    int sig_ciudad;
    int sig_genero;
    int sig_anio_pub;
};



struct nodo_album{
    int id;
    string titulo, nom_artis, cover, fotografia, editora, estudio_grab, anio_pub;
    MiVector<nodo_links> lista_links;
    MiVector<nodo_canciones> lista_caciones;
    MiVector<nodo_artistas> lista_artistas;
    int sig_titulo, sig_nomArtis, sig_listaArtis, sig_cover, sig_estudioGrab, sig_fotografia, sig_editora;
    int sig_anioPublic, sig_listaLinks, sig_listaCanci;
    
};

#endif
