#ifndef GRAPH_H
#define GRAPH_H
#include<vector>
#include<queue>
#include<iostream>


template<class ItemType>
class Graph
{
public:

    Graph();

    Graph(ItemType vertices_array[], int number_of_vertices, int edges[][3], int number_of_edges); // int edges[][3] this shows a 2d array with tree spaces like {1, 2, 3}
                                                                                                                                                        //       {4, 5, 6}
    ~Graph();

    int getNumberVertices() const;

    int getNumEdges() const;

    bool add_vertex(ItemType vertex);

    bool add_multiple_vertices(ItemType vertices[]);

    bool add_edge(ItemType start, ItemType end, int edgeWeight); // adds an edge between the two given vertices

    bool remove_edge(ItemType start, ItemType end); // remove an edge between two given verticies

    int getEdgeWeight(ItemType start, ItemType end) const;

    void depthFirstTraversal(ItemType start, void Visit(ItemType&));

    void breadthFirstTraversal(ItemType start, void Visit(ItemType&));

    void displayAdjacencyList() const;

    void displayAdjacencyMatrix() const;


private:
    std::vector<ItemType> vertices;
    std::vector<std::vector<int>> adjMatrix;
    int numVertices;
    int numEdges;

    // Private helper methods
    int getVertexIndex(ItemType vertex) const;

    void depthFirstTraversal_helper(int node_index, std::vector<bool>& visited, void Visit(ItemType&));


};

template<class ItemType>
Graph<ItemType>::Graph() : numVertices(0), numEdges(0)
{

}

// edges[][3] is needed because add edges also takes in the weight {start = 1, end = 2, weight = 1}
template<class ItemType>
Graph<ItemType>::Graph(ItemType vertices_array[], int number_of_vertices, int edges[][3], int number_of_edges) : numVertices(0), numEdges(0)
{
    for(int i = 0; i < number_of_vertices; i++)
    {
        add_vertex(vertices_array[i]); // calling this method would resize the adj matrix
    }

    // adds the edges
    for(int i = 0; i < number_of_edges; i++)
    {
        int start_index = edges[i][0];
        int end_index = edges[i][1];
        int weight = edges[i][2];

        adjMatrix[start_index][end_index] = weight;
        adjMatrix[end_index][start_index] = weight; // this is for a non-directional graph. comment out if directional
        numEdges++;
    }
}

template<class ItemType>
Graph<ItemType>::~Graph()
{

}

template<class ItemType>
int Graph<ItemType>::getNumberVertices() const
{
    return numVertices;
}

template<class ItemType>
int Graph<ItemType>::getNumEdges() const
{
    return numEdges;
}

template<class ItemType>
bool Graph<ItemType>::add_vertex(ItemType vertex)
{
    // Check if the vertex does not exist so there are no duplicates
    int vertex_checker = getVertexIndex(vertex);
    if(vertex_checker == -1)
    {
        vertices.push_back(vertex); // add to the vertex vector
        numVertices++; // increment the number of ver

        // resize the outer vector to add the new vertex
        adjMatrix.resize(numVertices, std::vector<int>(numVertices, 0));

        // resize the inner vector to add the new vertex
        for(std::vector<int>& row : adjMatrix)
        {
            row.resize(numVertices, 0);
        }

        return true;
    }
    return false;
}

template<class ItemType>
bool Graph<ItemType>::add_multiple_vertices(ItemType vertices[])
{

}


// Assuming this method is creating the edges for the vertices
// Given two vertices this method will add a connection to it
template<class ItemType>
bool Graph<ItemType>::add_edge(ItemType start, ItemType end, int edgeWeight)
{
    // Get indexes of the vertices from the vertex vector
    int startIndex = getVertexIndex(start);
    int endIndex = getVertexIndex(end);

    // This checks if the vertices exist
    if(startIndex == -1 || endIndex == -1)
    {
        return false;
    }

    // This checks if the vertices are already connected and edge already exists
    if(adjMatrix[startIndex][endIndex] != 0)
    {
        return false;
    }

    // Adds a connection based on the weight so instead of just adding 1 to show they are connect this method adds the edgeWeight showing that they are connected and how much this connection cost
    adjMatrix[startIndex][endIndex] = edgeWeight; // If you want a directional graph comment out the bottom part. If yoy would like a vertex to connect both ways but be directional then you would
                                                  //  have to call add_edge twice like this add_edge(A, B, 1) and then again for add_edge(B, A, 1)
    adjMatrix[endIndex][startIndex] = edgeWeight; //This part would be added if you want a unidirectional graph. If you add this part you would only need to add the edge once.
                                                 //  EX no need to do add_edge(A, B, 1 ) and add_edge(B, A, 1) but instead just do one of them, and it will automatically generate a non-directional path
    numEdges++; // increments the edges
    return true;
}

