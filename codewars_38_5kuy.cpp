/**
* 	https://www.codewars.com/kata/55aa075506463dac6600010d/train/cpp
*  5Kyu
* Integers: Recreation One
* Find all integers between m and n (m and n integers with 1 <= m <= n) such that the sum of their squared divisors is itself a square.
*/


#include <utility>
#include <vector>
#include <iostream>
#include <numeric>      // std::accumulate
#include <algorithm>
#include <cmath>

using namespace std ; 
class SumSquaredDivisors
{
public:
    static std::vector<std::pair<long long, long long>> listSquared(long long m, long long n){
		
		std::vector<std::pair<long long, long long>> res; 
		vector<long> divs;
		
		for (long num = m ; num <= n ; num ++){
			for (long i = 1 ; i*i <= num ; i ++){
				if (num % i == 0) {
					divs.push_back(i);
					if (i != num/i)
						divs.push_back(num/i);
				}
			}
			 
			std::for_each(divs.begin(), divs.end(), [](long &k){ k = k*k; });			
			double sum = (double) std::accumulate (divs.begin(), divs.end(), 0); 
			if (ceil(sqrt(sum)) == floor(sqrt(sum))) {
				auto p = std::make_pair(num,sum);
				res.push_back(p);
			}
			divs.clear(); 			
		}
		
		return res; 
	}
};


int main (){
	
	auto res = SumSquaredDivisors::listSquared (1,250); 
	//divs.clear (); 
		for (auto i : res){ 
			cout << i.first << " " << i.second << " , ";  
			cout << endl ;
		}
	return 0; 
}
