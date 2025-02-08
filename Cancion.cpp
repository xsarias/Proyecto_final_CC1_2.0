#include "Librerias/Cancion.h"
#include <iostream>
#include <fstream>
#include "Librerias/MiVector.h"

void Cancion :: imprimir_lista(string parametro, int pos_cab) {
    // Obtener la posición inicial de la cabeza para el orden del parámetro
    int cab = multi_cancion.retornar_pos(pos_cab, "pos_cabeza");
    int cont;
    if (cab < 0) {
        cout << "La lista está vacía o no se ha ordenado." << endl;
        return;
    }
    cout << "Lista de " << multi_cancion.retornar_dato(pos_cab, "nombreCabeza") << ":" << endl;
    int pos_actual=cab;
    cont= 1;
    while (pos_actual != 0){
        // Obtener y mostrar el nombre de la canción actual
        string caracteristica = multi_cancion.retornar_dato(pos_actual, parametro);
        cout << cont << "). Nombre canción: " << multi_cancion.retornar_dato(pos_actual, "nom_cancion") << endl;
        cout << parametro << " -> " << caracteristica << endl;
        cont++;

        // Pasar al siguiente elemento en la lista
        if (parametro == "nombre_artistico") {
            pos_actual = multi_cancion.retornar_pos(pos_actual, "sig_nombre_artistico");
        } else if (parametro == "anio") {
            pos_actual = multi_cancion.retornar_pos(pos_actual, "sig_anio");
        } else if (parametro == "nombre_cancion") {
            pos_actual = multi_cancion.retornar_pos(pos_actual, "sig_cancion");
        } else if (parametro == "compositor") {
            pos_actual = multi_cancion.retornar_pos(pos_actual, "sig_compositor");
        } else if (parametro == "interprete") {
            pos_actual = multi_cancion.retornar_pos(pos_actual, "sig_interprete");
        } else {
            // Si el parámetro no coincide con ninguno de los anteriores, salir del bucle
            cout << "Parámetro no válido." << endl;
            break;
        }
    }
}
void  Cancion :: insertar_cabeceras(){
    //Posición de las cabezas
    multi_cancion.insertar(nombre_artis);//1
    multi_cancion.insertar(nom_cancion);//2
    multi_cancion.insertar(comp_let);  //3
    multi_cancion.insertar(comp_music);  //4
    multi_cancion.insertar(pais); //5
    multi_cancion.insertar(ciudad);  //6
    multi_cancion.insertar(genero_); //7
    multi_cancion.insertar(anio_pub); //8

}
nodo_canciones  Cancion :: insertar_cancion(Cancion cancion, MiVector<Links> links, MiVector<Artista> artista){
    nodo_canciones cancion_nueva;
    cancion_nueva.nom_cancion = cancion.nombreCancion;
    cancion_nueva.nom_artistico = cancion.nom_artistico;
    cancion_nueva.arrMusic = cancion.arrMusic;
    cancion_nueva.anioPublicacion = cancion.anioPublicacion;
    cancion_nueva.arrMusic = cancion.arrMusic;
    cancion_nueva.ciudadGrabacion = cancion.ciudadGrabacion;
    cancion_nueva.composLetra = cancion.ciudadGrabacion;
    cancion_nueva.composMusica = cancion.composLetra;
    cancion_nueva.duracion = cancion.duracion;
    cancion_nueva.genero = cancion.genero;
    for(int i=1; i<artista.size(); i++){
        cancion_nueva.list_artist.push_back(artista[i].insertar_artista(artista[i]));
    }
    for(int i=1; i<=links.size(); i++){
        cancion_nueva.list_links.push_back(links[i].insertar_link(links[i]));
    }
    multi_cancion.insertar(cancion_nueva);
    cout<<"canción insertada"<<endl;
    return cancion_nueva;
}
void Cancion :: insertar_artista(Artista artista){
    artista.insertar_artista(artista);
}

// Método para guardar la lista de Canciones en un archivo
void Cancion::guardarEnArchivo(const string& nombreArchivo, const MiVector<Cancion>& lista) {
    ofstream archivo(nombreArchivo);
    if (!archivo) {
        cerr << "Error al abrir el archivo para escritura." << endl;
        return;
    }

    for (size_t i = 1; i <= lista.size(); i++) {
        archivo << lista[i].getId() << ","
                << lista[i].getNombreCancion() << ","
                << lista[i].getNomArtistico() << ","
                << lista[i].getGenero() << ","
                << lista[i].getAnioPublicacion() << ","
                << lista[i].getDuracion() << endl;
    }

    archivo.close();
}

// Método para leer la lista de Canciones desde un archivo
void Cancion::leerDesdeArchivo(const string& nombreArchivo, MiVector<Cancion>& lista) {
    ifstream archivo(nombreArchivo);
    if (!archivo) {
        cerr << "Error al abrir el archivo para lectura." << endl;
        return;
    }

    lista.clear();

    int id, anioPublicacion;
    string nombreCancion, nomArtistico, genero, duracion;
    while (archivo >> id) {
        archivo.ignore();
        getline(archivo, nombreCancion, ',');
        getline(archivo, nomArtistico, ',');
        getline(archivo, genero, ',');
        archivo >> anioPublicacion;
        archivo.ignore();
        getline(archivo, duracion);
        lista.push_back(Cancion(id, nombreCancion, nomArtistico, genero, anioPublicacion, duracion));
    }

    archivo.close();
}