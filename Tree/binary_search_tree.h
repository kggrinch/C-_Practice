#ifndef BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_H_
#include <iostream>
#include "binary_node.h"
#include "binary_tree.h"
#include "tree_interface.h"

template <class T>
class BinarySearchTree : public BinaryTree<T> 
{
public:

    // Constructors
  BinarySearchTree();
  BinarySearchTree(const T& rootItem); 
  BinarySearchTree(const BinarySearchTree<T>& tree);
  virtual ~BinarySearchTree();


    // Methods
  bool isEmpty() const;
  int getHeight() const;
  int getNumberOfNodes() const;
  T getRootData() const;
  void setRootData(const T& newData) const;
  bool add(const T& newEntry);
  bool remove(const T& anEntry);
  void clear();
  T getEntry(const T& anEntry) const;
  bool contains(const T& anEntry) const;

    // Traversal
  void preorderTraverse(void visit(T&)) const;
  void inorderTraverse(void visit(T&)) const;
  void postorderTraverse(void visit(T&)) const;

    // Overload operators
  BinarySearchTree<T>& operator=(const BinarySearchTree<T>& rightHandSide);


protected:

  BinaryNode<T>* insertInorder(BinaryNode<T>* subTreePtr, BinaryNode<T>* newNode);

  // Removes the given target value from the tree while maintaining a // binary search tree.
  BinaryNode<T>* removeValue(BinaryNode<T>* subTreePtr, const T target, bool& success);

  // Removes a given node from a tree while maintaining a
  // binary search tree.
  BinaryNode<T>* removeNode(BinaryNode<T>* nodePtr);

  // Removes the leftmost node in the left subtree of the node // pointed to by nodePtr.
  // Sets inorderSuccessor to the value in this node.
  // Returns a pointer to the revised subtree. BinaryNode<ItemType>* removeLeftmostNode(
  BinaryNode<T>* removeLeftmostNode(BinaryNode<T>* subTreePtr, T& inorderSuccessor);

  BinaryNode<T>* findNode(BinaryNode<T>* treePtr, const T& target) const;

private:
    BinaryNode<T>* rootPtr;
};

#endif