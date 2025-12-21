#include<bits/stdc++.h>
using namespace std;

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

    //Inicializar todas las posiciones como no visitadas
    vector<vector<bool>> visitado(tam_mapa, vector<bool>(tam_v, false));
    visitado[start.first][start.second] = true;

    //Crear cola para ir moviendose y lo iniliamos con el inicio (S)
    queue<pair<int, int>> q;
    q.push(start);

    while(!q.empty()){
        //Guarmos las posiciones anteriores para avanzar
        int i = q.front().first;
        int j = q.front().second;

        //Avanza
        q.pop();

        //Definimos las siguientes posiciones
        int new_i = i + 1;
        int new_j = j;

        //Mirar que no se pase del mapa y que no esté ya visitado
        if(new_i >= 0 && new_i < tam_mapa && new_j >= 0 && new_j < tam_v && !visitado[new_i][new_j]){
            //Si nos enconramos con un divisor (^)
            if(mapa[new_i][new_j] == '^'){
                //Sumamos el resultado pedido -> OBJETIVO DEL EJERCICIO
                solucion++;
                //Definimos sus lados (el rayo de parte en dos)
                int li = new_j - 1;
                int ld = new_j + 1;

                //Miramos si estan dentro del límite y si no estan visitados para añadirlos
                if(li >= 0 && li < tam_v && !visitado[new_i][li]){
                    q.push({new_i, li});
                    visitado[new_i][li] = true;
                }

                if(ld >= 0 && ld < tam_v && !visitado[new_i][ld]){
                    q.push({new_i, ld});
                    visitado[new_i][ld] = true;
                }
            }else{
                //Si no hay divisor seguimos avanzando
                q.push({new_i, new_j});
                visitado[new_i][new_j] = true;
            }
        }
    }



    input.close();
    cout << solucion << endl;

    return 0;
}
