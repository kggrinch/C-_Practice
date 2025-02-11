#ifndef VERTEXT_H
#define VERTEXT_H
#include <vector>

template<class ItemType>
class Vertex
{
public:

    Vertex(ItemType value);

    ItemType getLabel() const;

    void addNeighbor(Vertex<ItemType>* neighbor);

    const std::vector<Vertex<ItemType>*>& getNeighbors() const;

    bool isConnectedTo(const Vertex<ItemType>* other) const;

private:
    ItemType label;  // The value of the vertex
    std::vector<Vertex<ItemType>*> neighbors;

};

#include "vertex.cpp"
#endif //VERTEXT_H
