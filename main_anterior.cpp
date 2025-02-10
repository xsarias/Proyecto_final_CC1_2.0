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

// Limpiamos los vectores antes de comenzar a agregar nuevas canciones
listalinksalbum.push_back(Links(11, 0, 2, 0, "spotify", "https://open.spotify.com/intl-es/album/0LrNWpYtxu1v9tb4VR7SIn?si=1kZOq6xZRLu_sQFkT-ALWw", ""));
listalinksalbum.push_back(Links(12, 0, 2, 0, "youtube", "https://youtube.com/playlist?list=PLRXmrOeEmWB1OYYXfeGpPht9Q0Q8Wpo6i", ""));

listalinkscancion.clear();
listaArtistas.clear();
listaVersiones.clear();
listaCanciones.push_back(Cancion(11, 2, "Solo Tú", "Carlos Vives", "vallenato", 2019, "00:03:35", "Carlos Vives", "Luis Veleza", "Sofia Perez", "Santa Marta", "Colombia", 2));
listaCanciones.push_back(Cancion(12, 2, "La Bicicleta", "Carlos Vives & Shakira", "pop", 2016, "00:03:51", "Carlos Vives", "Luis Veleza", "Sofia Perez", "Barranquilla", "Colombia", 1));
listaCanciones.push_back(Cancion(13, 2, "Bailando", "Enrique Iglesias", "pop", 2014, "00:04:00", "Enrique Iglesias", "Luis Veleza", "Sofia Perez", "Miami", "US", 3));
listaCanciones.push_back(Cancion(14, 2, "Despacito", "Luis Fonsi & Daddy Yankee", "reggaeton", 2017, "00:03:49", "Luis Fonsi", "Daddy Yankee", "Sofia Perez", "San Juan", "Puerto Rico", 4));
listaCanciones.push_back(Cancion(15, 2, "Dákiti", "Bad Bunny & Jhay Cortez", "reggaeton", 2020, "00:03:34", "Bad Bunny", "Jhay Cortez", "Sofia Perez", "San Juan", "Puerto Rico", 6));
listaCanciones.push_back(Cancion(16, 2, "Mienteme", "Maria Becerra & TINI", "pop", 2021, "00:03:14", "Maria Becerra", "TINI", "Sofia Perez", "Buenos Aires", "Argentina", 2));
listaCanciones.push_back(Cancion(17, 2, "Me Gusta", "Shakira & Anuel AA", "reggaeton", 2019, "00:03:34", "Shakira", "Anuel AA", "Sofia Perez", "Barranquilla", "Colombia", 3));
listaCanciones.push_back(Cancion(18, 2, "Felices los 4", "Maluma", "reggaeton", 2017, "00:03:43", "Maluma", "Sofia Perez", "Luis Veleza", "Medellín", "Colombia", 3));
listaCanciones.push_back(Cancion(19, 2, "Vivir Mi Vida", "Marc Anthony", "salsa", 2013, "00:04:13", "Marc Anthony", "Luis Veleza", "Sofia Perez", "New York", "US", 1));
listaCanciones.push_back(Cancion(20, 2, "La Gozadera", "Gente de Zona & Marc Anthony", "salsa", 2015, "00:04:02", "Gente de Zona", "Marc Anthony", "Sofia Perez", "Havana", "Cuba", 2));

// Canción 1
listalinkscancion.push_back(Links(14, 11, 0, 0, "spotify", "https://open.spotify.com/intl-es/song/0g58YNff7p7O2zH4dVoNjL", "https://youtube.com/playlist?list=PLRXmrOeEmWB1OYYXfeGpPht9Q0Q8Wpo6i"));
listaArtistas.push_back(Artista(19, 11, 0, "Carlos Vives", "Carlos", "Colombia", "voz"));
listaArtistas.push_back(Artista(20, 11, 0, "Carlos Vives", "Carlos", "Colombia", "guitarra"));
listaCancionesAlbum.push_back(cancioncita.insertar_cancion(listaCanciones[1], listalinkscancion, listaArtistas));

