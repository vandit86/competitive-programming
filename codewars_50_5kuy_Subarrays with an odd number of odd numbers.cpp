/**
https://www.codewars.com/kata/6155e74ab9e9960026efc0e4
Implement a function which takes an array of nonnegative integers and returns the number of subarrays with an odd number of odd numbers. Note, a subarray is a contiguous subsequence.
*/

#include <vector>

long long solve(const std::vector<int> &arr) {
    size_t count = 0;
    size_t even = 0;
    size_t sum = 0;  
    size_t odd = 0;

    // traverse in the array
    for (size_t i = 0; i < arr.size(); i++) 
    {
        sum += (arr[i]&1);

        if (sum & 1){
            odd++;
            count ++; 
            count += even;
        }
        else {
            count += odd;
            even ++; 
        }
    }

    return count;
}
