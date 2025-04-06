#ifndef RED_BLACK_NODE_H
#define RED_BLACK_NODE_H
#include "binary_node.h"

enum Color { RED, BLACK };

template<class ItemType>
class RedBlackNode : BinaryNode<ItemType>
{

public:
    // Constructors
    RedBlackNode();
    RedBlackNode(const ItemType& anItem);
    RedBlackNode(const ItemType& anItem, BinaryNode<ItemType>* leftPtr, Color leftEdgeColor, BinaryNode<ItemType>* rightPtr, Color rightEdgeColor);

    // Getters and Setters for pointer colors
    Color getLeftColor() const;
    void setLeftColor(Color newColor);

    Color getRightColor() const;
    void setRightColor(Color newColor);

private:
    Color leftColor, rightColor; // Colors of the pointers (edges)
};

#include "red_black_node.cpp"

#endif //RED_BLACK_NODE_H
