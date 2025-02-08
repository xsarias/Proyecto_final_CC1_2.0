#ifndef LINKS_H
#define LINKS_H
#include <string>
using namespace std;
class Links {
private:
    string nomPlat;  // Nombre de la plataforma
    string linkAlbum;
    string linkCancion;

public:
    // Constructor
    Links() : nomPlat(" "), linkAlbum(" "), linkCancion(" "){}
    Links(const string& nomPlat, const string& linkAlbum, const string& linkCancion)
        : nomPlat(nomPlat), linkAlbum(linkAlbum), linkCancion(linkCancion) {}

    // Getters
    string getNomPlat() const { return nomPlat; }
    string getLinkAlbum() const { return linkAlbum; }
    string getLinkCancion() const { return linkCancion; }

    // Método para obtener el link completo
    string obtenerLink() const {
        return "Link Álbum: " + linkAlbum + ", Link Canción: " + linkCancion;
    }

    // Método para actualizar el link del álbum
    void actualizarLink(const string& link) {
        linkAlbum = link; 
    }

    // Método para obtener el nombre de la plataforma
    string obtenerPlataforma() const {
        return nomPlat;
    }

};
#endif