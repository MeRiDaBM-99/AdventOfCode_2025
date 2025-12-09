#include<bits/stdc++.h>
using namespace std;


template <typename T>
class BSNode {
public:
    // ATRIBUTOS
    T elem;                 // Elemento almacenado
    BSNode<T>* left;        // Puntero al nodo sucesor izquierdo
    BSNode<T>* right;       // Puntero al nodo sucesor derecho

    // MÉTODOS
    // Constructor
    BSNode(T elem, BSNode<T>* left=nullptr, BSNode<T>* right=nullptr)
        : elem{elem}, left{left}, right{right} {}
};

template <typename T>
class BSTree {
private:
    // ATRIBUTOS
    long long nelem;              // Nº elementos almacenados
    BSNode<T>* root;        // Nodo raiz

    // MÉTODOS
    // Inserción de elementos (versión interna)
    // Devuelve el nuevo subárbol y un flag de si se insertó (para actualizar nelem)
    std::pair<BSNode<T>*, bool> insert(BSNode<T>* n, const T& e) {
        if (n == nullptr) {
            // crear nodo nuevo
            return { new BSNode<T>(e), true };            // ← cambio (BSNode, y devolvemos flag)
        } else if (n->elem == e) {
            // duplicado: no insertamos nada
            return { n, false };                           // ← cambio (no devolver -1; mantener el nodo y flag=false)
        } else if (n->elem < e) {
            auto res = insert(n->right, e);                // ← cambio (propagar flag)
            n->right = res.first;
            return { n, res.second };
        } else {
            auto res = insert(n->left, e);                 // ← cambio (propagar flag)
            n->left = res.first;
            return { n, res.second };
        }
    }

public:
    // MÉTODOS
    // Creación y tamaño
    BSTree() : nelem{0}, root{nullptr} {}                  // ← cambio (inicializar root)

    long long size() const {                                     // Devuelve el nº de elementos
        return nelem;
    }

    // Inserción de elementos (API pública)
    // Devuelve 1 si se insertó, 0 si era duplicado
    long long insert(const T& e) {                               // ← cambio (firma y retorno coherente)
        auto res = insert(root, e);                        // llama a la interna
        root = res.first;
        if (res.second) ++nelem;                           // ← cambio (actualizar nelem solo si insertó)
        return res.second ? 1 : 0;
    }
};



int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //Obtener datos del archivo
    ifstream input("input.txt");
    if(!input.is_open()){ 
        cerr << "Error, el archivo no se puede abrir" << endl;
        return 1;
    }


    string linea;
    vector<pair<long long, long long>> rango;
    bool cambiarDato = false;
    long long solucion = 0;
    BSTree<long long> bstree = BSTree<long long>();

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

            for(long long i = 0; i < rango.size(); i++){
                for(long long j = rango[i].first; j <= rango[i].second; j++){
                    bstree.insert(j);
                }
            }
            
        }
        
    }


    input.close();
    cout << bstree.size() << endl;

    return 0;
}