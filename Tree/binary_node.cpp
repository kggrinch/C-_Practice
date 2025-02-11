#ifndef BINARYNODE_CPP_
#define BINARYNODE_CPP_
#include "binary_node.h"
#include <iostream>

// default constructor
template<class T>
BinaryNode<T>::BinaryNode() : item {item}, rightChild(nullptr), leftChild(nullptr)
{

}

// destructor
// template<class T>
// BinaryNode<T>::~BinaryNode()
// {
//     // If suffering from memory leaks, uncomment next line
//     // std::cout << "Deleting " << *this << std::endl;
// }

// constructor setting item
// left and right childPtr set to nullptr as default
template<class T>
BinaryNode<T>::BinaryNode(const T& item) : item {item}, rightChild(nullptr), leftChild(nullptr)
{

}

// true if no children, both leftPtr and rightPtr are nullptrs
template<class T>
bool BinaryNode<T>::isLeaf() const
{
    return leftChild == nullptr && rightChild == nullptr;
}

// getter for left child
template<class T>
BinaryNode<T>* BinaryNode<T>::getLeftChildPtr() const
{
    return leftChild;
}

// setter for left child
template<class T>
void BinaryNode<T>::setLeftChildPtr(BinaryNode* childPtr)
{
    leftChild = childPtr;
}

// getter for right child
template<class T>
BinaryNode<T>* BinaryNode<T>::getRightChildPtr() const
{
    return rightChild;
}

// setter for left child
template<class T>
void BinaryNode<T>::setRightChildPtr(BinaryNode* childPtr)
{
    rightChild = childPtr;
}

// getter for item stored at node
template<class T>
T BinaryNode<T>::getItem() const
{
    return item;
}

// setter for item stored at node
template<class T>
void BinaryNode<T>::setItem(const T& item)
{
    this->item = item;
}

#endif