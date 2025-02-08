#include <iostream>
#include "Librerias/Cancion.h"
#include "Librerias/Links.h"
#include "Librerias/Artista.h"
#include "Librerias/MiVector.h"
#include "Cancion.cpp"
#include "Artista.cpp"
#include "Links.cpp"


using namespace std;


int main() {
    MiVector<Artista> listaArtistas;

    // Agregar artistas a la lista
    listaArtistas.push_back(Artista(1, "Freddie Mercury", "Queen", "Reino Unido", "Voz, Piano"));
    listaArtistas.push_back(Artista(2, "Kurt Cobain", "Nirvana", "EE.UU.", "Voz, Guitarra"));
    listaArtistas.push_back(Artista(3, "David Gilmour", "Pink Floyd", "Reino Unido", "Guitarra, Voz"));

    // Guardar la lista en archivo
    Artista::guardarEnArchivo("artistas.txt", listaArtistas);

    // Limpiar la lista para simular la carga desde archivo
    listaArtistas.clear();
    cout << "Lista de artistas vaciada." << endl;

    // Leer la lista desde el archivo
    Artista::leerDesdeArchivo("artistas.txt", listaArtistas);

    // Mostrar artistas cargados
    cout << "Lista de artistas cargados desde el archivo:" << endl;
    for (size_t i = 1; i <= listaArtistas.size(); i++) {
        cout << "ID: " << listaArtistas[i].getId() << ", "
             << "Nombre Real: " << listaArtistas[i].getNomReal() << ", "
             << "Nombre Artístico: " << listaArtistas[i].getNomArtist() << ", "
             << "País: " << listaArtistas[i].getPaisOrigen() << ", "
             << "Instrumento: " << listaArtistas[i].getInstrumInter() << endl;
    }

    return 0;
}
// int main() {
//     MiVector<Cancion> listaCanciones;

//     // Agregar algunas canciones de prueba
//     listaCanciones.push_back(Cancion(1, "Bohemian Rhapsody", "Queen", "Rock", 1975, "5:55"));
//     listaCanciones.push_back(Cancion(2, "Imagine", "John Lennon", "Soft Rock", 1971, "3:07"));
//     listaCanciones.push_back(Cancion(3, "Smells Like Teen Spirit", "Nirvana", "Grunge", 1991, "5:01"));

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
