#ifndef TWO_TREE_TREE_CPP
#define TWO_TREE_TREE_CPP
#include "two_three_tree.h"

template<class T>
TwoThreeTree<T>::TwoThreeTree() : rootPtr(nullptr)
{

}

template<class T>
TwoThreeTree<T>::TwoThreeTree(const T& rootItem) : rootPtr(rootItem)
{

}

// copy
template<class T>
TwoThreeTree<T>::TwoThreeTree(const TwoThreeTree<T>& tree) : rootPtr(nullptr)
{
    rootPtr = tree.rootPtr ? BinaryTree<T>::copyTree(tree.rootPtr) : nullptr;
}

template<class T>
TwoThreeTree<T>::~TwoThreeTree()
{
    clear();
}


// Methods
template<class T>
bool TwoThreeTree<T>::isEmpty() const
{
    return rootPtr == nullptr;
}

// Different implementation for 2-3 Tree
template<class T>
int TwoThreeTree<T>::getHeight() const
{
    return get_height_helper(rootPtr);
}

// Different implementation for 2-3 Tree
// Returns the number of elements in the tree
template<class T>
int TwoThreeTree<T>::getNumberOfNodes() const
{
    int total = 0;
    getNumberOfNodesHelper(rootPtr, total);
    return total;
}

template<class T>
T TwoThreeTree<T>::getRootData() const
{
    if (isEmpty()) throw std::runtime_error("Tree is empty"); // Might not need
    return rootPtr->getItem();
}

// Different implementation for 2-3 Tree
template<class T>
void TwoThreeTree<T>::setRootData(const T& newData) const
{

}

// Different implementation for 2-3 Tree

// This implementation works but you still need to run tests on left child, middle child, and right child so there arent any pointer issues
template<class T>
bool TwoThreeTree<T>::add(const T& newEntry)
{
    // Check if item already exist
    // if(findNode(rootPtr, newEntry)) return false;
    //
    // // Check if tree is empty
    // if(!rootPtr)
    // {
    //     rootPtr = new TriNode<T>(newEntry);
    //     return true;
    // }
    //
    //
    // // find leaf_node to insert new_node into
    // TriNode<T>* leaf_node = locate_leaf_node(rootPtr, newEntry);
    //
    // // Insert the new_node into the leaf node.
    // // This function checks if the leaf node will become full and if it requires a split.
    // return insertInLeaf(leaf_node, newEntry);


    if (rootPtr == nullptr) {
        // Create a new root
        rootPtr = new TriNode<T>(newEntry);
        return true;
    }

    if(findNode(rootPtr, newEntry)) return false;

    T medianValue;
    TriNode<T>* newRightHalf = nullptr;

    TriNode<T>* result = insertIntoNode(rootPtr, newEntry, newRightHalf, medianValue);

    if (result != nullptr)
    {
        // Create a new root with the median value
        TriNode<T>* newRoot = new TriNode<T>(medianValue);
        newRoot->setLeftChildPtr(result);
        newRoot->setRightChildPtr(newRightHalf); // I think it should be newRoot->setRightChildPtr(newRightHalf); // newRoot->setMidChildPtr(newRightHalf);
        rootPtr = newRoot;
    }

    return true;

}

template<class T>
TriNode<T>* TwoThreeTree<T>::insertIntoNode(TriNode<T>* nodePtr, const T& newItem, TriNode<T>*& newChildPtr, T& medianValue)
{
    if (nodePtr->isLeaf())
    {
        if (nodePtr->isTwoNode())
        {
            // Simple case: insert directly into a two-node leaf
            if (newItem < nodePtr->getSmallItem())
            {
                nodePtr->setLargeItem(nodePtr->getSmallItem());
                nodePtr->setSmallItem(newItem);
            }
            else
            {
                nodePtr->setLargeItem(newItem);
            }
            return nullptr; // No splitting needed
        }
        else
        {
            // Need to split this leaf node
            splitNode(nodePtr, newItem, nullptr, medianValue, newChildPtr);
            return nodePtr; // Return the original node (left half)
        }
    }
    else
    {
        // Internal node
        TriNode<T>* nextPtr;
        TriNode<T>* returnedNode = nullptr;

        if (newItem < nodePtr->getSmallItem())
        {
            // Go left
            nextPtr = nodePtr->getLeftChildPtr();
        }
        else if (nodePtr->isTwoNode() || newItem > nodePtr->getLargeItem())
        {
            // Go right
            nextPtr = nodePtr->getRightChildPtr();
        }
        else
        {
            // Go middle
            nextPtr = nodePtr->getMidChildPtr();
        }

        T childMedianValue;
        TriNode<T>* newRightChild = nullptr;
        returnedNode = insertIntoNode(nextPtr, newItem, newRightChild, childMedianValue);

        if (returnedNode == nullptr)
        {
            return nullptr; // No split occurred below
        }

        // A split occurred below, handle the promoted item
        if (nodePtr->isTwoNode())
        {
            // Can insert into this node without splitting
            if (childMedianValue < nodePtr->getSmallItem()) {
                nodePtr->setLargeItem(nodePtr->getSmallItem());
                nodePtr->setSmallItem(childMedianValue);
                nodePtr->setRightChildPtr(nodePtr->getRightChildPtr()); // nodePtr->setRightChildPtr(nodePtr->getMidChildPtr());
                nodePtr->setMidChildPtr(newRightChild);
            }
            else
            {
                nodePtr->setLargeItem(childMedianValue);
                nodePtr->setRightChildPtr(newRightChild);
                nodePtr->setMidChildPtr(returnedNode);
            }
            return nullptr; // No further splitting needed
        }
        else
        {
            // Need to split this node too
            splitNode(nodePtr, childMedianValue, newRightChild, medianValue, newChildPtr);
            return nodePtr; // Return the original node (left half)
        }
    }
}


template<class T>
void TwoThreeTree<T>::splitNode(TriNode<T>* nodePtr, const T& newItem, TriNode<T>* newChildPtr, T& medianValue, TriNode<T>*& rightHalf)
{
    // Create a new node for the right half
    rightHalf = new TriNode<T>();

    // Determine the median item and arrange items
    if (newItem < nodePtr->getSmallItem())
    {
        // newItem, smallItem, largeItem
        medianValue = nodePtr->getSmallItem();
        rightHalf->setSmallItem(nodePtr->getLargeItem());
        nodePtr->setSmallItem(newItem);

        if (!nodePtr->isLeaf())
        {
            rightHalf->setLeftChildPtr(nodePtr->getMidChildPtr());
            rightHalf->setRightChildPtr(nodePtr->getRightChildPtr()); // Change this to rightHalf->setRightChildPtr(nodePtr->getRightChildPtr()); // rightHalf->setMidChildPtr(nodePtr->getRightChildPtr());
            nodePtr->setRightChildPtr(newChildPtr); // Add these two lines of code and comment out the one on top // nodePtr->setMidChildPtr(newChildPtr);
        }
    }
    else if (newItem < nodePtr->getLargeItem())
    {
        // smallItem, newItem, largeItem
        medianValue = newItem;
        rightHalf->setSmallItem(nodePtr->getLargeItem());

        if (!nodePtr->isLeaf())
        {
            rightHalf->setLeftChildPtr(newChildPtr);
            rightHalf->setRightChildPtr(nodePtr->getRightChildPtr()); // rightHalf->setMidChildPtr(nodePtr->getRightChildPtr());
            nodePtr->setRightChildPtr(nodePtr->getMidChildPtr()); // Guess
        }
    }
    else
    {
        // smallItem, largeItem, newItem
        medianValue = nodePtr->getLargeItem();
        rightHalf->setSmallItem(newItem);

        if (!nodePtr->isLeaf())
        {
            rightHalf->setLeftChildPtr(nodePtr->getRightChildPtr());
            rightHalf->setRightChildPtr(newChildPtr); // Change this to setRightChildPtr // rightHalf->setMidChildPtr(newChildPtr);

            // adding this to update the left childs right child
            nodePtr->setRightChildPtr(nodePtr->getMidChildPtr());
        }
    }

    // Reset the original node to be a two-node
    nodePtr->setLargeItem(T());
    nodePtr->setMidChildPtr(nullptr); // Set middle child to nullptr. // nodePtr->setRightChildPtr(nullptr);
}

