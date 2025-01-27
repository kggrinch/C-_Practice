#include "array_max_heap.h"

template<class ItemType>
ArrayMaxHeap<ItemType>::ArrayMaxHeap()
{

}

template<class ItemType>
ArrayMaxHeap<ItemType>::ArrayMaxHeap(const ItemType someArray[], const int arraySize) : itemCount(arraySize), maxItems(2 * arraySize)
{
  // Allocate the array
  items = new ItemType[2 * arraySize];

  // Copy given values into the array
  for (int i = 0; i < itemCount; i++)
  {
    items[i] = someArray[i];
  } 

  // Reorganize the array into heap
  heapCreate();
}

template<class ItemType>
ArrayMaxHeap<ItemType>::~ArrayMaxHeap()
{
  
}

template<class ItemType>
bool ArrayMaxHeap<ItemType>::isEmpty() const
{
  
}

template<class ItemType>
int ArrayMaxHeap<ItemType>::getNumberOfNodes() const
{
  
}

template<class ItemType>
int ArrayMaxHeap<ItemType>::getHeight() const
{
  
}

template<class ItemType>
ItemType ArrayMaxHeap<ItemType>::peekTop() const // throw(PrecondViolatedExcep)
{
  if (!isEmpty())
  {
    return items[0];
  }
  // throw PrecondViolatedExcep("Attempted peek into an empty heap.");
}

template<class ItemType>
bool ArrayMaxHeap<ItemType>::add(const ItemType& newData)
{
  
}

template<class ItemType>
bool ArrayMaxHeap<ItemType>::remove()
{
  
}

template<class ItemType>
void ArrayMaxHeap<ItemType>::clear()
{
  
}

// Private methods

template<class ItemType>
int ArrayMaxHeap<ItemType>::getLeftChildIndex(const int nodeIndex) const
{
  return (2 * nodeIndex) + 1;
}

template<class ItemType>
int ArrayMaxHeap<ItemType>::getRightChildIndex(int nodeIndex) const
{
  return (2 * nodeIndex) + 2;
}

template<class ItemType>
int ArrayMaxHeap<ItemType>::getParentIndex(int nodeIndex) const
{
  return (index - 1) / 2;
}

template<class ItemType>
bool ArrayMaxHeap<ItemType>::isLeaf(int nodeIndex) const
{
  
}

template<class ItemType>
void ArrayMaxHeap<ItemType>::heapRebuild(int subTreeRootIndex)
{
  
}

template<class ItemType>
void ArrayMaxHeap<ItemType>::heapCreate()
{
  // Creates it by starting at the middle technique
  for (int index = itemCount / 2; index >= 0; index--) 
  {
    heapRebuild(index);
  }
}