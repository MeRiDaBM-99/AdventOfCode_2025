#include<bits/stdc++.h>
using namespace std;


long long cuadrado(long long x, long long y, vector<pair<long long, long long>> &b, vector<vector<long long>> &M, long long rev_x, long long rev_y){
    cout << "entrada a la funcion con:" << x << " " << y << endl;
    
    if(M[x][y] != -1){return M[x][y];}

    if(x < 0 ||y < 0){return 0;}
    
    else{
            cout << "entrada a la funcion BUCLE, comprobando con: " << rev_x << " " << rev_y << endl;

            if(x == rev_x && y == rev_y){
                return M[x][y];
            }
            if(x == rev_x){
                if(y < rev_y){
                    M[x][y] = 1 + cuadrado(x, y + 1, b, M, rev_x, rev_y);
                }else{
                    M[x][y] = 1 + cuadrado(x, y - 1, b, M, rev_x, rev_y);
                }
            }

            if(y == rev_y){
                if(x < rev_x){
                    M[x][y] = 1 + cuadrado(x + 1, y, b, M, rev_x, rev_y);
                }else{
                    M[x][y] = 1 + cuadrado(x - 1, y, b, M, rev_x, rev_y);
                }
            }else{
                if(y < rev_y){
                    M[x][y] = 1 + cuadrado(x, y + 1, b, M, rev_x, rev_y);
                }if(y > rev_y){
                    M[x][y] = 1 + cuadrado(x, y - 1, b, M, rev_x, rev_y);
                }
                
                if(x < rev_x){
                    M[x][y] = 1 + cuadrado(x + 1, y, b, M, rev_x, rev_y);
                }if(x > rev_x){
                    M[x][y] = 1 + cuadrado(x - 1, y, b, M, rev_x, rev_y);
                }
            }
    }
    return M[x][y];
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
    vector<pair<long long, long long>> baldosas;
    long long fil_max = -1;
    long long col_max = -1;

    while(getline(input, linea)){
        int coma = linea.find(',');
        long long x = stoll(linea.substr(0, coma));
        long long y = stoll(linea.substr(coma + 1));

        baldosas.push_back({x, y});

        if(y > fil_max){ fil_max = y;}
        if(x > col_max){ col_max = x;}
        
    }

    vector<vector<long long>> M(fil_max, vector<long long>(col_max, -1));
    long long prev_sol;

    for(int i = 0; i < baldosas.size(); i++){
        for(int j = 0; j < baldosas.size(); j++){
            prev_sol = cuadrado(baldosas[i].first, baldosas[i].second, baldosas, M, baldosas[j].first, baldosas[j].second);
            if(prev_sol > solucion){
                solucion = prev_sol;
            }
    
        }
    }


    input.close();
    cout << solucion << endl;

    return 0;
}