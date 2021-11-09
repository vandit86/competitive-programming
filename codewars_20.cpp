/**
 * 7kyu
 * https://www.codewars.com/kata/54c27a33fb7da0db0100040e/train/cpp
 * Given an integral number, determine if it's a square number
 * 
*/

#include <iostream>
#include <math.h>

bool is_square(int n)
{       
        if (n<0) return false; 
        int num = (int) sqrt(n);  
        return num*num == n; 
}

int main(int argc, char const *argv[])
{
        std::cout << is_square(25) << std::endl;
        std::cout << is_square(26) << std::endl;
        std::cout << is_square(-1) << std::endl;
        std::cout << is_square(0) << std::endl;

        return 0;
}