template<class ItemType>
bool Graph<ItemType>::remove_edge(ItemType start, ItemType end)
{
    // Get indexes of the vertices from the vertex vector
    int startIndex = getVertexIndex(start);
    int endIndex = getVertexIndex(end);

    // This checks if the vertices exist
    if(startIndex == -1 || endIndex == -1) // This indicates that one or both do not exist
    {
        return false;
    }

    // Check if the edge between the vertices exists
    if (adjMatrix[startIndex][endIndex] == 0) {
        return false; // Edge does not exist
    }

    // Add 0 to show there is no connection between the vertices
    adjMatrix[startIndex][endIndex] = 0;
    numEdges--; // decrement the number of edges
    return true;
}

template<class ItemType>
int Graph<ItemType>::getEdgeWeight(ItemType start, ItemType end) const
{
    int startIndex = getVertexIndex(start);
    int endIndex = getVertexIndex(end);

    // Check if vertices exist
    if(startIndex == -1 || endIndex == -1)
    {
        return -1; // returns -1 indicating error input
    }

    // Do not need to do this because the code under will return 0 indicating that the weight is 0 meaning they are not connected
    // // Check if edges are connected
    // if(adjMatrix[startIndex][endIndex] == 0) // if its 0 that means that the edges are not connected
    // {
    //     return -1; // return -1 indication error input
    // }

    return adjMatrix[startIndex][endIndex];
}

template<class ItemType>
void Graph<ItemType>::depthFirstTraversal(ItemType start, void Visit(ItemType&))
{
    // get the start index from the vertex vector
    int startIndex = getVertexIndex(start);

    // Check if given vertex exists
    if(startIndex == -1) return;

    // Initialize a vector holding booleans which has a size of the number of vertices
    std::vector<bool> visited(numVertices, false); // every vertex is marked false at the start

    // Call recursive helper function
    depthFirstTraversal_helper(startIndex, visited, Visit);
}

template<class ItemType>
void Graph<ItemType>::breadthFirstTraversal(ItemType start, void Visit(ItemType&))
{
    // Get the start node index from vertex vector and check if it exists
    int startIndex = getVertexIndex(start);
    if(startIndex == -1) return;

    // Create a vertex of booleans to indicate whether each vertex has been visited
    std::vector<bool> visited(numVertices, false);

    // Create a queue to hold the vertex that is next to be visited
    std::queue<int> queue;

    // Push the start vertex first in the queue and indicate it as visited
    queue.push(startIndex);
    visited[startIndex] = true;

    while(!queue.empty())
    {
        // Save the current vertex index
        int current_vertex_index = queue.front();
        queue.pop(); // pop the current vertex index from the queue

        // visit the item in the current vertex
        ItemType current_vertex_item = vertices[current_vertex_index];
        Visit(current_vertex_item);

        // Run a for loop to iterate over the values inside the current vertex position
        // ex  0 1 2 3 4
        //   0 0 1 0 1 0
        //   1
        //   2
        // Here current_vertex_index is at 0 and with the for loop we are iterating over the 0's neighbors checking if they are connected and have not been visited.
        // so i = 0, 1, 2, 3, 4
        for(int i = 0; i < numVertices; i++)
        {
            if(adjMatrix[current_vertex_index][i] != 0 && !visited[i])
            {
                queue.push(i); // if vertex has not been visited push next in queue
                visited[i] = true; // mark as visited
            }
        }
    }
}

template<class ItemType>
void Graph<ItemType>::displayAdjacencyMatrix() const
{
    for(int i = 0; i < numVertices; i++)
    {
        for(int j = 0; j < numVertices; j++)
        {
            std::cout << adjMatrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}



// Private helper functions
template<class ItemType>
int Graph<ItemType>::getVertexIndex(ItemType vertex) const
{
    // Traverse the vertex vector and check if the given vertex exist in there and return its index in the vertex vector
    for(int i = 0; i < numVertices; i++)
    {
        if(vertices[i] == vertex)
        {
            return i;
        }
    }
    return -1; // return -1 if the vertex does not exist
}

template<class ItemType>
void Graph<ItemType>::depthFirstTraversal_helper(int vertex_index, std::vector<bool>& visited, void Visit(ItemType&))
{
    // Mark as the given node visited
    visited[vertex_index] = true;

    // Visit the item in the node
    ItemType current_item = vertices[vertex_index];
    Visit(current_item);


    for(int i = 0; i < numVertices; i++)
    {
        // Check all the neighbors of the current node. Check if they have a connection and if they have not been visited yet
        // ex:   0, 1, 2, 3
        //     0 0  1  0 [1]
        // node_index represents 0 and i represents the index of the 0 nodes so i would be at position 3 right under 3 indicating that 0 is connected to 3
        if(adjMatrix[vertex_index][i] != 0 && !visited[i])
        {
            depthFirstTraversal_helper(i, visited, Visit);
        }
    }
}

#endif //GRAPH_H
