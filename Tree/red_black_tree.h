#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H
#include "binary_search_tree.h"
#include "red_black_node.h"


template <class T>
class RedBlackTree : BinarySearchTree<T>
{

public:
    // Constructors
    RedBlackTree();
    RedBlackTree(const T& rootItem);
    RedBlackTree(const RedBlackTree<T>& tree);
    virtual ~RedBlackTree();

    // Red-Black Tree Operations
    bool add(const T& newEntry);
    bool remove(const T& anEntry);

    // Helper methods for balancing
    void fixInsert(RedBlackNode<T>* node);
    void rotateLeft(RedBlackNode<T>* node);
    void rotateRight(RedBlackNode<T>* node);

protected:
    RedBlackNode<T>* insertInOrder(RedBlackNode<T>* subTreePtr, RedBlackNode<T>* newNode);
    RedBlackNode<T>* removeValue(RedBlackNode<T>* subTreePtr, const T target, bool& success);

private:
    RedBlackNode<T>* rootPtr;  // Root pointer, now using RedBlackNode type
};

#include "red_black_node.cpp"


#endif //RED_BLACK_TREE_H
