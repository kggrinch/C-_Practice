#include <iostream>
#include <unordered_map>
#include "trie.h"

std::string condition(bool value)
{
    if(value) return "true";
    return "false";

}


int main()
{
    Trie trie;
    std::string word = "hat";
    std::string prefix = "ha";
    trie.insert(word);
    std::cout << condition(trie.search(word)) << "\n";
    std::cout << condition(trie.isPrefix(prefix)) << "\n";

    return 0;
}
