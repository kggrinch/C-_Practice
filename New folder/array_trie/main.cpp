#include <iostream>
#include "trie.h"
#include <vector>

int main()
{
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
