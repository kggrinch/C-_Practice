#ifndef RED_BLACK_TREE_CPP
#define RED_BLACK_TREE_CPP
#include "red_black_tree.h"

template<class T>
RedBlackTree<T>::RedBlackTree()
{

}

template<class T>
RedBlackTree<T>::RedBlackTree(const T& rootItem)
{

}

template<class T>
RedBlackTree<T>::RedBlackTree(const RedBlackTree<T>& tree)
{

}

template<class T>
RedBlackTree<T>::~RedBlackTree()
{

}

// Red-Black Tree Operations

template<class T>
bool RedBlackTree<T>::add(const T& newEntry)
{

}


template<class T>
bool RedBlackTree<T>::remove(const T& anEntry)
{

}

// Helper methods for balancing

template<class T>
void RedBlackTree<T>::fixInsert(RedBlackNode<T>* node)
{

}

template<class T>
void RedBlackTree<T>::rotateLeft(RedBlackNode<T>* node)
{

}

template<class T>
void RedBlackTree<T>::rotateRight(RedBlackNode<T>* node)
{

}

template<class T>
RedBlackNode<T>* RedBlackTree<T>::insertInOrder(RedBlackNode<T>* subTreePtr, RedBlackNode<T>* newNode)
{

}

template<class T>
RedBlackNode<T>* RedBlackTree<T>::removeValue(RedBlackNode<T>* subTreePtr, const T target, bool& success)
{

}

#endif