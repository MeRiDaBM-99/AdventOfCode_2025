#include<bits/stdc++.h>
using namespace std;

long long invalidos(long long inicio, long long fin) {
    if (inicio > fin) 
        return 0;

    if (inicio == fin) {
        string s = to_string(inicio);
        if (s.size() % 2 != 0) {  
            return 0; 
        }
        int mid = s.size() / 2;
        string p1 = s.substr(0, mid);
        string p2 = s.substr(mid);
        if (p1 == p2) {
            return inicio;
        } else {
            return 0;    
        } 
    }

    long long mid = (inicio + fin) / 2;
    long long izquierda = invalidos(inicio, mid);
    long long derecha   = invalidos(mid + 1, fin);
    return izquierda + derecha;
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
            invalidos_totales += invalidos(inicio, fin);
        }
        
    }
    cout << invalidos_totales << endl;
    return 0;
}

