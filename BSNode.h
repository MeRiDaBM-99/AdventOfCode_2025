#ifndef BSNODE_H
#define BSNODE_H

#include <ostream>

template <typename T> 
class BSNode {
    public:
    BSNode<T>* left;
	BSNode<T>* right;
	T inicio;
	T fin;
	T maxfin;
	
	BSNode(T inicio, T fin);

};

template <typename T>
BSNode<T>::BSNode(T inicio, T fin){
	this->inicio = inicio;
	this->fin = fin;
	maxfin = fin;
	left = nullptr;
	right = nullptr;
}

#endif
