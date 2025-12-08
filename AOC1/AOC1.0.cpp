#include <iostream>
#include <string>

using namespace std;

int main(){
    int pasos;
    int pos = 50;
    string instrucciones;
    int contador = 0;
    
    while (cin >> instrucciones){
        char direccion = instrucciones[0]; //Coje la letra
        pasos = stoi(instrucciones.substr(1)); //Coje los numeros

        pasos %= 100; //No puede llegar a 100

        if (direccion == 'L' || direccion == 'l'){
            pos = (pos - pasos + 100) % 100;
        }
        else{
            pos =(pos + pasos) % 100;
        }
        if(pos == 0){
            contador ++;
        }
    }
    cout << "contador: " << contador << endl;
    return 0;
}