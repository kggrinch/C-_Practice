#ifndef DOUBLY_LINKED_LIST_H_
#define DOUBLY_LINKED_LIST_H_
#include <iostream>

template<class T>
class DoublyLinkedList
{

  public:
    DoublyLinkedList();

    DoublyLinkedList(const DoublyLinkedList& other);

    ~DoublyLinkedList();

    bool insert(T* obj);

    bool remove(T target, T& result);

    bool merge(DoublyLinkedList& other);

    bool reverse();

    int RemoveAll(T& target); // Removes all instances of the object

    DoublyLinkedList& operator=(const DoublyLinkedList& other);

    template<class U>
    friend std::ostream& operator<<(std::ostream& stream, DoublyLinkedList<U>& other);

  private:

  struct Node
  {
    T* data;
    Node* next;
    Node* prev;
  };

  Node* head_;
  Node* tail_;
};

template<class T>
DoublyLinkedList<T>::DoublyLinkedList() : head_(nullptr), tail_(nullptr)
{

}

template<class T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& other)
{

}

template<class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
  if(head_ != nullptr)
  {
    Node* remove_node = head_;
    head_ = head_->next;
    if(head_ != nullptr)
    { 
      head_->prev = nullptr;
    }
    
    delete remove_node->data;
    remove_node->data = nullptr;
    remove_node = nullptr;
    remove_node = nullptr;
  }
  head_ = nullptr;
  tail_ = nullptr;
}

template<class T>
bool DoublyLinkedList<T>::insert(T* obj)
{
  // Check if valid obj
  if(obj == nullptr)
  {
    return false;
  }

  // Check if dup. Changed to check final quiz doubly linkedlist implementation
  Node* current = head_;
  while(current != nullptr)
  {
    if(*(current->data) == *(obj))
    {
      return false;
    }
    current = current->next;
  }

  // Allocate new memory
  T* new_obj = new T;
  *(new_obj) = *(obj);
  Node* new_node = new Node;
  new_node->data = new_obj;
  new_node->next = nullptr;
  new_node->prev = nullptr;

  // Check if list is empty
  if(head_ == nullptr)
  {
    head_ = new_node;
    tail_ = new_node;
    return true;
  }

  // Check if head
  if(*(new_node->data) < *(head_->data))
  {
    new_node->next = head_;
    head_->prev = new_node;
    head_ = new_node;
    return true;
  }

  // Check if tail
  if(*(new_node->data) >= *(tail_->data))
  {
    tail_->next = new_node;
    new_node->prev = tail_;
    tail_ = new_node;
    return true;
  }

  current = head_;
  while(current != nullptr && *(current->data) <= *(new_node->data))
  {
    current = current->next;
  }

  new_node->next = current;
  new_node->prev = current->prev;

  current->prev->next = new_node;
  current->prev = new_node;
  return true;



  // T* new_obj = new T;
  // *(new_obj) = *(obj);
  // Node* new_node = new Node;
  // new_node->data = new_obj;
  // new_node->next = nullptr;
  // new_node->prev = nullptr;
  //
  // if (head_ == nullptr)
  //   { // List is empty
  //   head_ = tail_ = new_node;
  // }
  // else {
  //   tail_->next = new_node;
  //   new_node->prev = tail_;
  //   tail_ = new_node;
  // }


}

template<class T>
bool DoublyLinkedList<T>::remove(T target, T& result)
{
  // Check if list is empty
  if(head_ == nullptr)
  {
    return false;
  }

  // Check if item exists in the list
  Node* current = head_;
  while(current != nullptr && *(current->data) != target)
  {
    current = current->next;
  }
  if(current == nullptr)
  {
    return false;
  }

  // Check head
  if(*(head_->data) == target)
  {
    // Iterate to next head
    Node* remove_node = head_;
    head_ = head_->next;
    
    // delete the old head;
    result = *(remove_node->data);
    delete remove_node->data;
    remove_node->data = nullptr;
    delete remove_node;
    remove_node = nullptr;

    // Check if list is empty and set tail to be a nullptr
    if(head_ == nullptr)
    {
      tail_ = nullptr;
    }

    return true; 
  }

  // Check tail
  if(*(tail_->data) == target)
  {
    Node* remove_node = tail_;
    tail_ = tail_->prev;
    tail_->next = nullptr;

    result = *(remove_node->data);
    delete remove_node->data;
    remove_node->data = nullptr;
    delete remove_node;
    remove_node = nullptr;
    return true;
  }

  // Check the rest of the list
  current = head_->next;
  while(*(current->data) != target)
  {
    current = current->next;
  }

  Node* remove_node = current;
  current->prev->next = current->next;
  current->next->prev = current->prev;

  result = *(remove_node->data);
  delete remove_node->data;
  remove_node->data = nullptr;
  delete remove_node;
  remove_node = nullptr;
  return true;

}

