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
        // create sub vect and sort
        vector<int> sub = {ls.begin(), ls.begin() + k};
        sort(sub.begin(), sub.end());

        int dSum = 0;
        dSum = accumulate(sub.begin(), sub.end(), 0); // get sum

        for (auto it = ls.begin() + k; it != ls.end(); it++)
        {

            if (dSum < limit)
            {
                for (auto jt = sub.begin(); jt != sub.end(); jt++)
                {
                    int val = dSum - *jt + *it; 
                    if ( val > dSum && val <= limit ){
                        *jt = *it; 
                        dSum = val; 
                        break ; 
                    }
                }
            }
            /*  recerce iteration */
            else if (dSum > limit){
                for (auto jt = sub.rbegin(); jt != sub.rend(); jt++)
                {
                    int val = dSum - *jt + *it;
                    if (val < dSum && val <= limit){
                        *jt = *it; 
                        dSum = val; 
                        break;
                    }
                }
            }
            
            // for (auto &i : sub)
            // {
            //     cout << " " << i;
            // }
            // cout << "\n*it " << *it << endl ; 

            // sort(sub.begin(), sub.end()); // sort
        }
        return (dSum>limit)?-1:dSum;
    }
};

int main(int argc, char const *argv[])
{
    std::vector<int> ts = {50, 55, 56, 57, 58,10};
    std::vector<int> tsbb = {100, 76, 56, 44, 89, 73, 68, 56, 64, 123, 2333, 144, 50};
    int n = BestTravel::chooseBestSum(163, 4, tsbb);
    cout << "sum =" << n;
    return 0;
}
