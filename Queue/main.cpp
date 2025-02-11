#include <iostream>
#include "array_queue.h"
#include "heap_priority_queue.h"
#include "linked_list_queue.h"
#include "heap_priority_queue.h"

int main()
{
  // This is a circular queue meaning that it uses front and pack pointer manipulation while keeps the data always stored in the vector data structure. This is why its more efficent
  // to implment this queue using dynamic array.



  ArrayQueue<int> my_array_queue;
  std::cout << "y_queue.is_empty(): " << my_array_queue.is_empty() << "\n";

  my_array_queue.push(1);
  my_array_queue.push(2);
  my_array_queue.push(3);
  my_array_queue.push(4);
  my_array_queue.push(5);

  std::cout << "my_queue.count(): " << my_array_queue.count() << "\n";
  std::cout << "my_queue.is_empty(): " << my_array_queue.is_empty() << "\n";
  std::cout << "my_queue.front(): " << my_array_queue.front() << "\n";
  std::cout << "my_queue.back(): " << my_array_queue.back() << "\n";
  std::cout << "my_queue: " << my_array_queue << "\n";

  std::cout << "my_queue.pop(): " << my_array_queue.pop() << "\n";
  std::cout << "my_queue.front(): " << my_array_queue.front() << "\n";
  std::cout << "my_queue: " << my_array_queue << "\n";


  // Linked_List_Queue
  LinkedQueue<int> linked_queue;

  linked_queue.enqueue(1);
  linked_queue.enqueue(2);
  linked_queue.enqueue(3);
  linked_queue.enqueue(4);
  linked_queue.enqueue(5);
  std::cout << linked_queue.peekFront() << "\n";
  std::cout << linked_queue << "\n";

  // Heap Priority Queue
  HeapPriorityQueue<int> heap_priority_queue;

  heap_priority_queue.enqueue(1);
  heap_priority_queue.enqueue(2);
  heap_priority_queue.enqueue(3);
  heap_priority_queue.enqueue(4);
  heap_priority_queue.enqueue(5);
  heap_priority_queue.display();
  std::cout << heap_priority_queue.peekFront() << "\n";
  std::cout << heap_priority_queue.dequeue() << "\n";
  heap_priority_queue.display();





}
