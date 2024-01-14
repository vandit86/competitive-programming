/** https://www.codewars.com/kata/525f4206b73515bffb000b21
We need to sum big numbers and we require your help.
Write a function that returns the sum of two numbers. The input numbers are strings and the function must return a string.
*/

#include <string>
#include <iostream>     // std::cout
#include <sstream>      // std::stringstream
#include <algorithm>

using namespace std ; 

std::string add(const std::string& a, const std::string& b) {
  auto rest = 0; 
  stringstream ss; 
  for (auto ap = a.rbegin(), bp = b.rbegin(); 
        ap < a.rend() || bp < b.rend(); ap ++, bp++ ){  
    auto numA = (ap >=a.rend())? 0 : *ap-'0';
    auto numB = (bp >=b.rend())? 0 : *bp-'0'; 
    auto numC = numA + numB + rest; 
    rest = (numC>9)? 1 : 0; 
    ss << numC%10; 
  }
  if (rest) ss << 1; 
  auto res = ss.str();  
  std::reverse(res.begin(), res.end());
  return res;
}
