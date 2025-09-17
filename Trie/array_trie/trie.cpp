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
    root = nullptr;
}

// Method to insert a key into the Trie
    // Time: O(n)
    // Space: O(n)

void Trie::insert(const std::string& key)
{
    // Initialize the curr pointer with the root node
    TrieNode *curr = root;

    // Iterate across the length of the string
    for (char c : key)
    {
        // Check if the node exists for the
        // current character in the Trie
        if (curr->getChild(c - 'a') == nullptr)
        {

            // If node for current character does
            // not exist then make a new node
            TrieNode *newNode = new TrieNode();

            // Keep the reference for the newly
            // created node
            curr->setChild(c - 'a', newNode);
        }

        // Move the curr pointer to the
        // newly created node
        curr = curr->getChild(c - 'a');
    }

    // Mark the end of the word
    curr->setIsLeaf(true);
}

// Method to search a key in the Trie
// Time: O(n)
// Space: O(1)
bool Trie::search(const std::string& key)
{
    if (root == nullptr)
    {
        return false;
    }

    // Initialize the curr pointer with the root node
    TrieNode *curr = root;

    // Iterate across the length of the string
    for (char c : key)
    {

        // Check if the node exists for the
        // current character in the Trie
        if (curr->getChild(c - 'a') == nullptr) return false;

        // Move the curr pointer to the
        // already existing node for the
        // current character
        curr = curr->getChild(c - 'a');
    }

    // Return true if the word exists
    // and is marked as ending
    return curr->getIsLeaf();
}

// Method to Search Prefix key in Trie
// Time: O(n)
// Space: O(1)
bool Trie::isPrefix(std::string &key)
{
    TrieNode *current = root;
    for (char c : key)
    {
        int index = c - 'a';

        // If character doesn't exist, return false
        if (current->getChild(index) == nullptr)
        {
            return false;
        }
        current = current->getChild(index);
    }

    return true;
}