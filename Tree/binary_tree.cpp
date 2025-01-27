#include <iostream>
#include "binary_tree.h"
#include "stack"


// This is a binary tree. nont a binary search tree.



// Constructors

// Default
template<class T> 
BinaryTree<T>::BinaryTree() : rootPtr(nullptr) 
{

} 

// constructor root only
template<class T> 
BinaryTree<T>::BinaryTree(const T& rootItem) 
{
  rootPtr = new BinaryNode<T>(rootItem, nullptr, nullptr);
} 

// Overloaded constructor
template<class T> 
BinaryTree<T>::BinaryTree(const T& rootItem, const BinaryTree<T>* leftTreePtr, const BinaryTree<T>* rightTreePtr)
{
  rootPtr = new BinaryNode<T>(rootItem, copyTree(leftTreePtr->rootPtr), copyTree(rightTreePtr->rootPtr));
}

// Copy constructor
template<class T> 
BinaryTree<T>::BinaryTree(const BinaryTree<T>& treePtr)
{
  rootPtr = copyTree(treePtr.rootPtr);
}

// Deconstructor
template<class T>
BinaryTree<T>::~BinaryTree()
{
  destroyTree();
}

// Copy method used by copy constructors
template<class T> 
BinaryNode<T>* BinaryTree<T>::copyTree(const BinaryNode<T>* treePtr)  const
{
  BinaryNode<T>* newTreePtr = nullptr;

  // Copy tree nodes during a preorder traversal
  if (treePtr != nullptr)
  {
    // Copy node
    newTreePtr = new BinaryNode<T>(treePtr->getItem(), nullptr, nullptr); 
    newTreePtr->setLeftChildPtr(copyTree(treePtr->getLeftChildPtr()));
    newTreePtr->setRightChildPtr(copyTree(treePtr->getRightChildPtr())); 
  } 

  // Else tree is empty (newTreePtr is nullptr)
  return newTreePtr;

}

// Destroy tree method used in deconstructor
template<class T>
void BinaryTree<T>::destroyTree(BinaryNode<T>* subTreePtr)
{
  if (subTreePtr != nullptr)
  {
    destroyTree(subTreePtr->getLeftChildPtr()); destroyTree(subTreePtr->getRightChildPtr()); delete subTreePtr;
  }
} 

// Get height helper method
template<class T>
int BinaryTree<T>::getHeightHelper(BinaryNode<T>* subTreePtr) const 
{
  if (subTreePtr == nullptr) 
  {
    return 0;
  }
  else
  {
    return 1 + max(getHeightHelper(subTreePtr->getLeftChildPtr()), getHeightHelper(subTreePtr->getRightChildPtr())); 

  }
} 


// Add method
template<class T>
bool BinaryTree<T>::add(const T& newData) 
{
  BinaryNode<T>* newNodePtr = new BinaryNode<T>(newData); rootPtr = balancedAdd(rootPtr, newNodePtr);
  return true;
}

// Balanced add method
template<class T>
BinaryNode<T>* BinaryTree<T>::balancedAdd(BinaryNode<T>* subTreePtr, BinaryNode<T>* newNodePtr)
{
  if (subTreePtr == nullptr)
  {
    return newNodePtr;
  }
  else
  {
    BinaryNode<ItemType>* leftPtr = subTreePtr->getLeftChildPtr(); BinaryNode<ItemType>* rightPtr = subTreePtr->getRightChildPtr();
    if (getHeightHelper(leftPtr) > getHeightHelper(rightPtr)) 
    {
      rightPtr = balancedAdd(rightPtr, newNodePtr);
      subTreePtr->setRightChildPtr(rightPtr);
    }
    else
    {
      leftPtr = balancedAdd(leftPtr, newNodePtr); subTreePtr->setLeftChildPtr(leftPtr);
    }
    return subTreePtr; 
  } 
}


// In-order traversal
template<class T>
void BinaryTree<T>::inorder(void visit(T&), BinaryNode<T>* treePtr) const
{
  if (treePtr != nullptr) 
  {
    inorder(visit, treePtr->getLeftChildPtr()); 
    ItemType theItem = treePtr->getItem(); visit(theItem);
    inorder(visit, treePtr->getRightChildPtr());
  }
}

template<class T>
void BinaryTree<T>::preorder(void visit(T&), BinaryNode<T>* treePtr) const
{
  if (treePtr != nullptr) 
  {
    ItemType theItem = treePtr->getItem(); visit(theItem);
    preorder(visit, treePtr->getLeftChildPtr()); 
    preorder(visit, treePtr->getRightChildPtr());
  }
}

template<class T>
void BinaryTree<T>::postorder(void visit(T&), BinaryNode<T>* treePtr) const
{
  if (treePtr != nullptr) 
  {
    postorder(visit, treePtr->getLeftChildPtr()); 
    postorder(visit, treePtr->getRightChildPtr());
    ItemType theItem = treePtr->getItem(); visit(theItem);
  }
}

// Non recursive in order traversal method
template<class T>
void inorderTraverseNonRecursive(void visit(T&))
{
  std::stack my_stack;
  curPtr = rootPtr() // Start at root done = false
  bool done = false;

  while (!done) 
  {
    if (curPtr != nullptr) 
    {
    // Place pointer to node on stack before traversing the node’s left subtree nodeStack.push(curPtr)
    // Traverse the left subtree
    curPtr = curPtr->getLeftChildPtr() 
    }
    else // Backtrack from the empty subtree and visit the node at the top of // the stack; however, if the stack is empty, you are done
    {
      if (!nodeStack.isEmpty()) 
      {
        nodeStack.peek(curPtr)
        
        visit(curPtr->getItem())
        nodeStack.pop()
        // Traverse the right subtree of the node just visited
        curPtr = curPtr ->getRightChildPtr()
      }
      else
      {
        done = true
      }
    }
  }
}