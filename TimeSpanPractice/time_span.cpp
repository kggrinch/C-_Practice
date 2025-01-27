#include "time_span.h"
#include <iostream>
#include <string>
#include <cmath>

// Default constructor - sets attribute to 0
TimeSpan::TimeSpan() : a_seconds_(0), a_minutes_(0), a_hours_(0)
{

}

// Constructors call the set_time() method
// Constructor - sets given seconds. sets the rest to 0.
TimeSpan::TimeSpan(double seconds) : a_seconds_(0), a_minutes_(0), a_hours_(0)
{
  set_time(0, 0, seconds);
}

// Constructor - sets given seconds and minutes. Sets the rest to 0    
TimeSpan::TimeSpan(double minutes, double seconds) : a_seconds_(0), a_minutes_(0), a_hours_(0) 
{
  set_time(0, minutes, seconds);
}

// Constructor - sets given seconds, minutes, and hours. 
TimeSpan::TimeSpan(double hours, double minutes, double seconds) : a_seconds_(0), a_minutes_(0), a_hours_(0)
{
  set_time(hours, minutes, seconds);
}

// returns hours
int TimeSpan::hours() const
{
  return a_hours_;
}

// returns minutes
int TimeSpan::minutes() const
{
  return a_minutes_;
}

// returns seconds
int TimeSpan::seconds() const
{
  return a_seconds_;
}

// Outputs time formatted
void TimeSpan::get_time() const
{
  std::cout << "Hours: " << hours() << ", " << "Minutes: " << minutes() << ", " << "Seconds: " << seconds() << "\n";
}

// returns string of time formatted
std::string TimeSpan::return_time_string() const
{
  return "Hours: " + std::to_string(hours()) + ", " + "Minutes: " + std::to_string(minutes()) + ", " + "Seconds: " + std::to_string(seconds());
}

// private method that sets the hours
void TimeSpan::set_hours(double hours)
{
  this->a_hours_ = (int)hours;
}

// private method that sets the minutes
void TimeSpan::set_minutes(double minutes)
{
  if(minutes >= 60)
  {
    set_hours(minutes / 60);
    this->a_minutes_ = (int)minutes % 60;
  }
  else if(minutes <= 0)
  {
    set_hours(minutes / 60);
    this->a_minutes_ = (int)minutes % 60;
  }
  else
  {
     this->a_minutes_ = (int)minutes;
  }
}

// private method that sets the seconds
void TimeSpan::set_seconds(double seconds)
{
  if(seconds >= 60)
  {
    set_minutes(seconds / 60);
    this->a_seconds_ = (int)seconds % 60;
  }
  else if(seconds <= 0)
  {
    set_minutes(seconds / 60);
    this->a_seconds_ = (int)seconds % 60;
  }
  else
  {
    this->a_seconds_ = (int)seconds;
  }
}

// Primary method that sets the time      
void TimeSpan::set_time(double hours, double minutes, double seconds)
{
  // Break all given parameters into total_seconds
  double total_seconds = hours * 3600;
  total_seconds += minutes * 60;
  total_seconds += seconds;
  
  // Round total seconds if needed
  total_seconds = std::round(total_seconds);

  // give total_seconds to set_seconds() function.
  set_seconds(total_seconds);
}

// overloading operator +=
TimeSpan& TimeSpan::operator+=(const TimeSpan& other)
{
  this->set_time(a_hours_ + other.a_hours_, a_minutes_ + other.a_minutes_, a_seconds_ + other.a_seconds_);
  return *this;
}

 // overloading operator -= 
TimeSpan& TimeSpan::operator-=(const TimeSpan& other)
{
  this->set_time(a_hours_ - other.a_hours_, a_minutes_ - other.a_minutes_, a_seconds_ - other.a_seconds_);
  return *this;
}

// overloading operator +
TimeSpan TimeSpan::operator+(const TimeSpan& other) const
{
  return TimeSpan(a_hours_ + other.a_hours_, a_minutes_ + other.a_minutes_, a_seconds_ + other.a_seconds_);
}

