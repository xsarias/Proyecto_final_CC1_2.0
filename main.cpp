#include <iostream>
#include "Librerias/Cancion.h"
#include "Librerias/Links.h"
#include "Librerias/Artista.h"
#include "Librerias/MiVector.h"
#include "Librerias/Version.h"
#include "Cancion.cpp"
#include "Artista.cpp"
#include "Links.cpp"
#include "Versiones.cpp"

using namespace std;

int main() {
    MiVector<Version> listaVersiones;

    // Crear algunas versiones
    Version v1(1, "Bohemian Rhapsody", "Studio", 1975, "Londres", "Reino Unido", "Rock", "Queen");
    Version v2(2, "Imagine", "Live", 1971, "Nueva York", "EE.UU.", "Soft Rock", "John Lennon");
    Version v3(3, "Hotel California", "Acoustic", 1976, "Los Ángeles", "EE.UU.", "Rock", "Eagles");

    // Insertarlas en la lista
    listaVersiones.push_back(v1);
    listaVersiones.push_back(v2);
    listaVersiones.push_back(v3);

    // Guardar en archivo
    string nombreArchivo = "versiones.txt";
    Version::guardarEnArchivo(nombreArchivo, listaVersiones);
    cout << "Se han guardado las versiones en " << nombreArchivo << endl;

    // Limpiar la lista y leer desde el archivo
    listaVersiones.clear();
    Version::leerDesdeArchivo(nombreArchivo, listaVersiones);
    cout << "Se han leído las versiones desde el archivo:" << endl;

    // Mostrar las versiones leídas
    for (size_t i = 1; i <= listaVersiones.size(); i++) {
        cout << "ID: " << listaVersiones[i].getIdVersion()
             << ", Título: " << listaVersiones[i].getTituloVer()
             << ", Tipo: " << listaVersiones[i].getTipVersion()
             << ", Año: " << listaVersiones[i].getAnio()
             << ", Ciudad: " << listaVersiones[i].getCiudadGrab()
             << ", País: " << listaVersiones[i].getPaisGra()
             << ", Género: " << listaVersiones[i].getGenero()
             << ", Artista: " << listaVersiones[i].getArrMusic() << endl;
    }

    return 0;
}
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
