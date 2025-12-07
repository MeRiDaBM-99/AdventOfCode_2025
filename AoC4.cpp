#include <bits/stdc++.h>
using namespace std;

bool comprobar(int i, int j, int filas, int columnas) {
    return i >= 0 && i < filas && j >= 0 && j < columnas;
}

int main(){
    ifstream archivo("imprenta.txt");
    if(!archivo.is_open()){
        cout << "Archivo no encontrado" << endl;
        return 0;
    }

    //creo el arbol
    vector<string> cuadricula;
    string linea;

    while(getline(archivo, linea)){
        cuadricula.push_back(linea);
    }

    //hago la busqueda
    int filas = cuadricula.size();
    int columnas = cuadricula[0].size();

    int direcciones[8][2] = {
        {-1, -1}, {-1, 0}, {-1, 1},
        { 0, -1},          { 0, 1},
        { 1, -1}, { 1, 0}, { 1, 1}
    };
    
    //contador de rollos accesibles
    int accesibles = 0;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (cuadricula[i][j] == '@') {
                int vecinos_rollo = 0;
                for (int d = 0; d < 8; d++) {
                    int nueva_i = i + direcciones[d][0];
                    int nueva_j = j + direcciones[d][1];
                    if (comprobar(nueva_i, nueva_j, filas, columnas)) {
                        if (cuadricula[nueva_i][nueva_j] == '@') {
                            vecinos_rollo++;
                        }
                    }
                }
                if (vecinos_rollo < 4) {
                    accesibles++;
                }
            }
        }
    }
    cout << accesibles << endl;
    return 0;
}