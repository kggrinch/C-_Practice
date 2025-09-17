#ifndef TRIE_H
#define TRIE_H
#include "trie_node.h"
#include <string>
#include <vector>


class Trie
{
public:
    Trie();
    ~Trie();
    void insert(const std::string& key);
    bool search(const std::string& key);
    bool isPrefix(const std::string& key);
    std::vector<std::string> autoComplete(const std::string& key);

private:
    TrieNode* root;

    // Private helper for autoComplete. Collections all words with the given prefix
    void collect(TrieNode* node, const std::string& key, std::vector<std::string>& results);
};



#endif //TRIE_H
