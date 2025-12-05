#include<bits/stdc++.h>
using namespace std;

template <typename T> 
class BSNode {
    public:
        //ATRIBUTOS
	T elem;			//Elemento almacenado
	BSNode<T>* left;	//Puntero al nodo sucesor izquierdo
	BSNode<T>* right;	//Puntero al nodo sucesor derecho
    
	//MÉTODOS
	//Constructor
	BSNode(T elem, BSNode<T>* left=nullptr, BSNode<T>* right=nullptr):elem{elem}, left{left}, right{right}{}

};

template <typename T> 
class BSTree {
    private:
        //ATRIBUTOS
	int nelem;		//Nº elementos almacenados
	BSNode<T> *root;	//Nodo raiz

	//MÉTODOS
	//Inserción de elementos
	BSNode<T>* insert(BSNode<T>* n, T e){
		if(n == null){
			return new Node(e);
		}else if (n->elem == e){
			break;
		}else if (n->elem < e){
			n->right = insert(n->right, e);
		}else{
			n->left = insert(n->left, e);
		}

		return n;
	}

    public:
    //MÉTODOS
	//Creación y tamaño
	BSTree(): nelem{0}{}	//Constructor vacio

	int size() const{	//Devuelve el nº de elementos
		return nelem;
	}
	

	//Inserción de elementos
	void insert(T e){
		root = insert(root, e);
	}

};




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
    long long solucion = 0;
    long long cont, aux;
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

            for(int i = 0; i < rango.size(); i++){
                for(int i = rango[i].first; i <= rango[i].second; i++){
                    bstree.insert(i);
                }
            }
            

            /*
            for(int i = 0; i < rango.size(); i++){
                cont = 0;
                if (maxi < rango[i].second && mini > rango[i].first){    //El rango esta contenido en otro más grande
                        cont = 0;
                        break;
                }

                if(mini < rango[i].second){
                    if(maxi > rango[i].second && mini > rango[i].first){       // El mini esta contenido pero el maxi esta fuera de otro rango.
                        if(cont != 0){                      //Por si ya ha hecho calculos respecto otro rango
                            aux = maxi + 1 - rango[i].second;
                            cont = abs(aux - cont);
                        }else{
                            cont = maxi + 1 - rango[i].second;
                        }
                    }
                }else if(maxi < rango[i].second){  
                    if(mini < rango[i].first && maxi > rango[i].first){      //Maxi esta contenido pero mini esta fuera de otro rango
                        if(cont != 0){
                            aux = rango[i].first + 1 - mini;
                            cont = abs(aux - cont);
                        }else{
                            cont = rango[i].first + 1 - mini;
                        }
                    }
                }else if((mini < rango[i].first && maxi < rango[i].first) || (mini > rango[i].second && maxi > rango[i].second)){
                    cont = maxi + 1 - mini;
                }
            }
            solucion += cont;
            */
        }
        
    }


    input.close();
    cout << bstree.size() << endl;

    return 0;
}