// cata : https://www.codewars.com/kata/52f787eb172a8b4ae1000a34/train/cpp
// solution based on : https://tproger.ru/problems/how-many-zeros-at-the-end-of-the-factorial-of-100/

#include <iostream>

long long zeros(long long n) {
  long long z{0ll},aux{0ll}; 
  for (long long i = 1; i <= n; i++)
  { 
    aux = i ; 
    while ((aux % 5) == 0 && aux>=5 ){
      z++;
      aux = aux/5; 
    }
  }
  return z;
}

int main(int argc, char const *argv[])
{
    std::cout<< zeros(300000000000000000) << std::endl;  
    return 0;
}


