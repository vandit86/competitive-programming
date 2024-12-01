// https://www.codewars.com/kata/54da539698b8a2ad76000228

#include <algorithm>
#include<vector>
using namespace std;


bool isValidWalk(std::vector<char> vec) {

    if (vec.size()!=10) return false; 
    int cN{}, cS{}, cE{}, cW{}; 
    cN = std::count(vec.begin(), vec.end(), 'n');
    cS = std::count(vec.begin(), vec.end(), 's');
    cE = std::count(vec.begin(), vec.end(), 'e');
    cW = std::count(vec.begin(), vec.end(), 'w');

    return (cN == cS && cE == cW); 
}
