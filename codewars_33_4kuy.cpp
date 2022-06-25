/**
https://www.codewars.com/kata/529bf0e9bdf7657179000008/train/cpp

Sudoku Solution Validator
Write a function validSolution/ValidateSolution/valid_solution() that accepts a 2D array representing a Sudoku board, 
and returns true if it is a valid solution, or false otherwise. The cells of the sudoku board may also contain 0's, 
which will represent empty cells. Boards containing one or more zeroes are considered to be invalid solutions.

The board is always 9 cells by 9 cells, and every cell only contains integers from 0 to 9.

*/

#include <iostream>
#include <vector>

using namespace std; 

bool validSolution(unsigned int board[9][9]){
	
	vector<unsigned int> v_count (10,0);
	vector<unsigned int> v_val (9,0); 
	
	
	auto check_vector = [&]()->bool {
		v_count.assign(10, 0);
		for (auto i : v_val){
			v_count[i] ++; 
			if (i == 0 || v_count[i]>1) return false; 
		}
		return true; 		
    };
	
	// rows 
	for (int i = 0 ; i < 9 ; i ++ ){
		for (int j = 0 ; j < 9 ; j ++){
			v_val[j] = board[i][j];
			cout << v_val[j] << " "; 
		}
		//cout << " res " << check_vector() ; 
		if (!check_vector()) return false;
		cout << endl; 
	}
	
	cout << endl; 
	// clos 
	for (int i = 0 ; i < 9 ; i ++ ){
		for (int j = 0 ; j < 9 ; j ++){
			v_val[j] = board[j][i];
			cout << v_val[j] << " ";			
		}
		if (!check_vector()) return false; 
		cout << endl;
	}
	
	cout << endl; 
	
	// cells
	for (int k = 0 ; k < 9 ; k +=3){
		for (int l = 0; l < 9; l+=3){
			
			for (int i = 0 ; i < 3 ; i ++ ){
				for (int j = 0 ; j < 3 ; j ++){
					v_val[j+i*3] = board[i+k][j+l];
					cout << v_val[j+i*3] << " ";			
				}
			cout << endl;
			}
		if (!check_vector()) return false; 		
		cout << endl; 
		}
	}
	
	return true;
}

int main (void){
	unsigned int example1[9][9] = {{5, 3, 4, 6, 7, 8, 9, 1, 2}, 
                             {6, 7, 2, 1, 9, 5, 3, 4, 8},
                             {1, 9, 8, 3, 4, 2, 5, 6, 7},
                             {8, 5, 9, 7, 6, 1, 4, 2, 3},
                             {4, 2, 6, 8, 5, 3, 7, 9, 1},
                             {7, 1, 3, 9, 2, 4, 8, 5, 6},
                             {9, 6, 1, 5, 3, 7, 2, 8, 4},
                             {2, 8, 7, 4, 1, 9, 6, 3, 5},
                             {3, 4, 5, 2, 8, 6, 1, 7, 9}}; 
	
	cout << validSolution(example1) << endl; 
}
