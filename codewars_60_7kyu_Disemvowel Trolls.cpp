// https://www.codewars.com/kata/52fba66badcd10859f00097e

#include <string>

std::string disemvowel( const std::string& strIn) {
    std::string vowels = "aeiouAEIOU";
    std::string str {strIn};
    for (size_t i = 0; i < str.size(); ) {
        if (vowels.find(str[i]) != std::string::npos) {
            str.erase(i, 1);
        } else {
            ++i; 
        }
    }
  return str; 
}
