#include "Librerias/Cancion.h"
#include <iostream>
#include <fstream>
#include "Librerias/MiVector.h"

void Cancion :: imprimir_lista(string parametro, int pos_cab) {
    // Obtener la posición inicial de la cabeza para el orden del parámetro
    int cab = multi_cancion.retornar_pos(pos_cab, "pos_cabeza");
    int cont;
    if (cab < 0) {
        cout << "La lista está vacía o no se ha ordenado." << endl;
        return;
    }
    cout << "Lista de " << multi_cancion.retornar_dato(pos_cab, "nombreCabeza") << ":" << endl;
    int pos_actual=cab;
    cont= 1;
    while (pos_actual != 0){
        // Obtener y mostrar el nombre de la canción actual
        string caracteristica = multi_cancion.retornar_dato(pos_actual, parametro);
        cout << cont << "). Nombre canción: " << multi_cancion.retornar_dato(pos_actual, "nom_cancion") << endl;
        cout << parametro << " -> " << caracteristica << endl;
        cont++;

        // Pasar al siguiente elemento en la lista
        if (parametro == "nombre_artistico") {
            pos_actual = multi_cancion.retornar_pos(pos_actual, "sig_nombre_artistico");
        } else if (parametro == "anio") {
            pos_actual = multi_cancion.retornar_pos(pos_actual, "sig_anio");
        } else if (parametro == "nombre_cancion") {
            pos_actual = multi_cancion.retornar_pos(pos_actual, "sig_cancion");
        } else if (parametro == "compositor") {
            pos_actual = multi_cancion.retornar_pos(pos_actual, "sig_compositor");
        } else if (parametro == "interprete") {
            pos_actual = multi_cancion.retornar_pos(pos_actual, "sig_interprete");
        } else if(parametro == "duracion"){
            pos_actual=multi_cancion.retornar_pos(pos_actual,"duracion" );
        }else{
            cout << "Parámetro no válido." << endl;
            break;
        }
    }
}
void  Cancion :: insertar_cabeceras(){
    //Posición de las cabezas
    multi_cancion.insertar(nombre_artis);//1
    multi_cancion.insertar(nom_cancion);//2
    multi_cancion.insertar(comp_let);  //3
    multi_cancion.insertar(comp_music);  //4
    multi_cancion.insertar(pais); //5
    multi_cancion.insertar(ciudad);  //6
    multi_cancion.insertar(genero_); //7
    multi_cancion.insertar(anio_pub); //8
    multi_cancion.insertar(duracion_can);

}
nodo_canciones  Cancion :: insertar_cancion(Cancion cancion, MiVector<Links> links, MiVector<Artista> artista, MiVector<nodo_versiones> version){
    nodo_canciones cancion_nueva;
    cancion_nueva.id = cancion.id;
    cancion_nueva.id_album = cancion.id_album;
    cancion_nueva.nom_cancion = cancion.nombreCancion;
    cancion_nueva.nom_artistico = cancion.nom_artistico;
    cancion_nueva.arrMusic = cancion.arrMusic;
    cancion_nueva.anioPublicacion = cancion.anioPublicacion;
    cancion_nueva.arrMusic = cancion.arrMusic;
    cancion_nueva.ciudadGrabacion = cancion.ciudadGrabacion;
    cancion_nueva.composLetra = cancion.ciudadGrabacion;
    cancion_nueva.composMusica = cancion.composLetra;
    cancion_nueva.duracion = cancion.duracion; 
    cancion_nueva.genero = cancion.genero;
    cancion_nueva.numArtistasPrincipales = cancion.numArtistasPrincipales;
    for(int i=1; i<=artista.size(); i++){
        cancion_nueva.list_artist.push_back(artista[i].insertar_artista(artista[i]));
    }
    for(int i=1; i<=links.size(); i++){
        cancion_nueva.list_links.push_back(links[i].insertar_link(links[i]));
    }
    if(version.size()>0){
        for(int i=1; i<=version.size(); i++){
            cancion_nueva.list_versiones.push_back(version[i]);
        }
    }
    
    multi_cancion.insertar(cancion_nueva);
    cout<<"canción insertada"<<endl;
    return cancion_nueva;
}
// Método para guardar la lista de Canciones en un archivo
void Cancion::guardarEnArchivo(const string& nombreArchivo, const MiVector<Cancion>& lista) {
    ofstream archivo(nombreArchivo);
    if (!archivo) {
        cerr << "Error al abrir el archivo para escritura." << endl;
        return;
    }

    for (size_t i = 1; i <= lista.size(); i++) {
        archivo << lista[i].getId() << ","
                << lista[i].getNombreCancion() << ","
                << lista[i].getNomArtistico() << ","
                << lista[i].getGenero() << ","
                << lista[i].getAnioPublicacion() << ","
                << lista[i].getDuracion() << endl;
    }

    archivo.close();
}

// Método para leer la lista de Canciones desde un archivo
void Cancion::leerDesdeArchivo(const string& nombreArchivo, MiVector<Cancion>& lista) {
    ifstream archivo(nombreArchivo);
    if (!archivo) {
        cerr << "Error al abrir el archivo para lectura." << endl;
        return;
    }

    lista.clear();
    int id, id_album, anioPublicacion;
    string nombreCancion, nomArtistico, genero, duracion;
    int numArtistasPrincipales;  
    string composLetra;  
    string composMusica;  
    string arrMusic;  
    string ciudadGrabacion; 
    string paisGrabacion; 
    while (archivo >> id) {
        archivo.ignore();
        getline(archivo, nombreCancion, ',');
        getline(archivo, nomArtistico, ',');
        getline(archivo, genero, ',');
        archivo >> anioPublicacion;
        archivo.ignore();
        getline(archivo, duracion);
        lista.push_back(Cancion(id, id_album, nombreCancion, nomArtistico, genero, anioPublicacion, duracion,composLetra, composMusica, arrMusic, ciudadGrabacion, paisGrabacion, numArtistasPrincipales));
    }

    archivo.close();
}