// Limpiamos los vectores para la siguiente canción
listalinkscancion.clear();
listaArtistas.clear();
listaVersiones.clear();

// Canción 2
listalinkscancion.push_back(Links(15, 12, 0, 0, "spotify", "https://open.spotify.com/intl-es/song/1eRrrv52hIfG3jdQHk7ftY", "https://youtube.com/playlist?list=PLRXmrOeEmWB1OYYXfeGpPht9Q0Q8Wpo6i"));
listaArtistas.push_back(Artista(21, 12, 0, "Shakira", "Shakira", "Colombia", "voz"));
listaArtistas.push_back(Artista(22, 12, 0, "Carlos Vives", "Carlos", "Colombia", "guitarra"));
listaCancionesAlbum.push_back(cancioncita.insertar_cancion(listaCanciones[2], listalinkscancion, listaArtistas));

// Limpiamos los vectores para la siguiente canción
listalinkscancion.clear();
listaArtistas.clear();
listaVersiones.clear();

// Canción 3
listalinkscancion.push_back(Links(16, 13, 0, 0, "youtube", "https://www.youtube.com/watch?v=fGcD7gn5D94", "https://www.youtube.com/watch?v=VAy8oFLdrT4"));
listaArtistas.push_back(Artista(23, 13, 0, "Enrique Iglesias", "Enrique", "España", "voz"));
listaArtistas.push_back(Artista(24, 13, 0, "Descemer Bueno", "Descemer", "Cuba", "piano"));
listaCancionesAlbum.push_back(cancioncita.insertar_cancion(listaCanciones[3], listalinkscancion, listaArtistas));

// Limpiamos los vectores para la siguiente canción
listalinkscancion.clear();
listaArtistas.clear();
listaVersiones.clear();

// Canción 4
listalinkscancion.push_back(Links(17, 14, 0, 0, "spotify", "https://open.spotify.com/intl-es/song/5wsAjh6chhGklfpzFb08", "https://www.youtube.com/watch?v=kJQP7kiw5Fk"));
listaArtistas.push_back(Artista(25, 14, 0, "Luis Fonsi", "Luis", "Puerto Rico", "voz"));
listaArtistas.push_back(Artista(26, 14, 0, "Daddy Yankee", "Daddy", "Puerto Rico", "rap"));
listaCancionesAlbum.push_back(cancioncita.insertar_cancion(listaCanciones[4], listalinkscancion, listaArtistas));

// Limpiamos los vectores para la siguiente canción
listalinkscancion.clear();
listaArtistas.clear();
listaVersiones.clear();

// Canción 5
listalinkscancion.push_back(Links(18, 15, 0, 0, "youtube", "https://www.youtube.com/watch?v=ckFv18fe0tY", "https://www.youtube.com/watch?v=md3hZbbphWg"));
listaArtistas.push_back(Artista(27, 15, 0, "Bad Bunny", "Bad Bunny", "Puerto Rico", "voz"));
listaArtistas.push_back(Artista(28, 15, 0, "Jhay Cortez", "Jhay", "Puerto Rico", "voz"));
listaCancionesAlbum.push_back(cancioncita.insertar_cancion(listaCanciones[5], listalinkscancion, listaArtistas));

// Limpiamos los vectores para la siguiente canción
listalinkscancion.clear();
listaArtistas.clear();
listaVersiones.clear();

// Canción 6
listalinkscancion.push_back(Links(19, 16, 0, 0, "spotify", "https://open.spotify.com/intl-es/song/5kmMdvscU0ZfdtFGW2dsOp", "https://www.youtube.com/watch?v=dGm2klCUxhI"));
listaArtistas.push_back(Artista(29, 16, 0, "Maria Becerra", "Maria", "Argentina", "voz"));
listaArtistas.push_back(Artista(30, 16, 0, "TINI", "TINI", "Argentina", "voz"));
listaCancionesAlbum.push_back(cancioncita.insertar_cancion(listaCanciones[6], listalinkscancion, listaArtistas));

// Limpiamos los vectores para la siguiente canción
listalinkscancion.clear();
listaArtistas.clear();
listaVersiones.clear();

