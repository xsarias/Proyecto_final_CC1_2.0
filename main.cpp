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

    // Agregamos algunos datos de prueba
    listaLinks.push_back(Links("Spotify", "https://spotify.com/album1", "https://spotify.com/song1"));
    listaLinks.push_back(Links("YouTube", "https://youtube.com/album2", "https://youtube.com/song2"));
    listaLinks.push_back(Links("Apple Music", "https://apple.com/album3", "https://apple.com/song3"));

    // Guardar en archivo
    cout << "Guardando en archivo 'links.txt'..." << endl;
    Links::guardarEnArchivo("links.txt", listaLinks);

    // Limpiar la lista para verificar la lectura
    listaLinks.clear();

    // Leer desde archivo
    cout << "Leyendo desde archivo 'links.txt'..." << endl;
    Links::leerDesdeArchivo("links.txt", listaLinks);

    // Mostrar los datos leídos
    cout << "\nContenido de la lista después de leer del archivo:" << endl;
    for (size_t i = 1; i <= listaLinks.size(); i++) {
        cout << "Plataforma: " << listaLinks[i].getNomPlat() << endl;
        cout << "Álbum: " << listaLinks[i].getLinkAlbum() << endl;
        cout << "Canción: " << listaLinks[i].getLinkCancion() << endl;
        cout << "---------------------------" << endl;
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