// New Delete implementation
template<class T>
bool TwoThreeTree<T>::deleteElement(const T& newEntry)
{
    bool deleted = false;

    deleted = deleteRec(rootPtr, newEntry);

    if(rootPtr->getLeftChildPtr() == nullptr) rootPtr = nullptr;

    return deleted;
}

template<class T>
bool TwoThreeTree<T>::deleteRec(TriNode<T>* current, const T& newEntry)
{
    bool deleted = true;

    if(current == nullptr)
    {
        deleted = false;
    }
    else
    {
        // Recursive case, we are still finding the element to delete
        if(current->getSmallItem() != newEntry)
        {
            // If there is no element in the right (2 Node) or the element to delete is less than the right element
            if(current->isThreeNode() && current->getLargeItem() > newEntry)
            {
                // The left element is bigger than the element to delete, so we go through the left child
                if(current->getSmallItem() > newEntry)
                {
                    deleted = deleteRec(current->getLeftChildPtr(), newEntry);
                }
                else
                { // If not, we go through the mid child
                    deleted = deleteRec(current->getMidChildPtr(), newEntry);
                }
            }
            else
            {
                // If the element to delete does not equals the right element, we go through the right child
                if(current->getLargeItem() != newEntry)
                {
                    deleted = deleteRec(current->getRightChildPtr(), newEntry);
                }
                else
                {
                    // If not, we have found the element
                    // Situation A, the element equals the right element of a leaf so we just have to delete it
                    if(current->isLeaf())
                    {
                        current->setLargeItem(newEntry);
                    }
                    else
                    { // We found the element but it is not in the leaf, this is the situation B
                        // We get the min element of the right branch, remove it from its current position and put it
                        // where we found the element to delete
                        T replacement = current->getRightChildPtr()->replaceWithMinKey();
                        current->setLargeItem(replacement);;
                    }
                }
            }
        }
        else
        {
            if(current->isLeaf())
            { // Situation A
                // The left element, the element to remove, is replaced by the right element
                if(current->isThreeNode())
                {
                    current->setSmallItem(current->getLargeItem());
                    current->setLargeItem(T());
                }
                else
                { // If there is no element in the right, a rebalance will be necessary
                    current->setSmallItem(T());
                    // We let the node empty
                    // We warn on the bottom up that a node has been deleted (is empty) and a rebalance is necessary
                    // in THAT level of the tree
                    return true;
                }
            }
            else
            { // Situation B
                // We move the max element of the left branch where we have found the element
                // T replacement = current->getLeftChildPtr()->replaceWithMaxKey();
                T replacement = findSuccessor(current);
                current->setSmallItem(replacement);
            }
        }
    }

    if(current != nullptr && !current->isBalanced())
    {
        current->rebalance();  // The bottom level have to be rebalanced
    }
    else if(current != nullptr && !current->isLeaf())
    {
        bool balanced = false;
        while(!balanced)
        {
            if(current->getRightChildPtr() == nullptr)
            {
                // Critical case of the situation B at the left child
                if(current->getLeftChildPtr()->isLeaf() && !current->getMidChildPtr()->isLeaf())
                {
                    T replacement = current->getMidChildPtr()->replaceWithMinKey();
                    T readdition = current->getSmallItem();
                    current->setSmallItem(replacement);
                    add(readdition); // Might not work
                    // insert(readdition);
                    // Critical case of hte situation B at the right child
                }
                else if(!current->getLeftChildPtr()->isLeaf() && current->getMidChildPtr()->isLeaf())
                {
                    if(current->isTwoNode())
                    {
                        T replacement = current->getLeftChildPtr()->replaceWithMaxKey();
                        T readdition = current->getSmallItem();
                        current->setSmallItem(replacement);
                        add(readdition);
                        // insert(readdition);
                    }
                }
            }
            if(current->getRightChildPtr() != nullptr)
            {
                if(current->isThreeNode() && current->getMidChildPtr()->isLeaf() && !current->getRightChildPtr()->isLeaf())
                {
                    current->getRightChildPtr()->rebalance();
                }
                if(current->isThreeNode() && current->getMidChildPtr()->isLeaf() && !current->getRightChildPtr()->isLeaf())
                {
                    T replacement = current->getRightChildPtr()->replaceWithMinKey();
                    T readdition = current->getLargeItem();
                    current->setLargeItem(replacement);
                    add(readdition);
                    // insert(readdition);
                }
                else balanced = true;
            }
            if(current->isBalanced()) balanced = true;
        }

    }
    return deleted;

}















// My implementation
// Different implementation for 2-3 Tree
template<class T>
bool TwoThreeTree<T>::remove(const T& anEntry)
{
    bool isSuccessful = false;
    TriNode<T>* merged_child = nullptr;
    if(rootPtr == nullptr || !findNode(rootPtr, anEntry)) return isSuccessful;

    TriNode<T>* result = removeValue(rootPtr, anEntry, isSuccessful, merged_child);

    if(result != rootPtr)
    {
        // Create a new root
        TriNode<T>* new_root = result;
        rootPtr = new_root;
        return true;
    }

    return true;


    rootPtr = removeValue(rootPtr, anEntry, isSuccessful, merged_child);
    return isSuccessful;
}

// Remove helper functions
template<class T>
TriNode<T>* TwoThreeTree<T>::removeValue(TriNode<T>* subTreePtr, const T target, bool& success, TriNode<T>*& new_child)
{
    if(subTreePtr == nullptr)
    {
        success = false;
        return nullptr;
    }

    bool isTarget = false;
    bool inSmallItem = false;
    bool inThreeNode = false;

    // Check if target is in current node
    if (target == subTreePtr->getSmallItem())
    {
        isTarget = true;
        inSmallItem = true;
        if(subTreePtr->isThreeNode()) inThreeNode = true;
    }
    else if (subTreePtr->isThreeNode() && target == subTreePtr->getLargeItem())
    {
        isTarget = true;
        inSmallItem = false;
        inThreeNode = true;
    }

    // Target found in current node
    if (isTarget)
    {
        success = true;

        // Case 1: Leaf node
        if (subTreePtr->isLeaf())
        {
            if (subTreePtr->isThreeNode())
            {
                // If three-node leaf, just remove the item and convert to two-node
                if (inSmallItem)
                {
                    subTreePtr->setSmallItem(subTreePtr->getLargeItem());
                    subTreePtr->setLargeItem(T());
                }
                else
                {
                    subTreePtr->setLargeItem(T());
                }
                return subTreePtr;
            }
            else
            {
                // If two-node leaf, remove the node
                delete subTreePtr;
                subTreePtr = nullptr;
                return nullptr;
            }
        }
        // Case 2: Internal node
        else
        {
            // Replace with inorder successor and then remove it
            T successor;

            // Might have issue here. If small item does not right away mean that it is a three node so traversing to the middle child might cause issues if the small item was found in a two node
            // To fix add a bool to check if the item was found in a two node or three node. If two node then find success from the right child.
            // If three node then if small item find success from the middle. If large item find successor from the right
            if (inSmallItem)
            {
                if(inThreeNode)
                {
                    // Find successor for small item (smallest value in middle subtree since the target was found in a three node)
                    successor = findSuccessor(subTreePtr->getMidChildPtr());
                    subTreePtr->setSmallItem(successor);
                    subTreePtr->setMidChildPtr(removeValue(subTreePtr->getMidChildPtr(), successor, success, new_child));
                }
                else
                {
                    // Find successor for the samll item (smallest value in the right subtree since the target was found in a two node)
                    successor = findSuccessor(subTreePtr->getRightChildPtr());
                    subTreePtr->setSmallItem(successor);
                    subTreePtr->setRightChildPtr(removeValue(subTreePtr->getRightChildPtr(), successor, success, new_child)); // Not sure about this // subTreePtr->setMidChildPtr(removeValue(subTreePtr->getMidChildPtr(), successor, success));
                }
            }
            else
            {
                // Find successor for large item (smallest value in right subtree)
                successor = findSuccessor(subTreePtr->getRightChildPtr());
                subTreePtr->setLargeItem(successor);
                subTreePtr->setRightChildPtr(removeValue(subTreePtr->getRightChildPtr(), successor, success, new_child));
            }

            // Check for underflow and rebalance if needed
            return balanceAfterRemoval(subTreePtr, new_child);
        }
    }
    // Target not in current node, recurse through children
    else
    {
        if (target < subTreePtr->getSmallItem())
        {
            // Search in left subtree
            subTreePtr->setLeftChildPtr(removeValue(subTreePtr->getLeftChildPtr(), target, success, new_child));
        }
        else if (subTreePtr->isThreeNode() && target < subTreePtr->getLargeItem())
        {
            // Search in middle subtree
            subTreePtr->setMidChildPtr(removeValue(subTreePtr->getMidChildPtr(), target, success, new_child));
        }
        else
        {
            // Search in right subtree
            subTreePtr->setRightChildPtr(removeValue(subTreePtr->getRightChildPtr(), target, success, new_child));
        }

        // Check for underflow and rebalance if needed
        return balanceAfterRemoval(subTreePtr, new_child); // This should return the root or the new root
    }
}

