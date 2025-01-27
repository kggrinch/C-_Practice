#include <iostream>
#include <algorithm>

bool conversion(int value, int base, std::string& result)
{
// Create digit conversion
std::string static kDigital = "0123456789ABCDEF";

// Check if correct values passed in
if(value < 0 || base < 2 || base > 16)
{
  return false;
}

if(value < base)
{
	result += kDigital[value];
	std::reverse(result.begin(), result.end()); // use a algorithm library to reverse the string
	return true; // return true here
}
else
{
	result += kDigital[value % base];
	return conversion(value/base, base, result);
}
}


// Conversion to decimal
bool toDecimal(const std::string& value, int base, int& result) {
    result = 0;

    if (base < 2 || base > 16) {
        return false;
    }

    for (char c : value) {
        int digit_value = (c >= '0' && c <= '9') ? c - '0' : 
                          (c >= 'A' && c <= 'F') ? c - 'A' + 10 :
                          (c >= 'a' && c <= 'f') ? c - 'a' + 10 : -1;

        if (digit_value < 0 || digit_value >= base) 
        {
          return false; 
        }

        result = result * base + digit_value;
    }

    return true;

}



int main()
{
  std::string resultString = "";
  int result = 6453;
  int base = 16;
  conversion(result, base, resultString);
  std::cout << resultString << "\n";

  std::string hex = "110111000001";
  int nresult = 0;
  int nbase = 2;
  toDecimal(hex, nbase, nresult);
  std::cout << nresult << "\n";


}