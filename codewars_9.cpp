// https://www.codewars.com/kata/526571aae218b8ee490006f4/train/cpp
#include <iostream>
unsigned int countBits(unsigned long long n)
{
    unsigned int sum =0; 
    for (int i = 0; i < 64; i++)
    {
        if (n & (1L << i)) sum ++; 
    }
    return sum ; 
}

int main(int argc, char const *argv[])
{
    std::cout<< countBits (26); 
    return 0;
}

