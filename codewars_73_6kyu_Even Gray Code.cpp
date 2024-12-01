// https://www.codewars.com/kata/66dc904c177237f5b3e9eb5f

#include <iostream>
using namespace std; 

std::string even_gray_code(int size, int position) {
  
  auto res = std::string(size, '0');  
  auto invert = [](char c)->char{
    return (c == '0')? '1':'0'; 
  }; 
  
  for (int i = 1 ; i <= position ; i++){  
    for (int pos = 2; pos <=size ; pos ++){  
        
      auto start = size-pos;   
      auto val = res.substr (start, 2); 
        
      if (val == "00") {
          res.replace(start, 2, "11");
          break; 
      }
      else if (val == "01"){
        res.replace(start, 2, "10");
        // invert all pairs to end 
        for (int j = start+2 ; (j+1) < size ; j=j+2){
          res[j] = invert (res[j]);
          res[j+1] = invert (res[j+1]); 
        }
          break;
      }
      else continue; 
      }
  }
  return res;
}
