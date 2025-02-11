#ifndef ARRAY_MAX_HEAP_CPP_
#define ARRAY_MAX_HEAP_CPP_
#include "array_max_heap.h"
#include <algorithm>

template<class ItemType>
ArrayMaxHeap<ItemType>::ArrayMaxHeap() : items(nullptr), itemCount(0), maxItems(DEFAULT_CAPACITY)
{
  items = new ItemType[DEFAULT_CAPACITY];
}

template<class ItemType>
ArrayMaxHeap<ItemType>::ArrayMaxHeap(const ItemType someArray[], const int arraySize) : items(nullptr), itemCount(arraySize), maxItems(2 * arraySize)
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
  delete[] items;
}

template<class ItemType>
bool ArrayMaxHeap<ItemType>::isEmpty() const
{
  return itemCount == 0;
}

template<class ItemType>
int ArrayMaxHeap<ItemType>::getNumberOfNodes() const
{
  return itemCount;
}

template<class ItemType>
int ArrayMaxHeap<ItemType>::getHeight() const
{
  int height = 0;
  int nodes = itemCount;

  while (nodes > 0) {
    nodes /= 2;
    height++;
  }

  return height;
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
  // If item count reaches max size resize the max
  if (itemCount == maxItems)
  {
    maxItems *= 2;
    ItemType* newArray = new ItemType[maxItems];

    for (int i = 0; i < itemCount; i++)
    {
      newArray[i] = items[i];
    }
    delete[] items;
    items = newArray;
  }

  items[itemCount] = newData;
  int newDataIndex = itemCount;
  itemCount++;

  while (newDataIndex > 0)
    {
    int parentIndex = getParentIndex(newDataIndex);
    if (items[newDataIndex] > items[parentIndex])
    {
      std::swap(items[newDataIndex], items[parentIndex]);
      newDataIndex = parentIndex;
    }
    else
    {
      break;
    }
  }

  return true;
}

template<class ItemType>
bool ArrayMaxHeap<ItemType>::remove()
{
  if (isEmpty())
  {
    return false;
  }

  items[0] = items[itemCount - 1];
  itemCount--;
  heapRebuild(0);

  return true;
}

template<class ItemType>
void ArrayMaxHeap<ItemType>::clear()
{
  itemCount = 0;
}

template<class ItemType>
void ArrayMaxHeap<ItemType>::display() const
{
  for(int i = 0; i < itemCount; i++)
  {
    std::cout << items[i] << " ";
  }
  std::cout << "\n";
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
  return (nodeIndex - 1) / 2;
}

template<class ItemType>
bool ArrayMaxHeap<ItemType>::isLeaf(int nodeIndex) const
{
  return getLeftChildIndex(nodeIndex) >= itemCount;
}

template<class ItemType>
void ArrayMaxHeap<ItemType>::heapRebuild(int subTreeRootIndex)
{
  if (!isLeaf(subTreeRootIndex))
  {
    int leftChildIndex = getLeftChildIndex(subTreeRootIndex);
    int rightChildIndex = getRightChildIndex(subTreeRootIndex);
    int largerChildIndex = leftChildIndex;

    if (rightChildIndex < itemCount && items[rightChildIndex] > items[leftChildIndex])
    {
      largerChildIndex = rightChildIndex;
    }

    if (largerChildIndex < itemCount && items[subTreeRootIndex] < items[largerChildIndex])
    {
      std::swap(items[subTreeRootIndex], items[largerChildIndex]);
      // display(); // This displays the heap after each iteration of rebuild
      heapRebuild(largerChildIndex);
    }
  }
}

template<class ItemType>
void ArrayMaxHeap<ItemType>::heapCreate()
{
  // Creates it by starting at the middle technique
  for (int index = itemCount / 2; index >= 0; index--) 
  {
    heapRebuild(index);
    display(); // This displays the heap after each iteration of rebuild
  }
}

#endif