template<class T>
T TwoThreeTree<T>::findSuccessor(TriNode<T>* subTreePtr)
{
    // Find the leftmost (smallest) item in the subtree
    if (subTreePtr->getLeftChildPtr() == nullptr)
    {
        return subTreePtr->getSmallItem();
    }
    else
    {
        return findSuccessor(subTreePtr->getLeftChildPtr());
    }
}

template<class T>
TriNode<T>* TwoThreeTree<T>::balanceAfterRemoval(TriNode<T>* nodePtr, TriNode<T>*& new_child)
{

    if (nodePtr == nullptr) return nullptr;

    if(nodePtr->isLeaf()) return nodePtr;

    TriNode<T>* parent = balance_mistake_parent(nodePtr);

    // Check if there is a balance issue from the nodePtr
    if(parent != nullptr)
    {
        // Left child is null - underflow in left subtree
        if (parent->getLeftChildPtr() == nullptr || parent->getLeftChildPtr() == new_child)
        {
            if(parent->isThreeNode())
            {
                TriNode<T>* middleChild = parent->getMidChildPtr();
                if(middleChild->isThreeNode()) // parent will stay a three node.
                {
                    // Will require some left rotations with parent small item and middle small item
                    TriNode<T>* leftChild = new TriNode<T>(parent->getSmallItem());
                    parent->setSmallItem(middleChild->getSmallItem());
                    middleChild->setSmallItem(middleChild->getLargeItem());
                    middleChild->setLargeItem(T());
                    parent->setLeftChildPtr(leftChild);
                }
                else // parent will become a two node
                {
                    TriNode<T>* leftChild = middleChild;
                    leftChild->setLargeItem(leftChild->getSmallItem());
                    leftChild->setSmallItem(parent->getSmallItem());
                    parent->setSmallItem(parent->getLargeItem());
                    parent->setLargeItem(T());
                    parent->setLeftChildPtr(leftChild);
                    parent->setMidChildPtr(nullptr);
                }
                return parent;
            }
            // Parent is a two node does not have a middle child
            else
            {
                TriNode<T>* rightChild = parent->getRightChildPtr();
                // If right child is a three node redistribution is required
                if(rightChild->isThreeNode())
                {
                    TriNode<T>* newLeft = new TriNode<T>(parent->getSmallItem());
                    parent->setSmallItem(rightChild->getSmallItem());
                    rightChild->setSmallItem(rightChild->getLargeItem());
                    rightChild->setLargeItem(T());

                    // THis now merges and connects all the subroots. It might not be prefect so there can be issues
                    parent->setLeftChildPtr(newLeft);
                    newLeft->setLeftChildPtr(new_child); // Might need to change this because you want to inhert the children that were left
                    newLeft->setRightChildPtr(rightChild->getLeftChildPtr());
                    rightChild->setLeftChildPtr(rightChild->getMidChildPtr());
                    rightChild->setRightChildPtr(rightChild->getRightChildPtr());
                    rightChild->setMidChildPtr(nullptr);
                    return parent;
                }
                // merging is required and passing up c
                else
                {
                    rightChild->setLargeItem(rightChild->getSmallItem());
                    rightChild->setSmallItem(parent->getSmallItem());

                    // If parent is a three-node
                    if (parent->isThreeNode())
                    {
                        nodePtr->setSmallItem(nodePtr->getLargeItem());
                        nodePtr->setLargeItem(T());
                        nodePtr->setLeftChildPtr(rightChild);
                        nodePtr->setMidChildPtr(nodePtr->getRightChildPtr());
                        nodePtr->setRightChildPtr(nullptr);
                    }
                    else
                    {
                        // If parent is a two-node, return the merged child
                        TriNode<T>* temp = rightChild;
                        delete nodePtr;
                        nodePtr = nullptr;
                        return temp;
                    }
                }
            }
        }
        // Right child is null underflow in right subtree
        else if (parent->getRightChildPtr() == nullptr || parent->getRightChildPtr() == new_child) // change to parent->getRightChildPtr
        {
            // If parent is a three node
            if(parent->isThreeNode())
            {
                TriNode<T>* middleChild = parent->getMidChildPtr();
                if(middleChild->isThreeNode()) // parent stays a three node
                {
                    TriNode<T>* rightChild = new TriNode<T>(parent->getLargeItem());
                    parent->setLargeItem(middleChild->getLargeItem());
                    middleChild->setLargeItem(T());
                    parent->setRightChildPtr(rightChild);
                }
                else // parent becomes a two node
                {
                    TriNode<T>* rightChild = middleChild;
                    rightChild->setLargeItem(parent->getLargeItem());
                    parent->setLargeItem(T());
                    parent->setRightChildPtr(rightChild);
                    parent->setMidChildPtr(nullptr);
                }
                return parent;
            }
            // If parent is a two node
            else
            {
                TriNode<T>* leftChild = parent->getLeftChildPtr();
                // If left child is a three-node, redistribute
                if (leftChild->isThreeNode())
                {
                    TriNode<T>* rightChild = new TriNode<T>(parent->getSmallItem());
                    parent->setSmallItem(leftChild->getLargeItem());
                    leftChild->setLargeItem(T());

                    // THis should be setRightChild
                    parent->setRightChildPtr(rightChild);
                    rightChild->setLeftChildPtr(leftChild->getRightChildPtr());
                    rightChild->setRightChildPtr(nullptr);
                    leftChild->setRightChildPtr(nullptr);
                    return parent;
                }
                else // left child is a two node
                {
                    leftChild->setLargeItem(parent->getSmallItem());
                    leftChild->setMidChildPtr(leftChild->getRightChildPtr());
                    leftChild->setRightChildPtr(new_child);

                    delete parent;
                    parent = nullptr;
                    new_child = leftChild;
                    return leftChild;
                }
                // // If left child is a two-node and parent is a three-node
                // else if (nodePtr->isThreeNode())
                // {
                //     TriNode<T>* rightChild = nodePtr->getRightChildPtr();
                //     // If right child is a three-node, redistribute
                //     if (rightChild && rightChild->isThreeNode())
                //     {
                //         TriNode<T>* newMid = new TriNode<T>(nodePtr->getLargeItem());
                //         nodePtr->setLargeItem(rightChild->getSmallItem());
                //         rightChild->setSmallItem(rightChild->getLargeItem());
                //         rightChild->setLargeItem(T());
                //
                //         nodePtr->setMidChildPtr(newMid);
                //         newMid->setLeftChildPtr(nullptr);
                //         newMid->setMidChildPtr(rightChild->getLeftChildPtr());
                //         rightChild->setLeftChildPtr(rightChild->getMidChildPtr());
                //         rightChild->setMidChildPtr(rightChild->getRightChildPtr());
                //         rightChild->setRightChildPtr(nullptr);
                //     }
                //     // If right child is a two-node, merge
                //     else
                //     {
                //         leftChild->setLargeItem(nodePtr->getSmallItem());
                //         nodePtr->setSmallItem(nodePtr->getLargeItem());
                //         nodePtr->setLargeItem(T());
                //
                //         nodePtr->setMidChildPtr(rightChild);
                //         nodePtr->setRightChildPtr(nullptr);
                //     }
            }
            // If parent is a two-node and left child is a two-node, merge
        }
        // Underflow in middle subtree
        else if(parent->isThreeNode() && (parent->getMidChildPtr() == nullptr || parent->getMidChildPtr() == new_child))
        {
            TriNode<T>* leftChild = parent->getLeftChildPtr();
            if(leftChild->isThreeNode())
            {
                // rotation with parent small item and left large item and middle child
                TriNode<T>* midChild = new TriNode<T>(parent->getSmallItem());
                parent->setSmallItem(leftChild->getLargeItem());
                leftChild->setLargeItem(T());
                parent->setMidChildPtr(midChild);
            }
            else
            {
                leftChild->setLargeItem(parent->getSmallItem());
                parent->setSmallItem(parent->getLargeItem());
                parent->setLargeItem(T());
                parent->setMidChildPtr(nullptr);
            }
            return parent;
        }

        // The underflow is lower
        // else
        // {
        //     // Check which side has an underflow
        //     if(parent->isThreeNode()) // parent is a three node distribution required
        //     {
        //
        //
        //     }
        //     else // parent is a two node merging required
        //     {
        //         // We need to get another if statement to check if the opposite side is full or not.
        //         TriNode<T>* new_root = parent->rightChildPtr;
        //         if(parent->leftChildPtr == new_child)
        //         {
        //
        //             new_root->setLargeItem(new_root->getSmallItem());
        //             new_root->setSmallItem(parent->getSmallItem());
        //
        //             new_root->setMidChildPtr(new_root->getLeftChildPtr());
        //             new_root->setLeftChildPtr(new_child);
        //             return new_root;
        //
        //         }
        //         else
        //         {
        //             new_root->setLargeItem(parent->getSmallItem());
        //             new_root->setMidChildPtr(new_root->getRightChildPtr());
        //             new_root->setRightChildPtr(new_child);
        //         }
        //         return new_root;
        //     }
    }
    else
    {
        return nodePtr;
    }




    //
    // if (nodePtr->getLeftChildPtr() == nullptr || nodePtr->getRightChildPtr() == nullptr || (nodePtr->isThreeNode() && nodePtr->getMidChildPtr() == nullptr))
    // {
    //     // Left child is null - underflow in left subtree
    //     if (nodePtr->getLeftChildPtr() == nullptr)
    //     {
    //         TriNode<T>* midChild = nodePtr->getMidChildPtr();
    //
    //         if(midChild == nullptr)
    //         {
    //
    //         }
    //         // If mid child is a three-node, redistribute
    //         else if (midChild->isThreeNode())
    //         {
    //             TriNode<T>* newLeft = new TriNode<T>(nodePtr->getSmallItem());
    //             nodePtr->setSmallItem(midChild->getSmallItem());
    //             midChild->setSmallItem(midChild->getLargeItem());
    //             midChild->setLargeItem(T());
    //
    //             nodePtr->setLeftChildPtr(newLeft);
    //             newLeft->setLeftChildPtr(nullptr);
    //             newLeft->setMidChildPtr(midChild->getLeftChildPtr());
    //             midChild->setLeftChildPtr(midChild->getMidChildPtr());
    //             midChild->setMidChildPtr(midChild->getRightChildPtr());
    //             midChild->setRightChildPtr(nullptr);
    //         }
    //         // If mid child is a two-node, merge
    //         else
    //         {
    //             midChild->setLargeItem(midChild->getSmallItem());
    //             midChild->setSmallItem(nodePtr->getSmallItem());
    //
    //             // If parent is a three-node
    //             if (nodePtr->isThreeNode())
    //             {
    //                 nodePtr->setSmallItem(nodePtr->getLargeItem());
    //                 nodePtr->setLargeItem(T());
    //                 nodePtr->setLeftChildPtr(midChild);
    //                 nodePtr->setMidChildPtr(nodePtr->getRightChildPtr());
    //                 nodePtr->setRightChildPtr(nullptr);
    //             }
    //             else
    //             {
    //                 // If parent is a two-node, return the merged child
    //                 TriNode<T>* temp = midChild;
    //                 delete nodePtr;
    //                 return temp;
    //             }
    //         }
    //     }
    //     // Mid child is null - underflow in mid subtree
    //     else if (nodePtr->getMidChildPtr() == nullptr)
    //     {
    //         TriNode<T>* leftChild = nodePtr->getLeftChildPtr();
    //
    //         // If left child is a three-node, redistribute
    //         if (leftChild->isThreeNode())
    //         {
    //             TriNode<T>* newMid = new TriNode<T>(nodePtr->getSmallItem());
    //             nodePtr->setSmallItem(leftChild->getLargeItem());
    //             leftChild->setLargeItem(T());
    //
    //             nodePtr->setMidChildPtr(newMid);
    //             newMid->setLeftChildPtr(leftChild->getRightChildPtr());
    //             newMid->setMidChildPtr(nullptr);
    //             leftChild->setRightChildPtr(nullptr);
    //         }
    //         // If left child is a two-node and parent is a three-node
    //         else if (nodePtr->isThreeNode())
    //         {
    //             TriNode<T>* rightChild = nodePtr->getRightChildPtr();
    //
    //             // If right child is a three-node, redistribute
    //             if (rightChild && rightChild->isThreeNode())
    //             {
    //                 TriNode<T>* newMid = new TriNode<T>(nodePtr->getLargeItem());
    //                 nodePtr->setLargeItem(rightChild->getSmallItem());
    //                 rightChild->setSmallItem(rightChild->getLargeItem());
    //                 rightChild->setLargeItem(T());
    //
    //                 nodePtr->setMidChildPtr(newMid);
    //                 newMid->setLeftChildPtr(nullptr);
    //                 newMid->setMidChildPtr(rightChild->getLeftChildPtr());
    //                 rightChild->setLeftChildPtr(rightChild->getMidChildPtr());
    //                 rightChild->setMidChildPtr(rightChild->getRightChildPtr());
    //                 rightChild->setRightChildPtr(nullptr);
    //             }
    //             // If right child is a two-node, merge
    //             else
    //             {
    //                 leftChild->setLargeItem(nodePtr->getSmallItem());
    //                 nodePtr->setSmallItem(nodePtr->getLargeItem());
    //                 nodePtr->setLargeItem(T());
    //
    //                 nodePtr->setMidChildPtr(rightChild);
    //                 nodePtr->setRightChildPtr(nullptr);
    //             }
    //         }
    //         // If parent is a two-node and left child is a two-node, merge
    //         else
    //         {
    //             leftChild->setLargeItem(nodePtr->getSmallItem());
    //             delete nodePtr;
    //             return leftChild;
    //         }
    //     }
    //     // Right child is null in a three-node - underflow in right subtree
    //     else if (nodePtr->isThreeNode() && nodePtr->getRightChildPtr() == nullptr)
    //     {
    //         TriNode<T>* midChild = nodePtr->getMidChildPtr();
    //
    //         // If mid child is a three-node, redistribute
    //         if (midChild->isThreeNode())
    //         {
    //             TriNode<T>* newRight = new TriNode<T>(nodePtr->getLargeItem());
    //             nodePtr->setLargeItem(midChild->getLargeItem());
    //             midChild->setLargeItem(T());
    //
    //             nodePtr->setRightChildPtr(newRight);
    //             newRight->setLeftChildPtr(midChild->getRightChildPtr());
    //             midChild->setRightChildPtr(nullptr);
    //         }
    //         // If mid child is a two-node, check left child
    //         else
    //         {
    //             TriNode<T>* leftChild = nodePtr->getLeftChildPtr();
    //
    //             // If left child is a three-node, redistribute
    //             if (leftChild->isThreeNode())
    //             {
    //                 midChild->setLargeItem(midChild->getSmallItem());
    //                 midChild->setSmallItem(nodePtr->getSmallItem());
    //                 nodePtr->setSmallItem(leftChild->getLargeItem());
    //                 leftChild->setLargeItem(T());
    //
    //                 midChild->setRightChildPtr(midChild->getMidChildPtr());
    //                 midChild->setMidChildPtr(midChild->getLeftChildPtr());
    //                 midChild->setLeftChildPtr(leftChild->getRightChildPtr());
    //                 leftChild->setRightChildPtr(nullptr);
    //             }
    //             // If left child is a two-node, merge with mid child
    //             else
    //             {
    //                 leftChild->setLargeItem(nodePtr->getSmallItem());
    //                 nodePtr->setSmallItem(nodePtr->getLargeItem());
    //                 nodePtr->setLargeItem(T());
    //
    //                 leftChild->setRightChildPtr(midChild->getLeftChildPtr());
    //                 delete midChild;
    //                 nodePtr->setMidChildPtr(nodePtr->getRightChildPtr());
    //                 nodePtr->setRightChildPtr(nullptr);
    //             }
    //         }
    //     }
    // }
    // else
    // {
    // }
    //
    // return nodePtr;






    // if (nodePtr == nullptr)
    //     return nullptr;
    //
    // // Check if any child is null (underflow)
    // if (nodePtr->getLeftChildPtr() == nullptr || nodePtr->getRightChildPtr() == nullptr || (nodePtr->isThreeNode() && nodePtr->getMidChildPtr() == nullptr))
    // {
    //     // Left child is null - underflow in left subtree
    //     if (nodePtr->getLeftChildPtr() == nullptr)
    //     {
    //         TriNode<T>* midChild = nodePtr->getMidChildPtr();
    //
    //         if(midChild == nullptr)
    //         {
    //
    //         }
    //         // If mid child is a three-node, redistribute
    //         else if (midChild->isThreeNode())
    //         {
    //             TriNode<T>* newLeft = new TriNode<T>(nodePtr->getSmallItem());
    //             nodePtr->setSmallItem(midChild->getSmallItem());
    //             midChild->setSmallItem(midChild->getLargeItem());
    //             midChild->setLargeItem(T());
    //
    //             nodePtr->setLeftChildPtr(newLeft);
    //             newLeft->setLeftChildPtr(nullptr);
    //             newLeft->setMidChildPtr(midChild->getLeftChildPtr());
    //             midChild->setLeftChildPtr(midChild->getMidChildPtr());
    //             midChild->setMidChildPtr(midChild->getRightChildPtr());
    //             midChild->setRightChildPtr(nullptr);
    //         }
    //         // If mid child is a two-node, merge
    //         else
    //         {
    //             midChild->setLargeItem(midChild->getSmallItem());
    //             midChild->setSmallItem(nodePtr->getSmallItem());
    //
    //             // If parent is a three-node
    //             if (nodePtr->isThreeNode())
    //             {
    //                 nodePtr->setSmallItem(nodePtr->getLargeItem());
    //                 nodePtr->setLargeItem(T());
    //                 nodePtr->setLeftChildPtr(midChild);
    //                 nodePtr->setMidChildPtr(nodePtr->getRightChildPtr());
    //                 nodePtr->setRightChildPtr(nullptr);
    //             }
    //             else
    //             {
    //                 // If parent is a two-node, return the merged child
    //                 TriNode<T>* temp = midChild;
    //                 delete nodePtr;
    //                 return temp;
    //             }
    //         }
    //     }
    //     // Mid child is null - underflow in mid subtree
    //     else if (nodePtr->getMidChildPtr() == nullptr)
    //     {
    //         TriNode<T>* leftChild = nodePtr->getLeftChildPtr();
    //
    //         // If left child is a three-node, redistribute
    //         if (leftChild->isThreeNode())
    //         {
    //             TriNode<T>* newMid = new TriNode<T>(nodePtr->getSmallItem());
    //             nodePtr->setSmallItem(leftChild->getLargeItem());
    //             leftChild->setLargeItem(T());
    //
    //             nodePtr->setMidChildPtr(newMid);
    //             newMid->setLeftChildPtr(leftChild->getRightChildPtr());
    //             newMid->setMidChildPtr(nullptr);
    //             leftChild->setRightChildPtr(nullptr);
    //         }
    //         // If left child is a two-node and parent is a three-node
    //         else if (nodePtr->isThreeNode())
    //         {
    //             TriNode<T>* rightChild = nodePtr->getRightChildPtr();
    //
    //             // If right child is a three-node, redistribute
    //             if (rightChild && rightChild->isThreeNode())
    //             {
    //                 TriNode<T>* newMid = new TriNode<T>(nodePtr->getLargeItem());
    //                 nodePtr->setLargeItem(rightChild->getSmallItem());
    //                 rightChild->setSmallItem(rightChild->getLargeItem());
    //                 rightChild->setLargeItem(T());
    //
    //                 nodePtr->setMidChildPtr(newMid);
    //                 newMid->setLeftChildPtr(nullptr);
    //                 newMid->setMidChildPtr(rightChild->getLeftChildPtr());
    //                 rightChild->setLeftChildPtr(rightChild->getMidChildPtr());
    //                 rightChild->setMidChildPtr(rightChild->getRightChildPtr());
    //                 rightChild->setRightChildPtr(nullptr);
    //             }
    //             // If right child is a two-node, merge
    //             else
    //             {
    //                 leftChild->setLargeItem(nodePtr->getSmallItem());
    //                 nodePtr->setSmallItem(nodePtr->getLargeItem());
    //                 nodePtr->setLargeItem(T());
    //
    //                 nodePtr->setMidChildPtr(rightChild);
    //                 nodePtr->setRightChildPtr(nullptr);
    //             }
    //         }
    //         // If parent is a two-node and left child is a two-node, merge
    //         else
    //         {
    //             leftChild->setLargeItem(nodePtr->getSmallItem());
    //             delete nodePtr;
    //             return leftChild;
    //         }
    //     }
    //     // Right child is null in a three-node - underflow in right subtree
    //     else if (nodePtr->isThreeNode() && nodePtr->getRightChildPtr() == nullptr)
    //     {
    //         TriNode<T>* midChild = nodePtr->getMidChildPtr();
    //
    //         // If mid child is a three-node, redistribute
    //         if (midChild->isThreeNode())
    //         {
    //             TriNode<T>* newRight = new TriNode<T>(nodePtr->getLargeItem());
    //             nodePtr->setLargeItem(midChild->getLargeItem());
    //             midChild->setLargeItem(T());
    //
    //             nodePtr->setRightChildPtr(newRight);
    //             newRight->setLeftChildPtr(midChild->getRightChildPtr());
    //             midChild->setRightChildPtr(nullptr);
    //         }
    //         // If mid child is a two-node, check left child
    //         else
    //         {
    //             TriNode<T>* leftChild = nodePtr->getLeftChildPtr();
    //
    //             // If left child is a three-node, redistribute
    //             if (leftChild->isThreeNode())
    //             {
    //                 midChild->setLargeItem(midChild->getSmallItem());
    //                 midChild->setSmallItem(nodePtr->getSmallItem());
    //                 nodePtr->setSmallItem(leftChild->getLargeItem());
    //                 leftChild->setLargeItem(T());
    //
    //                 midChild->setRightChildPtr(midChild->getMidChildPtr());
    //                 midChild->setMidChildPtr(midChild->getLeftChildPtr());
    //                 midChild->setLeftChildPtr(leftChild->getRightChildPtr());
    //                 leftChild->setRightChildPtr(nullptr);
    //             }
    //             // If left child is a two-node, merge with mid child
    //             else
    //             {
    //                 leftChild->setLargeItem(nodePtr->getSmallItem());
    //                 nodePtr->setSmallItem(nodePtr->getLargeItem());
    //                 nodePtr->setLargeItem(T());
    //
    //                 leftChild->setRightChildPtr(midChild->getLeftChildPtr());
    //                 delete midChild;
    //                 nodePtr->setMidChildPtr(nodePtr->getRightChildPtr());
    //                 nodePtr->setRightChildPtr(nullptr);
    //             }
    //         }
    //     }
    // }
    //
    // return nodePtr;
}

