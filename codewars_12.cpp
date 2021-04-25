// cata : https://www.codewars.com/kata/52f787eb172a8b4ae1000a34/train/cpp
// solution based on : https://tproger.ru/problems/how-many-zeros-at-the-end-of-the-factorial-of-100/

#include <iostream>

long zeros(long n) {
  long z{0l},aux{0l}; 
  if (n < 5) return 0; 
  for (long i = 5, aux = 25, k = 1; i <= n; i=i+5)
  { 
    z+=k ; 
    if (i == aux){
      aux = 5 * aux; 
      k++; 
    }
    // while ((aux % 5) == 0 && aux>=5 ){
    //   z++;
    //   aux = aux/5; 
    // }
  }
  return z;
}

// reference solution 
// long zeros(long n) {
//     long result = 0;
//     while(n)
//         result += n/=5;
//     return result;
// }

int main(int argc, char const *argv[])
{
    // std::cout<< zeros(30) << std::endl;  
    std::cout<< zeros(1000000000) << std::endl;  
    return 0;
}




