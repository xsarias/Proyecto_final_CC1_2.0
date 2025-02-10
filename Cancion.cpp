#include "Librerias/Cancion.h"
#include <iostream>
#include <fstream>
#include "Librerias/MiVector.h"
#include <utility> 

MiVector<Cancion> lista_canciones_archivo;
void Cancion :: imprimir_lista(string parametro, int pos_cab) {
    // Obtener la posición inicial de la cabeza para el orden del parámetro
    int cab = multi_cancion.retornar_pos(pos_cab, "pos_cabeza");
    int cont;
    if (cab < 1) {
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
    multi_cancion.insertar(duracion_can); //9

}
nodo_canciones  Cancion :: insertar_cancion(Cancion cancion, MiVector<Links> links, MiVector<Artista> artista){
    lista_canciones_archivo.push_back(cancion);
    nodo_canciones cancion_nueva;
    cancion_nueva.id = cancion.id;
    cancion_nueva.id_album = cancion.id_album;
    cancion_nueva.nom_cancion = cancion.nombreCancion;
    cancion_nueva.nom_artistico = cancion.nom_artistico;
    cancion_nueva.arrMusic = cancion.arrMusic;
    cancion_nueva.anioPublicacion = cancion.anioPublicacion;
    cancion_nueva.arrMusic = cancion.arrMusic;
    cancion_nueva.ciudadGrabacion = cancion.ciudadGrabacion;
    cancion_nueva.composLetra = cancion.composLetra;
    cancion_nueva.composMusica = cancion.composMusica;
    cancion_nueva.duracion = cancion.duracion; 
    cancion_nueva.genero = cancion.genero;
    cancion_nueva.numArtistasPrincipales = cancion.numArtistasPrincipales;
    for(int i=1; i<=artista.size(); i++){
        cout<<artista[i].getId();
        cancion_nueva.list_artist.push_back(artista[i].insertar_artista(artista[i]));
    }
    for(int i=1; i<=links.size(); i++){
        cancion_nueva.list_links.push_back(links[i].insertar_link(links[i]));
    } 

    multi_cancion.insertar(cancion_nueva);
    //cout<<"canción insertada"<<endl;
    return cancion_nueva;
}
nodo_canciones  Cancion :: insertar_cancion(Cancion cancion, MiVector<Links> links, MiVector<Artista> artista, MiVector<nodo_versiones> version){
    lista_canciones_archivo.push_back(cancion);
    nodo_canciones cancion_nueva;
    cancion_nueva.id = cancion.id;
    cancion_nueva.id_album = cancion.id_album;
    cancion_nueva.nom_cancion = cancion.nombreCancion;
    cancion_nueva.nom_artistico = cancion.nom_artistico;
    cancion_nueva.arrMusic = cancion.arrMusic;
    cancion_nueva.anioPublicacion = cancion.anioPublicacion;
    cancion_nueva.arrMusic = cancion.arrMusic;
    cancion_nueva.ciudadGrabacion = cancion.ciudadGrabacion;
    cancion_nueva.composLetra = cancion.composLetra;
    cancion_nueva.composMusica = cancion.composMusica;
    cancion_nueva.duracion = cancion.duracion; 
    cancion_nueva.genero = cancion.genero;
    cancion_nueva.numArtistasPrincipales = cancion.numArtistasPrincipales;
    for(size_t i=1; i<=artista.size(); i++){
        cancion_nueva.list_artist.push_back(artista[i].insertar_artista(artista[i]));
    }
    for(size_t i=1; i<=links.size(); i++){
        cancion_nueva.list_links.push_back(links[i].insertar_link(links[i]));
    }
    for(int i=1; i<=version.size(); i++){
        cancion_nueva.list_versiones.push_back(version[i]);
    }
    
    multi_cancion.insertar(cancion_nueva);
    //cout<<"canción insertada"<<endl;
    return cancion_nueva;
}
// Método para guardar la lista de Canciones en un archivo
void Cancion::guardarEnArchivo(const string& nombreArchivo) {
    ofstream archivo(nombreArchivo);
    if (!archivo) {
        cerr << "Error al abrir el archivo para escritura." << endl;
        return;
    }
    cout<<"tamaño en guardar"<<lista_canciones_archivo.size();
    
    
    for (size_t i = 1; i <= lista_canciones_archivo.size(); i++) {
        archivo << lista_canciones_archivo[i].getId() << ","
                << lista_canciones_archivo[i].getIdAlbum() << ","
                << lista_canciones_archivo[i].getNombreCancion() << ","
                << lista_canciones_archivo[i].getNomArtistico() << ","
                << lista_canciones_archivo[i].getDuracion() << ","
                << lista_canciones_archivo[i].getNumArtistasPrincipales() << ","
                << lista_canciones_archivo[i].getComposLetra() << ","
                << lista_canciones_archivo[i].getComposMusica() << ","
                << lista_canciones_archivo[i].getArrMusic() << ","
                << lista_canciones_archivo[i].getCiudadGrabacion() << ","
                << lista_canciones_archivo[i].getPaisGrabacion()<< ","
                << lista_canciones_archivo[i].getAnioPublicacion() << ","
                << lista_canciones_archivo[i].getGenero() << endl;
    }

    archivo.close();
}

// Método para leer la lista de Canciones desde un archivo
void Cancion::leerDesdeArchivo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo) {
        cerr << "Error al abrir el archivo para lectura." << endl;
        return;
    }

    lista_canciones_archivo.clear();
    int id, id_album, anioPublicacion, numArtistasPrincipales;
    string nombreCancion, nomArtistico, genero, duracion;
    string composLetra, composMusica, arrMusic, ciudadGrabacion, paisGrabacion;

    while (archivo >> id) {
        archivo.ignore();  
        archivo >> id_album;
        archivo.ignore();
        getline(archivo, nombreCancion, ',');
        getline(archivo, nomArtistico, ',');
        getline(archivo, duracion, ',');
        archivo >> numArtistasPrincipales;
        archivo.ignore();
        getline(archivo, composLetra, ',');
        getline(archivo, composMusica, ',');
        getline(archivo, arrMusic, ',');
        getline(archivo, ciudadGrabacion, ',');
        getline(archivo, paisGrabacion, ',');
        archivo >> anioPublicacion;
        archivo.ignore();
        getline(archivo, genero);

        lista_canciones_archivo.push_back(Cancion(id, id_album, nombreCancion, nomArtistico, genero, anioPublicacion, duracion,
                                composLetra, composMusica, arrMusic, ciudadGrabacion, paisGrabacion, numArtistasPrincipales));
    }

    archivo.close();
}

