
/*
https://www.codewars.com/kata/57591ef494aba64d14000526/train/cpp

	a(0) = 1 ; j (0) = 0; 
	a(n) = n - j(t); t = a(n-1); 
	j(n) = n - a(t); t = j(n-1);  
	
*/

#include <iostream>
#include <vector>

#define A_START 1
#define J_START 0

using namespace std; 

class Johnann
{
public:
    
	
	static std::vector<long long> john(long long n);
    static std::vector<long long> ann(long long n);
    static long long sumJohn(long long n);
    static long long sumAnn(long long n);
	
private:
	static void setVec (long long n);
	static long long getSum (long long n, int k); 
	static vector <long long> vJ;
	static vector <long long> vA;
	

};

	vector <long long> Johnann::vJ;
	vector <long long> Johnann::vA;

void 
Johnann::setVec(long long n ) {
	vA.clear();
	vJ.clear();
	vJ.push_back(0);
	vA.push_back(1); 
	
	for (long long i = 1; i < n ; i ++){
		long long tA = vA[i-1];
		long long tJ = vJ[i-1];
		vJ.push_back(i - vA[tJ]); 
		vA.push_back(i - vJ[tA]); 
	}	
}

long long 
Johnann::getSum(long long n, int k){
	setVec(n);
	long long res = 0;
	vector<long long> vec = (k)?vA:vJ; 
	for (auto i : vec){
		cout << i << " ";
		res+=i; 
	}
	cout << endl; 
	return res; 
}

long long 
Johnann::sumAnn(long long n){
	return getSum (n, 1); 
}

long long 
Johnann::sumJohn(long long n){
	return getSum (n, 0); 
}

std::vector<long long> 
Johnann::john(long long n){
	setVec(n); 
	return vJ; 
}

std::vector<long long> 
Johnann::ann(long long n){
	setVec(n); 
	return vA; 
}

int main (){
	
	// Johnann::setVec(11);
	auto out = Johnann::sumJohn(75);
	cout << "sum " << out << endl; 
	
	auto vec = Johnann::john(11); 
	
	for (auto i : vec ) cout << i << " "; 

}