template<class T>
int TwoThreeTree<T>::get_balance(BinaryNode<T>* sub_root)
{
    // This read like this: If subTreePtr is not a nullptr then return height of left child - height of right child else return 0
    return sub_root ? BinaryTree<T>::getHeightHelper(sub_root->getLeftChildPtr()) - BinaryTree<T>::getHeightHelper(sub_root->getRightChildPtr()) : 0;
}

template<class T>
TriNode<T>* TwoThreeTree<T>::balance_mistake_parent(TriNode<T>* subTreePtr)
{
    // if(subTreePtr == nullptr)
    // {
    //     return nullptr;
    // }
    //
    // if(subTreePtr->isTwoNode())
    // {
    //     if((subTreePtr->getLeftChildPtr() == nullptr && subTreePtr->getRightChildPtr() != nullptr) || subTreePtr->getLeftChildPtr() != nullptr && subTreePtr->getRightChildPtr() == nullptr)
    //     {
    //         return subTreePtr;
    //     }
    //     else
    //     {
    //         TriNode<T>* leftCheck = balance_mistake_parent(subTreePtr->getLeftChildPtr());
    //         if (leftCheck != nullptr) return leftCheck;
    //         return balance_mistake_parent(subTreePtr->getRightChildPtr());
    //     }
    // }
    // else
    // {
    //     if((subTreePtr->getLeftChildPtr() == nullptr && subTreePtr->getRightChildPtr() != nullptr && subTreePtr->getMidChildPtr() != nullptr) ||
    //         (subTreePtr->getLeftChildPtr() != nullptr && subTreePtr->getRightChildPtr() == nullptr && subTreePtr->getMidChildPtr() != nullptr) ||
    //         (subTreePtr->getLeftChildPtr() != nullptr && subTreePtr->getRightChildPtr() != nullptr && subTreePtr->getMidChildPtr() == nullptr))
    //     {
    //         return subTreePtr;
    //     }
    //     else
    //     {
    //         // Recursively check the three children for missing subtrees
    //         TriNode<T>* leftCheck = balance_mistake_parent(subTreePtr->getLeftChildPtr());
    //         if (leftCheck != nullptr) return leftCheck;
    //
    //         TriNode<T>* middleCheck = balance_mistake_parent(subTreePtr->getMidChildPtr());
    //         if (middleCheck != nullptr) return middleCheck;
    //
    //         return balance_mistake_parent(subTreePtr->getRightChildPtr());
    //     }
    // }



    if (subTreePtr == nullptr)
        return nullptr;

    // Recursively check the children of this node
    if (!subTreePtr->isLeaf())
    {
        // Check for imbalance in the left child
        TriNode<T>* leftChild = subTreePtr->getLeftChildPtr();
        if (leftChild != nullptr && leftChild->isLeaf() && !leftChild->isBalanced())
        {
            return subTreePtr;
        }

        // Check for imbalance in the middle child (if it exists)
        TriNode<T>* midChild = subTreePtr->getMidChildPtr();
        if (midChild != nullptr && midChild->isLeaf() && !midChild->isBalanced())
        {
            return subTreePtr;
        }

        // Check for imbalance in the right child (if it exists)
        TriNode<T>* rightChild = subTreePtr->getRightChildPtr();
        if (rightChild != nullptr && rightChild->isLeaf() && !rightChild->isBalanced())
        {
            return subTreePtr;
        }
    }

    // If no imbalance found, return nullptr
    return nullptr;



}


