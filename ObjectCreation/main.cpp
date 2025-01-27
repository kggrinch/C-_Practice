#include "Circle.h"
#include <iostream>

int main()
{
  Circle c(3.14);
  Circle c2(1.38);
  Circle c3;

  c3 = -c;
  // c = c2;
  

  std::cout << c << "\n";
  std::cout << c3 << "\n";




  return 0;
}