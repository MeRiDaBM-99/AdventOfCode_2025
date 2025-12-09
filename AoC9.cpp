#include<bits/stdc++.h>
using namespace std;

struct Puntos{
    long long i, j;
};

int main(){
    ifstream archivo("baldosas.txt");
    if(!archivo.is_open()){ 
        cerr << "Error, el archivo no se puede abrir" << endl;
        return 1;
    }

    vector<Puntos> baldosas;
    string linea;
    while(getline(archivo, linea)){
        vector<long long> coord;
        stringstream ss(linea);
        string partes;
        while(getline(ss, partes, ',')){
            coord.push_back(stoi(partes));
        }
        if(coord.size() == 2) {
            int x = coord[0];
            int y = coord[1];
            //cout << "x, y: " << x << "," << y << endl;
            baldosas.push_back({x,y});
        }
    }

    long long definitivo = 0;
    for(int a = 0; a<baldosas.size(); a++){
        for(int b = a+1; b<baldosas.size();b++){
            long long x1 = baldosas[a].i, y1 = baldosas[a].j;
            long long x2 = baldosas[b].i, y2 = baldosas[b].j;
            long long area = ((abs(x2 - x1))+1)*((abs(y2-y1))+1);
            if(area > definitivo)
                definitivo = area;
        }
    }

    cout << definitivo << endl;
    return 0;
}
