#include <iostream>
#include "Librerias/Links.h"
#include "Librerias/MiVector.h"
#include "Links.cpp"
using namespace std;

int main() {
	// ---------------------------------------------------------------------------------------------
	// para probar los metodos de archivado de Links
	// ---------------------------------------------------------------------------------------------
	MiVector<Links> listaLinks;

    // Agregamos algunos Links con ID
    listaLinks.push_back(Links(1, "Spotify", "https://spotify.com/album1", "https://spotify.com/song1"));
    listaLinks.push_back(Links(2, "Apple Music", "https://apple.com/album2", "https://apple.com/song2"));
    listaLinks.push_back(Links(3, "YouTube", "https://youtube.com/album3", "https://youtube.com/song3"));

    // Guardamos en archivo
    string archivo = "links.txt";
    Links::guardarEnArchivo(archivo, listaLinks);
    cout << "Links guardados en archivo." << endl;

    // Limpiamos la lista y la volvemos a cargar desde el archivo
    listaLinks.clear();
    Links::leerDesdeArchivo(archivo, listaLinks);

    // Mostramos los links cargados
    cout << "Links cargados desde archivo:" << endl;
    for (size_t i = 1; i <= listaLinks.size(); i++) {  // Desde 1 por MiVector
        cout << listaLinks[i].obtenerLink() << endl;
    }

    return 0;
}


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
