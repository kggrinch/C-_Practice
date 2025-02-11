#include "Circle.h"
#include <iostream>

Circle::Circle() : radius_(0), diameter_(0)
{

}

Circle::Circle(double radius) : radius_(radius), diameter_(calculateDiameter())
{

}

double Circle::radius() const
{
  return radius_;
}

void Circle::set_radius(double radius)
{
  radius_ = radius;
}

double Circle::diameter() const
{
  return diameter_;
}

double Circle::calculateDiameter()
{
  return diameter_ = radius_*2;
}

Circle Circle::operator+(const Circle& other) const
{
  Circle temp(radius_ + other.radius_);
  temp.calculateDiameter();
  return temp;
}

Circle& Circle::operator+=(const Circle& other)
{
  this->radius_ += other.radius_;
  this->calculateDiameter();
  return *this;
}

// This allows you to modify the current object to be negative. If you want to just assign other values to be negative without cahnging the current value like this:
// b = -a;
// b is now negative but a remains positive.
// To do this you need to create this same thing but without returning a reference and returning a copy Circle.
// Circle& Circle::operator-()
// {
//   this->radius_ = -this->radius_;
//   this->calculateDiameter();
//   return *this;
// }
Circle Circle::operator-()
{
  return Circle(-radius_);
}

// Circle& Circle::operator=(const Circle& other)
// {
//   this->radius_ = other.radius_;
//   this->calculateDiameter();
//   return *this;
// }



bool Circle::operator>(const Circle& other) const
{
  if(radius_ > other.radius_)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool Circle::operator>=(const Circle& other) const
{
  if(radius_ >= other.radius_)
  {
    return true;
  }
  else
  {
    return false;
  }
}

std::ostream& operator<<(std::ostream& stream, const Circle& other)
{
  stream << "Radius: " + std::to_string(other.radius()) << " Diameter: " << std::to_string(other.diameter());
  return stream;
}

std::istream& operator>>(std::istream& stream, Circle& other)
{ 
  double tempRadius;
  stream >> tempRadius;
  other.set_radius(tempRadius);
  return stream;
}


 


