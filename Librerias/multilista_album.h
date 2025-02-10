#ifndef MULTILISTA_ALBUM_H
#define MULTILISTA_ALBUM_H
#include <iostream>
#include <string>
#include "MiVector.h"
#include "estructuras.h"
#include "busqueda_binaria.h"
#include "ordenador_vectores.h"
using namespace std;

class Multilista_album{
    int num_dat, num_cab, cab;
     // Contadores de datos y cabeceras
    MiVector<cabeza>lista_cabeceras; // Puntero a la lista de cabeceras
    MiVector<nodo_album>lista_datos;      // Puntero al primer nodo de datos

public:
    Multilista_album() { 
        num_dat=0;
        num_cab=0; 
    }

    void insertar(nodo_album Dato);
    void insertar(cabeza Cabeza);
    bool Multilista_vacia();
    string retornar_dato(int x,  std::string parametro);
    int retornar_pos(int x, std::string parametro);
    void ordenar_alfabeticamente(int pos, std::string dato, std::string atributo, std::string apuntador);
    void ordenar_alfabeticamente_centinelas(int pos, std::string dato, std::string atributo, std::string apuntador);
    MiVector<nodo_album> consulta_por_atributo(std:: string atributo, int cab, std::string contex, string clav_orden);
    bool lista_llena();
    MiVector<nodo_busqueda> obtener_vectorOrdenado(string atributo, int cabecera);
};

