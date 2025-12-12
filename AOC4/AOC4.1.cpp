#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
//#include <bits/stdc++.h> -> libreria universal
using namespace std;

struct Key {
    int x, y;
    bool operator==(Key const& o) const {
        return x == o.x && y == o.y;
    }
};

struct Hasher {
    size_t operator()(Key const& k) const {
        return ((long long)k.x << 32) ^ (long long)k.y;
    }
};

int main() {
    //ios::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_set<Key, Hasher> rolls;

    string line;
    int y = 0;
    while (getline(cin, line)) {
        for (int x = 0; x < (int)line.size(); x++) {
            if (line[x] == '@') {
                rolls.insert({x,y});
            }
        }
        y++;
    }

    const int dx[8] = {-1,-1,-1, 0,0, 1,1,1};
    const int dy[8] = {-1, 0, 1,-1,1,-1,0,1};

    int accessible = 0;

    for (auto const& k : rolls) { // : -> sirve para recorrer todas las k dentro de rolls 
        int cont = 0;
        for (int d = 0; d < 8; d++) {
            Key clave = {k.x + dx[d], k.y + dy[d]};
            if (rolls.count(clave)){
                cont++;
            }
        }
        if (cont < 4){
            accessible++;
        } 
    }

    cout << accessible << "\n";
}