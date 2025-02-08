#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H
#include <string>
#include "MiVector.h"
struct cabeza{
    std :: string nombre_list;
    int pos_cabeza;
};
struct nodo_links{
    std::string nom_plat;
    std::string link_album;
    std::string link_cancion;
    int sig_nomPlata, sig_linkAlb, sig_linkCan;
};
struct nodo_artistas{
    std::string nom_real;
    std::string nom_artistico;
    std::string pais_origen;
    std::string instru_interpre;
    int sig_nomReal, sig_nomArtistico, sig_paisOri, sig_instrumento;
};

struct nodo_versiones{
    std::string titulos, tipo_version, pais_grab, artista_princ, ciudad_grab, genero;
    int año;
    MiVector<nodo_links> lista_links;
    MiVector<nodo_artistas> lista_artistas;
    int sig_titulo, sig_tipoVers, sig_paisGrab, sig_artistaPrinc, sig_listaArt;
    int sig_ciudadGrab, sig_genero, sig_año, sig_listaLinks;
};


struct nodo_canciones{
    std::string nom_artistico;
    std::string nom_cancion;
    std::string duracion;
    MiVector<nodo_artistas> list_artist;  
    int numArtistasPrincipales;  
    std::string composLetra;  
    std::string composMusica;  
    std::string arrMusic;  
    std::string ciudadGrabacion; 
    std::string paisGrabacion; 
    int anioPublicacion; 
    std::string genero;
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
    std::string titulo, nom_artis, cover, fotografia, editora, estudio_grab, anio_pub;
    MiVector<nodo_links> lista_links;
    MiVector<nodo_canciones> lista_caciones;
    MiVector<nodo_artistas> lista_artistas;
    int sig_titulo, sig_nomArtis, sig_listaArtis, sig_cover, sig_estudioGrab, sig_fotografia, sig_editora;
    int sig_anioPublic, sig_listaLinks, sig_listaCanci;
    
};


#endif