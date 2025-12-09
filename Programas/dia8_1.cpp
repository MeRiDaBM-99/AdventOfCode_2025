#include<bits/stdc++.h>
using namespace std;

//definir los puntos
class Punto {
    public:
        long long x, y, z;
};

//inicialización de la estructura (cada 'nodo' es su propia raiz independiente)
template<typename T>
void iniciar(vector<T> &p, vector<T> &d, long long v){
    p[v] = v;
    d[v] = 1;
}

//calcular la distancia entre dos puntos
long long distancia(const Punto& a, const Punto& b) {
    long long dx = a.x - b.x;
    long long dy = a.y - b.y;
    long long dz = a.z - b.z;
    return (long long) sqrt((dx * dx) + (dy * dy) + (dz * dz));
}

//busca la raiz del subarbol montado por la union de diferentes cajas cercanas
template<typename T>
long long encontrar(vector<T> &p, long long x) {
    if (p[x] != x) {
        p[x] = encontrar(p, p[x]);
    }
    return p[x];
}

//Obtiene la raiz de ambos, si son iguales (ya estan unidos) no hace nada, sino 
//juntas el más pequeño (ry) con el más grande (rx) para aumentar su tamaño
template<typename T>
bool unir(vector<T> &p, vector<T> &d, long long x, long long y) {
    
    long long rx = encontrar(p, x);
    long long ry = encontrar(p, y);
    if (rx == ry){ 
        return false;
    }

    if (d[rx] < d[ry]){
        swap(rx, ry);
    }
    p[ry] = rx;
    d[rx] += d[ry];
    return true;

}


int main(){
    //Obtener datos del archivo
    ifstream input("input.txt");
    if(!input.is_open()){ 
        cerr << "Error, el archivo no se puede abrir" << endl;
        return 1;
    }

    vector<Punto> puntos;
    string linea;

    //guardamos los puntos en un vector
    while(getline(input, linea)){
        Punto p;
        char coma;
        stringstream ss(linea);

        ss >> p.x >> coma >> p.y >> coma >> p.z;

        puntos.push_back(p);
    }

    int n = puntos.size();
    
    //creamos los vectore padre y size y los iniciamos a por defectoo
    vector<long long> padre(n), size(n);
    for(long long i = 0; i < puntos.size(); i++){
        iniciar(padre, size, i);
    }

    //buscamos las distancias menores y vamos uniendo.
    set<pair<int, int>> conexiones;
    for(int x = 0; x < 1000; x++){
        long long dist_min = 10000000000;
        long long a = -1, b = -1;

        for(long long i = 0; i < puntos.size(); i++){
            for(long long j = i + 1; j < puntos.size(); j++){
                //Si la conexion no se ha hecho y la distancia es menor a la ya registrada
                if(!conexiones.count({i, j}) && distancia(puntos[i], puntos[j]) < dist_min){
                    dist_min = distancia(puntos[i], puntos[j]);
                    a = i; 
                    b = j;
                }
            }
        }
        unir(padre, size, a, b);
        conexiones.insert({a, b});
    }
    
    //se añaden los tamaños en una pila donde se colocan los más grandes en la cima.
    priority_queue<long long> pila;
    for(int i = 0; i < puntos.size(); i++){
        if(padre[i] == i){
            pila.push(size[i]);
        }
    }

    //extraemos los tamaños más grandes
    long long longitud1 = pila.top();
    pila.pop();
    long long longitud2 = pila.top();
    pila.pop();
    long long longitud3 = pila.top();
    pila.pop();

    
    cout << longitud1 << " " << longitud2 << " "  << longitud3 << endl;
    cout << longitud1 * longitud2 * longitud3;
    input.close();

    return 0;
}