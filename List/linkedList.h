/*
Declaration
*/
#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include <iostream>
#include <fstream>

template<class T> 
class LinkedList
{
  public:


    // Constructor
    LinkedList();

    // Copy Constructor
    LinkedList(const LinkedList& other);

    // Deconstructor - deallocates all allocated memory 
    ~LinkedList();

    // Insertion - inserts object into the list
    bool Insert(T* obj);

    // Remove - removes object from list and assigns to result
    bool Remove(T target, T& result); // - Test if removing a non-exist target

    // DeleteList - deletes lists
    void DeleteList();

    // Merge - merges two lists
    bool Merge(LinkedList& list1);

    // Reverse the linkedList in place
    bool Reverse();

    // return a new reverse list
    LinkedList return_reverse();

    // Assignment
    LinkedList& operator=(const LinkedList& other);

    int nth_to_last(int n);

    // Output Operator
    template<typename U>
    friend std::ostream& operator<<(std::ostream& stream, const LinkedList<U>& other);

  private:

    // Struct Node
    struct Node
    {
      T *data;
      Node *next;
    };

    Node* head_; // head pointer
};


/*
Implementation
*/

// Default Constructor sets head_ to nullptr
template<class T>
LinkedList<T>::LinkedList() : head_(nullptr)
{

}

// Copy Constructor set head_ to nullptr and uses assignment operator
template<class T>
LinkedList<T>::LinkedList(const LinkedList& other) : head_(nullptr)
{

}

// Deconstructor calls DeleteList function.
template<class T>
LinkedList<T>::~LinkedList()
{
  DeleteList();
}

// // Inserts object into the list in sorted order and checks for duplicates
template<class T>
bool LinkedList<T>::Insert(T* obj)
{
// Check if valid object
if(obj == nullptr)
{
  return false;
}

  // Allocate new memory for object. Copy given object to new allocated memory
  T* new_obj = new T;
  *(new_obj) = *(obj);

  // Allocate new memory for node. Insert copied object into new allocated node
  Node* new_node = new Node;
  new_node->data = new_obj;
  new_node->next = nullptr;

  // Check if list is empty. Assign head to insert_node
  if(head_ == nullptr)
  {
    head_ = new_node;
    return true;
  }

  // Check for duplicate. Delete allocated memory if duplicate. Return false
  Node* current = head_;
  while(current != nullptr)
  {
    if(*(current->data) == *(new_node->data))
    {
      delete new_obj;
      new_obj = nullptr;
      delete new_node;
      new_node = nullptr;
      return false;
    }
    current = current->next;
  }

  // Check if insert_node is to be inserted first in the list
  if(*(new_node->data) < *(head_->data))
  {
    new_node->next = head_;
    head_ = new_node;
    return true;
  }

  // Traverse list for correct position. Return true.
  current = head_;
  while(current->next != nullptr && *(current->next->data) < *(new_node->data))
  {
    current = current->next;
  }
  new_node->next = current->next;
  current->next = new_node;
  return true;

}

// // Removes object from list. Remeber to return the booleans and delete memory
template<class T>
bool LinkedList<T>::Remove(T target, T& result)
{

// Check if list is empty. Return false
if(head_ == nullptr)
{
return false;
}

// Check if object exists in list. Return false
Node* current = head_;
while(current != nullptr && *(current->data) != target)
{
current = current->next;
}
if(current == nullptr)
{
return false;
}

// Check if object to be removed is the head
if(*(head_->data) == target)
{
	Node* remove_node = head_;
	result = *(remove_node->data);
	head_ = head_->next;
	
	delete remove_node->data;
	remove_node->data = nullptr;
	delete remove_node;
	remove_node = nullptr;
	return true;
}
 // Traverse list for correct node
current = head_;
while(*(current->next->data) != target)
{
	current = current->next;
}

	Node* remove_node = current->next;
	result = *(remove_node->data);
	current->next = current->next->next;
	delete remove_node->data;
	remove_node->data = nullptr;
	delete remove_node;
	remove_node = nullptr;
	return true;

}

// Deletes all objects and nodes from list.
template<class T>
void LinkedList<T>::DeleteList()
{

// Remove all elements and nodes while iterating through the head_
while(head_ != nullptr)
{
Node* remove_node = head_;
head_ = head_->next;
delete remove_node->data;
remove_node->data = nullptr;
delete remove_node;
remove_node = nullptr;
}

}

