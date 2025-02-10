#include "Librerias/Version.h"
#include <iostream>
#include <fstream>
#include "Librerias/Artista.h"
using namespace std;

void Version::insertar_cabeceras() {
    multi_version.insertar(titulo_ver);
    multi_version.insertar(tipoVers);
    multi_version.insertar(anioPub);
    multi_version.insertar(paisGrab);
    multi_version.insertar(artistaPrinc);
    multi_version.insertar(ciudad_Grab);
    multi_version.insertar(genero_ver);
}

nodo_versiones Version::insertar_version(Version version, MiVector<Artista> artistas_version, MiVector<Links> links_version) {
    nodo_versiones version_nueva;
    version_nueva.id = version.idVersion;
    version_nueva.id_cancion = version.idCancion;
    version_nueva.titulos = version.tituloVer;
    version_nueva.tipo_version = version.tipVersion;
    version_nueva.anio_pub = version.anio;
    version_nueva.pais_grab = version.paisGra;
    version_nueva.artista_princ = version.artistaPrin;
    version_nueva.ciudad_grab = version.ciudadGrab;
    version_nueva.genero = version.genero;
    for(int i=1; i<= artistas_version.size(); i++){
        version_nueva.lista_artistas.push_back(artistas_version[i].insertar_artista(artistas_version[i]));
    }
    for(int i=1; i<= links_version.size(); i++){
        version_nueva.lista_links.push_back(links_version[i].insertar_link(links_version[i]));
    }
    multi_version.insertar(version_nueva);
    //cout<< "version insertada";
    return version_nueva;
}

// Guardar lista de versiones en archivo
void Version::guardarEnArchivo(const string& nombreArchivo, const MiVector<Version>& lista) {
    ofstream archivo(nombreArchivo);
    if (!archivo) {
        cerr << "Error al abrir el archivo para escritura." << endl;
        return;
    }

    for (size_t i = 1; i <= lista.size(); i++) {
        archivo << lista[i].getIdVersion() << ","
                << lista[i].getIdCancion() << ","   
                << lista[i].getTituloVer() << ","
                << lista[i].getTipVersion() << ","
                << lista[i].getAnio() << ","
                << lista[i].getCiudadGrab() << ","
                << lista[i].getPaisGra() << ","
                << lista[i].getArtistaPrincipal() << ","
                << lista[i].getGenero()  << endl;
    }

    archivo.close();
}

// Leer lista de versiones desde archivo
void Version::leerDesdeArchivo(const string& nombreArchivo, MiVector<Version>& lista) {
    ifstream archivo(nombreArchivo);
    if (!archivo) {
        cerr << "Error al abrir el archivo para lectura." << endl;
        return;
    }

    lista.clear();

    int id, idCancion, idAlbum, anio;
    string tituloVer, tipVersion, ArtistaPrin, ciudadGrab, paisGra, genero, arrMusic;

    while (archivo >> id) {
        archivo.ignore();
        archivo >> idCancion; archivo.ignore(); // Leer idCancion
        archivo >> idAlbum; archivo.ignore();   // Leer idAlbum
        getline(archivo, tituloVer, ',');
        getline(archivo, tipVersion, ',');
        archivo >> anio;
        archivo.ignore();
        getline(archivo, ciudadGrab, ',');
        getline(archivo, paisGra, ',');
        getline(archivo, genero, ',');

        lista.push_back(Version(id, idCancion, tituloVer, tipVersion, ArtistaPrin, anio, ciudadGrab, paisGra, genero));
    }

    archivo.close();
}

