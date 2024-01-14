/**
https://www.codewars.com/kata/51f2d1cafc9c0f745c00037d
Complete the solution so that it returns true if the first argument(string) passed in ends with the 2nd argument (also a string).
*/

#include <string>
bool solution(std::string const &str, std::string const &ending) {
    if (str.length() < ending.length()) return false; 
    for (auto i = ending.rbegin(), j = str.rbegin(); i != ending.rend() ; i++, j++){
        if (*i != *j ) return false; 
    }
    return true;
}
