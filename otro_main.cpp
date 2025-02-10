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

int main() {
    int numeroVersiones;
    cout << "Ingrese el número mínimo de versiones: ";
    cin >> numeroVersiones;

    consultaNumeroVersiones(numeroVersiones);

    return 0;
}