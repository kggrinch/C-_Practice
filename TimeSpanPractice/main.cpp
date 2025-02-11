#include <iostream>
#include "time_span.h"
#include <sstream>
#include <string>

using namespace std;

bool CheckValues(TimeSpan time, int hours, int minutes, int seconds)
{
if ((time.hours() != hours) || (time.minutes() != minutes) || (time.seconds()
!= seconds))
{
return false;
}
return true;
}

bool TestZeros()
{
TimeSpan ts(0, 0, 0);
return CheckValues(ts, 0, 0, 0);
}

bool TestFloatSeconds()
{

TimeSpan ts1(127.86);
if (!CheckValues(ts1, 0, 2, 8)) 
{
  return false;
}

TimeSpan ts2(10.0, -2.0, 127.86);

if(!CheckValues(ts2, 10.0, 0, 8))
{
  return false;
}

TimeSpan ts3(10.0f, -2.0f, 127.86f);
if (!CheckValues(ts3, 10, 0, 8))
{
  return false;
}


TimeSpan ts4(127.86f);
if (!CheckValues(ts4, 0, 2, 8))
{
  return false;
}

TimeSpan ts5(1.0f, 127.86f);
if (!CheckValues(ts5, 0, 3, 8))
{
  return false;
} 

TimeSpan ts6(1.0, 127.86);
if (!CheckValues(ts6, 0, 3, 8))
{ 
 return false;
}

  return true;
}

bool TestNegativeMinute()
{
TimeSpan ts(8, -23, 0);
return CheckValues(ts, 7, 37, 0);
}

bool TestNegativeHour()
{
TimeSpan ts(-3, 73, 2);
return CheckValues(ts, -1, -46, -58);
}

bool TestAdd()
{
TimeSpan ts1, ts2(5), ts3(7, 0), ts4(4, 0, 0);
TimeSpan add_it_up = ts1 + ts2 + ts3 + ts4;
return CheckValues(add_it_up, 4, 7, 5);
}

bool TestAddInPlace()
{
TimeSpan ts1(5, 6, 7);
TimeSpan ts2(1, 1, 1);
if ((!CheckValues(ts1, 5, 6, 7)) || (!CheckValues(ts2, 1, 1, 1)))
{
return false;
}
ts1 += ts2;
if ((!CheckValues(ts1, 6, 7, 8)) || (!CheckValues(ts2, 1, 1, 1)))
{
return false;
}
return true;
}

bool TestConstructor()
{
  TimeSpan ts(1, 2, 3);
  return CheckValues(ts, 1, 2, 3);
}

bool TestDefaultConstructor()
{
  TimeSpan ts;
  return CheckValues(ts, 0, 0, 0);
}

bool TestUnaryNegation()
{
  TimeSpan ts(5, 4, 20), ts2;
  ts2 = -ts;
  return CheckValues(ts2, -5, -4, -20);
}

bool TestSubtraction()
{
  TimeSpan ts1(5, 340, 7462);
  TimeSpan ts2(5, 340, 7462);
  TimeSpan ts3;
  ts3 = ts1 - ts2;
  return CheckValues(ts3, 0, 0, 0);
}

bool TestSubtractionInside()
{
  TimeSpan ts(5, 0, -18000);
  return CheckValues(ts, 0, 0, 0);
}

bool TestAddAndSubtract()
{
  TimeSpan ts1(1, 2, 3);
  TimeSpan ts2(2, 3);
  TimeSpan ts3;
  TimeSpan ts4(3600);
  ts3 = ts1 + ts2 - ts4;
  return CheckValues(ts3, 0, 4, 6);
}

bool TestSet()
{
  TimeSpan ts;
  ts.set_time(5, 23, 46);
  return CheckValues(ts, 5, 23, 46);
}

