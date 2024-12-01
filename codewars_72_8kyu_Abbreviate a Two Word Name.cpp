// https://www.codewars.com/kata/57eadb7ecd143f4c9c0000a3

#include <string>

std::string abbrevName(std::string name)
{
  std::string res {"..."}; 
  auto pos = name.find(" ");
  res[0] = std::toupper(name[0]); 
  res[2] = std::toupper(name[pos+1]); 
  
  return   res; 
}