template<class T>
bool DoublyLinkedList<T>::merge(DoublyLinkedList<T>& other)
{
  // Check if the same list
  if(this == &other)
  {
    return false;
  }
  // Check if both lists contain the same exact data
  // if(*this == other)
  // {
  //   return false;
  // }
  // Check if passed in list is empty
  if(other.head_ == nullptr)
  {
    return false;
  }
  // Check if this list is empty
  if(head_ == nullptr)
  {
    head_ = other.head_;
    tail_ = other.tail_;
    other.head_ = nullptr;
    other.tail_ = nullptr;
    return true;
  }

  // Dummy node operation
  Node* merged_list = new Node;
  Node* current = merged_list;

  // create two pointers
  Node* ptr1 = head_;
  Node* ptr2 = other.head_;

  // Iteratie through both lists adding items in sorted order into the merged list
  while(ptr1 != nullptr && ptr2 !=  nullptr)
  {
    if(*(ptr1->data) < *(ptr2->data))
    {
      current->next = ptr1;
      current->next->prev = current;
      ptr1 = ptr1->next;
    }
    else if(*(ptr1->data) > *(ptr2->data))
    {
      current->next = ptr2;
      current->next->prev = current;
      ptr2 = ptr2->next;
    }
    else
    {
      current->next = ptr1;
      current->next->prev = current;
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

  // Do the rest of whatever list was not finished
  if(ptr1 != nullptr)
  {
    current->next = ptr1;
    current->next->prev = current;
  }
  else if(ptr2 != nullptr)
  {
    current->next = ptr2;
    current->next->prev = current;
  }

  // Assign head
  head_ = merged_list->next;
  head_->prev = nullptr;

  // assign tail
  current = head_;
  while(current->next != nullptr)
  {
    current = current->next;
  }
  tail_ = current;

  // set pointers to null
  merged_list = nullptr;
  other.head_ = nullptr;
  return true;
}

template<class T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& other)
{
  // Check if the same lists
  if(this == &other)
  {
    return *this;
  }
  // Check if both lists contain the same data
  // if(*this == other)
  // {
  //   return *this;
  // }

  // Clear this list
  while(head_ != nullptr)
  {
    Node* remove_node = head_;
    head_ = head_->next;
    head_->prev = nullptr;
    delete remove_node->data;
    remove_node->data = nullptr;
    delete remove_node;
    remove_node = nullptr;
  }
  tail_ = nullptr;

  // After removeing nodes check if the passed in list is empty. If empty return the new empty list
  if(other.head_ == nullptr)
  {
    return *this;
  }

  // insert new head with new memory
  T* new_obj = new T;
  *(new_obj) = *(other.head_->data);
  Node* new_node = new Node;
  new_node->data = new_obj;
  new_node->next = nullptr;
  new_node->prev = nullptr;

  head_ = new_node;

  // Inser th rest of the items
  Node* current1 = head_;
  Node* current2 = other.head_->next;
  while(current2 != nullptr)
  {
    T* new_obj = new T;
    *(new_obj) = *(current2->data);
    Node* new_node = new Node;
    new_node->data = new_obj;

    new_node->next = current1->next;
    new_node->prev = current1;
    current1->next = new_node;

    current1 = current1->next;
    current2 = current2->next;
  }
  tail_ = current1;

  return *this;
}

template<class T>
int DoublyLinkedList<T>::RemoveAll(T& target)
{
  if(head_ == nullptr)
  {
    return 0;
  }

  int count = 0;

  Node* current = head_;

  while(current != nullptr)
  {
    if(*(current->data) == target)
    {
      Node* remove_node = current;
      current = current->next;

      if(head_ == remove_node)
      {
        head_ = remove_node->next;
        if(head_ != nullptr)
        {
          head_->prev = nullptr;
        }
        else
        {
          tail_ = nullptr;
        }
      }
      else if(tail_ == remove_node)
      {
        tail_ = remove_node->prev;
        if(tail_ != nullptr)
        {
          tail_->next = nullptr;
        }
      }
      else
      {
        remove_node->prev->next = remove_node->next;
        remove_node->next->prev = remove_node->prev;
      }

        delete remove_node->data;
        remove_node->data = nullptr;
        delete remove_node;
        remove_node = nullptr;

      count++;
    }
    else
    {
      current = current->next;
    }
  }
  return count;

}


template<class T>
bool DoublyLinkedList<T>::reverse()
{
  if(head_ == nullptr)
  {
    return false;
  }

  Node* current = head_;
  Node* temp = nullptr; // Temporary node to assist in swapping

  // Iterate through the list and reverse both prev and next pointers
  while(current != nullptr)
  {
    temp = current->prev;
    current->prev = current->next;
    current->next = temp;

    // Move to the next node in the original sequence
    current = current->prev; // Because pointers are swapped, prev is the next node
  }

  // Adjust head and tail pointer and set tail next to nullptr
  temp = head_;
  head_ = tail_;
  tail_ = temp;
  tail_->next = nullptr;
  head_->prev = nullptr;
  return true;
}


template<class T>
std::ostream& operator<<(std::ostream& stream, DoublyLinkedList<T>& other)
{
  typename DoublyLinkedList<T>::Node* current = other.head_;
  while(current != nullptr)
  {
    stream << *(current->data); 
    current = current->next;                      
  }
  return stream;
}



#endif