// Canción 7
listalinkscancion.push_back(Links(20, 17, 0, 0, "spotify", "https://open.spotify.com/intl-es/song/0I8OtqH7j3hYY5B7aKxz7W", "https://www.youtube.com/watch?v=hpF5G9J3nBs"));
listaArtistas.push_back(Artista(31, 17, 0, "Shakira", "Shakira", "Colombia", "voz"));
listaArtistas.push_back(Artista(32, 17, 0, "Anuel AA", "Anuel", "Puerto Rico", "rap"));
listaCancionesAlbum.push_back(cancioncita.insertar_cancion(listaCanciones[7], listalinkscancion, listaArtistas));

// Limpiamos los vectores para la siguiente canción
listalinkscancion.clear();
listaArtistas.clear();
listaVersiones.clear();

// Canción 8
listalinkscancion.push_back(Links(21, 18, 0, 0, "spotify", "https://open.spotify.com/intl-es/song/0Mz7lF0jwYKmMLvmljYBSh", "https://www.youtube.com/watch?v=2kXiECXh_A0"));
listaArtistas.push_back(Artista(33, 18, 0, "Maluma", "Maluma", "Colombia", "voz"));
listaCancionesAlbum.push_back(cancioncita.insertar_cancion(listaCanciones[8], listalinkscancion, listaArtistas));

// Limpiamos los vectores para la siguiente canción
listalinkscancion.clear();
listaArtistas.clear();
listaVersiones.clear();

// Canción 9
listalinkscancion.push_back(Links(22, 19, 0, 0, "spotify", "https://open.spotify.com/intl-es/song/0zxmgJt9djVoSx5bbzXgl7", "https://www.youtube.com/watch?v=G2fTG_6tRvc"));
listaArtistas.push_back(Artista(34, 19, 0, "Marc Anthony", "Marc", "Puerto Rico", "voz"));
listaCancionesAlbum.push_back(cancioncita.insertar_cancion(listaCanciones[9], listalinkscancion, listaArtistas));

// Limpiamos los vectores para la siguiente canción
listalinkscancion.clear();
listaArtistas.clear();
listaVersiones.clear();

// Canción 10
listalinkscancion.push_back(Links(23, 20, 0, 0, "spotify", "https://open.spotify.com/intl-es/song/0z0ekC0ih2LVqxg5j8XftG", "https://www.youtube.com/watch?v=wntA1XBOaWk"));
listaArtistas.push_back(Artista(35, 20, 0, "Gente de Zona", "Gente de Zona", "Cuba", "voz"));
listaArtistas.push_back(Artista(36, 20, 0, "Marc Anthony", "Marc", "Puerto Rico", "voz"));
listaCancionesAlbum.push_back(cancioncita.insertar_cancion(listaCanciones[10], listalinkscancion, listaArtistas));
// Ahora podemos imprimir o hacer lo que sea necesario con la lista de canciones en el album.
album.insertar_album(Album(2, "Fiesta Tropical", "Carlos Vives", "Colombia", 2019, "Carlos Vives", "Carlos Vives", "Sony Music Latin", "Miami, FL"), listaCancionesAlbum, listalinksalbum);

