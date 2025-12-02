#include<bits/stdc++.h>
using namespace std;

//Funcion que mira entre el rango 'inicio' y 'fin' los posibles invalidos
long long invalidos(long long inicio, long long fin) {
    if (inicio > fin) 
        return 0;

    if (inicio == fin) {
        string s = to_string(inicio);

        if (s.size() % 2 != 0) {  
            return 0; 
        }

        //Comprobar si en ambas mitades se repite un patron
        int mid = s.size() / 2;
        string p1 = s.substr(0, mid);
        string p2 = s.substr(mid);

        if (p1 == p2) {
            //Invalido
            return inicio; 
        } else {
            //Valido
            return 0;     
        } 
    }

    long long mid = (inicio + fin) / 2;
    long long izquierda = invalidos(inicio, mid);
    long long derecha   = invalidos(mid + 1, fin);
    return izquierda + derecha;
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
            invalidos_totales += invalidos(inicio, fin);
        }
        
    }
    cout << invalidos_totales << endl;
    return 0;
}