//
// Created by Kirill on 1/29/2025.
//

#ifndef HEAP_PRIORITY_QUEUE_H
#define HEAP_PRIORITY_QUEUE_H

template<class ItemType>
class HeapPriorityQueue
{

public:
    HeapPriorityQueue();
    void enqueue(const ItemType &newEntry);
    bool dequeue();
    ItemType peekFront() const;
    bool isEmpty() const;
    void display() const; // For debugging

    void heapCreate();


private:
    std::vector<ItemType> items; // Min-heap array
    int itemCount;

    int getLeftChildIndex(int parentIndex) const { return 2 * parentIndex + 1; }
    int getRightChildIndex(int parentIndex) const { return 2 * parentIndex + 2; }
    int getParentIndex(int childIndex) const { return (childIndex - 1) / 2; }

    void heapRebuild(int subTreeRootIndex);

};


// Implementation
template <class ItemType>
HeapPriorityQueue<ItemType>::HeapPriorityQueue() : itemCount(0) {}

// Rebuild the heap after removing an element
template <class ItemType>
void HeapPriorityQueue<ItemType>::heapRebuild(int subTreeRootIndex)
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
        heapRebuild(largerChildIndex);
    }
}

// Insert element into priority queue
template <class ItemType>
void HeapPriorityQueue<ItemType>::enqueue(const ItemType &newEntry)
{
    items.push_back(newEntry);
    int newDataIndex = itemCount;
    itemCount++;

    // Heapify Up
    while (newDataIndex > 0)
    {
        int parentIndex = getParentIndex(newDataIndex);
        if(items[newDataIndex] > items[parentIndex])
        {
            std::swap(items[newDataIndex], items[parentIndex]);
            newDataIndex = parentIndex;
        }
        else
        {
            break;
        }
    }
}

// Remove highest priority element
template <class ItemType>
bool HeapPriorityQueue<ItemType>::dequeue()
{
    if (isEmpty())
        return false;

    items[0] = items[itemCount - 1]; // Replace root with last element
    items.pop_back();
    itemCount--;

    if (!isEmpty())
    {
        heapRebuild(0); // Restore heap property
    }
    return true;
}

// Get the element with highest priority
template <class ItemType>
ItemType HeapPriorityQueue<ItemType>::peekFront() const
{
    if (isEmpty())
        throw std::runtime_error("Priority queue is empty.");
    return items[0];
}

// Check if queue is empty
template <class ItemType>
bool HeapPriorityQueue<ItemType>::isEmpty() const
{
    return itemCount == 0;
}

// Build heap from unordered array
template <class ItemType>
void HeapPriorityQueue<ItemType>::heapCreate()
{
    for (int index = itemCount / 2; index >= 0; index--)
    {
        heapRebuild(index);
    }
}

// Display the heap (for debugging)
template <class ItemType>
void HeapPriorityQueue<ItemType>::display() const
{
    for (const auto &item : items)
        std::cout << item << " ";
    std::cout << std::endl;
}

#endif //HEAP_PRIORITY_QUEUE_H
