#include <vector>
#include <map>
#include <iostream>

std::vector<int> deleteNth(std::vector<int> arr, int n)
{
  std::vector<int> result;
  std::map<int, int> nums;
  for (int i : arr)
  {
    if (nums[i] < n)
    {
      nums[i]++;
      result.push_back(i);
    }
  }
  return result;
}

template <typename T>
void printV(std::vector<T> vec)
{
  for (T i : vec)
  {
    std::cout << i << " ";
  }
  std::cout << "\n";
}

int main(int argc, char const *argv[])
{
  printV(deleteNth({20, 37, 20, 21}, 1));
  return 0;
}
