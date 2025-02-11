#include<iostream>
#include "binary_tree.h"
#include "binary_node.h"
#include "binary_search_tree.h"

template<class T>
void display(T& item)
{
  std::cout << item << " ";
}

int main()
{
  BinaryTree<int> binary_tree;
  binary_tree.add(5);
  binary_tree.add(4);
  binary_tree.add(3);
  binary_tree.add(2);

  binary_tree.inorderTraverse(display);

  std::cout << "\nbinary search tree\n ";
  // BinarySearchTree<int> binary_search_tree;
  // binary_search_tree.add(5);
  // binary_search_tree.add(3);
  // binary_search_tree.add(7);
  // binary_search_tree.add(2);
  // binary_search_tree.add(4);
  // binary_search_tree.add(6);
  // binary_search_tree.add(8);
  //
  // binary_search_tree.inorderTraverse(display);
  // std::cout << "\nbinary_search_tree.Max(): " << binary_search_tree.Max() << "\n";

  BinarySearchTree<int> binary_search_tree2;
  binary_search_tree2.add(29);
  binary_search_tree2.add(15);
  binary_search_tree2.add(16);
  binary_search_tree2.add(10);
  binary_search_tree2.add(12);
  binary_search_tree2.add(13);
  binary_search_tree2.add(17);
  binary_search_tree2.add(35);
  binary_search_tree2.add(11);
  binary_search_tree2.add(7);
  binary_search_tree2.add(3);
  binary_search_tree2.postorderTraverse(display);



  return 0;
}