// Different implementation for 2-3 Tree
template<class T>
void TwoThreeTree<T>::clear()
{

}

template<class T>
T TwoThreeTree<T>::getEntry(const T& anEntry) const
{
    TriNode<T>* node = findNode(rootPtr, anEntry);
    if (!node) throw std::runtime_error("Entry not found");
    return node->getItem();
}

template<class T>
bool TwoThreeTree<T>::contains(const T& anEntry) const
{
    TriNode<T>* node = findNode(rootPtr, anEntry);
    if (!node) return false;

    return true;
}


// Traversals
template<class T>
void TwoThreeTree<T>::preorderTraverse(void visit(T&)) const
{
    if(rootPtr != nullptr)
    {
        preorder(visit, rootPtr);
    }

}

template<class T>
void TwoThreeTree<T>::inorderTraverse(void visit(T&)) const
{
    if(rootPtr != nullptr)
    {
        inorder(visit, rootPtr);
    }
}

template<class T>
void TwoThreeTree<T>::postorderTraverse(void visit(T&)) const
{
    if(rootPtr != nullptr)
    {
        postorder(visit, rootPtr);
    }
}

// operator overloading
template<class T>
TwoThreeTree<T>& TwoThreeTree<T>::operator=(const TwoThreeTree<T>& rightHandSide)
{

}

