#include <iostream>
#include <fstream>
#include "Librerias/Album.h"
#include "Librerias/Links.h"
#include "Librerias/Cancion.h"

using namespace std;
MiVector<Album> albums_archivo;
MiVector<Cancion>listaCancionesEncontradas;
MiVector<Links> listaLinksEncontrados;
void Album::insertar_cabeceras()
{
    multi_album.insertar(titulo);
    multi_album.insertar(nom_artis);
    multi_album.insertar(anio_publi);
    multi_album.insertar(cover);
    multi_album.insertar(fotografia);
    multi_album.insertar(estudio_grabaci);
    multi_album.insertar(editorial);
}

void Album ::insertar_album(Album album, MiVector<nodo_canciones> canciones_album, MiVector<Links> links_album)
{
    nodo_album album_nuevo;
    albums_archivo.push_back(album);
    album_nuevo.id = album.id;
    album_nuevo.titulo = album.titulo_alb;
    album_nuevo.nom_artis = album.nombre_art;
    album_nuevo.cover = album.cover_art;
    album_nuevo.fotografia = album.fotogra;
    album_nuevo.editora = album.editora;
    album_nuevo.estudio_grab = album.estudio_grab;
    album_nuevo.anio_pub = to_string(album.anio_pub);
    for(int i=1; i<= canciones_album.size(); i++){
        album_nuevo.lista_caciones.push_back(canciones_album[i]);
    }
    for (int j = 1; j <= links_album.size(); j++)
    {
        album_nuevo.lista_links.push_back(links_album[j].insertar_link(links_album[j]));
    }

    multi_album.insertar(album_nuevo);
    cout << "Álbum insertado" << endl;
}
void Album:: consultar_por_atributo(string atributo, int cabecera, string contex, string clav_orden){
    MiVector<nodo_album> lista_porAnio;
    lista_porAnio = multi_album.consulta_por_atributo(atributo, cabecera, contex, clav_orden);
    cout << lista_porAnio[1].anio_pub << endl;
    cout << lista_porAnio[2].anio_pub << endl;
}
void Album :: insertar_album_multi(Album album, MiVector<Cancion> canciones_album, MiVector<Links> links_album)
{
    nodo_album album_nuevo;
    albums_archivo.push_back(album);
    album_nuevo.id = album.id;
    album_nuevo.titulo = album.titulo_alb;
    album_nuevo.nom_artis = album.nombre_art;
    album_nuevo.cover = album.cover_art;
    album_nuevo.fotografia = album.fotogra;
    album_nuevo.editora = album.editora;
    album_nuevo.estudio_grab = album.estudio_grab;
    album_nuevo.anio_pub = to_string(album.anio_pub);

    nodo_canciones cancion_album;
    for(int i=1; i<= canciones_album.size(); i++){
        cancion_album.id = canciones_album[i].getId();
        cancion_album.id_album = canciones_album[i].getIdAlbum();
        cancion_album.nom_cancion = canciones_album[i].getNombreCancion();
        cancion_album.nom_artistico = canciones_album[i].getNomArtistico();
        cancion_album.arrMusic = canciones_album[i].getArrMusic();
        cancion_album.anioPublicacion = canciones_album[i].getAnioPublicacion();
        cancion_album.arrMusic = canciones_album[i].getArrMusic();
        cancion_album.ciudadGrabacion = canciones_album[i].getCiudadGrabacion();
        cancion_album.composLetra = canciones_album[i].getComposLetra();
        cancion_album.composMusica = canciones_album[i].getComposMusica();
        cancion_album.duracion = canciones_album[i].getDuracion(); 
        cancion_album.genero = canciones_album[i].getGenero();
        album_nuevo.lista_caciones.push_back(cancion_album);
    }

    multi_album.insertar(album_nuevo);
    cout << "Álbum insertado" << endl;
}

