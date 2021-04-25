// https://www.codewars.com/kata/52b7ed099cdc285c300001cd/train/cpp

#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>

int sum_intervals(std::vector<std::pair<int, int>> s)
{
    // sort vector by first element of pair using lambda
    std::sort(s.begin(), s.end(), [](std::pair<int, int> a, std::pair<int, int> b) {
        return a.first < b.first;
    });
    int res = 0; 
    int fst = s[0].first; 
    int sec = s[0].second;

    for (auto it = s.begin(); it != s.end(); it++)
    {
        if (it->first > sec){
            res+= sec-fst; 
            fst = it->first;
            sec = it->second; 
        }
        else if ( it->second > sec){
            sec = it->second;
        }
    }
    res+=sec-fst; 
    // std::cout << it->first << "  " << it->second << std::endl;
    return res;
}

int main(int argc, char const *argv[])
{
    int res = sum_intervals({{1, 5},
                             {10, 20},
                             {1, 6},
                             {16, 19},
                             {5, 11}});

    std::cout << res;
    return 0;
}

