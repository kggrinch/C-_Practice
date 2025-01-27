#include <iostream>
#include <vector>
#include <algorithm>

template<class T>
void printVector(std::vector<T>& my_vector)
{
  for(int i = 0; i < my_vector.size(); i++)
  {
    std::cout << my_vector[i] << " ";
  }
  std::cout << "\n";
}

// Worst time: O(n^2)
// Average time; O(n^2)
// Best time: O(n)
template<class T>
void insertion_sort(std::vector<T>& my_vector)
{
  for(int i = 1; i < my_vector.size(); i++)
  {
    T temp = my_vector[i];
    int j = i - 1;
    while(j >= 0 && my_vector[j] > temp)
    {
      my_vector[j+1] = my_vector[j];
      j--;
    }
    my_vector[j+1] = temp;
  }


// With an array without []
// for(int i = 0; i < length; i++)
// {
//   T temp = *(array + i);
//   int j = i - 1;
//   while(j >= 0 && *(array + j) > temp)
//   {
//     *(array + j + 1) = *(array + j);
//     j--;
//   }
//   *(array + j + 1) = temp;
// }

}

// Worst time: O(n^2)
// Average time: O(n²)
// Best time: O(n)
template<class T>
void bubble_sort(std::vector<T>& my_vector)
{
  for(int i = 0; i < my_vector.size() - 1; i++)
  {
    for(int j = 0; j < my_vector.size() - i - 1; j++)
    {
      if(my_vector[j] > my_vector[j+1])
      {
        T temp = my_vector[j+1];
        my_vector[j+1] = my_vector[j];
        my_vector[j] = temp;
      }
    }
  }

// With an array without []
  // for(int i = 0; i < length - i; i++)
  // {
  //   for(int j = 0; j < length - i - 1; j++)
  //   {
  //     if(*(array + j) > *(array + j + 1))
  //     {
  //       T temp = *(array + j + 1);
  //       *(array + j + 1) = *(array + j);
  //       *(array + j) = temp;
  //     }
  //   }
  // }
}

// Worst time: O(n^2)
// Average time: O(n^2)
// Best time: O(n^2)
template<class T>
void selection_sort(std::vector<T>& my_vector)
{
  // for(int i = 0; i < my_vector.size() - 1; i++)
  // {
  //   int min = i;
  //   for(int j = i + 1; j < my_vector.size(); j++)
  //   {
  //     if(my_vector[min] > my_vector[j])
  //     min = j;
  //   }
  //   T temp = my_vector[i];
  //   my_vector[i] = my_vector[min];
  //   my_vector[min] = temp;
  // }
}

// Merge sort
// Worst case = O(n log n)
// average case = O(n log n)
// void merge(std::vector<int>& vec, int first, int last, int mid)
// {
//   int size = last - first + 1; // Get size of array to be sorted // +1

//   // Create a temp array. This will hold the sorted elements
//   int* temp_array; // + 1
//   temp_array = new int[size]; // + 1

//   // Splitting the list

//   // The left portion of the list
//   int first1 = first; // + 1
//   int last1 = mid; // + 1

//   // The right portion of the list
//   int first2 = mid + 1; // + 1
//   int last2 = last; // + 1

//   // while not reached the end of the left portion of the list and the right portion of the list. 
//   // add the smallest elements in the list to the new array.
//   int index = 0; // This keeps track of the index of the array we are placing the elements
//   while(first1 <= last1 && first2 <= last2) // o(n)
//   {
//     if(vec[first1] < vec[first2]) // Check which element in the lists is smaller
//     {
//       temp_array[index] = vec[first1]; // place it first
//       first1++;
//     }
//     else
//     {
//       temp_array[index] = vec[first2];
//       first2++;
//     }
//     index++;
//   }

//   // Once one of the lists is empty copy over all the elements from the other list.

//   // If left list is empty. copy the rest of the elements in the right list to the new_list.
//   while(first1 <= last1) // O(n)
//   {
//     temp_array[index] = vec[first1];
//     first1++;
//     index++;
//   }
//   // if right list is empty. copy the rest of the elements in the left list to the new_list.
//   while(first2 <= last2)
//   {
//     temp_array[index] = vec[first2];
//     first2++;
//     index++;
//   }

//   // Copy the elements from the new_list to the original since the new_list has the elements sorted
//   for(int i = 0; i < size; i++)
//   {
//     vec[first] = temp_array[i];
//     first++;
//   }
//   delete[] temp_array; // delete memory used to allocate the new array

