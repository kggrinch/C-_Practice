#include <iostream>
#include<map>
#include<string>

struct Edge
{
    std::string endVertex;
    int weight;

    // Overload << to allow printing Edge objects
    friend std::ostream& operator<<(std::ostream& os, const Edge& e)
    {
        os << e.weight;  // Prints only the weight
        return os;
    }
};


int main()
{
    std::map<int, std::string> students;

    // Insert using operator
    students[1] = "Alice";
    students[2] = "Bob";

    // Insert using method
    students.insert({3, "Charlie"});

    // Insert using emplace (preferred for efficiency)
    students.emplace(4, "Davis");

    // Outputting map
    for(const auto& [key, value] : students)
    {
        std::cout << key << ": " << value << "\n";
    }

    // Iterating map using an iterator
    for(auto it = students.begin(); it != students.end(); it++)
    {
        std::cout << it->first << ": " << it->second << "\n";
    }

    // accessing elements
    std::cout << students[2] << '\n';  // Bob
    std::cout << students.at(3) << '\n'; // Charlie (throws exception if key is missing)

    // Checking if an item exists with the specified key. If the key exists, it returns a iterator pointer. If key does not exist it returns a student.end() iterator pointer to the last element
    auto student2_iterator_pointer = students.find(2);
    if(student2_iterator_pointer != students.end())
    {
        std::cout << student2_iterator_pointer->first << ": " << student2_iterator_pointer->second << "\n";
    }
    else
    {
        std::cout << "Key not found " << "\n";
    }

    // Checks how many times the key appears in the map. map only stores unique keys, so this is useful to check if a key exists since it is simpler than find because
    // find returns an iterator but count returns a value.

    // returns an int 1 if key exists
    // returns an int 0 if key does not exist
    std::cout << students.count(2); // ask what it counts

    // erasing elements
    students.erase(2); // erase by key
    students.erase(students.find(3)); // erase by iterator


    // Map as adjacency list
    std::map<std::string, Edge, std::less<std::string>> adjacencyList;
    Edge edge1("B", 10);
    Edge edge2("C", 10);
    Edge edge3("D", 10);

    adjacencyList.insert({"A", edge1});
    adjacencyList.insert({"A", edge2});
    adjacencyList.insert({"B", edge3});
    adjacencyList.insert({"C", edge3});

    adjacencyList.empty();












    return 0;
}
