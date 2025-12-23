#ifndef BSNODE_H
#define BSNODE_H

#include <ostream>

template <typename T> 
// Clase del nodo con inervalos.
class BSNode {
    public:
    BSNode<T>* left;			// Puntero a hijo izquierdo.
	BSNode<T>* right;			// Puntero a hijo derecho.	
	T inicio;					// Inicio del rango/intervalo.
	T fin;						// Fin del rango/intervalo.
	T maxfin;					// Valor maximo de la rama.
	
	BSNode(T inicio, T fin);	// Constructor.

};
//Constructor, inicia el nodo con los punteros apuntando a nullptr y las variables de los rangos con los valores que se le mete como argumento.
template <typename T>
BSNode<T>::BSNode(T inicio, T fin){
	this->inicio = inicio;
	this->fin = fin;
	maxfin = fin;
	left = nullptr;
	right = nullptr;
}

#endif
