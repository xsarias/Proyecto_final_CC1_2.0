#include "Librerias/Cancion.h"
#include "Librerias/MiVector.h"
#include <iostream>
#include <vector>
#include <string>
#include <utility> // Para std::pair

void consultaNumeroVersiones(int numeroVersiones) {
    MiVector<Cancion> listaCanciones;
    Cancion::leerDesdeArchivo("canciones.txt", listaCanciones);

    // Vector para almacenar pares de género y año, junto con el contador de canciones
    std::vector<std::pair<std::pair<std::string, int>, int>> cancionesPorGeneroYAnio;

    for (size_t i = 1; i <= listaCanciones.size(); i++) {
        Cancion cancion = listaCanciones[i];
        int numVersiones = Cancion::contarVersiones(cancion.getNombreCancion());

        if (numVersiones >= numeroVersiones) {
            std::string genero = cancion.getGenero();
            int anioPublicacion = cancion.getAnioPublicacion();

            // Buscar si ya existe una entrada para este género y año
            bool encontrado = false;
            for (size_t j = 0; j < cancionesPorGeneroYAnio.size(); j++) {
                if (cancionesPorGeneroYAnio[j].first.first == genero &&
                    cancionesPorGeneroYAnio[j].first.second == anioPublicacion) {
                    // Incrementar el contador de canciones para este género y año
                    cancionesPorGeneroYAnio[j].second++;
                    encontrado = true;
                    break;
                }
            }

            // Si no se encontró una entrada existente, agregar una nueva
            if (!encontrado) {
                cancionesPorGeneroYAnio.push_back({{genero, anioPublicacion}, 1});
            }
        }
    }

    // Mostrar los resultados
    for (const auto& entry : cancionesPorGeneroYAnio) {
        std::string genero = entry.first.first;
        int anio = entry.first.second;
        int numCanciones = entry.second;

        std::cout << "Género: " << genero << ", Año: " << anio
                  << " - Número de canciones: " << numCanciones << std::endl;
    }
}

int main() {
    int numeroVersiones;
    std::cout << "Ingrese el número mínimo de versiones: ";
    std::cin >> numeroVersiones;

    consultaNumeroVersiones(numeroVersiones);

    return 0;
}