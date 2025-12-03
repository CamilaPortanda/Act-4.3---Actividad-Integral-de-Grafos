#include "puerto.hpp"
#include <iostream>

Puerto::Puerto()
{
    puerto = 0;
    freq = 0;
}

Puerto::Puerto(int p)
{
    puerto = p;
    freq = 1;
}

int Puerto::getPuerto() const { return puerto; }
int Puerto::getFreq() const { return freq; }
unordered_map<string, int>& Puerto::getUsuarios() { return usuarios; }

void Puerto::setPuerto(int p) { puerto = p; }
void Puerto::setFreq(int f) { freq = f; }

void Puerto::aumentarFreq()
{
    freq++;
}

void Puerto::agregarUsuario(const string& usuario)
{
    usuarios[usuario]++; //añadimos lo de usuario.
}

void Puerto::mostrarInfo() const
{
    cout << "Puerto: " << puerto << endl;
    cout << "Frecuencia total: " << freq << endl;
    cout << "Usuarios ilegales:" << endl;

    for (const auto& par : usuarios) {
        cout << "   " << par.first << "-->" << par.second << " veces" << endl;
    }
}
