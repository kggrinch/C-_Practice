#ifndef QUAD_NODE_CPP_
#define QUAD_NODE_CPP_
#include "quad_node.h"

template<class ItemType>
QuadNode<ItemType>::QuadNode() :
smallItem(ItemType()), middleItem(ItemType()), largeItem(ItemType()), leftChildPtr(nullptr), leftMidChildPtr(nullptr), rightMidChildPtr(nullptr), rightChildPtr(nullptr)
{

}

template<class ItemType>
QuadNode<ItemType>::QuadNode( const ItemType& anItem) :
smallItem(anItem), middleItem(ItemType()), largeItem(ItemType()), leftChildPtr(nullptr), leftMidChildPtr(nullptr), rightMidChildPtr(nullptr), rightChildPtr(nullptr)
{

}

template<class ItemType>
QuadNode<ItemType>::QuadNode(const ItemType& anItem, QuadNode<ItemType>* leftPtr, QuadNode<ItemType>* leftMidPtr, QuadNode<ItemType>* rightMidPtr, QuadNode<ItemType>* rightPtr) :
smallItem(anItem), middleItem(ItemType()), largeItem(ItemType()), leftChildPtr(leftPtr), leftMidChildPtr(leftMidPtr), rightMidChildPtr(rightMidPtr), rightChildPtr(rightPtr)
{

}

template<class ItemType>
bool QuadNode<ItemType>::isLeaf() const
{
    if(leftChildPtr == nullptr && rightMidChildPtr == nullptr && leftMidChildPtr == nullptr && rightChildPtr == nullptr) return true;
    return false;
}

template<class ItemType>
bool QuadNode<ItemType>::isTwoNode() const
{
    if(largeItem == ItemType() && middleItem == ItemType()) return true;
    return false;

}

template<class ItemType>
bool QuadNode<ItemType>::isThreeNode() const
{
    if(middleItem == ItemType()) return true;
    return false;

}

template<class ItemType>
bool QuadNode<ItemType>::isFourNode() const
{
   if(!isTwoNode() && !isThreeNode()) return true;
    return false;
}

template<class ItemType>
ItemType QuadNode<ItemType>::getSmallItem() const
{
    return smallItem;
}

template<class ItemType>
ItemType QuadNode<ItemType>::getMidItem() const
{
    return middleItem;
}

template<class ItemType>
ItemType QuadNode<ItemType>::getLargeItem() const
{
    return largeItem;
}

template<class ItemType>
void QuadNode<ItemType>::setSmallItem( const ItemType& anItem)
{
    smallItem = anItem;
}

template<class ItemType>
void QuadNode<ItemType>::setMidItem(const ItemType& anItem)
{
    middleItem = anItem;
}

template<class ItemType>
void QuadNode<ItemType>::setLargeItem( const ItemType& anItem)
{
    largeItem = anItem;
}

template<class ItemType>
QuadNode<ItemType>* QuadNode<ItemType>::getLeftChildPtr() const
{
    return leftChildPtr;
}

template<class ItemType>
QuadNode<ItemType>* QuadNode<ItemType>::getLeftMidChildPtr() const
{
    return leftMidChildPtr;
}

template<class ItemType>
QuadNode<ItemType>* QuadNode<ItemType>::getRightMidChildPtr() const
{
    return rightMidChildPtr;
}

template<class ItemType>
QuadNode<ItemType>* QuadNode<ItemType>::getRightChildPtr() const
{
    return rightChildPtr;
}

template<class ItemType>
void QuadNode<ItemType>::setLeftChildPtr(QuadNode<ItemType>* leftPtr)
{
    leftChildPtr = leftPtr;
}

template<class ItemType>
void QuadNode<ItemType>::setLeftMidChildPtr(QuadNode<ItemType>* leftMidPtr)
{
    leftMidChildPtr = leftMidPtr;
}

template<class ItemType>
void QuadNode<ItemType>::setRightMidChildPtr(QuadNode<ItemType>* rightMidPtr)
{
    rightMidChildPtr = rightMidPtr;
}

template<class ItemType>
void QuadNode<ItemType>::setRightChildPtr(QuadNode<ItemType>* rightPtr)
{
    rightChildPtr = rightPtr;
}



#endif