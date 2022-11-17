/**
https://www.codewars.com/kata/58905bfa1decb981da00009e/cpp
Get all the people to the floors they want to go to while obeying the Lift rules and the People rules
*/


// #include <utility>
 #include <vector>
 #include <iostream>
// #include <numeric>      // std::accumulate
 #include <algorithm>
// #include <cmath>
// #include <string>		// push_back . pop_back , std::to_string(42);
// #include <queue>		// push - last, pop firs

//#include <bits/stdc++.h>

using namespace std;

// return true if someone get out of lift and update inside 
bool check_out (std::vector<int> &in, int flor){
	if (in.size() == 0) return false; 
	// check pas out 
	const auto last = std::remove(in.begin(), in.end(), flor); 
	if (last == in.end()) return false; 
	in.erase(last, in.end());
	return true; 
}

// return true is someone enter the lift, and update queues 
bool check_in (std::vector<int> &in, std::vector<int> &qu, int cap, bool move_up,  int flor){
	bool enter = false; 
	for (auto it = qu.begin(); it != qu.end(); it++){
		//if (in.size() >= cap) break;
		if ( (move_up && flor < *it) || (!move_up && flor > *it) ){
			enter = true;
			if (in.size() < cap){
				in.push_back(*it);
				qu.erase(it--);
			}
		}
	}
	
	return enter; 
}



std::vector<int> the_lift(std::vector<std::vector<int>> &queues, int capacity) {
  
  vector <int> res {0}; 
  vector <int> inside {}; 		// persons inside lift 
  size_t QSIZE = queues.size(); // size of building 
  
  int stop 		= -1; 			// num stops per cicle 
  int flor 		= 0;			// flor  
  bool move_up	= true ; 		// lift goes up 
  
  while (1){
	
	if (flor == 0){					// new cicle 
		if (stop == 0) break; 		// no stops on previous cycle 
		stop = 0; 					// clear stop counter ; 
		move_up = true ; 			// we move up 
	}
	
	if (flor == QSIZE - 1){
		move_up = false; 			// move down 
	}
	
	bool out = check_out (inside, flor);  
	bool in  = check_in (inside, queues.at(flor), capacity, move_up, flor); 
	if ( out || in ){
		stop++;
		if (res.back() != flor)
		res.push_back(flor); 
	}
	
	if (move_up) flor++;
	else flor--; 
  }
  
  if (res.back() != 0)
	res.push_back(0); 
  
  return res;
}

// test 
int main (){
	
	 std::vector<std::vector<int>> queues; std::vector<int> result;
    
       // queues = { {}, {}, {5,5,5}, {}, {}, {}, {} };
		// queues = { {}, {0}, {}, {}, {2}, {3}, {} };
		 queues = { {}, {3}, {4}, {}, {5}, {}, {} };

	auto res = the_lift (queues, 5); 
	
	for (auto i : res){
		cout << i << " "; 
	}
	return 0; 
}
