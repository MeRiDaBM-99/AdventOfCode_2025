#ifndef BSTREE_H
#define BSTREE_H

#include <ostream>
#include <stdexcept>
#include "BSNode.h"

template <typename T> 
class BSTree {
    private:
	    int nelem;
	    BSNode<T> *root;

	    bool search(BSNode<T>* n, T id) const;
	    BSNode<T>* insert(BSNode<T>* n, T inicio, T fin);
	    T max(BSNode<T>* n) const;
	    void delete_cascade(BSNode<T>* n);
        
    public:
	    BSTree();
		~BSTree();
	    int size() const;
	    bool search(T id) const;
	    void insert(T inicio, T fin); 
};

template <typename T>
BSTree<T>::BSTree(){
	nelem = 0;
	root = nullptr;
}

template <typename T>
int BSTree<T>::size() const{
	return nelem;
}

template <typename T>
bool BSTree<T>::search(T id) const{
	return search(root, id);
}

template <typename T>
bool BSTree<T>::search(BSNode<T>* n, T id) const{
	if(n == nullptr)
		return false;
	if(id >= n->inicio && id <= n->fin)
		return true;
	if(n->left != nullptr && n->left->maxfin >= id)
		return search(n->left, id);
	return search(n->right, id);
}

template <typename T>
void BSTree<T>::insert(T inicio, T fin){
	root = insert(root, inicio, fin);
	nelem++;
}

template <typename T>
BSNode<T>* BSTree<T>::insert(BSNode<T>* n, T inicio, T fin){
	if(n == nullptr){
		return new BSNode<T>(inicio, fin);
	}
	if(inicio < n->inicio){
		n->left = insert(n->left, inicio, fin);
	}else{
		n->right = insert(n->right, inicio, fin);
	}
	T maxizq = n->fin;
	T maxder = n->fin;
	if(n->left !=nullptr)
		maxizq = n->left->maxfin;
	if(n->right != nullptr)
		maxder = n->right->maxfin;
	n->maxfin = std::max(n->fin, std::max(maxizq, maxder));
	return n;
}

template <typename T>
T BSTree<T>::max(BSNode<T>* n) const{
	if(n == nullptr){
        throw std::runtime_error("No se ha encontrado el elemento");
  	}else if(n->right != nullptr){
		return max(n->right);
	}else{
		return n->fin;
	}
}

template <typename T>
BSTree<T>::~BSTree(){
	delete_cascade(root);
}

template <typename T>
void BSTree<T>::delete_cascade(BSNode<T>* n){
	if(n != nullptr){
		delete_cascade(n->left);
		delete_cascade(n->right);
		delete n;
	}
}

#endif
