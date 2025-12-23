#include<bits/stdc++.h>
using namespace std;

#include "BSNode.h"
#include "BSTree.h"


int main(){
    // Abrimos el archivo
    ifstream archivo("ingredientes.txt");
    // Si hay algun error lanzamos un mensaje de error y terminamos.
    if(!archivo.is_open()){                                 
        cerr << "Error, el archivo no se puede abrir" << endl;
        return 1;
    }

    bool rangos = true;                        // Variable que indica cuando se estan leyendo rangos y cuando identificadores.
    string linea;
    BSTree<long long> tree;                    // Creamos el arbol.
    long long definitivos = 0;                 // Variable que lleva la cuenta de ingredientes frescos.
    // Leemos el archivo linea a linena
    while(getline(archivo, linea)){
        // Si la linea esta en blanco la pasamos y actualizamos rangos a false (empiezan los ids).
        if(linea.empty()){
            rangos = false;
            continue;
        }
        // Si se esta leyendo rangos.
        if(rangos){
            stringstream ss(linea);
            long long inicio, fin;
            char guion;
            ss >> inicio >> guion >> fin;      // Dividimos la linea en inicio - fin.
            tree.insert(inicio, fin);          // Insertamos un nodo con el rango de la linea leida.
        // Si se esta leyendo ids. 
        }else{
            long long id = stoll(linea);       // Convertimos la linea en una variable de tipo long long.
            if(tree.search(id)){               // Buscamos el id
                definitivos++;                 // Si existe actualizamos definifitos, incrementando su valor 1.
            }
        }                                      // Si no existe leemos la siguiente linea y repetimos el proceso.
    }
    cout << definitivos << endl;               // Imprimimos el resultado por pantalla.
    return 0;
}

