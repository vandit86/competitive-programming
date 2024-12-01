// https://www.codewars.com/kata/546f922b54af40e1e90001da

#include <string>
#include <cctype> // for std::tolower


std::string alphabet_position(const std::string &text) {
  std::string res = ""; 
  
  for (char i : text){
    if (!std::isalpha(i)) continue;
      res+= std::to_string( std::tolower(i) - 'a' + 1) + " "; 
  }
  if (!res.empty()) res.pop_back(); 
  return res;
}
