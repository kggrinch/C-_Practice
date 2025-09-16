#ifndef TRIE_H
#define TRIE_H
#include "trie_node.h"
#include <string>


class Trie
{
public:
    Trie();

    // Method to insert a key into the Trie
    // Time: O(n)
    // Space: O(n)
    void insert(const std::string& key);

    // Method to search a key in the Trie
    // Time: O(n)
    // Space: O(1)
    bool search(const std::string& key);

    // Method to Search Prefix key in Trie
    // Time: O(n)
    // Space: O(1)
    bool isPrefix(std::string &key);


private:
    TrieNode* root;
};



#endif //TRIE_H