template<class T>
T TwoThreeTree<T>::Max()
{

}





// other helper functions
template<class T>
TriNode<T>* TwoThreeTree<T>::findNode(TriNode<T>* treePtr, const T& target) const
{
    // Check if tree is empty
    if(treePtr == nullptr) return nullptr;

    // If root is a two node
    if(treePtr->isTwoNode())
    {
        // Check if root has the target
        if(treePtr->getSmallItem() == target)
        {
            return treePtr;
        }
        // Check if root is leaf
        // If leaf reached the end return nullptr
        else if(treePtr->isLeaf())
        {
            return nullptr;
        }
        // If target is less go left child
        else if(target < treePtr->getSmallItem())
        {
            return findNode(treePtr->getLeftChildPtr(), target);
        }
        // If target is greater go right child
        else
        {
            return findNode(treePtr->getRightChildPtr(), target);
        }
    }
    // If root is a three node
    else
    {
        // Check if root has the target
        if(treePtr->getSmallItem() == target || treePtr->getLargeItem() == target)
        {
            return treePtr;
        }
        // Check if leaf/
        // If leaf the end is reach return nullptr
        if(treePtr->isLeaf())
        {
            return nullptr;
        }
        else if(target < treePtr->getSmallItem())
        {
            return findNode(treePtr->getLeftChildPtr(), target);
        }
        else if(target < treePtr->getLargeItem())
        {
            return findNode(treePtr->getMidChildPtr(), target);
        }
        else
        {
            return findNode(treePtr->getRightChildPtr(), target);
        }
    }
}

template<class T>
TriNode<T>* TwoThreeTree<T>::Max_helper(TriNode<T>* treePtr)
{
    return nullptr;
}


