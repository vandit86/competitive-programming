
// https://www.codewars.com/kata/5277c8a221e209d3f6000b56/train/cpp
/**
 * Write a function that takes a string of braces, and determines if the order of the braces is valid. 
 * It should return true if the string is valid, and false if it's invalid.

*/

#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std; 

bool valid_braces(std::string braces) 
{   
    std::unordered_map<char, char> uMap = {
        {'{' , '}'}, 
        {'(' , ')'}, 
        {'[' , ']'} 
    };
    
    std::stack<char> mStk;
    
    for (char ch : braces){     
        auto res = uMap.find(ch); 
        if (res != uMap.end())
            mStk.push(ch); 
        else {
            if (!mStk.empty() && uMap[mStk.top()] == ch)  
                mStk.pop();
            else return false; 
        }
    }
  return true; 
}


int main() {
    
    auto res = valid_braces ("(())"); 
    std::cout << res << std::endl;
    return 0;
}
