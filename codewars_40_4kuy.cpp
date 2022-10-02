/**
* 	https://www.codewars.com/kata/52a382ee44408cea2500074c/train/cpp
*   4Kyu
* 	Write a function that accepts a square matrix (N x N 2D array) and returns the determinant of the matrix.
*/

#include <vector>
#include <iostream>

using namespace std;

vector<vector<long long>> get_mx (vector<vector<long long>> m, int col){
	
	vector <vector <long long>> vec; 
 	for (int i = 1 ; i < m.size(); i ++){
		vector <long long > aux;
		for (int j = 0 ; j < m.size(); j ++){
			if (j != col) aux.push_back(m[i][j]); 
		}
		vec.push_back(aux); 		
	}
	return vec; 
}

 // TODO: Return the determinant of the square matrix passed in
long long determinant(vector< vector<long long> > m) {
	
	if (m.size() == 1) return m[0][0]; 
	if (m.size() == 2){
		return m[0][0] * m[1][1] - m[0][1]*m[1][0]; 
	}
	long long res = 0;
	for (int col = 0 ; col < m.size() ; col ++){
		
		auto mx = get_mx (m,col); 
		long long val = m[0][col]*determinant(mx); 
		
		if (col % 2 != 0) val*=-1;
		res+=val; 
	}
	
  return res;
}


int main (){
	
	vector< vector<long long> > v {
      vector<long long> {2, 5, 3},
      vector<long long> {1, -2, -1},
      vector<long long> {1, 3, 4}
    }; 
	auto res = determinant (v); 
	cout << res << endl; 
	return 0; 
}