using namespace std;
void insertar_prueba(){
    MiVector<Cancion> listaCanciones;
    MiVector<Links> listalinkscancion;
    MiVector<Links> listalinksalbum;
    MiVector<Artista> listaArtistas, lista_art2;
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

    
    // Caso de prueba 1: Agregar canciones de prueba
    listaCanciones.push_back(Cancion(1, "Bohemian Rhapsody", "Queen", "Rock", 1975, "5:55"));
    listaCanciones.push_back(Cancion(2, "Imagine", "John Lennon", "Soft Rock", 1971, "3:07"));
    listaCanciones.push_back(Cancion(3, "Smells Like Teen Spirit", "Nirvana", "Grunge", 1991, "5:01"));
    listaCanciones.push_back(Cancion(4, "Let It Be", "The Beatles", "Rock", 1970, "4:03"));
    listaCanciones.push_back(Cancion(5, "Yesterday", "The Beatles", "Pop", 1965, "2:05"));
    listaCanciones.push_back(Cancion(6, "Shape of You", "Ed Sheeran", "Pop", 2017, "3:53"));
    listaCanciones.push_back(Cancion(7, "Rolling in the Deep", "Adele", "Pop", 2010, "3:48"));
    listaCanciones.push_back(Cancion(8, "Stairway to Heaven", "Led Zeppelin", "Rock", 1971, "8:02"));
    listaCanciones.push_back(Cancion(9, "Purple Haze", "Jimi Hendrix", "Rock", 1967, "3:08"));
    listaCanciones.push_back(Cancion(10, "Hotel California", "Eagles", "Rock", 1976, "6:30"));
    
    // Enlaces para las canciones
    listalinkscancion.push_back(Links(1, 101, 201, "Spotify", "https://spotify.com/album/101", "https://spotify.com/track/123"));
    listalinkscancion.push_back(Links(3, 103, 203, "YouTube", "https://youtube.com/album/103", "https://youtube.com/track/345"));
    
    // Caso de prueba 2: Agregar artistas
    listaArtistas.push_back(Artista(1, "Paul David Hewson", "Bono", "Irlanda", "Rock"));
    listaArtistas.push_back(Artista(2, "Maroon 5", "Adam Levine", "EE. UU.", "Pop"));
    listaArtistas.push_back(Artista(3, "CNCO", "Joel Pimentel", "México", "Pop Latino"));
    listaArtistas.push_back(Artista(4, "Ed Sheeran", "Ed Sheeran", "Reino Unido", "Pop"));
    listaArtistas.push_back(Artista(5, "Adele", "Adele", "Reino Unido", "Pop"));
    listaArtistas.push_back(Artista(6, "The Beatles", "John Lennon, Paul McCartney, George Harrison, Ringo Starr", "Reino Unido", "Rock"));
    listaArtistas.push_back(Artista(7, "Led Zeppelin", "Robert Plant, Jimmy Page, John Paul Jones, John Bonham", "Reino Unido", "Rock"));
    listaArtistas.push_back(Artista(8, "Queen", "Freddie Mercury, Brian May, Roger Taylor, John Deacon", "Reino Unido", "Rock"));
    listaArtistas.push_back(Artista(9, "Jimi Hendrix", "Jimi Hendrix", "EE. UU.", "Rock"));
    listaArtistas.push_back(Artista(10, "Eagles", "Don Henley, Glenn Frey, Bernie Leadon, Randy Meisner", "EE. UU.", "Rock"));
    
    // Caso de prueba 3: Insertar versiones y canciones
    listaVersiones.push_back(vers.insertar_version(Version(1, 2, 3, "Titulo1", "Oficial", 2023, "Madrid", "España", "Rock", "Guitarra"), listaArtistas, listalinkscancion));
    cancionInsertada = cancioncita.insertar_cancion(Cancion(3, "Smells Like Teen Spirit", "Nirvana", "Grunge", 1991, "5:01"), listalinkscancion, listaArtistas, listaVersiones);
    listaCancionesAlbum.push_back(cancionInsertada);
    
    // Caso de prueba 4: Insertar un álbum con canciones y enlaces
    listalinksalbum.push_back(Links(4, 104, 204, "Deezer", "https://deezer.com/album/104", "https://deezer.com/track/456"));
    album.insertar_album(Album(1, "Thriller", "Michael Jackson", "EE. UU.", 1982, "thriller_cover.jpg", "John Smith", "Epic Records", "Westlake Recording Studios"), listaCancionesAlbum, listalinksalbum);
    album.insertar_album(Album(2, "Abbey Road", "The Beatles", "Reino Unido", 1969, "abbey_road_cover.jpg", "George Martin", "Apple Records", "Abbey Road Studios"), listaCancionesAlbum, listalinksalbum);
    cout<<"inserte hasta aca"<<endl;
    
    
    // Imprimir el nombre del artista del álbum insertado
    cout << albumInsertado.nom_artis << endl;
    
    // Guardar las canciones en un archivo
    string nombreArchivo = "canciones.txt";
    Cancion::guardarEnArchivo(nombreArchivo, listaCanciones);
    cout << "Canciones guardadas en " << nombreArchivo << endl;
    
    
}
int main() {
    insertar_prueba();
    /*MiVector<Cancion> listaCanciones;
    MiVector<Links> listalinkscancion;
    MiVector<Links> listalinksalbum;
    MiVector<Artista> listaartisas, lista_art2;
    MiVector<nodo_versiones>lista_versiones;
    MiVector<nodo_canciones>lista_canciones_album;
    nodo_album album_insertado;
    nodo_canciones cancion_insertada;
    nodo_versiones version;
    Album album;
    Cancion cancioncita;
    Version vers;
	cancioncita.insertar_cabeceras();
    album.insertar_cabeceras();
    vers.insertar_cabeceras();
    // Agregar algunas canciones de prueba
    listaCanciones.push_back(Cancion(1, "Bohemian Rhapsody", "Queen", "Rock", 1975, "5:55"));
    listaCanciones.push_back(Cancion(2, "Imagine", "John Lennon", "Soft Rock", 1971, "3:07"));
    listaCanciones.push_back(Cancion(3, "Smells Like Teen Spirit", "Nirvana", "Grunge", 1991, "5:01"));
    listalinkscancion.push_back(Links(1, "Spotify", "https://open.spotify.com/album/123", "https://open.spotify.com/track/456"));
    listalinkscancion.push_back(Links(2, "Apple Music", "https://music.apple.com/album/789", "https://music.apple.com/track/012"));
    listaartisas.push_back(Artista(1, "Paul David Hewson", "Bono", "Irlanda", "color"));
	listaartisas.push_back(Artista(2, "Maroon 5", "Bono", "Irlanda", "color2"));
    lista_art2.push_back(Artista(3, "CNCO", "NN", "España", "c"));
    lista_versiones.push_back(vers.insertar_version(Version(1, "Titulo1", "Oficial", 2023, "Madrid", "España", "Rock", "Guitarra"),listaartisas, listalinkscancion));
    cancion_insertada = cancioncita.insertar_cancion((Cancion(3, "Smells Like Teen Spirit", "Nirvana", "Grunge", 1991, "5:01")), listalinkscancion, listaartisas, lista_versiones);
    lista_canciones_album.push_back(cancion_insertada);
    listalinksalbum.push_back(Links(2, "Youtube", "https://youtube.com/album/789", "https://music.apple.com/track/012"));
    album.insertar_album(Album(1, "Thriller", "Michael Jackson", "EE. UU.", 1982, "thriller_cover.jpg", "John Smith", "Epic Records", "Westlake Recording Studios"), lista_canciones_album, listalinksalbum);
    for(int i=1; i<= cancion_insertada.list_artist.size(); i++){
        cout<< cancion_insertada.list_artist[i].instru_interpre;
    }
    cout<< album_insertado.nom_artis;
    
    // Guardar las canciones en un archivo
    string nombreArchivo = "canciones.txt";
    Cancion::guardarEnArchivo(nombreArchivo, listaCanciones);
    cout << "Canciones guardadas en " << nombreArchivo << endl;
    // Limpiar la lista y volver a cargar desde el archivo
    MiVector<Cancion> listaRecuperada;
    Cancion::leerDesdeArchivo(nombreArchivo, listaRecuperada);
    cout << "Canciones cargadas desde el archivo:\n";

    // Mostrar las versiones leídas
    /*for (size_t i = 1; i <= listaVersiones.size(); i++) {
        cout << "ID: " << listaVersiones[i].getIdVersion()
             << ", Título: " << listaVersiones[i].getTituloVer()
             << ", Tipo: " << listaVersiones[i].getTipVersion()
             << ", Año: " << listaVersiones[i].getAnio()
             << ", Ciudad: " << listaVersiones[i].getCiudadGrab()
             << ", País: " << listaVersiones[i].getPaisGra()
             << ", Género: " << listaVersiones[i].getGenero()
             << ", Artista: " << listaVersiones[i].getArrMusic() << endl;
    }*/

    return 0;
}

