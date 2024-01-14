/**
https://www.codewars.com/kata/529e2e1f16cb0fcccb000a6b
We need the ability to divide an unknown integer into a given number of even parts - or at least as even as they can be. 
The sum of the parts should be the original value, but each part should be an integer, and they should be as close as possible.
Complete the function so that it returns an array of integers representing the parts. 
If the input number is too small to split it into requested amount of parts, the additional parts should have value 0. 
Ignoring the order of the parts, there is only one valid solution for each input to your function!
*/

#include <string>
#include <iostream>
#include <algorithm> 
#include <vector>

using namespace std; 

std::vector<int> splitInteger(int num, int parts) {
  
    vector<int> res (parts,0);  
    int v = num/parts;   // integer devision
    size_t  last = 0; 
    if (v == 0){
        last = num;  
    }
    else{
        fill(res.begin(), res.end(),v);
        last = num - v*parts; 
    }
    std::for_each(res.rbegin(), res.rbegin() + last, [](int &i){i++;}); 
    return res;
}
