//https://www.codewars.com/kata/559a28007caad2ac4e000083/train/cpp

#include <iostream>
typedef unsigned long long ull;
class SumFct
{
public:
  static ull perimeter(int n);
};

ull SumFct::perimeter(int n)
{
  ull sum = 1;
  if (n > 1)
  {
    ull n_1 = 1;
    ull n_2 = 0;
    ull val = 0;
    for (int i = 0; i < n; i++)
    {
      val = n_1 + n_2;
      n_2 = n_1;
      n_1 = val;
      sum += val;
    }
  }
  else if (n == 1)
    sum += 1;

  return 4 * sum;
}

int main(int argc, char const *argv[])
{

  std::cout << SumFct::perimeter(4);
  return 0;
}
