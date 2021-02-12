//https://www.codewars.com/kata/5592e3bd57b64d00f3000047/train/cpp
#include<iostream>
#include <cmath>
class ASum
{
  public:
  static long long findNb(long long m);
};

long long 
ASum::findNb (long long m){
    unsigned int n = 0; 
    long long sum = 0; 
    while (sum < m){
        sum = sum + pow (++n, 3);
    }
    if (sum == m) return n; 
    return -1; 
}

void test_reverse (long long n){
    long long res =0;
    for (size_t i = 1; i <= n; i++)
    {
        res = res + pow(i,3); 
    }
    std::cout << res << "\n"; 
}

int main(int argc, char const *argv[])
{
    std::cout<<ASum::findNb(1025292944081377280);
    //test_reverse (45001);  
    return 0;
}

// 45001
