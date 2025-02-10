#include "Librerias/Version.h"
#include <iostream>
#include <fstream>
#include "Librerias/Artista.h"
using namespace std;
MiVector<Version> versiones_archivo;
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
    versiones_archivo.push_back(version);
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
void Version::guardarEnArchivo(const string& nombreArchivo) {
    ofstream archivo(nombreArchivo);
    if (!archivo) {
        cerr << "Error al abrir el archivo para escritura." << endl;
        return;
    }

    for (size_t i = 1; i <= versiones_archivo.size(); i++) {
        archivo << versiones_archivo[i].getIdVersion() << ","
                << versiones_archivo[i].getIdCancion() << ","   
                << versiones_archivo[i].getTituloVer() << ","
                << versiones_archivo[i].getTipVersion() << ","
                << versiones_archivo[i].getAnio() << ","
                << versiones_archivo[i].getCiudadGrab() << ","
                << versiones_archivo[i].getPaisGra() << ","
                << versiones_archivo[i].getArtistaPrincipal() << ","
                << versiones_archivo[i].getGenero()  << endl;
    }

    archivo.close();
}


// Leer lista de versiones desde archivo
void Version::leerDesdeArchivo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo) {
        cerr << "Error al abrir el archivo para lectura." << endl;
        return;
    }

    versiones_archivo.clear();

    int id, idCancion, anio;
    string tituloVer, tipVersion, ArtistaPrin, ciudadGrab, paisGra, genero, arrMusic;

    while (archivo >> id) {
        archivo.ignore();
        archivo >> idCancion; archivo.ignore();
        getline(archivo, tituloVer, ',');
        getline(archivo, tipVersion, ',');
        archivo >> anio;
        archivo.ignore();
        getline(archivo, ciudadGrab, ',');
        getline(archivo, paisGra, ',');
        getline(archivo, genero, ',');

        versiones_archivo.push_back(Version(id, idCancion, tituloVer, tipVersion, ArtistaPrin, anio, ciudadGrab, paisGra, genero));
    }

    archivo.close();
}


