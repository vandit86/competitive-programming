// https://www.codewars.com/kata/52597aa56021e91c93000cb0

#include <vector>

std::vector<int> move_zeroes(const std::vector<int>& input) {
  std::vector<int> out (input.size(), 0);
  std::size_t i = 0; 
  for ( auto v : input){
    if (v){
      out[i++]=v;
    }
  }
  return out; 
}
