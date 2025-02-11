#ifndef LINKED_LIST_QUEUE_H_
#define LINKED_LIST_QUEUE_H_
#include "node.h"

template<class ItemType>
class LinkedQueue
{
public:
    LinkedQueue();
    LinkedQueue( const LinkedQueue& aQueue);
    ~LinkedQueue();
    bool isEmpty() const ;
    bool enqueue(const ItemType& newEntry);
    bool dequeue();
    ItemType peekFront()  const;

    template<class U>
    friend std::ostream& operator<<(std::ostream& stream, const LinkedQueue<U>& other);

private:
    Node<ItemType>* frontPtr;
    Node<ItemType>* backPtr;
};

// Implementation
template<class ItemType>
LinkedQueue<ItemType>::LinkedQueue() : frontPtr(nullptr), backPtr(nullptr)
{

}

template<class ItemType>
LinkedQueue<ItemType>::LinkedQueue(const LinkedQueue& aQueue) : frontPtr(nullptr), backPtr(nullptr)
{

}

template<class ItemType>
LinkedQueue<ItemType>::~LinkedQueue()
{

}

template<class ItemType>
bool LinkedQueue<ItemType>::isEmpty() const
{
    return frontPtr == nullptr;
}

template<class ItemType>
bool LinkedQueue<ItemType>::enqueue( const ItemType& newEntry)
{
    Node<ItemType>* newNode = new Node<ItemType>(newEntry);

    if (isEmpty())
    {
        frontPtr = newNode;  // If the queue is empty, set both front and back to new node
        backPtr = newNode;
    }
    else
    {
        backPtr->setNext(newNode);  // Set the next pointer of the current back node
        backPtr = newNode;          // Update backPtr to point to the new last node
    }

    return true;
}

template<class ItemType>
bool LinkedQueue<ItemType>::dequeue()
{
    if (isEmpty())
    {
        return false;  // Can't dequeue from an empty queue
    }

    Node<ItemType>* nodeToDelete = frontPtr;
    frontPtr = frontPtr->getNext();  // Move frontPtr to the next node

    if (frontPtr == nullptr)
    {
        backPtr = nullptr;  // If the queue is now empty, set backPtr to nullptr
    }

    delete nodeToDelete;  // Free the memory for the old front node
    return true;
}

template<class ItemType>
ItemType LinkedQueue<ItemType>::peekFront()  const
{
    if(!isEmpty())
    {
        return frontPtr->getItem();
    }
}

template<class ItemType>
std::ostream& operator<<(std::ostream& stream, const LinkedQueue<ItemType>& other)
{
    if(other.frontPtr != nullptr)
    {
        Node<ItemType>* current = other.frontPtr;
        while(current != nullptr)
        {
            stream << current->getItem() << " ";
            current = current->getNext();
        }
    }
    return stream << "\n";
}


#endif
