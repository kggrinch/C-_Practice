#include <iostream>
#include <vector>
#include <algorithm>

template<class T>
void printArray(T* array, const int& length)
{
  for(int i = 0; i < length; i++)
  {
    std::cout << *(array + i) << " ";
  }
  std::cout << "\n";
}

template<class T>
void printArrayRegular(T array[], const int& length)
{
  for(int i = 0; i < length; i++)
  {
    std::cout << array[i] << " ";
  }
  std::cout << "\n";
}

void printArrayByReference(int (&array)[4])
{
  for(int i = 0; i < 3; i++)
  {
    std::cout << array[i] << " ";
  }
  std::cout << "\n";
}

// Array exercies
int sum(int array[], const int& length)
{
  int total = 0;
  for(int i = 0; i < length; i++)
  {
    total += array[i]; // dyamic array: total += *(array + i);
  }
  return total;
}
template<class T>
void modifyArray(T* array, const int& length)
{
  for(int i = 0; i < length; i++)
  {
    *(array + i) += 1; // can also do ++(*(array + i));
  }
}

template<class T>
void printVector(const std::vector<T>& vect)
{
  for(int i = 0; i < vect.size(); i++)
  {
    std::cout << vect[i] << " ";
  }
  std::cout << "\n";
}

void displayInt(void (*f)(int), int input)
{
  std::cout << "displaying: ";
  f(input);
}


void f1(int x)
{
  std::cout << x << "\n";
}

void squaredElements(int array[], const int& length)
{
  for(int i = 0; i < length; i++)
  {
    array[i] = array[i]*array[i];
  }
}

// array pointer exercies 1
// Function to count and print all instances of item in array
template<class T>
void instances(T* array, int length)
{
  for(int i = 0; i < length; i++)
  {
    T temp = *(array + i);
    int occurance = 0;
    for(int j = 0; j < length; j++)
    {
      if(*(array + j) == temp)
      {
        occurance++;
      }
    }
     std::cout << *(array + i) <<" has " << occurance << " instances in the array\n";
  }
}

// Method to fill in a allocated memory array from a static array. dynamic array must be allocated and has a length set
template<class T>
bool fill_array(T* dest_array, T source_array[], int length)
{
  for(int i = 0; i < length; i++)
  {
    *(dest_array + i) = source_array[i];
  }
  return true;
}


// array pointer exercies 2
// reverses the array in place
template <class T>
void reverse(T* array, int length)
{
  for(int low = 0, high = length - 1; low < high; low++, high--)
  {
    T temp = *(array + high);
    *(array + high) = *(array + low);
    *(array + low) = temp;
  }
}

template<class T>
bool find_max_and_min(T* array, int length, T& max, T& min)
{
  max = *array;
  min = *array;

  for(int i = 0; i < length; i++)
  {
    if(*(array + i) > max)
    {
      max = *(array + i);
    }
    if(*(array + i) < min)
    {
      min = *(array + i);
    }
  }
  return true;
}

template<class T>
T* copy(T* array, int length)
{
	T* new_array = new T[length];
	
	for(int i = 0; i < length; i++)
{
	*(new_array + i) = *(array + i);
}

return new_array;
}

// Exercies 5
template<class T>
T* allocateArray(int length)
{
	T* new_array = new T[length];
	for(int i = 0; i < length; i++)
	{
		*(new_array + i) = i;
		std::cout << *(new_array + i) << " ";
	}
	std::cout << "\n";
	return new_array;
}

// Exercies 6
int string_length(const char* str)
{
  int index = 0;

  while(*(str + index) != '\0')
  {
    index++;
  }
  return index;
}

// Exercise 7
template <class T>
T* merge(T* array1, int length1, T* array2, int length2)
{
  int new_length = length1 + length2;
  T* new_array = new T[new_length];

  int index1 = 0;
  int index2 = 0;
  int new_array_index = 0;
  while(index1 < length1 && index2 < length2)
  {
    if(*(array1 + index1) < *(array2 + index2))
    {
      *(new_array + new_array_index) = *(array1 + index1);
      index1++;
    }
    else
    {
      *(new_array + new_array_index) = *(array2 + index2);
      index2++;
    }
    new_array_index++;
  }

  if(index1 < length1)
  {
    *(new_array + new_array_index) = *(array1 + index1);
    index1++;
    new_array_index++;
  }
  else if(index2 < length2)
  {
    *(new_array + new_array_index) = *(array2 + index2);
    index2++;
    new_array_index++;
  }

  return new_array;
}

