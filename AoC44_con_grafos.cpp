#include <bits/stdc++.h>
using namespace std;

struct nodo {
    int id;
    int j, i;
    int grado;
};

struct grafo {
    vector<nodo> nodos;
    vector<vector<int>> adyacencias; //una lista de otra lista, en la primera esta el id del nodo y el la segundo el id de los nodos adyacentes
};

void rejilla_completa(ifstream &archivo, grafo &g, vector<string> &rejilla){
    string linea;
    int F = 0; // fila
    int ids = 0;
    while(getline(archivo, linea)){
        for(int i = 0; i < linea.size(); i++){
            if(linea[i] == '@'){
                nodo nuevo;
                nuevo.id = ids;
                nuevo.j = i; //columnas
                nuevo.i = F; //filas
                nuevo.grado = 0;
                g.nodos.push_back(nuevo); //mete el nodo en la lista de nodos para el grafo
                ids++;
            }
        }
        F++;
        rejilla.push_back(linea);
    }
}

bool comprobar(int i, int j, int di, int dj, const vector<string> &rejilla){
    int ni = i + di;
    int nj = j + dj;
    return ni >= 0 && ni < rejilla.size() && nj >= 0 && nj < rejilla[ni].size();
}


void lista_adyacencias(grafo &g, vector<string> &rejilla){
    g.adyacencias.resize(g.nodos.size());
    for (int x = 0; x < g.nodos.size(); x++){
        g.nodos[x].grado = 0;
        g.adyacencias[x].clear();
    }
    for(int x = 0; x < g.nodos.size(); x++){
        int i = g.nodos[x].i;
        int j = g.nodos[x].j;
        //(-1,+1)
        if(comprobar(i,j, -1, +1, rejilla)){
            if(rejilla[i - 1][j + 1] == '@'){
                for(int y = 0; y < g.nodos.size(); y++){
                if(g.nodos[y].i == i-1 && g.nodos[y].j == j+1){
                    g.adyacencias[x].push_back(g.nodos[y].id);
                    g.nodos[x].grado++;
                    break;
                }
                }
            }
        }
        //(-1,j)
        if(comprobar(i,j,-1, 0, rejilla)){
            if(rejilla[i - 1][j] == '@'){
                for(int y = 0; y < g.nodos.size(); y++){
                if(g.nodos[y].i == i-1 && g.nodos[y].j == j){
                    g.adyacencias[x].push_back(g.nodos[y].id);
                    g.nodos[x].grado++;
                    break;
                }
                }
            }
        }
        //(-1,-1)
        if(comprobar(i,j, -1, -1, rejilla)){
            if(rejilla[i - 1][j - 1] == '@'){
                for(int y = 0; y < g.nodos.size(); y++){
                    if(g.nodos[y].i == i-1 && g.nodos[y].j == j-1){
                        g.adyacencias[x].push_back(g.nodos[y].id);
                        g.nodos[x].grado++;
                        break;
                    }
                }
            }
        }
        //(i,+1)
        if(comprobar(i,j, 0, +1, rejilla)){
            if(rejilla[i][j + 1] == '@'){
                for(int y = 0; y < g.nodos.size(); y++){
                    if(g.nodos[y].i == i && g.nodos[y].j == j+1){
                        g.adyacencias[x].push_back(g.nodos[y].id);
                        g.nodos[x].grado++;
                        break;
                    }
                }
            }
        }
        //(i,-1)
        if(comprobar(i,j, 0, -1, rejilla)){
            if(rejilla[i][j - 1] == '@'){
                for(int y = 0; y < g.nodos.size(); y++){
                    if(g.nodos[y].i == i && g.nodos[y].j == j-1){
                        g.adyacencias[x].push_back(g.nodos[y].id);
                        g.nodos[x].grado++;
                        break;
                    }
                }
            }
        }
        //(+1,+1)
        if(comprobar(i,j, +1, +1, rejilla)){
            if(rejilla[i + 1][j + 1] == '@'){
                for(int y = 0; y < g.nodos.size(); y++){
                    if(g.nodos[y].i == i+1 && g.nodos[y].j == j+1){
                        g.adyacencias[x].push_back(g.nodos[y].id);
                        g.nodos[x].grado++;
                        break;
                    }
                }
            }
        }
        //(+1,j)
        if(comprobar(i,j, +1, 0, rejilla)){
            if(rejilla[i + 1][j] == '@'){
                for(int y = 0; y < g.nodos.size(); y++){
                    if(g.nodos[y].i == i+1 && g.nodos[y].j == j){
                        g.adyacencias[x].push_back(g.nodos[y].id);
                        g.nodos[x].grado++;
                        break;
                    }
                }
            }
        }
        //(+1,-1)
        if(comprobar(i,j, +1, -1, rejilla)){
            if(rejilla[i + 1][j - 1] == '@'){
                for(int y = 0; y < g.nodos.size(); y++){
                    if(g.nodos[y].i == i+1 && g.nodos[y].j == j-1){
                        g.adyacencias[x].push_back(g.nodos[y].id);
                        g.nodos[x].grado++;
                        break;
                    }
                }
            }
        }

    }
}

int contador_acesibles(grafo &g, int contador, int comparar, vector<string> &rejilla){ // la paso por referencia para que no haga un copia de todo el grafo y la pongo como constante para estar segura de que nada me modifique el grafo
    lista_adyacencias(g, rejilla);
    for(int x = 0; x<g.nodos.size(); x++){
        if(g.nodos[x].grado < 4){
            contador++;
            g.nodos.erase(g.nodos.begin() + x);
            x--;
        }
    }
    if(contador == comparar){
        return contador;
    }else{
        comparar = contador;
        return contador_acesibles(g, contador, comparar, rejilla);
    }
}

int main(){
    ifstream archivo("imprenta.txt");
    if(!archivo.is_open()){
        cout << "Archivo no encontrado" << endl;
        return 0;
    }
    
    grafo AoC;
    vector<string> rejilla;
    int definitivo;
    int count = 0;
    int compara = 1;

    rejilla_completa(archivo, AoC, rejilla);
    lista_adyacencias(AoC, rejilla);
    definitivo = contador_acesibles(AoC, count, compara, rejilla);
    cout << definitivo << endl;

    return 0;
}