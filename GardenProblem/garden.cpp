#include "garden.h"
#include <iostream>
#include <vector>

Garden::Garden()
{

}

void Garden::plant_in_garden(const Plant& plant)
{
  garden_.push_back(plant); // Planted the plant in the garden
}

Garden::Plant Garden::dig_up(const int& index)
{
  if(index < 0 || index >= garden_.size())
  {
    Plant emptyPlant;
    return emptyPlant;
  }
  else
  {
    Plant returnedPlant = garden_[index];
    garden_.erase(garden_.begin() + index);
    return returnedPlant;
  }
}

void Garden::view_garden() const
{
  for(int i = 0; i < garden_.size(); i++)
  {
    std::cout << garden_[i].name << " ";
  }
  std::cout << "\n";
}