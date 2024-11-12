#include <iostream>
#include <fstream>
#include <string>

void crearArchivoCompilado() {
    std::string prompt;
    std::cout << "Introduce el contenido para el archivo: ";
    std::getline(std::cin, prompt);

    std::ofstream archivo("nombrearchivo.fxxstudio");
    if (archivo.is_open()) {
        archivo << prompt;
        archivo.close();
        std::cout << "Archivo 'nombrearchivo.fxxstudio' creado con éxito." << std::endl;
    } else {
        std::cerr << "Error al crear el archivo." << std::endl;
    }
}


void mostrarContenidoArchivo() {
    std::ifstream archivo("nombrearchivo.fxxstudio");
    if (archivo.is_open()) {
        std::string linea;
        std::cout << "Contenido del archivo 'nombrearchivo.fxxstudio':" << std::endl;
        while (std::getline(archivo, linea)) {
            std::cout << linea << std::endl;
        }
        archivo.close();
    } else {
        std::cerr << "Error al abrir el archivo." << std::endl;
    }
}
