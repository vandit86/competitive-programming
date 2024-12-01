// https://www.codewars.com/kata/5467e4d82edf8bbf40000155

#include <cinttypes>
#include <string>
#include <algorithm>

uint64_t descendingOrder(uint64_t a)
{
  auto str = std::to_string(a);
  std::sort(str.begin(), str.end(), [](char a, char b) {
        return a > b;
    });
  return std::stoull (str);
}
