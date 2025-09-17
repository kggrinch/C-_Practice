#ifndef TRI_NODE_H
#define TRI_NODE_H


// Still needs a deconstructor

class TrieNode
{
public:
    TrieNode();

    TrieNode* getChild(const int& index);
    void setChild(const int& index, TrieNode* node);

    bool getIsLeaf() const;
    void setIsLeaf(bool val);

private:

    // pointer array for child nodes of each node
    TrieNode* children[26];

    // Used for indicating ending of string
    bool isLeaf;
};



#endif //TRI_NODE_H
