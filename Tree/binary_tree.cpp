#ifndef BINARY_TREE_CPP_
#define BINARY_TREE_CPP_
#include <iostream>
#include "binary_tree.h"
#include "stack"

// This is a binary tree. not a binary search tree.



// Constructors

// Default
template<class T> 
BinaryTree<T>::BinaryTree() : rootPtr(nullptr) 
{

} 

// constructor root only
template<class T> 
BinaryTree<T>::BinaryTree(const T& rootItem) : rootPtr(nullptr)
{
  rootPtr = new BinaryNode<T>(rootItem, nullptr, nullptr);
} 

// Overloaded constructor
template<class T> 
BinaryTree<T>::BinaryTree(const T& rootItem, const BinaryTree<T>* leftTreePtr, const BinaryTree<T>* rightTreePtr) : rootPtr(nullptr)
{
  rootPtr = new BinaryNode<T>(rootItem, copyTree(leftTreePtr->rootPtr), copyTree(rightTreePtr->rootPtr));
}

// Copy constructor
template<class T> 
BinaryTree<T>::BinaryTree(const BinaryTree<T>& treePtr) : rootPtr(nullptr)
{
  rootPtr = copyTree(treePtr.rootPtr);
}

// Deconstructor
template<class T>
BinaryTree<T>::~BinaryTree()
{
  destroyTree(rootPtr);
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
    destroyTree(subTreePtr->getLeftChildPtr());
    destroyTree(subTreePtr->getRightChildPtr());
    delete subTreePtr;
  }
} 

// Get height helper method

// Time Complexity: O(n)
template<class T>
int BinaryTree<T>::getHeightHelper(BinaryNode<T>* subTreePtr) const 
{
  if (subTreePtr == nullptr) return 0;

  return 1 + std::max(getHeightHelper(subTreePtr->getLeftChildPtr()), getHeightHelper(subTreePtr->getRightChildPtr()));
}

template<class T>
void BinaryTree<T>::getNumberOfNodesHelper(BinaryNode<T>* subTreePtr, int& total) const
{
  if(!subTreePtr)
  {
    getNumberOfNodesHelper(subTreePtr->getLeftChildPtr(), total);
    total++;
    getNumberOfNodesHelper(subTreePtr->getRightChildPtr(), total);
  }
}


// Add method
template<class T>
bool BinaryTree<T>::add(const T& newData) 
{
  BinaryNode<T>* newNodePtr = new BinaryNode<T>(newData);
  rootPtr = balancedAdd(rootPtr, newNodePtr);
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
    BinaryNode<T>* leftPtr = subTreePtr->getLeftChildPtr(); BinaryNode<T>* rightPtr = subTreePtr->getRightChildPtr();
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

template<class T>
void BinaryTree<T>::preorderTraverse(void visit(T&)) const
{
  preorder(visit, rootPtr);
}

template<class T>
void BinaryTree<T>::inorderTraverse(void visit(T&)) const
{
  inorder(visit, rootPtr);
}

template<class T>
void BinaryTree<T>::postorderTraverse(void visit(T&)) const
{
  postorder(visit, rootPtr);
}



// In-order traversal helper
template<class T>
void BinaryTree<T>::inorder(void visit(T&), BinaryNode<T>* treePtr) const
{
  if (treePtr != nullptr) 
  {
    inorder(visit, treePtr->getLeftChildPtr()); 
    T theItem = treePtr->getItem();
    visit(theItem);
    inorder(visit, treePtr->getRightChildPtr());
  }
}

// pre order traverse helper
template<class T>
void BinaryTree<T>::preorder(void visit(T&), BinaryNode<T>* treePtr) const
{
  if (treePtr != nullptr) 
  {
    T theItem = treePtr->getItem();
    visit(theItem);
    preorder(visit, treePtr->getLeftChildPtr()); 
    preorder(visit, treePtr->getRightChildPtr());
  }
}

// postorder traverse helper
template<class T>
void BinaryTree<T>::postorder(void visit(T&), BinaryNode<T>* treePtr) const
{
  if (treePtr != nullptr) 
  {
    postorder(visit, treePtr->getLeftChildPtr()); 
    postorder(visit, treePtr->getRightChildPtr());
    T theItem = treePtr->getItem();
    visit(theItem);
  }
}

// Non recursive in order traversal method
// template<class T>
// void inorderTraverseNonRecursive(void visit(T&))
// {
//   std::stack my_stack;
//   curPtr = rootPtr() // Start at root done = false
//   bool done = false;
//
//   while (!done)
//   {
//     if (curPtr != nullptr)
//     {
//     // Place pointer to node on stack before traversing the node’s left subtree nodeStack.push(curPtr)
//     // Traverse the left subtree
//     curPtr = curPtr->getLeftChildPtr()
//     }
//     else // Backtrack from the empty subtree and visit the node at the top of // the stack; however, if the stack is empty, you are done
//     {
//       if (!nodeStack.isEmpty())
//       {
//         nodeStack.peek(curPtr)
//
//         visit(curPtr->getItem())
//         nodeStack.pop()
//         // Traverse the right subtree of the node just visited
//         curPtr = curPtr ->getRightChildPtr()
//       }
//       else
//       {
//         done = true
//       }
//     }
//   }
// }

#endif