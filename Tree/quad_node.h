#ifndef QUAD_NODE_H
#define QUAD_NODE_H


template<class ItemType>
class QuadNode
{
public:
    QuadNode();
    QuadNode( const ItemType& anItem);
    QuadNode(const ItemType& anItem, QuadNode<ItemType>* leftPtr, QuadNode<ItemType>* leftMidPtr, QuadNode<ItemType>* rightMidPtr, QuadNode<ItemType>* rightPtr);

    bool isLeaf() const;
    bool isTwoNode() const;
    bool isThreeNode() const;
    bool isFourNode() const;

    ItemType getSmallItem() const;
    ItemType getMidItem() const;
    ItemType getLargeItem() const;

    void setSmallItem( const ItemType& anItem);
    void setMidItem(const ItemType& anItem);
    void setLargeItem( const ItemType& anItem);

    QuadNode<ItemType>* getLeftChildPtr() const;
    QuadNode<ItemType>* getLeftMidChildPtr() const;
    QuadNode<ItemType>* getRightMidChildPtr() const;
    QuadNode<ItemType>* getRightChildPtr() const;

    void setLeftChildPtr(QuadNode<ItemType>* leftPtr);
    void setLeftMidChildPtr(QuadNode<ItemType>* leftMidPtr);
    void setRightMidChildPtr(QuadNode<ItemType>* rightMidPtr);
    void setRightChildPtr(QuadNode<ItemType>* rightPtr);

private:
    ItemType smallItem, middleItem, largeItem; // Data portion
    QuadNode<ItemType>* leftChildPtr;
    QuadNode<ItemType>* leftMidChildPtr;
    QuadNode<ItemType>* rightMidChildPtr;
    QuadNode<ItemType>* rightChildPtr;
};

#include "quad_node.cpp"

#endif //QUAD_NODE_H
