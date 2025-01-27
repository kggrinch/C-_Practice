#include <iostream>

template<class T>
void swap(T& x, T& y)
{
  T temp = x;
  x = y;
  y = temp;
}

template<class T>
T& return_function(T& a)
{
  int b=0;
  b++;
  return b;
}



int main()
{
  int x = 1;
  int y = 2;

  std::cout << "Before swap: " << "x: " << x << " y: " << y << "\n"; 

  swap(x, y);

  std::cout <<"After swap: " << "x: " << x << " y: " << y << "\n";

  int a = 25;
  a = return_function(a);
  std::cout << a << "\n";
}

