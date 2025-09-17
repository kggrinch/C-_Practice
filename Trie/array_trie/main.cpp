#include <iostream>
#include "trie.h"
#include <vector>

int main()
{
    // An array of 5 pointers
    int a = 5;
    int* int_pointer[5];
    int_pointer[0] = &a;

    std::cout << "int_pointer: " << int_pointer << "\n"; // Prints the address of the array
    std::cout << "*int_pointer: " << *int_pointer << "\n"; // Prints the address of pointer in the [0] since the array decays to the first element
    std::cout << "int_pointer[0]: " << int_pointer[0] << "\n"; // Same as the top returns address of the pointer in [0]
    std::cout << "*int_pointer[0]: " << *int_pointer[0] << "\n"; // Returns the garbage int in the first element after dereferencing the first pointer


    // Create am example Trie
    Trie trie1;
    std::vector<std::string> arr = {"and", "ant", "do", "dad"};
    for (const std::string &s : arr)
    {
        trie1.insert(s);
    }

    // One by one search strings
    std::vector<std::string> searchKeys = {"do", "gee", "bat"};
    for (std::string &s : searchKeys){

        if(trie1.search(s))
            std::cout << "true ";
        else
            std::cout << "false ";
    }
    std::cout<<"\n";

    // One by one search for prefixes
    std::vector<std::string> prefixKeys = {"ge", "ba", "do", "de"};
    for (std::string &s : prefixKeys){

        if (trie1.isPrefix(s))
            std::cout << "true ";
        else
            std::cout << "false ";
    }

    return 0;
}