// }


// void merge_sort(std::vector<int>& vect, int first, int last)
// {
//     if(first < last) // +1 
//     {
//         int mid = (first + last) / 2; // + 1

//         merge_sort(vect, first, mid); // n / 2
//         merge_sort(vect, mid+1, last);
//         merge(vect, first, last, mid);
//     }
// }


template<class T>
void merge(std::vector<T>& vect, int first, int last, int mid)
{
  int size = (last - first) + 1;
  std::vector<T> temp(size);

  int first1 = first;
  int last1 = mid;

  int first2 = mid + 1;
  int last2 = last;

  int index = 0;
  while(first1 <= last1 && first2 <= last2)
  {
    if(vect[first1] <= vect[first2])
    {
      temp[index] = vect[first1];
      first1++;
    }
    else
    {
      temp[index] = vect[first2];
      first2++;
    }
    index++;
  }
  
  while(first1 <= last1)
  {
    temp[index] = vect[first1];
    first1++;
    index++;
  }
  while(first2 <= last2)
  {
    temp[index] = vect[first2];
    first2++;
    index++;
  }

  for(int i = 0; i < size; i++)
  {
    vect[first] = temp[i];
    first++;
  }
}


template<class T>
void merge_sort(std::vector<T>& vect, int first, int last)
{
  if(first < last)
  {
    int mid = (first + last) / 2;
    merge_sort(vect, first, mid);
    merge_sort(vect, mid + 1, last);
    merge(vect, first, last, mid);
  }
}


// Quick Sort
// void quick_sort(std::vector<int>& vect, int first, int last)
// {
//   // This part check if the array is a small array. If a small array it is more effiecent to use other algorithms, since quicksort is more efficent with larger data.
//   // This is called if the size of the vect is smaller than 4.
//   // if(last - first < 4)
//   // {
//   //   merge_sort(vect, first, last);
//   //   return;
//   // }

//   if(first >= last)
//   {
//     return;
//   }

//   int mid = (first + last) / 2;
  
//   // Sort the items in the first, middle, and last positions

//   // Check first element is greater then the last element
//   if(vect[first] > vect[last])
//   {
//     std::swap(vect[first], vect[last]); // swap method

//     // Swap technique
//     // int temp = vect[last];
//     // vect[last] = vect[first];
//     // vect[first] = temp;
//   } 
//   // Check if middle element is greater than the last
//   if(vect[first] > vect[mid])
//   {
//     std::swap(vect[first], vect[mid]); // swap method

//     // Swap technique
//     // int temp = vect[last];
//     // vect[last] = vect[mid];
//     // vect[mid] = temp;
//   }
//   else if(vect[mid] > vect[last])
//   {
//     std::swap(vect[mid], vect[last]); // swap method
//   }
//   // Teacher implementation
//   int pivot = vect[mid]; // aknowledge the pivot
//   std::swap(vect[mid], vect[last]); // place the pivot last and the last in the middle

//   int leftIndex = first; // Already sorted the first.
//   int rightIndex = last - 1; // Already sorted the last + need to skip the pivot
//   bool done = false;

//   while(!done)
//   {
//     // Hes doing the current list trick where you increment until you find the right values.
//     while(vect[leftIndex] < pivot)
//     {
//       leftIndex++;
//     }
//     while(vect[rightIndex] > pivot)
//     {
//       rightIndex--; 
//     }


//     if(rightIndex >= leftIndex) // Indexes imporant to do the check with right > left instead of right != left
//     {
//       std::swap(vect[leftIndex], vect[rightIndex]);
//       rightIndex--;
//       leftIndex++;
//     }
//     else
//     {
//       std::swap(vect[leftIndex], vect[last]); 
//       quick_sort(vect, first, leftIndex-1); // left side
//       quick_sort(vect, leftIndex+1, last); // right side
//       done = true;
//     }
//   }
// }

