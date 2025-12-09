#include<bits/stdc++.h>
using namespace std;

long long suma(const vector<string> &v){
    long long sum = 0;
    for(int i = 0; i < v.size() - 1; i++){
        sum += stoll(v[i]);
    }
    return sum;
}

long long prod(const vector<string> &v){
    long long prod = 1;
    for(int i = 0; i < v.size() - 1; i++){
        prod *= stoll(v[i]);
    }
    return prod;
}


int main(){
    //Obtener datos del archivo
    ifstream input("input.txt");
    if(!input.is_open()){ 
        cerr << "Error, el archivo no se puede abrir" << endl;
        return 1;
    }


    string linea;
    vector<vector<string>> operaciones;
    long long solucion = 0;
    string x;
    long long ndato = 0;
    bool crear = true;

    while(getline(input, linea)){
        istringstream ss(linea);

        if(crear){
            while(ss >> x){
                operaciones.emplace_back();
                operaciones.back().push_back(x);
            }
        }else{
            while(ss >> x){
                operaciones[ndato].push_back(x);

                ndato++;
            }
            ndato = 0;

        }
        crear = false;
        
    }

    for(int i = 0; i < operaciones.size(); i++){
        if(operaciones[i].back() == "+"){
            solucion += suma(operaciones[i]);
        }else if(operaciones[i].back() == "*"){
            solucion += prod(operaciones[i]);
        }
    }

    input.close();
    cout << solucion << endl;

    return 0;
}