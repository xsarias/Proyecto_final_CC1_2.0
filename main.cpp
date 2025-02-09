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
    listalinkscancion.push_back(Links(1, "Spotify", "https://open.spotify.com/album/123", "https://open.spotify.com/track/456"));
    listalinkscancion.push_back(Links(2, "Apple Music", "https://music.apple.com/album/789", "https://music.apple.com/track/012"));
    listalinkscancion.push_back(Links(3, "Spotify", "https://open.spotify.com/album/456", "https://open.spotify.com/track/789"));
    listalinkscancion.push_back(Links(4, "Apple Music", "https://music.apple.com/album/123", "https://music.apple.com/track/345"));
    
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
    listaVersiones.push_back(vers.insertar_version(Version(1, "Titulo1", "Oficial", 2023, "Madrid", "España", "Rock", "Guitarra"), listaArtistas, listalinkscancion));
    cancionInsertada = cancioncita.insertar_cancion(Cancion(3, "Smells Like Teen Spirit", "Nirvana", "Grunge", 1991, "5:01"), listalinkscancion, listaArtistas, listaVersiones);
    listaCancionesAlbum.push_back(cancionInsertada);
    
    // Caso de prueba 4: Insertar un álbum con canciones y enlaces
    listalinksalbum.push_back(Links(2, "Youtube", "https://youtube.com/album/789", "https://music.apple.com/track/012"));
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
