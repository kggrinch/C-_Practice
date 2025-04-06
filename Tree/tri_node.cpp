#ifndef TRI_NODE_CPP
#define TRI_NODE_CPP

#include "tri_node.h"

template<class ItemType>
TriNode<ItemType>::TriNode() : smallItem(ItemType()), largeItem(ItemType()), leftChildPtr(nullptr), midChildPtr(nullptr), rightChildPtr(nullptr)
{

}

// Constructor with item
template<class ItemType>
TriNode<ItemType>::TriNode(const ItemType& anItem) : smallItem(anItem), largeItem(ItemType()), leftChildPtr(nullptr), midChildPtr(nullptr), rightChildPtr(nullptr)
{

}

// Constructor with item and child pointers
template<class ItemType>
TriNode<ItemType>::TriNode(const ItemType& anItem, TriNode<ItemType>* leftPtr, TriNode<ItemType>* midPtr, TriNode<ItemType>* rightPtr)
: smallItem(anItem), largeItem(ItemType()), leftChildPtr(leftPtr), midChildPtr(midPtr), rightChildPtr(rightPtr)
{

}

// Check if the node is a leaf (has no children)
template<class ItemType>
bool TriNode<ItemType>::isLeaf()const
{
    return (leftChildPtr == nullptr && midChildPtr == nullptr && rightChildPtr == nullptr);
}

// Check this
// Check if the node is a two-node (has only smallItem)
template<class ItemType>
bool TriNode<ItemType>::isTwoNode()const
{
    return largeItem == ItemType();
}

// Check this
template<class ItemType>
bool TriNode<ItemType>::isThreeNode()const
{
    return !(isTwoNode());
}

template<class ItemType>
ItemType TriNode<ItemType>::getSmallItem()const
{
    return smallItem;
}

template<class ItemType>
ItemType TriNode<ItemType>::getLargeItem()const
{
    return largeItem;
}

template<class ItemType>
void TriNode<ItemType>::setSmallItem( const ItemType& anItem)
{
    smallItem = anItem;
}

template<class ItemType>
void TriNode<ItemType>::setLargeItem( const ItemType& anItem)
{
    largeItem = anItem;
}

template<class ItemType>
TriNode<ItemType>* TriNode<ItemType>::getLeftChildPtr() const
{
    return leftChildPtr;
}

template<class ItemType>
TriNode<ItemType>* TriNode<ItemType>::getMidChildPtr() const
{
    return midChildPtr;
}

template<class ItemType>
TriNode<ItemType>* TriNode<ItemType>::getRightChildPtr() const
{
    return rightChildPtr;
}

template<class ItemType>
void TriNode<ItemType>::setLeftChildPtr(TriNode<ItemType>* leftPtr)
{
    leftChildPtr = leftPtr;
}

template<class ItemType>
void TriNode<ItemType>::setMidChildPtr(TriNode<ItemType>* midPtr)
{
    midChildPtr = midPtr;
}

template<class ItemType>
void TriNode<ItemType>::setRightChildPtr(TriNode<ItemType>* rightPtr)
{
    rightChildPtr = rightPtr;
}

template<class ItemType>
ItemType TriNode<ItemType>::replaceWithMinKey()
{
    ItemType minKey;
    if(!isLeaf())
    {
        minKey = leftChildPtr->replaceWithMinKey();
    } //traversing to reach leaf left child
    else
    { // Trivial case, we are on the leaf level of the tree
        minKey = smallItem;
        smallItem = ItemType();
        if(largeItem != ItemType())
        { // We traversed to left most child since there was right child
            smallItem = largeItem;
            largeItem = ItemType();
        }
    }
    if(!isBalanced())rebalance(); //rebalance
    return minKey;
}

template<class ItemType>
ItemType TriNode<ItemType>::replaceWithMaxKey()
{
    ItemType maxKey;
    if(!isLeaf())
    { // Recursion, not on leaf node
        if(largeItem != ItemType()) maxKey = rightChildPtr->replaceWithMaxKey(); // traversing to reach last element in right child
        else maxKey = midChildPtr->replaceWithMaxKey();  // else, we traverse in middle child
    }
    else
    {	// Trivial case, we are on the leaf level of the tree
        if(largeItem == ItemType())
        {
            maxKey = smallItem;
            setSmallItem(ItemType());
        }
        else
        {
            maxKey = getLargeItem();
            setLargeItem(ItemType());//no rebalance required
        }
    }
    if(!isBalanced()) rebalance(); // rebalance if tree not balanced
    return maxKey;
}

