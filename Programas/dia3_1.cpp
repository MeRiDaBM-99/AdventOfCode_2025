#include<bits/stdc++.h>
using namespace std;

int voltaje(string linea, int ini, int fin){
    if(ini > fin){return -1;}

    if(ini == fin){return ini;}

    if(fin == ini + 1){
        if(linea[ini] > linea[fin]){return ini;}
        else if(linea[fin] >= linea[ini]){return fin;}
    }

    int med = (ini + fin)/2;
    int izq = voltaje(linea, ini, med);
    int der = voltaje(linea, med + 1, fin);


    if(linea[izq] > linea[der]){return izq;}
    else{return der;}
}

int main(){
    //Obtener datos del archivo
    ifstream input("input.txt");
    if(!input.is_open()){ 
        cerr << "Error, el archivo no se puede abrir" << endl;
        return 1;
    }


    string linea;
    long long solucion = 0;

    while(getline(input, linea)){
        long long maxVal = 0;

        for(int first = 0; first < linea.size() - 1; first++){
            int second = voltaje(linea, first + 1, linea.size()-1);
            if (second == -1) continue;

            char first_n = linea[first];
            char second_n = linea[second];

            string s;
            s.push_back(first_n);
            s.push_back(second_n);

            long long v = stoi(s);

            if(v > maxVal){
                maxVal = v;
            }

        }

        solucion += maxVal;
        
    }


    input.close();
    cout << solucion << endl;

    return 0;
}