void Cancion::eliminarDeArchivo(const string& nombreArchivo) {
    int idEliminar;
    cout << "Ingrese el ID de la canción que desea eliminar: ";
    cin >> idEliminar;

    bool encontrado = false;
    for (size_t i = 1; i <= lista_canciones_archivo.size(); i++) {
        if (lista_canciones_archivo[i].getId() == idEliminar) {
            encontrado = true;
            cout << "Está seguro de eliminar la siguiente canción? (y/n)\n";
            cout << "ID: " << lista_canciones_archivo[i].getId() << "\n"
            << "ID del Álbum: " << lista_canciones_archivo[i].getIdAlbum() << "\n"
            << "Nombre: " << lista_canciones_archivo[i].getNombreCancion() << "\n"
            << "Artista: " << lista_canciones_archivo[i].getNomArtistico() << "\n"
            << "Duración: " << lista_canciones_archivo[i].getDuracion() << "\n"
            << "Número de Artistas Principales: " << lista_canciones_archivo[i].getNumArtistasPrincipales() << "\n"
            << "Compositor de Letra: " << lista_canciones_archivo[i].getComposLetra() << "\n"
            << "Compositor de Música: " << lista_canciones_archivo[i].getComposMusica() << "\n"
            << "Arreglista Musical: " << lista_canciones_archivo[i].getArrMusic() << "\n"
            << "Ciudad de Grabación: " << lista_canciones_archivo[i].getCiudadGrabacion() << "\n"
            << "País de Grabación: " << lista_canciones_archivo[i].getPaisGrabacion() << "\n"
            << "Año de Publicación: " << lista_canciones_archivo[i].getAnioPublicacion() << "\n"
            << "Género: " << lista_canciones_archivo[i].getGenero() << "\n";

            char confirmacion;
            cout << "Confirmar eliminación (y/n): ";
            cin >> confirmacion;

            if (confirmacion == 'y' || confirmacion == 'Y') {
                lista_canciones_archivo.erase(i);  // Eliminar de la lista
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
    guardarEnArchivo(nombreArchivo);
}

void Cancion::actualizarDesdeArchivo(const string& nombreArchivo) {
    int idEditar;
    cout << "Ingrese el ID de la canción que desea editar: ";
    cin >> idEditar;

    bool encontrado = false;
    for (size_t i = 1; i <= lista_canciones_archivo.size(); i++) {
        if (lista_canciones_archivo[i].getId() == idEditar) {
            encontrado = true;
            cout << "Canción encontrada. Datos actuales:\n";
            cout << "1. ID Álbum: " << lista_canciones_archivo[i].getIdAlbum() << "\n";
            cout << "2. Nombre: " << lista_canciones_archivo[i].getNombreCancion() << "\n";
            cout << "3. Artista: " << lista_canciones_archivo[i].getNomArtistico() << "\n";
            cout << "4. Género: " << lista_canciones_archivo[i].getGenero() << "\n";
            cout << "5. Año de publicación: " << lista_canciones_archivo[i].getAnioPublicacion() << "\n";
            cout << "6. Duración: " << lista_canciones_archivo[i].getDuracion() << "\n";
            cout << "7. Número de artistas principales: " << lista_canciones_archivo[i].getNumArtistasPrincipales() << "\n";
            cout << "8. Compositor de la letra: " << lista_canciones_archivo[i].getComposLetra() << "\n";
            cout << "9. Compositor de la música: " << lista_canciones_archivo[i].getComposMusica() << "\n";
            cout << "10. Arreglista musical: " << lista_canciones_archivo[i].getArrMusic() << "\n";
            cout << "11. Ciudad de grabación: " << lista_canciones_archivo[i].getCiudadGrabacion() << "\n";
            cout << "12. País de grabación: " << lista_canciones_archivo[i].getPaisGrabacion() << "\n";

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
                        lista_canciones_archivo[i].setIdAlbum(nuevoInt);
                        break;
                    case 2:
                        cout << "Nuevo nombre de la canción: ";
                        getline(cin, nuevoValor);
                        lista_canciones_archivo[i].setNombre(nuevoValor);
                        break;
                    case 3:
                        cout << "Nuevo nombre del artista: ";
                        getline(cin, nuevoValor);
                        lista_canciones_archivo[i].setNomArtistico(nuevoValor);
                        break;
                    case 4:
                        cout << "Nuevo género: ";
                        getline(cin, nuevoValor);
                        lista_canciones_archivo[i].setGenero(nuevoValor);
                        break;
                    case 5:
                        cout << "Nuevo año de publicación: ";
                        cin >> nuevoInt;
                        lista_canciones_archivo[i].setAnioPublicacion(nuevoInt);
                        break;
                    case 6:
                        cout << "Nueva duración: ";
                        getline(cin, nuevoValor);
                        lista_canciones_archivo[i].setDuracion(nuevoValor);
                        break;
                    case 7:
                        cout << "Nuevo número de artistas principales: ";
                        cin >> nuevoInt;
                        lista_canciones_archivo[i].setNumArtistasPrincipales(nuevoInt);
                        break;
                    case 8:
                        cout << "Nuevo compositor de la letra: ";
                        getline(cin, nuevoValor);
                        lista_canciones_archivo[i].setComposLetra(nuevoValor);
                        break;
                    case 9:
                        cout << "Nuevo compositor de la música: ";
                        getline(cin, nuevoValor);
                        lista_canciones_archivo[i].setComposMusica(nuevoValor);
                        break;
                    case 10:
                        cout << "Nuevo arreglista_canciones_archivo musical: ";
                        getline(cin, nuevoValor);
                        lista_canciones_archivo[i].setArrMusic(nuevoValor);
                        break;
                    case 11:
                        cout << "Nueva ciudad de grabación: ";
                        getline(cin, nuevoValor);
                        lista_canciones_archivo[i].setCiudadGrabacion(nuevoValor);
                        break;
                    case 12:
                        cout << "Nuevo país de grabación: ";
                        getline(cin, nuevoValor);
                        lista_canciones_archivo[i].setPaisGrabacion(nuevoValor);
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
    guardarEnArchivo(nombreArchivo);
}

Cancion Cancion::buscarCancionConRelacionados(const string& nombreArchivoCancion,  
    const string& nombreArchivoLinks,  
    const string& nombreArchivoArtistas,  
    MiVector<Links>& listaLinks,  
    MiVector<Artista>& listaArtistas)  
{  
    int idBuscado;  
    cout << "Ingrese el ID de la canción a buscar: ";  
    cin >> idBuscado;  

    MiVector<Cancion> listaCanciones;  
    leerDesdeArchivo(nombreArchivoCancion);  

    Cancion cancionEncontrada;  
    bool encontrado = false;  

    // Buscar la canción por ID  
    for (size_t i = 1; i <= listaCanciones.size(); i++) {  
        if (listaCanciones[i].getId() == idBuscado) {  
            cancionEncontrada = listaCanciones[i];  
            encontrado = true;  
            break;  
        }  
    }  

    if (!encontrado) {  
        cout << "No se encontró una canción con el ID especificado.\n";  
        return Cancion();  
    }  

    // Leer registros de Links  
    MiVector<Links> todosLosLinks;  
    Links::leerDesdeArchivo(nombreArchivoLinks);  

    // Filtrar los links relacionados con esta canción  
    listaLinks.clear();  
    for (size_t i = 1; i <= todosLosLinks.size(); i++) {  
        if (todosLosLinks[i].getIdCancion() == idBuscado) {  
            listaLinks.push_back(todosLosLinks[i]);  
        }  
    }  

    // Leer registros de Artistas  
    MiVector<Artista> todosLosArtistas;  
    Artista::leerDesdeArchivo(nombreArchivoArtistas);  

    // Filtrar los artistas relacionados con esta canción  
    listaArtistas.clear();  
    for (size_t i = 1; i <= todosLosArtistas.size(); i++) {  
        if (todosLosArtistas[i].getIdCancion() == idBuscado) {  
            listaArtistas.push_back(todosLosArtistas[i]);  
        }  
    }  

    return cancionEncontrada;  
}
int Cancion::contarVersiones(const string& titulo) {
    MiVector<Cancion> listaCanciones;
    leerDesdeArchivo("canciones.txt"); // Asegúrate de usar el nombre correcto del archivo

    int idBuscado = -1;

    // Buscar la canción por título para obtener su ID
    for (size_t i = 0; i < listaCanciones.size(); i++) {  // Cambio: i inicia en 0
        if (listaCanciones[i].getNombreCancion() == titulo) {
            idBuscado = listaCanciones[i].getId();
            break;
        }
    }

    if (idBuscado == -1) {
        cout << "No se encontró la canción con título: " << titulo << endl;
        return 0;
    }

    // Leer registros de Links
    MiVector<Links> todosLosLinks;
    Links::leerDesdeArchivo("links.txt"); // Ajusta el nombre del archivo si es diferente

    // Contar los links relacionados con esta canción (que representan versiones)
    int contadorVersiones = 0;
    for (size_t i = 0; i < todosLosLinks.size(); i++) {  // Cambio: i inicia en 0
        if (todosLosLinks[i].getIdCancion() == idBuscado) {
            contadorVersiones++;
        }
    }

    return contadorVersiones;
}

// ------------------- CONSULTA 5 -------------------
void consultaNumeroVersiones(int numeroVersiones) {
    // Obtener todas las canciones
    MiVector<nodo_canciones> todasLasCanciones = multi_cancion.consulta_por_atributo("nom_cancion", 2, "", "");

    // Verificar si hay canciones
    if (todasLasCanciones.size() == 0) {
        std::cout << "No hay canciones disponibles." << std::endl;
        return;
    }

    // Vector para almacenar los resultados clasificados por género y año
    MiVector<std::pair<std::pair<std::string, int>, int>> resultados;

    for (int i = 0; i < todasLasCanciones.size(); i++) {  // Cambio: i inicia en 0
        nodo_canciones cancion = todasLasCanciones[i];
        int numVersiones = Cancion::contarVersiones(cancion.nom_cancion);

        if (numVersiones >= numeroVersiones) {
            std::string genero = cancion.genero;
            int anioPublicacion = cancion.anioPublicacion;

            // Buscar si ya existe una entrada para este género y año
            bool encontrado = false;
            for (int j = 0; j < resultados.size(); j++) {  // Cambio: j inicia en 0
                if (resultados[j].first.first == genero &&
                    resultados[j].first.second == anioPublicacion) {
                    // Incrementar el contador de canciones para este género y año
                    resultados[j].second++;
                    encontrado = true;
                    break;
                }
            }

            // Si no se encontró una entrada existente, agregar una nueva
            if (!encontrado) {
                resultados.push_back({{genero, anioPublicacion}, 1});
            }
        }
    }

    // Mostrar los resultados
    for (int i = 0; i < resultados.size(); i++) {  // Cambio: i inicia en 0
        std::cout << "Género: " << resultados[i].first.first
                  << ", Año: " << resultados[i].first.second
                  << " - Número de canciones: " << resultados[i].second << std::endl;
    }
}
