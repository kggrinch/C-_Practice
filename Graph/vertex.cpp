#ifndef VERTEX_CPP_
#define VERTEX_CPP_
#include "vertex.h"

template<class ItemType>
Vertex<ItemType>::Vertex(ItemType value) : label(value)
{

}
template<class ItemType>
ItemType Vertex<ItemType>::getLabel() const
{
    return label;
}
template<class ItemType>
void Vertex<ItemType>::addNeighbor(Vertex<ItemType>* neighbor)
{
    neighbors.push_back(neighbor);
}
template<class ItemType>
const std::vector<Vertex<ItemType>*>& Vertex<ItemType>::getNeighbors() const
{
    return neighbors;
}
template<class ItemType>
bool Vertex<ItemType>::isConnectedTo(const Vertex<ItemType>* other) const
{
    for (const auto& neighbor : neighbors) {
        if (neighbor == other) {
            return true;
        }
    }
    return false;
}

#endif
