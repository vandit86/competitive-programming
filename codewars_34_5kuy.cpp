/**
5 kyu 
https://www.codewars.com/kata/5c09ccc9b48e912946000157/train/cpp
A bird flying high above a mountain range is able to estimate the height of the highest peak.

^^^^^^
 ^^^^^^^^
  ^^^^^^^
  ^^^^^
  ^^^^^^^^^^^
  ^^^^^^
  ^^^^
*/

#include <iostream>
#include <vector>
#define MSIZE 128

using namespace std; 

int peak_height(std::vector<std::string>& mountain) {
  
  int mnt [MSIZE][MSIZE] = {{0}};
  int mnt_inx [MSIZE][MSIZE] = {{0}};
  
  int max_height = 0; 
  int mnt_size = mountain.size(); 
  if (mnt_size > MSIZE-1) {
	  cout << "MAX size" << endl; 
	  return 0; 
  }
  
  
  auto print_mnt = [](int mnt [MSIZE][MSIZE]){
	for (int i =0;  i < MSIZE; i ++){
	  for (int j = 0 ; j < MSIZE ; j ++){
		  cout << mnt[i][j] << " "; 
	  }
	  cout << endl; 
	}
	cout << endl; 
  }; 
  

	// insert values 
	int i= 1, j=1; 
	for (auto str : mountain){
		if (str.length() > MSIZE-1) cout << "MAX size str" << endl; 
		for (auto ch : str){
			if (ch == '^') { max_height = 1; mnt[i][j]=1; }
			j++; 
		}
		i ++; 
		j = 1; 
	}
  
	//print_mnt(mnt);
	// calculate
	 
	
	for (int k = 0 ; k < mnt_size/2 ; k++){
		for (i = 1; i < MSIZE-1; i ++){
			for (j = 1; j <  MSIZE-1; j ++){
				if ( mnt[i][j] 				   && 
					(mnt[i][j] == mnt[i][j+1]) && 
					(mnt[i][j] == mnt[i][j-1]) && 
					(mnt[i][j] == mnt[i+1][j]) && 
					(mnt[i][j] == mnt[i-1][j]) ) 
				{ 
					mnt_inx[i][j]++; 
				}
			}
		}
		
		for (int i =0;  i < MSIZE; i ++){
			for (int j = 0 ; j < MSIZE ; j ++){
				if (mnt_inx[i][j]) {
					if ((++ mnt[i][j]) > max_height) max_height = mnt[i][j];
				}
				mnt_inx[i][j] = 0; 
			}
		}	
	}
	
	
	//print_mnt(mnt);
	//print_mnt(mnt_inx); 
	
  
  return max_height;
}

int main (void){
	
	std::vector<std::string> mountain = {
            "^^^^^^        ",
            " ^^^^^^^^     ",
            "  ^^^^^^^     ",
            "  ^^^^^       ",
            "  ^^^^^^^^^^^ ^^",
            "  ^^^^^^      ",
            "  ^^^^        "
        };
	
	cout << peak_height (mountain) << endl; 
	return 0; 
}
