#include <iostream>
#include <fstream>
#include "Librerias/Artista.h"
MiVector<Artista>artistas_archivo;
void Artista::imprimir_artista(Artista artista){
    cout << artista.nom_real << endl;
    cout << artista.nom_artist << endl;
    cout << artista.pais_origen << endl;
    cout << artista.instrum_inter << endl;
}
nodo_artistas Artista :: insertar_artista(Artista artista){
    artistas_archivo.push_back(artista);
    nodo_artistas artista_nuevo;
    artista_nuevo.id = artista.id;
    artista_nuevo.id_cancion = artista.id_cancion;
    artista_nuevo.id_version = artista.id_version;
    artista_nuevo.nom_artistico = artista.nom_artist;
    artista_nuevo.nom_real = artista.nom_real;
    artista_nuevo.pais_origen = artista.pais_origen;
    artista_nuevo.instru_interpre = artista.instrum_inter;
    //cout<<"artista insertado"<<endl;
    return artista_nuevo;
}

// Método para guardar la lista de Artistas en un archivo
void Artista::guardarEnArchivo(const string& nombreArchivo) {
    ofstream archivo(nombreArchivo);
    if (!archivo) {
        cerr << "Error al abrir el archivo para escritura." << endl;
        return;
    }

    for (int i = 1; i <= artistas_archivo.size(); i++) {
        archivo << artistas_archivo[i].getId() << ","
                << artistas_archivo[i].getIdCancion() << ","
                << artistas_archivo[i].getIdVersion() << ","
                << artistas_archivo[i].getNomReal() << ","
                << artistas_archivo[i].getNomArtist() << ","
                << artistas_archivo[i].getPaisOrigen() << ","
                << artistas_archivo[i].getInstrumInter() << endl;
    }

    archivo.close();
}

// Método para leer la lista de Artistas desde un archivo
void Artista::leerDesdeArchivo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo) {
        cerr << "Error al abrir el archivo para lectura." << endl;
        return;
    }

    artistas_archivo.clear();

    int id, id_cancion, id_version;
    string nomReal, nomArtist, paisOrigen, instrumInter;
    while (archivo >> id) {
        archivo.ignore();
        archivo >> id_cancion;
        archivo.ignore();
        archivo >> id_version;
        archivo.ignore();
        getline(archivo, nomReal, ',');
        getline(archivo, nomArtist, ',');
        getline(archivo, paisOrigen, ',');
        getline(archivo, instrumInter);

        artistas_archivo.push_back(Artista(id, id_cancion, id_version, nomReal, nomArtist, paisOrigen, instrumInter));
    }

    archivo.close();
}

// Método para eliminar un Artista del archivo
void Artista::eliminarDeArchivo(const string& nombreArchivo) {
    int idEliminar;
    cout << "Ingrese el ID del artista que desea eliminar: ";
    cin >> idEliminar;

    bool encontrado = false;
    for (size_t i = 1; i <= artistas_archivo.size(); i++) {
        if (artistas_archivo[i].getId() == idEliminar) {
            encontrado = true;
            cout << "Está seguro de eliminar el siguiente artista? (y/n)\n";
            cout << "ID: " << artistas_archivo[i].getId() << "\n"
                 << "ID Canción: " << artistas_archivo[i].getIdCancion() << "\n"
                 << "ID Versión: " << artistas_archivo[i].getIdVersion() << "\n"
                 << "Nombre real: " << artistas_archivo[i].getNomReal() << "\n"
                 << "Nombre artístico: " << artistas_archivo[i].getNomArtist() << "\n"
                 << "País de origen: " << artistas_archivo[i].getPaisOrigen() << "\n"
                 << "Instrumento principal: " << artistas_archivo[i].getInstrumInter() << "\n";

            char confirmacion;
            cout << "Confirmar eliminación (y/n): ";
            cin >> confirmacion;

            if (confirmacion == 'y' || confirmacion == 'Y') {
                artistas_archivo.erase(i);  // Eliminar de la lista
                cout << "Artista eliminado con éxito.\n";
            } else {
                cout << "Eliminación cancelada.\n";
            }
            break;
        }
    }

    if (!encontrado) {
        cout << "No se encontró un artista con el ID especificado.\n";
        return;
    }

    // Guardar la lista actualizada en el archivo
    guardarEnArchivo(nombreArchivo);
}


void Artista::actualizarDesdeArchivo(const string& nombreArchivo) {
    int idEditar;
    cout << "Ingrese el ID del artista que desea editar: ";
    cin >> idEditar;

    bool encontrado = false;
    for (size_t i = 1; i <= artistas_archivo.size(); i++) {
        if (artistas_archivo[i].getId() == idEditar) {
            encontrado = true;
            cout << "Artista encontrado. Datos actuales:\n";
            cout << "1. ID Canción: " << artistas_archivo[i].getIdCancion() << "\n";
            cout << "2. ID Versión: " << artistas_archivo[i].getIdVersion() << "\n";
            cout << "3. Nombre real: " << artistas_archivo[i].getNomReal() << "\n";
            cout << "4. Nombre artístico: " << artistas_archivo[i].getNomArtist() << "\n";
            cout << "5. País de origen: " << artistas_archivo[i].getPaisOrigen() << "\n";
            cout << "6. Instrumento principal: " << artistas_archivo[i].getInstrumInter() << "\n";

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
                        cout << "Nuevo ID Canción: ";
                        cin >> nuevoValor;
                        artistas_archivo[i].setIdCancion(stoi(nuevoValor));
                        break;
                    case 2:
                        cout << "Nuevo ID Versión: ";
                        cin >> nuevoValor;
                        artistas_archivo[i].setIdVersion(stoi(nuevoValor));
                        break;
                    case 3:
                        cout << "Nuevo nombre real: ";
                        getline(cin, nuevoValor);
                        artistas_archivo[i].setNomReal(nuevoValor);
                        break;
                    case 4:
                        cout << "Nuevo nombre artístico: ";
                        getline(cin, nuevoValor);
                        artistas_archivo[i].setNomArtist(nuevoValor);
                        break;
                    case 5:
                        cout << "Nuevo país de origen: ";
                        getline(cin, nuevoValor);
                        artistas_archivo[i].setPaisOrigen(nuevoValor);
                        break;
                    case 6:
                        cout << "Nuevo instrumento principal: ";
                        getline(cin, nuevoValor);
                        artistas_archivo[i].setInstrumInter(nuevoValor);
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
        cout << "No se encontró un artista con el ID especificado.\n";
        return;
    }

    // Guardar la lista actualizada en el archivo
    guardarEnArchivo(nombreArchivo);
    cout << "Los cambios han sido guardados correctamente en el archivo.\n";
}

Artista Artista::buscarArtistaPorId(const string& nombreArchivoArtistas) {
    int idBuscado;
    cout << "Ingrese el ID del artista a buscar: ";
    cin >> idBuscado;

    MiVector<Artista> listaArtistas;
    leerDesdeArchivo(nombreArchivoArtistas);

    // Buscar el artista por ID
    for (size_t i = 1; i <= listaArtistas.size(); i++) {
        if (listaArtistas[i].getId() == idBuscado) {
            return listaArtistas[i]; // Devuelve el artista encontrado
        }
    }

    cout << "No se encontró un artista con el ID especificado.\n";
    return Artista(); // Devuelve un objeto vacío si no se encuentra
}
