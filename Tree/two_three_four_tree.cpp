#ifndef TWO_THREE_FOUR_TREE_CPP_
#define TWO_THREE_FOUR_TREE_CPP_
#include "two_three_four_tree.h"

template<class T>
TwoThreeFourTree<T>::TwoThreeFourTree()
{

}

template<class T>
TwoThreeFourTree<T>::TwoThreeFourTree(const T& rootItem)
{

}

template<class T>
TwoThreeFourTree<T>::TwoThreeFourTree(const TwoThreeFourTree<T>& tree)
{

}

template<class T>
TwoThreeFourTree<T>::~TwoThreeFourTree()
{

}

// Methods
template<class T>
bool TwoThreeFourTree<T>::isEmpty() const
{

}

template<class T>
int TwoThreeFourTree<T>::getHeight() const
{

}

template<class T>
int TwoThreeFourTree<T>::getNumberOfNodes() const
{

}

template<class T>
T TwoThreeFourTree<T>::getRootData() const
{

}

template<class T>
void TwoThreeFourTree<T>::setRootData(const T& newData) const
{

}

template<class T>
bool TwoThreeFourTree<T>::add(const T& newEntry)
{

}

template<class T>
bool TwoThreeFourTree<T>::remove(const T& anEntry)
{

}

template<class T>
void TwoThreeFourTree<T>::clear()
{

}

template<class T>
T TwoThreeFourTree<T>::getEntry(const T& anEntry) const
{

}

template<class T>
bool TwoThreeFourTree<T>::contains(const T& anEntry) const
{

}

// Traversals
template<class T>
void TwoThreeFourTree<T>::preorderTraverse(void visit(T&)) const
{

}

template<class T>
void TwoThreeFourTree<T>::inorderTraverse(void visit(T&)) const
{

}

template<class T>
void TwoThreeFourTree<T>::postorderTraverse(void visit(T&)) const
{

}

// operator overloading
template<class T>
TwoThreeFourTree<T>& TwoThreeFourTree<T>::operator=(const TwoThreeFourTree<T>& rightHandSide)
{

}

template<class T>
T TwoThreeFourTree<T>::Max()
{

}

// Remove 2-3 helper functions
template<class T>
QuadNode<T>* TwoThreeFourTree<T>::removeValue(QuadNode<T>* subTreePtr, const T target, bool& success, QuadNode<T>*& new_child)
{

}

template<class T>
T TwoThreeFourTree<T>::findSuccessor(QuadNode<T>* subTreePtr)
{

}

template<class T>
QuadNode<T>* TwoThreeFourTree<T>::balanceAfterRemoval(QuadNode<T>* nodePtr, QuadNode<T>*& new_child)
{

}

template<class T>
int TwoThreeFourTree<T>::get_balance(BinaryNode<T>* sub_root)
{

}

// other helper functions
template<class T>
QuadNode<T>* TwoThreeFourTree<T>::findNode(QuadNode<T>* treePtr, const T& target) const
{

}

template<class T>
QuadNode<T>* TwoThreeFourTree<T>::Max_helper(QuadNode<T>* treePtr)
{

}

template<class T>
int TwoThreeFourTree<T>::get_height_helper(QuadNode<T>* subTreePtr)
{

}

template<class T>
void TwoThreeFourTree<T>::getNumberOfNodesHelper(QuadNode<T>* subTreePtr, int& total) const
{

}

// 2-3 Tree Traversal helper functions
template<class T>
void TwoThreeFourTree<T>::preorder(void visit(T&), QuadNode<T>* subTreePtr) const
{

}

template<class T>
void TwoThreeFourTree<T>::inorder(void visit(T&), QuadNode<T>* subTreePtr) const
{

}

template<class T>
void TwoThreeFourTree<T>::postorder(void visit(T&), QuadNode<T>* subTreePtr) const
{

}

// Insert 2-3-4 helper methods
template<class T>
QuadNode<T>* TwoThreeFourTree<T>::insertIntoNode(QuadNode<T>* nodePtr, const T& newItem, QuadNode<T>*& newChildPtr, T& medianValue)
{

}

template<class T>
void TwoThreeFourTree<T>::splitNode(QuadNode<T>* nodePtr, const T& newItem, QuadNode<T>* newChildPtr, T& medianValue, QuadNode<T>*& rightHalf)
{

}

template<class T>
QuadNode<T>* TwoThreeFourTree<T>::findParent(QuadNode<T>* root, QuadNode<T>* child)
{

}


// Remove 2-3-4 helper methods
// returns the parent where the child has a balance issue
template<class T>
QuadNode<T>* TwoThreeFourTree<T>::balance_mistake_parent(QuadNode<T>* subTreePtr)
{

}



#endif



