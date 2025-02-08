#ifndef LINKS_H
#define LINKS_H
#include <string>
#include "estructuras.h"
#include "MiVector.h"
using namespace std;

class Links {
private:
    int id;          // Nuevo atributo ID
    string nomPlat;  // Nombre de la plataforma
    string linkAlbum;
    string linkCancion;

public:
    // Constructor
    Links() : id(0), nomPlat(" "), linkAlbum(" "), linkCancion(" ") {}
    Links(int id, const string& nomPlat, const string& linkAlbum, const string& linkCancion)
        : id(id), nomPlat(nomPlat), linkAlbum(linkAlbum), linkCancion(linkCancion) {}

    // Getters
    int getId() const { return id; }
    string getNomPlat() const { return nomPlat; }
    string getLinkAlbum() const { return linkAlbum; }
    string getLinkCancion() const { return linkCancion; }

    // Método para obtener el link completo
    string obtenerLink() const {
        return "ID: " + to_string(id) + " | Link Álbum: " + linkAlbum + ", Link Canción: " + linkCancion;
    }

    // Método para actualizar el link del álbum
    void actualizarLink(const string& link) {
        linkAlbum = link;
    }

    // Método para obtener el nombre de la plataforma
    string obtenerPlataforma() const {
        return nomPlat;
    }

    nodo_links insertar_link(Links links);

    // Métodos para leer y guardar en archivo
    static void guardarEnArchivo(const string& nombreArchivo, const MiVector<Links>& lista);
    static void leerDesdeArchivo(const string& nombreArchivo, MiVector<Links>& lista);
};

#endif
