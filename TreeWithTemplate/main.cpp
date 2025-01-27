#include <iostream>
#include "bst.h"

int main()
{
    BST<int> tree;
    int a, b, c, d, e, f, g, h, i, j, k, l;
    b = 4;
    c = 2;
    d = 6;
    e = 1;
    f = 7;
    g = 3;
    h = 5;


    i = 5;
    j = 2;
    k = 7;
    l = 0;

    // Testing Insert
    tree.insert(&b);
    tree.insert(&c);
    tree.insert(&d);
    tree.insert(&e);
    tree.insert(&f);
    tree.insert(&g);
    tree.insert(&h);
    // tree.insert(&i);
    // tree.insert(&j);
    // tree.insert(&k);
    // tree.insert(&l);

    // Testing display
    std::cout << tree << "\n";

    // Testing search
    std::cout << "tree.search(8): " << tree.search(8) << "\n";
    std::cout << "tree.search(21): " << tree.search(21) << "\n";

    // Testing Remove
    // int removed_item;
    // tree.remove(1, removed_item);
    // std::cout << "removed item: " << removed_item << "\n";
    // tree.remove(6, removed_item);
    // std::cout << "removed item: " << removed_item << "\n";
    // tree.remove(4, removed_item);
    // std::cout << "removed item: " << removed_item << "\n";
    //
    // std::cout << tree << "\n";

    // Testing Remove 2
    BST<int> tree2;
    tree2.insert(&i);
    tree2.insert(&j);
    tree2.insert(&k);

    int result;
    // tree2.remove(5, result);
    // std::cout << "removed item: " << result << "\n";
    // tree2.remove(2, result);
    // std::cout << "removed item: " << result << "\n";
    // tree2.remove(7, result);
    // std::cout << "removed item: " << result << "\n";


    // HW tree problem
    BST<int> tree3;
    a = 26;
    b = 23;
    c = 70;
    d = 5;
    e = 24;
    f = 25;
    g = 7;
    h = 10;

    tree3.insert(&a);
    tree3.insert(&b);
    tree3.insert(&c);
    tree3.insert(&d);
    tree3.insert(&e);
    tree3.insert(&f);
    tree3.insert(&g);
    tree3.insert(&h);

    std::cout << tree3;






    return 0;
}