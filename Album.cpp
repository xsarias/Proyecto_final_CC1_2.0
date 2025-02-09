#include <iostream>
#include <fstream>
#include "Librerias/Album.h"
#include "Librerias/Links.h"
#include "Librerias/Cancion.h"

using namespace std;

void Album::insertar_cabeceras() {
    multi_album.insertar(titulo);
    multi_album.insertar(nom_artis);
    multi_album.insertar(anio_publi);
    multi_album.insertar(cover);
    multi_album.insertar(fotografia);
    multi_album.insertar(estudio_grabaci);
    multi_album.insertar(editorial);
}

void Album ::insertar_album(Album album, MiVector<nodo_canciones>canciones_album, MiVector<Links> links_album){
    nodo_album album_nuevo;
    album_nuevo.id = album.id;
    album_nuevo.titulo = album.titulo_alb;
    album_nuevo.nom_artis = album.nombre_art;
    album_nuevo.cover = album.cover_art;
    album_nuevo.fotografia = album.fotogra;
    album_nuevo.editora = album.editora;
    album_nuevo.estudio_grab = album.estudio_grab;
    album_nuevo.anio_pub = album.anio_pub;
    for(int i=1; i<= canciones_album.size(); i++){
        album_nuevo.lista_caciones.push_back(canciones_album[i]);
        cout << "cancion insertada 1 insertado" << endl;
    }
    for(int j=1; j<=links_album.size(); j++){
        album_nuevo.lista_links.push_back(links_album[j].insertar_link(links_album[j]));
        cout << "links 1 insertado" << endl;
    }
    
    multi_album.insertar(album_nuevo);
    cout << "Álbum insertado" << endl;
}
void Album:: consultar_por_atributo(string atributo, int cabecera, string contex){
    multi_album.consulta_por_atributo(atributo, cabecera, contex);
}

// Guardar lista de álbumes en archivo
void Album::guardarEnArchivo(const string& nombreArchivo, const MiVector<Album>& lista) {
    ofstream archivo(nombreArchivo);
    if (!archivo) {
        cerr << "Error al abrir el archivo para escritura." << endl;
        return;
    }

    for (size_t i = 1; i <= lista.size(); i++) {
        archivo << lista[i].getId() << ","
                << lista[i].getTitulo() << ","
                << lista[i].getNombreArt() << ","
                << lista[i].getPaisGrab() << ","
                << lista[i].getAnioPub() << ","
                << lista[i].getCoverArt() << ","
                << lista[i].getFotogra() << ","
                << lista[i].getEditora() << ","
                << lista[i].getEstudioGrab() << endl;
    }

    archivo.close();
}

// Leer lista de álbumes desde archivo
void Album::leerDesdeArchivo(const string& nombreArchivo, MiVector<Album>& lista) {
    ifstream archivo(nombreArchivo);
    if (!archivo) {
        cerr << "Error al abrir el archivo para lectura." << endl;
        return;
    }

    lista.clear();

    int id, anioPub;
    string tituloAlb, nombreArt, paisGrab, coverArt, fotogra, editora, estudioGrab;

    while (archivo >> id) {
        archivo.ignore();
        getline(archivo, tituloAlb, ',');
        getline(archivo, nombreArt, ',');
        getline(archivo, paisGrab, ',');
        archivo >> anioPub;
        archivo.ignore();
        getline(archivo, coverArt, ',');
        getline(archivo, fotogra, ',');
        getline(archivo, editora, ',');
        getline(archivo, estudioGrab);

        lista.push_back(Album(id, tituloAlb, nombreArt, paisGrab, anioPub, coverArt, fotogra, editora, estudioGrab));
    }

    archivo.close();
}

void Album::eliminarDeArchivo(const string& nombreArchivo, MiVector<Album>& lista) {
    int idEliminar;
    cout << "Ingrese el ID del álbum que desea eliminar: ";
    cin >> idEliminar;

    bool encontrado = false;
    for (size_t i = 1; i <= lista.size(); i++) {
        if (lista[i].getId() == idEliminar) {
            encontrado = true;
            cout << "Está seguro de eliminar el siguiente álbum? (y/n)\n";
            cout << "ID: " << lista[i].getId() << "\n"
                 << "Título: " << lista[i].getTitulo() << "\n"
                 << "Artista: " << lista[i].getNombreArt() << "\n"
                 << "País de grabación: " << lista[i].getPaisGrab() << "\n"
                 << "Año de publicación: " << lista[i].getAnioPub() << "\n"
                 << "Cover Art: " << lista[i].getCoverArt() << "\n"
                 << "Fotografía: " << lista[i].getFotogra() << "\n"
                 << "Editora: " << lista[i].getEditora() << "\n"
                 << "Estudio de grabación: " << lista[i].getEstudioGrab() << "\n";

            char confirmacion;
            cout << "Confirmar eliminación (y/n): ";
            cin >> confirmacion;

            if (confirmacion == 'y' || confirmacion == 'Y') {
                lista.erase(i);  // Eliminar de la lista
                cout << "Álbum eliminado con éxito.\n";
            } else {
                cout << "Eliminación cancelada.\n";
            }
            break;
        }
    }

    if (!encontrado) {
        cout << "No se encontró un álbum con el ID especificado.\n";
        return;
    }

    // Guardar la lista actualizada en el archivo
    guardarEnArchivo(nombreArchivo, lista);
}