// Guardar lista de álbumes en archivo
void Album::guardarEnArchivo(const string &nombreArchivo)
{
    ofstream archivo(nombreArchivo);
    if (!archivo)
    {
        cerr << "Error al abrir el archivo para escritura." << endl;
        return;
    }

    for (size_t i = 1; i <= albums_archivo.size(); i++)
    {
        archivo << albums_archivo[i].getId() << ","
                << albums_archivo[i].getTitulo() << ","
                << albums_archivo[i].getNombreArt() << ","
                << albums_archivo[i].getPaisGrab() << ","
                << albums_archivo[i].getAnioPub() << ","
                << albums_archivo[i].getCoverArt() << ","
                << albums_archivo[i].getFotogra() << ","
                << albums_archivo[i].getEditora() << ","
                << albums_archivo[i].getEstudioGrab() << endl;
    }
    archivo.close();
}

// Leer lista de álbumes desde archivo
void Album::leerDesdeArchivo(const string &nombreArchivo)
{
    ifstream archivo(nombreArchivo);
    if (!archivo)
    {
        cerr << "Error al abrir el archivo para lectura." << endl;
        return;
    }

    albums_archivo.clear();

    int id, anioPub;
    string tituloAlb, nombreArt, paisGrab, coverArt, fotogra, editora, estudioGrab;

    while (archivo >> id)
    {
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

        albums_archivo.push_back(Album(id, tituloAlb, nombreArt, paisGrab, anioPub, coverArt, fotogra, editora, estudioGrab));
    }

    archivo.close();
}

void Album::eliminarDeArchivo(const string &nombreArchivo)
{
    int idEliminar;
    cout << "Ingrese el ID del álbum que desea eliminar: ";
    cin >> idEliminar;

    bool encontrado = false;
    for (size_t i = 1; i <= albums_archivo.size(); i++)
    {
        if (albums_archivo[i].getId() == idEliminar)
        {
            encontrado = true;
            cout << "Está seguro de eliminar el siguiente álbum? (y/n)\n";
            cout << "ID: " << albums_archivo[i].getId() << "\n"
                 << "Título: " << albums_archivo[i].getTitulo() << "\n"
                 << "Artista: " << albums_archivo[i].getNombreArt() << "\n"
                 << "País de grabación: " << albums_archivo[i].getPaisGrab() << "\n"
                 << "Año de publicación: " << albums_archivo[i].getAnioPub() << "\n"
                 << "Cover Art: " << albums_archivo[i].getCoverArt() << "\n"
                 << "Fotografía: " << albums_archivo[i].getFotogra() << "\n"
                 << "Editora: " << albums_archivo[i].getEditora() << "\n"
                 << "Estudio de grabación: " << albums_archivo[i].getEstudioGrab() << "\n";

            char confirmacion;
            cout << "Confirmar eliminación (y/n): ";
            cin >> confirmacion;

            if (confirmacion == 'y' || confirmacion == 'Y')
            {
                albums_archivo.erase(i); // Eliminar de la lista
                cout << "Álbum eliminado con éxito.\n";
            }
            else
            {
                cout << "Eliminación cancelada.\n";
            }
            break;
        }
    }

    if (!encontrado)
    {
        cout << "No se encontró un álbum con el ID especificado.\n";
        return;
    }

    // Guardar la lista actualizada en el archivo
    guardarEnArchivo(nombreArchivo);
}

