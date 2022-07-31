/**
 * https://www.codewars.com/kata/585d7d5adb20cf33cb000235/train/cpp
 * Find the unique number: here is an array with some numbers. All numbers are equal except for one. Try to find it!
*/

#include <algorithm>
#include <vector>
#include <iostream>

float find_uniq(const std::vector<float> &v)
{
    std::vector<float> vCop (v); 
    std::unique (vCop.begin(), vCop.end()); 
    //for (auto i : vCop) std::cout << i << " " << std::endl; 
    return vCop[1];
}

int main (){
    const std::vector<float> test {
                //999.666,  999.666, 999.666, 999.666, 999.666, 999.666, 999.666, 999, 999.666
                1, 1, 1, 1, 2, 1, 1, 1, 1
            }; 
            
    std::cout << find_uniq (test); 
}
