#ifndef SORT_LIST_CPP_
#define SORT_LIST_CPP_
#include "Sort_list.h"
#include <vector>
#include <iostream>

template<class T>
SortList<T>::SortList()
{

}

template<class T>
void SortList<T>::add_item(const T& item)
{
	items_.push_back(item);
}

template<class T>
void SortList<T>::print_items()
{
	for(int i = 0; i < items_.size(); i++)
{
std::cout << items_[i] << " "; 
}
std::cout << "\n";
}


template<class T>
void SortList<T>::sort()
{
	for(int i = 0; i < items_.size() - 1; i++)
{
for(int j = 0; j < items_.size() - i - 1; j++)
{
	if(items_[j] > items_[j+1])
	{
		T temp = items_[j+1];
		items_[j+1] = items_[j];
		items_[j] = temp;
	}
}
}
}


#endif
