#include<bits/stdc++.h>

using namespace std;

bool comprobar (const vector<string> &matriz, int i, int j){
    
    int df[8] = {-1,-1,-1, 0, 0, 1, 1, 1};
    int dc[8] = {-1, 0, 1,-1, 1,-1, 0, 1};
    
    int F = (int)matriz.size();     //TNº filas
    int C = (int)matriz[0].size();  //nº columnas 

    int cont = 0;
    for (int k = 0; k < 8; k++) {
        int nf = i + df[k];
        int nc = j + dc[k];

        // Comprobar limites
        if (nf >= 0 && nf < F && nc >= 0 && nc < C) {
            if (matriz[nf][nc] == '@') {cont++;}
        }
    }
    // comprobar que es menor a 4
    return cont < 4;

}


int main(){
    //Obtener datos del archivo
    ifstream input("input.txt");
    if(!input.is_open()){ 
        cerr << "Error, el archivo no se puede abrir" << endl;
        return 1;
    }


    string linea;
    vector<string> matriz;
    int solucion = 0;

    //Definir la matriz con los valores del archivo
    while(getline(input, linea)){
        matriz.push_back(linea);
    }

    
    for(int i = 0; i < matriz.size(); i++){
        for(int j = 0; j < matriz[i].size(); j++){
            if(matriz[i][j] == '@'){
                if(comprobar(matriz, i, j)){solucion++;}
            }
        }
    }


    input.close();
    cout << solucion << endl;

    return 0;
}