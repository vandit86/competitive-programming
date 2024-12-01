// https://www.codewars.com/kata/55b42574ff091733d900002f

#include <string>
#include <vector>

std::vector<std::string> friendOrFoe(const std::vector<std::string>& input) {
  std::vector<std::string> out{};    
  for (const auto& name : input){
    if (name.length()==4){
      out.push_back(name); 
    }
  }    
    return out;
}