void Album::actualizarDesdeArchivo(const string& nombreArchivo, MiVector<Album>& lista) {
    int idEditar;
    cout << "Ingrese el ID del álbum que desea editar: ";
    cin >> idEditar;

    bool encontrado = false;
    for (size_t i = 1; i <= lista.size(); i++) {
        if (lista[i].getId() == idEditar) {
            encontrado = true;
            cout << "Álbum encontrado. Datos actuales:\n";
            cout << "1. ID: " << lista[i].getId() << "\n";
            cout << "2. Título: " << lista[i].getTitulo() << "\n";
            cout << "3. Nombre del artista: " << lista[i].getNombreArt() << "\n";
            cout << "4. País de grabación: " << lista[i].getPaisGrab() << "\n";
            cout << "5. Año de publicación: " << lista[i].getAnioPub() << "\n";
            cout << "6. Cover Art: " << lista[i].getCoverArt() << "\n";
            cout << "7. Fotografía: " << lista[i].getFotogra() << "\n";
            cout << "8. Editora: " << lista[i].getEditora() << "\n";
            cout << "9. Estudio de grabación: " << lista[i].getEstudioGrab() << "\n";

            int opcion;
            while (true) {
                cout << "Ingrese el número del atributo que desea modificar (0 para salir): ";
                cin >> opcion;
                cin.ignore(); // Limpiar buffer

                if (opcion == 0) {
                    cout << "Saliendo del modo de edición...\n";
                    break;
                }

                string nuevoValor;
                int nuevoId, nuevoAnio;
                switch (opcion) {
                    case 1:
                        cout << "Nuevo ID: ";
                        cin >> nuevoId;
                        lista[i].setId(nuevoId);
                        break;
                    case 2:
                        cout << "Nuevo título: ";
                        getline(cin, nuevoValor);
                        lista[i].setTitulo(nuevoValor);
                        break;
                    case 3:
                        cout << "Nuevo nombre del artista: ";
                        getline(cin, nuevoValor);
                        lista[i].setNombreArt(nuevoValor);
                        break;
                    case 4:
                        cout << "Nuevo país de grabación: ";
                        getline(cin, nuevoValor);
                        lista[i].setPaisGrab(nuevoValor);
                        break;
                    case 5:
                        cout << "Nuevo año de publicación: ";
                        cin >> nuevoAnio;
                        lista[i].setAnioPub(nuevoAnio);
                        break;
                    case 6:
                        cout << "Nuevo cover art: ";
                        getline(cin, nuevoValor);
                        lista[i].setCoverArt(nuevoValor);
                        break;
                    case 7:
                        cout << "Nueva fotografía: ";
                        getline(cin, nuevoValor);
                        lista[i].setFotogra(nuevoValor);
                        break;
                    case 8:
                        cout << "Nueva editora: ";
                        getline(cin, nuevoValor);
                        lista[i].setEditora(nuevoValor);
                        break;
                    case 9:
                        cout << "Nuevo estudio de grabación: ";
                        getline(cin, nuevoValor);
                        lista[i].setEstudioGrab(nuevoValor);
                        break;
                    default:
                        cout << "Opción no válida. Intente de nuevo.\n";
                        continue;
                }
                cout << "Cambio realizado con éxito.\n";
            }
            break;
        }
    }

    if (!encontrado) {
        cout << "No se encontró un álbum con el ID especificado.\n";
        return;
    }

    // Guardar la lista actualizada en el archivo
    guardarEnArchivo(nombreArchivo, lista);
    cout << "Los cambios han sido guardados correctamente en el archivo.\n";
}

Album Album::buscarAlbumConRelacionados(const string& nombreArchivoAlbum, 
    const string& nombreArchivoLinks, 
    const string& nombreArchivoCanciones, 
    MiVector<Links>& listaLinks, 
    MiVector<Cancion>& listaCanciones) 
{
int idBuscado;
cout << "Ingrese el ID del álbum a buscar: ";
cin >> idBuscado;

MiVector<Album> listaAlbumes;
leerDesdeArchivo(nombreArchivoAlbum, listaAlbumes);

Album albumEncontrado;
bool encontrado = false;

// Buscar el álbum por ID
for (size_t i = 1; i <= listaAlbumes.size(); i++) {
if (listaAlbumes[i].getId() == idBuscado) {
albumEncontrado = listaAlbumes[i];
encontrado = true;
break;
}
}

if (!encontrado) {
cout << "No se encontró un álbum con el ID especificado.\n";
return Album();
}

// Leer registros de Links
MiVector<Links> todosLosLinks;
Links::leerDesdeArchivo(nombreArchivoLinks, todosLosLinks);

// Filtrar los links relacionados con este álbum
listaLinks.clear();
for (size_t i = 1; i <= todosLosLinks.size(); i++) {
if (todosLosLinks[i].getIdAlbum() == idBuscado) {
listaLinks.push_back(todosLosLinks[i]);
}
}

// Leer registros de Canciones
MiVector<Cancion> todasLasCanciones;
Cancion::leerDesdeArchivo(nombreArchivoCanciones, todasLasCanciones);

// Filtrar las canciones relacionadas con este álbum
listaCanciones.clear();
for (size_t i = 1; i <= todasLasCanciones.size(); i++) {
if (todasLasCanciones[i].getIdAlbum() == idBuscado) {
listaCanciones.push_back(todasLasCanciones[i]);
}
}

return albumEncontrado;
}


