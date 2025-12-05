#include<bits/stdc++.h>
using namespace std;


int main(){
    //Obtener datos del archivo
    ifstream input("input.txt");
    if(!input.is_open()){ 
        cerr << "Error, el archivo no se puede abrir" << endl;
        return 1;
    }


    string linea;
    vector<pair<long long, long long>> rango;
    bool cambiarDato = false;
    int solucion = 0;

    while(getline(input, linea)){
        if(linea.empty()){
            cambiarDato = true;
            continue;
        }

        if(!cambiarDato){
            int guion = linea.find('-');
            long long mini = stoll(linea.substr(0, guion));
            long long maxi = stoll(linea.substr(guion + 1));

            rango.push_back({mini, maxi});

        }else{
            long long valor = stoll(linea);

            for(int i = 0; i < rango.size(); i++ ){
                if(valor >= rango[i].first && valor <= rango[i].second){
                    solucion++;
                    break;
                }
            }

        }
    }


    input.close();
    cout << solucion << endl;

    return 0;
}