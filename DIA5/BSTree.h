#ifndef BSTREE_H
#define BSTREE_H

#include <ostream>
#include <stdexcept>
#include "BSNode.h"

template <typename T> 
// Clase del arbol de intervalos.
class BSTree {
    private:
	    int nelem;												// Numero de elementos del arbol.
	    BSNode<T> *root; 										// Puntero a la raiz del arbol.

	    bool search(BSNode<T>* n, T id) const;					// Funcion que busca por identificador.
	    BSNode<T>* insert(BSNode<T>* n, T inicio, T fin);		// Funcion que inserta un nodo con un rango.
	    void delete_cascade(BSNode<T>* n);						// Funcion que borra el arbol.
        
    public:
	    BSTree();												// Constructor.
		~BSTree();												// Destructor.
	    int size() const;										// Funcion que devuelve el tamaño del arbol.
	    bool search(T id) const;								// Funcion lanzadera de bool search(BSNode<T>* n, T id) const.
	    void insert(T inicio, T fin);							// Funcion lanzadera de BSNode<T>* insert(BSNode<T>* n, T inicio, T fin).
};

// Constructor, inicializa el arbol vacio.
template <typename T>
BSTree<T>::BSTree(){
	nelem = 0;
	root = nullptr;
}

// Funcion que devuelve el tamaño del arbol (numero de elementos de este).
template <typename T>
int BSTree<T>::size() const{
	return nelem;
}

// Funcion lanzadera de bool search(BSNode<T>* n, T id) const.
template <typename T>
bool BSTree<T>::search(T id) const{
	return search(root, id);
}

// Funcion que busca por identificador.
template <typename T>
bool BSTree<T>::search(BSNode<T>* n, T id) const{
	// Caso base: Si el nodo no existe devuelve false (no se ha encontrado id).
	if(n == nullptr)
		return false;
	// Caso base: Si existe, mira si id esta dentro del rango, si lo esta devuelve true (el id se ha encontrado).
	if(id >= n->inicio && id <= n->fin)
		return true;
	// Si no esta en el nodo actual, mira en la izquierda si el valor maximo es mayor que el id llama recursivamente a la funcion para volver a comparar.
	if(n->left != nullptr && n->left->maxfin >= id)
		return search(n->left, id);
	// Si la anterior condicion no se da, busca en el lado derecho.
	return search(n->right, id);
}

// Funcion lanzadera de BSNode<T>* insert(BSNode<T>* n, T inicio, T fin).
template <typename T>
void BSTree<T>::insert(T inicio, T fin){
	root = insert(root, inicio, fin);
	nelem++;							// Incrementamos el numero de elementos del arbol.
}

// Funcion que inserta un nodo con un rango.
template <typename T>
BSNode<T>* BSTree<T>::insert(BSNode<T>* n, T inicio, T fin){
	// Caso base: Si el nodo actual es nulo, se crea uno nuevo con el intervalo (inicio, fin).
	if(n == nullptr){
		return new BSNode<T>(inicio, fin);
	}
	// Si el inicio a insertar es menor que el inicio del nodo actual se recorre el lado izquierdo.
	if(inicio < n->inicio){
		n->left = insert(n->left, inicio, fin);
	// Si no se recorre el lado derecho.
	}else{
		n->right = insert(n->right, inicio, fin);
	}
	// Se actualiza el valor de maxfin.
	T maxizq = n->fin;
	T maxder = n->fin;
	if(n->left !=nullptr)										// Si existe el hijo izquierdo se toma su maxfin.
		maxizq = n->left->maxfin;								
	if(n->right != nullptr)										// Si eexiste el hijo derecho se toma su maxfin.
		maxder = n->right->maxfin;
	n->maxfin = std::max(n->fin, std::max(maxizq, maxder));		// Se calcula el maxfin del nodo, con el maximo entre si mismo y sus hijos.
	return n;													// Se devulve el nodo ya actualizado.
}

// Destructor.
template <typename T>
BSTree<T>::~BSTree(){
	delete_cascade(root);
}

// Funcion que borra el arbol.
template <typename T>
void BSTree<T>::delete_cascade(BSNode<T>* n){
	if(n != nullptr){					// Si el nodo existe.
		delete_cascade(n->left);		// Llama recursivamente a la rama izquierda.
		delete_cascade(n->right);		// Llama recursivamente a la rama derecha.
		delete n;						// Borra el nodo.
	}
}

#endif
