#include <iostream>
#include "Cancion.cpp"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {

	Cancion cancion("Bohemian Rhapsody", "queen", "Rock", 1975, "0:05:55",
                    "Freddie Mercury", "Freddie Mercury", "Queen",
                    "Londres", "Reino Unido", 4);
	
	cancion.insertar_cabeceras();
	cancion.insertar_cancion(cancion);
	Cancion cancion2("cho", "maria", "Rock", 1975, "0:05:55",
		"Freddie Mercury", "Freddie Mercury", "Queen",
		"Londres", "Reino Unido", 4);
	//cancion.mostrarInformacion();
	cancion2.insertar_cancion(cancion2);
	Cancion cancion3("cho", "aries", "Rock", 1975, "0:05:55",
		"Freddie Mercury", "Freddie Mercury", "Queen",
		"Londres", "Reino Unido", 4);
	cancion.insertar_cancion(cancion3);
	cancion.imprimir_lista("nombre_artistico",1);
	
	return 0;

}
