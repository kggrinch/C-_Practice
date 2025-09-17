#include "trie.h"

Trie::Trie()
{
     // This creates a dynamic trienode which will live beyond the scope of the Trie object. Therefore, it need a deconstruct
     root = new TrieNode();

     // If you used a static Trie node then it will live only within the scope of the Trie object. No need for a deconstruct
     // For a static implementation leave the constructor empty.
}

// Deallocate dynamic memory if chosen to use dynamic trienode
Trie::~Trie()
{
     delete root;
}

void Trie::insert(const std::string& key)
{
     TrieNode* cur = root;
     for(char c : key)
     {
          if(!cur->getChild(c)) cur->setChild(c, new TrieNode());
          cur = cur->getChild(c);
     }
     cur->setIsLeaf(true);

}

bool Trie::search(const std::string& key)
{
     if(!root) return false;

     TrieNode* cur = root;
     for(const char& c : key)
     {
          cur = cur->getChild(c);
          if(!cur) return false;
     }
     return cur->getIsLeaf();
}

bool Trie::isPrefix(const std::string& key)
{
     TrieNode* cur = root;
     for(char c : key)
     {
          cur = cur->getChild(c);
          if(!cur) return false;
     }
     return true;
}

std::vector<std::string> Trie::autoComplete(const std::string& key)
{
     TrieNode* cur = root;
     for(char c : key)
     {
          cur = cur->getChild(c);
          if(!cur) return {}; // return empty list if character does not exist
     }
     std::vector<std::string> results;
     collect(cur, key, results);
     return results;
}

void Trie::collect(TrieNode* node, const std::string& key, std::vector<std::string>& results)
{
     if(node->getIsLeaf()) results.push_back(key);

     for(auto entry : node->getChildren())
     {
          char nextChar = entry.first;
          TrieNode* nextNode = entry.second;

          collect(nextNode, key + nextChar, results);
     }
}