void Multilista_album:: insertar(nodo_album Dato) {
    
    lista_datos.push_back(Dato);
    num_dat = lista_datos.size();
    ordenar_alfabeticamente(num_dat, lista_datos[num_dat].titulo, "titulo", "sig_titulo");
    cout<<"titulo"<<endl;
    ordenar_alfabeticamente(num_dat, lista_datos[num_dat].nom_artis, "nom_artis", "sig_nomArtis");
    cout<<"nom_artis"<<endl;
    ordenar_alfabeticamente(num_dat, lista_datos[num_dat].anio_pub, "anio_pub", "sig_anioPublic");
    cout<<"anio_pub"<<endl;
    ordenar_alfabeticamente_centinelas(num_dat, lista_datos[num_dat].cover, "cover", "sig_cover");
    cout<<"cover"<<endl;
    ordenar_alfabeticamente_centinelas(num_dat, lista_datos[num_dat].estudio_grab, "estudio_grab", "sig_estudioGrab");
    cout<<"estudi"<<endl;
    ordenar_alfabeticamente_centinelas(num_dat, lista_datos[num_dat].fotografia, "fotografia", "sig_fotografia");
    cout<<"fotogra"<<endl;
    ordenar_alfabeticamente_centinelas(num_dat, lista_datos[num_dat].editora, "editora", "sig_editora");
    cout<<"editora"<<endl;
}
void Multilista_album::insertar(cabeza Cabeza) {
    lista_cabeceras.push_back(Cabeza);
    num_cab++;
}
void Multilista_album::ordenar_alfabeticamente(int pos, std::string dato, std::string atributo, std::string apuntador){
    int pos_cab;
    if(atributo == "titulo"){
        pos_cab = 1;
        cab = lista_cabeceras[pos_cab].pos_cabeza;
        if (cab == 0 || dato < retornar_dato(cab, atributo)){
            lista_datos[pos].sig_titulo= cab;
            lista_cabeceras[pos_cab].pos_cabeza = pos;
        } else {
            int ant = cab;
            int sig = retornar_pos(cab, apuntador);

            while (sig != 0 && dato > retornar_dato(sig, atributo)) {
                ant = sig;
                sig = retornar_pos(sig, apuntador);
            }
            lista_datos[pos].sig_titulo = sig;
            lista_datos[ant].sig_titulo = pos;
        }

    }else if(atributo == "nom_artis"){
        pos_cab=2;
        cab = lista_cabeceras[pos_cab].pos_cabeza;
        if (cab == 0 || dato < retornar_dato(cab, atributo)){
            lista_datos[pos].sig_nomArtis = cab;
            lista_cabeceras[pos_cab].pos_cabeza = pos;
        } else {
            int ant = cab;
            int sig = retornar_pos(cab, apuntador);

            while (sig != 0 && dato > retornar_dato(sig, atributo)) {
                ant = sig;
                sig = retornar_pos(sig, apuntador);
            }
            lista_datos[pos].sig_nomArtis = sig;
            lista_datos[ant].sig_nomArtis = pos;
        }
    }else if(atributo== "anio_pub"){
        pos_cab=3;
        cab = lista_cabeceras[pos_cab].pos_cabeza;
        if (cab == 0 || dato < retornar_dato(cab, atributo)){
            lista_datos[pos].sig_anioPublic = cab;
            lista_cabeceras[pos_cab].pos_cabeza = pos;
        } else {
            int ant = cab;
            int sig = retornar_pos(cab, apuntador);

            while (sig != 0 && dato > retornar_dato(sig, atributo)) {
                ant = sig;
                sig = retornar_pos(sig, apuntador);
            }
            lista_datos[pos].sig_anioPublic = sig;
            lista_datos[ant].sig_anioPublic = pos;
        }
    }
}
void Multilista_album::ordenar_alfabeticamente_centinelas(int pos, string dato, string atributo, string apuntador){
    int pos_cab;
    if(atributo == "cover"){
        pos_cab = 4;
        cab = lista_cabeceras[pos_cab].pos_cabeza;
        if (cab == 0 || dato < retornar_dato(cab, atributo)){
            lista_datos[pos].sig_cover = cab;
            lista_cabeceras[pos_cab].pos_cabeza = pos;
        } else {
            int ant = cab;
            int sig = retornar_pos(cab, apuntador);

            while (sig != 0 && dato > retornar_dato(sig, atributo)) {
                ant = sig;
                sig = retornar_pos(sig, apuntador);
            }
            lista_datos[pos].sig_cover = sig;
            lista_datos[ant].sig_cover = pos;
        }
    }else if(atributo == "fotografia"){
        pos_cab = 5;
        cab = lista_cabeceras[pos_cab].pos_cabeza;
        if (cab == 0 || dato < retornar_dato(cab, atributo)){
            lista_datos[pos].sig_fotografia = cab;
            lista_cabeceras[pos_cab].pos_cabeza = pos;
        } else {
            int ant = cab;
            int sig = retornar_pos(cab, apuntador);

            while (sig != 0 && dato > retornar_dato(sig, atributo)) {
                ant = sig;
                sig = retornar_pos(sig, apuntador);
            }
            lista_datos[pos].sig_fotografia = sig;
            lista_datos[ant].sig_fotografia = pos;
        }
    }else if(atributo == "estudio_grab"){
        pos_cab = 6;
        cab = lista_cabeceras[pos_cab].pos_cabeza;
        if (cab == 0 || dato < retornar_dato(cab, atributo)){
            lista_datos[pos].sig_estudioGrab= cab;
            lista_cabeceras[pos_cab].pos_cabeza = pos;
        } else {
            int ant = cab;
            int sig = retornar_pos(cab, apuntador);

            while (sig != 0 && dato > retornar_dato(sig, atributo)) {
                ant = sig;
                sig = retornar_pos(sig, apuntador);
            }
            lista_datos[pos].sig_estudioGrab = sig;
            lista_datos[ant].sig_estudioGrab= pos;
        }
    }else if(atributo == "editora"){
        pos_cab = 7;
        cab = lista_cabeceras[pos_cab].pos_cabeza;
        if (cab == 0 || dato < retornar_dato(cab, atributo)){
            lista_datos[pos].sig_editora = cab;
            lista_cabeceras[pos_cab].pos_cabeza = pos;
        } else {
            int ant = cab;
            int sig = retornar_pos(cab, apuntador);

            while (sig != 0 && dato > retornar_dato(sig, atributo)) {
                ant = sig;
                sig = retornar_pos(sig, apuntador);
            }
            lista_datos[pos].sig_editora = sig;
            lista_datos[ant].sig_editora = pos;
        }
    }

}

bool Multilista_album::Multilista_vacia() {
    return num_dat == 0;
}

