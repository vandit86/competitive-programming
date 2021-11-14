/**
 * https://www.codewars.com/kata/590adadea658017d90000039/train/cpp
 * You will be given three reels of different images and told at which 
 * index the reels stop. From this information your job is to return the score 
 * of the resulted reels.
 * 
*/
#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <map>

#define MAX_ITEMS 10
using namespace std;

// Create a map of items strings (that map to score/position)
// std::map<std::string, int> items_map {
//                     {"Jack", 1},
//                     {"GPU", 15}, {"RAM", 20}, };

static const vector<string> it_vt{
			"Wild",		// 0
			"Jack",		// 1
			"Queen",
			"King",
			"Bar",
			"Cherry",
			"Seven",
			"Shell",
			"Bell",
			"Star"		// 9 
		};

unsigned fruit(const array<vector<string>, 3> &reels,
	       const array<unsigned, 3> &spins)
{
	array<int,MAX_ITEMS> items = {0}; 
	unsigned long score  = 0 ; 
	
	// check 3 spins 
	for (size_t i = 0; i < 3; i++)
	{
		// find item and item pos
		auto rv = reels[i];
		auto val = rv[spins[i]];   
		auto res = find(it_vt.begin(), it_vt.end(), val);
		if (res !=it_vt.end()){
			int pos = distance (it_vt.begin(),res); 
			 ++items[pos]; 
		}
	}

	if (items[0] == 2) return 10 ; 
	if (items[0] == 3) return 100; 
	for (size_t i = 1; i < MAX_ITEMS; i++)
	{
		//if (!items[i]) continue; 
		if (items[i] == 2 ){
			score = i;
			if (items[0]){
				score *= 2;
			}
		} else if (items[i] == 3)
		{
			score = i * 10 ; 
		}
	}

	return score; // Code here
}

int main(int argc, char const *argv[])
{
	array<vector<string>, 3> reels;
        array<unsigned, 3>       spins;
        
        reels[0] = {"Wild", "Star", "Bell", "Shell", "Seven", "Cherry", "Bar", "King", "Queen", "Jack"};
        reels[1] = {"Wild", "Star", "Bell", "Shell", "Seven", "Cherry", "Bar", "King", "Queen", "Jack"};
        reels[2] = {"Wild", "Star", "Bell", "Shell", "Seven", "Cherry", "Bar", "King", "Queen", "Jack"};
        spins    = {0, 0, 9};
	cout << fruit(reels, spins) << endl ; 
	return 0;
}

