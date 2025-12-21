#include<bits/stdc++.h>
using namespace std;

#include "BSNode.h"
#include "BSTree.h"


int main(){
    ifstream archivo("ingredientes.txt");
    if(!archivo.is_open()){ 
        cerr << "Error, el archivo no se puede abrir" << endl;
        return 1;
    }

    bool rangos = true;
    string linea;
    BSTree<long long> tree;
    long long definitivos = 0;
    while(getline(archivo, linea)){
        if(linea.empty()){
            rangos = false;
            continue;
        }
        if(rangos){
            stringstream ss(linea);
            long long inicio, fin;
            char guion;
            ss >> inicio >> guion >> fin;
            tree.insert(inicio, fin);
        }else{
            long long id = stoll(linea);
            if(tree.search(id)){
                definitivos++;
            }
        }
    }
    cout << definitivos << endl;
    return 0;
}