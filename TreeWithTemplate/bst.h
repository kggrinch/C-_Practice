#ifndef BST_H_
#define BST_H_
#include <iostream>

template <class T>
class BST
{
  public:
    // Constructors
    BST(); // default
    BST(BST& other); // copy
    ~BST(); // deconstruct

    // methods
    bool insert(T* obj);
    bool remove(const T& target, T& result); // in-progress
    bool search(const T& target) const;
    int height() const;
    int count() const;
    T max() const;

    template<class U>
    friend std::ostream& operator<<(std::ostream&, const BST<U>& other);

  private:
    // Private node struct
    struct Node
    {
      T* data;
      Node* right;
      Node* left;
    };

    // BST private members
    Node* root_;
    int count_;

    // Private BST methods. This is used for recursion in the main methods
    Node* insert_helper(Node* root, T* obj);
    Node* remove_helper(Node* root, const T& target, T& result);
    bool search_helper(Node* root, const T& target) const;
    T successor(const Node* root) const;
    T predecessor(const Node* root) const;
    const Node* max_helper(const Node* root) const;


    // Might not need these helper methods
    Node* find_min_helper(Node* root) const;
    int height_helper(Node* root) const;
    int count_helper(Node* root) const;
    void copy_tree(Node* root, Node*& target_node);

    // helper tree traverse methods
    void in_order_traversal(Node* root, std::ostream& stream) const; // in-order traversal
    void reverse_in_order_traversal(Node* root, std::ostream& stream) const; // reverse in-order traversal
    void pre_order_traversal(Node* root, std::ostream& stream) const; // pre-order traversal - this has reverse order too
    void post_order_traversal(Node* root, std::ostream& stream) const; // post-order traversal - this has reverse order too
};

template <class T>
BST<T>::BST() : root_(nullptr), count_(0)
{

}

template <class T>
BST<T>::BST(BST& other)
{

}

template <class T>
BST<T>::~BST()
{
  T result;
  while(root_ != nullptr)
  {
    remove(*(root_->data), result);
  }
}

template <class T>
bool BST<T>::insert(T* obj)
{
  // Check if given obj is a nullptr. Return false if true
  if(obj == nullptr)
  {
    return false;
  }

  // Create memory for new obj
  T* new_obj = new T;
  *(new_obj) = *(obj);
  root_ = insert_helper(root_, new_obj);
  return true;
}
template <class T>
typename BST<T>::Node* BST<T>::insert_helper(Node* root, T* obj)
{
  // If tree is empty
  if(root == nullptr)
  {
    count_++;
    Node* new_node = new Node;
    new_node->data = obj;
    new_node->right = nullptr;
    new_node->left = nullptr;
    return new_node;
  }
  
  // If object is less go left
  if(*obj < *(root->data))
  {
    root->left = insert_helper(root->left, obj);
  }
  // If object is greater go right
  else if(*obj > *(root->data))
  {
    root->right = insert_helper(root->right, obj);
  }
  return root; // returns root node
}



template <class T>
bool BST<T>::remove(const T& target, T& result)
{
  root_ = remove_helper(root_, target, result);
  // Check if the target was found
  if(root_ != nullptr)
  {
    count_--;
    return true;
  }
  // if root is a nullptr that means either tree is empty or target not found.
  return false;
}

template<class T>
typename BST<T>::Node* BST<T>::remove_helper(Node* root, const T& target, T& result)
{
  // Original
  // Checks if the tree is empty or at the end of the tree. (target not found)
  if(root == nullptr)
  {
    return root; // returns original node.
  }
  else if(target < *(root->data))
  {
    root->left = remove_helper(root->left, target, result);
  }
  else if(target > *(root->data))
  {
    root->right = remove_helper(root->right, target, result);
  }
  else // node found. Make sure you take into account the memory of the node and the obj inside the node.s
  {
    result = *(root->data);
    // If leaf node
    if(root->left == nullptr && root->right == nullptr)
    {
      delete root->data;
      root->data = nullptr;
      delete root;
      root = nullptr;
    }
    // If not leaf node and has a right child
    else if(root->right != nullptr)
    {
      delete root->data;
      *(root->data) = successor(root); // finds a successor to replace this node
      root->right = remove_helper(root->right, *(root->data), result);
    }
    else
    {
      *(root->data) = predecessor(root); // finds a predecessor to replace this node
      root->left = remove_helper(root->left, *(root->data), result);
    }
  }
  return root;

}

