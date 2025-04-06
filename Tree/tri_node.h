#ifndef TRI_NODE_H
#define TRI_NODE_H

template <class ItemType>
class TriNode
{

public:
    TriNode();
    TriNode( const ItemType& anItem);
    TriNode(const ItemType& anItem, TriNode<ItemType>* leftPtr, TriNode<ItemType>* midPtr, TriNode<ItemType>* rightPtr);

    bool isLeaf() const;
    bool isTwoNode() const;
    bool isThreeNode() const;
    ItemType getSmallItem() const;
    ItemType getLargeItem() const;
    void setSmallItem( const ItemType& anItem);
    void setLargeItem( const ItemType& anItem);
    TriNode<ItemType>* getLeftChildPtr() const ;
    TriNode<ItemType>* getMidChildPtr() const ;
    TriNode<ItemType>* getRightChildPtr() const ;
    void setLeftChildPtr(TriNode<ItemType>* leftPtr);
    void setMidChildPtr(TriNode<ItemType>* midPtr);
    void setRightChildPtr(TriNode<ItemType>* rightPtr);

    // Remove Implementation private node methods
    ItemType replaceWithMinKey();
    ItemType replaceWithMaxKey();
    bool isBalanced();
    void rebalance();

private:
    ItemType smallItem, largeItem; // Data portion
    TriNode<ItemType>* leftChildPtr;   // Left-child pointer
    TriNode<ItemType>* midChildPtr;    // Middle-child pointer
    TriNode<ItemType>* rightChildPtr; // Right-child pointer



};

#include "tri_node.cpp"

#endif //TRI_NODE_H