template<class T>
void quick_sort(std::vector<T>& vec, int first, int last)
{
  if(first >= last)
  {
    return;
  }

  int mid = (first + last) / 2;
  if(vec[first] > vec[last])
  {
    std::swap(vec[first], vec[last]);
    
  }
  if(vec[first] > vec[mid])
  {
    std::swap(vec[first], vec[mid]);
  }
  if(vec[mid] > vec[last])
  {
    std::swap(vec[mid], vec[last]);
  }
  T pivot = vec[mid];
  std::swap(vec[mid], vec[last]);
  int left = first;
  int right = last - 1;
  bool done = false;
  while(!done)
  {
    while(vec[left] < pivot)
    {
      left++;
    }
    while(vec[right] > pivot)
    {
      right--;
    }

    if(right > left)
    {
      std::swap(vec[left], vec[right]);
      left++;
      right--;
    }
    else
    {
      std::swap(vec[left], vec[last]);
      quick_sort(vec, first, left - 1);
      quick_sort(vec, left + 1, last);
      done = true;
    }
  }


}


/* [Shell Sort]

Time Complexity:
Worst: O(n^2)
Average: O(n^(3/2))
Best: O(n log n)

Space Complexity: O(1)
*/

template<class T>
void ShellSort(std::vector<T>& vec, int first, int last)
{
  int size = (last + first) / 2;
  for(int gap = size / 2; gap > 0; gap /= 2)
  {
    for(int i = first + gap; i < last + 1; i++)
    {
      T temp = vec[i];
      int j;
      for(j = i; j >= gap + first && vec[j - gap] > temp; j -= gap)
      {
        vec[j] = vec[j - gap];
      }
      vec[j] = temp;
    }
  }
}





/*
[Radix Sort

Time Complexity:
Worst case: O(d(n + b)) - n = inputs, d = digit places, b = base system

Space Complexity: O(1)
*/
// Helper for radix sort
void countSort(std::vector<int>& vect, int exp)
{
  int n = vect.size();
  std::vector<int> output(n);
  int count[10] = {0}; // Count array for digits (0 - 9) 
  for(int i = 0; i < n; i++)
  {
    int digit = (vect[i] / exp);
    digit = digit % 10;
    count[digit]++;
  }

  // Transforming count array to store cumulative counts
  for(int i = 1; i < 10; i++)
  {
    count[i] += count[i - 1];
  }

  // convert cumulative counts
  for(int i = n - 1; i >= 0; i--)
  {
    // Traverse from the back
    int digit = (vect[i] / exp) % 10;
    output[count[digit] - 1] = vect[i];
    count[digit]--;
  }

  // Copy the sorted numbers back to the original vector
  for(int i = 0; i < n; i++)
  {
    vect[i] = output[i];
  }
}

void radixSort(std::vector<int>& vect)
{
  // Finding the max element in the vector to know the number of digits
  int maxN = vect[0];
  
  // Could use a for-loop to find max value in array
  for(int i = 1; i < vect.size(); i++)
  {
    if(vect[i] > maxN)
    {
      maxN = vect[i];
    }
  }

  // Perform counting of each digit
  for(int exp = 1; maxN / exp > 0; exp = exp * 10)
  {
    countSort(vect, exp);
  }
}





// template <class T>
// int binarySearch(const std::vector<T>& vect, const T& target)
// {
//   int low = 0;
//   int high = vect.size() - 1;
//   while(low <= high)
//   {
//     int mid = (low + high) / 2;
//     if(vect[mid] < target)
//     {
//       low = mid + 1;
//     }
//     else if(vect[mid] > target)
//     {
//       high = mid - 1;
//     }
//     else
//     {
//       return mid;
//     }
//   }
//   return -1;
// }

template<class T>
int binarySearch(const std::vector<T>& vect, const T& target)
{
  int low = 0;
  int high = vect.size() - 1;
  while(low <= high)
  {
    int mid = (low + high) / 2;
    if(vect[mid] < target)
    {
      low = mid + 1;
    }
    else if(vect[mid] > target)
    {
      high = mid - 1;
    }
    else
    {
      return mid;
    }
  }
  return -1;
}




template<class T>
int binarySearchRecursive(const std::vector<T>& vect, int low, int high, const T& target)
{
  if(low > high)
  {
    return -1;
  }
  int mid = (low + high) / 2;
  if(vect[mid] == target)
  {
    return mid;
  }
  else if(vect[mid] < target)
  {
    return binarySearchRecursive(vect, low = mid + 1, high, target);
  }
  else if(vect[mid] > target)
  {
    return binarySearchRecursive(vect, low, high = mid - 1, target);
  }
}

