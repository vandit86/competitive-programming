/**
* 	https://www.codewars.com/kata/51ba717bb08c1cd60f00002f/train/cpp
*   4Kyu
* 	Range Extraction: 
*   The range includes all integers in the interval including both endpoints. 
* 	It is not considered a range unless it spans at least 3 numbers.
*/


#include <utility>
#include <vector>
#include <iostream>
#include <numeric>      // std::accumulate
#include <algorithm>
#include <cmath>
#include <string>		// push_back . pop_back , std::to_string(42);
#include <queue>		// push - last, pop firs

using namespace std ; 

std::string range_extraction(std::vector<int> args) {
	std::string mStr (""); 
	int count = 0,num, i; 
	
	for (i = 1, num = args[0]; i < args.size(); i ++){ 
		
		if (args[i] - args[i-1] == 1){
			count ++ ; 
		}
		else {
			if (count >= 2 ){
				mStr+=std::to_string(num);
				mStr+="-";
				mStr+=std::to_string(args[i-1]);
			}
			
			else if (count == 1){
				mStr+=std::to_string(num);
				mStr+=",";
				mStr+=std::to_string(args[i-1]);
			}
			else {
				mStr+=std::to_string(num);
			}
			mStr+=",";
			count = 0;
			num = args[i]; 
		}
		 
	}
	
	if (count >=2) {
		mStr+=std::to_string(num);
		mStr+="-";
		mStr+=std::to_string(args[i-1]);
	}
	else if (count == 1){
				mStr+=std::to_string(num);
				mStr+=",";
				mStr+=std::to_string(args[i-1]);
	}
	else {
			mStr+=std::to_string(num);
	}
  
  return mStr;
}

int main (){
	
	//vector <int> v = {-6,-3,-2,-1,0,1,3,4,5,7,8,9,10,11,14,15,17,18,19,20}; 
	vector <int> v = {-3,-2,-1,2,10,15,16,18,19,20}; 
	
	auto res = range_extraction (v);  
	cout << res << endl; 
	return 0; 
}
