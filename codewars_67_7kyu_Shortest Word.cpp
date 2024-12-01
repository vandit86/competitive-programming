// https://www.codewars.com/kata/57cebe1dc6fdc20c57000ac9

#include <string>
int find_short(std::string str)
{
  int res{100000}, count{0}; 
  for (const auto i : str){
    if (i == ' '){
      res = (count < res)? count:res;
      count = 0; 
    }
    else count++; 
  }
  return res = (count < res)? count:res;
}
