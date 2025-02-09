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
void insertar_prueba(){
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

    //album #1
    // Limpiamos los vectores antes de comenzar a agregar nuevas canciones
    listalinkscancion.clear();
    listaArtistas.clear();
    listaVersiones.clear();
    listaCanciones.push_back(Cancion(1, 1, "Quisiera", "CNCO", "pop", 2016, "00:03:05", "Sebastian Yatra", "Luis Veleza", "Sofia Perez", "Miami", "US", 5));
    listaCanciones.push_back(Cancion(2, 1, "Tu luz", "CNCO", "balada", 2016, "00:03:53", "Richard Camacho", "Luis Veleza", "Sofia Perez", "Miami", "US", 5));
    listaCanciones.push_back(Cancion(3, 1, "Cien", "CNCO", "pop", 2016, "00:03:07", "Saray Rojas", "Maria Magdalena", "Andres Botia", "Miami", "US", 5));
    listaCanciones.push_back(Cancion(4, 1, "Más Allá", "CNCO", "pop", 2016, "00:03:40", "Saray Rojas", "Maria Magdalena", "Andres Botia", "Miami", "US", 5));
    listaCanciones.push_back(Cancion(5, 1, "Para enamorarte", "CNCO", "pop", 2016, "00:03:07", "Saray Rojas", "Maria Magdalena", "Andres Botia", "Miami", "US", 5));
    listaCanciones.push_back(Cancion(6, 1, "Tan Fácil", "CNCO", "pop", 2016, "00:04:07", "Saray Rojas", "Maria Magdalena", "Andres Botia", "Miami", "US", 5));
    listaCanciones.push_back(Cancion(7, 1, "Primera cita", "CNCO", "pop", 2016, "00:02:57", "Saray Rojas", "Maria Magdalena", "Andres Botia", "Miami", "US", 5));
    listaCanciones.push_back(Cancion(8, 1, "cometa", "CNCO", "pop", 2016, "00:03:28", "Santiago Lopez", "Alejandra Murillo", "Andres Botia", "Miami", "US", 5));
    listaCanciones.push_back(Cancion(9, 1, "Volverte a ver", "CNCO", "pop", 2016, "00:03:00", "Saray Rojas", "Maria Magdalena", "Marisol Guerrero", "Miami", "US", 5));
    listaCanciones.push_back(Cancion(10, 1, "Reggaeton Lento", "CNCO", "reggaeton", 2016, "00:02:48", "Saray Rojas", "Maria Magdalena", "Marisol Guerrero", "Miami", "US", 5));
    // Canción 1
    listalinkscancion.push_back(Links(3, 1, 0, 0, "youtube", "https://youtube.com/playlist?list=OLAK5uy_nttgDedsyufhdeu=sjdhdej", "https://youtube.com/playlist?list=OLAK5uy_nttgDeXu2YSQIFRbzBvyHu_FuYzznbgWg&si=71klPGOS79S5wRqI"));
    listaArtistas.push_back(Artista(1, 8, 0, "Joel Pimentel de Leon", "DE LEON", "México", "voz"));
    listaArtistas.push_back(Artista(2, 8, 0, "Christopher Velez", "Chris", "Ecuador", "guitarra"));
    cout << "inserteeeee";
    listaCancionesAlbum.push_back(cancioncita.insertar_cancion(listaCanciones[1], listalinkscancion, listaArtistas, listaVersiones));
    cout<< "toy aqui";
    // Limpiamos los vectores para la siguiente canción
    listalinkscancion.clear();
    listaArtistas.clear();
    listaVersiones.clear();

    // Canción 2
    listalinkscancion.push_back(Links(5, 2, 0, 0, "spotify", "https://open.spotify.com/intl/song/K5uy_nttgDeefedsyufhdeu=sjdhde=ejfejj", "https://youtube.com/playlist?list=OLAK5uy_nttgDeXu2YSQIFRbzBvyHu_FuYzznbgWg&si=71klPGOS79S5wRqI"));
    listaArtistas.push_back(Artista(3, 2, 0, "Zabdiel de Jesús", "Zabdiel", "Puerto Rico", "piano"));
    listaArtistas.push_back(Artista(4, 2, 0, "Erick Brian Colon", "Erick", "Cuba", "guitarra"));
    listaCancionesAlbum.push_back(cancioncita.insertar_cancion(listaCanciones[2], listalinkscancion, listaArtistas, listaVersiones));

    // Limpiamos los vectores para la siguiente canción
    listalinkscancion.clear();
    listaArtistas.clear();
    listaVersiones.clear();

    // Canción 3
    listalinkscancion.push_back(Links(6, 3, 0, 0, "youtube", "https://youtube.com/playlist?list=OLAK5uy_nttgDedsyufhdeu=sjdhdej", "https://youtube.com/playlist?list=OLAK5uy_nttgDeXu2YSQIFRbzBvyHu_FuYzznbgWg&si=71klPGOS79S5wRqI"));
    listaArtistas.push_back(Artista(5, 3, 0, "Saray Rojas", "Saray", "Colombia", "voz"));
    listaArtistas.push_back(Artista(6, 3, 0, "Maria Magdalena", "Magdalena", "México", "bajo"));
    listaCancionesAlbum.push_back(cancioncita.insertar_cancion(listaCanciones[3], listalinkscancion, listaArtistas, listaVersiones));

    // Limpiamos los vectores para la siguiente canción
    listalinkscancion.clear();
    listaArtistas.clear();
    listaVersiones.clear();

    // Canción 4
    listalinkscancion.push_back(Links(7, 4, 0, 0, "spotify", "https://open.spotify.com/intl/song/K5uy_nttgDeefedsyufhdeu=sjdhde=ejfejj", "https://youtube.com/playlist?list=OLAK5uy_nttgDeXu2YSQIFRbzBvyHu_FuYzznbgWg&si=71klPGOS79S5wRqI"));
    listaArtistas.push_back(Artista(7, 4, 0, "Andres Botia", "Botia", "Colombia", "batería"));
    listaArtistas.push_back(Artista(8, 4, 0, "Sofia Perez", "Sofia", "Argentina", "teclado"));
    listaCancionesAlbum.push_back(cancioncita.insertar_cancion(listaCanciones[4], listalinkscancion, listaArtistas, listaVersiones));

    // Limpiamos los vectores para la siguiente canción
    listalinkscancion.clear();
    listaArtistas.clear();
    listaVersiones.clear();

    // Canción 5
    listalinkscancion.push_back(Links(8, 5, 0, 0, "youtube", "https://youtube.com/playlist?list=OLAK5uy_nttgDedsyufhdeu=sjdhdej", "https://youtube.com/playlist?list=OLAK5uy_nttgDeXu2YSQIFRbzBvyHu_FuYzznbgWg&si=71klPGOS79S5wRqI"));
    listaArtistas.push_back(Artista(9, 5, 0, "Luis Veleza", "Veleza", "México", "voz"));
    listaArtistas.push_back(Artista(10, 5, 0, "Santiago Lopez", "Santiago", "Colombia", "guitarra"));
    listaCancionesAlbum.push_back(cancioncita.insertar_cancion(listaCanciones[5], listalinkscancion, listaArtistas, listaVersiones));

    // Limpiamos los vectores para la siguiente canción
    listalinkscancion.clear();
    listaArtistas.clear();
    listaVersiones.clear();

    // Canción 6
    listalinkscancion.push_back(Links(9, 6, 0, 0, "spotify", "https://open.spotify.com/intl/song/K5uy_nttgDeefedsyufhdeu=sjdhde=ejfejj", "https://youtube.com/playlist?list=OLAK5uy_nttgDeXu2YSQIFRbzBvyHu_FuYzznbgWg&si=71klPGOS79S5wRqI"));
    listaArtistas.push_back(Artista(11, 6, 0, "Alejandra Murillo", "Alejandra", "México", "voz"));
    listaArtistas.push_back(Artista(12, 6, 0, "Marisol Guerrero", "Marisol", "Colombia", "bajo"));
    listaCancionesAlbum.push_back(cancioncita.insertar_cancion(listaCanciones[6], listalinkscancion, listaArtistas, listaVersiones));

    // Limpiamos los vectores para la siguiente canción
    listalinkscancion.clear();
    listaArtistas.clear();
    listaVersiones.clear();

    // Canción 7
    listalinkscancion.push_back(Links(10, 7, 0, 0, "youtube", "https://youtube.com/playlist?list=OLAK5uy_nttgDedsyufhdeu=sjdhdej", "https://youtube.com/playlist?list=OLAK5uy_nttgDeXu2YSQIFRbzBvyHu_FuYzznbgWg&si=71klPGOS79S5wRqI"));
    listaArtistas.push_back(Artista(13, 7, 0, "Richard Camacho", "Richard", "Ecuador", "voz"));
    listaArtistas.push_back(Artista(14, 7, 0, "Saray Rojas", "Saray", "Colombia", "guitarra"));
    listaCancionesAlbum.push_back(cancioncita.insertar_cancion(listaCanciones[7], listalinkscancion, listaArtistas, listaVersiones));

    // Limpiamos los vectores para la siguiente canción
    listalinkscancion.clear();
    listaArtistas.clear();
    listaVersiones.clear();

    // Canción 8
    listalinkscancion.push_back(Links(11, 8, 0, 0, "spotify", "https://open.spotify.com/intl/song/K5uy_nttgDeefedsyufhdeu=sjdhde=ejfejj", "https://youtube.com/playlist?list=OLAK5uy_nttgDeXu2YSQIFRbzBvyHu_FuYzznbgWg&si=71klPGOS79S5wRqI"));
    listaArtistas.push_back(Artista(15, 8, 0, "Juan Luis Morera Luna", "Wisin", "Puerto Rico", "voz"));
    listaArtistas.push_back(Artista(16, 8, 0, "Christopher Velez", "Chris", "Ecuador", "guitarra"));
    listaCancionesAlbum.push_back(cancioncita.insertar_cancion(listaCanciones[8], listalinkscancion, listaArtistas, listaVersiones));

    // Limpiamos los vectores para la siguiente canción
    listalinkscancion.clear();
    listaArtistas.clear();
    listaVersiones.clear();

    // Canción 9
    listalinkscancion.push_back(Links(12, 9, 0, 0, "youtube", "https://youtube.com/playlist?list=OLAK5uy_nttgDedsyufhdeu=sjdhdej", "https://youtube.com/playlist?list=OLAK5uy_nttgDeXu2YSQIFRbzBvyHu_FuYzznbgWg&si=71klPGOS79S5wRqI"));
    listaArtistas.push_back(Artista(17, 9, 0, "Zabdiel de Jesús", "Zabdiel", "Puerto Rico", "piano"));
    listaArtistas.push_back(Artista(18, 9, 0, "Erick Brian Colon", "Erick", "Cuba", "guitarra"));
    listaCancionesAlbum.push_back(cancioncita.insertar_cancion(listaCanciones[9], listalinkscancion, listaArtistas, listaVersiones));

    // Limpiamos los vectores para la siguiente canción
    listalinkscancion.clear();
    listaArtistas.clear();
    listaVersiones.clear();

    // Canción 10
    listalinkscancion.push_back(Links(13, 10, 0, 0, "spotify", "https://open.spotify.com/intl/song/K5uy_nttgDeefedsyufhdeu=sjdhde=ejfejj", "https://youtube.com/playlist?list=OLAK5uy_nttgDeXu2YSQIFRbzBvyHu_FuYzznbgWg&si=71klPGOS79S5wRqI"));
    listaArtistas.push_back(Artista(19, 10, 0, "Saray Rojas", "Saray", "Colombia", "voz"));
    listaArtistas.push_back(Artista(20, 10, 0, "Maria Magdalena", "Magdalena", "México", "bajo"));
    listaCancionesAlbum.push_back(cancioncita.insertar_cancion(listaCanciones[10], listalinkscancion, listaArtistas, listaVersiones));

    // Insertamos el álbum con todas las canciones
    album.insertar_album(Album(1, "Primera Cita", "CNCO", "US", 2016, "Edward Frank", "Luisa Restrepo", "Sony Music Latin", "5020 studio miami"), listaCancionesAlbum, listalinksalbum);

}
void mostrarMenu() {
    insertar_prueba();
    cout << "Menú:" << endl;
    cout << "1. Insertar álbumes." << endl;
    cout << "2. Insertar canciones." << endl;
    cout << "3. Insertar versiones." << endl;
    cout << "4. Eliminar álbumes." << endl;
    cout << "5. Eliminar canciones." << endl;
    cout << "6. Eliminar versiones." << endl;
    cout << "7. Realizar consultas" <<endl;
    cout << "8. Salir" << endl;
    cout << "Seleccione una opción: ";
}
void menu_consultas(){
    cout << "Menú consultas:" << endl;
    //clasificada por año de publicación y nombre artistico.
    cout << "1. Albúm de una editora." << endl;
    //clasificados por año y país de grabación.
    cout << "2. Albumes y canciones grabados en un estudio dado." << endl;
    //clasificado por ciudad de grabación. Incluyendo arreglista, autores de letra y de la música.
    cout << "3. Canciones cuya duración es mayor a un tiempo dado." << endl;
    //Incluir nombre de la canción, nombre artístico y los datos del artista que interpreta el instrumento.
    cout << "4. Listado de canciones de un género y un instrumento dado." << endl;
    //clasificado por género y año de la grabación.
    cout << "5. Número de canciones que tienen una cantidad de versiones mayor o igual a un número dado." << endl;
    //Incluir el título de la versión, nombre artista principal, género, año, país de publicación, nombre obra original, 
    //plataformas en las que se encuentra
    cout << "6. Versiones que pertenecen a un tipo de versión dada, que se encuentren en más de una plataforma." << endl;
    //Incluir nombre de la plataforma y link.
    cout << "7. Links de las plataformas donde se encuentra una canción dada y sus versiones." <<endl;
    //Clasificado por género y año de publicación. Incluyendo nombre del encargado, el género y el año.
    cout << "8. Número de canciones y versiones que ha creado cada encargado del cover." << endl;
    //Clasificado por país de grabación.
    cout << "9. Albumes dado el nombre del encargado de fotografía y del estudio de grabación." << endl;
    //incluyendo género, año, nombre canción, album al que pertenece, número plataformas en las que se encuentra.
    cout << "10. Canciones escritas por un compositor de letra dado." << endl;
    cout << "11. Volver al menú principal"<<endl;
    cout << "Seleccione una opción: ";
}

int main() {
    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;
        switch (opcion) {
            case 1:
                cout << "Opción para insertar álbumes" << endl;
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
                do{
                    menu_consultas();
                    switch(op_cons){
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
                }while(op_cons!=11);
                
                break;
            default:
                cout << "Opción no válida. Intente nuevamente." << endl;
        }
    } while (opcion != 8);

    return 0;
}
