#include<bits/stdc++.h>
using namespace std;

bool invalido(long long n) {
    string s = to_string(n);
    int len = s.size();

    // Probar todos los posibles tamaños de bloque que dividan la longitud
    for (int k = 1; k <= len / 2; k++) {
        if (len % k != 0) continue; // solo bloques que encajan exactos

        string bloque = s.substr(0, k);
        bool repetido = true;

        // Comprobar que todos los bloques son iguales
        for (int i = k; i < len; i += k) {
            if (s.substr(i, k) != bloque) {
                repetido = false;
                break;
            }
        }

        if (repetido) return true; // inválido
    }
    return false; // válido
}

// Suma todos los inválidos en un rango [inicio, fin]
long long sumaInvalidos(long long inicio, long long fin) {
    long long total = 0;
    for (long long n = inicio; n <= fin; n++) {
        if (invalido(n)) {
            total += n;
        }
    }
    return total;
}

int main(){
    ifstream input("puzzle.txt");
    if(!input.is_open()){ 
        cerr << "Error, el archivo no se puede abrir" << endl;
        return 1;
    }

    long long invalidos_totales = 0;
    string linea;
    while (getline(input, linea)){
        stringstream ss(linea);
        string segmento;
        while (getline(ss, segmento, ',')) {
            int guion = segmento.find("-");

            long long inicio = stoll(segmento.substr(0, guion));
            long long fin = stoll(segmento.substr(guion + 1));
            invalidos_totales += sumaInvalidos(inicio, fin);
        }
        
    }
    cout << invalidos_totales << endl;
    return 0;
}