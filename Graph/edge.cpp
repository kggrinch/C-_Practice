#ifndef EDGE_CPP_
#define EDGE_CPP_
#include "edge.h"

template<class ItemType>
Edge<ItemType>::Edge(Vertex<ItemType>* start, Vertex<ItemType>* end, double weight) : start(start), end(end), weight(weight)
{

}

template<class ItemType>
Vertex<ItemType>* Edge<ItemType>::getStart() const
{
    return start;
}

template<class ItemType>
Vertex<ItemType>* Edge<ItemType>::getEnd() const
{
    return end;
}

template<class ItemType>
double Edge<ItemType>::getWeight() const
{
    return weight;
}

template<class ItemType>
bool Edge<ItemType>::connects(Vertex<ItemType>* v1, Vertex<ItemType>* v2) const
{
    return (start == v1 && end == v2) || (start == v2 && end == v1);
}

#endif