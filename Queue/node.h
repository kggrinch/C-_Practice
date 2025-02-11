#ifndef NODE_H
#define NODE_H

template <class ItemType>
class Node {

public:
    // Default constructor
    Node();

    // Constructor with item initialization
    Node(const ItemType& anItem);

    // Constructor with item and next node initialization
    Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);
    // Getter for item
    ItemType getItem() const;

    // Setter for item
    void setItem(const ItemType& anItem);

    // Getter for next node pointer
    Node<ItemType>* getNext() const;

    // Setter for next node pointer
    void setNext(Node<ItemType>* nextNodePtr);

private:
    ItemType item;          // The data stored in the node
    Node<ItemType>* next;   // Pointer to the next node in the list
};

// implementation

template<class ItemType>
Node<ItemType>::Node() : next(nullptr)
{

}

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem) : item(anItem), next(nullptr)
{

}

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem, Node<ItemType>* nextNodePtr) : item(anItem), next(nextNodePtr)
{

}

template<class ItemType>
ItemType Node<ItemType>::getItem() const
{
    return item;
}

template<class ItemType>
void Node<ItemType>::setItem(const ItemType& anItem)
{
    item = anItem;
}

template<class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const
{
    return next;
}

template<class ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr)
{
    next = nextNodePtr;
}



#endif // NODE_H
