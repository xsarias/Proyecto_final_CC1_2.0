#ifndef BUSQUEDA_BINARIA_H
#define BUSQUEDA_BINARIA_H
#include <iostream>
#include <string>
#include "estructuras.h"
#include "MiVector.h"
using namespace std;

class Busqueda_binaria{
private:
    int inicio, fin, centinela, mitad;
    MiVector<int> lista_encontrados;
    MiVector<nodo_busqueda> lista_a_comsultar;
    std:: string referencia;
public:
    Busqueda_binaria(MiVector<nodo_busqueda> lista_busqueda, std::string contex):
    lista_a_comsultar(lista_busqueda), referencia(contex){
        inicio = 1;
        fin = lista_a_comsultar.size();
        centinela = 0;
    }
    MiVector<int> busquedaBinaria();

};
MiVector<int> Busqueda_binaria:: busquedaBinaria(){
    while (inicio <= fin && centinela == 0){
        mitad = (fin + inicio) / 2;
        if(referencia == lista_a_comsultar[mitad].clave){
            lista_encontrados.push_back(lista_a_comsultar[mitad].indice);
            while(lista_a_comsultar[mitad-1].clave == referencia && (mitad-1 != 0)){
                mitad = mitad - 1;
                lista_encontrados.push_back(lista_a_comsultar[mitad].indice);
            }
            mitad = (fin + inicio) / 2;
            while (lista_a_comsultar[mitad + 1].clave == referencia && (mitad+1 != 0)){
                mitad = mitad + 1;
                lista_encontrados.push_back(lista_a_comsultar[mitad].indice);
            }
            centinela = 1;
            return lista_encontrados;
        }else if(referencia < lista_a_comsultar[mitad].clave){
            fin = mitad -1;
        }else{
            inicio = mitad + 1;
        }
    }
    return lista_encontrados;
}

#endif