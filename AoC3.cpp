#include<bits/stdc++.h>
using namespace std;


int main(){
    ifstream archivo("baterias.txt");
    if(!archivo.is_open()){
        cout << "Archivo no encontrado" << endl;
        return 0;
    }

    int derecha = -1;
    int pivote;
    int suma = 0;
    int definitivo = -1;
    string linea;
    while(getline(archivo, linea)){
        definitivo = -1;
        for(int i = 0; i< linea.size() - 1; i++){
            pivote = (linea[i]-'0')*10;
            derecha = -1;
            for(int j = i+1; j<linea.size();j++){
                if(derecha<(linea[j]-'0'))
                    derecha = (linea[j]-'0');
            }
            if(definitivo<(pivote + derecha))
                definitivo = pivote + derecha;
        }
        suma+=definitivo;
    }
    cout<< suma << endl;
    return 0;
}