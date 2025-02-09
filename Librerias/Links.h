#ifndef LINKS_H
#define LINKS_H
#include <string>
#include "estructuras.h"
#include "MiVector.h"
using namespace std;

class Links {
private:
    int id;         // ID único del link
    int idCancion;  // ID de la canción asociada (clave foránea)
    int idAlbum;    // ID del Álbum asociado (clave foránea)
    int idVersion;  // ID de la Versión asociada (clave foránea)
    string nomPlat; // Nombre de la plataforma
    string linkAlbum;
    string linkCancion;

public:
    // Constructor por defecto
    Links() : id(0), idCancion(0), idAlbum(0), idVersion(0), nomPlat(" "), linkAlbum(" "), linkCancion(" ") {}

    // Constructor con parámetros
    Links(int id,int idCancion, int idAlbum, int idVersion, const string& nomPlat, const string& linkAlbum, const string& linkCancion)
        : id(id), idCancion(idCancion), idAlbum(idAlbum), idVersion(idVersion), nomPlat(nomPlat), linkAlbum(linkAlbum), linkCancion(linkCancion) {}

    // Getters
    int getId() const { return id; }
    int getIdAlbum() const { return idAlbum; }
    int getIdVersion() const { return idVersion; }
    string getNomPlat() const { return nomPlat; }
    string getLinkAlbum() const { return linkAlbum; }
    string getLinkCancion() const { return linkCancion; }

    // Método para obtener el link completo
    string obtenerLink() const {
        return "ID: " + to_string(id) + " | Álbum ID: " + to_string(idAlbum) + " | Versión ID: " + to_string(idVersion) +
               " | Link Álbum: " + linkAlbum + ", Link Canción: " + linkCancion;
    }

    // Método para actualizar el link del álbum
    void actualizarLinkAlbum(const string& link) {
        linkAlbum = link;
    }

    // Método para actualizar el link de la canción
    void actualizarLinkCancion(const string& link) {
        linkCancion = link;
    }

    nodo_links insertar_link(Links links);

    // Métodos para leer y guardar en archivo
    static void guardarEnArchivo(const string& nombreArchivo, const MiVector<Links>& lista);
    static void leerDesdeArchivo(const string& nombreArchivo, MiVector<Links>& lista);
    static void eliminarDeArchivo(const string& nombreArchivo, MiVector<Links>& lista);

};

#endif
