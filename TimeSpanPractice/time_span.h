#ifndef TIME_SPAN_H_
#define TIME_SPAN_H_
#include <iostream>

class TimeSpan
{
  public:

    // Default constructor
    TimeSpan();

    // Constructor with just seconds given
    TimeSpan(double seconds);

    // Constructor with just minutes and seconds given
    TimeSpan(double minutes, double seconds);

    // Constructor with hours, minutes, and seconds given
    TimeSpan(double hours, double minutes, double seconds);

    // getter retuns hours
    int hours() const;

    // getter returns minutes
    int minutes() const;

    // getter returns seconds
    int seconds() const;

    // Outputs time formatted
    void get_time() const;

    // Returns time formatted as string
    std::string return_time_string() const;

    // setter sets time given parameters (uses set_hours, set_minutes, and set_seconds helper functions)
    void set_time(double hours, double minutes, double seconds);

    // overloading operator +=
    TimeSpan& operator+=(const TimeSpan& other);

    // overloading operator -= 
    TimeSpan& operator-=(const TimeSpan& other);

    // overloading operator +
    TimeSpan operator+(const TimeSpan& other) const;

    // overloading operator -
    TimeSpan operator-(const TimeSpan& other) const;

    // overloading operator -unary negation
    TimeSpan operator-();

    // overloading operator ==
    bool operator==(const TimeSpan& other) const;

    // overloading operator !=
    bool operator!=(const TimeSpan& other) const;

    // overloading operator >
    bool operator>(const TimeSpan& other) const;

    // overloading operator <
    bool operator<(const TimeSpan& other) const;
        
    // overloading operator >=    
    bool operator>=(const TimeSpan& other) const;

    // overloading operator <=
    bool operator<=(const TimeSpan& other) const;

    // overloading operator Cout << 
    friend std::ostream& operator<<(std::ostream& stream, const TimeSpan& other);

    // overloading operator Cin >>
    friend std::istream& operator>>(std::istream& stream, TimeSpan& other);

  private:
    
    // private attributes
    int a_hours_;
    int a_minutes_;
    int a_seconds_;

    // private set hours, minutes, and seconds functions
    void set_hours(double hours);

    void set_minutes(double minutes);

    void set_seconds(double seconds);
};

#endif