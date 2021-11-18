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

        int dSum = -1;
        // for (auto &i : ls ) cout << i <<" , "; 
        // cout << "\n l = " << limit << "k = " << k << endl ; 
        for (auto ib = ls.begin()+k, ia = ls.begin(); 
                                ib !=ls.end(); ib ++, ia++){
            int iSum = accumulate(ia, ib, 0); // get sum of carrier
            int aSum = 0;
            for (auto jt = ls.begin(); jt != ls.end() ; jt ++){
                if (jt >= ia && jt < ib) continue; // if we in carrier
                
                aSum = -1;                 
                for (auto ii = ia; ii != ib; ii++){
                    int val = iSum - *ii + *jt;
                    if (val <= limit && val > aSum){
                        aSum = val;
                    }
                }
                if (aSum > dSum) dSum = aSum;
            }
            if (iSum > dSum && iSum <= limit) dSum = iSum;
        }

        return (dSum>limit)?-1:dSum;
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
