/**
	https://www.codewars.com/kata/55c6126177c9441a570000cc/train/cpp
	Weight for weight
	
	Given a string with the weights of FFC members in normal order can you give this string ordered by "weights" of these numbers?
	When two numbers have the same "weight", let us class them as if they were strings (alphabetical ordering) and not numbers:
*/

#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>


struct Number {
	int num; 
	std::string numStr; 
}; 

class WeightSort
{
public:
    std::string orderWeight(const std::string &strng);
};

std::string WeightSort::orderWeight (const std::string &str){
	
    std::string buf,output;          // Have a buffer string
    std::stringstream ss(str);       // Insert the string into a stream
	std::vector <Number> nums; 		
    
    while (ss >> buf){
		int i =0; 
		for (char& c : buf){
			i += (c - '0');  
		}
		nums.push_back(Number());
		nums.back().num = i; 
		nums.back().numStr = buf; 
	}
	
	
	// Using lambda expressions in C++11
	std::sort(nums.begin(), nums.end(), [](const Number& lhs, const Number& rhs) {
		//return lhs.key < rhs.key;
		if (lhs.num < rhs.num) return true; 
		else if (lhs.num == rhs.num) {
			int c = lhs.numStr.compare(rhs.numStr); 
			if (c < 0) return true; 
		}
		return false; 
	});	
	
	for (auto& c : nums){
		//std::cout << c.numStr << " ";
		output+=c.numStr;
		output+=" "; 
	}
	if (!output.empty())
		output.pop_back();
	return output; 
}

int main (){
	WeightSort ws; 
	std::string str = ws.orderWeight("103 123 4444   99 2000  ");
	std::cout << str; 
	return 0; 
}

