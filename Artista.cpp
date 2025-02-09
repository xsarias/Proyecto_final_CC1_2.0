#include <iostream>
#include <fstream>
#include "Librerias/Artista.h"
void Artista::imprimir_artista(Artista artista){
    cout << artista.nom_real << endl;
    cout << artista.nom_artist << endl;
    cout << artista.pais_origen << endl;
    cout << artista.instrum_inter << endl;
}
nodo_artistas Artista :: insertar_artista(Artista artista){
    nodo_artistas artista_nuevo;
    artista_nuevo.id_cancion = artista.id_cancion;
    artista_nuevo.id_version = artista.id_version;
    artista_nuevo.nom_artistico = artista.nom_artist;
    artista_nuevo.nom_real = artista.nom_real;
    artista_nuevo.pais_origen = artista.pais_origen;
    artista_nuevo.instru_interpre = artista.instrum_inter;
    return artista_nuevo;
}

// Método para guardar la lista de Artistas en un archivo
void Artista::guardarEnArchivo(const string& nombreArchivo, const MiVector<Artista>& lista) {
    ofstream archivo(nombreArchivo);
    if (!archivo) {
        cerr << "Error al abrir el archivo para escritura." << endl;
        return;
    }

    for (size_t i = 1; i <= lista.size(); i++) {
        archivo << lista[i].getId() << ","
                << lista[i].getIdCancion() << ","
                << lista[i].getIdVersion() << ","
                << lista[i].getNomReal() << ","
                << lista[i].getNomArtist() << ","
                << lista[i].getPaisOrigen() << ","
                << lista[i].getInstrumInter() << endl;
    }

    archivo.close();
}

// Método para leer la lista de Artistas desde un archivo
void Artista::leerDesdeArchivo(const string& nombreArchivo, MiVector<Artista>& lista) {
    ifstream archivo(nombreArchivo);
    if (!archivo) {
        cerr << "Error al abrir el archivo para lectura." << endl;
        return;
    }

    lista.clear();

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

        lista.push_back(Artista(id, id_cancion, id_version, nomReal, nomArtist, paisOrigen, instrumInter));
    }

    archivo.close();
}

// Método para eliminar un Artista del archivo
void Artista::eliminarDeArchivo(const string& nombreArchivo, MiVector<Artista>& lista) {
    int idEliminar;
    cout << "Ingrese el ID del artista que desea eliminar: ";
    cin >> idEliminar;

    bool encontrado = false;
    for (size_t i = 1; i <= lista.size(); i++) {
        if (lista[i].getId() == idEliminar) {
            encontrado = true;
            cout << "Está seguro de eliminar el siguiente artista? (y/n)\n";
            cout << "ID: " << lista[i].getId() << "\n"
                 << "ID Canción: " << lista[i].getIdCancion() << "\n"
                 << "ID Versión: " << lista[i].getIdVersion() << "\n"
                 << "Nombre real: " << lista[i].getNomReal() << "\n"
                 << "Nombre artístico: " << lista[i].getNomArtist() << "\n"
                 << "País de origen: " << lista[i].getPaisOrigen() << "\n"
                 << "Instrumento principal: " << lista[i].getInstrumInter() << "\n";

            char confirmacion;
            cout << "Confirmar eliminación (y/n): ";
            cin >> confirmacion;

            if (confirmacion == 'y' || confirmacion == 'Y') {
                lista.erase(i);  // Eliminar de la lista
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
    guardarEnArchivo(nombreArchivo, lista);
}
