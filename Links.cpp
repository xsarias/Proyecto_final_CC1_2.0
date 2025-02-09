#include <iostream>
#include <fstream>
#include "Librerias/Links.h"
#include "Librerias/MiVector.h"

nodo_links Links::insertar_link(Links links) {

    nodo_links nuevo_link;
    nuevo_link.id = links.id;
    nuevo_link.link_album = links.linkAlbum;
    nuevo_link.link_cancion = links.linkCancion;
    nuevo_link.nom_plat = links.nomPlat;

    return nuevo_link;
}

// Método para guardar la lista de Links en un archivo
void Links::guardarEnArchivo(const string& nombreArchivo, const MiVector<Links>& lista) {
    ofstream archivo(nombreArchivo);
    if (!archivo) {
        cerr << "Error al abrir el archivo para escritura." << endl;
        return;
    }

    for (size_t i = 1; i <= lista.size(); i++) {  // Desde 1 por la estructura de MiVector
        archivo << lista[i].getId() << ","
                << lista[i].getIdAlbum() << ","
                << lista[i].getIdVersion() << ","
                << lista[i].getIdCancion() << ","  
                << lista[i].getNomPlat() << ","
                << lista[i].getLinkAlbum() << ","
                << lista[i].getLinkCancion() << endl;
    }

    archivo.close();
}


// Método para leer la lista de Links desde un archivo
void Links::leerDesdeArchivo(const string& nombreArchivo, MiVector<Links>& lista) {
    ifstream archivo(nombreArchivo);
    if (!archivo) {
        cerr << "Error al abrir el archivo para lectura." << endl;
        return;
    }

    lista.clear();  // Limpiar la lista antes de cargar datos nuevos

    int id, idAlbum, idVersion, idCancion;
    string nomPlat, linkAlbum, linkCancion;
    while (archivo >> id) { // Leer ID
        archivo.ignore();
        archivo >> idAlbum;
        archivo.ignore();
        archivo >> idVersion;
        archivo.ignore();
        archivo >> idCancion;  // 🔹 Nuevo campo
        archivo.ignore();
        getline(archivo, nomPlat, ',');
        getline(archivo, linkAlbum, ',');
        getline(archivo, linkCancion);

        lista.push_back(Links(id, idAlbum, idVersion, idCancion, nomPlat, linkAlbum, linkCancion));
    }

    archivo.close();
}


void Links::eliminarDeArchivo(const string& nombreArchivo, MiVector<Links>& lista) {
    int idEliminar;
    cout << "Ingrese el ID del link que desea eliminar: ";
    cin >> idEliminar;

    bool encontrado = false;
    for (size_t i = 1; i <= lista.size(); i++) {
        if (lista[i].getId() == idEliminar) {
            encontrado = true;
            cout << "Está seguro de eliminar el siguiente link? (y/n)\n";
            cout << "ID: " << lista[i].getId() << "\n"
                 << "ID Álbum: " << lista[i].getIdAlbum() << "\n"
                 << "ID Versión: " << lista[i].getIdVersion() << "\n"
                 << "ID Canción: " << lista[i].getIdCancion() << "\n"  // 🔹 Nuevo campo
                 << "Plataforma: " << lista[i].getNomPlat() << "\n"
                 << "Link Álbum: " << lista[i].getLinkAlbum() << "\n"
                 << "Link Canción: " << lista[i].getLinkCancion() << "\n";

            char confirmacion;
            cout << "Confirmar eliminación (y/n): ";
            cin >> confirmacion;

            if (confirmacion == 'y' || confirmacion == 'Y') {
                lista.erase(i);  // Eliminar de la lista
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
    guardarEnArchivo(nombreArchivo, lista);
}

void Links::actualizarDesdeArchivo(const string& nombreArchivo, MiVector<Links>& lista) {
    int idEditar;
    cout << "Ingrese el ID del link que desea editar: ";
    cin >> idEditar;

    bool encontrado = false;
    for (size_t i = 1; i <= lista.size(); i++) {
        if (lista[i].getId() == idEditar) {
            encontrado = true;
            cout << "Link encontrado. Datos actuales:\n";
            cout << "1. ID Canción: " << lista[i].getIdCancion() << "\n";  // 🔹 Nuevo campo
            cout << "2. Plataforma: " << lista[i].getNomPlat() << "\n";
            cout << "3. Link Álbum: " << lista[i].getLinkAlbum() << "\n";
            cout << "4. Link Canción: " << lista[i].getLinkCancion() << "\n";

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
                switch (opcion) {
                    case 1:
                        int nuevoIdCancion;
                        cout << "Nuevo ID de la canción: ";
                        cin >> nuevoIdCancion;
                        lista[i].setIdCancion(nuevoIdCancion);  // 🔹 Nuevo campo
                        break;
                    case 2:
                        cout << "Nuevo nombre de plataforma: ";
                        getline(cin, nuevoValor);
                        lista[i].setNomPlat(nuevoValor);
                        break;
                    case 3:
                        cout << "Nuevo link del álbum: ";
                        getline(cin, nuevoValor);
                        lista[i].setLinkAlbum(nuevoValor);
                        break;
                    case 4:
                        cout << "Nuevo link de la canción: ";
                        getline(cin, nuevoValor);
                        lista[i].setLinkCancion(nuevoValor);
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
        cout << "No se encontró un link con el ID especificado.\n";
        return;
    }

    // Guardar la lista actualizada en el archivo
    guardarEnArchivo(nombreArchivo, lista);
}


