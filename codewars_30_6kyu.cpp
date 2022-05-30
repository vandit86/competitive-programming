
/*
https://www.codewars.com/kata/566543703c72200f0b0000c9/train/cpp

(I)    S[k+1] = S[k] - dt * b * S[k] * I[k]
(II)   I[k+1] = I[k] + dt * (b * S[k] * I[k] - a * I[k])
(III)  R[k+1] = R[k] + dt * I[k] *a

where s(t), i(t), r(t) are the susceptible, infected, recovered at time t and s'(t), i'(t), r'(t) the corresponding derivatives. 
b and a are constants: b is representing a number of contacts which can spread the disease and a is a fraction of the infected that will recover.

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 


class Epidem
{
public:
    static int epidemic(int tm, int n, int s0, int i0, double b, double a){
		
		
		double dt = (double)tm/n; 
		vector <double> S,I,R; 
		S.push_back(s0);
		I.push_back(i0);
		
		for (int i =0 ; i < n; i++){
			S.push_back (S[i] - dt * b * S[i] * I[i]);
			I.push_back (I[i] + dt * (b*S[i] * I[i] - a * I[i]) );  
		}
		auto it =  max_element(I.begin(), I.end());
		return (int) *it; 
	}
};


int main (){
	
	int tm = 18 ;int n = 432 ;int s0 = 1004 ;int i0 = 1 ;double b = 0.00209 ;double a = 0.51;
    int res = Epidem::epidemic(tm, n, s0, i0, b, a);
	cout << res << endl; 
	
}
