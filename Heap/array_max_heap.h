#ifndef ARRAY_MAX_HEAP_H_
#define ARRAY_MAX_HEAP_H_
#include "heap_interface.h"

template<class ItemType>
class ArrayMaxHeap : public HeapInterface<ItemType>
{

  public:
    ArrayMaxHeap();

    ArrayMaxHeap(const ItemType someArray[], const int arraySize);

    virtual ~ArrayMaxHeap();

    // HeapInterface Public Methods:
    bool isEmpty() const;

    int getNumberOfNodes() const;

    int getHeight() const;

    ItemType peekTop() const throw(PrecondViolatedExcep);
    
    bool add(const ItemType& newData);

    bool remove();

    void clear();

  private:
    static const int ROOT_INDEX = 0; // Helps with readability
    static const int DEFAULT_CAPACITY = 21; // Small capacity to test for a full heap
    ItemType* items; // Array of heap items
    int itemCount; // Current count of heap items
    int maxItems; // Maximum capacity of the heap

    // --------------------------------------------------------------------- 
    // Most of the private utility methods use an array index as a parameter
    // and in calculations. This should be safe, even though the array is an
    // implementation detail, since the methods are private.
    // ---------------------------------------------------------------------
     
    // Returns the array index of the left child (if it exists).
    int getLeftChildIndex(const int nodeIndex) const;

    // Returns the array index of the right child (if it exists).

    int getRightChildIndex(int nodeIndex) const; // Returns the array index of the parent node.

    int getParentIndex(int nodeIndex) const; // Tests whether this node is a leaf.

    bool isLeaf(int nodeIndex) const; // Converts a semiheap to a heap.

    void heapRebuild(int subTreeRootIndex); // Creates a heap from an unordered array.
    
    void heapCreate();

};



#endif