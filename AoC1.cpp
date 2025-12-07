//Ejercicio 1 AoC
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main(){
    ifstream archivo("ordenes.txt");
    string linea;
    int inicio = 50;
    int contra = 0;

    if(!archivo.is_open()){
        cout << "Archivo no encontrado" << endl;
        return 0;
    }

    while(getline(archivo, linea)){
        if(linea.empty()) continue;
        char d = linea[0];
        int n = stoi(linea.substr(1));
        if (d == 'L') {
            inicio = (inicio - n) % 100;
            if (inicio < 0) 
                inicio += 100;   
            if (inicio == 0) 
                contra++;       
        } else if (d == 'R') {
            inicio = (inicio + n) % 100;
            if (inicio < 0) 
                inicio += 100;
            if (inicio == 0) 
                contra++;
        }
    }
    cout << contra << endl;
    return 0;
}
