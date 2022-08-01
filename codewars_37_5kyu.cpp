
/**
https://www.codewars.com/kata/5279f6fe5ab7f447890006a7/train/cpp
In this kata, you will write a function that returns the positions and the values of the "peaks" (or local maxima) of a numeric array.
For example, the array arr = [0, 1, 2, 5, 1, 0] has a peak at position 3 with a value of 5 (since arr[3] equals 5).
*/
#include <vector>
#include <iostream>
#include <algorithm>    // std::find



using namespace std; 
struct PeakData {
  vector<int> pos, peaks;
};

PeakData pick_peaks(const std::vector<int> &v) {
  PeakData result;
  
  int pos = 0, peak = -1000000; 
  
  for (int i = 1 ; i < v.size() ; i ++){
      if (v[i] > v[i-1]){
        pos = i; 
        peak = v[i]; 
      }
      else if (v[i] < peak){
        result.pos.push_back(pos); 
        result.peaks.push_back(peak);
        //pos = ; 
        peak = -1000000;
      }
  }

  return result;
}



int main (){
    
    const vector<int> data {3, 2, 3, 6, 4, 1, 2, 3, 2, 1, 2, 3}; 
    auto res = pick_peaks (data); 
    
    for (auto i : res.pos) cout << i << " "; 
    cout << endl; 
    for (auto i : res.peaks) cout << i << " "; 
    cout << endl; 
    
    return 0; 
}
