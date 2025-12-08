#include <iostream>
#include <string>
#include<sstream>

using namespace std;
/*
string ID = [11-22,95-115,998-1012,1188511880-1188511890,222220-222224,
1698522-1698528,446443-446449,38593856-38593862,565653-565659,
824824821-824824827,2121212118-2121212124].find(',');
*/
bool Invalido(long long n){
    string ID = to_string(n);
    if(ID.size()%2 != 0){ //los impares están bien, por lo tanto solo hay q comprobar los pares
        return false;
    }
    int mid = ID.size() / 2;
    return ID.substr(0, mid) == ID.substr(mid);  
}


int main(){
    string ID;
    getline(cin, ID);
    stringstream ss(ID);
    string rango;
    long long suma = 0;

    while(getline(ss, rango, ',')){ //separa por comas
        size_t guion = rango.find('-');
        long long inicio = stoll(rango.substr(0, guion));
        long long fin = stoll(rango.substr(guion + 1));
        for (long long i = inicio; i <= fin; i++){
            if (Invalido(i)){
                suma += i;
            }
        }

    }
    cout << "Valores inválidos: " << suma << endl;

return 0;

}


