/**
https://www.codewars.com/kata/546e2562b03326a88e000020
ou are asked to square every digit of a number and concatenate them.

*/

#include <string>

int square_digits(int num) {
    auto s = std::to_string(num);
    std::string res; 
    for (auto i : s){
        res+= std::to_string ((i - '0')*(i - '0')); 
    }
    return stoi(res);
}
