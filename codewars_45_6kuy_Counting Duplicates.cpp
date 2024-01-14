/**
https://www.codewars.com/kata/54bf1c2cd5b56cc47f0007a1
Write a function that will return the count of distinct case-insensitive alphabetic characters and numeric digits that occur more than once in the input string. 
The input string can be assumed to contain only alphabets (both uppercase and lowercase) and numeric digits.
*/

#include <algorithm>
#include <cctype>
#include <string>
#include <iostream>
#include <array>

size_t duplicateCount(const std::string& in)
{	
	std::array<uint32_t, 128> v {};
	for (auto& c : in) v[std::tolower(c)]++; 
 return  std::count_if(v.begin(), v.end(), [](uint32_t i) { return i > 1; });;
}

size_t duplicateCount(const std::string& in)
{	
	constexpr int size = 128; 
	uint32_t vec [size] = {};
	uint32_t res = 0; 
	for (auto c : in){
		vec[std::tolower(c)]++; 
	}
	for (size_t i = 0 ; i < size ; i ++)
		if ( vec[i]>1)
			res ++; 
 return res;
}
