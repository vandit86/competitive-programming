/**
 * https://www.codewars.com/kata/541af676b589989aed0009e7/train/cpp
 * 
 * Write a function that counts how many different ways you can make change for 
 * an amount of money, given an array of coin denominations. For example, there 
 * are 3 ways to give change for 4 if you have coins with denomination 1 and 2:
 * 
 * 1+1+1+1, 1+1+2, 2+2.
 * 
 * NOTES: 
 * this is a well known problem of 
 * https://www.geeksforgeeks.org/coin-change-dp-7/ 
 * and can be solved by recurcive sollution ( not pass by  timeout)
 * 
 * dynamic programming  (not pass by memmory)
 * https://apptractor.ru/info/github/zadachi-s-sobesedovaniy-razmen.html
 * 
 * BEST SOLUTION 
 * https://www.geeksforgeeks.org/understanding-the-coin-change-problem-with-dynamic-programming/
 * 
*/


#include <vector>
#include <iostream>
#include <algorithm>
using namespace std; 

// Returns the count of ways we can
// sum S[0...m-1] coins to get sum n
int count(int S[], int m, int n)
{
     
    // If n is 0 then there is 1 solution
    // (do not include any coin)
    if (n == 0)
        return 1;
     
    // If n is less than 0 then no
    // solution exists
    if (n < 0)
        return 0;
 
    // If there are no coins and n
    // is greater than 0, then no
    // solution exist
    if (m <= 0 && n >= 1)
        return 0;
 
    // count is sum of solutions (i)
    // including S[m-1] (ii) excluding S[m-1]
    return count(S, m - 1, n) +
           count(S, m, n - S[m - 1]);
}
 

unsigned long long 
countChange(const unsigned int money, const std::vector<unsigned int>& coins) {

    
    int sizeCoin = coins.size(); 
    // int S [sizeCoin]; 
    // for (size_t i = 0; i < sizeCoin; i++)
    // {
    //     S[i] = coins[i]; 
    // }
    
    // return count (S,sizeCoin,money);

    unsigned int tab[money+1][sizeCoin], x, y; 
    
    for (unsigned int i =0; i < sizeCoin; i++)
        tab[0][i]=1; 

    for (unsigned int i = 1 ; i < money+1; i++){
        for (unsigned int j = 0 ; j < sizeCoin; j++){
            x =  (i >= coins[j])? tab[i - coins[j]][j] : 0; 
            y = (j>=1)? tab [i][j-1] : 0; 
            tab[i][j] = x+y; 
        }
    }     

    return tab[money][sizeCoin-1]; 
}

int main(int argc, char const *argv[])
{
    /* code */
    std::cout << countChange(4, {1,2}) << std::endl; 
    return 0;
    //  cout << "money " << money << endl ; 
    // for (auto x : coins){
    //   cout << " " << x << endl ;  
      
    // }
}