void Cancion::eliminarDeArchivo(const string& nombreArchivo, MiVector<Cancion>& lista) {
    int idEliminar;
    cout << "Ingrese el ID de la canción que desea eliminar: ";
    cin >> idEliminar;

    bool encontrado = false;
    for (size_t i = 1; i <= lista.size(); i++) {
        if (lista[i].getId() == idEliminar) {
            encontrado = true;
            cout << "Está seguro de eliminar la siguiente canción? (y/n)\n";
            cout << "ID: " << lista[i].getId() << "\n"
                 << "Nombre: " << lista[i].getNombreCancion() << "\n"
                 << "Artista: " << lista[i].getNomArtistico() << "\n"
                 << "Género: " << lista[i].getGenero() << "\n"
                 << "Año de Publicación: " << lista[i].getAnioPublicacion() << "\n"
                 << "Duración: " << lista[i].getDuracion() << "\n";

            char confirmacion;
            cout << "Confirmar eliminación (y/n): ";
            cin >> confirmacion;

            if (confirmacion == 'y' || confirmacion == 'Y') {
                lista.erase(i);  // Eliminar de la lista
                cout << "Canción eliminada con éxito.\n";
            } else {
                cout << "Eliminación cancelada.\n";
            }
            break;
        }
    }

    if (!encontrado) {
        cout << "No se encontró una canción con el ID especificado.\n";
        return;
    }

    // Guardar la lista actualizada en el archivo
    guardarEnArchivo(nombreArchivo, lista);
}

void Cancion::actualizarDesdeArchivo(const string& nombreArchivo, MiVector<Cancion>& lista) {
    int idEditar;
    cout << "Ingrese el ID de la canción que desea editar: ";
    cin >> idEditar;

    bool encontrado = false;
    for (size_t i = 1; i <= lista.size(); i++) {
        if (lista[i].getId() == idEditar) {
            encontrado = true;
            cout << "Canción encontrada. Datos actuales:\n";
            cout << "1. ID Álbum: " << lista[i].getIdAlbum() << "\n";
            cout << "2. Nombre: " << lista[i].getNombreCancion() << "\n";
            cout << "3. Artista: " << lista[i].getNomArtistico() << "\n";
            cout << "4. Género: " << lista[i].getGenero() << "\n";
            cout << "5. Año de publicación: " << lista[i].getAnioPublicacion() << "\n";
            cout << "6. Duración: " << lista[i].getDuracion() << "\n";
            cout << "7. Número de artistas principales: " << lista[i].getNumArtistasPrincipales() << "\n";
            cout << "8. Compositor de la letra: " << lista[i].getComposLetra() << "\n";
            cout << "9. Compositor de la música: " << lista[i].getComposMusica() << "\n";
            cout << "10. Arreglista musical: " << lista[i].getArrMusic() << "\n";
            cout << "11. Ciudad de grabación: " << lista[i].getCiudadGrabacion() << "\n";
            cout << "12. País de grabación: " << lista[i].getPaisGrabacion() << "\n";

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
                int nuevoInt;
                switch (opcion) {
                    case 1:
                        cout << "Nuevo ID del álbum: ";
                        cin >> nuevoInt;
                        lista[i].setIdAlbum(nuevoInt);
                        break;
                    case 2:
                        cout << "Nuevo nombre de la canción: ";
                        getline(cin, nuevoValor);
                        lista[i].setNombre(nuevoValor);
                        break;
                    case 3:
                        cout << "Nuevo nombre del artista: ";
                        getline(cin, nuevoValor);
                        lista[i].setNomArtistico(nuevoValor);
                        break;
                    case 4:
                        cout << "Nuevo género: ";
                        getline(cin, nuevoValor);
                        lista[i].setGenero(nuevoValor);
                        break;
                    case 5:
                        cout << "Nuevo año de publicación: ";
                        cin >> nuevoInt;
                        lista[i].setAnioPublicacion(nuevoInt);
                        break;
                    case 6:
                        cout << "Nueva duración: ";
                        getline(cin, nuevoValor);
                        lista[i].setDuracion(nuevoValor);
                        break;
                    case 7:
                        cout << "Nuevo número de artistas principales: ";
                        cin >> nuevoInt;
                        lista[i].setNumArtistasPrincipales(nuevoInt);
                        break;
                    case 8:
                        cout << "Nuevo compositor de la letra: ";
                        getline(cin, nuevoValor);
                        lista[i].setComposLetra(nuevoValor);
                        break;
                    case 9:
                        cout << "Nuevo compositor de la música: ";
                        getline(cin, nuevoValor);
                        lista[i].setComposMusica(nuevoValor);
                        break;
                    case 10:
                        cout << "Nuevo arreglista musical: ";
                        getline(cin, nuevoValor);
                        lista[i].setArrMusic(nuevoValor);
                        break;
                    case 11:
                        cout << "Nueva ciudad de grabación: ";
                        getline(cin, nuevoValor);
                        lista[i].setCiudadGrabacion(nuevoValor);
                        break;
                    case 12:
                        cout << "Nuevo país de grabación: ";
                        getline(cin, nuevoValor);
                        lista[i].setPaisGrabacion(nuevoValor);
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
        cout << "No se encontró una canción con el ID especificado.\n";
        return;
    }

    // Guardar la lista actualizada en el archivo
    guardarEnArchivo(nombreArchivo, lista);
}
