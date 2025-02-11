#ifndef ARRAY_MIN_HEAP_CPP_
#define ARRAY_MIN_HEAP_CPP_
#include "array_min_heap.h"
#include <algorithm>


template<class ItemType>
ArrayMinHeap<ItemType>::ArrayMinHeap() : items(nullptr), itemCount(0), maxItems(DEFAULT_CAPACITY)
{
  items = new ItemType[DEFAULT_CAPACITY];
}

template<class ItemType>
ArrayMinHeap<ItemType>::ArrayMinHeap(const ItemType someArray[], const int arraySize) : items(nullptr), itemCount(arraySize), maxItems(2 * arraySize)
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
ArrayMinHeap<ItemType>::~ArrayMinHeap()
{
  delete[] items;
}

template<class ItemType>
bool ArrayMinHeap<ItemType>::isEmpty() const
{
  return itemCount == 0;
}

template<class ItemType>
int ArrayMinHeap<ItemType>::getNumberOfNodes() const
{
  return itemCount;
}

template<class ItemType>
int ArrayMinHeap<ItemType>::getHeight() const
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
ItemType ArrayMinHeap<ItemType>::peekTop() const // throw(PrecondViolatedExcep)
{
  if (!isEmpty())
  {
    return items[0];
  }
  // throw PrecondViolatedExcep("Attempted peek into an empty heap.");
}

template<class ItemType>
bool ArrayMinHeap<ItemType>::add(const ItemType& newData)
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
    if (items[newDataIndex] < items[parentIndex])
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
bool ArrayMinHeap<ItemType>::remove()
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
void ArrayMinHeap<ItemType>::clear()
{
  itemCount = 0;
}

template<class ItemType>
void ArrayMinHeap<ItemType>::display() const
{
  for(int i = 0; i < itemCount; i++)
  {
    std::cout << items[i] << " ";
  }
  std::cout << "\n";
}


// Private methods

template<class ItemType>
int ArrayMinHeap<ItemType>::getLeftChildIndex(const int nodeIndex) const
{
  return (2 * nodeIndex) + 1;
}

template<class ItemType>
int ArrayMinHeap<ItemType>::getRightChildIndex(int nodeIndex) const
{
  return (2 * nodeIndex) + 2;
}

template<class ItemType>
int ArrayMinHeap<ItemType>::getParentIndex(int nodeIndex) const
{
  return (nodeIndex - 1) / 2;
}

template<class ItemType>
bool ArrayMinHeap<ItemType>::isLeaf(int nodeIndex) const
{
  return getLeftChildIndex(nodeIndex) >= itemCount;
}

template<class ItemType>
void ArrayMinHeap<ItemType>::heapRebuild(int subTreeRootIndex)
{
  int leftChildIndex = getLeftChildIndex(subTreeRootIndex);
  int rightChildIndex = getRightChildIndex(subTreeRootIndex);
  int smallerChildIndex = leftChildIndex;

  // Find the smaller child to maintain the min-heap property
  if (rightChildIndex < itemCount && items[rightChildIndex] < items[leftChildIndex])
  {
    smallerChildIndex = rightChildIndex;
  }

  // Swap if the parent is greater than the smaller child (min-heap condition)
  if (smallerChildIndex < itemCount && items[subTreeRootIndex] > items[smallerChildIndex])
  {
    std::swap(items[subTreeRootIndex], items[smallerChildIndex]);
    // display(); // This displays the heap after each iteration of rebuild
    heapRebuild(smallerChildIndex);
  }
}

template<class ItemType>
void ArrayMinHeap<ItemType>::heapCreate()
{
  // Creates it by starting at the middle technique
  for (int index = itemCount / 2; index >= 0; index--)
  {
    heapRebuild(index);
    // display(); // This displays the heap after each iteration of rebuild
  }
}

#endif