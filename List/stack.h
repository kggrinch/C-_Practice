#ifndef STACK_H_
#define STACK_H_
#include <iostream>

template<class T>
class Stack
{
  public:
    Stack();
    
    Stack(const Stack& other);

    ~Stack();

    bool push(T* obj);

    bool pop(T& result);

    bool merge(Stack& other);

    Stack& operator=(const Stack& other);

    template<class U>
    friend std::ostream& operator<<(std::ostream& stream, const Stack<U>& other);

  private:
    struct Node
    {
      T* data;
      Node* next;
    };

    Node* head_;
};

template<class T>
Stack<T>::Stack() : head_(nullptr)
{

}

template<class T>    
Stack<T>::Stack(const Stack<T>& other) : head_(nullptr)
{
  *this = other;
}

template<class T>
Stack<T>::~Stack()
{
  T x;
  while(pop(x));
}

template<class T>
bool Stack<T>::push(T* obj)
{
  // Validate obj
  if(obj == nullptr)
  {
    return false;
  }

  // Check for duplicates
  Node* current = head_;
  while(current != nullptr)
  {
    if(*(current->data) == *(obj))
    {
      return false;
    }
    current = current->next;
  }

  // Allocate memory for obj and node
  T* new_obj = new T;
  *(new_obj) = *(obj);
  Node* new_node = new Node;
  new_node->data = new_obj;

  // Insert new_node
  new_node->next = head_;
  head_ = new_node;
  return true;
}

template<class T>
bool Stack<T>::pop(T& result)
{
  // Check if list is empty
  if(head_ == nullptr)
  {
    return false;
  }

  // Delete the head;
  Node* remove_node = head_;
  head_ = head_->next;
  result = *(remove_node->data);
  delete remove_node->data;
  remove_node->data = nullptr;
  delete remove_node;
  remove_node = nullptr;
  return true;
}

template<class T>
bool Stack<T>::merge(Stack& other)
{
  // Check if the same list
  if(this == &other)
  {
    return false;
  }

  // Check if contain the same objects
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
    other.head_ = nullptr;
  }

  // Iteratre through the other list and add to the top of this list
  Node* other_current = other.head_;
  while(other_current != nullptr)
  {
    // Check for dups
    Node* current = head_;
    while(current != nullptr)
    {
      if(*(current->data) == *(other_current->data))
      {
        other_current = other_current->next;
        current = head_;
      }
      current = current->next;
    }

    Node* temp = other_current;
    other_current = other_current->next;
    temp->next = head_;
    head_ = temp;
  }
  other.head_ = nullptr;

  return true;
}

template<class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other)
{

  // Check if same lists
  if(this == &other)
  {
    return *this;
  }
  
  // Clear this from data
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

  // You would do this part like you would in a single linkedList because you want to maintain the same order as the other list
  T* new_obj = new T;
  *(new_obj) = *(other.head_->data);
  Node* new_node = new Node;
  new_node->data = new_obj;
  new_node->next = nullptr;

  head_ = new_node;

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

    current2 = current2->next;
    current1 = current1->next;
  }

  return *this;
}

template<class T>
std::ostream& operator<<(std::ostream& stream, const Stack<T>& other)
{
  typename Stack<T>::Node* current = other.head_;
  while(current != nullptr)
  {
    stream << *(current->data); 
    current = current->next;                      
  }
  return stream;
}


#endif