void Album::actualizarDesdeArchivo(const string &nombreArchivo)
{
    int idEditar;
    cout << "Ingrese el ID del álbum que desea editar: ";
    cin >> idEditar;

    bool encontrado = false;
    for (size_t i = 1; i <= albums_archivo.size(); i++)
    {
        if (albums_archivo[i].getId() == idEditar)
        {
            encontrado = true;
            cout << "Álbum encontrado. Datos actuales:\n";
            cout << "1. ID: " << albums_archivo[i].getId() << "\n";
            cout << "2. Título: " << albums_archivo[i].getTitulo() << "\n";
            cout << "3. Nombre del artista: " << albums_archivo[i].getNombreArt() << "\n";
            cout << "4. País de grabación: " << albums_archivo[i].getPaisGrab() << "\n";
            cout << "5. Año de publicación: " << albums_archivo[i].getAnioPub() << "\n";
            cout << "6. Cover Art: " << albums_archivo[i].getCoverArt() << "\n";
            cout << "7. Fotografía: " << albums_archivo[i].getFotogra() << "\n";
            cout << "8. Editora: " << albums_archivo[i].getEditora() << "\n";
            cout << "9. Estudio de grabación: " << albums_archivo[i].getEstudioGrab() << "\n";

            int opcion;
            while (true)
            {
                cout << "Ingrese el número del atributo que desea modificar (0 para salir): ";
                cin >> opcion;
                cin.ignore(); // Limpiar buffer

                if (opcion == 0)
                {
                    cout << "Saliendo del modo de edición...\n";
                    break;
                }

                string nuevoValor;
                int nuevoId, nuevoAnio;
                switch (opcion)
                {
                case 1:
                    cout << "Nuevo ID: ";
                    cin >> nuevoId;
                    albums_archivo[i].setId(nuevoId);
                    break;
                case 2:
                    cout << "Nuevo título: ";
                    getline(cin, nuevoValor);
                    albums_archivo[i].setTitulo(nuevoValor);
                    break;
                case 3:
                    cout << "Nuevo nombre del artista: ";
                    getline(cin, nuevoValor);
                    albums_archivo[i].setNombreArt(nuevoValor);
                    break;
                case 4:
                    cout << "Nuevo país de grabación: ";
                    getline(cin, nuevoValor);
                    albums_archivo[i].setPaisGrab(nuevoValor);
                    break;
                case 5:
                    cout << "Nuevo año de publicación: ";
                    cin >> nuevoAnio;
                    albums_archivo[i].setAnioPub(nuevoAnio);
                    break;
                case 6:
                    cout << "Nuevo cover art: ";
                    getline(cin, nuevoValor);
                    albums_archivo[i].setCoverArt(nuevoValor);
                    break;
                case 7:
                    cout << "Nueva fotografía: ";
                    getline(cin, nuevoValor);
                    albums_archivo[i].setFotogra(nuevoValor);
                    break;
                case 8:
                    cout << "Nueva editora: ";
                    getline(cin, nuevoValor);
                    albums_archivo[i].setEditora(nuevoValor);
                    break;
                case 9:
                    cout << "Nuevo estudio de grabación: ";
                    getline(cin, nuevoValor);
                    albums_archivo[i].setEstudioGrab(nuevoValor);
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

    if (!encontrado)
    {
        cout << "No se encontró un álbum con el ID especificado.\n";
        return;
    }

    // Guardar la lista actualizada en el archivo
    guardarEnArchivo(nombreArchivo);
    cout << "Los cambios han sido guardados correctamente en el archivo.\n";
}

void Album::buscarAlbumConRelacionados(int id_bus)
{
  


    Album albumEncontrado;
    bool encontrado = false;

    // Buscar el álbum por ID
    for (size_t i = 1; i <= albums_archivo.size(); i++)
    {
        if (albums_archivo[i].getId() == id_bus)
        {
            albumEncontrado = albums_archivo[i];
            encontrado = true;
            break;
        }
    }


    // Leer registros de Links
    

    // Filtrar los links relacionados con este álbum
    listaLinksEncontrados.clear();
    for (size_t i = 1; i <= links_archivo.size(); i++)
    {
        if (links_archivo[i].getIdAlbum() == id_bus)
        {
            listaLinksEncontrados.push_back(links_archivo[i]);
        }
    }

    // Leer registros de Canciones
    

    // Filtrar las canciones relacionadas con este álbum
    listaCancionesEncontradas.clear();
    for (size_t i = 1; i <= lista_canciones_archivo.size(); i++)
    {
        if (lista_canciones_archivo[i].getIdAlbum() == id_bus)
        {
            listaCancionesEncontradas.push_back(lista_canciones_archivo[i]);
        }
    }

    
    albumEncontrado.insertar_album_multi(albumEncontrado, listaCancionesEncontradas, listaLinksEncontrados);
}
