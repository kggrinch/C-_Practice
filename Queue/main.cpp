#include <iostream>
#include "queue.h"

int main()
{
  // This is a circular queue meaning that it uses front and pack pointer manipulation while keeps the data always stored in the vector data structure. This is why its more efficent
  // to implment this queue using dynamic array.



  Queue<int> my_queue;
  std::cout << "y_queue.is_empty(): " << my_queue.is_empty() << "\n";

  my_queue.push(1);
  my_queue.push(2);
  my_queue.push(3);
  my_queue.push(4);
  my_queue.push(5);

  std::cout << "my_queue.count(): " << my_queue.count() << "\n";
  std::cout << "my_queue.is_empty(): " << my_queue.is_empty() << "\n";
  std::cout << "my_queue.front(): " << my_queue.front() << "\n";
  std::cout << "my_queue.back(): " << my_queue.back() << "\n";
  std::cout << "my_queue: " << my_queue << "\n";

  std::cout << "my_queue.pop(): " << my_queue.pop() << "\n";
  std::cout << "my_queue.front(): " << my_queue.front() << "\n";
  std::cout << "my_queue: " << my_queue << "\n";
}