// Exercise 8 
template<class T>
bool shift_right(T* array, int length, int k)
{
  // Reverse the array
  for(int low = 0, high = length-1; low < high; low++, high--)
  {
    T temp = *(array + low);
    *(array + low) = *(array + high);
    *(array + high) = temp;
  }

  // Reverse elements from 0 to k - 1 because reverse the first k elements
  for(int low = 0, high = k - 1; low < high; low++, high--)
  {
    T temp = *(array + low);
    *(array + low) = *(array + high);
    *(array + high) = temp;
  }

  // reverse the remaining elements from k to length - 1
  for(int low = k, high = length - 1; low < high; low++, high--)
  {
    T temp = *(array + low);
    *(array + low) = *(array + high);
    *(array + high) = temp;
  }
  return true;
}

template<class T>
bool shift_left(T* array, int length, int k)
{
  // Reverse up to the first k elements 0 - k - 1
  for(int low = 0, high = k - 1; low < high; low++, high--)
  {
    T temp = *(array + high);
    *(array + high) = *(array + low);
    *(array + low) = temp;
  }

  // Reverse the rest k - length  - 1
  for(int low = k, high = length - 1; low < high; low++, high--)
  {
    T temp = *(array + high);
    *(array + high) = *(array + low);
    *(array + low) = temp;
  }

  // Reverse the whole list
  for(int low = 0, high = length - 1; low < high; low++, high--)
  {
    T temp = *(array + high);
    *(array + high) = *(array + low);
    *(array + low) = temp;
  }
}


template<class T>
bool remove_duplicate(T* array, int& length)
{
 int index = 1;
 for(int i = 1; i < length; i++)
 {
  bool is_dup = false;
  for(int j = 0; j < index; j++)
  {
    if(*(array + i) == *(array + j))
    {
      is_dup = true;
      break;
    }
  }

  if(!is_dup)
  {
    *(array + index) = *(array + i);
    index++;
  }
 }
 length = index;
 return true;
}
// 1 1 2 3

template <class T>
bool remove_duplicate_vector(std::vector<T>& vec)
{
    if (vec.size() <= 1) return true;  // No duplicates if vector size is 0 or 1

    int index = 1;  // Start from the second element

    // Traverse the vector
    for (size_t i = 1; i < vec.size(); ++i) {
        bool is_dup = false;

        // Check if the element already exists in the processed portion of the vector
        for (int j = 0; j < index; ++j) {
            if (vec[i] == vec[j]) {
                is_dup = true;
                break;  // Exit the loop if a duplicate is found
            }
        }

        // If it's not a duplicate, move it to the next available position
        if (!is_dup) {
            vec[index] = vec[i];
            index++;  // Move the index to the next available position
        }
    }

    // Resize the vector to remove the excess elements (duplicates)
    vec.resize(index);

    return true;  // Indicate that the operation succeeded
}


