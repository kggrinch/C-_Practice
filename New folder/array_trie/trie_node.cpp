#include "trie_node.h"

// initialize the wordEnd variable with false
// initialize every index of childNode array with NULL
TrieNode::TrieNode() : isLeaf(false)
{
    for(auto& i : children)
    {
        i = nullptr;
    }
}

TrieNode* TrieNode::getChild(const int& index)
{
    return children[index];
}

void TrieNode::setChild(const int& index, TrieNode* node)
{
    children[index] = node;
}

bool TrieNode::getIsLeaf() const
{
    return isLeaf;
}

void TrieNode::setIsLeaf(bool val)
{
    isLeaf = val;
}