// Finds the least value after moving right once
template<class T>
T BST<T>::successor(const Node* root) const
{
  root = root->right;
  while(root->left != nullptr)
  {
    root = root->left;
  }
  return *(root->data);

}
// Finds the greatest value after moving left once
template<class T>
T BST<T>::predecessor(const Node* root) const
{
  root = root->left;
  while(root->right != nullptr)
  {
    root = root->right;
  }
  return *(root->data);

}

template <class T>    
bool BST<T>::search(const T& target) const
{
  return search_helper(root_, target);
}

template<class T>
bool BST<T>::search_helper(Node* root, const T& target) const
{
  // Check if tree is empty
  if(root == nullptr)
  {
    return false;
  }
  else if(*(root->data) == target)
  {
    return true;
  }
  else if(*(root->data) > target)
  {
    return search_helper(root->left, target);
  }
  else
  {
    return search_helper(root->right, target);
  }
}

template <class T>
int BST<T>::height() const
{
  return -1;
}

template <class T>
int BST<T>::count() const
{
  return -1;
}

template<class T>
T BST<T>::max() const
{
  T data = *(max_helper(root_)->data);
  return data;
}

template<class T>
const typename BST<T>::Node* BST<T>::max_helper(const Node* root) const
{
  // if(root != nullptr)
  // {
  //   if(root->right == nullptr)
  //   {
  //     return root;
  //   }
  //   return max_helper(root->right);
  // }
  // else
  // {
  //   return nullptr;
  // }


  // my implemnetation
  if(root == nullptr)
  {
    return nullptr;
  }
  if(root->right == nullptr)
  {
    return root;
  }
  return max_helper(root->right);

  // Tae's implementation
  // if(root == nullptr)
  // {
  //   return nullptr;
  // }
  // while(root->right != nullptr)
  // {
  //   root = root->right;
  // }
  // return root;



}





template<class T>
std::ostream& operator<<(std::ostream& stream, const BST<T>& other)
{
  bool done = false;
  while(!done)
  {
    int result = -1;
    std::cout << "Enter (0 = in-order | 1 = reverse in-order | 2 = pre-order | 3 = post-order): " ;
    std::cin >> result;
    if(result == 0)
    {
      other.in_order_traversal(other.root_, stream);
      done = true;
    }
    else if(result == 1)
    {
      other.reverse_in_order_traversal(other.root_, stream);
      done = true;
    }
    else if(result == 2)
    {
      other.pre_order_traversal(other.root_, stream);
      done = true;
    }
    else if(result == 3)
    {
      other.post_order_traversal(other.root_, stream);
      done = true;
    }
    else
    {
      std::cout << "Incorrect input. Try again\n";
    }
  }
  return stream;
}

template<class T>
void BST<T>::in_order_traversal(Node* root, std::ostream& stream) const
{
  if(root != nullptr)
  {
    in_order_traversal(root->left, stream);
    stream << *(root->data) << " ";
    in_order_traversal(root->right, stream);
  }
}

template<class T>
void BST<T>::reverse_in_order_traversal(Node* root, std::ostream& stream) const
{
  if(root != nullptr)
  {
    reverse_in_order_traversal(root->right, stream);
    stream << *(root->data) << " ";
    reverse_in_order_traversal(root->left, stream);
  }
}

template<class T>
void BST<T>::pre_order_traversal(Node* root, std::ostream& stream) const
{
  if(root != nullptr)
  {
    std::cout << *(root->data) << " ";
    pre_order_traversal(root->left, stream);
    pre_order_traversal(root->right, stream);
  }
}

template<class T>
void BST<T>::post_order_traversal(Node* root, std::ostream& stream) const
{
  if(root != nullptr)
  {
  post_order_traversal(root->left, stream);
  post_order_traversal(root->right, stream);
  std::cout << *(root->data) << " ";
  }
}




#endif