#ifndef AVL_TREE_CPP
#define AVL_TREE_CPP
#include "avl_tree.h"

template<class T>
AVL_Tree<T>::AVL_Tree() : rootPtr(nullptr)
{

}

template<class T>
AVL_Tree<T>::AVL_Tree(const T& rootItem) : rootPtr(nullptr)
{
    rootPtr = new BinaryNode<T>(rootItem);
}

template<class T>
AVL_Tree<T>::AVL_Tree(const AVL_Tree<T>& tree) : rootPtr(nullptr)
{
    rootPtr = tree.rootPtr ? BinaryTree<T>::copyTree(tree.rootPtr) : nullptr;
}

template<class T>
AVL_Tree<T>::~AVL_Tree()
{
    clear();
}

template<class T>
bool AVL_Tree<T>::isEmpty() const
{
    return rootPtr == nullptr;
}

template<class T>
int AVL_Tree<T>::getHeight() const
{
     return BinaryTree<T>::getHeightHelper(rootPtr);
}

template<class T>
int AVL_Tree<T>::getNumberOfNodes() const
{
    return BinaryTree<T>::getNumberOfNodesHelper(rootPtr);
}

template<class T>
T AVL_Tree<T>::getRootData() const
{
    if (isEmpty()) throw std::runtime_error("Tree is empty"); // Might not need
    return rootPtr->getItem();
}

// Might not need in AVL
template<class T>
void AVL_Tree<T>::setRootData(const T& newData) const
{
    if (rootPtr) rootPtr->setItem(newData);
}

// @TimeComplexity: O(n) - due to the balance function
template<class T>
bool AVL_Tree<T>::add(const T& newEntry)
{
    // Check for duplicates
    if(findNode(rootPtr, newEntry) != nullptr) return false;

    // Allocate memory for new node
    BinaryNode<T>* new_node = new BinaryNode<T>(newEntry);

    // Insert the new node into the correct order. InserNode calls balance on new node and move upward
    rootPtr = insertInorder(rootPtr, new_node);

    return true;
}

template<class T>
bool AVL_Tree<T>::remove(const T& anEntry)
{
    bool success = false;
    rootPtr = removeValue(rootPtr, anEntry, success);

    return success;
}

template<class T>
void AVL_Tree<T>::clear()
{
    BinaryTree<T>::destroyTree(rootPtr);
    rootPtr = nullptr;
}

template<class T>
T AVL_Tree<T>::getEntry(const T& anEntry) const
{
    BinaryNode<T>* node = findNode(rootPtr, anEntry);
    if (!node) throw std::runtime_error("Entry not found");
    return node->getItem();
}

template<class T>
bool AVL_Tree<T>::contains(const T& anEntry) const
{
    return findNode(rootPtr, anEntry) != nullptr;
}


template<class T>
void AVL_Tree<T>::preorderTraverse(void visit(T&)) const
{
    BinaryTree<T>::preorder(visit, rootPtr);
}

template<class T>
void AVL_Tree<T>::inorderTraverse(void visit(T&)) const
{
    BinaryTree<T>::inorder(visit, rootPtr);
}

template<class T>
void AVL_Tree<T>::postorderTraverse(void visit(T&)) const
{
    BinaryTree<T>::postorder(visit, rootPtr);
}

template<class T>
AVL_Tree<T>& AVL_Tree<T>::operator=(const AVL_Tree<T>& rightHandSide)
{
    if (this != &rightHandSide) {
        clear();
        rootPtr = rightHandSide.rootPtr ? new BinaryNode<T>(*rightHandSide.rootPtr) : nullptr;
    }
    return *this;
}

template<class T>
T AVL_Tree<T>::Max()
{
    return Max_helper(rootPtr)->getItem();
}

// Protected functions

