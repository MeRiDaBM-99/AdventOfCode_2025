#include<bits/stdc++.h>
using namespace std;

//Funcion que comprueba que sean valores invalidos
bool invalido(long long n) {
    string s = to_string(n);
    int tam = s.size();
    
    //Probar posibles tamaños del patron (deberán de ser particiones pares)
    for (int k = 1; k <= tam / 2; k++) {

        if (tam % k != 0) continue; // solo bloques que encajan exactos
        string bloque = s.substr(0, k);
        bool repetido = true;
        
        // Comprobar que todos los bloques son iguales
        for (int i = k; i < tam; i += k) {
            if (s.substr(i, k) != bloque) {
                repetido = false;
                break;
            }
        }

        //invalido
        if (repetido) return true;
    }

    //valido
    return false;
}

//Funcion que suma todos los inválidos entre 'inicio' y 'fin'
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
    //Obtener datos del archivo
    ifstream input("input.txt");
    if(!input.is_open()){ 
        cerr << "Error, el archivo no se puede abrir" << endl;
        return 1;
    }

    long long invalidos_totales = 0;
    string linea;

    while (getline(input, linea)){
        stringstream ss(linea);
        string segmento;

        //Leer hasta la coma
        while (getline(ss, segmento, ',')) {
            //Sacar la posicion del guion
            int guion = segmento.find("-");

            //Separamos los valores limitados por el guion
            long long inicio = stoll(segmento.substr(0, guion));
            long long fin = stoll(segmento.substr(guion + 1));
            
            //Suma de los valores invalidos
            invalidos_totales += sumaInvalidos(inicio, fin);
        }
        
    }
    cout << invalidos_totales << endl;
    return 0;
}