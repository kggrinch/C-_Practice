#ifndef AVL_TREE_H
#define AVL_TREE_H
#include "binary_search_tree.h"
#include "binary_tree.h"

// Currently this AVL tree is not optimized as the insertion and remove takes O(n) because the nodes heights are not tracked.
//


template<class T>
class AVL_Tree : public BinarySearchTree<T>
{
public:
    AVL_Tree();
    AVL_Tree(const T& rootItem);
    AVL_Tree(const AVL_Tree<T>& tree);
    virtual ~AVL_Tree();


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

    // Traversals
    void preorderTraverse(void visit(T&)) const;
    void inorderTraverse(void visit(T&)) const;
    void postorderTraverse(void visit(T&)) const;
    // operator overloading
    AVL_Tree<T>& operator=(const AVL_Tree<T>& rightHandSide);
    T Max();



protected:
    // This inserts in correct bst order
    BinaryNode<T>* insertInorder(BinaryNode<T>* subTreePtr, BinaryNode<T>* newNode);

    // Remove helper functions
    BinaryNode<T>* removeValue(BinaryNode<T>* subTreePtr, const T target, bool& success);
    BinaryNode<T>* removeNode(BinaryNode<T>* nodePtr);
    BinaryNode<T>* removeInorderSuccessor(BinaryNode<T>* subTreePtr, T& inorderSuccessor);

    // other helper functions
    BinaryNode<T>* findNode(BinaryNode<T>* treePtr, const T& target) const;
    BinaryNode<T>* Max_helper(BinaryNode<T>* treePtr);

    // AVL tree protected balance helper function
    BinaryNode<T>* rotate_left(BinaryNode<T>* subTreePtr);
    BinaryNode<T>* rotate_right(BinaryNode<T>* subTreePtr);
    BinaryNode<T>* balance(BinaryNode<T>* subTreePtr);
    int get_balance(BinaryNode<T>* sub_root);


private:
   BinaryNode<T>* rootPtr;

};

#include "avl_tree.cpp"

#endif //AVL_TREE_H