// Método para eliminar una versión del archivo
void Version::eliminarDeArchivo(const string& nombreArchivo, MiVector<Version>& lista) {
    int idEliminar;
    cout << "Ingrese el ID de la versión que desea eliminar: ";
    cin >> idEliminar;

    bool encontrado = false;
    for (size_t i = 1; i <= lista.size(); i++) {
        if (lista[i].getIdVersion() == idEliminar) {
            encontrado = true;
            cout << "Está seguro de eliminar la siguiente versión? (y/n)\n";
            cout << "ID: " << lista[i].getIdVersion() << "\n"
                 << "Título: " << lista[i].getTituloVer() << "\n"
                 << "Tipo: " << lista[i].getTipVersion() << "\n"
                 << "Año: " << lista[i].getAnio() << "\n"
                 << "Ciudad Grabación: " << lista[i].getCiudadGrab() << "\n"
                 << "País Grabación: " << lista[i].getPaisGra() << "\n"
                 << "Género: " << lista[i].getGenero() << "\n"
                 << "Arreglo Musical: " << lista[i].getArtistaPrincipal() 
                 << "ID Cancion: " << lista[i].getIdVersion() << "\n";

            char confirmacion;
            cout << "Confirmar eliminación (y/n): ";
            cin >> confirmacion;

            if (confirmacion == 'y' || confirmacion == 'Y') {
                lista.erase(i);  // Eliminar de la lista
                cout << "Versión eliminada con éxito.\n";
            } else {
                cout << "Eliminación cancelada.\n";
            }
            break;
        }
    }

    if (!encontrado) {
        cout << "No se encontró una versión con el ID especificado.\n";
        return;
    }

    // Guardar la lista actualizada en el archivo
    guardarEnArchivo(nombreArchivo, lista);
}

void Version::actualizarDesdeArchivo(const string& nombreArchivo, MiVector<Version>& lista) {
    int idEditar;
    cout << "Ingrese el ID de la versión que desea editar: ";
    cin >> idEditar;

    bool encontrado = false;
    for (size_t i = 1; i <= lista.size(); i++) {
        if (lista[i].getIdVersion() == idEditar) {
            encontrado = true;
            cout << "Versión encontrada. Datos actuales:\n";
            cout << "1. ID de la versión: " << lista[i].getIdVersion() << "\n";
            cout << "2. ID de la canción: " << lista[i].getIdCancion() << "\n";
            cout << "3. Título: " << lista[i].getTituloVer() << "\n";
            cout << "4. Tipo de Versión: " << lista[i].getTipVersion() << "\n";
            cout << "5. Año: " << lista[i].getAnio() << "\n";
            cout << "6. Ciudad de Grabación: " << lista[i].getCiudadGrab() << "\n";
            cout << "7. País de Grabación: " << lista[i].getPaisGra() << "\n";
            cout << "8. Género: " << lista[i].getGenero() << "\n";
            cout << "9. Artista Principal: " << lista[i].getArtistaPrincipal() << "\n";

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
                        cout << "Nuevo ID de la versión: ";
                        cin >> nuevoId;
                        lista[i].setIdVersion(nuevoId);
                        break;
                    case 2:
                        cout << "Nuevo ID de la canción: ";
                        cin >> nuevoId;
                        lista[i].setIdCancion(nuevoId);
                        break;
                    case 3:
                        cout << "Nuevo título: ";
                        getline(cin, nuevoValor);
                        lista[i].setTituloVer(nuevoValor);
                        break;
                    case 4:
                        cout << "Nuevo tipo de versión: ";
                        getline(cin, nuevoValor);
                        lista[i].setTipVersion(nuevoValor);
                        break;
                    case 5:
                        cout << "Nuevo año de publicación: ";
                        cin >> nuevoAnio;
                        lista[i].setAnio(nuevoAnio);
                        cin.ignore(); // Limpiar buffer
                        break;
                    case 6:
                        cout << "Nueva ciudad de grabación: ";
                        getline(cin, nuevoValor);
                        lista[i].setCiudadGrab(nuevoValor);
                        break;
                    case 7:
                        cout << "Nuevo país de grabación: ";
                        getline(cin, nuevoValor);
                        lista[i].setPaisGra(nuevoValor);
                        break;
                    case 8:
                        cout << "Nuevo género: ";
                        getline(cin, nuevoValor);
                        lista[i].setGenero(nuevoValor);
                        break;
                    case 9:
                        cout << "Nuevo artista principal: ";
                        getline(cin, nuevoValor);
                        lista[i].setArtistaPrincipal(nuevoValor);
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
        cout << "No se encontró una versión con el ID especificado.\n";
        return;
    }

    // Guardar la lista actualizada en el archivo
    guardarEnArchivo(nombreArchivo, lista);
    cout << "Los cambios han sido guardados correctamente en el archivo.\n";
}
