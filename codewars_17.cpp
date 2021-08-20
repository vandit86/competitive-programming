/**
 *  https://www.codewars.com/kata/525c7c5ab6aecef16e0001a5/train/cpp 
*/


#include <string>
#include<iostream>  
#include<unordered_map>
#include<vector>

std::unordered_map<std::string, long> NUMS = {
    {"zero", 0},
    {"one", 1},
    {"two", 2},
    {"three", 3},
    {"four", 4},
    {"five", 5},
    {"six", 6},
    {"seven", 7},
    {"eight", 8},
    {"nine", 9},
    {"ten", 10},
    {"eleven", 11},
    {"twelve", 12},
    {"thirteen", 13},
    {"fourteen", 14},
    {"fifteen", 15},
    {"sixteen", 16},
    {"seventeen", 17},
    {"eighteen", 18},
    {"nineteen", 19},
    {"twenty", 20},
    {"thirty", 30},
    {"forty", 40},
    {"fifty", 50},
    {"sixty", 60},
    {"seventy", 70},
    {"eighty", 80},
    {"ninety", 90},
};

std::unordered_map <std::string, long> MULT {
    {"hundred", 100},
    {"thousand", 1000},
    {"million", 1000000}
}; 


std::vector <std::string> splitNumbers (std::string s, std::string delimiter = " "){
    std::vector<std::string> res; 
    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos)
    {
        token = s.substr(0, pos);
        res.push_back(token); 
        s.erase(0, pos + 1);
    }
    res.push_back (s); 
    return res ; 
}

long parse_int(std::string number) {

    long res = 0 ;
    long val = 0 ; 
    std::vector <std::string>  nums = splitNumbers (number); 
    for(auto &n : nums){
        // if twenty-two  
        if (n.find('-') != std::string::npos){
            long f =0; 
            std::vector <std::string> kk = splitNumbers (n, "-");
            for (auto &j : kk)
            {
                if (NUMS.find(j) != NUMS.end())
                {
                    f += NUMS[j];
                }
            }
            val += f;
            continue;  
        }

        if (NUMS.find(n) != NUMS.end()){
            val += NUMS[n]; 
            continue; 
        }

        if (MULT.find(n) != MULT.end()){
            val *= MULT[n];
            if (n.compare("thousand")==0){
                res = val; 
                val = 0; 
            }
        } 
    }
    return res+=val;
}

int main(int argc, char const *argv[])
{
    long val = parse_int("forty-six"); 
    std::cout <<val << std::endl; 
    val = parse_int("forty-six thousand");
    std::cout <<val << std::endl;  
    val = parse_int("six hundred sixty-six thousand six hundred sixty-six"); 
    std::cout <<val << std::endl; 
    return 0;
}
