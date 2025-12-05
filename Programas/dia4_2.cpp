#include<bits/stdc++.h>

using namespace std;

void eliminar(vector<string> &matriz, const vector<int> &fil, const vector<int> &col){
    for(int i = 0; i < fil.size(); i++){
        matriz[fil[i]][col[i]] = '.';
    }
}


bool comprobar (const vector<string> &matriz, int i, int j){
    
    int df[8] = {-1,-1,-1, 0, 0, 1, 1, 1};
    int dc[8] = {-1, 0, 1,-1, 1,-1, 0, 1};
    
    int F = matriz.size();     //Nº filas
    int C = matriz[0].size();  //Nº columnas 

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
    vector<int> fil, col;
    int total = 0;

    //Definir la matriz con los valores del archivo
    while(getline(input, linea)){
        matriz.push_back(linea);
    }

    for(int i = 0; i < matriz.size(); i++){
        for(int j = 0; j < matriz[i].size(); j++){
            if(matriz[i][j] == '@'){
                if(comprobar(matriz, i, j)){
                    total++;
                    fil.push_back(i);
                    col.push_back(j);
                }
            }
        }
    }

    solucion += total;

    while(total != 0){
        eliminar(matriz, fil, col);
        fil.clear();
        col.clear();
        total = 0;

        for(int i = 0; i < matriz.size(); i++){
            for(int j = 0; j < matriz[i].size(); j++){
                if(matriz[i][j] == '@'){
                    if(comprobar(matriz, i, j)){
                        total++;
                        fil.push_back(i);
                        col.push_back(j);
                    }
                }
            }
        }

        solucion += total;
    }


    input.close();
    cout << solucion << endl;

    return 0;
}