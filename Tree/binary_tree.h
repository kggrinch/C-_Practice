#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_
#include <iostream>
#include "binary_node.h"
#include "tree_interface.h"

template <class T>
class BinaryTree : public Tree<T> 
{
  public:

    // Constructors
    BinaryTree();
    BinaryTree(const T& rootItem); 
    BinaryTree(const T& rootItem, const BinaryTree<T>* leftTreePtr, const BinaryTree<T>* rightTreePtr);
    BinaryTree(const BinaryTree<T>& tree);
    virtual ~BinaryTree();

    // Methods
    bool isEmpty() const;
    int getHeight() const;
    int getNumberOfNodes() const;
    T getRootData() const throw(PrecondViolatedExcep); 
    void setRootData(const T& newData);
    bool add(const T& newData); // Adds a node
    bool remove(const T& data); // Removes a node
    void clear();
    T getEntry(const T& anEntry) const throw(NotFoundException);
    bool contains(const T& anEntry) const;

    // Traversal
    void preorderTraverse(void visit(T&)) const;
    void inorderTraverse(void visit(T&)) const;
    void postorderTraverse(void visit(T&)) const;
    void inorderTraverseNonRecursive(void visit(T&));

    // Overload operators
    BinaryNodeTree& operator=(const BinaryNodeTree& rightHandSide);


  protected:
    int getHeightHelper(BinaryNode<T>* subTreePtr) const;
    int getNumberOfNodesHelper(BinaryNode<T>* subTreePtr) const;

    // Recursively deletes all nodes from the tree.
    void destroyTree(BinaryNode<T>* subTreePtr);

    // Recursively adds a new node to the tree in a left/right fashion to
    // keep the tree balanced.
    BinaryNode<T>* balancedAdd(BinaryNode<T>* subTreePtr, BinaryNode<T>* newNodePtr);

    // Removes the target value from the tree by calling moveValuesUpTree // to overwrite value with value from child.
    BinaryNode<T>* removeValue(BinaryNode<T>* subTreePtr, const T target, bool& success);
    
    // Copies values up the tree to overwrite value in current node until
    // a leaf is reached; the leaf is then removed, since its value is
    // stored in the parent.
    BinaryNode<T>* moveValuesUpTree(BinaryNode<T>* subTreePtr);

    // Recursively searches for target value in the tree by using a // preorder traversal.
    BinaryNode<T>* findNode(BinaryNode<T>* treePtr, const T& target, bool& success) const;
    
    // Copies the tree rooted at treePtr and returns a pointer to // the copy.
    BinaryNode<T>* copyTree(const BinaryNode<T>* treePtr) const;
   
    // Recursive traversal helper methods:
    void preorder(void visit(T&), BinaryNode<T>* treePtr) const;
    void inorder(void visit(T&), BinaryNode<T>* treePtr) const;
    void postorder(void visit(T&), BinaryNode<T>* treePtr) const;


  private:
    BinaryNode<T>* rootPtr;
};

#endif