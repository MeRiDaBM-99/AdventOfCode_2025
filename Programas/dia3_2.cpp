#include<bits/stdc++.h>
using namespace std;

long long voltaje(string linea, int ini, int fin, vector<vector<long long>> &M, int cant){
    if (M[ini][cant] != -1){return M[ini][cant];}

    if(cant == 0){M[ini][cant] = 0;}

    else if (fin - ini + 1 >= cant){
        M[ini][cant] = max(voltaje(linea, ini + 1, fin, M, cant), (linea[ini] - '0') + voltaje(linea, ini + 1, fin, M, cant - 1));

        
    }return M[ini][cant];
    
}

int main(){
    //Obtener datos del archivo
    ifstream input("input.txt");
    if(!input.is_open()){ 
        cerr << "Error, el archivo no se puede abrir" << endl;
        return 1;
    }


    string linea;
    long long solucion = 0;

    while(getline(input, linea)){
        long long maxVal = 0;
        vector<vector<long long>> M(linea.size() + 1, vector<long long>(12 + 1, -1));


        for(int first = 0; first < linea.size() - 12; first++){
            

            /*int second = voltaje(linea, first + 1, linea.size()-1, M, 12);
            if (second == -1) continue;

            char first_n = linea[first];
            char second_n = linea[second];

            string s;
            s.push_back(first_n);
            s.push_back(second_n);

            long long v = stoi(s);

            if(v > maxVal){
                maxVal = v;
            }
            */

        }   
        
        cout << voltaje(linea, 0, linea.size() - 1, M, 12) << "\n"; // salto de línea por fila
    
    }



    //cout << solucion << endl;

    return 0;
}