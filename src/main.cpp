#include "puerto.hpp"
#include <iostream>
#include <fstream>

vector<Puerto> readFile(const string& filename) {
    ifstream file(filename);
    vector<Puerto> listaPuertos;

    if (!file.is_open()) {
        cout << "No se pudo abrir archivo";
        return listaPuertos;
    }

    string line;
    while (getline(file, line)) {

        // Buscar ":" que marca el puerto
        size_t posDosPuntos = line.rfind(":");
        if (posDosPuntos == string::npos) continue;

        // El puerto termina en un espacio después de ":"
        size_t posEspacio = line.find(" ", posDosPuntos);
        if (posEspacio == string::npos) continue;

        // Extraer puerto
        string strPuerto = line.substr(posDosPuntos + 1, posEspacio - posDosPuntos - 1);
        int puerto = stoi(strPuerto);

        // Extraer usuario ilegal (última palabra de la línea)
        size_t posUltimoEspacio = line.rfind(" ");
        if (posUltimoEspacio == string::npos) continue;

        string usuario = line.substr(posUltimoEspacio + 1);

        bool found = false;

        // Buscar si el puerto ya existe
        for (int i = 0; i < listaPuertos.size(); i++) {
            if (listaPuertos[i].getPuerto() == puerto) {
                listaPuertos[i].agregarUsuario(usuario);
                listaPuertos[i].aumentarFreq();
                found = true;
                break;
            }
        }

        // Si no existe, se crea uno nuevo
        if (!found) {
            Puerto nuevoPuerto(puerto);
            nuevoPuerto.agregarUsuario(usuario);
            listaPuertos.push_back(nuevoPuerto);
        }
    }

    file.close();
    return listaPuertos;
}


int main()
{
    vector<Puerto> puertos = readFile("bitacora.txt");

    for (int i = 0; i < puertos.size(); i++) {
        puertos[i].mostrarInfo();
        cout << "---------------------------\n";
    }

    return 0;
}