// overloading operator -
TimeSpan TimeSpan::operator-(const TimeSpan& other) const
{
  return TimeSpan(a_hours_ - other.a_hours_, a_minutes_ - other.a_minutes_, a_seconds_ - other.a_seconds_);
}

// overloading operator -unary negation
TimeSpan TimeSpan::operator-()
{
  return TimeSpan(-a_hours_, -a_minutes_, -a_seconds_);
}

 // overloading operator ==
bool TimeSpan::operator==(const TimeSpan& other) const
{
  return a_hours_ == other.a_hours_ && a_minutes_ == other.a_minutes_ && a_seconds_ == other.a_seconds_;
}

 // overloading operator != 
bool TimeSpan::operator!=(const TimeSpan& other) const
{
  return a_hours_ != other.a_hours_ || a_minutes_ != other.a_minutes_ || a_seconds_ != other.a_seconds_;
}

  // overloading operator >
bool TimeSpan::operator>(const TimeSpan& other) const
{
  if(a_hours_ > other.a_hours_)
  {
    return true;
  }
  else if(a_hours_ < other.a_hours_)
  {
    return false;
  }
  else if(a_minutes_ > other.a_minutes_)
  {
    return true;
  }
  else if(a_minutes_ < other.a_minutes_)
  {
    return false;
  }
  else if(a_seconds_ > other.a_seconds_)
  {
    return true;
  }
  else if(a_seconds_ < other.a_seconds_)
  {
    return false;
  }
  else
  {
    return false;
  }
}

// overloading operator <
bool TimeSpan::operator<(const TimeSpan& other) const
{
  if(a_hours_ < other.a_hours_)
  {
    return true;
  }
  else if(a_hours_ > other.a_hours_)
  {
    return false;
  }
  else if(a_minutes_ < other.a_minutes_)
  {
    return true;
  }
  else if(a_minutes_ > other.a_minutes_)
  {
    return false;
  }
  else if(a_seconds_ < other.a_seconds_)
  {
    return true;
  }
  else if(a_seconds_ > other.a_seconds_)
  {
    return false;
  }
  else
  {
    return false;
  }
}

 // overloading operator >=
bool TimeSpan::operator>=(const TimeSpan& other) const
{
  if(a_hours_ > other.a_hours_)
  {
    return true;
  }
  else if(a_hours_ < other.a_hours_)
  {
    return false;
  }
  else if(a_minutes_ > other.a_minutes_)
  {
    return true;
  }
  else if(a_minutes_ < other.a_minutes_)
  {
    return false;
  }
  else if(a_seconds_ >= other.a_seconds_)
  {
    return true;
  }
  else if(a_seconds_ < other.a_seconds_)
  {
    return false;
  }
  else
  {
    return false;
  }    
}

// overloading operator <=
bool TimeSpan::operator<=(const TimeSpan& other) const
{
  if(a_hours_ < other.a_hours_)
  {
    return true;
  }
  else if(a_hours_ > other.a_hours_)
  {
    return false;
  }
  else if(a_minutes_ < other.a_minutes_)
  {
    return true;
  }
  else if(a_minutes_ > other.a_minutes_)
  {
    return false;
  }
  else if(a_seconds_ <= other.a_seconds_)
  {
    return true;
  }
  else if(a_seconds_ > other.a_seconds_)
  {
    return false;
  }
  else
  {
    return false;
  }    
}

 // overloading operator Cout << 
std::ostream& operator<<(std::ostream& stream, const TimeSpan& other)
{
  stream << other.return_time_string() << "\n";
  return stream;
}

    // overloading operator Cin >>
std::istream& operator>>(std::istream& stream, TimeSpan& other)
{
  double temp_hours, temp_minutes, temp_seconds;
  stream >> temp_hours >> temp_minutes >> temp_seconds;
  other.set_time(temp_hours, temp_minutes, temp_seconds);
  return stream;
}