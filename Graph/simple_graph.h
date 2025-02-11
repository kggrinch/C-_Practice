#ifndef SIMPLE_GRAPH_H
#define SIMPLE_GRAPH_H
#include <vector>
#include "vertex.h"

template<class ItemType>
class SimpleGraph
{
public:

    // Adjacency List
    SimpleGraph();

    ~SimpleGraph();

    int getNumberVertices() const;

    int getNumEdges() const;

    bool add(ItemType start, ItemType end);

    bool remove(ItemType start, ItemType end);

    void depthFirstTraversal(ItemType start, void Visit(ItemType&));

    void breadthFirstTraversal(ItemType start, void Visit(ItemType&));

    void displayAdjacencyList() const;


private:


    void depthFirst_Helper(ItemType node, std::vector<bool>& visited, void Visit(ItemType&));
    Vertex<ItemType>* getVertex(ItemType label) const;
    void clear();

};

// Implementations

template<class ItemType>
SimpleGraph<ItemType>::SimpleGraph()
{

}

template<class ItemType>
SimpleGraph<ItemType>::~SimpleGraph()
{

}

template<class ItemType>
int SimpleGraph<ItemType>::getNumberVertices() const
{

}

template<class ItemType>
int SimpleGraph<ItemType>::getNumEdges() const
{

}

template<class ItemType>
bool SimpleGraph<ItemType>::add(ItemType start, ItemType end)
{

}

template<class ItemType>
bool SimpleGraph<ItemType>::remove(ItemType start, ItemType end)
{

}

template<class ItemType>
void SimpleGraph<ItemType>::depthFirstTraversal(ItemType start, void Visit(ItemType&))
{

}

template<class ItemType>
void SimpleGraph<ItemType>::depthFirst_Helper(ItemType node, std::vector<bool>& visited, void Visit(ItemType&))
{

}

template<class ItemType>
void SimpleGraph<ItemType>::breadthFirstTraversal(ItemType start, void Visit(ItemType&))
{

}

template<class ItemType>
void SimpleGraph<ItemType>::displayAdjacencyList() const
{

}

template<class ItemType>
Vertex<ItemType>* SimpleGraph<ItemType>::getVertex(ItemType label) const
{

}

template<class ItemType>
void SimpleGraph<ItemType>::clear()
{

}





#endif //SIMPLE_GRAPH_H