int main()
{
  // Regular array
  int regularArray[] = {3, 2, 5, 4};

  int* dynamicArray = new int[4];
  *(dynamicArray) = 3;
  *(dynamicArray + 1) = 2;
  *(dynamicArray + 2) = 5;
  *(dynamicArray + 3) = 4;

  std::cout << "printArray with pointer: " << "\n";
  std::cout << "regular array: "; printArray(regularArray, 4);
  std::cout << "dynamic array: "; printArray(dynamicArray, 4);

  std::cout << "printArray with regular: " << "\n";
  std::cout << "regular array: "; printArrayRegular(regularArray, 4);
  std::cout << "dynamic array: "; printArrayRegular(dynamicArray, 4);

  std::cout << "printArray with reference: " << "\n";
  std::cout << "regular array: "; printArrayByReference(regularArray); 
  // std::cout << "dynamic array: "; printArrayByReference(dynamicArray); // issue here because this sends in the address of the array but the paraemter takes in the address of the pointer.

  
  // some array exercieses
  std::cout << "sum of regular array: " << sum(regularArray, 4) << "\n";
  std::cout << "sum of regular array: " << sum(dynamicArray, 4) << "\n";

  std::cout << "modify arrays: ";
  modifyArray(regularArray, 4);
  modifyArray(dynamicArray, 4);
  std::cout << "regular array: "; printArray(regularArray, 4);
  std::cout << "dynamic array: "; printArray(dynamicArray, 4);


  int arr[] = {1, 2, 3};
  int* ptr = arr;
  std::cout << ptr[1] << "\n"; // This prints 2

  // function which takes in a function pointer
  displayInt(f1, 2);
  
  std::cout << "squareElements: " << "\n";
  squaredElements(regularArray, 4);
  std::cout << "regular array: "; printArray(regularArray, 4);

  delete[] dynamicArray;
  dynamicArray = nullptr;


  // pointer array exercies
  int templateArray[10] = {1, 1, 2, 6, 2, 2, 3, 6, 7, 3};

  int* pArray = new int[10];
  int length = 10;
  for(int i = 0; i < 10; i++)
  {
    *(pArray + i) = templateArray[i];
  }

  // Exercise 1 count the amount of instances of each item in the array
  instances(pArray, length);


  // Exercie 2 reverse the array in place
  printArray(pArray, length);
  reverse(pArray, length);
  printArray(pArray, length);

  // Exercie 3 find the max and min element in the array
  int max = 0;
  int min = 0;
  find_max_and_min(pArray, length, max, min);
  std::cout << "max: " << max << " min: " << min << "\n";

  // Exercie 4 copy the elements in one array point to another and return the new array;
  int* new_array = copy(pArray, length);
  printArray(new_array, length);
  delete[] new_array;
  new_array = nullptr;

  // Exercise 5 given a length of the array allocate new meory of an array fill it with values and print it
  new_array = allocateArray<int>(length);

  // Exercise 6 given a char pointer find the length of the string if its null terminated
  char temp_string_array[6] = {'B', 'O', 'B', 'R', 'O', 'S'};
  char* string_array = new char[6];
  fill_array(string_array, temp_string_array, 6);

  int string_array_length = string_length(string_array);
  printArray(string_array, string_array_length);

  // Exercise 7 merge two sorted arrays
  int array2[] = {2, 4, 6};
  int array3[] = {1, 3, 5};

  int* new_array2 = new int[3];
  int* new_array3 = new int[3];
  fill_array(new_array2, array2, 3);
  fill_array(new_array3, array3, 3);
 
  delete[] new_array;
  
  new_array = merge(new_array2, 3, new_array3, 3);
  printArray(new_array, 6);

  // Exercise 8 shift elements to the right by a given value
  std::cout << "Shift left:\n";
  std::cout << "Array before: ";
  printArray(new_array, 6);
  shift_right(new_array, 6, 1);
  std::cout << "Array after: ";
  printArray(new_array, 6);

  // shift elements to the left by a given value
  std::cout << "Shift right:\n";
  std::cout << "Array before: ";
  printArray(new_array, 6);
  shift_left(new_array, 6, 1);
  std::cout << "Array after: ";
  printArray(new_array, 6);

  // Exercise 9 remove duplicates
  std::cout << "Remove duplicate\n";
  int my_length = 6;
  new_array[0] = 1;
  new_array[1] = 1;
  new_array[5] = 3;
  printArray(new_array, my_length);
  remove_duplicate(new_array, my_length);
  printArray(new_array, my_length);

  std::vector<int> my_vect = {1, 1, 2, 3, 2, 4, 3};
  printVector(my_vect);
  remove_duplicate_vector(my_vect);
  printVector(my_vect);


  // 2D array 
  const int kRows = 3;
  const int kColums = 2;
  int two_d_array[kRows][kColums] =
  {
    {0, 1}, // To access 1 its [0][1]
    {2, 3}, // To access 2 its [1][0]
    {4, 5} // to acess 5 its [2][1]
  };

  // Accessing elements in a 2d array
  for(int i = 0; i < kRows; i++)
  {
    for(int j = 0; j < kColums; j++)
    {
      std::cout << two_d_array[i][j];
    }
  }

  int x = 15;
  int* ptr1 = &x;

  std::cout << "ptr1 " << ptr1 << "\n";
  std::cout << "*ptr1 " << *ptr1 << "\n";
  // std::cout << "**ptr1 " << *(*ptr1) << "\n"; Does not go back to the address.




  


  








  






  return 0;
}