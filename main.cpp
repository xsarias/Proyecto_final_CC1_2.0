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
    listalinksalbum.push_back(Links(24, 0, 2, 0, "spotify", "https://open.spotify.com/intl-es/album/1Ly49h9HjH2lQRz4QJ8l9i?si=HbK9VbhmQw1eCrmb-XaTHw", ""));
    listalinksalbum.push_back(Links(25, 0, 2, 0, "youtube", "https://youtube.com/playlist?list=PLZYW8nOaHSb8F4gfq5ni7HdoW8DkXgLz5", ""));

    // Aquí se añade el álbum

    listalinkscancion.clear();
    listaArtistas.clear();
    listaVersiones.clear();
    listaCanciones.push_back(Cancion(21, 2, "Vivir Mi Vida", "Marc Anthony", "salsa", 2013, "00:04:13", "Marc Anthony", "Luis Veleza", "Sofia Perez", "New York", "US", 1));
    listaCanciones.push_back(Cancion(22, 2, "La Gozadera", "Gente de Zona & Marc Anthony", "salsa", 2015, "00:04:02", "Gente de Zona", "Marc Anthony", "Sofia Perez", "Havana", "Cuba", 2));
    listaCanciones.push_back(Cancion(23, 2, "Havana", "Camila Cabello", "pop", 2017, "00:03:38", "Camila Cabello", "Pharrell Williams", "Sofia Perez", "Havana", "Cuba", 3));
    listaCanciones.push_back(Cancion(24, 2, "Taki Taki", "DJ Snake, Selena Gomez, Ozuna & Cardi B", "reggaeton", 2018, "00:03:32", "DJ Snake", "Selena Gomez", "Sofia Perez", "Los Angeles", "US", 4));
    listaCanciones.push_back(Cancion(25, 2, "Dura", "Daddy Yankee", "reggaeton", 2018, "00:03:24", "Daddy Yankee", "Luis Veleza", "Sofia Perez", "San Juan", "Puerto Rico", 5));
    listaCanciones.push_back(Cancion(26, 2, "Bailando", "Enrique Iglesias", "pop", 2014, "00:04:00", "Enrique Iglesias", "Luis Veleza", "Sofia Perez", "Miami", "US", 6));
    listaCanciones.push_back(Cancion(27, 2, "Limbo", "Daddy Yankee", "reggaeton", 2012, "00:03:28", "Daddy Yankee", "Luis Veleza", "Sofia Perez", "San Juan", "Puerto Rico", 7));
    listaCanciones.push_back(Cancion(28, 2, "Súbeme la Radio", "Daddy Yankee", "reggaeton", 2017, "00:03:38", "Daddy Yankee", "Luis Veleza", "Sofia Perez", "San Juan", "Puerto Rico", 8));
    listaCanciones.push_back(Cancion(29, 2, "Echame la Culpa", "Luis Fonsi & Demi Lovato", "pop", 2017, "00:03:05", "Luis Fonsi", "Demi Lovato", "Sofia Perez", "Miami", "US", 9));
    listaCanciones.push_back(Cancion(30, 2, "Vente Pa' Ca", "Ricky Martin & Maluma", "pop", 2016, "00:03:52", "Ricky Martin", "Maluma", "Sofia Perez", "Miami", "US", 10));

    // Canción 1
    listalinkscancion.push_back(Links(26, 21, 0, 0, "spotify", "https://open.spotify.com/intl-es/song/0FkS9VGjzR2sZ0gWvPzHwS", "https://youtube.com/playlist?list=PLZYW8nOaHSb8F4gfq5ni7HdoW8DkXgLz5"));
    listaArtistas.push_back(Artista(37, 21, 0, "Marc Anthony", "Marc", "Puerto Rico", "voz"));
    listaArtistas.push_back(Artista(38, 21, 0, "Luis Veleza", "Luis", "Puerto Rico", "guitarra"));
    listaCancionesAlbum.push_back(cancioncita.insertar_cancion(listaCanciones[1], listalinkscancion, listaArtistas));

    // Limpiamos los vectores para la siguiente canción
    listalinkscancion.clear();
    listaArtistas.clear();
    listaVersiones.clear();

    // Canción 2
    listalinkscancion.push_back(Links(27, 22, 0, 0, "spotify", "https://open.spotify.com/intl-es/song/0rxdVbLqHm5Vgwzv9bvwOw", "https://youtube.com/playlist?list=PLZYW8nOaHSb8F4gfq5ni7HdoW8DkXgLz5"));
    listaArtistas.push_back(Artista(39, 22, 0, "Gente de Zona", "Gente", "Cuba", "voz"));
    listaArtistas.push_back(Artista(40, 22, 0, "Marc Anthony", "Marc", "Puerto Rico", "voz"));
    listaCancionesAlbum.push_back(cancioncita.insertar_cancion(listaCanciones[2], listalinkscancion, listaArtistas));

    // Limpiamos los vectores para la siguiente canción
    listalinkscancion.clear();
    listaArtistas.clear();
    listaVersiones.clear();

    // Canción 3
    listalinkscancion.push_back(Links(28, 23, 0, 0, "youtube", "https://www.youtube.com/watch?v=HCdJkjXMjHg", "https://www.youtube.com/watch?v=oy0Vw6bEjTY"));
    listaArtistas.push_back(Artista(41, 23, 0, "Camila Cabello", "Camila", "Cuba", "voz"));
    listaArtistas.push_back(Artista(42, 23, 0, "Pharrell Williams", "Pharrell", "US", "piano"));
    listaCancionesAlbum.push_back(cancioncita.insertar_cancion(listaCanciones[3], listalinkscancion, listaArtistas));

    // Limpiamos los vectores para la siguiente canción
    listalinkscancion.clear();
    listaArtistas.clear();
    listaVersiones.clear();

    // Canción 4
    listalinkscancion.push_back(Links(29, 24, 0, 0, "spotify", "https://open.spotify.com/intl-es/song/7h6ZJlc85o81GVziHHwP0i", "https://www.youtube.com/watch?v=FkPOyWg4TcY"));
    listaArtistas.push_back(Artista(43, 24, 0, "Selena Gomez", "Selena", "US", "voz"));
    listaArtistas.push_back(Artista(44, 24, 0, "Ozuna", "Ozuna", "Puerto Rico", "voz"));
    listaCancionesAlbum.push_back(cancioncita.insertar_cancion(listaCanciones[4], listalinkscancion, listaArtistas));

    // Limpiamos los vectores para la siguiente canción
    listalinkscancion.clear();
    listaArtistas.clear();
    listaVersiones.clear();

    // Canción 5
    listalinkscancion.push_back(Links(30, 25, 0, 0, "youtube", "https://www.youtube.com/watch?v=3WRdFkrxOOY", "https://www.youtube.com/watch?v=GbTQzAql27o"));
    listaArtistas.push_back(Artista(45, 25, 0, "Daddy Yankee", "Daddy", "Puerto Rico", "voz"));
    listaCancionesAlbum.push_back(cancioncita.insertar_cancion(listaCanciones[5], listalinkscancion, listaArtistas));

    // Limpiamos los vectores para la siguiente canción
    listalinkscancion.clear();
    listaArtistas.clear();
    listaVersiones.clear();

    // Canción 6
    listalinkscancion.push_back(Links(31, 26, 0, 0, "spotify", "https://open.spotify.com/intl-es/song/6MljzH7XYlVuVjZc9azsbF", "https://www.youtube.com/watch?v=WyGAd5dM-dw"));
    listaArtistas.push_back(Artista(46, 26, 0, "Enrique Iglesias", "Enrique", "España", "voz"));
    listaCancionesAlbum.push_back(cancioncita.insertar_cancion(listaCanciones[6], listalinkscancion, listaArtistas));

    // Limpiamos los vectores para la siguiente canción
    listalinkscancion.clear();
    listaArtistas.clear();
    listaVersiones.clear();

    // Canción 7
    listalinkscancion.push_back(Links(32, 27, 0, 0, "spotify", "https://open.spotify.com/intl-es/song/0hxLMzDFGb0m0NJbN6h2jb", "https://www.youtube.com/watch?v=OjVpZg5xx_Y"));
    listaArtistas.push_back(Artista(47, 27, 0, "Daddy Yankee", "Daddy", "Puerto Rico", "voz"));
    listaCancionesAlbum.push_back(cancioncita.insertar_cancion(listaCanciones[7], listalinkscancion, listaArtistas));

    // Limpiamos los vectores para la siguiente canción
    listalinkscancion.clear();
    listaArtistas.clear();
    listaVersiones.clear();

    // Canción 8
    listalinkscancion.push_back(Links(33, 28, 0, 0, "spotify", "https://open.spotify.com/intl-es/song/0vDt9pI2hNMBg9Wtyuh7tQ", "https://www.youtube.com/watch?v=wHpnqLmjTX0"));
    listaArtistas.push_back(Artista(48, 28, 0, "Luis Fonsi", "Luis", "Puerto Rico", "voz"));
    listaCancionesAlbum.push_back(cancioncita.insertar_cancion(listaCanciones[8], listalinkscancion, listaArtistas));

    // Limpiamos los vectores para la siguiente canción
    listalinkscancion.clear();
    listaArtistas.clear();
    listaVersiones.clear();

    // Canción 9
    listalinkscancion.push_back(Links(34, 29, 0, 0, "spotify", "https://open.spotify.com/intl-es/song/7l4X8z7xGRjeqLe7FqOlq9", "https://www.youtube.com/watch?v=3c2g9ctM-mA"));
    listaArtistas.push_back(Artista(49, 29, 0, "Ricky Martin", "Ricky", "Puerto Rico", "voz"));
    listaCancionesAlbum.push_back(cancioncita.insertar_cancion(listaCanciones[9], listalinkscancion, listaArtistas));

    // Limpiamos los vectores para la siguiente canción
    listalinkscancion.clear();
    listaArtistas.clear();
    listaVersiones.clear();

    // Canción 10
    listalinkscancion.push_back(Links(35, 30, 0, 0, "youtube", "https://www.youtube.com/watch?v=OhkTmwxt3Tc", ""));
    listaArtistas.push_back(Artista(50, 30, 0, "Maluma", "Maluma", "Colombia", "voz"));
    listaArtistas.push_back(Artista(51, 30, 0, "Ricky Martin", "Ricky", "Puerto Rico", "voz"));
    listaCancionesAlbum.push_back(cancioncita.insertar_cancion(listaCanciones[10], listalinkscancion, listaArtistas));
    
    album.insertar_album(Album(3, "Éxitos Latinos", "Carlos Vives", "Mexico", 2016, "Carlos Vives", "Carlos Vives", "Sony Music Latin", "Miami, FL"), listaCancionesAlbum, listalinksalbum);
    // Ahora podemos imprimir o hacer lo que sea necesario con la lista de canciones en el album.
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
Artista crearArtista()
{
    int id, idCancion, idVersion;
    string nomReal, nomArtist, paisOrigen, instrumInter;

    // Solicitar información al usuario
    cout << "Ingrese el ID del artista: ";
    cin >> id;
    cout << "Ingrese el ID de la canción asociada: ";
    cin >> idCancion;
    cout << "Ingrese el ID de la versión asociada: ";
    cin >> idVersion;
    cin.ignore(); // Limpiar el buffer de entrada

    cout << "Ingrese el nombre real del artista: ";
    getline(cin, nomReal);

    cout << "Ingrese el nombre artístico del artista: ";
    getline(cin, nomArtist);

    cout << "Ingrese el país de origen del artista: ";
    getline(cin, paisOrigen);

    cout << "Ingrese el instrumento/interés musical del artista: ";
    getline(cin, instrumInter);

    // Crear el objeto Artista con los datos ingresados
    return Artista(id, idCancion, idVersion, nomReal, nomArtist, paisOrigen, instrumInter);
}
Album crear_album()
{
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
Cancion crear_cancion()
{
    int id, id_album, numArtistasPrincipales, anioPublicacion;
    string nombreCancion, nom_artistico, duracion, composLetra, composMusica, arrMusic;
    string ciudadGrabacion, paisGrabacion, genero;

    // Solicitar información al usuario
    cout << "Ingrese el ID de la canción: ";
    cin >> id;
    cout << "Ingrese el ID del álbum: ";
    cin >> id_album;
    cin.ignore(); // Limpiar el buffer de entrada

    cout << "Ingrese el nombre de la canción: ";
    getline(cin, nombreCancion);

    cout << "Ingrese el nombre artístico: ";
    getline(cin, nom_artistico);

    cout << "Ingrese la duración de la canción (formato: mm:ss): ";
    getline(cin, duracion);

    cout << "Ingrese el número de artistas principales: ";
    cin >> numArtistasPrincipales;
    cin.ignore(); // Limpiar el buffer de entrada

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
    cin.ignore(); // Limpiar el buffer de entrada

    cout << "Ingrese el género de la canción: ";
    getline(cin, genero);

    // Crear el objeto Cancion con los datos ingresados
    return Cancion(id, id_album, nombreCancion, nom_artistico, genero, anioPublicacion, duracion, composLetra, composMusica, arrMusic, ciudadGrabacion, paisGrabacion, numArtistasPrincipales);
}
Version crearVersion()
{
    int idVersion, idCancion, anio;
    string tituloVer, tipVersion, artistaPrin, ciudadGrab, paisGra, genero;

    cout << "Ingrese el ID de la versión: ";
    cin >> idVersion;
    cout << "Ingrese el ID de la canción asociada: ";
    cin >> idCancion;
    cin.ignore(); // Limpiar el buffer de entrada

    cout << "Ingrese el título de la versión: ";
    getline(cin, tituloVer);

    cout << "Ingrese el tipo de versión (por ejemplo, 'remix', 'versión acústica'): ";
    getline(cin, tipVersion);

    cout << "Ingrese el artista principal de la versión: ";
    getline(cin, artistaPrin);

    cout << "Ingrese el año de la versión: ";
    cin >> anio;
    cin.ignore(); // Limpiar el buffer de entrada

    cout << "Ingrese la ciudad de grabación (opcional): ";
    getline(cin, ciudadGrab);

    cout << "Ingrese el país de grabación (opcional): ";
    getline(cin, paisGra);

    cout << "Ingrese el género de la versión (opcional): ";
    getline(cin, genero);

    // Crear el objeto Version con los datos ingresados
    return Version(idVersion, idCancion, tituloVer, tipVersion, artistaPrin, anio, ciudadGrab, paisGra, genero);
}
Links crearLink()
{
    int id, idCancion, idAlbum, idVersion;
    string nomPlat, linkAlbum, linkCancion;

    // Solicitar información al usuario
    cout << "Ingrese el ID del link: ";
    cin >> id;

    cout << "Ingrese el ID de la canción: ";
    cin >> idCancion;

    cout << "Ingrese el ID del álbum: ";
    cin >> idAlbum;

    cout << "Ingrese el ID de la versión: ";
    cin >> idVersion;
    cin.ignore(); // Limpiar el buffer de entrada

    cout << "Ingrese el nombre de la plataforma: ";
    getline(cin, nomPlat);

    cout << "Ingrese el link del álbum: ";
    getline(cin, linkAlbum);

    cout << "Ingrese el link de la canción: ";
    getline(cin, linkCancion);

    // Crear el objeto Links con los datos ingresados
    return Links(id, idCancion, idAlbum, idVersion, nomPlat, linkAlbum, linkCancion);
}

int main()
{
    insertar_prueba();
    Album album_ins;
    Cancion cancion_ins;
    Version version_ins;
    MiVector<Cancion> listaCanciones;
    MiVector<Links> listalinkscancion, listalinksalbum, listalinkversion;
    MiVector<Artista> listaArtistas, lista_artis_vers;
    MiVector<nodo_versiones> listaVersiones;
    MiVector<nodo_canciones> listaCancionesAlbum;
    Cancion::leerDesdeArchivo("ArchivosPlanos/canciones.txt");
    Artista::leerDesdeArchivo("ArchivosPlanos/artistas.txt");
    Links::leerDesdeArchivo("ArchivosPlanos/links.txt");
    Album::leerDesdeArchivo("ArchivosPlanos/albums.txt");
    Version::leerDesdeArchivo("ArchivosPlanos/versiones.txt");
    
    for(int i=1; i<=albums_archivo.size(); i++ ){
        album_ins.buscarAlbumConRelacionados(i);
    }
    
    
    int opcion;
    do
    {
        mostrarMenu();
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            listalinkscancion.clear();
            listaArtistas.clear();
            listaVersiones.clear();
            listalinkversion.clear();
            listalinksalbum.clear();
            listaCancionesAlbum.clear();
            lista_artis_vers.clear();

            album_ins = crear_album();
            int num_canciones;
            cout << "¿Cuántas canciones tiene el álbum? Ingrese la cantidad: ";
            cin >> num_canciones;

            for (int i = 1; i <= num_canciones; i++)
            {
                cout << " ---- Canción #" << i << " ----" << endl;
                cancion_ins = crear_cancion();

                int num_links;
                cout << "¿En cuántas plataformas se encuentra esta canción?: ";
                cin >> num_links;

                listalinkscancion.clear();
                for (int j = 1; j <= num_links; j++)
                {
                    cout << "  -> Link canción #" << j << ": " << endl;
                    listalinkscancion.push_back(crearLink());
                }

                int num_versiones;
                cout << "¿Cuántas versiones tiene esta canción?: ";
                cin >> num_versiones;

                for (int k = 1; k <= num_versiones; k++)
                {
                    cout << "  -> Versión #" << k << " de la canción:" << endl;
                    version_ins = crearVersion();

                    int num_artistas_version;
                    cout << "¿Cuántos artistas tiene esta versión?: ";
                    cin >> num_artistas_version;

                    lista_artis_vers.clear();
                    for (int m = 1; m <= num_artistas_version; m++)
                    {
                        cout << "  -> Artista de versión #" << m << ": " << endl;
                        lista_artis_vers.push_back(crearArtista());
                    }

                    int num_links_version;
                    cout << "¿En cuántas plataformas se encuentra esta versión?: ";
                    cin >> num_links_version;

                    listalinkversion.clear();
                    for (int j = 1; j <= num_links_version; j++)
                    {
                        cout << "  -> Link versión #" << j << ": " << endl;
                        listalinkversion.push_back(crearLink());
                    }

                    listaVersiones.push_back(version_ins.insertar_version(version_ins, lista_artis_vers, listalinkversion));
                }

                int num_artistas;
                cout << "¿Cuántos artistas tiene esta canción?: ";
                cin >> num_artistas;

                listaArtistas.clear();
                for (int k = 1; k <= num_artistas; k++)
                {
                    cout << "  -> Artista canción #" << k << ": " << endl;
                    listaArtistas.push_back(crearArtista());
                }

                listaCancionesAlbum.push_back(cancion_ins.insertar_cancion(cancion_ins, listalinkscancion, listaArtistas));
            }

            int num_links_album;
            cout << "¿En cuántas plataformas se encuentra este álbum?: ";
            cin >> num_links_album;

            listalinksalbum.clear();
            for (int k = 1; k <= num_links_album; k++)
            {
                cout << "  -> Link álbum #" << k << ": " << endl;
                listalinksalbum.push_back(crearLink());
            }

            album_ins.insertar_album(album_ins, listaCancionesAlbum, listalinksalbum);
            cout << "Álbum insertado correctamente." << endl;
            break;

        case 2:
            listalinkscancion.clear();
            listaArtistas.clear();
            listaVersiones.clear();

            cancion_ins = crear_cancion();

            int cantidad_links, cantidad_versiones, cantidad_artistas, cantidad_links_version;

            cout << "Ingresa los links para esta canción, ¿En cuántas plataformas se encuentra?: ";
            cin >> cantidad_links;
            for (int j = 1; j <= cantidad_links; j++)
            {
                cout << "  -> Link canción #" << j << ": ";
                listalinkscancion.push_back(crearLink());
            }

            cout << "¿Cuántas versiones tiene esta canción?: ";
            cin >> cantidad_versiones;
            for (int k = 1; k <= cantidad_versiones; k++)
            {
                cout << "  -> Versión canción #" << k << ": ";
                version_ins = crearVersion();

                lista_artis_vers.clear();
                cout << "¿Cuántos artistas tiene esta versión?: ";
                cin >> cantidad_artistas;
                for (int m = 1; m <= cantidad_artistas; m++)
                {
                    cout << "  -> Artista de versión #" << m << ": ";
                    lista_artis_vers.push_back(crearArtista());
                }

                listalinkversion.clear();
                cout << "¿En cuántas plataformas se encuentra esta versión?: ";
                cin >> cantidad_links_version;
                for (int j = 1; j <= cantidad_links_version; j++)
                {
                    cout << "  -> Link versión #" << j << ": ";
                    listalinkversion.push_back(crearLink());
                }

                listaVersiones.push_back(version_ins.insertar_version(version_ins, lista_artis_vers, listalinkversion));
            }

            listaArtistas.clear();
            cout << "¿Cuántos artistas tiene esta canción?: ";
            cin >> cantidad_artistas;
            for (int k = 1; k <= cantidad_artistas; k++)
            {
                cout << "  -> Artista canción #" << k << ": ";
                listaArtistas.push_back(crearArtista());
            }

            cancion_ins.insertar_cancion(cancion_ins, listalinkscancion, listaArtistas);

            cout << "Canción creada exitosamente." << endl;
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
    Cancion::guardarEnArchivo("ArchivosPlanos/canciones.txt");
    Artista::guardarEnArchivo("ArchivosPlanos/artistas.txt");
    Links::guardarEnArchivo("ArchivosPlanos/links.txt");
    Album::guardarEnArchivo("ArchivosPlanos/albums.txt");
    Version::guardarEnArchivo("ArchivosPlanos/versiones.txt");
    return 0;
}
