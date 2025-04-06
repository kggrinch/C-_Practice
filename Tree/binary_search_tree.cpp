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
    rootPtr = tree.rootPtr ? BinaryTree<T>::copyTree(tree.rootPtr) : nullptr;
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
    int total = 0;
    BinaryTree<T>::getNumberOfNodesHelper(rootPtr);
    return total;
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
    // Needs implementation
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
        // Case 1. subTreePtr will become a nullptr if the remove node was a leaf node
        // Case 2. subTreePtr will become the left child of the remove node or the right child of the remove node
        // Case 3. subTreePtr will become the successor and the node where the successor was taken will be deleted
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
    // Case 1: if remove node does not have a left child
    if (!nodePtr->getLeftChildPtr()) // read this like if the nodePtr does not have a left child | If the nodePtr left child is not a real node (nullptr) | If nodePtr left child is a nullptr
    {
        // If no right child either, a nullptr is set to temp.
        BinaryNode<T>* temp = nodePtr->getRightChildPtr();
        delete nodePtr;
        nodePtr = nullptr;
        return temp;
    }
    // Case 2: If remove node does not have a right child
    // Case 1 & 2 both work in the case if remove node does not have children. In that case either case 1 will return a nullptr.
    else if (!nodePtr->getRightChildPtr())
    {
        BinaryNode<T>* temp = nodePtr->getLeftChildPtr();
        delete nodePtr;
        nodePtr = nullptr;
        return temp;
    }
    // Case 3: If remove node has two children.
    // Replace the remove node with the successor (smallest value from the remove node's right subtree) - default most common approach
    // or the processor (greatest value from the remove node's left subtree)
    else
    {
        // Save the Successor item
        T inorderSuccessor;
        nodePtr->setRightChildPtr(removeInorderSuccessor(nodePtr->getRightChildPtr(), inorderSuccessor)); // remove the successor node
        nodePtr->setItem(inorderSuccessor); // Set the remove_node with the successor item
        return nodePtr;
    }
}

// Removes the leftmost node in the left subtree of the node // pointed to by nodePtr.
// Sets inorderSuccessor to the value in this node.
// Returns a pointer to the revised subtree. BinaryNode<ItemType>* removeLeftmostNode(
template<class T>
BinaryNode<T>* BinarySearchTree<T>::removeInorderSuccessor(BinaryNode<T>* subTreePtr, T& inorderSuccessor)
{
    // If the left child is a nullptr it is the successor node
    if (!subTreePtr->getLeftChildPtr())
    {
        inorderSuccessor = subTreePtr->getItem(); // save successor item
        BinaryNode<T>* temp = subTreePtr->getRightChildPtr(); // replace the successor node with the right child. If no right child it will be set to nullptr
        delete subTreePtr;
        subTreePtr= nullptr;
        return temp; // return nullptr or the right child of the successor
    }
    else
    {
        // If not successor keep traversing left
        subTreePtr->setLeftChildPtr(removeInorderSuccessor(subTreePtr->getLeftChildPtr(), inorderSuccessor));
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