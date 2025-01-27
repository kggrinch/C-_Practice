#ifndef CIRCLE_H_
#define CIRCLE_H_
#include <iostream>

class Circle
{ 
  public:
  // Constructors
    Circle();

    Circle(double radius);

  // getter 
    double radius() const;
  // setter
    void set_radius(double radius);
  // other methods
    double diameter() const;
  // overlaod operators
    Circle operator+(const Circle& other) const;

    Circle& operator+=(const Circle& other);

    // Circle& operator-();
    Circle operator-();

    // Circle& operator=(const Circle& other);

    bool operator>(const Circle& other) const; 

    bool operator>=(const Circle& other) const;

    friend std::ostream& operator<<(std::ostream& stream, const Circle& other);

    friend std::istream& operator>>(std::istream& stream, Circle& other);

  private:
    // Private attribute
    double radius_;
    double diameter_;

    // private method()
    double calculateDiameter();

};


#endif