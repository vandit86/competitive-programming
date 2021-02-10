// https://www.codewars.com/kata/517abf86da9663f1d2000003/train/cpp

#include <string>

std::string to_camel_case(std::string text) {
  // TODO: Your code goes here!
  char under = '_'  ;
  char dash = '-'   ;
  char val = '\0'; 
  std::string out;              // out string 
  out.reserve(text.length());   // reserve memmory
  bool found = false;    
  
    for (char const &c: text){
        val = c; 
        if (val == under || val == dash){found = true; continue;}
        if (found){
            val = toupper(c);
            found = false; 
        }
        out.push_back(val); 
    }
    return out; 
}