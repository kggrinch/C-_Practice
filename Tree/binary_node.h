
/** A class of nodes for a link-based binary tree. @file BinaryNode.h */
#ifndef _BINARY_NODE 
#define _BINARY_NODE

template<class T> 
class BinaryNode
{

public:
  BinaryNode();
  BinaryNode(const T& anItem); BinaryNode(const T& anItem,
  BinaryNode<T>* leftPtr, BinaryNode<T>* rightPtr);
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

 #endif