// 2-3 Tree protected helper functions
// template<class T>
// TriNode<T>* TwoThreeTree<T>::splitNode(TriNode<T>* subTreePtr, T& newEntry)
// {
//
//     // Determine order of values
//     T smallest_value, middle_value, largest_value;
//     if(newEntry < subTreePtr->getSmallItem())
//     {
//         smallest_value = newEntry;
//         middle_value = subTreePtr->getSmallItem();
//         largest_value = subTreePtr->getLargeItem();
//     }
//     else if(newEntry > subTreePtr->getLargeItem())
//     {
//         smallest_value = subTreePtr->getSmallItem();
//         middle_value = subTreePtr->getLargeItem();
//         largest_value = newEntry;
//     }
//     else
//     {
//         smallest_value = subTreePtr->getSmallItem();
//         middle_value = newEntry;
//         largest_value = subTreePtr->getLargeItem();
//     }
//
//     // Creating left and right child nodes
//     TriNode<T>* leftChild = new TriNode<T>(smallest_value);
//     TriNode<T>* rightChild = new TriNode<T>(largest_value);
//
//     // If the node being split is an internal node, redistribute children
//     if (!subTreePtr->isLeaf()) {
//         leftChild->setLeftChildPtr(subTreePtr->getLeftChildPtr());
//         leftChild->setRightChildPtr(subTreePtr->getMidChildPtr());
//
//         rightChild->setLeftChildPtr(subTreePtr->getRightChildPtr());
//         rightChild->setRightChildPtr(subTreePtr->getExtraChildPtr());
//     }
//
//     // If splitting at the root, create a new root
//     if (subTreePtr == rootPtr)
//     {
//         TriNode<T>* newRoot = new TriNode<T>(middle_value);
//         newRoot->setLeftChildPtr(leftChild);
//         newRoot->setRightChildPtr(rightChild);
//         rootPtr = newRoot;
//         return newRoot;
//     }
//
//     // Otherwise, promote middle value to the parent
//     TriNode<T>* parent = findParent(rootPtr, subTreePtr);
//
//     if (parent->isTwoNode())
//     {
//         // Parent is a two-node, convert to three-node
//         if (middle_value < parent->getSmallItem())
//         {
//             // Promote middle value and insert into parent
//             parent->setLargeItem(parent->getSmallItem());
//             parent->setSmallItem(middle_value);
//
//             parent->setMidChildPtr(rightChild);
//             parent->setLeftChildPtr(leftChild);
//         }
//         else
//         {
//             // Insert in right position
//             parent->setLargeItem(middle_value);
//             parent->setMidChildPtr(leftChild);
//             parent->setRightChildPtr(rightChild);
//         }
//     }
//     else
//     {
//         // Parent is already a three-node; recursively split the parent
//         return splitNode(parent, middle_value);
//     }
//
//     return parent;



    // Original 2
    // Locate the smallest, middle, and largest values in the subTreePtr
    // T smallest_value, middle_value, largest_value;
    // if(newEntry < subTreePtr->getSmallItem())
    // {
    //     smallest_value = newEntry;
    //     middle_value = subTreePtr->getSmallItem();
    //     largest_value = subTreePtr->getLargeItem();
    // }
    // else if(newEntry > subTreePtr->getLargeItem())
    // {
    //     smallest_value = subTreePtr->getSmallItem();
    //     middle_value = subTreePtr->getLargeItem();
    //     largest_value = newEntry;
    // }
    // else
    // {
    //     smallest_value = subTreePtr->getSmallItem();
    //     middle_value = newEntry;
    //     largest_value = subTreePtr->getLargeItem();
    // }
    //
    // // Create a new right child node
    // // Save new child with the largest value of the subtree
    // // This might be used for the middle child
    // // This might be used as the right child
    // // TriNode<T>* new_child = new TriNode<T>(largest_value);
    // //
    // // // Update subtree
    // // subTreePtr->setSmallItem(smallest_value);
    // // subTreePtr->setLargeItem(T()); // reset large item since its promoted
    //
    // // If split happens at the root
    // if(subTreePtr == rootPtr)
    // {
    //     // Create new root and new right child node
    //     TriNode<T>* new_root = new TriNode<T>(middle_value);
    //     TriNode<T>* right_child = new TriNode<T>(largest_value);
    //     subTreePtr->setSmallItem(smallest_value);
    //     subTreePtr->setLargeItem(T()); // reset large item since its promoted
    //
    //     // set the old sub_tree ptr as the left child. This it meant to hold the smallItem in the subtree root
    //     new_root->setLeftChildPtr(subTreePtr);
    //     new_root->setRightChildPtr(right_child); // set the right child with the newly created child
    //
    //     rootPtr = new_root; // update rootPtr with the new root
    //     return new_root;
    // }
    //
    // // else, promote middle value to the parent
    // TriNode<T>* parent = findParent(rootPtr, subTreePtr);
    // // If parent is a two node (one element in the node)
    // if(parent->isTwoNode())
    // {
    //     // If the middle value is less then the element in the two node
    //     // This means we are promoting from the left subtree
    //     if(middle_value < parent->getSmallItem())
    //     {
    //         TriNode<T>* middle_child = new TriNode<T>(largest_value);
    //         subTreePtr->setSmallItem(smallest_value);
    //         subTreePtr->setLargeItem(T()); // reset large item since its promoted
    //
    //         // set the element in the parent to largeItem
    //         parent->setLargeItem(parent->getSmallItem()); // Set the smallItem as the largeItem (smallItem > middle_value) [middle_value, smallItem]
    //         parent->setSmallItem(middle_value); // Set the middle_value as the smallItem (smallItem > middle_value) [middle_value, smallItem]
    //         parent->setMidChildPtr(middle_child); // Set the newly created right child as the middle child with the largest element from subtree because we are going from left subtree.
    //                                           // Left child will remain sub_tree with no largeItem and right child is not touched. // since its parent is now a three node
    //     }
    //     // If the middle value is greater than the element in the two node
    //     // This means we are promoting form the right subtree
    //     else
    //     {
    //         TriNode<T>* middle_child = new TriNode<T>(smallest_value);
    //         subTreePtr->setSmallItem(subTreePtr->getLargeItem());
    //         subTreePtr->setLargeItem(T());
    //
    //         parent->setLargeItem(middle_value); // Set the large item as the middle value (smallItem < middle_value) [smallItem, middle_value]
    //         parent->setMidChildPtr(middle_child); // set the middle child as the subtree holding the smallest value // since parent is now a three node
    //         parent->setRightChildPtr(subTreePtr); // Set the right child with the new child holding the largest value // since parent is now a three node
    //     }
    // }
    // // If parent is a three node recursively split the parent while promoting the middle child
    // else
    // {
    //
    //     return splitNode(parent, middle_value);
    // }
    //
    // return parent;

    // Original
    // Check if subTreePtr is three node
    // if(subTreePtr->isThreeNode())
    // {
    //     // Locate the smallest, middle, and largest values in the subTreePtr
    //     T smallest_value, middle_value, largest_value;
    //     if(newEntry < subTreePtr->getSmallItem())
    //     {
    //         smallest_value = newEntry;
    //         middle_value = subTreePtr->getSmallItem();
    //         largest_value = subTreePtr->getLargeItem();
    //     }
    //     else if(newEntry > subTreePtr->getLargeItem())
    //     {
    //         smallest_value = subTreePtr->getSmallItem();
    //         middle_value = subTreePtr->getLargeItem();
    //         largest_value = newEntry;
    //     }
    //     else
    //     {
    //         smallest_value = subTreePtr->getSmallItem();
    //         middle_value = newEntry;
    //         largest_value = subTreePtr->getLargeItem();
    //     }
    //
    //
    //     if(subTreePtr == rootPtr)
    //     {
    //         // Create new root and new right child node
    //         TriNode<T>* new_root = new TriNode<T>(middle_value);
    //         TriNode<T>* right_node = new TriNode<T>(largest_value);
    //
    //         // set the old sub_tree ptr as the left child. This it meant to hold the smallItem in the subtree root
    //         new_root->setLeftChildPtr(subTreePtr);
    //         new_root->setRightChildPtr(right_node); // set the right child with the newly created right_node
    //
    //         subTreePtr->setLargeItem(T()); // remove the largeItem from the subtree which is now left child of the new parent
    //         rootPtr = new_root;
    //
    //         return new_root;
    //     }
    //     // If not the main root
    //     else
    //     {
    //         TriNode<T>* parent_node = findParent(rootPtr, subTreePtr);
    //         // Check if parent only has one element
    //         if(parent_node->isTwoNode())
    //         {
    //             if(middle_value < parent_node->getSmallItem())
    //             {
    //                 parent_node->setLargeItem(parent_node->getSmallItem());
    //                 parent_node->setSmallItem(middle_value);
    //
    //             }
    //             else
    //             {
    //                 parent_node->setLargeItem(middle_value);
    //             }
    //
    //             // Create a new node to be the middle child
    //             TriNode<T>* middle_node = new TriNode<T>(largest_value);
    //             subTreePtr->setSmallItem(smallest_value);
    //             subTreePtr->setLargeItem(T());
    //
    //             parent_node->setLeftChildPtr(subTreePtr); // set the left child of the parent node
    //             parent_node->setMidChildPtr(middle_node); // set the right child of the parent node
    //             subTreePtr->setLargeItem(T()); // remove the largeItem from the subtree which is now left child of the new parent
    //         }
    //         else
    //         {
    //
    //             return splitNode(parent_node, middle_value);
    //         }
    //     }
    // }






    // Some other implementation
    // if(subTreePtr->isThreeNode())
    // {
    //     T smallest_value, middle_value, largest_value;
    //     if(newEntry < subTreePtr->getSmallItem())
    //     {
    //         smallest_value = newEntry;
    //         middle_value = subTreePtr->getSmallItem();
    //         largest_value = subTreePtr->getLargeItem();
    //     }
    //     else if(newEntry > subTreePtr->getLargeItem())
    //     {
    //         smallest_value = subTreePtr->getSmallItem();
    //         middle_value = subTreePtr->getLargeItem();
    //         largest_value = newEntry;
    //     }
    //     else
    //     {
    //         smallest_value = subTreePtr->getSmallItem();
    //         middle_value = newEntry;
    //         largest_value = subTreePtr->getLargeItem();
    //     }
    //
    //     TriNode<T>* new_node = new TriNode<T>(largest_value);
    //     new_node->setMidChildPtr(subTreePtr->getMidChildPtr());
    //     new_node->setRightChildPtr(subTreePtr->getRightChildPtr());
    //
    //     subTreePtr->setLargeItem(subTreePtr->getSmallItem());
    //     subTreePtr->setLeftChildPtr(subTreePtr->getLeftChildPtr());
    //
    //     subTreePtr->setRightChildPtr(nullptr);
    //
    //     TriNode<T>* parent_node = findParent(rootPtr, subTreePtr);
    // }
    // }