// int main() {
//     MiVector<Cancion> listaCanciones;
//     MiVector<Links> listalinkscancion;
//     MiVector<Artista> listaartisas;
//     nodo_canciones cancion_insertada;
//     nodo_versiones version;
//     Cancion cancioncita;
// 	cancioncita.insertar_cabeceras();
//     // Agregar algunas canciones de prueba
//     listaCanciones.push_back(Cancion(1, "Bohemian Rhapsody", "Queen", "Rock", 1975, "5:55"));
//     listaCanciones.push_back(Cancion(2, "Imagine", "John Lennon", "Soft Rock", 1971, "3:07"));
//     listaCanciones.push_back(Cancion(3, "Smells Like Teen Spirit", "Nirvana", "Grunge", 1991, "5:01"));
//     listalinkscancion.push_back(Links(1, "Spotify", "https://open.spotify.com/album/123", "https://open.spotify.com/track/456"));
//     listalinkscancion.push_back(Links(2, "Apple Music", "https://music.apple.com/album/789", "https://music.apple.com/track/012"));
//     listaartisas.push_back(Artista(1, "Paul David Hewson", "Bono", "Irlanda", "color"));
// 	listaartisas.push_back(Artista(2, "Paul David Hewson", "Bono", "Irlanda", "color2"));
//     cancion_insertada = cancioncita.insertar_cancion((Cancion(3, "Smells Like Teen Spirit", "Nirvana", "Grunge", 1991, "5:01")), listalinkscancion, listaartisas);
//     for(int i=1; i<= cancion_insertada.list_artist.size(); i++){
//         cout<< cancion_insertada.list_artist[i].instru_interpre;
//     }
//     // Guardar las canciones en un archivo
//     string nombreArchivo = "canciones.txt";
//     Cancion::guardarEnArchivo(nombreArchivo, listaCanciones);
//     cout << "Canciones guardadas en " << nombreArchivo << endl;
//     // Limpiar la lista y volver a cargar desde el archivo
//     MiVector<Cancion> listaRecuperada;
//     Cancion::leerDesdeArchivo(nombreArchivo, listaRecuperada);
//     cout << "Canciones cargadas desde el archivo:\n";

