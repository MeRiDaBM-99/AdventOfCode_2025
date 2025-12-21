#include<bits/stdc++.h>
using namespace std;

const int tam = 400;

struct Nodo {
    char nombre[20];
    vector<Nodo*> salidas;
    Nodo *next;  
};

struct Hash {
    Nodo *tabla[tam];
};

void iniciarTabla(Hash &h){
    for(int i = 0; i< tam; i++)
        h.tabla[i] = nullptr;
}

int nombre_a_numero(const char *nombre){
    int sum = 0;
    for(int i = 0; nombre[i] != '\0'; i++)
        sum+= nombre[i];
    return sum % tam;
}

Nodo* buscar_nombre(Hash &h, const char *nombre) {
    int idx = nombre_a_numero(nombre);
    Nodo *actual = h.tabla[idx];
    while (actual != NULL) {
        if (strcmp(actual->nombre, nombre) == 0) {
            return actual;
        }
        actual = actual->next;
    }
    return nullptr;
}

Nodo* crear_nodo(Hash &h, const char *nombre) {
    Nodo *n = buscar_nombre(h, nombre);
    if (n != nullptr) return n;

    Nodo *nuevo = new Nodo;
    strcpy(nuevo->nombre, nombre);
    nuevo->salidas.clear();
    nuevo->next = nullptr;

    int idx = nombre_a_numero(nombre);
    nuevo->next = h.tabla[idx];
    h.tabla[idx] = nuevo;

    return nuevo;
}

int definitivo(Nodo *inicio, Nodo *fin){
    if(inicio == fin)
        return 1;
    int def = 0;
    for(int i = 0; i<(int)inicio->salidas.size();i++)
        def+= definitivo(inicio->salidas[i], fin);
    return def;
}

void crear_grafo(Hash &h, ifstream &archivo){
    iniciarTabla(h);
    string linea;
    while(getline(archivo, linea)){
        if(linea.empty())
            continue;
        int puntos = linea.find(':');
        string s1 = linea.substr(0, puntos);
        string s2 = linea.substr(puntos + 1);
        Nodo *origen = crear_nodo(h, s1.c_str());
        stringstream ss(s2);
        string destino;
        while(getline(ss, destino, ' ')){
            Nodo *nd = crear_nodo(h, destino.c_str());
            origen->salidas.push_back(nd);
        }
    }
}

int main(){
    ifstream archivo("aparatos.txt");
    if(!archivo.is_open()){ 
        cerr << "Error, el archivo no se puede abrir" << endl;
        return 1;
    }
    Hash h;
    crear_grafo(h, archivo);
    Nodo *inicio = buscar_nombre(h, "you");
    Nodo *fin = buscar_nombre(h, "out");
    if(inicio == nullptr || fin == nullptr){
        cout << "ERROR: no se encuentra you o out" << endl;
        return 1;
    }
    int total = definitivo(inicio, fin);
    cout << total << endl;
    return 0;
}