// Time Complexity: O(log n) - balanced tree
template<class T>
BinaryNode<T>* AVL_Tree<T>::insertInorder(BinaryNode<T>* subTreePtr, BinaryNode<T>* newNode)
{
    if(subTreePtr == nullptr) return newNode;

    if(newNode->getItem() < subTreePtr->getItem())
    {
        subTreePtr->setLeftChildPtr(insertInorder(subTreePtr->getLeftChildPtr(), newNode));
    }
    else
    {
        subTreePtr->setRightChildPtr(insertInorder(subTreePtr->getRightChildPtr(), newNode));
    }

    return balance(subTreePtr); // balance from the new node and go upwards
}

template<class T>
BinaryNode<T>* AVL_Tree<T>::removeValue(BinaryNode<T>* subTreePtr, const T target, bool& success)
{
    // target not found
    if (!subTreePtr) return nullptr;

    // Go left
    if (target < subTreePtr->getItem())
    {
        subTreePtr->setLeftChildPtr(removeValue(subTreePtr->getLeftChildPtr(), target, success));
    }
    // Go right
    else if (target > subTreePtr->getItem())
    {
        subTreePtr->setRightChildPtr(removeValue(subTreePtr->getRightChildPtr(), target, success));
    }
    // target found
    else
    {
        // Case 1. subTreePtr will become a nullptr if the remove node was a leaf node
        // Case 2. subTreePtr will become the left child of the remove node or the right child of the remove node
        // Case 3. subTreePtr will become the successor and the node where the successor was taken will be deleted
        subTreePtr = removeNode(subTreePtr);
        success = true;
    }
    return balance(subTreePtr);
}

template<class T>
BinaryNode<T>* AVL_Tree<T>::removeNode(BinaryNode<T>* subTreePtr)
{
    // Case 1: if remove node does not have a left child
    if (!subTreePtr->getLeftChildPtr()) // read this like if the nodePtr does not have a left child | If the nodePtr left child is not a real node (nullptr) | If nodePtr left child is a nullptr
    {
        // If no right child either, a nullptr is set to temp.
        BinaryNode<T>* temp = subTreePtr->getRightChildPtr();
        delete subTreePtr;
        subTreePtr = nullptr;
        return temp;
    }
    // Case 2: If remove node does not have a right child
    // Case 1 & 2 both work in the case if remove node does not have children. In that case either case 1 will return a nullptr.
    else if (!subTreePtr->getRightChildPtr())
    {
        BinaryNode<T>* temp = subTreePtr->getLeftChildPtr();
        delete subTreePtr;
        subTreePtr = nullptr;
        return temp;
    }
    // Case 3: If remove node has two children.
    // Replace the remove node with the successor (smallest value from the remove node's right subtree) - default most common approach
    // or the processor (greatest value from the remove node's left subtree)
    else
    {
        // Save the Successor item
        T inorderSuccessor;
        subTreePtr->setRightChildPtr(removeInorderSuccessor(subTreePtr->getRightChildPtr(), inorderSuccessor)); // remove the successor node
        subTreePtr->setItem(inorderSuccessor); // Set the remove_node with the successor item
        return subTreePtr;
    }
}