template<class ItemType>
bool TriNode<ItemType>::isBalanced()
{
    bool isBalanced = false;
    if(!isLeaf()) isBalanced = true;  // If we are at the leaf node(last level), it is well-balanced for sure

    // There are two cases: 2 Node or 3 Node
    else if(leftChildPtr != nullptr && midChildPtr != nullptr)
    {
        if(largeItem != ItemType())
        { // 3 Node/has 3 children
            if(rightChildPtr != nullptr)
            {
                isBalanced = true;
            }
        }
        else
        {  // 2 Node/has 2 children
            isBalanced = true;
        }
    }
    return isBalanced;

}

template<class ItemType>
void TriNode<ItemType>::rebalance()
{
      while(!isBalanced())
      {
          if(getLeftChildPtr() == nullptr)
          { // The unbalance is in the left child
              // We put the left element of current node as the left element of the left child
              getLeftChildPtr()->setSmallItem(getSmallItem());
              // Now we replace the left element of the mid child as the left element of the current node
              setSmallItem(getMidChildPtr()->getSmallItem());
              // If a right element on the mid child exists, we shift it to the left
              if(getMidChildPtr()->isThreeNode())
              {
                  getMidChildPtr()->setSmallItem(getMidChildPtr()->getLargeItem());
                  getMidChildPtr()->setLargeItem(ItemType());
              }
              // Else, we let the mid child EMPTY, so the next iteration may solve this situation
              // if not, the condition of the critical case
              else
              {
                  getMidChildPtr()->setSmallItem(ItemType());
              }
          }
          else if(getMidChildPtr() == nullptr)

          { // The unbalance is in the right child
              //BASE CASE, each node (child) of the deepest level have just one element (the right is empty)
              // will have to rebalance from a higher level of the tree
              if(isTwoNode())
              {
                  if(getLeftChildPtr()->isTwoNode())
                  {
                      setLargeItem(getSmallItem());
                      setSmallItem(getLeftChildPtr()->getSmallItem());
                      //remove the current children
                      setLeftChildPtr(nullptr);
                      setRightChildPtr(nullptr);
                      setRightChildPtr(nullptr);
                  }
                  else
                  {
                      getMidChildPtr()->setSmallItem(getSmallItem());
                      if(getLeftChildPtr()->isTwoNode())
                      {
                          setSmallItem(getLeftChildPtr()->getSmallItem());
                          getLeftChildPtr()->setSmallItem(ItemType());
                      }
                      else
                      {
                          setSmallItem(getLeftChildPtr()->getLargeItem());
                          getLeftChildPtr()->setLargeItem(ItemType());
                      }
                      if(getLeftChildPtr() == nullptr && getMidChildPtr() == nullptr)
                      {
                          // The other but same case
                          setLeftChildPtr(nullptr);
                          setMidChildPtr(nullptr);
                          setRightChildPtr(nullptr);
                      }
                  }
              }
              else
              {
                  // We put the right element of the current node as the left element of the middle child
                  getMidChildPtr()->setSmallItem(getLargeItem());
                  // We put the left element of the right child as the right element of the current node
                  setLargeItem(getRightChildPtr()->getSmallItem());
                  // If the right child, where we have taken the last element has a right element, we move it
                  // into the left of the same child
                  if(getRightChildPtr()->isThreeNode())
                  {
                      getRightChildPtr()->setSmallItem(getRightChildPtr()->getLargeItem());
                      getRightChildPtr()->setLargeItem(ItemType());
                  }
                  else
                  { // Else, we let the right child EMPTY
                      getRightChildPtr()->setSmallItem(ItemType());
                  }
              }
              // Unbalance in the right child
          }
          else if(isThreeNode() && getRightChildPtr() == nullptr)
          {
              if(getMidChildPtr()->isThreeNode())
              { // (1)case
                  getRightChildPtr()->setSmallItem(getLargeItem());
                  setLargeItem(getMidChildPtr()->getLargeItem());
                  getMidChildPtr()->setLargeItem(ItemType());
              }
              else
              { // (2)case
                  getMidChildPtr()->setLargeItem(getLargeItem());
                  setLargeItem(ItemType());
              }
          }
      }
}


#endif