//     // Mostrar las versiones leídas
//     for (size_t i = 1; i <= listaVersiones.size(); i++) {
//         cout << "ID: " << listaVersiones[i].getIdVersion()
//              << ", Título: " << listaVersiones[i].getTituloVer()
//              << ", Tipo: " << listaVersiones[i].getTipVersion()
//              << ", Año: " << listaVersiones[i].getAnio()
//              << ", Ciudad: " << listaVersiones[i].getCiudadGrab()
//              << ", País: " << listaVersiones[i].getPaisGra()
//              << ", Género: " << listaVersiones[i].getGenero()
//              << ", Artista: " << listaVersiones[i].getArrMusic() << endl;
//     }

//     return 0;
// }
// int main() {
//     MiVector<Cancion> listaCanciones;
//     MiVector<Links> listalinkscancion;
//     MiVector<Artista> listaartisas;
//     nodo_canciones cancion_insertada;
//     nodo_versiones version;
//     Cancion cancioncita;
//     // Agregar algunas canciones de prueba
//     listaCanciones.push_back(Cancion(1, "Bohemian Rhapsody", "Queen", "Rock", 1975, "5:55"));
//     listaCanciones.push_back(Cancion(2, "Imagine", "John Lennon", "Soft Rock", 1971, "3:07"));
//     listaCanciones.push_back(Cancion(3, "Smells Like Teen Spirit", "Nirvana", "Grunge", 1991, "5:01"));
//     listalinkscancion.push_back(Links(1, "Spotify", "https://open.spotify.com/album/123", "https://open.spotify.com/track/456"));
//     listalinkscancion.push_back(Links(2, "Apple Music", "https://music.apple.com/album/789", "https://music.apple.com/track/012"));
//     listaartisas.push_back(Artista(1, "Paul David Hewson", "Bono", "Irlanda", "Voz"));
//     cancion_insertada = cancioncita.insertar_cancion((Cancion(3, "Smells Like Teen Spirit", "Nirvana", "Grunge", 1991, "5:01")), listalinkscancion, listaartisas);
//     for(int i=1; i<= cancion_insertada.list_artist.size(); i++){
//         cout<< cancion_insertada.list_artist[i].instru_interpre;
//     };
//     // Guardar las canciones en un archivo
//     string nombreArchivo = "canciones.txt";
//     Cancion::guardarEnArchivo(nombreArchivo, listaCanciones);
//     cout << "Canciones guardadas en " << nombreArchivo << endl;
//     // Limpiar la lista y volver a cargar desde el archivo
//     MiVector<Cancion> listaRecuperada;
//     Cancion::leerDesdeArchivo(nombreArchivo, listaRecuperada);
//     cout << "Canciones cargadas desde el archivo:\n";

