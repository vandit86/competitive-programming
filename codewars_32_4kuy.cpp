/**
	https://www.codewars.com/kata/5a3af5b1ee1aaeabfe000084/discuss/cpp
	
	The task is simply stated. Given an integer n (3 < n < 109), find the length of the smallest list of perfect squares which add up to n. 
	
	Examples:

	sum_of_squares(17) = 2
	17 = 16 + 1 (4 and 1 are perfect squares).
	
	Based on Lagrange's Four Square theorem, there 
	are only 4 possible results: 1, 2, 3, 4.
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <numeric>
using namespace std;


int sum_of_squares(int num ) {
  int k = 0, m1 = 4; 
  k = static_cast<int>(sqrt(num));

  if (k*k == num) return 1; 
	int a,b,c=0; 
	 for (int i = k-1 ; i > 0 ; i --){
		a = i * i; 
		b = num - a;
		b = static_cast<int>(sqrt(b));
		b = b * b; 
		if (a + b == num) m1 = min (m1,2); 
		else {
			c = num - a - b;
			c = static_cast<int>(sqrt(c));
			c = c * c; 
			if (a+b+c == num) m1 = min (m1,3);
		}
		
		  
	 }
	 

 return m1;
}

int main (){
	
	long num (18); 
	cout << sum_of_squares(num) << endl; 
	return 0 ; 
}
