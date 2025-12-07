#include <bits/stdc++.h>
using namespace std;

int main(){
    ifstream archivo("math.txt");
    if(!archivo.is_open()){
        cerr << "Error al abrir el archivo" << endl;
        return 1;
    }
    vector<vector<int>> numeros;  
    vector<char> signo;            
    string linea;
    while(getline(archivo, linea)){
        stringstream ss(linea);
        string cosa;
        vector<int> fila;          
        while(getline(ss, cosa, ' ')){ 
            if(cosa.empty()) continue;  

            if(cosa == "+" || cosa == "*"){
                signo.push_back(cosa[0]);
            } else {
                int num = stoi(cosa);
                fila.push_back(num);
            }
        }
        if(!fila.empty()){
            numeros.push_back(fila);     
        }
    }

    long long definitivo = 0;
    int filas = numeros.size();
    int columnas = signo.size();
    for(int i = 0; i < columnas; i++){
        char op = signo[i];             
        long long resultado;
        if(op == '+') 
            resultado = 0;
        else 
            resultado = 1;
        for(int j = 0; j < filas; j++){
            int valor = numeros[j][i];
            if(op == '+') 
                resultado += valor;
            else 
                resultado *= valor;
        }
        definitivo += resultado;
    }

    cout << definitivo << endl;
    return 0;
}