//     // Mostrar las canciones recuperadas
//     for (size_t i = 1; i <= listaRecuperada.size(); i++) {
//         cout << "ID: " << listaRecuperada[i].getId() << " | "
//              << "Nombre: " << listaRecuperada[i].getNombreCancion() << " | "
//              << "Artista: " << listaRecuperada[i].getNomArtistico() << " | "
//              << "Género: " << listaRecuperada[i].getGenero() << " | "
//              << "Año: " << listaRecuperada[i].getAnioPublicacion() << " | "
//              << "Duración: " << listaRecuperada[i].getDuracion() << endl;
//     }

//     return 0;
// }


// #include <iostream>
// #include "Librerias/Links.h"
// #include "Librerias/MiVector.h"
// #include "Links.cpp"
// using namespace std;

// int main() {
// 	// ---------------------------------------------------------------------------------------------
// 	// para probar los metodos de archivado de Links
// 	// ---------------------------------------------------------------------------------------------
// 	MiVector<Links> listaLinks;

//     // Agregamos algunos Links con ID
//     listaLinks.push_back(Links(1, "Spotify", "https://spotify.com/album1", "https://spotify.com/song1"));
//     listaLinks.push_back(Links(2, "Apple Music", "https://apple.com/album2", "https://apple.com/song2"));
//     listaLinks.push_back(Links(3, "YouTube", "https://youtube.com/album3", "https://youtube.com/song3"));

//     // Guardamos en archivo
//     string archivo = "links.txt";
//     Links::guardarEnArchivo(archivo, listaLinks);
//     cout << "Links guardados en archivo." << endl;

//     // Limpiamos la lista y la volvemos a cargar desde el archivo
//     listaLinks.clear();
//     Links::leerDesdeArchivo(archivo, listaLinks);

//     // Mostramos los links cargados
//     cout << "Links cargados desde archivo:" << endl;
//     for (size_t i = 1; i <= listaLinks.size(); i++) {  // Desde 1 por MiVector
//         cout << listaLinks[i].obtenerLink() << endl;
//     }

//     return 0;
// }


// #include <iostream>
// #include "Cancion.cpp"
// /* run this program using the console pauser or add your own getch, system("pause") or input loop */

// int main(int argc, char** argv) {

// 	Cancion cancion("Bohemian Rhapsody", "queen", "Rock", 1975, "0:05:55",
//                     "Freddie Mercury", "Freddie Mercury", "Queen",
//                     "Londres", "Reino Unido", 4);
	
// 	cancion.insertar_cabeceras();
// 	cancion.insertar_cancion(cancion);
// 	Cancion cancion2("cho", "maria", "Rock", 1975, "0:05:55",
// 		"Freddie Mercury", "Freddie Mercury", "Queen",
// 		"Londres", "Reino Unido", 4);
// 	//cancion.mostrarInformacion();
// 	cancion2.insertar_cancion(cancion2);
// 	Cancion cancion3("cho", "aries", "Rock", 1975, "0:05:55",
// 		"Freddie Mercury", "Freddie Mercury", "Queen",
// 		"Londres", "Reino Unido", 4);
// 	cancion.insertar_cancion(cancion3);
// 	cancion.imprimir_lista("nombre_artistico",1);
	
// 	return 0;

// }
