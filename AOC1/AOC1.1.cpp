#include <iostream>
#include <string>
using namespace std;

int main(){
    int pasos;
    int pos = 50;
    string instrucciones;
    int contador = 0;
    int PasarPorCero = 0;
    int t0;
    
    while (cin >> instrucciones){
        char direccion = instrucciones[0]; //Coje la letra
        pasos = stoi(instrucciones.substr(1)); //Coje los numeros


        t0 = (direccion == 'R' || direccion == 'r') ? (100 - pos) % 100 : pos % 100;
        if(t0 == 0){
            t0 = 100;
        }
        if(pasos >= t0){
            PasarPorCero += 1 + (pasos - t0) / 100;
        }

        int k = pasos % 100;
        
        if (direccion == 'L' || direccion == 'l'){
            pos = (pos - k + 100) % 100;
        }else{
            pos = (pos + k) % 100;
        }

        if(pos == 0){
            contador++;
        }
        
    }
    cout << "password: " << PasarPorCero  << endl;
    return 0;
}






/*
int main() {
    int pos = 50;                 // posición inicial
    int terminaEnCero = 0;  // veces que termina en 0
    int pasaPorCero = 0;    // veces que pasa por 0 en total
    string instr;

    while (cin >> instr) {
        char dir = instr[0];
        int pasos = stoll(instr.substr(1));

        // Calcular cuántas veces pasa por 0 en esta rotación

        int t0 = (dir == 'R' || dir == 'r') ? (100 - pos) % 100 : pos % 100;
        if (t0 == 0){
            t0 = 100;
        } 
        if (pasos >= t0){
            pasaPorCero += 1 + (pasos - t0) / 100;
        }

        // Actualizar posición final (solo mod 100)
        int k = pasos % 100;
        if (dir == 'L' || dir == 'l'){
            pos = (pos - k + 100) % 100;
        }else{
            pos = (pos + k) % 100;
        }

        if (pos == 0){
            terminaEnCero++;
        }
    }

    cout << " " << pasaPorCero << "\n";
    return 0;
}
*/