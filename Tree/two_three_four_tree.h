#ifndef TWO_THREE_FOUR_TREE_H
#define TWO_THREE_FOUR_TREE_H
#include "binary_search_tree.h"
#include "quad_node.h"

template<class T>
class TwoThreeFourTree : public BinarySearchTree<T>
{
public:
    TwoThreeFourTree();
    TwoThreeFourTree(const T& rootItem);
    TwoThreeFourTree(const TwoThreeFourTree<T>& tree);
    virtual ~TwoThreeFourTree();


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
    TwoThreeFourTree<T>& operator=(const TwoThreeFourTree<T>& rightHandSide);
    T Max();

protected:
    // Remove 2-3 helper functions
    QuadNode<T>* removeValue(QuadNode<T>* subTreePtr, const T target, bool& success, QuadNode<T>*& new_child);
    T findSuccessor(QuadNode<T>* subTreePtr);
    QuadNode<T>* balanceAfterRemoval(QuadNode<T>* nodePtr, QuadNode<T>*& new_child);
    int get_balance(BinaryNode<T>* sub_root);


    // other helper functions
    QuadNode<T>* findNode(QuadNode<T>* treePtr, const T& target) const;
    QuadNode<T>* Max_helper(QuadNode<T>* treePtr);
    int get_height_helper(QuadNode<T>* subTreePtr);
    void getNumberOfNodesHelper(QuadNode<T>* subTreePtr, int& total) const;

    // 2-3 Tree Traversal helper functions
    void preorder(void visit(T&), QuadNode<T>* subTreePtr) const;
    void inorder(void visit(T&), QuadNode<T>* subTreePtr) const;
    void postorder(void visit(T&), QuadNode<T>* subTreePtr) const;

    // Insert 2-3-4 helper methods
    QuadNode<T>* insertIntoNode(QuadNode<T>* nodePtr, const T& newItem, QuadNode<T>*& newChildPtr, T& medianValue);
    void splitNode(QuadNode<T>* nodePtr, const T& newItem, QuadNode<T>* newChildPtr, T& medianValue, QuadNode<T>*& rightHalf);
    QuadNode<T>* findParent(QuadNode<T>* root, QuadNode<T>* child);

    // Remove 2-3-4 helper methods
    // returns the parent where the child has a balance issue
    QuadNode<T>* balance_mistake_parent(QuadNode<T>* subTreePtr);

private:
    QuadNode<T>* rootPtr;
};

#include "two_three_four_tree.cpp"


#endif //TWO_THREE_FOUR_TREE_H
