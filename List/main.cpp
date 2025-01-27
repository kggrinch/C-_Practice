#include <iostream>
#include "linkedList.h"
#include "stack.h"
#include "doublyLinkedList.h"

int main()
{
  LinkedList<int> list;
  int a, b, c, d, e, f, g;
  a = 1;
  b = 2;
  c = 3;
  d = 4;
  e = 5;
  f = 6;
  g = 7;

  list.Insert(&c); // 3
  list.Insert(&b); // 2 3
  list.Insert(&e); // 2 3 5
  list.Insert(&d); // 2 3 4 5
  std::cout << "Insert: " << list << "\n";

  // list.DeleteList();
  // std::cout << "List after list.DeleteList(): " << list << "\n"; 
  // list.DeleteList();

  // int x;
  // list.Remove(g, x);
  // std::cout << "Removed: 7" << x << "\n";
  // list.Remove(e, x);
  // std::cout << "Removed: " << x << "\n";
  // list.Remove(c, x);
  // std::cout << "Removed: " << x << "\n";
  // list.Remove(b, x);
  // std::cout << "Removed: " << x << "\n";
  // list.Remove(d, x);
  // std::cout << "Removed: " << x << "\n";
  // list.Remove(g, x);
  // std::cout << "Removed: 7" << x << "\n";
  // std::cout <<"list after removing all elements: " << list << "\n";
  

  // Merge
  LinkedList<int> list2;
  int h, i, j, k, l, m, n, o, p, q, r;
  o = 0;
  h = 1;
  i = 7;
  k = 8;
  l = 9;
  m = 10;
  n = 11;
  p = 12;
  q = 13;
  r = 14;

  list.Merge(list2);
  std::cout << "list1: " << list << "\n";

  list2.Insert(&h);
  list.Merge(list2);
  std::cout << "list1: " << list << "\n";

  list2.Insert(&h);
  list2.Insert(&h);
  list2.Insert(&i);
  list2.Insert(&k);
  list2.Insert(&l);
  list2.Insert(&m);
  list2.Insert(&n);
  list2.Insert(&o);
  list2.Insert(&p);
  list2.Insert(&q);
  list2.Insert(&r);
  std::cout <<"list2: " <<list2 << "\n";
  list.Merge(list2);
  std::cout << "list1: " << list << "\n"; 
  std::cout << "list2: " << list2 << "\n";

  list2.Insert(&k);
  list2 = list;
  std::cout << "list2: " << list2 << "\n";
  std::cout << "list: " << list << "\n";

  list2.Reverse();
  std::cout <<"list2 reverse: " << list2 << "\n";

  // LinkedList<int> list3;
  // list3 = list2.return_reverse();
  // std::cout << "list3: " << list3 << "\n";

  LinkedList<int> list4, list5;
  list4 = list5;

  // Stack List
  Stack<int> stack;
  int s, t, u, v, w;
  s = 1;
  t = 2;
  u = 3;
  v = 4;
  w = 5;

  // push
  stack.push(&s);
  stack.push(&t);
  stack.push(&u);
  stack.push(&v);
  stack.push(&w);
  stack.push(&s); // check for dup

  std::cout << "Stack.push(): " << stack << "\n";

  // pop
  stack.pop(w);
  std::cout << "stack.pop: should be 5: " << w << "\n";
  std::cout << "stack after stack.pop(): " << stack << "\n";

  // merge
  Stack<int> stack2;
  // int x, y, z;
  // x = 6;
  // y = 7;
  // z = 3;
  // stack2.push(&x);
  // stack2.push(&y);
  // stack2.push(&z);

  stack.merge(stack2);
  std::cout << "stack after stack.merge(stack2): " << stack << "\n";
  std::cout << "stacl2 after stack.merge(stacl2): " << stack2 << "\n";

  stack2 = stack;
  std::cout << "stack2 after stack2 = stack: " << stack2 << "\n";


  // Doubly LinkedList
  
  // Insertion
  DoublyLinkedList<int> doublyLinkedList;
  int aa, bb, cc, dd;
  aa = 1;
  bb = 2;
  cc = 3;
  dd = 4;

  // Insertion
  doublyLinkedList.insert(&cc);
  doublyLinkedList.insert(&dd);
  doublyLinkedList.insert(&aa);
  doublyLinkedList.insert(&bb);
  doublyLinkedList.insert(&cc);
  std::cout << "doublyLinkedList.insert(): " << doublyLinkedList << "\n";



  // Remove
  // doublyLinkedList.remove(cc, ee);
  // std::cout << "removed: " << ee << "\n";
  // std::cout << "doublyLinkedList after remove: " << doublyLinkedList << "\n";

  // doublyLinkedList.remove(bb, ee);
  // std::cout << "removed: " << ee << "\n";
  // std::cout << "doublyLinkedList after remove: " << doublyLinkedList << "\n";

  // doublyLinkedList.remove(aa, ee);
  // std::cout << "removed: " << ee << "\n";
  // std::cout << "doublyLinkedList after remove: " << doublyLinkedList << "\n";

  // doublyLinkedList.remove(dd, ee);
  // std::cout << "removed: " << ee << "\n";
  // std::cout << "doublyLinkedList after remove: " << doublyLinkedList << "\n";

  // doublyLinkedList.remove(cc, ee);
  // std::cout << "removed: " << ee << "\n";
  // std::cout << "doublyLinkedList after remove: " << doublyLinkedList << "\n";

  // Merge
  DoublyLinkedList<int> doublyLinkedList2;
  int ff, gg;
  ff = 5;
  gg = 6;
  doublyLinkedList2.insert(&ff);
  doublyLinkedList2.insert(&gg);

  doublyLinkedList.merge(doublyLinkedList2);
  std::cout << "list1 after doublyLinkedList.merge(doublyLinkedList2): " << doublyLinkedList << "\n";
  std::cout << "list2 after doublyLinkedList.merge(doublyLinkedList2): " << doublyLinkedList2 << "\n";

  // assignment operator
  // doublyLinkedList2 = doublyLinkedList;
  // std::cout << "list2 after doublyLinkedList2 = doublyLinkedList: " << doublyLinkedList2 << "\n";

  DoublyLinkedList<int> doublyLinkedList3;
  doublyLinkedList3 = doublyLinkedList2;
  std::cout << "list3 after doublyLinkedList3 = doublyLinkedLis2: " << doublyLinkedList3 << "\n";

  doublyLinkedList3 = doublyLinkedList;
  std::cout << "list3 after doublyLinkedList3 = doublyLinkedList: " << doublyLinkedList3 << "\n";

  doublyLinkedList.reverse();
  std::cout << "list2 after reverse: " << doublyLinkedList << "\n";


  // Final quiz doubly linkedlist check

  DoublyLinkedList<int> list3;
  int qq, ww, ee, rr, tt, yy, uu;
  qq = 1;
  ww = 2;
  ee = 3;
  rr = 1;
  tt = 4;
  yy = 5;
  uu = 1;

  list3.insert(&qq);
  list3.insert(&ww);
  list3.insert(&ee);
  list3.insert(&rr);
  list3.insert(&tt);
  list3.insert(&yy);
  list3.insert(&uu);
  std::cout << "list3 with duplicates: " << list3 << "\n"; 

  list3.RemoveAll(qq);
  std::cout << "list3 after removeAll: " << list3 << "\n";









}