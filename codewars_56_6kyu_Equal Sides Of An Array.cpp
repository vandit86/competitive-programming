// https://www.codewars.com/kata/5679aa472b8f57fb8c000047

#include <vector>
#include <numeric>

using namespace std;

int find_even_index (const vector <int> numbers) {
  
  for (int i = 0 ; i < numbers.size(); i++){
    int left = std::accumulate(numbers.begin(), numbers.begin()+i, 0);
    int right = std::accumulate(numbers.begin()+i+1, numbers.end(), 0);
    if (left == right) return i; 
  }

  return -1;
}