template<class T>
int binary_search_recursive(T* array, int low, int high, const T& target)
{
	if(low > high)
	{
		return -1;
	}
	int mid = (low + high) / 2;
	if(*(array + mid) == target)
	{
		return mid;
	}
	else if(*(array + mid) < target)
	{
		return binary_search_recursive(array, mid + 1, high, target);
	}
	else if(*(array + mid) > target)
	{
		return binary_search_recursive(array, low, mid - 1, target);
	}
}

template<class T>
int binary_search_iterative(T* array, int length, const T& target)
{
	int low = 0;
	int high = length - 1;
	while(low <= high)
	{
		int mid = (low + high) / 2;
		if(*(array + mid) == target)
		{
			return mid;
		}
		else if(*(array + mid) < target)
		{
			low = mid + 1;
		}
		else if(*(array + mid) > target)
		{
			high = mid - 1;
		}
	}
	return -1;
}

int main()
{
  std::cout << __cplusplus << std::endl; // Checks which version of c++ it is running on = Version c++14

  std::vector<int> my_vector1 = {6, 4, 8, 2, 5, 7, 1, 9, 3};
  std::vector<std::string> my_vector2 = {"Jabe", "Bob", "John", "Larry", "Daryl"};
  std::vector<char> my_vector3 = {'V', 'P', 'W', 'A', 'R', 'D', 'B'};
  std::vector<int> my_vector4 = {8, 2, 9, 5, 4, 3, 0, 1, 7, 6};
  std::vector<int> my_vector5 = {6, 7, 3, 8, 4, 9, 1, 2, 0, 5};
  std::vector<int> merge_vector = {6, 7, 3};
  std::vector<int> quick_vector = {6, 7, 3, 8, 4, 9, 1, 2, 0, 5};
  std::vector<int> radix_vector = {6, 7, 3, 8, 4, 9, 1, 2, 0, 5};
  std::vector<int> shell_vector = {10, 7, 3, 8, 4, 6, 1, 2, 0, 5, 9};


  printVector(my_vector2);
  printVector(my_vector3);

  bubble_sort(my_vector1);
  printVector(my_vector1);

  insertion_sort(my_vector2);
  printVector(my_vector2);

  selection_sort(my_vector3);
  printVector(my_vector3);

  // Test
  std::cout << "my_vector1: "; printVector(my_vector1);
  std::cout << "my_vector4: "; printVector(my_vector4);
  std::cout << "my_vector5: "; printVector(my_vector5);

  std::cout << "Bubble Sort: ";
  bubble_sort(my_vector1);
  printVector(my_vector1);

  std::cout << "Insertion Sort: ";
  insertion_sort(my_vector4);
  printVector(my_vector4);

  std::cout << "Selection Sort: ";
  selection_sort(my_vector5);
  printVector(my_vector5);

  std::cout << "Merge Sort: ";
  std::cout << "Unsorted: ";
  printVector(merge_vector);
  merge_sort(merge_vector, 0, merge_vector.size()-1);
  printVector(merge_vector);

  std::cout << "Quick Sort: ";
  std::cout << "Unsorted: ";
  printVector(quick_vector);
  quick_sort(quick_vector, 0, quick_vector.size() - 1);
  printVector(quick_vector);

  std::cout << "Radix Sort: ";
  std::cout << "Unsorted: "; 
  printVector(radix_vector);
  radixSort(radix_vector);
  printVector(radix_vector);

  std::cout << "Shell Sort: ";
  std::cout << "Unsorted: "; 
  printVector(shell_vector);
  ShellSort(shell_vector, 0, shell_vector.size() - 1);
  printVector(shell_vector);


  int target = -5;
  std::cout <<"BinarySearch(): " << binarySearch(quick_vector, target) << "\n";
  std::cout << "BinarySearchRecursive(): " << binarySearchRecursive(quick_vector, 0, quick_vector.size() - 1, 5) << "\n";

  std::string name = "Hello";
  

  for(int i = name.size()-1, j = 0; i != j; i--, j++)
  {
    char temp = name[j];
    name[j] = name[i];
    name[i] = temp;
  }

  std::cout << name << "\n";


  // Binary search recursive using pointer array
  std::cout << "Recursive Binary Search with pointer array\n";
  int* array = new int[10];
  for(int i = 0; i < 10; i++)
  {
    *(array + i) = i;
  }

  std::cout << "4 is located at index: " <<  binary_search_recursive(array, 0, 9, 4) << "\n";
  std::cout << "4 is located at index: " << binary_search_iterative(array, 10, 4);


  return 0;
}