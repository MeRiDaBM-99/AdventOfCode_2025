#include<bits/stdc++.h>
using namespace std;

//Tamaño de la Tabla Hash
const int tam = 400; 

// Estructura del nodo del grafo, representa un dispositivo.
struct Nodo { 
    char nombre[20];                         // Nombre del dispositivo.
    vector<Nodo*> salidas;                   // Vector que contiene los dispositivos a los que puede conectarse.
    Nodo *next;                              // Puntero al nodo siguiente, en el caso de que haya colision en la Tabla Hash.
};

//Estructura para la Tabla Hash, consta de un array de punteros a nodos.
struct Hash { 
    Nodo *tabla[tam];
};

 // Inicializar la tabla vacia, para despues ir rellenandola.
void iniciarTabla(Hash &h){
    for(int i = 0; i< tam; i++)
        h.tabla[i] = nullptr;
}

// Convertir un nombre a un id para la Tabla Hash.
int nombre_a_numero(const char *nombre){ 
    int sum = 0;
    for(int i = 0; nombre[i] != '\0'; i++)  // Lee caracter a caracter sumando su valor en ASCII, y guardandolo en la variable sum.
        sum+= nombre[i];
    return sum % tam;                       // Hace el modulo entre sum y tam para obtener el id final.
}

// Busca un nombre en la Tabla.
Nodo* buscar_nombre(Hash &h, const char *nombre) { 
    int idx = nombre_a_numero(nombre);     // Convierte el nombre a buscar en el indice que hay que buscar en la tabla.
    Nodo *actual = h.tabla[idx];           // Puntero del primer nodo de la lista con ese indice.
    while (actual != nullptr) {            // Recorre toda la lista comparando el nombre a buscar con el que hay en cada nodo.
        if (strcmp(actual->nombre, nombre) == 0)
            return actual;                 // Si lo encuentra devuelve el nodo.
        actual = actual->next;
    }
    return nullptr;                        // Si no encuentra devuelve nullptr.
}

// Crear un nodo.
Nodo* crear_nodo(Hash &h, const char *nombre) {
    Nodo *n = buscar_nombre(h, nombre);
    //Comprobamos si el nodo existe en la tabla.
    if (n != nullptr) 
        return n;                         // Si existe, se devuelve 
    // Si no existe se crea un nuevo nodo.
    Nodo *nuevo = new Nodo; 
    strcpy(nuevo->nombre, nombre);        // Copiamos el nombre en el nodo.
    nuevo->salidas.clear();               // Inicializamos salidas vacio.
    nuevo->next = nullptr;                // Inicializamos el puntero para que apunte a nullptr.
    //Calculamos su indice y lo insertamos.
    int idx = nombre_a_numero(nombre);
    nuevo->next = h.tabla[idx];           // El nuevo nodo apunta al que estaba antes en esa posicion.
    h.tabla[idx] = nuevo;                 // Ahora el inicio de la lista apunta al nuevo nodo.
    //Devolvemos el nuevo nodo.
    return nuevo;
}

// Contabilizar todos los trayectos.
int definitivo(Nodo *inicio, Nodo *fin){
    // Caso base: si el nodo en el que estamos es el destino, se ha realizado el trayecto entero.
    if(inicio == fin)
        return 1;                                     // Contamos 1.
    // Si no probamos otros trayectos de manera recursiva.
    int def = 0;
    for(int i = 0; i<(int)inicio->salidas.size();i++) // Recorre toda la lista de dispositivos a los que puede ir.
        def+= definitivo(inicio->salidas[i], fin);
    return def;                                       // Devuelve la suma total de trayectos.
}


// Crear el grafo.
void crear_grafo(Hash &h, ifstream &archivo){
    iniciarTabla(h);                                    // Inicializamos la Tabla vacia.
    // Recorremos el archivo.
    string linea;
    while(getline(archivo, linea)){                     // Leemos el archivo linea a linea.
        // Si la linea esta vacia la pasamos.
        if(linea.empty())
            continue;
        // Separamos la linea en origen : destinos.
        int puntos = linea.find(':');
        string s1 = linea.substr(0, puntos);            // Origen.
        string s2 = linea.substr(puntos + 1);           // Destinos.
        Nodo *origen = crear_nodo(h, s1.c_str());       // Creamos nodo al origen.
        // Dividimos el destino por espacios.
        stringstream ss(s2);
        string destino;
        while(getline(ss, destino, ' ')){
            Nodo *nd = crear_nodo(h, destino.c_str());  // Creamos un nodo por cada destino.
            origen->salidas.push_back(nd);              // Metemos en la lista de dispositivos del origen, los destinos.
        }
    }
}

int main(){
    // Abrimos el archivo.
    ifstream archivo("aparatos.txt");
    if(!archivo.is_open()){                            // Si ha habido algun error muestra un mensaje de error y termina.
        cerr << "Error, el archivo no se puede abrir" << endl;
        return 1;
    }
    // Realizamos la busqueda de trayectorias.
    Hash h;                                            // Creamos una Tabla.
    crear_grafo(h, archivo); // Creamos el grafo.
    Nodo *inicio = buscar_nombre(h, "you");            // Buscamos el origen (you);
    Nodo *fin = buscar_nombre(h, "out");               // Buscamos el destino (out);
    // Si no se enceuntra origen o error muestra un mensaje de error y termina.
    if(inicio == nullptr || fin == nullptr){ 
        cout << "ERROR: no se encuentra you o out" << endl;
        return 1;
    }
    // Calculamos el numero de trayectorias validas y lo guardamos en total.
    int total = definitivo(inicio, fin);
    cout << total << endl;                            // Imprimimos por pantalla el resultado.
    return 0;
}


