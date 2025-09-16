#include <iostream>      // I/O streams (used for printing and reading to console)
#include <algorithm>     // algorithms library that can be used on the ADTs

#include <string>        // String
#include <vector>        // vector
#include <list>          // LinkedList - doubly
#include <stack>         // Stack
#include <deque>         // doubly ended queue
#include <queue>         // normal queue and can also be used to initialize priority queue
#include <unordered_map> // Map dictionary implemented using hashing (has no order of element retrieval)
#include <map>           // Map dictionary implemented using a balance tree (red and black tree) (has order of element retrieval)
#include <unordered_set> // Set dictionary implemented using hashing (has order to elements)
#include <set>           // Set dictionary implemented using balance tree (red and black tree)
#include <utility>       // Pair

/*
 * Data Structure
 ? Sub_Data Structure or functionality/use-cases
 ! sub_functionality/use-cases
 */


template<class ItemType>
void print(ItemType list)
{
  for(auto& v : list)
  {
    std::cout << v << " ";
  }
  std::cout << "\n";
}



int main()
{
  /**
  * Strings
  * Exmplanation: A string is made up of individual character data types stored as an array that can be manipulated.
  */
  std::string s = "Hello";

  // Appending strings
  s += " World!"; // s is now "Hello World!"
  std::cout << "s: " << s << "\n";

  // retrieving the length of a string
  int length = s.length();
  std::cout << "s length: " << length << "\n";

  // Retrieving a character at a specific index of a string
  char c = s.at(0); // retrieves the first char in the string (h);
  std::cout << "s.at(0): " << c << "\n";

  // Retrieves the substring of the string
  // This works like this:
  // String: Hello World! - it has 11 character including the blank space in the middle
  // s.substr(6, 5) - says get the first character at position 6 and build the rest of the string until we reach a string of 5 characters
  std::string sub_string_s = s.substr(6, 5);
  std::cout << "s.substr(0, 5): " << sub_string_s << "\n";

  // Retrieves the first index occurrence of the given string
  int index = s.find("ld!");
  std::cout << "s.find(ld!): " << index << "\n";

  // Inserts text at a given index
  s.insert(5, " |");
  std::cout << "s.insert(5, |) on s: " << s << "\n";

  // replace part of a substring
  s.replace(8, 12, "User!");
  std::cout << "s.replace(8, 11, User) on s: " << s << "\n";

  // erase part of a substring
  s.erase(0, 8);
  std::cout << "s.erase(0, 7) on s: " << s << "\n";
  std::cout << s.length() << "\n";

  // Check if s is empty
  bool yes = s.empty();
  std::cout << "s.empty() 1=true | 0=false: " << yes << "\n";

  // Saving all characters into an array and printing from the array
  char c_array[s.length()];
  for(int i = 0; i < s.length(); i++)
  {
    c_array[i] = s[i];
  }
  std::cout << "Saving and printing all characters in the string from an array\n";
  for(auto& ch : c_array)
  {
    std::cout << ch << " ";
  }
  std::cout << "\n";

  // Clear string
  s.clear();
  std::cout << "s.clear(): " << s << "\n";


  /**
  * Arrays
  * Explanation: An array holds a raw data type list of elements. Arrays can be dynamic or static
  *
  */
  std::cout << "\nArrays\n";

  // Static array initialization
  int i_a[] = {1, 2, 3, 4, 5};
  char c_a[] = {'H', 'e', 'l', 'l', 'o'};

  // array with declared size
  std::string s_a[5];
  s_a[0] = "Hi";
  s_a[1] = "Hello";
  s_a[2] = "Bonjour";
  s_a[2] = "Prevet";
  s_a[4] = "Ola";

  // Dynamic array initialization
  int* dynamic_i_a = new int[5];
  std::string* dynamic_s_a = new std::string[5];
  char* dynamic_c_a = new char[5];

  // filling in dynamic arrays
  for(int i = 0; i < 5; ++i)
  {
    dynamic_i_a[i] = i; // fills dynamic array with i iterator ints
    dynamic_s_a[i] = "DynamicHello5"; // fills dynamic array with 5 "DynamicHello5" strings
    dynamic_c_a[i] = '5'; // fills dynamic array with 5 '5' characters
  }

  // Printing individual values in array
  int arr[] = {1, 2, 3};
  int* ptr = arr;
  std::cout << ptr[1] << "\n"; // This prints 2

  // array iteration with for-loop
  std::cout << "\nArray Iteration " << std::endl;
  for(int i = 0; i < 5; i++)
  {
    std::cout << "i_a[i]: " << i_a[i] << "\n";
    std::cout << "s_a[i]: " << s_a[i] << "\n";
    std::cout << "c_a[i]: " << c_a[i] << "\n";
    std::cout << "dynamic_i_a[i]: " << dynamic_i_a[i] << "\n";
    std::cout << "dynamic_s_a[i]: " << dynamic_s_a[i] << "\n";
    std::cout << "dynamic_c_a[i]: " << dynamic_c_a[i] << "\n";
  }

  // Array iteration For each-loop
  std::cout  << "\nArray Iteration (for each-loop)" << std::endl;
  for(auto each : i_a)
  {
    std::cout  << each << std::endl;
  }

  // delete allocated memory in dynamic arrays
  delete[] dynamic_i_a;
  delete[] dynamic_s_a;
  delete[] dynamic_c_a;
  dynamic_i_a = nullptr;
  dynamic_s_a = nullptr;
  dynamic_c_a = nullptr;


  //? 2D Array

  int row_size = 3;
  int column_size = 3;

  // In a 2D array the size must be declared before initialization
  int twoD_array[row_size][column_size] = {
    {1, 2, 3}, // [0][1] = 1
    {4, 5, 6}, // [1][1] = 5
    {7, 8, 9} // [2][2] = 8
  };

  // Iterating through a 2D array
  std::cout  << "\nArray Iteration (2D array)" << std::endl;
  for(int i = 0; i < column_size; ++i)
  {
    for(int j = 0; j < row_size; ++j)
    {
      std::cout << twoD_array[i][j] << " ";
    }
    std::cout << " row " << i << "\n";
  }




  /**
  * vectors
  * Explanation: a vector is a object array data structure that works like an array but with more functionality and resizing ablity after intitlitation
  *
  */
  std::cout << "\nVector\n";


  std::vector<int> v, v2(5, 0); // V2 creates a vector of 5 spaces each occupied by 0
  std::vector<std::string> v3 = {"Hello", "Hi", "Bonjour", "Prevet", "Ola"}; // Initializing a vector with already declared values

  // Inserting elements
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
  v.push_back(5);

  // retrieving length of vector
  int v_length = v.size();
  std::cout << "\nv.size();: " << v_length;

  // Check if empty
  bool isEmpty = v.empty();
  std::cout << "\nv.empty(): " << isEmpty << "\n";

  // Accessing elements
  std::cout << v[3] << "\n"; // can do it like this
  std::cout << v.at(3) << "\n"; // or can do it like this (recommended because the [] is also an assignment operator)

  // removing elements using an iterator
  v.erase(v.begin() + 4); // remove last element in the vector

  // remove last element
  v.pop_back();

  // Printing vector elements using for loop
  for(int i = 0; i < v.size(); i++)
  {
    std::cout << v.at(i) << " "; // Can access element using a function
    // std::cout << v2[i] << " "; // can access element using built in access brackets
  }
  std::cout << "\n";

  for(const auto& i: v)
  {
    std::cout << i << " "; // can access element using built in access brackets
  }
  std::cout << "\n";


  /**
  * Lists (doubly linkedList) (works similar to a vector but with better insertions and deletions)
  * Explanation: A doubly linkedlist container that supports constant time insertions and removal of elements from anywhere in the container.
  *              Each element is linked to the next and previous elements, this means we can traverse the list in order and reverse order.
  */
  std::cout << "\nList\n";

  std::list<int> l1;
  std::list<int> l2 = {1, 2, 3, 4, 5}; // list can use an initializer list

  //? Inserting elements
  l1.push_back(3);
  l1.push_back(3);
  l1.push_back(4);
  l1.push_back(4);
  l1.push_front(1);
  auto list_it = l1.begin();
  while(list_it != l1.end() && *list_it != 3) // traverse linked list until we find 3
  {
    list_it++; // increment iterator to go to next position
  }
  l1.insert(list_it, 2); // insert 2 before 3
  l1.insert(list_it, 2);

  // .begin() - returns an iterator pointing to the first position in the list
  // .end() - returns an iterator pointing to the last position in the list
  // .front() - returns a reference pointing to the value in the front of the list
  // .back() - returns a reference pointing to the value in the back of the list

  //? Accessing elements. (can only access the front and back at const time)
  int front_value = l1.front();
  int back_value = l1.back();
  std::cout << "front value: " << front_value << "\nback value: " << back_value << "\n";

  //? Accessing elements through traversal. (can access a specific element by traversing the list "linear time")
  int find_two{}; // {} sets a default value for find_two
  for(auto v : l1)
  {
    if(v == 2) find_two = v;
  }
  std::cout << "accessing value through traversal: " << find_two << "\n";

  //? Removing elements all instances of the item from the list
  l1.remove(2); // removes all instances of the item in the list
  std::cout << "l1 after l1.remove(2):\n";
  for(const auto& v : l1)
  {
    std::cout << v << " ";
  }
  std::cout << "\n";

  //? Removing a specific element from the list
  auto three_it = l1.begin();
  while(three_it != l1.end() && *three_it != 3) // traverse list until we reach an iterator point to the first 3
  {
    three_it++; // increment the iterator to go to next position
  }
  l1.erase(three_it); // removes only the item the iterator is associated to.

  // Could use a std::find() algorithm to retrieve an iterator pointing to the desired value
  // auto l1_it2 = std::find(l1.begin(), l1.end(), 3);

  std::cout << "list after l1.erase(three_it):\n";
  for(const auto& v : l1)
  {
    std::cout << v << " ";
  }
  std::cout << "\n";

  // removes all consecutive elements, meaning one unique element will be left while any duplicates of the elements are removed
  l1.unique();
  std::cout << "l1 after l1.unique(4):\n";
  print(l1);

  // Check if empty
  std::cout << "l1.empty(): " << l1.empty() << "\n";

  // Clear list
  l1.clear();
  std::cout << "l1.empty() after l1.clear(): " << l1.empty() << "\n";



  /**
  * Stacks
  * Explanation:  A stack Last In First Out (LIFO) ADT where each value is stacked on top of each other and the value
  *               at the top of the stack if first to get popped. The stack in the STL is implemented using a deque ADT (dequeue is implemented using an array)
  */
  std::cout << "\nStack\n";

  std::stack<int> stack;

  //? Inserting
  stack.push(1);
  stack.push(2);
  stack.push(3);
  stack.push(4);
  stack.push(5);

  //? Accessing elements
  // In a stack you can only access the top element
  // Will cause stegmation fault if stack is empty
  std::cout << "stack.top(): " << stack.top() << "\n"; // Access element at the top

  //? Removing elements
  stack.pop(); // removes top element. Does not return anything
  std::cout << "stack.top() after stack.pop(): " << stack.top() << "\n";

  //? Check size
  std::cout << "stack.size(): " << stack.size() << "\n";

  //? Check if empty
  std::cout << "stack.empty(): " << stack.empty() << "\n";

  //? Clear
  // Stack does not have a clear function so use this algorithm
  while(!stack.empty())
  {
    stack.pop();
  }
  std::cout << "stack.empty after clear operation: " << stack.empty() << "\n";


  /**
  * Queues
  *
  */


  /*
  ?  Double Ended Queue
  ?  Explanation:
  */

  std::deque<int> q;

  for(int i = 0; i < 5; i++)
  {
    q.push_front(i);
  }

  std::cout <<"q.size(): " << q.size() << "\n";
  q.pop_front();
  std::cout <<"q.size(): " << q.size() << "\n";

  q.push_back(6);


  /*
  ?  Normal Queue
  ?  Explanation:
  */



  /*
  ?  Priority Queue
  ?  Explanation: A priority queue is a queue that has a certain order of retrieval. Usually a priority queue always has the largest value first in the queue, but it can also be reversed to have the smallest always first
  ?               in the queue, and there are also ways to make it custom to have your specific priority need to be first in the queue
  ?  Implementation: A priority queue is usually implemented using a max or min heap tree.
  */


  /**
  * Unordered Maps
  * Exmplanation: A map is a dictionary ADT that holds key value pairs where each vlaue is assigned to a distaict unique key.
  *               In the case of a unordered_map, it has no order to its keys or values and uses hashing specifically the seperate chaining collion technique.
  */
  std::cout << "\nUnordered_Map\n";

  std::unordered_map<int, std::string> unordered_names;

  //?  Inserting elements into unordered_map
  //! Traditional insert function.
  // Will insert the key-value pair in the map if key does not already exist. Uses pair initializer list
  // If key already exists it will return an iterator to the key and false indicating that the insertion did not work.
  unordered_names.insert({1, "Bob"});

  //! Inserting use brackets (useful for when you want to either insert and element or update the element at the key)
  // Technically a find or add operation.
  // This will try to locate the key and update the element at the key.
  // If the key does not exist it will create a key value pair
  // This requires the key to have a default initializer type
  unordered_names[2] = "Jane";

  //! Insertion where object is created in place.
  // Normal insertion utilizes a copy constructor where the key value pair is copied from the parameters.
  // An emplace function carries the passed in key value pair in the parameter to a constructor which creates the objects.
  // Same case as insert it will not override a key value pair if it already exists in the map
  unordered_names.emplace(3, "Larry"); // E

  //! Insertion by passing a pair
  std::pair<int, std::string> unordered_name4 = {2, "Jane"};
  unordered_names.insert(unordered_name4);

  //? Accessing elements
  std::cout << "Accessing first element: ";
  const auto& un_map_it = unordered_names.find(1); // returns iterator
  const std::string un_map_name = un_map_it->second;
  std::cout << un_map_name << "\n";

  //? Accessing elements through loop
  // Notice how accessing the elements has no order
  std::cout << "Accessing elements through loop:\n";
  for(const auto& elements : unordered_names)
  {
    std::cout << "Key: " << elements.first << " Value: " << elements.second << "\n";
  }
  std::cout << "\n";

  //? C++ pro trick
  // For more organization use a pair initializer list to hold elements separately this avoid using .first and .second
  // for(const auto& [key, value] : unordered_names)
  // {
  //   std::cout << "Key: " << key << " Value: " << value << "\n";
  // }
  // std::cout << "\n";

  //? Checking if an element exists */
  // Two ways

  /*! Using count() */
  // count returns the number of occurrences the element has in the set. However, since it's a set and an element exists in the set it will only
  // have one occurrence, and if it does not exist then there will be no occurrence and count will return a 0.
  std::cout << "Using count():\n";
  std::cout << "Element exist with count | unordered_names.count(1) | 1=true 0=false: " << unordered_names.count(1) << "\n";
  std::cout << "Element does not exist with count | unordered_names.count(1) | 1=true 0=false: " << unordered_names.count(5) << "\n";

  /*! Using find() */
  // find returns an iterator at the place where the element is at, but if the element does not exist then the iterator will point to .end()
  // If the iterator points to .end we can assume the element does not exist in the set
  std::cout << "Using find():\n";
  const auto& un_map_foundIt = unordered_names.find(1);
  const auto& un_map_notFoundIt = unordered_names.find(5);
  bool un_map_found = un_map_foundIt != unordered_names.end() ? true : false;
  bool un_map_notFound = un_map_notFoundIt != unordered_names.end() ? true : false;
  std::cout << "Element exist with find | unordered_names.find(1) | 1=true 0=false: " << un_map_found << "\n";
  std::cout << "Element does not exist with find | unordered_names.find(1) | 1=true 0=false: " << un_map_notFound << "\n";

  //? Check if empty
  bool isUnmapEmpty = unordered_names.empty();
  std::cout << "unordered_names.empty(): " << isUnmapEmpty << "\n";

  //?  Clear unordered map
  unordered_names.clear();
  std::cout << "empty() after unordered_names.empty(): " << unordered_names.empty() << "\n";



  /**
  * Maps
  * Explanation: A map is a dictionary ADT that holds with key value pairs where each value is assinged to a distict unique key.
  *              In the case of a Normal Map, it has an order to its keys only and uses a balance search tree (red and black tree)
  */
  std::cout << "\nMap\n";

  std::map<int, std::string> names;

  //?  Inserting elements into map

  //! Traditional insert function.
  // Will insert the key-value pair in the map if key does not already exist. Uses pair initializer list
  // If key already exists it will return an iterator to the key and false indicating that the insertion did not work.
  names.insert({1, "Bob"});

  //! Inserting use brackets (useful for when you want to either insert and element or update the element at the key)
  // Technically a find or add operation.
  // This will try to locate the key and update the element at the key.
  // If the key does not exist it will create a key value pair
  // This requires the key to have a default initializer type
  names[2] = "Jane";

  //! Insertion where object is created in place.
  // Normal insertion utilizes a copy constructor where the key value pair is copied from the parameters.
  // An emplace function carries the passed in key value pair in the parameter to a constructor which creates the objects.
  // Same case as insert it will not override a key value pair if it already exists in the map
  names.emplace(3, "Larry"); // E

  //! Insertion by passing a pair
  std::pair<int, std::string> name4 = {2, "Jane"};
  names.insert(name4);

  //? Accessing elements
  std::cout << "Accessing first element: ";
  const auto& map_it = names.find(1); // returns iterator
  const std::string map_name = map_it->second;
  std::cout << map_name << "\n";

  //? Accessing elements through loop
  // Notice how accessing the elements has an order in the keys
  std::cout << "Accessing elements through loop:\n";
  for(const auto& elements : names)
  {
    std::cout << "Key: " << elements.first << " Value: " << elements.second << "\n";
  }
  std::cout << "\n";

  //? C++ pro trick
  // For more organization use a pair initializer list to hold elements separately this avoid using .first and .second
  // for(const auto& [key, value] : names)
  // {
  //   std::cout << "Key: " << key << " Value: " << value << "\n";
  // }
  // std::cout << "\n";


  //? Checking if an element exists */
  // Two ways

  /*! Using count() */
  // count returns the number of occurrences the element has in the set. However, since it's a set and an element exists in the set it will only
  // have one occurrence, and if it does not exist then there will be no occurrence and count will return a 0.
  std::cout << "Using count():\n";
  std::cout << "Element exist with count | names.count(1) | 1=true 0=false: " << names.count(1) << "\n";
  std::cout << "Element does not exist with count | names.count(5) | 1=true 0=false: " << names.count(5) << "\n";

  /*! Using find() */
  // find returns an iterator at the place where the element is at, but if the element does not exist then the iterator will point to .end()
  // If the iterator points to .end we can assume the element does not exist in the set
  std::cout << "Using find():\n";
  const auto& map_foundIt = names.find(1);
  const auto& map_notFoundIt = names.find(5);
  bool map_found = map_foundIt != names.end() ? true : false;
  bool map_notFound = map_notFoundIt != names.end() ? true : false;
  std::cout << "Element exist with find | names.find(1) | 1=true 0=false: " << map_found << "\n";
  std::cout << "Element does not exist with find | names.find(5) | 1=true 0=false: " << map_notFound << "\n";

  //? Check if empty
  bool isMapEmpty = names.empty();
  std::cout << "names.empty(): " << isMapEmpty << "\n";

  //?  Clear map
  names.clear();
  std::cout << "empty() after names.clear(): " << names.empty() << "\n";


  /**
  * Unordered Sets
  * Explanation: A set dictionary works like a map except there is only one unique key element. Each key is saved once in the set so no duplicate are allowed.
  *              In the case of an UNORDERED SET, it has no order in its elements and uses hashing to store elements in a randomized order
  *
  */
  std::cout << "\nUnordered Sets\n";

  std::unordered_set<std::string> unordered_string_set;
  // Inserting elements
  unordered_string_set.insert("Bob");
  unordered_string_set.insert("Joe");
  unordered_string_set.insert("Dane");
  unordered_string_set.insert("Karl");
  unordered_string_set.insert("Bob"); // This will not add to the set since it's a duplicate

  // Accessing elements
  std::cout << "Accessing first element: ";
  const auto& unordered_set_it = unordered_string_set.find("Bob");
  std::string unordered_set_first_name = *unordered_set_it;
  std::cout << unordered_set_first_name << "\n";

  // Accessing elements through loop
  // Notice how accessing the elements does not have an order
  std::cout << "Accessing elements through loop: ";
  for(auto& elements : unordered_string_set)
  {
    std::cout << elements << " ";
  }
  std::cout << "\n";

  unordered_string_set.erase(unordered_string_set.find("Karl"));
  std::cout << "string_set after string_set.erase(string_set.find(Karl)): ";
  for(auto& elements : unordered_string_set)
  {
    std::cout << elements << " ";
  }
  std::cout << "\n";

  // Checking if an element exists
  // Two ways

  // Using count()
  // count returns the number of occurrences the element has in the set. However, since it's a set and an element exists in the set it will only
  // have one occurrence, and if it does not exist then there will be no occurrence and count will return a 0.
  std::cout << "Using count():\n";
  std::cout << "Element exist with count | string_set.count(Dane) | 1=true 0=false: " << unordered_string_set.count("Dane") << "\n";
  std::cout << "Element does not exist with count | string_set.count(Karl) | 1=true 0=false: " << unordered_string_set.count("Karl") << "\n";

  // Using find()
  // find returns an iterator at the place where the element is at, but if the element does not exist then the iterator will point to .end()
  // If the iterator points to .end we can assume the element does not exist in the set
  std::cout << "Using find():\n";
  const auto& foundIt = unordered_string_set.find("Dane");
  const auto& notFoundIt = unordered_string_set.find("Karl");
  bool found = foundIt != unordered_string_set.end() ? true : false;
  bool notFound = notFoundIt != unordered_string_set.end() ? true : false;
  std::cout << "Element exist with find | string_set.find(Dane) | 1=true 0=false: " << found << "\n";
  std::cout << "Element does not exist with find | string_set.find(Karl) | 1=true 0=false: " << notFound << "\n";

  // Check if empty
  bool isSetEmpty = unordered_string_set.empty();
  std::cout << "string_set.empty(): " << isSetEmpty << "\n";

  // Clear set
  unordered_string_set.clear();
  std::cout << "empty() after string_set.clear(): " << unordered_string_set.empty() << "\n";

  /**
  * Sets
  * Explanation: A set dictionary works like a map except there is only one unique key element. Each key is saved once in the set so no duplicates are allowed/
  *              In the case of just a normal Set, it utilizes a ordered strucutre of elements using a balance search tree (red and black tree).
  */
  std::cout << "\nSets\n";

  std::set<std::string> string_set;

  // Inserting elements
  string_set.insert("Bob");
  string_set.insert("Joe");
  string_set.insert("Dane");
  string_set.insert("Karl");
  string_set.insert("Bob"); // This will not add to the set since it's a duplicate

  // Accessing elements
  std::cout << "Accessing first element: ";
  const auto& set_it = string_set.find("Bob");
  std::string set_first_name = *set_it;
  std::cout << set_first_name << "\n";

  // Accessing elements through loop
  // Notice how accessing the elements is in an ordered way from least to greatest A->Z
  std::cout << "Accessing elements through loop: ";
  for(auto& elements : string_set)
  {
    std::cout << elements << " ";
  }
  std::cout << "\n";

  // removing elements
  string_set.erase(string_set.find("Karl"));
  std::cout << "string_set after string_set.erase(string_set.find(Karl)): ";
  for(auto& elements : string_set)
  {
    std::cout << elements << " ";
  }
  std::cout << "\n";

  // Checking if an element exists
  // Two ways

  // Using count()
  // count returns the number of occurrences the element has in the set. However, since it's a set and an element exists in the set it will only
  // have one occurrence, and if it does not exist then there will be no occurrence and count will return a 0.
  std::cout << "Using count():\n";
  std::cout << "Element exist with count | string_set.count(Dane) | 1=true 0=false: " << string_set.count("Dane") << "\n";
  std::cout << "Element does not exist with count | string_set.count(Karl) | 1=true 0=false: " << string_set.count("Karl") << "\n";

  // Using find()
  // find returns an iterator at the place where the element is at, but if the element does not exist then the iterator will point to .end()
  // If the iterator points to .end we can assume the element does not exist in the set
  std::cout << "Using find():\n";
  const auto& s_foundIt = string_set.find("Dane");
  const auto& s_notFoundIt = string_set.find("Karl");
  bool s_found = s_foundIt != string_set.end() ? true : false;
  bool s_notFound = s_notFoundIt != string_set.end() ? true : false;
  std::cout << "Element exist with find | string_set.find(Dane) | 1=true 0=false: " << found << "\n";
  std::cout << "Element does not exist with find | string_set.find(Karl) | 1=true 0=false: " << notFound << "\n";

  // Check if empty
  bool s_isSetEmpty = string_set.empty();
  std::cout << "string_set.empty(): " << s_isSetEmpty << "\n";

  // Clear set
  string_set.clear();
  std::cout << "empty() after string_set.clear(): " << string_set.empty() << "\n";

  /**
  * Pair
  * Explanation:
  */
  std::pair<int, int> my_p;



  return 0;

}