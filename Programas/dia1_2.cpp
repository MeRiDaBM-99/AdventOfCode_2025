#include<bits/stdc++.h>
using namespace std;

//Funcion para obtener 'R' o 'L'
char getDir(string texto) {
    return texto[0]; 
}

//Funcion para sacar el valor
int getNum(string texto) {
    return stoi(texto.substr(1)); 
}


int main(){
    //Obtener datos del archivo
    ifstream input("input.txt");
    if(!input.is_open()){ 
        cerr << "Error, el archivo no se puede abrir" << endl;
        return 1;
    }

    int posicion = 50;
    int cont_ceros = 0;
    string instruccion;

    while(getline(input,instruccion)){
        char dir = getDir(instruccion);
        int num = getNum(instruccion);
        
        //Cambios dia1_2 (movemos de 1 en 1)
        for(int i = 0 ; i < num ; i++ ){
            if(dir == 'R'){
                posicion++;
                if(posicion == 100){
                    posicion = 0;
                }
            }else{
                posicion--;
                if(posicion < 0){
                    posicion = posicion + 100;
                } 
            }
            if(posicion == 0){
                cont_ceros++;
            }
        }

        
    }
    input.close();
    cout << "La contrasenya es: " << cont_ceros << endl;

    return 0;
    
}