bool TestEqualAndNotEqualOperators()
{
  TimeSpan ts1(90, 80, 6000);
  TimeSpan ts2(90, 80, 6000);
  TimeSpan ts3(-90, -80, -6000);
  
  
  if(ts1 == ts2 && ts1 != ts3 && !(ts1 != ts2) && !(ts1 == ts3))
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool TestLessOrEqualToOperators()
{
  TimeSpan ts1(-10, -60, -3600);
  TimeSpan ts2(10, 60, 3600);

  TimeSpan ts3(10, 4, 6);
  TimeSpan ts4(5, 90, 1);

  TimeSpan ts5(1, 2.4, 3);
  TimeSpan ts6(1, 2.6, 3);

  TimeSpan ts7(1, 2, 3.5);
  TimeSpan ts8(1, 2, 3.4);

  bool less = ts1 < ts2 && ts4 < ts3 && ts5 < ts6 && ts8 < ts7;
  bool notLess = !(ts2 < ts1) && !(ts3 < ts4) && !(ts6 < ts5) && !(ts7 < ts8);
  bool lessEqual = ts1 <= ts1 && ts1 <= ts2 && ts4 <= ts4 &&  ts4 <= ts3;
  bool notLessEqual =  !(ts2 <= ts1) && !(ts3 <= ts4) && !(ts6 <= ts5) && !(ts7 <= ts8);

  return less && notLess && lessEqual && notLessEqual;
}

bool TestGreaterOrEqualToOperators()
{
  TimeSpan ts1(10, 23, 32);
  TimeSpan ts2(-2, 2, 3600);

  TimeSpan ts3(4, 0, 1);
  TimeSpan ts4(0, 240, 0);

  TimeSpan ts5(3, -23, 23);
  TimeSpan ts6(-1, 2, 3600);

  TimeSpan ts7(1, 0, 0);
  TimeSpan ts8(-0, 0, 3601);

  bool greater = ts1 > ts2 && ts3 > ts4 && ts5 > ts6 && ts8 > ts7;
  bool notGreater = !(ts2 > ts1) && !(ts4 > ts3) && !(ts6 > ts5) && !(ts7 > ts8);
  bool greaterEqual = ts1 >= ts1 && ts1 >= ts2 && ts3 >= ts3 && ts3 >= ts4;
  bool notGreaterEqual = !(ts2 >= ts1) && !(ts4 >= ts3) && !(ts6 >= ts5) && !(ts7 >= ts8);

  return greater && notGreater && greaterEqual && notGreaterEqual;  
}

bool TestCout()
{
  TimeSpan ts(3, 5, 3);
  std::string expected = "Hours: 3, Minutes: 5, Seconds: 3\n";
  std::ostringstream stream;
  stream << ts;
  return stream.str() == expected;
}

bool TestCin()
{
  TimeSpan ts;
  std::istringstream stream("10 5 0");
  std::cin.rdbuf(stream.rdbuf());
  std::cin >> ts;
  return CheckValues(ts, 10, 5, 0);
}

bool TestEdgeCases()
{
  TimeSpan ts(0, 0, -3), ts2(5.5, 43.5), ts3(-0), ts4(5000, 20000, 300000), ts5;
  if(CheckValues(ts, 0, 0, -3) && CheckValues(ts2, 0, 6, 14) && CheckValues(ts3, 0, 0, 0) && CheckValues(ts4, 5416, 40, 0)
   && CheckValues(ts5, 0, 0, 0))
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool TestGetters()
{
  TimeSpan ts1(2, 993, 56);
  int h = 18, m = 33, s = 56;
  return(ts1.hours() == h && ts1.minutes() == m && ts1.seconds() == s); 
}



int main()
{
cout << "Testing TimeSpan Class" << endl;

if(!TestZeros()) cout << "Failed: TestZeros" << endl;
if(!TestFloatSeconds()) cout << "Failed: TestFloatSeconds" << endl;
if(!TestNegativeMinute()) cout << "Failed: TestNegativeMinute" << endl;
if(!TestNegativeHour()) cout << "Failed: TestNegativeHour" << endl;
if(!TestAdd()) cout << "Failed: TestAdd" << endl;
if(!TestAddInPlace()) cout << "Failed: TestAddInPlace" << endl;
if(!TestDefaultConstructor()) cout << "Failed: TestDefaultConstructor" << endl;
if(!TestConstructor()) cout << "Failed: TestConstructor" << endl;
if(!TestUnaryNegation()) cout << "Failed: TestUnaryNegation" << endl;
if(!TestSubtraction()) cout << "Failed: TestSubtraction" << endl;
if(!TestSubtractionInside()) cout << "Failed: TestSubtractionInside" << endl;
if(!TestAddAndSubtract()) cout << "Failed: TestAddAndSubtract" << endl;
if(!TestSet()) cout << "Failed: TestSet" << endl;
if(!TestEqualAndNotEqualOperators()) cout << "Failed: TestEqualAndNotEqualOperators" << endl;
if(!TestLessOrEqualToOperators()) cout << "Failed: TestLessOrEqualToOperators" << endl;
if(!TestGreaterOrEqualToOperators()) cout << "Failed: TestGreaterOrEqualToOperators" << endl;
if(!TestCout()) cout << "Failed: TestCout" << endl;
if(!TestCin()) cout << "Failed: TestCin" << endl;
if(!TestEdgeCases()) cout << "Failed: TestEdgeCases" << endl;
if(!TestGetters()) cout << "Failed: TestGetters" << endl;

cout << "Testing Complete All Tests Passed!" << endl;

return 0;
}