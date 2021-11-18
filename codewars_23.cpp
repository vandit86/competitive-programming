/**
 * https://www.codewars.com/kata/55e7280b40e1c4a06d0000aa/train/cpp
 * 5Kyu
 * The function chooseBestSum () will take as parameters 
 * limit (maximum sum of distances, integer >= 0), 
 * k (number of towns to visit, k >= 1) and 
 * ls (list of distances, all distances are positive or zero integers and 
 * this list has at least one element). The function returns the "best" sum 
 * ie the biggest possible sum of k distances less than or equal to the given 
 * limit t, if that sum exists, or -1 otherwise
 * 
 * NOTES : ~
 * Note that each combination of 3 objects yields 6, or 3! permutations
 * https://www.math10.com/en/algebra/probabilities/combinations/combinations.html
 * https://www.geeksforgeeks.org/all-unique-combinations-whose-sum-equals-to-k/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class BestTravel
{
public:
    static int chooseBestSum(int limit, int k, std::vector<int> &ls)
    {
        if (k > (int)ls.size())
            return -1;
        int dSum = -1 ; 

        std::sort(ls.begin(), ls.end());
        do
        {
            //for (auto &i : ls ) cout << i << ", " ; 
            //cout << endl ; 
            int sum = accumulate (ls.begin(), ls.begin()+k, 0); 
            if (sum <= limit && dSum < sum) dSum = sum; 
        } while (std::next_permutation(ls.begin(), ls.end()));

        return (dSum > limit) ? -1 : dSum;
    }
};

int main(int argc, char const *argv[])
{
    // std::vector<int> ts = {50, 55, 56, 57, 58,10};
    // int n = BestTravel::chooseBestSum(163, 3, ts); // 163
    
    //std::vector<int> ts = {91, 74, 73, 85, 73, 81, 87};
    // int n = BestTravel::chooseBestSum(230, 3, ts); // 228
    // int n = BestTravel::chooseBestSum(331, 2, ts); // 178
    //int n = BestTravel::chooseBestSum(331, 5, ts); // -1
    
    std::vector<int> tsbb = {100, 76, 56, 44, 89, 73, 68, 56, 64, 123, 2333, 144, 50,132, 123, 34, 89};
    int n = BestTravel::chooseBestSum(230, 4, tsbb); // 230 
    // int n = BestTravel::chooseBestSum(430, 5, tsbb); // 430 actual 427 
    cout << "\nsum =" << n;
    return 0;
}
