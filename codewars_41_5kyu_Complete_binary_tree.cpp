/**
	https://www.codewars.com/kata/5a3af5b1ee1aaeabfe000084/discuss/cpp
	
	are only 4 possible results: 1, 2, 3, 4.


*/

#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <algorithm>

//#include <bits/stdc++.h>

using namespace std;


// v_pos position in vals vector-- layer 
// K layer 

void print_vec (const vector<int>& v){
	for (auto i : v){
		cout << i << ", "; 
	}
	cout << endl; 
}


std::vector<int> complete_binary_tree(const std::vector<int>& input)
{
	if (input.size() == 1) return input; 
	
	vector<int> v_res ; 
	vector<int> v_last; 
	vector<int>	v_main; 
	vector<int> v_aux; 
	
	size_t  K = std::ceil (log2 (input.size()));  // num of layers 
	size_t  M = std::pow(2,K) - 1;				  // max capability 
	
	if (M < input.size()) {
		K++; 
		M = std::pow(2,K) - 1;
	} 
	
	size_t last_size = std::pow(2, K-1); 
	size_t out_num = last_size - (M - input.size());	// num of val in lover layer  
	
	// create full binary tree 
	for (size_t i = 0, pos = 0; i < input.size() ; i ++){
		if (i == pos && out_num > 0){
			pos+=2; 
			--out_num; 
			v_last.push_back(input.at(i)); 
		} else {
			v_main.push_back(input.at(i)); 
		}
	}
	
	v_aux.reserve (last_size);
	v_res.reserve (input.size()); 
	
	for (size_t i = 0; i < K-1; i++){
		
		size_t step = std::pow (2, i+1); 
		size_t start = std::pow (2, i) - 1; 
		v_aux.clear();
		
		for (size_t j = start; j < v_main.size(); j = j+step){
			v_aux.push_back(v_main.at(j)); 
		}
		
		for (auto it = v_aux.rbegin(); it < v_aux.rend(); it ++){
			v_res.push_back(*it);
		}
	}
	
	
	std::reverse (v_res.begin(), v_res.end());
	v_res.insert (v_res.end(), v_last.begin(), v_last.end()); 
	
	return v_res;
}

// recursion version 
void compute_permutation(vector<int> & permutation,  int curr, int max)
{
    if (curr > max) return;
	cout << curr << " "<< max << endl; 
    compute_permutation(permutation, curr * 2, max);
    permutation.push_back(curr - 1);
	print_vec (permutation); 
    compute_permutation(permutation, curr * 2 + 1, max);
}

vector<int> complete_binary_tree_rec(const vector<int> & input) 
{
    vector<int> output(input.size());
    vector<int> permutation{};
    compute_permutation(permutation, 1, input.size());
    for (size_t i = 0; i < input.size(); ++i)
    {
        output[permutation[i]] = input[i];
    }
    return output;
}

int main (){
	
	std::vector<int> input {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	 // input = {1};
	 
	 //input = {1, 2, 3, 4, 5, 6}; //  [ 4, 2, 6, 1, 3, 5 ]
	
	//input = {8, 19, 10, 1, 10, 6, 8, 13, 21, 35, 1, 40, 36, 3, 33, 12, 38, 29, 6, 16, 22, 2, 29};
		  // 12, 13, 16, 1, 40, 29, 2, 19, 6, 35, 3, 38, 6, 22, 29, 8, 10, 10, 8, 21, 1, 36, 33  // expected 
		//  12  10  16  10  35 29 2  19  1   13  36 38  6   22 29  8   8   21  40 33
	auto res = complete_binary_tree_rec (input); 
	for (auto i : res){
		cout << i << " "; 
	}
}
