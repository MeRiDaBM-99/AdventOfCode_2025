#include <bits/stdc++.h>
using namespace std;
//leo mi entrada como una lista de strings
// cada linea representa un banco de baterias

/*bucle por cada linea
otro bucle para recorrer la linea en pares consecutivos
comparo y calculo es maximo par y lo guardo
sumo todos los maximos*/

int main(){
    long long total_voltaje = 0; 
    string line;

    while(getline(cin, line)){
        //leer la entrada completa linea a linea
        
        int max_voltaje = -1;

        /*convertir caracteres a enteros 
        int ad = a - '0'
        int bd = b - '0'*/
        
        for (int i = 0; i+1 < line.size(); i++){
            char a = line[i];
            char b = line[i+1];

            int ad = a - '0';
            int bd = b - '0';
            int value = ad * 10 + bd;

            if(value > max_voltaje){
                max_voltaje = value;
            }
        }

        //si la linea tiene al menos un par valido, sumar al total
        if(max_voltaje >= 0){
            total_voltaje += max_voltaje;
        }  
    }

    cout << total_voltaje << "\n" << endl;
    return 0;
}
