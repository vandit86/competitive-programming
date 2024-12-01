// https://www.codewars.com/kata/541c8630095125aba6000c00
#include <string>

int digital_root(int n)
{
     
    auto str = std::to_string(n);
    
    while (str.length()>1){
      
      int res = 0;   
      for (const auto& i : str){
          res +=  i - '0'; 
      }
      str = std::to_string(res);
    } 
    
    return std::stoi (str); 
}
