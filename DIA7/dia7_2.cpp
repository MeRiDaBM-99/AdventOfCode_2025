#include<bits/stdc++.h>
using namespace std;


long long caminos(int new_i, int new_j, const vector<string> &mapa, vector<vector<long long>> &M){
    int tam_mapa = mapa.size();  
    int tam_v = mapa[0].size(); 

    if(new_j < 0 || new_j >= tam_v){    //Lo tomamos como que no ha terminado el recorrido
        return 0;                       //si se pasa de las paredes laterales
    }

    //Si llega al final -> ha completado el recorrido :D
    if(new_i >= tam_mapa){
        return 1;
    }

    //Mirar si ya se ha almacenado en memoria dicho camino
    if(M[new_i][new_j] != -1){
        return M[new_i][new_j];
    }

    //Si no cumple lo anterior...
    else{
        //Si nos enconramos con un divisor (^)
        if(mapa[new_i][new_j] == '^'){
            //Definimos sus lados (el rayo de parte en dos)
            int li = new_j - 1;
            int ld = new_j + 1;

            M[new_i][new_j] = caminos(new_i + 1, li, mapa, M) + caminos(new_i + 1, ld, mapa, M);

        
        }else{
            //Si no hay divisor seguimos avanzando
            M[new_i][new_j] = caminos(new_i + 1, new_j, mapa, M);
        }
    }
    return M[new_i][new_j];
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
    int cont = 0;
    pair<int ,int> start;
    vector<string> mapa;

    //Crear el mapa input y localizar 'S'
    while(getline(input, linea)){
        mapa.push_back(linea);
        for(int j = 0; j < linea.size(); j++){
            if(linea[j] == 'S'){
                start = {cont, j};
            }
        }
        cont++;
    }

    int tam_mapa = mapa.size();     //Nº filas
    int tam_v = mapa[0].size();     //Nº columnas

    vector<vector<long long>> M(tam_mapa, vector<long long>(tam_v, -1));

    //Guarmos las posiciones anteriores para avanzar
    int i = start.first;
    int j = start.second;

    //Definimos las siguientes posiciones
    int new_i = i + 1;
    int new_j = j;

    solucion = caminos(new_i, new_j, mapa, M);


    input.close();
    cout << solucion << endl;

    return 0;
}
