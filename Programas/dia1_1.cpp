#include<bits/stdc++.h>

using namespace std;

char getDir(string texto) {
    return texto[0]; 
}
int getNum(string texto) {
    return stoi(texto.substr(1)); 
}
int main(){
    ifstream input("input.txt");
    if(!input.is_open()){ 
        cerr << "Error, el archivo no se puede abrir" << endl;
        return 1;
    }
    int posicion= 50;
    int cont_ceros=0;
    string instruccion;

    while(getline(input,instruccion)){
        char dir=getDir(instruccion);
        int num=getNum(instruccion);
        if(dir=='R'){
            posicion=(posicion+num)%100;
        }else{
            posicion=(posicion-num)%100;
            if(posicion<0){
                posicion =posicion+100;
            }
        }

        if(posicion==0){
            cont_ceros++;
        }
    }
    input.close();
    cout << "La contrasenya es: " << cont_ceros << endl;

    return 0;
    
}