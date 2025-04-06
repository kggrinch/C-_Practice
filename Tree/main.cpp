#include<iostream>

#include "avl_tree.h"
#include "binary_tree.h"
#include "binary_node.h"
#include "binary_search_tree.h"
#include "two_three_tree.h"

template<class T>
void display(T& item)
{
  std::cout << item << " ";
}

int main()
{
  // Binary Tree
  BinaryTree<int> binary_tree;
  binary_tree.add(5);
  binary_tree.add(4);
  binary_tree.add(3);
  binary_tree.add(2);

  binary_tree.inorderTraverse(display);

  // Binary Search Tree
  std::cout << "\nbinary search tree\n ";
  BinarySearchTree<int> binary_search_tree;
  binary_search_tree.add(5);
  binary_search_tree.add(3);
  binary_search_tree.add(7);
  binary_search_tree.add(2);
  binary_search_tree.add(4);
  binary_search_tree.add(6);
  binary_search_tree.add(8);

  binary_search_tree.inorderTraverse(display);
  std::cout << "\nbinary_search_tree.Max(): " << binary_search_tree.Max() << "\n";

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

  // AVL Tree
  std::cout << "\nAVL Tree\n";
  AVL_Tree<int> avl_tree;
  avl_tree.add(1);
  avl_tree.add(2);
  avl_tree.add(3);
  avl_tree.add(4);
  avl_tree.add(5);
  avl_tree.add(6);
  avl_tree.add(7);
  avl_tree.add(8);
  avl_tree.add(9);
  avl_tree.add(10);
  std::cout << "avl tree height: " << avl_tree.getHeight() << "\n";

  BinarySearchTree<int> bst1, balanced_bst2;
  bst1.add(1);
  bst1.add(2);
  bst1.add(3);
  bst1.add(4);
  bst1.add(5);
  bst1.add(6);
  bst1.add(7);
  bst1.add(8);
  bst1.add(9);
  bst1.add(10);
  std::cout << "bst1 tree height: " << bst1.getHeight() << "\n";

  balanced_bst2.add(6);
  balanced_bst2.add(3);
  balanced_bst2.add(8);
  balanced_bst2.add(2);
  balanced_bst2.add(9);
  balanced_bst2.add(4);
  balanced_bst2.add(7);
  balanced_bst2.add(10);
  balanced_bst2.add(5);
  balanced_bst2.add(1);
  std::cout << "balanced bst2 height: " << balanced_bst2.getHeight() << "\n";

  // avl_tree.remove(10);
  // avl_tree.remove(9);
  // avl_tree.remove(2);
  // avl_tree.remove(3);

  // avl_tree.remove(1);
  // avl_tree.remove(3);

  avl_tree.remove(1);
  avl_tree.remove(10);
  std::cout << "avl tree height: " << avl_tree.getHeight() << "\n";


  // 2-3 Tree
  TwoThreeTree<int> two_tree_tree;

  // Test passed
  // two_tree_tree.add(50);
  // two_tree_tree.add(60);
  // two_tree_tree.add(70);
  // two_tree_tree.add(40);
  // two_tree_tree.add(30);
  // two_tree_tree.add(20);
  // two_tree_tree.add(15);

  // Test passed
  // two_tree_tree.add(27);
  // two_tree_tree.add(33);
  // two_tree_tree.add(8);
  // two_tree_tree.add(15);
  // two_tree_tree.add(75);
  // two_tree_tree.add(20);
  // two_tree_tree.add(95);
  // two_tree_tree.add(37);
  // two_tree_tree.add(36);
  //
  // two_tree_tree.add(94);
  // two_tree_tree.add(31);
  // two_tree_tree.add(41);
  // two_tree_tree.add(26);
  // two_tree_tree.add(81);
  //
  //
  // two_tree_tree.add(10);
  // two_tree_tree.add(58);
  // two_tree_tree.add(32);

  // Checking every child push
  // two_tree_tree.add(50);
  // two_tree_tree.add(60);
  // two_tree_tree.add(70);

  // Checking push up from left child small (root 2node)
  // two_tree_tree.add(40);
  // two_tree_tree.add(30);

  // Checking push up from left child middle (root 2node)
  // two_tree_tree.add(55);
  // two_tree_tree.add(52);

  // Checking push up from left large
  // two_tree_tree.add(40);
  // two_tree_tree.add(55);

  // Checking push from the right child large (root 2node)
  // two_tree_tree.add(80);
  // two_tree_tree.add(90);

  // Checking push from right child middle (root 2node)
  // two_tree_tree.add(65);
  // two_tree_tree.add(68);

  // Checking push from right child small (root 2node)
  // two_tree_tree.add(80);
  // two_tree_tree.add(65);

  // Checking push from left child small (root 3node)
  // two_tree_tree.add(40);
  // two_tree_tree.add(30);
  // two_tree_tree.add(20);
  // two_tree_tree.add(25);

  // Checking push from middle child small (root 3node)
  // two_tree_tree.add(40);
  // two_tree_tree.add(30);
  // two_tree_tree.add(55);
  // two_tree_tree.add(52);

  // Checking push from right child small (root 3node)
  // two_tree_tree.add(40);
  // two_tree_tree.add(30);
  // two_tree_tree.add(90);
  // two_tree_tree.add(80);

  // Checking push from left-left (not-leaf 2node)
  // two_tree_tree.add(40);
  // two_tree_tree.add(30);
  // two_tree_tree.add(20);
  // two_tree_tree.add(25);
  // two_tree_tree.add(10);
  // two_tree_tree.add(15);

  // Checking push from left-right not-leaf (not-leaf 2node)
  // two_tree_tree.add(40);
  // two_tree_tree.add(30);
  // two_tree_tree.add(20);
  // two_tree_tree.add(25);
  // two_tree_tree.add(35);
  // two_tree_tree.add(32);

  // Checking push from right-right not-leaf (not-leaf 2node)
  // two_tree_tree.add(40);
  // two_tree_tree.add(30);
  // two_tree_tree.add(20);
  // two_tree_tree.add(25);
  // two_tree_tree.add(65);
  // two_tree_tree.add(68);

  // Checking push from right-right not-leaf (not-leaf 2node)
  // two_tree_tree.add(40);
  // two_tree_tree.add(30);
  // two_tree_tree.add(20);
  // two_tree_tree.add(25);
  // two_tree_tree.add(45);
  // two_tree_tree.add(55);

  // Checking push from left-middle (not-leaf 3node)
  // two_tree_tree.add(40);
  // two_tree_tree.add(30);
  // two_tree_tree.add(20);
  // two_tree_tree.add(25);
  // two_tree_tree.add(10);
  // two_tree_tree.add(15);
  // two_tree_tree.add(23);
  // two_tree_tree.add(22);

  // Checking push from right middle (not-leaf 3node)
  // two_tree_tree.add(40);
  // two_tree_tree.add(30);
  // two_tree_tree.add(20);
  // two_tree_tree.add(25);
  // two_tree_tree.add(45);
  // two_tree_tree.add(55);
  // two_tree_tree.add(57);
  // two_tree_tree.add(56);

  // Checking push from middle-middle (not-leaf 3node)
  // two_tree_tree.add(40);
  // two_tree_tree.add(30);
  // two_tree_tree.add(20);
  // two_tree_tree.add(25);
  // two_tree_tree.add(45);
  // two_tree_tree.add(55);
  // two_tree_tree.add(57);
  // two_tree_tree.add(56);
  // two_tree_tree.add(47);
  // two_tree_tree.add(46);

  // Checking push from middle-middle-middle (not-leaf 3node) (root 3node)
  // two_tree_tree.add(40);
  // two_tree_tree.add(30);
  // two_tree_tree.add(20);
  // two_tree_tree.add(25);
  // two_tree_tree.add(45);
  // two_tree_tree.add(55);
  // two_tree_tree.add(57);
  // two_tree_tree.add(56);
  // two_tree_tree.add(47);
  // two_tree_tree.add(46);
  // two_tree_tree.add(49);
  // two_tree_tree.add(48);

  // Quick check
  // two_tree_tree.add(50);
  // two_tree_tree.add(60);
  // two_tree_tree.add(70);
  // two_tree_tree.add(40);
  // two_tree_tree.add(80);
  // two_tree_tree.add(45);
  // two_tree_tree.add(30);
  // two_tree_tree.add(55);
  // two_tree_tree.add(75);



  // All tests passed from here


  // Testing Remove

  // Testing remove from root when leaf

  // Testing root leaf remove two node (one element)
  // two_tree_tree.add(1);
  // two_tree_tree.remove(1);

  // Testing root leaf remove three node (two elements)
  // two_tree_tree.add(1);
  // two_tree_tree.add(2);

  // remove small item first then large
  // two_tree_tree.remove(1);
  // two_tree_tree.remove(2);

  // remove large item first than small
  // two_tree_tree.remove(2);
  // two_tree_tree.remove(1);

  // Remove test right and left child and root on leaf two node (root is two node)
  // Height 2
  two_tree_tree.add(50);
  two_tree_tree.add(60);
  two_tree_tree.add(70);
  // two_tree_tree.remove(70);
  // two_tree_tree.remove(50);
  // two_tree_tree.remove(60);

  // root with two leaf children that are both three nodes (two elements)
  // Height 2 with more nodes
  two_tree_tree.add(40);
  two_tree_tree.add(80);
  // two_tree_tree.remove(40);
  // two_tree_tree.remove(70);
  // two_tree_tree.remove(60);

  // redistructre to right remove from rigth chidl
  // two_tree_tree.remove(60);
  // two_tree_tree.remove(70);

  // redistribute to left remove from left child
  // two_tree_tree.remove(40);
  // two_tree_tree.remove(50);


  // Test with root being a three node and has three children.
  two_tree_tree.add(45);
  // two_tree_tree.add(55);
  // two_tree_tree.add(30);

  // remove left child
  // two_tree_tree.remove(40);

  // remove middle child
  // two_tree_tree.remove(50);

  // remove right child
  // two_tree_tree.remove(70);
  // two_tree_tree.remove(80);

  // remove roots
  // two_tree_tree.remove(45);
  // two_tree_tree.remove(60);

  // further root removal
  // two_tree_tree.remove(70);

  // height 3 tree - This needs to be worked on more
  two_tree_tree.add(30);
  two_tree_tree.add(55);
  two_tree_tree.add(75);

  // two_tree_tree.remove(75);
  two_tree_tree.remove(75);

  TwoThreeTree<int> t2;

  t2.add(10);
  t2.add(100);
  t2.add(30);
  t2.add(80);
  t2.add(50);

  t2.remove(10);

  t2.add(60);
  t2.add(70);
  t2.add(40);

  t2.remove(80);

  t2.add(90);
  // t2.add(20);
  t2.inorderTraverse(display); std::cout << "\n";
  t2.preorderTraverse(display); std::cout << "\n";
  t2.postorderTraverse(display); std::cout << "\n";



  // t2.remove(30); // Fails after this
  // t2.remove(70);


  // Final Trees

  BinarySearchTree<int> bst3;
  AVL_Tree<int> avlT1;
  TwoThreeTree<int> ttt1;

  // A
  bst3.add(13);
  bst3.add(17);
  bst3.add(35);
  bst3.add(11);
  bst3.add(7);
  bst3.add(3);
  bst3.add(29);
  bst3.add(15);
  bst3.add(16);
  bst3.inorderTraverse(display); std::cout << "\n";

  avlT1.add(13);
  avlT1.add(17);
  avlT1.add(35);
  avlT1.add(11);
  avlT1.add(7);
  avlT1.add(3);
  avlT1.add(29);
  avlT1.add(15);
  avlT1.add(16);


  return 0;
}