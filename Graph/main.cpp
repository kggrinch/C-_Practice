#include <iostream>
#include "graph.h"
#include <vector>
#include <algorithm>

#include "simple_graph.h"

template<class ItemType>
void display(ItemType item)
{
    std::cout << item << " ";
}


int main()
{
    // Add vertices first and then connect them with the edge
    Graph<std::string> graph;

    std::vector<std::string> vertices = {"A", "B", "C", "D"};

    for(int i = 0; i < vertices.size(); i++)
    {
        graph.add_vertex(vertices[i]);
    }

    graph.add_edge("A", "B", 1);
    graph.add_edge("A", "C", 1);

    // graph.add_edge("B", "A", 1);
    graph.add_edge("B", "D", 1);

    // graph.add_edge("C", "A", 1);
    graph.add_edge("C", "D", 1);

    // graph.add_edge("D", "B", 1);
    // graph.add_edge("D", "C", 1);

    std::cout << "depthFirstTraversal(A, display): ";
    graph.depthFirstTraversal("A", display);
    std::cout << "\nbreadthFirstTraversal(A, display): ";
    graph.breadthFirstTraversal("A", display);


    int edge_array[][3]  = {
        {0, 1, 1},
        {0, 2, 1},
        {3, 1, 1},
        {3, 2, 1}
    };
    int numEdges = 4;

    std::string v_array[] = {"A", "B", "C", "D"};
    int numVertices = 4;


    Graph<std::string> graph2(v_array, numVertices, edge_array, numEdges);

    std::cout << "\ngraph2.displayAdjacencyMatrix():\n ";
    graph2.displayAdjacencyMatrix();


    // FGraph
    Graph<std::string> g1;

    std::vector<std::string> ver = {"A", "B", "C", "D"};

    for(int i = 0; i < vertices.size(); i++)
    {
        graph.add_vertex(vertices[i]);
    }












    return 0;
}
