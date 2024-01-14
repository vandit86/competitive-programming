/**
https://www.codewars.com/kata/5264d2b162488dc400000001
Write a function that takes in a string of one or more words, and returns the same string, but with all words that have five or more letters reversed (Just like the name of this Kata).
Strings passed in will consist of only letters and spaces. Spaces will be included only when more than one word is present.
*/

#include <string>
#include <iostream>
#include <algorithm> 

using namespace std; 

std::string spinWords(const std::string &s)
{   
    string str {s}; 
    auto iA = str.begin(); 
    for (auto iB = str.begin(); iB != str.end(); iB ++){
        if (*iB == ' '){
            if (std::distance (iA, iB) >= 5){
                reverse(iA,iB); 
            }
            iA = iB+1; 
        }
    }
    if (std::distance (iA, str.end()) >= 5)
        reverse(iA,str.end()); 

    return str;
}// spinWords