// Must send the root of the tree for root.
template<class T>
TriNode<T>* TwoThreeTree<T>::findParent(TriNode<T>* root, TriNode<T>* child)
{
    // If child is nullptr can be any of the leaf node so return nullptr
    if (!child || root == child) return nullptr;
    if(root->getLeftChildPtr() == child || root->getMidChildPtr() || root->getRightChildPtr()) return root;

    if(child->getSmallItem() < root->getSmallItem())
    {
        return findParent(root->getLeftChildPtr(), child);
    }
    else if(child->getSmallItem() > root->getLargeItem() || root->isTwoNode())
    {
        return findParent(root->getRightChildPtr(), child);
    }
    else
    {
        return findParent(root->getMidChildPtr(), child);
    }
}

template<class T>
int TwoThreeTree<T>::get_height_helper(TriNode<T>* subTreePtr)
{
    if(!subTreePtr) return 0;

    return 1 + std::max(getHeightHelper(subTreePtr->getLeftChildPtr()), getHeightHelper(subTreePtr->getMidChildPtr()),getHeightHelper(subTreePtr->getRightChildPtr()));
}

template<class T>
void TwoThreeTree<T>::getNumberOfNodesHelper(TriNode<T>* subTreePtr, int& total) const
{
    if(subTreePtr->isLeaf())
    {
        total++;
    }
    else if(subTreePtr->isThreeNode())
    {
        getNumberOfNodesHelper(subTreePtr->getLeftChildPtr(), total);
        total++;
        getNumberOfNodesHelper(subTreePtr->getMidChildPtr(), total);
        total++;
        getNumberOfNodesHelper(subTreePtr->getRightChildPtr(), total);
    }
    else
    {
        getNumberOfNodesHelper(subTreePtr->getLeftChildPtr(), total);
        total++;
        getNumberOfNodesHelper(subTreePtr->getRightChildPtr(), total);
    }
}



// 2-3 Tree Traversal helper functions
template<class T>
void TwoThreeTree<T>::preorder(void visit(T&), TriNode<T>* subTreePtr) const
{
    if (subTreePtr->isLeaf()) {
        if (subTreePtr->isTwoNode()) {
            T temp = subTreePtr->getSmallItem();
            visit(temp);
        } else {
            T temp = subTreePtr->getSmallItem();
            T temp2 = subTreePtr->getLargeItem();
            visit(temp);
            visit(temp2);
        }
    } else if (subTreePtr->isThreeNode()) {
        // **Visit current node first** before recursive calls
        T temp = subTreePtr->getSmallItem();
        T temp2 = subTreePtr->getLargeItem();
        visit(temp);
        preorder(visit, subTreePtr->getLeftChildPtr());
        visit(temp2);
        preorder(visit, subTreePtr->getMidChildPtr());
        preorder(visit, subTreePtr->getRightChildPtr());
    } else {
        // **Visit the node before traversing the left and right children**
        T temp = subTreePtr->getSmallItem();
        visit(temp);
        preorder(visit, subTreePtr->getLeftChildPtr());
        preorder(visit, subTreePtr->getRightChildPtr());
    }
}

template<class T>
void TwoThreeTree<T>::inorder(void visit(T&), TriNode<T>* subTreePtr) const
{
    if(subTreePtr->isLeaf())
    {
        if(subTreePtr->isTwoNode())
        {
            T temp = subTreePtr->getSmallItem();
            visit(temp);
        }
        else
        {
            T temp = subTreePtr->getSmallItem();
            T temp2 = subTreePtr->getLargeItem();
            visit(temp);
            visit(temp2);
        }
    }
    else if(subTreePtr->isThreeNode())
    {
        inorder(visit, subTreePtr->getLeftChildPtr());
        T temp = subTreePtr->getSmallItem();
        visit(temp);
        inorder(visit, subTreePtr->getMidChildPtr());
        T temp2 = subTreePtr->getLargeItem();
        visit(temp2);
        inorder(visit, subTreePtr->getRightChildPtr());
    }
    else
    {
        inorder(visit, subTreePtr->getLeftChildPtr());
        T temp = subTreePtr->getSmallItem();
        visit(temp);
        inorder(visit, subTreePtr->getRightChildPtr());
    }
}

template<class T>
void TwoThreeTree<T>::postorder(void visit(T&), TriNode<T>* subTreePtr) const
{
    if (subTreePtr->isLeaf()) {
        if (subTreePtr->isTwoNode()) {
            T temp = subTreePtr->getSmallItem();
            visit(temp);
        } else {
            T temp = subTreePtr->getSmallItem();
            T temp2 = subTreePtr->getLargeItem();
            visit(temp);
            visit(temp2);
        }
    } else if (subTreePtr->isThreeNode()) {
        // **Visit left, middle, and right children first, then visit current node**
        T temp = subTreePtr->getSmallItem();
        T temp2 = subTreePtr->getLargeItem();

        postorder(visit, subTreePtr->getLeftChildPtr());
        postorder(visit, subTreePtr->getMidChildPtr());
        postorder(visit, subTreePtr->getRightChildPtr());
        visit(temp);
        visit(temp2);

    } else {
        // **Visit left and right children first, then visit current node**
        postorder(visit, subTreePtr->getLeftChildPtr());
        postorder(visit, subTreePtr->getRightChildPtr());
        T temp = subTreePtr->getSmallItem();
        visit(temp);
    }

}



#endif