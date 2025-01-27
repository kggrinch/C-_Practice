#include <iostream>
#include <vector>
#include "garden.h"




int main()
{

  Garden::Plant my_plant1;
  my_plant1.name = "Cactus";

  Garden::Plant my_plant2;
  my_plant2.name = "Rose";

  Garden my_garden;
  my_garden.plant_in_garden(my_plant1);
  my_garden.plant_in_garden(my_plant2);

  my_garden.view_garden();

  my_plant1 = my_garden.dig_up(1);

  my_garden.view_garden();

  my_plant1 = my_garden.dig_up(1);

  std::cout << my_plant1.name << "\n";


  




  return 0;
}