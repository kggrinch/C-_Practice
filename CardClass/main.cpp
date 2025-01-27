#include <iostream>
#include "Card.h"


int main()
{
  
  Card card(5, kDiamond);
  std::cout << card << "\n";

  std::cout << card.suit() << "\n";


  return 0;
}