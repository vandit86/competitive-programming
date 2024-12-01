//https://www.codewars.com/kata/5266876b8f4bf2da9b000362

#include <string>
#include <vector>
 
std::string likes(const std::vector<std::string> &names)
{
  auto n = names.size(); 
  switch (n){
      case 0 : return "no one likes this";
      case 1 : return names[0] + " likes this"; 
      case 2 : return names[0] + " and " + names[1] + " like this";
      case 3 : return names[0] + ", " + names[1] + " and " + names[2] + " like this";
      default: return names[0] + ", " + names[1] + " and " + std::to_string(n-2) + " others like this";
  }
     
}
