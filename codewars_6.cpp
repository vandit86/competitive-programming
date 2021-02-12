// https://www.codewars.com/kata/5270d0d18625160ada0000e4/train/cpp

#include <iostream>
#include <vector>
#define MAX_EL 6        // num of possible values in dice (6) 
int score(const std::vector<int>& dice) {
    int score = 0; 
    int arr [MAX_EL] = {0}; // init array 
    
    for (auto val : dice)  arr[val-1]++;

    for (size_t i = 0; i < MAX_EL; i++)
    {
        if (arr[i] > 2) {
            if (i >0) score = score + (i+1)*100; 
            else score = score + 1000;
            arr[i]-=3; 
        }
    }
    if (arr[0]>0) score = score + arr[0]*100;
    if (arr[4]>0) score = score + arr[4]*50;  
        //std::cout << arr [i] << " " ; 
    return score; 
}

int main(int argc, char const *argv[])
{
    score({2, 3, 4, 6, 2}); 
    return 0;
}
