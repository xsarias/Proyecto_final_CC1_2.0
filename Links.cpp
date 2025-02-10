#include <iostream>
#include <fstream>
#include "Librerias/Links.h"
#include "Librerias/MiVector.h"
MiVector<Links>links_archivo;
nodo_links Links::insertar_link(Links links) {
    links_archivo.push_back(links);
    nodo_links nuevo_link;
    nuevo_link.id = links.id;
    nuevo_link.id_cancion = links.idCancion;
    nuevo_link.id_album = links.idAlbum;
    nuevo_link.nom_plat = links.nomPlat;
    nuevo_link.link_album = links.linkAlbum;
    nuevo_link.link_cancion = links.linkCancion;
    //cout << "link insertado" <<endl;
    return nuevo_link;
}

// Método para guardar la lista de Links en un archivo
void Links::guardarEnArchivo(const string& nombreArchivo) {
    ofstream archivo(nombreArchivo);
    if (!archivo) {
        cerr << "Error al abrir el archivo para escritura." << endl;
        return;
    }
    for (int i = 1; i <= links_archivo.size(); i++) {
        archivo << links_archivo[i].getId() << ","
                << links_archivo[i].getIdCancion() << "," 
                << links_archivo[i].getIdAlbum() << ","
                << links_archivo[i].getNomPlat() << ","
                << links_archivo[i].getLinkAlbum() << ","
                << links_archivo[i].getLinkCancion() << endl;
    }

    archivo.close();
}


// Método para leer la lista de Links desde un archivo
void Links::leerDesdeArchivo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo) {
        cerr << "Error al abrir el archivo para lectura." << endl;
        return;
    }

    links_archivo.clear();  // Limpiar la lista antes de cargar datos nuevos

    int id, idAlbum, idVersion, idCancion;
    string nomPlat, linkAlbum, linkCancion;
    while (archivo >> id) { // Leer ID
        archivo.ignore();
        archivo >> idCancion;
        archivo.ignore();
        archivo >> idAlbum;
        archivo.ignore();
        archivo >> idVersion;
        archivo.ignore();
        getline(archivo, nomPlat, ',');
        getline(archivo, linkAlbum, ',');
        getline(archivo, linkCancion);

        links_archivo.push_back(Links(id,idCancion,idAlbum, idVersion, nomPlat, linkAlbum, linkCancion));
    }

    archivo.close();
}


void Links::eliminarDeArchivo(const string& nombreArchivo) {
    int idEliminar;
    cout << "Ingrese el ID del link que desea eliminar: ";
    cin >> idEliminar;

    bool encontrado = false;
    for (size_t i = 1; i <= links_archivo.size(); i++) {
        if (links_archivo[i].getId() == idEliminar) {
            encontrado = true;
            cout << "Está seguro de eliminar el siguiente link? (y/n)\n";
            cout << "ID: " << links_archivo[i].getId() << "\n"
                 << "ID Álbum: " << links_archivo[i].getIdAlbum() << "\n"
                 << "ID Versión: " << links_archivo[i].getIdVersion() << "\n"
                 << "ID Canción: " << links_archivo[i].getIdCancion() << "\n"  // 🔹 Nuevo campo
                 << "Plataforma: " << links_archivo[i].getNomPlat() << "\n"
                 << "Link Álbum: " << links_archivo[i].getLinkAlbum() << "\n"
                 << "Link Canción: " << links_archivo[i].getLinkCancion() << "\n";

            char confirmacion;
            cout << "Confirmar eliminación (y/n): ";
            cin >> confirmacion;

            if (confirmacion == 'y' || confirmacion == 'Y') {
                links_archivo.erase(i);  // Eliminar de la lista
                cout << "Link eliminado con éxito.\n";
            } else {
                cout << "Eliminación cancelada.\n";
            }
            break;
        }
    }

    if (!encontrado) {
        cout << "No se encontró un link con el ID especificado.\n";
        return;
    }

    // Guardar la lista actualizada en el archivo
    guardarEnArchivo(nombreArchivo);
}

