https://www.codewars.com/kata/54ff3102c1bad923760001f3
#include <string>
#include <algorithm>

using namespace std;

int getCount(const string& inputStr){
  return  std::count_if(inputStr.begin(), inputStr.end(), [](char n) {
        return (n == 'a' || n == 'e' || n == 'i' || n == 'o' | n == 'u');
    });
}
