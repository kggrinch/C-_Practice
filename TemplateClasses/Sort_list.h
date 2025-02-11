#ifndef SORT_LIST_H_
#define SORT_LIST_H_
#include <iostream>
#include <vector>

template<class T>
class SortList
{
	public:
    SortList();
		void add_item(const T& item);
		void print_items();
		void sort();

	
private:
	std::vector<T> items_;
	
};

#include "Sort_list.cpp"

#endif
