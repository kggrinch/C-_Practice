#include <iostream>
#include "array_max_heap.h"
#include "array_min_heap.h"

int main()
{
    // Array Max Heap
    // ArrayMaxHeap<int> array_max_heap;
    //
    // array_max_heap.add(5);
    // array_max_heap.add(3);
    // array_max_heap.add(7);
    // array_max_heap.add(2);
    // array_max_heap.add(4);
    // array_max_heap.add(6);
    // array_max_heap.add(8);
    //
    // std::cout <<" array_max_heap.getHeight(): " << array_max_heap.getHeight() << "\n";
    // std::cout <<" array_max_heap.getNumberOfNodes(): " << array_max_heap.getNumberOfNodes() << "\n";
    // std::cout <<" array_max_heap.peekTop(): " << array_max_heap.peekTop() << "\n";
    //
    // array_max_heap.remove();
    // std::cout <<" array_max_heap.peekTop(): " << array_max_heap.peekTop() << "\n";
    //
    // int array[] = {4, 6, 2, 3, 5};
    // ArrayMaxHeap<int> array_max_heap2(array, 5);
    // std::cout <<" array_max_heap2.peekTop(): " << array_max_heap2.peekTop() << "\n";
    // std::cout << "array_max_heap2: ";
    // array_max_heap2.display();

    // Array Min Heap
    // std::cout << "\nArray Min Heap\n";
    // ArrayMinHeap<int> array_min_heap;
    // array_min_heap.add(5);
    // array_min_heap.add(3);
    // array_min_heap.add(7);
    // array_min_heap.add(2);
    // array_min_heap.add(4);
    // array_min_heap.add(6);
    // array_min_heap.add(8);
    // std::cout <<" array_min_heap.getHeight(): " << array_min_heap.getHeight() << "\n";
    // std::cout <<" array_min_heap.getNumberOfNodes(): " << array_min_heap.getNumberOfNodes() << "\n";
    // std::cout <<" array_min_heap.peekTop(): " << array_min_heap.peekTop() << "\n";
    //
    // int array2[] = {4, 6, 2, 3, 5};
    // ArrayMinHeap<int> array_min_heap2(array2, 5);
    // std::cout <<" array_max_heap2.peekTop(): " << array_min_heap2.peekTop() << "\n";
    // std::cout << "array_min_heap2: ";
    // array_min_heap2.display();


    int array[] = {12, 7, 1, 2, 8, 3, 20, 5};
    ArrayMaxHeap<int> array_max_heap1(array, 8), array_max_heap2;
    array_max_heap2.add(12);
    array_max_heap2.add(7);
    array_max_heap2.add(1);
    array_max_heap2.add(2);
    array_max_heap2.add(8);
    array_max_heap2.add(3);
    array_max_heap2.add(20);
    array_max_heap2.add(5);

    std::cout << "heap1 ";
    array_max_heap1.display();
    std::cout << "\n";

    std::cout << "heap2 ";
    array_max_heap2.display();
    std::cout << "\n";

    array_max_heap2.add(25);
    std::cout << "heap2 ";
    array_max_heap2.display();
    std::cout << "\n";

    ArrayMaxHeap<int> a3;
    a3.add(8);
    a3.add(2);
    a3.add(5);
    a3.remove();
    std::cout << "heap3 ";
    a3.display();
    std::cout << "\n";



    return 0;
}