template<class T>
BinaryNode<T>* AVL_Tree<T>::removeInorderSuccessor(BinaryNode<T>* subTreePtr, T& inorderSuccessor)
{
    // If subTreePtr's left child is a nullptr then subTreePtr is the successor node
    if (!subTreePtr->getLeftChildPtr())
    {
        inorderSuccessor = subTreePtr->getItem(); // save successor item
        BinaryNode<T>* temp = subTreePtr->getRightChildPtr(); // replace the successor node with the right child. If no right child it will be set to nullptr
        delete subTreePtr;
        subTreePtr = nullptr;
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
BinaryNode<T>* AVL_Tree<T>::findNode(BinaryNode<T>* subTreePtr, const T& target) const
{
    if (!subTreePtr) return nullptr;

    if (target == subTreePtr->getItem()) return subTreePtr;
    else if (target < subTreePtr->getItem()) return findNode(subTreePtr->getLeftChildPtr(), target);
    else return findNode(subTreePtr->getRightChildPtr(), target);
}

template<class T>
BinaryNode<T>* AVL_Tree<T>::Max_helper(BinaryNode<T>* subTreePtr)
{
    if(subTreePtr == nullptr)
    {
        return nullptr;
    }
    if(subTreePtr->getRightChildPtr() == nullptr)
    {
        return subTreePtr;
    }
    return Max_helper(subTreePtr->getRightChildPtr());
}

// AVL tree protected balance helper function
// Figure out why each get balance falls into each case why check if > 1 or < -1
// @TimeComplexity: O(n)
template<class T>
BinaryNode<T>* AVL_Tree<T>::balance(BinaryNode<T>* subTreePtr)
{
    // Calculate balance factor of passed in subtree root
    int balance_factor = get_balance(subTreePtr); // O(n)

    // Greater than 1 means that there is an imbalance somewhere on the left side. (heavy on left)
    if(balance_factor > 1)
    {
        // Check if double rotation is needed LR imbalance which means we need a left rotation on left subtree first then a right rotation from root
        // This checks if the right side is heavy from the left subtree position.
        // negative means heavy on right side from left subtree position
        if(get_balance(subTreePtr->getLeftChildPtr()) < 0)
        {
            // Single left rotation (rotation with right child) from left subtree
            subTreePtr->setLeftChildPtr(rotate_left(subTreePtr->getLeftChildPtr())); // LR
        }
        // Single right rotation (rotation with left child) from root
        return rotate_right(subTreePtr); // LL
    }
    // Less than -1 means that there is an imbalance somewhere on the right side. (heavy on right)
    if(balance_factor < -1)
    {
        // Check if double rotation is needed RL imbalance which means we need a right rotation on right subtree first then a left rotation from root
        // This checks if the left side is heavy from the right subtree position.
        // positive means heavy on left side from right subtree position
        if (get_balance(subTreePtr->getRightChildPtr()) > 0)
        {
            // Single right rotation (rotation with left child) from right subtree
            subTreePtr->setRightChildPtr(rotate_right(subTreePtr->getRightChildPtr())); // RL Case
        }
        // Single left rotation (rotation with right child) from root
        return rotate_left(subTreePtr); // RR
    }
    // return the sub root passed in.
    return subTreePtr;
}

// Rotate to left side with rotating with right child
// @TimeComplexity: O(1) - constant
template<class T>
BinaryNode<T>* AVL_Tree<T>::rotate_left(BinaryNode<T>* subTreePtr)
{
    BinaryNode<T>* x = subTreePtr;
    BinaryNode<T>* y = subTreePtr->getRightChildPtr();

    x->setRightChildPtr(y->getLeftChildPtr());
    y->setLeftChildPtr(x);

    return y;
}

// Rotate to right side with rotating with left child
// @TimeComplexity: O(1) - constant
template<class T>
BinaryNode<T>* AVL_Tree<T>::rotate_right(BinaryNode<T>* subTreePtr)
{
    BinaryNode<T>* x = subTreePtr;
    BinaryNode<T>* y = subTreePtr->getLeftChildPtr();

    x->setLeftChildPtr(y->getRightChildPtr());
    y->setRightChildPtr(x);

    return y;
}

/**
 *  isBalanced helper returns the height difference between the left and right child from the passed in root
 * @param subTreePtr
 * @return integer indicating the height difference between the left child and right child
 * @TimeComplexity: O(n) - due to needing to calculate the height. If height is saved of each node time complexity can be reduced
 */
template<class T>
int AVL_Tree<T>::get_balance(BinaryNode<T>* subTreePtr)
{
    // This read like this: If subTreePtr is not a nullptr then return height of left child - height of right child else return 0
    return subTreePtr ? BinaryTree<T>::getHeightHelper(subTreePtr->getLeftChildPtr()) - BinaryTree<T>::getHeightHelper(subTreePtr->getRightChildPtr()) : 0;
}

#endif