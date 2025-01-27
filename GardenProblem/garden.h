#ifndef GARDEN_H_
#define GARDEN_H_
#include <iostream>
#include <vector>


class Garden
{
  public:
    Garden();

    struct Plant
    {
       std::string name; 
    };

    void plant_in_garden(const Plant& plant);

    Plant dig_up(const int& index);

    void view_garden() const;

  private:

    std::vector<Plant> garden_;

};


#endif