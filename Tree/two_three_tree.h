#ifndef TWO_TREE_TREE_H
#define TWO_TREE_TREE_H
#include "binary_search_tree.h"
#include "tri_node.h"


template<class T>
class TwoThreeTree : public BinarySearchTree<T>
{
public:
    TwoThreeTree();
    TwoThreeTree(const T& rootItem);
    TwoThreeTree(const TwoThreeTree<T>& tree);
    virtual ~TwoThreeTree();


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
    TwoThreeTree<T>& operator=(const TwoThreeTree<T>& rightHandSide);
    T Max();

    bool deleteElement(const T& newEntry);


protected:
    // Remove 2-3 helper functions
    TriNode<T>* removeValue(TriNode<T>* subTreePtr, const T target, bool& success, TriNode<T>*& new_child);
    T findSuccessor(TriNode<T>* subTreePtr);
    TriNode<T>* balanceAfterRemoval(TriNode<T>* nodePtr, TriNode<T>*& new_child);
    int get_balance(BinaryNode<T>* sub_root);


    // other helper functions
    TriNode<T>* findNode(TriNode<T>* treePtr, const T& target) const;
    TriNode<T>* Max_helper(TriNode<T>* treePtr);
    int get_height_helper(TriNode<T>* subTreePtr);
    void getNumberOfNodesHelper(TriNode<T>* subTreePtr, int& total) const;

    // 2-3 Tree Traversal helper functions
    void preorder(void visit(T&), TriNode<T>* subTreePtr) const;
    void inorder(void visit(T&), TriNode<T>* subTreePtr) const;
    void postorder(void visit(T&), TriNode<T>* subTreePtr) const;

    // Insert 2-3 helper methods
    TriNode<T>* insertIntoNode(TriNode<T>* nodePtr, const T& newItem, TriNode<T>*& newChildPtr, T& medianValue);
    void splitNode(TriNode<T>* nodePtr, const T& newItem, TriNode<T>* newChildPtr, T& medianValue, TriNode<T>*& rightHalf);
    TriNode<T>* findParent(TriNode<T>* root, TriNode<T>* child);

    // Remove 2-3 helper methods
    // returns the parent where the child has a balance issue
    TriNode<T>* balance_mistake_parent(TriNode<T>* subTreePtr);

    // New implementation
    bool deleteRec(TriNode<T>* current, const T& newEntry);
    T replaceWithMinKey(); // returns the minimum element in the tree



private:
    TriNode<T>* rootPtr;
};

#include "two_three_tree.cpp"

#endif //TWO_TREE_TREE_H
