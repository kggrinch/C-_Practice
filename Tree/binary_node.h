
/** A class of nodes for a link-based binary tree. @file BinaryNode.h */
#ifndef BINARY_NODE_H_
#define BINARY_NODE_H_

template<class T> 
class BinaryNode
{

public:
  BinaryNode();
  BinaryNode(const T& anItem); BinaryNode(const T& anItem, BinaryNode<T>* leftPtr, BinaryNode<T>* rightPtr);
  void setItem(const T& anItem); T getItem() const;
  bool isLeaf() const;
  BinaryNode<T>* getLeftChildPtr() const;
  BinaryNode<T>* getRightChildPtr() const;
  void setLeftChildPtr(BinaryNode<T>* leftPtr);
  void setRightChildPtr(BinaryNode<T>* rightPtr);

private:
     T item;
     BinaryNode<T>* leftChild;
     BinaryNode<T>* rightChild;
};

#include "binary_node.cpp"

 #endif