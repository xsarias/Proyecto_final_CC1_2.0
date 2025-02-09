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
    listalinksalbum.push_back(Links(0, 1, 0, "spotify", "https://open.spotify.com/intl-es/album/0YLrAWUbY0nyM7PFtqnYld?si=1kZOq6xZRLu_sQFkT-ALWw", ""));
    listalinksalbum.push_back(Links(0, 1, 0, "youtube", "https://youtube.com/playlist?list=OLAK5uy_nttgDeXu2YSQIFRbzBvyHu_FuYzznbgWg&si=71klPGOS79S5wRqI", ""));
    
    
    listaCanciones.push_back(Cancion(1, 1, "Quisiera", "CNCO", "pop", 2016, "00:03:05", "Sebastian Yatra", "Luis Veleza", "Sofia Perez", "Miami", "US", 5));
    listalinkscancion.push_back(Links(1, 0, 0, "youtube", "https://youtube.com/playlist?list=OLAK5uy_nttgDedsyufhdeu=sjdhdej", "https://youtube.com/playlist?list=OLAK5uy_nttgDeXu2YSQIFRbzBvyHu_FuYzznbgWg&si=71klPGOS79S5wRqI"));

    listaCanciones.push_back(Cancion(2, 1, "Tu luz", "CNCO", "balada", 2016, "00:03:53", "Richard Camacho", "Luis Veleza", "Sofia Perez", "Miami", "US", 5));
    listaCanciones.push_back(Cancion(3, 1, "Cien", "CNCO", "pop", 2016, "00:03:07", "Saray Rojas", "Maria Magdalena", "Andres Botia", "Miami", "US", 5));
    listaCanciones.push_back(Cancion(4, 1, "Más Allá", "CNCO", "pop", 2016, "00:03:40", "Saray Rojas", "Maria Magdalena", "Andres Botia", "Miami", "US", 5));
    listaCanciones.push_back(Cancion(5, 1, "Para enamorarte", "CNCO", "pop", 2016, "00:03:07", "Saray Rojas", "Maria Magdalena", "Andres Botia", "Miami", "US", 5));
    listaCanciones.push_back(Cancion(6, 1, "Tan Fácil", "CNCO", "pop", 2016, "00:04:07", "Saray Rojas", "Maria Magdalena", "Andres Botia", "Miami", "US", 5));
    listaCanciones.push_back(Cancion(7, 1, "Primera cita", "CNCO", "pop", 2016, "00:02:57", "Saray Rojas", "Maria Magdalena", "Andres Botia", "Miami", "US", 5));
    listaCanciones.push_back(Cancion(8, 1, "cometa", "CNCO", "pop", 2016, "00:03:28", "Santiago Lopez", "Alejandra Murillo", "Andres Botia", "Miami", "US", 5));
    listaCanciones.push_back(Cancion(9, 1, "Volverte a ver", "CNCO", "pop", 2016, "00:03:00", "Saray Rojas", "Maria Magdalena", "Marisol Guerrero", "Miami", "US", 5));
    listaCanciones.push_back(Cancion(10, 1, "Reggaeton Lento", "CNCO", "reggaeton", 2016, "00:02:48", "Saray Rojas", "Maria Magdalena", "Marisol Guerrero", "Miami", "US", 5));
    listaArtistas.push_back(Artista(1, 8, 0, "Joel Pimentel de Leon", "DE LEON", "México", "voz"));
    listaArtistas.push_back(Artista(2, 8,  0, "Christopher Velez", "Chris", "Ecuador", "guitarra"));
    
    listaCancionesAlbum.push_back(cancioncita.insertar_cancion(listaCanciones[1], listalinkscancion, listaArtistas, listaVersiones ));

    lista_artis_vers.push_back(Artista(3, 0, 1, "Juan Luis Morera Luna", "Wisin", "Puerto Rico", "voz"));
    listalinkversion.push_back(Links(0, 0, 1, "apple music", "", "https://music.apple.com/us/album/random/1440833094?i=1440833101"));
    listaVersiones.push_back(vers.insertar_version(Version(1, 6, "Tan Facil(feat. Wisim)-Urban Remix", "remix", "Wisin", 2017, "Lima", "Perú", "urbano"), lista_artis_vers, listalinkversion));
    
}
void mostrarMenu() {
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
    MiVector<nodo_canciones> listaCancionesAlbum;
    MiVector<Artista> listaArtistas, lista_artis_vers;
    MiVector<Links> listalinkscancion, listalinksalbum, listalinkversion;
    Album album;
    album.insertar_album(Album(1, "Thriller", "Michael Jackson", "EE. UU.", 1982, "thriller_cover.jpg", "John Smith", "Epic Records", "Westlake Recording Studios"), listaCancionesAlbum, listalinksalbum);
    album.insertar_album(Album(1, "Thriller", "jaime", "EE. UU.", 1982, "thriller_cover.jpg", "John Smith", "Epic Records", "Westlake Recording Studios"), listaCancionesAlbum, listalinksalbum);
    album.insertar_album(Album(1, "Thriller", "Michael Jackson", "EE. UU.", 1982, "thriller_cover.jpg", "John Smith", "Epic Records", "Westlake Recording Studios"), listaCancionesAlbum, listalinksalbum);
    album.consultar_por_atributo("titulo", 1, "Michael Jackson");
    /*
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

    return 0;*/
}
