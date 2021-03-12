// https://www.codewars.com/kata/5287e858c6b5a9678200083c/train/cpp

#include <iostream>
#include <math.h>
bool narcissistic(int value)
{
  int i = 0;
  int arr[32] = {0};
  double exponent = 0;
  int val = value;
  for (; val > 0; i++)
  {
    arr[i] = val % 10;
    val = val / 10;
  }
  val = 0;
  exponent = i;
  for (; i > 0; i--)
  {
    val += pow(arr[i - 1], exponent);
  }
  return (val == value)?true:false; 
}

int main(int argc, char const *argv[])
{
  std::cout<< narcissistic(371);
  return 0;
}
