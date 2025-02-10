#include <iostream>
#include "Librerias/Cancion.h"
#include "Librerias/Links.h"
#include "Librerias/Artista.h"
#include "Librerias/MiVector.h"
#include "Librerias/Version.h"
#include "Cancion.cpp"
#include "Artista.cpp"
#include "Links.cpp"
#include "Version.cpp"
#include "Album.cpp"
using namespace std;
#include <iostream>
MiVector<Cancion> canciones_archivo;


void insertar_prueba()
{
    MiVector<Cancion> listaCanciones;
    MiVector<Links> listalinkscancion, listalinksalbum, listalinkversion;
    MiVector<Artista> listaArtistas, lista_artis_vers;
    MiVector<nodo_versiones> listaVersiones;
    MiVector<nodo_canciones> listaCancionesAlbum;
    nodo_album albumInsertado;
    nodo_canciones cancionInsertada;
    nodo_versiones version;
    Album album;
    Cancion cancioncita;
    Version vers;
    cancioncita.insertar_cabeceras();
    album.insertar_cabeceras();
    vers.insertar_cabeceras();
    Cancion::leerDesdeArchivo("ArchivosPlanos/canciones.txt");
    Artista::leerDesdeArchivo("ArchivosPlanos/artistas.txt");
    Links::leerDesdeArchivo("ArchivosPlanos/links.txt");
    Album::leerDesdeArchivo("ArchivosPlanos/albums.txt");
    Version::leerDesdeArchivo("ArchivosPlanos/versiones.txt");

    // Ahora podemos imprimir o hacer lo que sea necesario con la lista de canciones en el album.
    album.insertar_album(Album(2, "Fiesta Tropical", "Carlos Vives", "Colombia", 2019, "Carlos Vives", "Carlos Vives", "Sony Music Latin", "Miami, FL"), listaCancionesAlbum, listalinksalbum);
    Cancion::guardarEnArchivo("ArchivosPlanos/canciones.txt");
    Artista::guardarEnArchivo("ArchivosPlanos/artistas.txt");
    Links::guardarEnArchivo("ArchivosPlanos/links.txt");
    Album::guardarEnArchivo("ArchivosPlanos/albums.txt");
    Version::guardarEnArchivo("ArchivosPlanos/versiones.txt");
}
void mostrarMenu()
{
    cout << "Menú:" << endl;
    cout << "1. Insertar álbumes." << endl;
    cout << "2. Insertar canciones." << endl;
    cout << "3. Insertar versiones." << endl;
    cout << "4. Eliminar álbumes." << endl;
    cout << "5. Eliminar canciones." << endl;
    cout << "6. Eliminar versiones." << endl;
    cout << "7. Realizar consultas" << endl;
    cout << "8. Salir" << endl;
    cout << "Seleccione una opción: ";
}
void menu_consultas()
{
    cout << "Menú consultas:" << endl;
    // clasificada por año de publicación y nombre artistico.
    cout << "1. Albúm de una editora." << endl;
    // clasificados por año y país de grabación.
    cout << "2. Albumes y canciones grabados en un estudio dado." << endl;
    // clasificado por ciudad de grabación. Incluyendo arreglista, autores de letra y de la música.
    cout << "3. Canciones cuya duración es mayor a un tiempo dado." << endl;
    // Incluir nombre de la canción, nombre artístico y los datos del artista que interpreta el instrumento.
    cout << "4. Listado de canciones de un género y un instrumento dado." << endl;
    // clasificado por género y año de la grabación.
    cout << "5. Número de canciones que tienen una cantidad de versiones mayor o igual a un número dado." << endl;
    // Incluir el título de la versión, nombre artista principal, género, año, país de publicación, nombre obra original,
    // plataformas en las que se encuentra
    cout << "6. Versiones que pertenecen a un tipo de versión dada, que se encuentren en más de una plataforma." << endl;
    // Incluir nombre de la plataforma y link.
    cout << "7. Links de las plataformas donde se encuentra una canción dada y sus versiones." << endl;
    // Clasificado por género y año de publicación. Incluyendo nombre del encargado, el género y el año.
    cout << "8. Número de canciones y versiones que ha creado cada encargado del cover." << endl;
    // Clasificado por país de grabación.
    cout << "9. Albumes dado el nombre del encargado de fotografía y del estudio de grabación." << endl;
    // incluyendo género, año, nombre canción, album al que pertenece, número plataformas en las que se encuentra.
    cout << "10. Canciones escritas por un compositor de letra dado." << endl;
    cout << "11. Volver al menú principal" << endl;
    cout << "Seleccione una opción: ";
}
Album insertar_album(){
    int id, anio_pub;
    string titulo_alb, nombre_art, pais_grab, cover_art, fotogra, editora, estudio_grab;

    // Solicitar información al usuario
    cout << "Ingrese el ID del álbum: ";
    cin >> id;
    cin.ignore(); // Limpiar el buffer de entrada

    cout << "Ingrese el título del álbum: ";
    getline(cin, titulo_alb);

    cout << "Ingrese el nombre del artista: ";
    getline(cin, nombre_art);

    cout << "Ingrese el país de grabación: ";
    getline(cin, pais_grab);

    cout << "Ingrese el año de publicación: ";
    cin >> anio_pub;
    cin.ignore(); // Limpiar el buffer de entrada

    cout << "Ingrese la portada del álbum: ";
    getline(cin, cover_art);

    cout << "Ingrese el fotógrafo: ";
    getline(cin, fotogra);

    cout << "Ingrese la editora: ";
    getline(cin, editora);

    cout << "Ingrese el estudio de grabación: ";
    getline(cin, estudio_grab);

    // Crear el objeto Album con los datos ingresados
    return Album(id, titulo_alb, nombre_art, pais_grab, anio_pub, cover_art, fotogra, editora, estudio_grab);
}
Cancion insertar_cancion(){
    int id, id_album, numArtistasPrincipales, anioPublicacion;
    string nombreCancion, nom_artistico, duracion, composLetra, composMusica, arrMusic;
    string ciudadGrabacion, paisGrabacion, genero;

    // Solicitar información al usuario
    cout << "Ingrese el ID de la canción: ";
    cin >> id;
    cout << "Ingrese el ID del álbum: ";
    cin >> id_album;
    cin.ignore();  // Limpiar el buffer de entrada

    cout << "Ingrese el nombre de la canción: ";
    getline(cin, nombreCancion);

    cout << "Ingrese el nombre artístico: ";
    getline(cin, nom_artistico);

    cout << "Ingrese la duración de la canción (formato: mm:ss): ";
    getline(cin, duracion);

    cout << "Ingrese el número de artistas principales: ";
    cin >> numArtistasPrincipales;
    cin.ignore();  // Limpiar el buffer de entrada

    cout << "Ingrese el compositor de la letra: ";
    getline(cin, composLetra);

    cout << "Ingrese el compositor de la música: ";
    getline(cin, composMusica);

    cout << "Ingrese el arreglo musical: ";
    getline(cin, arrMusic);

    cout << "Ingrese la ciudad de grabación: ";
    getline(cin, ciudadGrabacion);

    cout << "Ingrese el país de grabación: ";
    getline(cin, paisGrabacion);

    cout << "Ingrese el año de publicación: ";
    cin >> anioPublicacion;
    cin.ignore();  // Limpiar el buffer de entrada

    cout << "Ingrese el género de la canción: ";
    getline(cin, genero);

    // Crear el objeto Cancion con los datos ingresados
    return Cancion(id, id_album, nombreCancion, nom_artistico, genero, anio_pub, duracion, composLetra, composMusica, arrMusic, ciudadGrabacion, paisGrabacion, numArtistasPrincipales);

}
int main()
{

    int opcion;
    do
    {
        mostrarMenu();
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            cout << "Opción para insertar álbumes" << endl;
            MiVector<Cancion> listaCanciones;
            MiVector<Links> listalinkscancion, listalinksalbum, listalinkversion;
            MiVector<Artista> listaArtistas, lista_artis_vers;
            MiVector<nodo_versiones> listaVersiones;
            MiVector<nodo_canciones> listaCancionesAlbum;
            insertar_album();
            break;
        case 2:
            cout << "Opción para insertar canciones" << endl;
            break;
        case 3:
            cout << "Opción para insertar artistas" << endl;
            break;
        case 4:
            cout << "Saliendo del menú..." << endl;
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            int op_cons;
            do
            {
                menu_consultas();
                cin >> op_cons;
                switch (op_cons)
                {
                case 1:
                    cout << "Consulta 1" << endl;
                    break;
                case 2:
                    cout << "Consulta 2" << endl;
                    break;
                case 3:
                    cout << "Consulta 3" << endl;
                    break;
                case 4:
                    break;
                case 5:
                    break;
                case 6:
                    break;
                case 7:
                    break;
                case 8:
                    break;
                case 9:
                    break;
                case 10:
                    break;
                default:
                    cout << "Opción no válida. Intente nuevamente." << endl;
                }
            } while (op_cons != 11);

            break;
        default:
            cout << "Opción no válida. Intente nuevamente." << endl;
        }
    } while (opcion != 8);

    return 0;
}
