#pragma once

#include <string>
#include <unordered_map>
using namespace std;

class Puerto
{
private:
    int puerto; 
    int freq;
    unordered_map<string, int> usuarios; // usuario -> frecuencia

public:
    Puerto();
    Puerto(int p);

    int getPuerto() const;
    int getFreq() const;
    unordered_map<string, int>& getUsuarios();

    void setPuerto(int p);
    void setFreq(int f);

    void aumentarFreq();
    void agregarUsuario(const string& usuario);

    void mostrarInfo() const;
};