// Merges this list with list1 without new data allocations. 
template<class T>
bool LinkedList<T>::Merge(LinkedList& list1)
{
  // Check if same lists
  if(this == &list1)
  {
    return false;
  }

  // Check if lists with same nodes
  // if(*this == list1)
  // {
  //   return false;
  // }

  // Check if passed in list is empty
  if(list1.head_ == nullptr)
  {
    return true;
  }
  
  // Check if list being merged is empty
  if(head_ == nullptr)
  {
    head_ = list1.head_;
    list1.head_ = nullptr;
    return true;
  }

  // Create temp Node to store the merged nodes and an iterator node
  Node* merged_list = new Node;
  Node* current = merged_list;

  // Create iterators for this and passed in lists
  Node* ptr1 = head_; // this list iterator
  Node* ptr2 = list1.head_;// passed in list iterator
  
  // Traverse iterators of this and passed in lists checking order
  while(ptr1 != nullptr && ptr2 != nullptr)
  {
    // If one is less than add it to merged node iterators next traverse passed in list
    if(*(ptr1->data) < *(ptr2->data))
    {
      current->next = ptr1;
      ptr1 = ptr1->next;
    }
    else if(*(ptr1->data) > *(ptr2->data))
    {
      current->next = ptr2;
      ptr2 = ptr2->next;
    }
    // Three checks one less, one greater and last means duplicate. Add it one of the list to merged_node current and delete the other node
    else
    {
      current->next = ptr1;
      ptr1 = ptr1->next;
      Node* remove_node = ptr2;
      ptr2 = ptr2->next;
      delete remove_node->data;
      remove_node->data = nullptr;
      delete remove_node;
      remove_node = nullptr;
    }
    current = current->next;
  }

  // Onced traverse one list will not be fully traversed check both if they are traversed. If not traverse and add the remaining nodes
  if(ptr1 != nullptr)
  {
    current->next = ptr1;
  }
  else if(ptr2 != nullptr)
  {
    current->next = ptr2;
  }

  // Assign head to merged_list->next
  head_ = merged_list->next;
  // Delete the dummy node
  delete merged_list;
  list1.head_ = nullptr;
  return true;

}

// Assigns a list to another list
template<class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other)
{
  // Check if the assignment is the same object
  if(this == &other)
  {
    return *this;
  }
  // if(*this == other)
  // {
  //   return;
  // }

  // Empty destination list of elements. This is if the destination has elements in it
  if(head_ != nullptr)
  {
    while(head_ != nullptr)
    {
      Node* remove_node = head_;
      head_ = head_->next;
      delete remove_node->data;
      remove_node->data = nullptr;
      delete remove_node;
      remove_node = nullptr;
    }
  }

  // After clearing the list check if the passed in list is empty. If the passed in list is empty return the empty this list
  if(other.head_ == nullptr)
  {
    return *this;
  }

  // Create a new obj and new node and place into head
  T* new_obj = new T;
  *(new_obj) = *(other.head_->data);

  Node* new_node = new Node;
  new_node->data = new_obj;

  new_node->next = head_;
  head_ = new_node;

  // Iterate through source list and insert the nodes into destination list
  Node* current1 = head_;
  Node* current2 = other.head_->next;
  while(current2 != nullptr)
  {
    T* new_obj = new T;
    *(new_obj) = *(current2->data);

    Node* new_node = new Node;
    new_node->data = new_obj;

    new_node->next = current1->next;
    current1->next = new_node;
    current1 = current1->next;
    current2 = current2->next;
  }

  // Return updated list
  return *this;

}

template<class T>
bool LinkedList<T>::Reverse()
{
  // // Check if list is empty
  if(head_ != nullptr)
  {
    // Create a prev, current, and next node pointers
    Node* prev = nullptr;
    Node* current = head_;
    Node* next = nullptr;
    
    // Iterate through the list and reverse pointers of the list
    while(current != nullptr)
    {
      next = current->next; // initilzie the next
      current->next = prev; // reverse the pointer
      prev = current; // iteratre to the next node
      current = next; // iteratre to the next node
    }
    head_ = prev; // set prev as head
    return true;
  }
}


// template<class T>
// LinkedList<T> LinkedList<T>::return_reverse()
// {
//   LinkedList reversedList;

//   Node* real_head = reversedList.head_;
  
//   Node* current = head_;
//   while(current != nullptr)
//   {
//   current->next =  reversedList.head_; 
//   reversedList.head_ = current;
//   current = current->next;
//   }
//   reversedList.head_ = real_head;
//   return reversedList;
// }




// Output stream operator. Outputs list data to console
template<class T>
std::ostream& operator<<(std::ostream& stream, const LinkedList<T>& other)
{
  // Iterates through list and returns object data to stream
  typename LinkedList<T>::Node* current = other.head_;
  while(current != nullptr)
  {
    stream << *(current->data); 
    current = current->next;                      
  }
  return stream;
}

template<class T>
int LinkedList<T>::nth_to_last(int n) {
  if (head_ == nullptr || n < 0) {
    return -1;
  }

  Node* p1 = head_;
  Node* p2 = head_;

  for (int i = 0; i < n; i++) {
    if (p1 == nullptr) {
      return -1;
    }
    p1 = p1->next;
  }

  while (p1 != nullptr && p1->next != nullptr) {
    p2 = p2->next;
    p1 = p1->next;
  }

  return p2 != nullptr ? p2->data : -1;
}




#endif