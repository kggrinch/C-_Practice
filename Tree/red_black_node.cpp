#ifndef RED_BLACK_NODE_CPP
#define RED_BLACK_NODE_CPP
#include "red_black_node.h"

// Implementation of methods
template <class ItemType>
RedBlackNode<ItemType>::RedBlackNode() : BinaryNode<ItemType>(), leftColor(BLACK), rightColor(BLACK)
{

}

template <class ItemType>
RedBlackNode<ItemType>::RedBlackNode(const ItemType& anItem) :
BinaryNode<ItemType>(anItem), leftColor(BLACK), rightColor(BLACK)
{

}

template <class ItemType>
RedBlackNode<ItemType>::RedBlackNode(const ItemType& anItem, BinaryNode<ItemType>* leftPtr, Color leftEdgeColor, BinaryNode<ItemType>* rightPtr, Color rightEdgeColor) :
BinaryNode<ItemType>(anItem, leftPtr, rightPtr), leftColor(leftEdgeColor), rightColor(rightEdgeColor)
{

}

template <class ItemType>
Color RedBlackNode<ItemType>::getLeftColor() const
{
    return leftColor;
}

template <class ItemType>
void RedBlackNode<ItemType>::setLeftColor(Color newColor)
{
    leftColor = newColor;
}

template <class ItemType>
Color RedBlackNode<ItemType>::getRightColor() const
{
    return rightColor;
}

template <class ItemType>
void RedBlackNode<ItemType>::setRightColor(Color newColor)
{
    rightColor = newColor;
}

#endif