void Links::actualizarDesdeArchivo(const string& nombreArchivo) {
    int idEditar;
    cout << "Ingrese el ID del link que desea editar: ";
    cin >> idEditar;

    bool encontrado = false;
    for (size_t i = 1; i <= links_archivo.size(); i++) {
        if (links_archivo[i].getId() == idEditar) {
            encontrado = true;
            cout << "Link encontrado. Datos actuales:\n";
            cout << "1. ID: " << links_archivo[i].getId() << "\n";
            cout << "2. ID Canción: " << links_archivo[i].getIdCancion() << "\n";
            cout << "3. ID Álbum: " << links_archivo[i].getIdAlbum() << "\n";
            cout << "4. ID Versión: " << links_archivo[i].getIdVersion() << "\n";
            cout << "5. Plataforma: " << links_archivo[i].getNomPlat() << "\n";
            cout << "6. Link Álbum: " << links_archivo[i].getLinkAlbum() << "\n";
            cout << "7. Link Canción: " << links_archivo[i].getLinkCancion() << "\n";

            int opcion;
            while (true) {
                cout << "Ingrese el número del atributo que desea modificar (0 para salir): ";
                cin >> opcion;
                cin.ignore(); // Limpiar buffer

                if (opcion == 0) {
                    cout << "Saliendo del modo de edición...\n";
                    break;
                }

                switch (opcion) {
                    case 1: {
                        int nuevoId;
                        cout << "Nuevo ID: ";
                        cin >> nuevoId;
                        links_archivo[i].setId(nuevoId);
                        break;
                    }
                    case 2: {
                        int nuevoIdCancion;
                        cout << "Nuevo ID de la canción: ";
                        cin >> nuevoIdCancion;
                        links_archivo[i].setIdCancion(nuevoIdCancion);
                        break;
                    }
                    case 3: {
                        int nuevoIdAlbum;
                        cout << "Nuevo ID del álbum: ";
                        cin >> nuevoIdAlbum;
                        links_archivo[i].setIdAlbum(nuevoIdAlbum);
                        break;
                    }
                    case 4: {
                        int nuevoIdVersion;
                        cout << "Nuevo ID de la versión: ";
                        cin >> nuevoIdVersion;
                        links_archivo[i].setIdVersion(nuevoIdVersion);
                        break;
                    }
                    case 5: {
                        string nuevaPlataforma;
                        cout << "Nuevo nombre de la plataforma: ";
                        getline(cin, nuevaPlataforma);
                        links_archivo[i].setNomPlat(nuevaPlataforma);
                        break;
                    }
                    case 6: {
                        string nuevoLinkAlbum;
                        cout << "Nuevo link del álbum: ";
                        getline(cin, nuevoLinkAlbum);
                        links_archivo[i].setLinkAlbum(nuevoLinkAlbum);
                        break;
                    }
                    case 7: {
                        string nuevoLinkCancion;
                        cout << "Nuevo link de la canción: ";
                        getline(cin, nuevoLinkCancion);
                        links_archivo[i].setLinkCancion(nuevoLinkCancion);
                        break;
                    }
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
        cout << "No se encontró un link con el ID especificado.\n";
        return;
    }

    // Guardar la lista actualizada en el archivo
    guardarEnArchivo(nombreArchivo);
}

Links Links::buscarLinkPorId(const string& nombreArchivoLinks) {
    int idBuscado;
    cout << "Ingrese el ID del link a buscar: ";
    cin >> idBuscado;

    MiVector<Links> listaLinks;
    leerDesdeArchivo(nombreArchivoLinks);

    // Buscar el link por ID
    for (size_t i = 1; i <= listaLinks.size(); i++) {
        if (listaLinks[i].getId() == idBuscado) {
            return listaLinks[i]; // Devuelve el link encontrado
        }
    }

    cout << "No se encontró un link con el ID especificado.\n";
    return Links(); // Devuelve un objeto vacío si no se encuentra
}
