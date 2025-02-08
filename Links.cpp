#include <iostream>
#include "Librerias/Links.h"

nodo_links Links :: insertar_link(Links links){
    nodo_links nuevo_link;
    nuevo_link.link_album = links.linkAlbum;
    nuevo_link.link_cancion = links.linkCancion;
    nuevo_link.nom_plat = links.nomPlat;
    return nuevo_link;
}