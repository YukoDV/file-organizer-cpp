#include <iostream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

int main() {

    std::string ruta;

    std::cout << "Ingrese la ruta de la carpeta: ";
    std::getline(std::cin, ruta);

    try {

        for (const auto& archivo : fs::directory_iterator(ruta)) {

            if (archivo.is_regular_file()) {

                std::string extension = archivo.path().extension().string();
                std::string carpetaDestino;

                // Clasificación de archivos
                if (extension == ".png" || extension == ".jpg" || extension == ".jpeg" || extension == ".gif") {
                    carpetaDestino = ruta + "/Imagenes";
                }
                else if (extension == ".mp4" || extension == ".avi" || extension == ".mkv") {
                    carpetaDestino = ruta + "/Videos";
                }
                else if (extension == ".pdf" || extension == ".docx" || extension == ".txt") {
                    carpetaDestino = ruta + "/Documentos";
                }
                else if (extension == ".zip" || extension == ".rar") {
                    carpetaDestino = ruta + "/Comprimidos";
                }
                else {
                    carpetaDestino = ruta + "/Otros";
                }

                // Crear carpeta si no existe
                if (!fs::exists(carpetaDestino)) {
                    fs::create_directory(carpetaDestino);
                }

                // Ruta destino
                fs::path destino = carpetaDestino + "/" + archivo.path().filename().string();

                // Mover archivo
                fs::rename(archivo.path(), destino);

                std::cout << "Movido: " << archivo.path().filename() << " -> " << carpetaDestino << std::endl;
            }
        }

        std::cout << "\nArchivos organizados correctamente.\n";

    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}