bool Multilista_album::lista_llena(){
    return false; // Con punteros, no hay límite fijo de tamaño
}
int Multilista_album::retornar_pos(int x, std::string parametro){
    if (parametro == "sig_titulo") return lista_datos[x].sig_titulo;
    if (parametro == "sig_nomArtis") return lista_datos[x].sig_nomArtis;
    if (parametro == "sig_cover") return lista_datos[x].sig_cover;
    if (parametro == "sig_fotografia") return lista_datos[x].sig_fotografia;
    if (parametro == "sig_editora") return lista_datos[x].sig_editora;
    if (parametro == "sig_anioPublic") return lista_datos[x].sig_anioPublic;
    if (parametro == "sig_estudioGrab") return lista_datos[x].sig_estudioGrab;
    if (parametro == "pos_cabeza") return lista_cabeceras[x].pos_cabeza;
    if (parametro == "sig_estudioGrab") return lista_datos[x].sig_estudioGrab;
    return -1;
}

string Multilista_album::retornar_dato(int x, std::string parametro) {
    if (parametro == "titulo") return lista_datos[x].titulo;
    if (parametro == "nom_artis") return lista_datos[x].nom_artis;
    if (parametro == "cover") return lista_datos[x].cover;
    if (parametro == "fotografia") return lista_datos[x].fotografia;
    if (parametro == "editora") return lista_datos[x].editora;
    if (parametro == "estudio_grab") return lista_datos[x].estudio_grab;
    if (parametro == "anio_pub") return lista_datos[x].anio_pub;
    return "Parámetro desconocido";
}
MiVector<nodo_album> Multilista_album::consulta_por_atributo(std::string atributo, int cabecera, std::string contex, string clav_orden) {
    cout << "Llegué al método de búsqueda binaria" << endl;

    // Realizar la búsqueda binaria
    Busqueda_binaria consultados(obtener_vectorOrdenado(atributo, cabecera), contex);
    MiVector<int> lista_consultada = consultados.busquedaBinaria();
    MiVector<nodo_album> list_porAtributo;
    nodo_album aux ;
    //Crear un vector con los nevos nodos.
    if (lista_consultada.size() == 0) {
        return list_porAtributo;  // Retorna una lista vacía si no hay coincidencias
    }

    for (int i = 1; i <= lista_consultada.size(); i++) {
        if (lista_consultada[i] >= 1 && lista_consultada[i] <= lista_datos.size()) {
            list_porAtributo.push_back(lista_datos[lista_consultada[i]]);
        }
    }
    if (clav_orden == "anio_pub") {
        list_porAtributo = ordenarVector(list_porAtributo, &nodo_album::anio_pub);
    } else if (clav_orden == "titulo") {
        list_porAtributo = ordenarVector(list_porAtributo, &nodo_album::titulo);
    }
    return list_porAtributo;
   
}
MiVector<nodo_busqueda> Multilista_album:: obtener_vectorOrdenado(string atributo, int cabecera){
   
    MiVector<nodo_busqueda> lista_busqueda;
    cab = retornar_pos(cabecera, "pos_cabeza");
    int actual = cab;
    while (actual != 0) { // 0 indica el final de la lista
        nodo_busqueda elemento_busqueda;
        elemento_busqueda.indice = actual; // Guarda la posición en lista_datos
        elemento_busqueda.clave = retornar_dato(actual, atributo); // Obtiene el valor del atributo
        cout<<elemento_busqueda.clave<<endl;
        lista_busqueda.push_back(elemento_busqueda);

        // Avanzar al siguiente elemento en la lista ordenada
        if (atributo == "titulo") {
            actual = lista_datos[actual].sig_titulo;
        } else if (atributo == "nom_artis") {
            actual = lista_datos[actual].sig_nomArtis;
        } else if (atributo == "anio_pub") {
            actual = lista_datos[actual].sig_anioPublic;
        } else if (atributo == "cover") {
            actual = lista_datos[actual].sig_cover;
        } else if (atributo == "fotografia") {
            actual = lista_datos[actual].sig_fotografia;
        } else if (atributo == "estudio_grab") {
            actual = lista_datos[actual].sig_estudioGrab;
        } else if (atributo == "editora") {
            actual = lista_datos[actual].sig_editora;
        } else {
            cout << "Atributo no válido: " << atributo << endl;
        }
    }
    return lista_busqueda;

}

#endif