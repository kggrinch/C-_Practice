#ifndef BINARY_SEARCH_TREE_CPP_
#define BINARY_SEARCH_TREE_CPP_
#include <iostream>
#include "binary_search_tree.h"



template<class T>
BinarySearchTree<T>::BinarySearchTree() : rootPtr(nullptr)
{

}

template<class T>
BinarySearchTree<T>::BinarySearchTree(const T& rootItem) : rootPtr(nullptr)
{
    rootPtr = new BinaryNode<T>(rootItem);
}

template<class T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>& tree) : rootPtr(nullptr)
{
    rootPtr = tree.rootPtr ? new BinaryNode<T>(*tree.rootPtr) : nullptr;
}

template<class T>
BinarySearchTree<T>::~BinarySearchTree()
{
    clear();
}

template<class T>
bool BinarySearchTree<T>::BinarySearchTree::isEmpty() const
{
    return rootPtr == nullptr;
}

template<class T>
int BinarySearchTree<T>::getHeight() const
{
    return BinaryTree<T>::getHeightHelper(rootPtr);
}

template<class T>
int BinarySearchTree<T>::getNumberOfNodes() const
{
    return BinaryTree<T>::getNumberOfNodesHelper(rootPtr);
}

template<class T>
T BinarySearchTree<T>::getRootData() const
{
    if (isEmpty()) throw std::runtime_error("Tree is empty"); // Might not need
    return rootPtr->getItem();
}

template<class T>
void BinarySearchTree<T>::setRootData(const T& newData) const
{
    if (rootPtr) rootPtr->setItem(newData);
}

template<class T>
bool BinarySearchTree<T>::add(const T& newEntry)
{
    BinaryNode<T>* newNode = new BinaryNode<T>(newEntry);
    rootPtr = insertInorder(rootPtr, newNode);
    return true;
}

template<class T>
bool BinarySearchTree<T>::remove(const T& anEntry)
{
    bool success = false;
    rootPtr = removeValue(rootPtr, anEntry, success);
    return success;
}

template<class T>
void BinarySearchTree<T>::clear()
{
    BinaryTree<T>::destroyTree(rootPtr);
    rootPtr = nullptr;
}

template<class T>
T BinarySearchTree<T>::getEntry(const T& anEntry) const
{
    BinaryNode<T>* node = findNode(rootPtr, anEntry);
    if (!node) throw std::runtime_error("Entry not found");
    return node->getItem();
}

template<class T>
bool BinarySearchTree<T>::contains(const T& anEntry) const
{
    return findNode(rootPtr, anEntry) != nullptr;
}

    // Traversal
template<class T>
void BinarySearchTree<T>::preorderTraverse(void visit(T&)) const
{
    BinaryTree<T>::preorder(visit, rootPtr);
}

template<class T>
void BinarySearchTree<T>::inorderTraverse(void visit(T&)) const
{
    BinaryTree<T>::inorder(visit, rootPtr);
}

template<class T>
void BinarySearchTree<T>::postorderTraverse(void visit(T&)) const
{
    BinaryTree<T>::postorder(visit, rootPtr);
}

// Overload operators
template<class T>
BinarySearchTree<T>& BinarySearchTree<T>::operator=(const BinarySearchTree<T>& rightHandSide)
{
    if (this != &rightHandSide) {
        clear();
        rootPtr = rightHandSide.rootPtr ? new BinaryNode<T>(*rightHandSide.rootPtr) : nullptr;
    }
    return *this;
}

// protected methods
template<class T>
BinaryNode<T>* BinarySearchTree<T>::insertInorder(BinaryNode<T>* subTreePtr, BinaryNode<T>* newNode)
{
    if (!subTreePtr) return newNode;

    if (newNode->getItem() < subTreePtr->getItem()) {
        subTreePtr->setLeftChildPtr(insertInorder(subTreePtr->getLeftChildPtr(), newNode));
    } else {
        subTreePtr->setRightChildPtr(insertInorder(subTreePtr->getRightChildPtr(), newNode));
    }
    return subTreePtr;
}

// Removes the given target value from the tree while maintaining a // binary search tree.
template<class T>
BinaryNode<T>* BinarySearchTree<T>::removeValue(BinaryNode<T>* subTreePtr, const T target, bool& success)
{
    if (!subTreePtr) return nullptr;

    if (target < subTreePtr->getItem()) {
        subTreePtr->setLeftChildPtr(removeValue(subTreePtr->getLeftChildPtr(), target, success));
    } else if (target > subTreePtr->getItem()) {
        subTreePtr->setRightChildPtr(removeValue(subTreePtr->getRightChildPtr(), target, success));
    } else {
        subTreePtr = removeNode(subTreePtr);
        success = true;
    }
    return subTreePtr;
}

// Removes a given node from a tree while maintaining a
// binary search tree.
template<class T>
BinaryNode<T>* BinarySearchTree<T>::removeNode(BinaryNode<T>* nodePtr)
{
    if (!nodePtr->getLeftChildPtr()) {
        BinaryNode<T>* temp = nodePtr->getRightChildPtr();
        delete nodePtr;
        return temp;
    } else if (!nodePtr->getRightChildPtr()) {
        BinaryNode<T>* temp = nodePtr->getLeftChildPtr();
        delete nodePtr;
        return temp;
    } else {
        T inorderSuccessor;
        nodePtr->setRightChildPtr(removeLeftmostNode(nodePtr->getRightChildPtr(), inorderSuccessor));
        nodePtr->setItem(inorderSuccessor);
        return nodePtr;
    }
}

// Removes the leftmost node in the left subtree of the node // pointed to by nodePtr.
// Sets inorderSuccessor to the value in this node.
// Returns a pointer to the revised subtree. BinaryNode<ItemType>* removeLeftmostNode(
template<class T>
BinaryNode<T>* BinarySearchTree<T>::removeLeftmostNode(BinaryNode<T>* subTreePtr, T& inorderSuccessor)
{
    if (!subTreePtr->getLeftChildPtr()) {
        inorderSuccessor = subTreePtr->getItem();
        BinaryNode<T>* temp = subTreePtr->getRightChildPtr();
        delete subTreePtr;
        return temp;
    } else {
        subTreePtr->setLeftChildPtr(removeLeftmostNode(subTreePtr->getLeftChildPtr(), inorderSuccessor));
        return subTreePtr;
    }
}

template<class T>
BinaryNode<T>* BinarySearchTree<T>::findNode(BinaryNode<T>* treePtr, const T& target) const
{
    if (!treePtr) return nullptr;

    if (target == treePtr->getItem()) return treePtr;
    else if (target < treePtr->getItem()) return findNode(treePtr->getLeftChildPtr(), target);
    else return findNode(treePtr->getRightChildPtr(), target);
}



// Personal methods
template<class T>
T BinarySearchTree<T>::Max()
{
    return Max_helper(rootPtr)->getItem();
}

template<class T>
BinaryNode<T>* BinarySearchTree<T>::Max_helper(BinaryNode<T>* treePtr)
{
    if(treePtr == nullptr)
    {
        return nullptr;
    }
    if(treePtr->getRightChildPtr() == nullptr)
    {
        return treePtr;
    }
    return Max_helper(treePtr->getRightChildPtr());
}







#endif