#ifndef EDGE_H
#define EDGE_H
#include "vertex.h"

template<class ItemType>
class Edge
{

public:

    Edge(Vertex<ItemType>* start, Vertex<ItemType>* end, double weight = 1.0);

    Vertex<ItemType>* getStart() const;

    Vertex<ItemType>* getEnd() const;

    double getWeight() const;

    bool connects(Vertex<ItemType>* v1, Vertex<ItemType>* v2) const;

private:
    Vertex<ItemType>* start; // Pointer to the starting vertex
    Vertex<ItemType>* end;   // Pointer to the ending vertex
    double weight;
};

#include "edge.cpp"
#endif //EDGE_H
