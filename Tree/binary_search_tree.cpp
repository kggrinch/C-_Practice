#include <iostream>
#include "binary_search_tree.h"



template<class T>
BinarySearchTree<T>::BinarySearchTree()
{

}
  
template<class T>  
BinarySearchTree<T>::BinarySearchTree(const T& rootItem)
{

} 
  
template<class T>  
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>& tree)
{

}

template<class T>
BinarySearchTree<T>::~BinarySearchTree()
{

}

template<class T>
bool BinarySearchTree<T>::BinarySearchTree::isEmpty() const
{

}

template<class T>
int BinarySearchTree<T>::getHeight() const
{

}

template<class T>
int BinarySearchTree<T>::getNumberOfNodes() const
{

}

template<class T>
T BinarySearchTree<T>::getRootData() const
{

}

template<class T>
void BinarySearchTree<T>::setRootData(const T& newData) const
{

}

template<class T>
bool BinarySearchTree<T>::add(const T& newEntry)
{

}
  
template<class T>  
bool BinarySearchTree<T>::remove(const T& anEntry)
{

}

template<class T>
void BinarySearchTree<T>::clear()
{

}

template<class T>
T BinarySearchTree<T>::getEntry(const T& anEntry) const
{

}

template<class T>
bool BinarySearchTree<T>::contains(const T& anEntry) const
{

}

    // Traversal
template<class T>
void BinarySearchTree<T>::preorderTraverse(void visit(T&)) const
{

}

template<class T>
void BinarySearchTree<T>::inorderTraverse(void visit(T&)) const
{

}

template<class T>
void BinarySearchTree<T>::postorderTraverse(void visit(T&)) const
{

}

// Overload operators
template<class T>
BinarySearchTree<T>& BinarySearchTree<T>::operator=(const BinarySearchTree<T>& rightHandSide)
{

}