
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// Un ID es inválido si está formado por repetir un bloque al menos 2 veces
bool Invalido(long long n) {
    string s = to_string(n);
    int L = s.size();
    if (L < 2) return false; // no puede ser repetido si tiene 1 dígito

    // Probar todas las longitudes de bloque posibles
    for (int len = 1; len <= L / 2; ++len) {
        if (L % len != 0) continue; // debe dividir exactamente
        string bloque = s.substr(0, len);
        string repetido;
        for (int i = 0; i < L / len; ++i) repetido += bloque;
        if (repetido == s){
            return true;
        }
    }
    return false;
}

int main() {
    string entrada;
    getline(cin, entrada); // lee toda la línea con rangos
    stringstream ss(entrada);
    string rango;
    unsigned long long suma = 0;

    while (getline(ss, rango, ',')) {
        size_t guion = rango.find('-');
        long long inicio = stoll(rango.substr(0, guion));
        long long fin = stoll(rango.substr(guion + 1));
        if (inicio > fin) swap(inicio, fin);

        for (long long i = inicio; i <= fin; ++i) {
            if (Invalido(i)) suma += i;
        }
    }

    cout << suma << "\n";
    return 0;
}