// Método para eliminar una versión del archivo
void Version::eliminarDeArchivo(const string& nombreArchivo) {
    int idEliminar;
    cout << "Ingrese el ID de la versión que desea eliminar: ";
    cin >> idEliminar;

    bool encontrado = false;
    for (size_t i = 1; i <= versiones_archivo.size(); i++) {
        if (versiones_archivo[i].getIdVersion() == idEliminar) {
            encontrado = true;
            cout << "Está seguro de eliminar la siguiente versión? (y/n)\n";
            cout << "ID: " << versiones_archivo[i].getIdVersion() << "\n"
                 << "Título: " << versiones_archivo[i].getTituloVer() << "\n"
                 << "Tipo: " << versiones_archivo[i].getTipVersion() << "\n"
                 << "Año: " << versiones_archivo[i].getAnio() << "\n"
                 << "Ciudad Grabación: " << versiones_archivo[i].getCiudadGrab() << "\n"
                 << "País Grabación: " << versiones_archivo[i].getPaisGra() << "\n"
                 << "Género: " << versiones_archivo[i].getGenero() << "\n"
                 << "Arreglo Musical: " << versiones_archivo[i].getArtistaPrincipal() 
                 << "ID Cancion: " << versiones_archivo[i].getIdVersion() << "\n";

            char confirmacion;
            cout << "Confirmar eliminación (y/n): ";
            cin >> confirmacion;

            if (confirmacion == 'y' || confirmacion == 'Y') {
                versiones_archivo.erase(i);  // Eliminar de la lista
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
    guardarEnArchivo(nombreArchivo);
}

void Version::actualizarDesdeArchivo(const string& nombreArchivo) {
    int idEditar;
    cout << "Ingrese el ID de la versión que desea editar: ";
    cin >> idEditar;

    bool encontrado = false;
    for (size_t i = 1; i <= versiones_archivo.size(); i++) {
        if (versiones_archivo[i].getIdVersion() == idEditar) {
            encontrado = true;
            cout << "Versión encontrada. Datos actuales:\n";
            cout << "1. ID de la versión: " << versiones_archivo[i].getIdVersion() << "\n";
            cout << "2. ID de la canción: " << versiones_archivo[i].getIdCancion() << "\n";
            cout << "3. Título: " << versiones_archivo[i].getTituloVer() << "\n";
            cout << "4. Tipo de Versión: " << versiones_archivo[i].getTipVersion() << "\n";
            cout << "5. Año: " << versiones_archivo[i].getAnio() << "\n";
            cout << "6. Ciudad de Grabación: " << versiones_archivo[i].getCiudadGrab() << "\n";
            cout << "7. País de Grabación: " << versiones_archivo[i].getPaisGra() << "\n";
            cout << "8. Género: " << versiones_archivo[i].getGenero() << "\n";
            cout << "9. Artista Principal: " << versiones_archivo[i].getArtistaPrincipal() << "\n";

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
                        versiones_archivo[i].setIdVersion(nuevoId);
                        break;
                    case 2:
                        cout << "Nuevo ID de la canción: ";
                        cin >> nuevoId;
                        versiones_archivo[i].setIdCancion(nuevoId);
                        break;
                    case 3:
                        cout << "Nuevo título: ";
                        getline(cin, nuevoValor);
                        versiones_archivo[i].setTituloVer(nuevoValor);
                        break;
                    case 4:
                        cout << "Nuevo tipo de versión: ";
                        getline(cin, nuevoValor);
                        versiones_archivo[i].setTipVersion(nuevoValor);
                        break;
                    case 5:
                        cout << "Nuevo año de publicación: ";
                        cin >> nuevoAnio;
                        versiones_archivo[i].setAnio(nuevoAnio);
                        cin.ignore(); // Limpiar buffer
                        break;
                    case 6:
                        cout << "Nueva ciudad de grabación: ";
                        getline(cin, nuevoValor);
                        versiones_archivo[i].setCiudadGrab(nuevoValor);
                        break;
                    case 7:
                        cout << "Nuevo país de grabación: ";
                        getline(cin, nuevoValor);
                        versiones_archivo[i].setPaisGra(nuevoValor);
                        break;
                    case 8:
                        cout << "Nuevo género: ";
                        getline(cin, nuevoValor);
                        versiones_archivo[i].setGenero(nuevoValor);
                        break;
                    case 9:
                        cout << "Nuevo artista principal: ";
                        getline(cin, nuevoValor);
                        versiones_archivo[i].setArtistaPrincipal(nuevoValor);
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
    guardarEnArchivo(nombreArchivo);
    cout << "Los cambios han sido guardados correctamente en el archivo.\n";
}

Version Version::buscarVersionConRelacionados(const string& nombreArchivoVersion,  
    const string& nombreArchivoLinks,  
    const string& nombreArchivoArtistas,  
    MiVector<Links>& listaLinks,  
    MiVector<Artista>& listaArtistas)  
{  
    int idBuscado;  
    cout << "Ingrese el ID de la versión a buscar: ";  
    cin >> idBuscado;  

    MiVector<Version> listaVersiones;  
    leerDesdeArchivo(nombreArchivoVersion);  

    Version versionEncontrada;  
    bool encontrado = false;  

    // Buscar la versión por ID  
    for (size_t i = 1; i <= listaVersiones.size(); i++) {  
        if (listaVersiones[i].getIdVersion() == idBuscado) {  
            versionEncontrada = listaVersiones[i];  
            encontrado = true;  
            break;  
        }  
    }  

    if (!encontrado) {  
        cout << "No se encontró una versión con el ID especificado.\n";  
        return Version();  
    }  

    // Leer registros de Links  
    MiVector<Links> todosLosLinks;  
    Links::leerDesdeArchivo(nombreArchivoLinks);  

    // Filtrar los links relacionados con esta versión  
    listaLinks.clear();  
    for (size_t i = 1; i <= todosLosLinks.size(); i++) {  
        if (todosLosLinks[i].getIdVersion() == idBuscado) {  
            listaLinks.push_back(todosLosLinks[i]);  
        }  
    }  

    // Leer registros de Artistas  
    MiVector<Artista> todosLosArtistas;  
    Artista::leerDesdeArchivo(nombreArchivoArtistas);  

    // Filtrar los artistas relacionados con esta versión  
    listaArtistas.clear();  
    for (size_t i = 1; i <= todosLosArtistas.size(); i++) {  
        if (todosLosArtistas[i].getIdVersion() == idBuscado) {  
            listaArtistas.push_back(todosLosArtistas[i]);  
        }  
    }  

    return versionEncontrada;  
}
