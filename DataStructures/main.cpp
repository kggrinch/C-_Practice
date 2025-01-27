#include<iostream>
#include<string> // String
#include<vector> // vector
#include<list> // LinkedList - doubly
#include<stack> // Stack
#include<deque> // queue

int main()
{
  // Data structures list
  // 1. String
  // 2. Vector
  // 3. Array - dynamic and standard
  // 4. Linkedlist - doubly, singly, w/o tail
  // 5. Stack
  // 6. BST - does not have a direct DST in STL. Sets and Maps implement it under the hood.
  // 7. Queue

  std::deque<int> q;

  for(int i = 0; i < 5; i++)
  {
    q.push_front(i);
  }

  std::cout <<"q.size(): " << q.size() << "\n";
  q.pop_front();
  std::cout <<"q.size(): " << q.size() << "\n";

  q.push_back(6);




}